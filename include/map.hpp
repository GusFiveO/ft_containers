/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:10:27 by alorain           #+#    #+#             */
/*   Updated: 2022/10/13 17:03:12 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

namespace ft
{
	template<typename Key, typename Val,
		typename Compare = std::less<Key>, typename Alloc = std::allocator<ft::pair<const Key, Val> > >
	class map 
	{
			typedef typename Key 						key_type;
			typedef typename ft::pair<const Key, Val>	value_type;
			typedef typename Compare					key_compare;
			typedef typename Alloc						allocator_type;

		private:
			typedef Alloc::template rebind<value_type>::other	pair_alloc_type;
			typedef Rb_tree<key_type, value_type, std::_Select1st<value_type>,
						key_compare, pair_alloc_type> tree_type;

			tree_type	M_tree;

		public:
			typedef pair_alloc_type::reference			reference;
			typedef pair_alloc_type::const_reference	const_reference;
			typedef pair_alloc_type::pointer			pointer;
			typedef pair_alloc_type::const_pointer		const_pointer;
			typedef tree_type::size_type				size_type;
			typedef tree_type::difference_type			difference_type;
			typedef tree_type::iterator					iterator;
			typedef tree_type::const_iterator			const_iterator;

		map()
		: M_tree() {}

		explicit
		map(const Compare& comp)
		: M_tree(comp) {}
	};
}


#endif
