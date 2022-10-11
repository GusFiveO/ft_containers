/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:25:10 by alorain           #+#    #+#             */
/*   Updated: 2022/10/11 18:23:21 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BNR_HPP
# define BNR_HPP

# include "pair.hpp"

namespace ft
{

	enum Rb_tree_color {red = false, black = true};

struct Rb_tree_node_base
{
	typedef Rb_tree_node_base* 			base_pointer;
	typedef const Rb_tree_node_base*	const_base_pointer;
	
	Rb_tree_color	M_color;
	base_pointer 	M_parent;
	base_pointer	M_right;
	base_pointer	M_left;

	Rb_tree_node_base(Rb_tree_color color = red, base_pointer parent = NULL, base_pointer right = NULL, base_pointer left = NULL)
	: M_color(color), M_parent(parent), M_right(right), M_left(left) {}

	static base_pointer
	S_minimum(base_pointer root)
	{
		while (root->M_left != 0)
			root = root->M_left;
		return root;
	}

	static const_base_pointer
	S_minimum(const_base_pointer root)
	{
		while (root->M_left != 0)
			root = root->M_left;
		return root;
	}

	static base_pointer
	S_maximum(base_pointer root)
	{
		while (root->M_right != 0)
			root = root->M_right;
		return root;
	}

	static const_base_pointer
	S_maximum(const_base_pointer root)
	{
		while (root->M_right != 0)
			root = root->M_right;
		return root;
	}
};

template<typename Val>
struct Rb_tree_node : public Rb_tree_node_base 
{
	typedef Rb_tree_node<Val>*	node_ptr;
	Val 						M_value_field;

	void
	init_node(Rb_tree_color color, base_pointer parent, base_pointer right, base_pointer left)
	{
		M_color = color;
		M_parent = parent;
		M_right = right;
		M_left = left;
	}
};

Rb_tree_node_base*
Rb_increment(Rb_tree_node_base* x) throw()
{
	if (x->M_right)
	{
		x = x->M_right;
		while (x->M_left)
			x = x->M_left;
	}
	else
	{
		Rb_tree_node_base* y = x->M_parent;
		while (x == y->M_right)
		{
			x = y;
			y = y->M_parent;
		}
		if (y->M_parent == x)
			x = y->M_left;
		else if (x->M_right != y)
			x = y;
	}
	return x;
}


const Rb_tree_node_base*
Rb_increment(const Rb_tree_node_base* x) throw()
{
	if (x->M_right)
	{
		x = x->M_right;
		while (x->M_left)
			x = x->M_left;
	}
	else
	{
		Rb_tree_node_base* y = x->M_parent;
		while (x == y->M_right)
		{
			x = y;
			y = y->M_parent;
		}
		if (y->M_parent == x)
			x = y->M_left;
		else if (x->M_right != y)
			x = y;
	}
	return x;
}

Rb_tree_node_base*
Rb_decrement(Rb_tree_node_base* x) throw()
{
	if (x->M_left)
	{
		x = x->M_left;
		while (x->M_right)
			x = x->M_right;
	}
	else
	{
		Rb_tree_node_base* y = x->M_parent;
		while (x == y->M_left)
		{
			x = y;
			y = y->M_parent;
		}
		if (y->M_parent == x)
			x = y->M_right;
		else if (x->M_left != y)
			x = y;
	}
	return x;
}

const Rb_tree_node_base*
Rb_decrement(const Rb_tree_node_base* x) throw()
{
	if (x->M_left)
	{
		x = x->M_left;
		while (x->M_right)
			x = x->M_right;
	}
	else
	{
		Rb_tree_node_base* y = x->M_parent;
		while (x == y->M_left)
		{
			x = y;
			y = y->M_parent;
		}
		if (y->M_parent == x)
			x = y->M_right;
		else if (x->M_left != y)
			x = y;
	}
	return x;
}

template<typename T>
struct Rb_tree_iterator
{
	typedef T 	value_type;
	typedef T*	pointer;
	typedef T&	reference;

	typedef std::bidirectional_iterator_tag	iterator_category;
	typedef ptrdiff_t						difference_type;

	typedef Rb_tree_node_base::base_pointer	base_ptr;
	typedef Rb_tree_iterator<T>				self;
	typedef Rb_tree_node<T>*				node_ptr;

		base_ptr	M_node;

		Rb_tree_iterator()
		: M_node() {}

		explicit
		Rb_tree_iterator(base_ptr ptr)
		: M_node(ptr) {}

		reference
		operator*() const
		{
			return static_cast<node_ptr>(M_node)->M_value_field;
		}

		pointer
		operator->() const
		{
			return &(static_cast<node_ptr>(M_node)->M_value_field);
		}

		self
		operator++()
		{
			M_node = Rb_increment(M_node);
			return *this;
		}

		self
		operator++(int)
		{
			self tmp = *this;
			M_node = Rb_increment(M_node);
			return tmp;
		}

		self
		operator--()
		{
			M_node = Rb_decrement(M_node);
			return *this;
		}

		self
		operator--(int)
		{
			self tmp = *this;
			M_node = Rb_decrement(M_node);
			return tmp;
		}

		bool
		operator==(const self& rhs) const
		{
			return M_node == rhs.M_node;
		}

		bool
		operator!=(const self& rhs) const
		{
			return M_node != rhs.M_node;
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

		base_ptr
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
		destroy_node(base_ptr ptr)
		{
			get_allocator().destroy(&static_cast<node_ptr>(ptr)->M_value_field);
			dealloc_node(static_cast<node_ptr>(ptr));
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
					this->M_header.M_color = red;
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

		static base_ptr
		S_minimum(base_ptr root)
		{
			return Rb_tree_node_base::S_minimum(root);
		}

		static const_base_ptr
		S_minimum(const_base_ptr root)
		{
			return Rb_tree_node_base::S_minimum(root);
		}

		static base_ptr
		S_maximum(base_ptr root)
		{
			return Rb_tree_node_base::S_maximum(root);
		}

		static const_base_ptr
		S_maximum(const_base_ptr root)
		{
			return Rb_tree_node_base::S_maximum(root);
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
		removeBalanced(value_type val)
		{
			M_removeBalanced(val);
		}

		void
		insertBalanced(value_type val)
		{
			M_insertBalanced(val);
		}

		node_ptr
		searchNode(value_type val)
		{
			return M_searchNode(val);
		}

	protected:

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
		
		void
		M_removeBalanced(value_type val)
		{
			base_ptr x = M_searchNode(val);
			if (val == S_value(S_maximum(M_root())))
				M_impl.M_header.M_right = x->M_parent;
			if (val == S_value(S_minimum(M_root())))
			{
				if (x->M_right)
				{
					base_ptr tmp = x->M_right;
					while (tmp->M_left)
						tmp = tmp->M_left;
					M_impl.M_header.M_left = tmp;
				}
				else
					M_impl.M_header.M_left = x->M_parent;
			}
			M_removeNode(x);
		}

		void
		M_insertBalanced(value_type val)
		{
			node_ptr newNode;
			newNode = M_insertNode(val);
			if (val > S_value(M_impl.M_header.M_right))
				M_impl.M_header.M_right = newNode;
			if (val < S_value(M_impl.M_header.M_left))
				M_impl.M_header.M_left = newNode;
			M_insertFixTree(newNode);
		}
		
		node_ptr
		M_searchNode(value_type val)
		{
			node_ptr tmp = static_cast<node_ptr>(M_root());
			if (tmp == NULL)
				return NULL;
			while (S_value(tmp) != val)
			{
				if (val > S_value(tmp))
					tmp = S_right(tmp);
				if (val < S_value(tmp))
					tmp = S_left(tmp);
			}
			return tmp;
		}

		void
		M_leftRotate(base_ptr newNode)
		{
			base_ptr y = newNode->M_right;

			newNode->M_right = y->M_left;
			if (y->M_left != NULL)
				y->M_left->M_parent = newNode;
			y->M_parent = newNode->M_parent;
			if (newNode == M_root())
				M_root() = y;
			else if (newNode == newNode->M_parent->M_left)
				newNode->M_parent->M_left = y;
			else if (newNode == newNode->M_parent->M_right)
				newNode->M_parent->M_right = y;
			y->M_left = newNode;
			newNode->M_parent = y;
		}

		void
		M_rightRotate(base_ptr newNode)
		{
			base_ptr y = newNode->M_left;

			newNode->M_left = y->M_right;
			if (y->M_right != NULL)
				y->M_right->M_parent = newNode;
			y->M_parent = newNode->M_parent;
			if (newNode == M_root())
				M_root() = y;
			else if (newNode == newNode->M_parent->M_right)
				newNode->M_parent->M_right = y;
			else if (newNode == newNode->M_parent->M_left)
				newNode->M_parent->M_left = y;
			y->M_right = newNode;
			newNode->M_parent = y;
		}

		void
		M_insertFixTree(node_ptr newNode)
		{
			while (newNode != M_root() && newNode->M_parent->M_color == red)
			{
				if (newNode->M_parent == newNode->M_parent->M_parent->M_left)
				{
					node_ptr uncle = static_cast<node_ptr>(newNode->M_parent->M_parent->M_right);

					if (uncle && uncle->M_color == red)
					{
						newNode->M_parent->M_color = black;
						newNode->M_parent->M_parent->M_color = red;
						uncle->M_color = black;
						newNode = static_cast<node_ptr>(newNode->M_parent->M_parent);
					}
					else 
					{
						if (newNode == newNode->M_parent->M_right)
						{
							newNode = static_cast<node_ptr>(newNode->M_parent);
							M_leftRotate(newNode);
						}
						newNode->M_parent->M_color = black;
						newNode->M_parent->M_parent->M_color = red;
						M_rightRotate(static_cast<node_ptr>(newNode->M_parent->M_parent));
					}
				}
				else
				{
					node_ptr uncle = static_cast<node_ptr>(newNode->M_parent->M_parent->M_left);

					if (uncle && uncle->M_color == red)
					{
						newNode->M_parent->M_color = black;
						newNode->M_parent->M_parent->M_color = red;
						uncle->M_color = black;
						newNode = static_cast<node_ptr>(newNode->M_parent->M_parent);
					}
					else
					{
						if (newNode == newNode->M_parent->M_left)
						{
							newNode = static_cast<node_ptr>(newNode->M_parent);
							M_rightRotate(newNode);
						}
						newNode->M_parent->M_color = black;
						newNode->M_parent->M_parent->M_color = red;
						M_leftRotate(static_cast<node_ptr>(newNode->M_parent->M_parent));
					}
				}
			}
			static_cast<node_ptr>(M_root())->M_color = black;
		}


		node_ptr
		M_insertNode(value_type val)
		{
			node_ptr tmp = static_cast<node_ptr>(M_root());
			if (!tmp)
			{
				node_ptr New = static_cast<node_ptr>(create_node(val));

				New->init_node(black, static_cast<node_ptr>(&M_impl.M_header), NULL, NULL);
				M_impl.M_header.M_parent = New;
				M_impl.M_node_count++;
				return New;
			}
			while (tmp)
			{
				if (val > S_value(tmp))
				{
					if (S_right(tmp))
						tmp = S_right(tmp);
					else
					{
						node_ptr New = static_cast<node_ptr>(create_node(val));

						New->init_node(red, tmp, NULL, NULL);
						tmp->M_right = New;
						M_impl.M_node_count++;
						return New;
					}
				}
				else if (val < S_value(tmp))
				{
					if (S_left(tmp))
						tmp = S_left(tmp);
					else
					{
						node_ptr New = static_cast<node_ptr>(create_node(val));

						New->init_node(red, tmp, NULL, NULL);
						tmp->M_left = New;
						M_impl.M_node_count++;
						return New;
					}
				}
				else if (val == S_value(tmp))
					return tmp;
			}
			return NULL;
		}

		void
		M_transplant(base_ptr u, base_ptr v)
		{
			if (u == M_root())
				M_root() = v;
			else if (u == u->M_parent->M_right)
				u->M_parent->M_right = v;
			else
				u->M_parent->M_left = v;
			if (v)
				v->M_parent = u->M_parent;
		}


		// 3 case :
		// 1) the right is NULL so i can transplant to the left
		// 2) the left is NULL so i can transplant to the right
		// 3) both aren't NULL so i have to take the smallest element of the right subtree
		// 		then this element need to take the place of my new element
		base_ptr
		M_removeNode(base_ptr z)
		{
			base_ptr ret = NULL;
			base_ptr tmp = NULL;
			Rb_tree_color tmp_color = red;
			if (z->M_left == NULL)
			{
				ret = z->M_right;
				M_transplant(z, z->M_right);
			}
			else if (z->M_right == NULL)
			{
				ret = z->M_left;
				M_transplant(z, z->M_left);
			}
			else
			{
				tmp = S_minimum(z->M_right);

				tmp_color = tmp->M_color;
				ret = tmp->M_right;
				if (tmp->M_parent == z && ret)
					ret->M_parent = tmp;
				else
				{
					M_transplant(tmp, tmp->M_right);
					tmp->M_right = z->M_right;
					if (tmp->M_right)
						tmp->M_right->M_parent = tmp;
				}
				M_transplant(z, tmp);
				tmp->M_left = z->M_left;
				tmp->M_left->M_parent = tmp;
				tmp->M_color = z->M_color;
			}
			destroy_node(z);
			if (tmp_color == black)
			{
				M_removeFixTree(ret);
			}
			return ret;	
		}


		// 4 case 
		// 1) the sibling is red
		// 2) the sibling is black and both of his child are black
		// 3) the sibling is black and his left child is red and the other black
		// 4) the sibling is black and his right child is black
		// all of these rules are not exclusive
		void
		M_removeFixTree(base_ptr x)
		{
			base_ptr sibling = NULL;
			while (x && x != M_root() && x->M_color == black)
			{
				if (x == x->M_parent->M_left)
				{
					sibling = x->M_parent->M_right;

					if (sibling->M_color == red)
					{
						sibling->M_color = black;
						x->M_parent->M_color = red;
						M_leftRotate(x->M_parent);
						sibling = x->M_parent->M_right;
					}
					if ((sibling->M_left == NULL || sibling->M_left->M_color == black)
							&& (sibling->M_right == NULL || sibling->M_right->M_color == black))
					{
						sibling->M_color = red;
						x = x->M_parent;
						x->M_parent = x->M_parent->M_parent;
					}
					else
					{
						if (sibling->M_right == NULL || sibling->M_right->M_color == black)
						{
							sibling->M_left->M_color = black;
							sibling->M_color = red;
							M_rightRotate(sibling);
							sibling = x->M_parent->M_right;
						}
						sibling->M_color = x->M_parent->M_color;
						x->M_parent->M_color = black;
						if (sibling->M_right)
							sibling->M_right->M_color = black;
						M_leftRotate(x->M_parent);
						x = M_root();
					}
				}
				else
				{
					sibling = x->M_parent->M_left;

					if (sibling->M_color == red)
					{
						sibling->M_color = black;
						x->M_parent->M_color = red;
						M_rightRotate(x->M_parent);
						sibling = x->M_parent->M_left;
					}
					if ((sibling->M_right == NULL || sibling->M_right->M_color == black)
							&& (sibling->M_left == NULL || sibling->M_left->M_color == black))
					{
						sibling->M_color = red;
						x = x->M_parent;
					}
					else
					{
						if (sibling->M_left == NULL || sibling->M_left->M_color == black)
						{
							sibling->M_right->M_color = black;
							sibling->M_color = red;
							M_leftRotate(sibling);
							sibling = x->M_parent->M_left;
						}
						sibling->M_color = x->M_parent->M_color;
						x->M_parent->M_color = black;
						if (sibling->M_left)
							sibling->M_left->M_color = black;
						M_rightRotate(x->M_parent);
						x = M_root();
					}
				}
			}
			if (x)
				x->M_color = black;
		}

	private:
		int _level;

		void
		_display(base_ptr root)
		{
			if (!root)
				return;
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
			if (root->M_color == red)
				std::cout << "\033[31m";
			std::cout << S_value(root) << std::endl;
			if (root->M_color == red)
				std::cout << "\033[0m";
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

		typedef ft::Rb_tree_iterator<Val> 				iterator;
		typedef const ft::Rb_tree_iterator<Val>			const_iterator;

		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;


		void
		displayTree()
		{
			_level = 0;
			_display(M_root());
			_level = 0;
		}
		
		Rb_tree()
		: M_impl() {}

		~Rb_tree()
		{
			M_erase(M_begin());
		}

		iterator
		begin()
		{
			return iterator(M_impl.M_header.M_left);
		}

		iterator
		end()
		{
			return iterator(&M_impl.M_header);
		}

		const_iterator
		begin() const
		{
			return const_iterator(M_impl.M_header.M_left);
		}

		const_iterator
		end() const
		{
			return const_iterator(&M_impl.M_header);
		}

		reverse_iterator
		rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator
		rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator
		rbegin() const
		{
			return const_reverse_iterator(end());
		}

		const_reverse_iterator
		rend() const
		{
			return const_reverse_iterator(begin());
		}

};


}

#endif
