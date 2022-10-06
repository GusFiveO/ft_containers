/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:25:10 by alorain           #+#    #+#             */
/*   Updated: 2022/10/06 19:41:45 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BNR_HPP
# define BNR_HPP

# include "pair.hpp"

namespace ft
{

struct Rb_tree_node_base
{
	typedef Rb_tree_node_base* 			base_pointer;
	typedef const Rb_tree_node_base*	const_base_pointer;
	
	base_pointer M_parent;
	base_pointer M_right;
	base_pointer M_left;

	Rb_tree_node_base(base_pointer parent = NULL, base_pointer right = NULL, base_pointer left = NULL)
	: M_parent(parent), M_right(right), M_left(left) {}
};

template<typename Val>
struct Rb_tree_node : public Rb_tree_node_base 
{
	typedef Rb_tree_node<Val>*	node_ptr;
	Val 						M_value_field;

	void
	init_node(base_pointer parent, base_pointer right, base_pointer left)
	{
		M_parent = parent;
		M_right = right;
		M_left = left;
	}
};


template<typename Val, typename Alloc = std::allocator<Val> >
class Rb_tree
{

	protected:
		typedef Rb_tree_node_base* 			base_ptr;
		typedef const Rb_tree_node_base*	const_base_ptr;

	public:
		typedef Val 				value_type;

		typedef value_type* 		pointer;
		typedef const value_type* 	const_pointer;
		typedef value_type& 		reference;
		typedef const value_type& 	const_reference;
		typedef size_t				size_type;
		typedef ptrdiff_t			difference_type;

		typedef Alloc				allocator_type;
		typedef typename Alloc::template rebind<Rb_tree_node<Val> >::other node_allocator;

		typedef Rb_tree_node<Val>* 			node_ptr;
		typedef const Rb_tree_node<Val>*	const_node_ptr;
	
		allocator_type
		get_allocator()
		{
			return allocator_type();
		}

	protected:
		
		node_ptr
		alloc_node()
		{
			return (M_impl.node_allocator::allocate(1));
		}

		void
		dealloc_node(node_ptr ptr)
		{
			return (M_impl.node_allocator::deallocate(ptr, 1));
		}

		node_ptr
		create_node(const value_type& val)
		{
			node_ptr tmp = alloc_node();
			try
			{
				get_allocator().construct(&tmp->M_value_field, val);
			}
			catch(...)
			{
				dealloc_node(tmp);
				throw;
			}
			return tmp;
		}

		void
		destroy_node(node_ptr ptr)
		{
			get_allocator().destroy(&ptr->M_value_field);
			dealloc_node(ptr);
		}
	
	private:
		struct Rb_tree_impl : public node_allocator
		{
			Rb_tree_node_base	M_header;
			size_type			M_node_count;

			Rb_tree_impl()
			: node_allocator(), M_header(), M_node_count(0)
			{
				M_initialize();
			}

			private:
				void
				M_initialize()
				{
					this->M_header.M_parent = NULL;
					this->M_header.M_right = &this->M_header;
					this->M_header.M_left = &this->M_header;
				}
		};
		
		Rb_tree_impl M_impl;
	
	protected:

		base_ptr&
		M_root()
		{
			return M_impl.M_header.M_parent;
		}

		node_ptr
		M_begin()
		{
			return static_cast<node_ptr>(this->M_impl.M_header.M_parent);
		}

		static node_ptr
		S_right(base_ptr x)
		{
			return static_cast<node_ptr>(x->M_right);
		}

		static const_node_ptr
		S_right(const_base_ptr x)
		{
			return static_cast<const_node_ptr>(x->M_right);
		}

		static node_ptr
		S_left(base_ptr x)
		{
			return static_cast<node_ptr>(x->M_left);
		}

		static const_node_ptr
		S_left(const_base_ptr x)
		{
			return static_cast<const_node_ptr>(x->M_left);
		}

		static const_reference
		S_value(const_node_ptr x)
		{
			return x->M_value_field;
		}

		static const_reference
		S_value(const_base_ptr x)
		{
			return static_cast<const_node_ptr>(x)->M_value_field;
		}
		
	public:

		void
		insertBalanced(value_type val)
		{
			insertNode(&M_root(), val);
		}

		void
		insertNode(base_ptr* root, value_type val)
		{
			node_ptr tmp = static_cast<node_ptr>(*root);
			if (!tmp)
			{
				node_ptr New = create_node(val);
				New->init_node(static_cast<node_ptr>(&M_impl.M_header), NULL, NULL);
				M_impl.M_header.M_parent = New;
				M_impl.M_node_count++;
			}
			while (tmp)
			{
				if (val > S_value(tmp))
				{
					if (S_right(tmp))
						tmp = S_right(tmp);
					else
					{
						node_ptr New = create_node(val);
						New->init_node(tmp, NULL, NULL);
						tmp->M_right = New;
						M_impl.M_node_count++;
						return;
					}
				}
				else if (val < S_value(tmp))
				{
					if (S_left(tmp))
						tmp = S_left(tmp);
					else
					{
						node_ptr New = create_node(val);
						New->init_node(tmp, NULL, NULL);
						tmp->M_left = New;
						M_impl.M_node_count++;
						return;
					}
				}
				else if (val == S_value(tmp))
					return;
			}
		}

		int _level;

	private:
		void
		_display(base_ptr root)
		{
			for (int i = 0; i < _level * 2; i++)
				std::cout << " ";
			if (!_level)
				std::cout << " ";
			if (_level)
				std::cout << "│" <<std::endl;
			for (int i = 0; i < _level * 2; i++)
				std::cout << " ";
			if (_level && root->M_parent->M_left && root != root->M_parent->M_left)
				std::cout << "├";
			else if (_level)
				std::cout << "└";
			std::cout << S_value(root) << std::endl;
			++_level;
			if (S_right(root))
			{
				_display(S_right(root));
				--_level;
			}
			if (S_left(root))
			{
				_display(S_left(root));
				--_level;
			}

		}
	public:
		void
		displayTree()
		{
			_level = 0;
			_display(M_root());
			_level = 0;
		}

		void
		displayRoot()
		{
			std::cout << M_begin()->M_value_field << " parent: ";
			std::cout << S_value(M_begin()->M_parent) << std::endl;
			std::cout << S_value(M_begin()->M_left) << " parent: ";
			std::cout << S_value(M_begin()->M_left->M_parent) << std::endl;
			std::cout << S_value(M_begin()->M_right) << " parent: ";
			std::cout << S_value(M_begin()->M_right->M_parent) << std::endl;
		}
		
		Rb_tree()
		: M_impl() {}

		~Rb_tree()
		{
			M_erase(M_begin());
		}

		void
		M_erase(node_ptr x)
		{
			while (x != NULL)
			{
				M_erase(S_right(x));
				node_ptr y = S_left(x);
				destroy_node(x);
				x = y;
			}
		}
		
	

};

//TODO insert node comme dans un bst classique
//TODO spot les erreures de rb_tree
//TODO balance le tree (rotation tout ca tout ca)
//TODO utiliser tout ca pour faire un balanceInsert

}

#endif
