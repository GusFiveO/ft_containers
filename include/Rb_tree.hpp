/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:25:10 by alorain           #+#    #+#             */
/*   Updated: 2022/10/19 19:37:25 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BNR_HPP
# define BNR_HPP

# include "pair.hpp"
# include "Iterator.hpp"
# include "iterator_traits.hpp"
# include "algorithm.hpp"

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
		if (x->M_right != y)
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
		if (x->M_right != y)
			x = y;
	}
	return x;
}

Rb_tree_node_base*
Rb_decrement(Rb_tree_node_base* x) throw()
{
	//std::cout << "parent left value " << static_cast<Rb_tree_node<int>*>(y->M_left)->M_value_field;
	if (x->M_color == red
       && x->M_parent->M_parent == x)
     x = x->M_right;
	else if (x->M_left)
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
		if (x->M_left != y)
			x = y;
	}
	return x;
}

const Rb_tree_node_base*
Rb_decrement(const Rb_tree_node_base* x) throw()
{
	if (x->M_color == red
       && x->M_parent->M_parent == x)
     x = x->M_right;
	else if (x->M_left)
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
		if (x->M_left != y)
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
	typedef std::ptrdiff_t					difference_type;

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

		self&
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

		self&
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

		base_ptr
		base()
		{
			return M_node;
		}
};

template<typename T>
struct Rb_tree_const_iterator
{
	typedef T 			value_type;
	typedef const T*	pointer;
	typedef const T&	reference;

	typedef Rb_tree_iterator<T>	iterator;

	typedef std::bidirectional_iterator_tag	iterator_category;
	typedef std::ptrdiff_t					difference_type;

	typedef Rb_tree_node_base::const_base_pointer	base_ptr;
	typedef Rb_tree_const_iterator<T>				self;
	typedef const Rb_tree_node<T>*					node_ptr;

		base_ptr	M_node;

		Rb_tree_const_iterator()
		: M_node() {}

		explicit
		Rb_tree_const_iterator(base_ptr ptr)
		: M_node(ptr) {}

		Rb_tree_const_iterator(const iterator& x)
		: M_node(x.M_node) {}

		iterator
		M_const_cast() const
		{
			return iterator(static_cast<typename iterator::node_ptr>
			(const_cast<typename iterator::base_ptr>(M_node)));
		}

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

		self&
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

		self&
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

		base_ptr
		base()
		{
			return M_node;
		}
};


//KeyOfValue define wich part of the pair is the key and if is not a pair define that the key is the value we are using
//Compare is the function we use to define the order in the tree
template<typename Key, typename Val, typename KeyOfValue,
			typename Compare, typename Alloc = std::allocator<Val> >
class Rb_tree
{

	protected:
		typedef Rb_tree_node_base* 			base_ptr;
		typedef const Rb_tree_node_base*	const_base_ptr;

	public:
		typedef Val 				value_type;
		typedef Key					key_type;
		typedef value_type* 		pointer;
		typedef const value_type* 	const_pointer;
		typedef value_type& 		reference;
		typedef const value_type& 	const_reference;
		typedef size_t				size_type;
		typedef std::ptrdiff_t		difference_type;

		typedef Alloc				allocator_type;
		typedef typename Alloc::template rebind<Rb_tree_node<Val> >::other node_allocator;

		typedef Rb_tree_node<Val>* 			node_ptr;
		typedef const Rb_tree_node<Val>*	const_node_ptr;
	
		typedef ft::Rb_tree_iterator<Val> 				iterator;
		typedef ft::Rb_tree_const_iterator<Val>			const_iterator;

		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;


		allocator_type
		get_allocator()
		{
			return allocator_type();
		}

		node_allocator
		M_get_node_allocator() const
		{
			return static_cast<node_allocator>(M_impl);
		}

		Compare
		key_comp() const
		{
			return M_impl.M_key_compare;
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
		destroy_node(base_ptr ptr)
		{
			get_allocator().destroy(&static_cast<node_ptr>(ptr)->M_value_field);
			dealloc_node(static_cast<node_ptr>(ptr));
		}
	
	private:
		template<typename Key_compare>
		struct Rb_tree_impl : public node_allocator
		{
			Key_compare			M_key_compare;
			Rb_tree_node_base	M_header;
			size_type			M_node_count;

			Rb_tree_impl()
			: node_allocator(), M_key_compare() ,M_header(), M_node_count(0)
			{
				M_initialize();
			}

			Rb_tree_impl(const Key_compare& comp, const node_allocator& alloc)
			: node_allocator(alloc), M_key_compare(comp), M_header(), M_node_count(0)
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
		
		Rb_tree_impl<Compare> M_impl;

	public:

		iterator
		M_lower_bound(base_ptr first, base_ptr last, const key_type& key)
		{
			while (first != NULL)
			{
				if (!M_impl.M_key_compare(S_key(first), key))
				{
					last = first;
					first = S_left(first);
				}
				else
				{
					first = S_right(first);
				}
			}
			return iterator(last);
		}

		iterator
		lower_bound(const key_type& key)
		{
			return M_lower_bound(M_begin(), M_end(), key);
		}

		const_iterator
		M_lower_bound(const_base_ptr first, const_base_ptr last, const key_type& key) const
		{
			while (first != NULL)
			{
				if (!M_impl.M_key_compare(S_key(first), key))
				{
					last = first;
					first = S_left(first);
				}
				else
				{
					first = S_right(first);
				}
			}
			return const_iterator(last);
		}

		const_iterator
		lower_bound(const key_type& key) const
		{
			return M_lower_bound(M_begin(), M_end(), key);
		}

		iterator
		M_upper_bound(base_ptr first, base_ptr last, const key_type& key)
		{
			while (first != NULL)
			{
				if (M_impl.M_key_compare(key, S_key(first)))
				{
					last = first;
					first = S_left(first);
				}
				else
				{
					first = S_right(first);
				}
			}
			return iterator(last);
		}

		iterator
		upper_bound(const key_type& key)
		{
			return M_upper_bound(M_begin(), M_end(), key);
		}

		const_iterator
		M_upper_bound(const_base_ptr first, const_base_ptr last, const key_type& key) const
		{
			while (first != NULL)
			{
				if (M_impl.M_key_compare(key, S_key(first)))
				{
					last = first;
					first = S_left(first);
				}
				else
				{
					first = S_right(first);
				}
			}
			return const_iterator(last);
		}

		const_iterator
		upper_bound(const key_type& key) const
		{
			return M_upper_bound(M_begin(), M_end(), key);
		}

		ft::pair<iterator, iterator>
		equal_range(const key_type& key)
		{
			return ft::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key));
		}

		ft::pair<const_iterator, const_iterator>
		equal_range(const key_type& key) const
		{
			return ft::make_pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key));
		}
	
	protected:

		base_ptr&
		M_root()
		{
			return M_impl.M_header.M_parent;
		}

		const_base_ptr
		M_root() const
		{
			return M_impl.M_header.M_parent;
		}

		base_ptr&
		M_leftmost()
		{
			return M_impl.M_header.M_left;
		}

		const_base_ptr
		M_leftmost() const
		{
			return M_impl.M_header.M_left;
		}

		base_ptr&
		M_rightmost()
		{
			return M_impl.M_header.M_right;
		}

		const_base_ptr
		M_rightmost() const
		{
			return M_impl.M_header.M_right;
		}

		node_ptr
		M_begin()
		{
			return static_cast<node_ptr>(this->M_impl.M_header.M_parent);
		}

		const_node_ptr
		M_begin() const
		{
			return static_cast<const_node_ptr>(this->M_impl.M_header.M_parent);
		}

		node_ptr
		M_end()
		{
			return static_cast<node_ptr>(&this->M_impl.M_header);
		}

		const_node_ptr
		M_end() const
		{
			return static_cast<const_node_ptr>(&this->M_impl.M_header);
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

		static const key_type&
		S_key(const_base_ptr node)
		{
			return KeyOfValue()(S_value(node));
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

		node_ptr
		M_searchNode(key_type key)
		{
			node_ptr tmp = static_cast<node_ptr>(M_root());
			while (tmp && S_key(tmp) != key)
			{
				if (tmp == NULL)
					return NULL;
				else if (M_impl.M_key_compare(S_key(tmp), key))
					tmp = S_right(tmp);
				else if (M_impl.M_key_compare(key, S_key(tmp)))
					tmp = S_left(tmp);
			}
			return tmp;
		}

		ft::pair<iterator, bool>
		M_insertBalanced(base_ptr root, const value_type& val)
		{
			node_ptr newNode;
			newNode = M_insertNode(root, val);

			if (!newNode)
				return ft::make_pair<iterator, bool>(find(KeyOfValue()(val)), false);
			if (M_impl.M_key_compare(S_key(M_impl.M_header.M_right), KeyOfValue()(val)))
				M_impl.M_header.M_right = newNode;
			else if (M_impl.M_key_compare(KeyOfValue()(val), S_key(M_impl.M_header.M_left)))
				M_impl.M_header.M_left = newNode;

			newNode = M_insertFixTree(newNode);
			return ft::make_pair<iterator, bool>(iterator(newNode), true);
		}


		//insert a newNode the closest to the iterator's one passed in parameter
		// 1st case the iterator is the end one so we need to know if he is greater of the rightmost or not
		//	-if its greater we need to insert balanced with rightmost as root
		//	-else insert balanced with M_root() as root
		// 2nd case 
		iterator
		M_insertBalanced(const_iterator pos, const value_type& val)
		{
			node_ptr newNode;
			if (pos != end() && begin() != end() && M_impl.M_key_compare(S_key(M_root()), KeyOfValue()(*pos))
				&& M_impl.M_key_compare(S_key(M_root()), KeyOfValue()(val)))
			{
				while (M_impl.M_key_compare(KeyOfValue()(val), KeyOfValue()(*pos)))
					++pos;
				node_ptr close = M_searchNode(KeyOfValue()(*pos));
				newNode = M_insertNode(close, val);
			}
			else
				newNode = M_insertNode(M_root(), val);

			if (!newNode)
				return iterator(find(KeyOfValue()(val)));
			if (M_impl.M_key_compare(S_key(M_impl.M_header.M_right), KeyOfValue()(val)))
				M_impl.M_header.M_right = newNode;
			else if (M_impl.M_key_compare(KeyOfValue()(val), S_key(M_impl.M_header.M_left)))
				M_impl.M_header.M_left = newNode;

			M_insertFixTree(newNode);
			return iterator(newNode);
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

		node_ptr
		M_insertFixTree(node_ptr newNode)
		{
			node_ptr ret = newNode;
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
			return ret;
		}


		node_ptr
		M_insertNode(base_ptr root, const value_type &val)
		{
			node_ptr tmp = static_cast<node_ptr>(root);
			if (!tmp)
			{
				node_ptr New = static_cast<node_ptr>(create_node(val));

				New->init_node(black, static_cast<node_ptr>(&M_impl.M_header), NULL, NULL);
				M_impl.M_header.M_parent = New;
				M_impl.M_node_count++;
				M_impl.M_header.M_right = New;
				M_impl.M_header.M_left = New;
				return New;
			}
			while (tmp)
			{
				if (M_impl.M_key_compare(S_key(tmp), KeyOfValue()(val)))
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
				if (M_impl.M_key_compare(KeyOfValue()(val), S_key(tmp)))
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
				if (KeyOfValue()(val) == S_key(tmp))
					break;
			}
			return NULL;
		}
		
		void
		M_removeBalanced(value_type val)
		{
			base_ptr x = M_searchNode(KeyOfValue()(val));
			if (!x)
				return;
			if (val == S_value(M_rightmost()))
				M_impl.M_header.M_right = x->M_parent;
			if (val == S_value(M_leftmost()))
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
			M_impl.M_node_count--;
			M_removeNode(x);
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

		node_ptr
		M_clone_node(const_node_ptr node)
		{
			node_ptr ret = create_node(node->M_value_field);
			ret->M_color = node->M_color;
			ret->M_right = NULL;
			ret->M_left = NULL;
			return ret;
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
			std::cout << S_key(root) << ", ";
			std::cout << S_value(root).second << std::endl;
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
			std::cout << std::endl;
		}

	public:

		void
		displayTree()
		{
			_level = 0;
			_display(M_root());
			_level = 0;
		}
		
		Rb_tree()
		: M_impl() {}

		Rb_tree(const Compare& comp)
		: M_impl(comp, Alloc()) {}

		Rb_tree(const Rb_tree& copy)
		: M_impl(copy.M_impl.M_key_compare, copy.M_get_node_allocator())
		{
			if (copy.M_root())
			{
				M_root() = M_copy(copy.M_begin(), M_end());
				M_rightmost() = S_maximum(M_root());
				M_leftmost() = S_minimum(M_root());
				M_impl.M_node_count = copy.size();
			}
		}

		~Rb_tree()
		{
			M_erase(M_begin());
		}

		Rb_tree&
		operator=(const Rb_tree& assign)
		{
			if (this != &assign)
			{
				clear();
				M_impl.M_key_compare = assign.M_impl.M_key_compare;
				if (assign.M_root() != NULL)
				{
					M_root() = M_copy(assign.M_begin(), M_end());
					M_leftmost() = S_minimum(M_root());
					M_rightmost() = S_maximum(M_root());
					M_impl.M_node_count = assign.size();
				}
			}
			return *this;
		}

		size_type
		removeBalanced(const key_type& key)
		{
			node_ptr search = searchNode(key);
			if (!search)
				return 0;
			M_removeBalanced(search->M_value_field);
			return 1;
		}

		template<typename InputIt>
		void
		insertBalanced(InputIt first, InputIt last)
		{
			while (first != last)
				insertBalanced(*first++);
		}

		ft::pair<iterator, bool>
		insertBalanced(const value_type &val)
		{
			return M_insertBalanced(M_root(), val);
		}

		iterator
		insertBalanced(const_iterator pos, const value_type& val)
		{
			return M_insertBalanced(pos, val);
		}

		//node_ptr
		//searchNode(value_type val)
		//{
		//	return M_searchNode(KeyOfValue()(val));
		//}

		node_ptr
		searchNode(key_type key)
		{
			return M_searchNode(key);
		}

		iterator
		begin()
		{
			return iterator(static_cast<node_ptr>(M_impl.M_header.M_left));
		}

		iterator
		end()
		{
			return iterator(static_cast<node_ptr>(&M_impl.M_header));
		}

		const_iterator
		begin() const
		{
			return const_iterator(static_cast<const_node_ptr>(M_impl.M_header.M_left));
		}

		const_iterator
		end() const
		{
			return const_iterator(static_cast<const_node_ptr>(&M_impl.M_header));
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

		bool
		empty() const 
		{
			return M_impl.M_node_count == 0;
		}

		size_type
		size() const
		{
			return M_impl.M_node_count;
		}

		size_type
		max_size() const
		{
			return M_get_node_allocator().max_size();
		}


		void
		swap(Rb_tree& other)
		{
			if (M_root() == NULL)
			{
				if (other.M_root() != NULL)
				{
					M_root() = other.M_root();
					M_leftmost() = other.M_leftmost();
					M_rightmost() = other.M_rightmost();
					M_root()->M_parent = M_end();

					other.M_root() = NULL;
					other.M_leftmost() = other.M_end();
					other.M_rightmost() = other.M_end();
				}
			}
			else if (other.M_root() == NULL)
			{
				other.M_root() = M_root();
				other.M_leftmost() = M_leftmost();
				other.M_rightmost() = M_rightmost();
				other.M_root()->M_parent = other.M_end();

				M_root() = NULL;
				M_leftmost() = M_end();
				M_rightmost() = M_end();

			}
			else
			{
				std::swap(M_root(), other.M_root());
				std::swap(M_leftmost(), other.M_leftmost());
				std::swap(M_rightmost(), other.M_rightmost());

				M_root()->M_parent = M_end();
				other.M_root()->M_parent = other.M_end();
			}

			std::swap(M_impl.M_node_count, other.M_impl.M_node_count);
			std::swap(M_impl.M_key_compare, other.M_impl.M_key_compare);

		}

		iterator
		find(const key_type& key)
		{
			iterator j = M_lower_bound(M_begin(), M_end(), key);

			return (j == end() || M_impl.M_key_compare(key, S_key(j.M_node))) ? end() : j;
		}

		const_iterator
		find(const key_type& key) const
		{
			const_iterator j = M_lower_bound(M_begin(), M_end(), key);

			return (j == end() || M_impl.M_key_compare(key, S_key(j.M_node))) ? end() : j;
		}

	private:

		//the first and last elem to the function
		//it will copy starting with the right subtree
		//than it gonna loop throught the left one 
		//if a node get a right subtree he recursively copy it
		//then he gonna copy deeper on the left
		node_ptr
		M_copy(const_node_ptr first, node_ptr parent)
		{
			node_ptr top = M_clone_node(first);
			top->M_parent = parent;

			if (first->M_right)
				top->M_right = M_copy(S_right(first), top);

			first = S_left(first);
			parent = top;
			while (first != NULL)
			{
				node_ptr y = M_clone_node(first);
				parent->M_left = y;
				y->M_parent = parent;
				if (first->M_right)
					y->M_right = M_copy(S_right(first), y);
				parent = y;
				first = S_left(first);
			}
			return top;
		}
		
		void
		M_erase_sev(const_iterator first, const_iterator last)
		{
			const_iterator tmp = first;
			while (first != last)
			{
				first++;
				M_removeBalanced(*(tmp.M_const_cast()));
				tmp = first;
			}
		}

	public:

		void
		erase(iterator pos)
		{
			removeBalanced(KeyOfValue()(*pos));
		}

		void
		erase(const_iterator pos)
		{
			removeBalanced(KeyOfValue()(*pos));
		}

		size_type
		erase(const key_type& k)
		{
			return removeBalanced(k);
		}
		iterator
		erase(const_iterator first, const_iterator last)
		{
			M_erase_sev(first, last);
			return last.M_const_cast();
		}
		
		void
		clear()
		{
			M_erase(M_begin());
			M_leftmost() = M_end();
			M_root() = NULL;
			M_rightmost() = M_end();
			M_impl.M_node_count = 0;
		}
};

template<typename Key, typename Val, typename KeyOfValue,
					typename Compare, typename Alloc>
inline bool
operator==(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
			const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{
	return x.size() == y.size()
			&& std::equal(x.begin(), x.end(), y.begin());
}


template<typename Key, typename Val, typename KeyOfValue,
					typename Compare, typename Alloc>
inline bool
operator<(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
			const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{
	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template<typename Key, typename Val, typename KeyOfValue,
					typename Compare, typename Alloc>
inline bool
operator!=(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
			const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{
	return !(x == y);
}

template<typename Key, typename Val, typename KeyOfValue,
					typename Compare, typename Alloc>
inline bool
operator>(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
			const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{
	return y < x;
}

template<typename Key, typename Val, typename KeyOfValue,
					typename Compare, typename Alloc>
inline bool
operator<=(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
			const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{
	return !(x > y);
}

template<typename Key, typename Val, typename KeyOfValue,
					typename Compare, typename Alloc>
inline bool
operator>=(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
			const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{
	return !(x < y);
}

template<typename Key, typename Val, typename KeyOfValue,
					typename Compare, typename Alloc>
inline void
swap(const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& x,
			const Rb_tree<Key, Val, KeyOfValue, Compare, Alloc>& y)
{
	x.swap(y);
}

}

#endif
