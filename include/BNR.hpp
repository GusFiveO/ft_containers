/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BNR.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:25:10 by alorain           #+#    #+#             */
/*   Updated: 2022/10/05 17:43:25 by alorain          ###   ########.fr       */
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
	typedef Rb_tree_node<Val>*	link_type;
	Val 						M_value_field;
};


template<typename Val, typename Alloc = std::allocator<Val> >
class Rb_tree
{

//	protected:
//		typedef typename Rb_tree_node_base<Val>* 			base_ptr;
//		typedef typename const Rb_tree_node_base<Val>*		const_base_ptr;

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
			get_allocator().destroy(ptr->M_value);
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

		node_ptr
		M_begin()
		{
			return static_cast<node_ptr>(this->M_impl.M_header.M_parent);
		}
		
	public:
		void
		insertNode(value_type val)
		{
			node_ptr tmp = create_node(val);
			M_impl.M_header.M_parent = tmp;
		}

		void
		displayRoot()
		{
			std::cout << M_begin()->M_value_field << std::endl;
		}
		

		
	

};


}

#endif
