/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:10:27 by alorain           #+#    #+#             */
/*   Updated: 2022/10/19 16:21:38 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include "Rb_tree.hpp"
# include "pair.hpp"
# include "Iterator.hpp"
# include "iterator_traits.hpp"

namespace ft
{
	template<typename Key, typename Compare = std::less<Key> >
	class set 
	{
		public:
			typedef Key 						key_type;
			typedef Key							value_type;
			typedef Compare						key_compare;
			typedef std::allocator<value_type>	allocator_type;

		private:
			typedef typename allocator_type::template rebind<value_type>::other	alloc_type;
			typedef Rb_tree<key_type, value_type, std::_Identity<value_type>,
						key_compare, alloc_type> tree_type;

			tree_type	M_tree;

		public:
			
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class set<Key, Compare>;
				protected:
				Compare comp;

				value_compare(Compare c)
				: comp(c) {}

				public:

				bool
				operator()(const value_type& x, const value_type& y) const
				{
					return comp(x, y);
				}

			};

			typedef typename alloc_type::reference			reference;
			typedef typename alloc_type::const_reference	const_reference;
			typedef typename alloc_type::pointer			pointer;
			typedef typename alloc_type::const_pointer		const_pointer;
			typedef typename tree_type::size_type				size_type;
			typedef typename tree_type::difference_type			difference_type;
			typedef typename tree_type::iterator				iterator;
			typedef typename tree_type::const_iterator			const_iterator;
			typedef typename tree_type::reverse_iterator		reverse_iterator;
			typedef typename tree_type::const_reverse_iterator	const_reverse_iterator;

		set()
		: M_tree() {}

		explicit
		set(const Compare& comp)
		: M_tree(comp) {}

		template<typename InputIt>
		set(InputIt first, InputIt last, const Compare& comp = Compare())
		: M_tree(comp)
		{
			M_tree.insertBalanced(first, last);
		}

		set(const set& other)
		:M_tree(other.M_tree) {}

		~set()
		{
			M_tree.clear();
		}


		set&
		operator=(const set& other)
		{
			M_tree = other.M_tree;
			return *this;
		}

		allocator_type
		get_allocator()
		{
			return allocator_type();
		}

		value_type&
		at(const key_type& key)
		{
			try
			{
				iterator tmp = M_tree.find(key);
				return (*tmp).second;
			}
			catch(std::out_of_range)
			{
				throw;
			}
		}

		value_type&
		operator[](const key_type& key)
		{
			typename tree_type::node_ptr tmp = M_tree.searchNode(key);
			if (tmp == NULL)
				return insert(ft::make_pair<const key_type, value_type>(key, value_type())).first->second;
			return tmp->M_value_field.second;
		}

		const value_type&
		at(const key_type& key) const
		{
		    return *(M_tree.find(key));
		}
         
		iterator
		begin()
		{
			return M_tree.begin();
		}

		const_iterator
		begin() const
		{
			return M_tree.begin();
		}

		iterator
		end()
		{
			return M_tree.end();
		}

		const_iterator
		end() const
		{
			return M_tree.end();
		}

		const_iterator
		cbegin() const
		{
			return M_tree.begin();
		}

		const_iterator
		cend() const
		{
			return M_tree.end();
		}

		reverse_iterator
		rbegin()
		{
			return M_tree.rbegin();
		}

		const_reverse_iterator
		rbegin() const
		{
			return M_tree.rbegin();
		}

		reverse_iterator
		rend()
		{
			return M_tree.rend();
		}

		const_reverse_iterator
		rend() const
		{
			return M_tree.rend();
		}

		const_reverse_iterator
		crbegin() const
		{
			return M_tree.rbegin();
		}

		const_reverse_iterator
		crend() const
		{
			return M_tree.rend();
		}

		bool
		empty() const
		{
			return M_tree.empty();
		}

		size_type
		size() const
		{
			return M_tree.size();
		}

		size_type
		max_size() const
		{
			return M_tree.max_size();
		}

		void
		M_display()
		{
			M_tree.displayTree();
		}

		ft::pair<iterator, bool>
		insert(const value_type& val)
		{
			return M_tree.insertBalanced(val);
		}

		iterator
		insert(iterator pos, const value_type& val)
		{
			return M_tree.insertBalanced(pos, val);
		}

		template<typename InputIt>
		void
		insert(InputIt first, InputIt last)
		{
			while (first != last)
				M_tree.insertBalanced(*(first++));
		}

		void
		erase(iterator pos)
		{
			M_tree.erase(pos);
		}

		void
		erase(iterator first, iterator last)
		{
			while (first != last)
				M_tree.erase(first++);
		}

		size_type
		erase(const key_type& key)
		{
			return M_tree.erase(key);
		}

		void
		swap(set& other)
		{
			M_tree.swap(other.M_tree);
		}

		size_type
		count(const key_type& key) const
		{
			return M_tree.find(key) == M_tree.end() ? 0 : 1;
		}

		iterator
		find(const key_type& key)
		{
			return M_tree.find(key);
		}

		const_iterator
		find(const key_type& key) const
		{
			return M_tree.find(key);
		}

		iterator
		lower_bound(const key_type& key)
		{
			return M_tree.lower_bound(key);
		}

		const_iterator
		lower_bound(const key_type& key) const
		{
			return M_tree.lower_bound(key);
		}

		iterator
		upper_bound(const key_type& key)
		{
			return M_tree.upper_bound(key);
		}

		const_iterator
		upper_bound(const key_type& key) const
		{
			return M_tree.upper_bound(key);
		}

		ft::pair<iterator, iterator>
		equal_range(const key_type& key)
		{
			return M_tree.equal_range(key);
		}

		ft::pair<const_iterator, const_iterator>
		equal_range(const key_type& key) const
		{
			return M_tree.equal_range(key);
		}

		key_compare
		key_comp() const
		{
			return M_tree.key_comp();
		}

		value_compare
		value_comp() const
		{
			return value_compare(M_tree.key_comp());
		}

		void
		clear()
		{
			M_tree.clear();
		}

	template<typename K1, typename C1>
	friend bool
	operator==(const set<K1, C1>& x,
				const set<K1, C1>& y);

	template<typename K1, typename C1>
	friend bool
	operator>(const set<K1, C1>& x,
				const set<K1, C1>& y);

	};

template<typename Key, typename Compare>
inline bool
operator==(const set<Key, Compare>& x,
			const set<Key, Compare>& y)
{
	return x.M_tree == y.M_tree;
}

template<typename Key, typename Compare>
inline bool
operator>(const set<Key, Compare>& x,
			const set<Key, Compare>& y)
{
	return x.M_tree > y.M_tree;
}

template<typename Key, typename Compare>
inline bool
operator!=(const set<Key, Compare>& x,
			const set<Key, Compare>& y)
{
	return !(x == y);
}

template<typename Key, typename Compare>
inline bool
operator<(const set<Key, Compare>& x,
			const set<Key, Compare>& y)
{
	return y > x;
}

template<typename Key, typename Compare>
inline bool
operator>=(const set<Key, Compare>& x,
			const set<Key, Compare>& y)
{
	return !(x < y);
}

template<typename Key, typename Compare>
inline bool
operator<=(const set<Key, Compare>& x,
			const set<Key, Compare>& y)
{
	return !(y < x);
}

template<typename Key, typename Compare>
inline void
swap(set<Key, Compare>& x,
			set<Key, Compare>& y)
{
	x.swap(y);
}


}


#endif
