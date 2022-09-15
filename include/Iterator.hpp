/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:26:49 by alorain           #+#    #+#             */
/*   Updated: 2022/09/15 18:30:04 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "Vector.hpp"
# include "iterator_traits.hpp"

namespace ft
{

template <typename Iterator>
class simple_iterator : public iterator< typename iterator_traits<Iterator>::iterator_category,
										 typename iterator_traits<Iterator>::value_type,
										 typename iterator_traits<Iterator>::difference_type,
										 typename iterator_traits<Iterator>::pointer,
										 typename iterator_traits<Iterator>::reference >
{
	protected:
		Iterator _iter;
		typedef	ft::iterator_traits<Iterator> _traits;
	public:

		typedef typename _traits::value_type		value_type;
		typedef typename _traits::difference_type	difference_type;
		typedef typename _traits::pointer			pointer;
		typedef typename _traits::reference			reference;
		typedef typename _traits::iterator_category	iterator_category;

		simple_iterator(void) : _iter(Iterator()) {}
		
		explicit simple_iterator(pointer ptr) : _iter(ptr) {}

		template <typename T>
		simple_iterator(simple_iterator<T> & iter) : _iter(iter._iter) {}

		simple_iterator & operator=(const simple_iterator & rhs)
		{
			this->_iter = rhs._iter; 
			return *this;
		}

		// comparaison operator overload
		bool operator!=(const simple_iterator & rhs)
		{
			if (this->_iter == rhs._iter)
				return false;
			return true;
		}

		bool operator==(const simple_iterator & rhs)
		{
			if (this->_iter != rhs._iter)
				return false;
			return true;
		}

		bool operator<(const simple_iterator & rhs)
		{
			if (this->_iter >= rhs._iter)
				return false;
			return true;
		}

		bool operator<=(const simple_iterator & rhs)
		{
			if (this->_iter > rhs._iter)
				return false;
			return true;
		}

		bool operator>(const simple_iterator & rhs)
		{
			if (this->_iter <= rhs._iter)
				return false;
			return true;
		}

		bool operator>=(const simple_iterator & rhs)
		{
			if (this->_iter < rhs._iter)
				return false;
			return true;
		}
		//

		//binary arithmetic operator
		simple_iterator & operator+=(const difference_type n)
		{
			this->_iter += n;
			return this;
		}

		simple_iterator & operator-=(const difference_type n)
		{
			this->_iter -= n;
			return this;
		}

		simple_iterator operator+(const difference_type n)
		{
			return simple_iterator(this->_iter + n);
		}

		simple_iterator operator-(const difference_type n)
		{
			return simple_iterator(this->_iter - n);
		}

		//
		pointer operator->()
		{
			return this->_iter;
		}

		reference operator*()
		{
			return *(this->_iter);
		}

		reference operator[](difference_type n)
		{
			return this->_iter[n];
		}

		simple_iterator operator++( int )
		{
			simple_iterator tmp = *this;

			this->_iter++;
			return tmp;
		}

		simple_iterator operator++()
		{
			this->_iter++;
			return *this;
		}

		simple_iterator operator--( int )
		{
			simple_iterator tmp = *this;

			this->_iter--;
			return tmp;
		}

		simple_iterator operator--()
		{
			this->_iter--;
			return *this;
		}
};

}

#endif
