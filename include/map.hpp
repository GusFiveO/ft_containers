/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:10:27 by alorain           #+#    #+#             */
/*   Updated: 2022/10/17 20:56:43 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "Rb_tree.hpp"
# include "pair.hpp"
# include "Iterator.hpp"

namespace ft
{
	template<typename Key, typename Val,
		typename Compare = std::less<Key>, typename Alloc = std::allocator<ft::pair<const Key, Val> > >
	class map 
	{
			typedef Key 						key_type;
			typedef Val							mapped_type;
			typedef ft::pair<const Key, Val>	value_type;
			typedef Compare						key_compare;
			typedef Alloc						allocator_type;

		private:
			typedef typename Alloc::template rebind<value_type>::other	pair_alloc_type;
			typedef Rb_tree<key_type, value_type, std::_Select1st<value_type>,
						key_compare, pair_alloc_type> tree_type;

			tree_type	M_tree;

		public:
			typedef typename pair_alloc_type::reference			reference;
			typedef typename pair_alloc_type::const_reference	const_reference;
			typedef typename pair_alloc_type::pointer			pointer;
			typedef typename pair_alloc_type::const_pointer		const_pointer;
			typedef typename tree_type::size_type				size_type;
			typedef typename tree_type::difference_type			difference_type;
			typedef typename tree_type::iterator				iterator;
			typedef typename tree_type::const_iterator			const_iterator;

		map()
		: M_tree() {}

		explicit
		map(const Compare& comp)
		: M_tree(comp) {}

		template<typename InputIt>
		map(InputIt first, InputIt last, const Compare& comp = Compare())
		: M_tree(comp)
		{
			M_tree.insertBalanced(first, last);
		}

		map(const map& other)
		:M_tree(other.M_tree) {}

		~map()
		{
			M_tree.clear();
		}


		map&
		operator=(const map& other)
		{
			M_tree = other.M_tree;
		}

		allocator_type
		get_allocator()
		{
			return allocator_type();
		}

		mapped_type&
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

		mapped_type&
		operator[](const key_type& key)
		{
			typename tree_type::node_ptr tmp = M_tree.searchNode(key);
			if (!tmp)
				M_tree.insertBalanced(ft::make_pair<const key_type, mapped_type>(key, mapped_type()));
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
		swap(map& other)
		{
			M_tree.swap(other.M_tree);
		}

		size_type
		count(const key_type& key)
		{
			if (!M_tree.searchNode(key))
				return 0;
			return 1;
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

		void
		clear()
		{
			M_tree.clear();
		}

	};
}


#endif
