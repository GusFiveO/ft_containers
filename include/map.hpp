/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:10:27 by alorain           #+#    #+#             */
/*   Updated: 2022/10/13 20:10:47 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "Rb_tree.hpp"
# include "pair.hpp"

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
		empty()
		{
			return M_tree.empty();
		}

		size_type
		size()
		{
			return M_tree.size();
		}

		size_type
		max_size()
		{
			return M_tree.max_size();
		}

		void
		M_display()
		{
			M_tree.displayTree();
		}

		void
		clear()
		{
			M_tree.clear();
		}

	};
}


#endif
