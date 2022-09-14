/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:42:48 by alorain           #+#    #+#             */
/*   Updated: 2022/09/14 17:44:04 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft
{
//@{
  /**
   *  @defgroup iterator_tags Iterator Tags
   *  These are empty types, used to distinguish different iterators.  The
   *  distinction is not made by what they contain, but simply by what they
   *  are.  Different underlying algorithms can then be used based on the
   *  different operations supported by different iterator types.
  */
  ///  Marking input iterators.
  struct input_iterator_tag {};
  ///  Marking output iterators.
  struct output_iterator_tag {};
  /// Forward iterators support a superset of input iterator operations.
  struct forward_iterator_tag : public input_iterator_tag {};
  /// Bidirectional iterators support a superset of forward iterator
  /// operations.
  struct bidirectional_iterator_tag : public forward_iterator_tag {};
  /// Random-access iterators support a superset of bidirectional iterator
  /// operations.
  struct random_access_iterator_tag : public bidirectional_iterator_tag {};
  //@}

template<typename Iterator>
struct iterator_traits
{
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;

};

template<typename T>
struct iterator_traits<T*>
{
		typedef typename T value_type;
		typedef typename ptrdiff_t difference_type;
		typedef typename random_access_iterator_tag iterator_category;
		typedef typename T* pointer;
		typedef typename T& reference;

};

template <class Categoty, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
struct iterator
{
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;

};

}

#endif
