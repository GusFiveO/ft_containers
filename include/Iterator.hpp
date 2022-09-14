/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:26:49 by alorain           #+#    #+#             */
/*   Updated: 2022/09/14 18:26:27 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "Vector.hpp"
# include "iterator_traits.hpp"

namespace ft
{

template <typename T>
class simple_iterator : public iterator< iterator_traits<T>::iterator_category,
										 iterator_traits<T>::value_type,
										 iterator_traits<T>::difference_type,
										 iterator_traits<T>::pointer,
										 iterator_traits<T>::reference >
{
	protected:
		pointer _ptr;
	public:

		simple_iterator(void) : _ptr(NULL) {}
		
		explicit simple_iterator(pointer ptr) : _ptr(ptr) {}

		simple_iterator(simple_iterator & iter) : _ptr(iter._ptr) {}

		simple_operator & operator=(const simple_operator & rhs)
		{
			this->_ptr = rhs._ptr; 
			return *this;
		}

		// comparaison operator overload
		bool operator!=(const simple_operator & rhs)
		{
			if (this->_ptr == rhs._ptr)
				return false;
			return true;
		}

		bool operator==(const simple_operator & rhs)
		{
			if (this->_ptr != rhs._ptr)
				return false;
			return true;
		}

		bool operator<(const simple_operator & rhs)
		{
			if (this->_ptr >= rhs._ptr)
				return false;
			return true;
		}

		bool operator<=(const simple_operator & rhs)
		{
			if (this->_ptr > rhs._ptr)
				return false;
			return true;
		}

		bool operator>(const simple_operator & rhs)
		{
			if (this->_ptr <= rhs._ptr)
				return false;
			return true;
		}

		bool operator>=(const simple_operator & rhs)
		{
			if (this->_ptr < rhs._ptr)
				return false;
			return true;
		}
		//

		//binary arithmetic operator
		simple_iterator & operator+=(const difference_type n)
		{
			this->_ptr += n;
			return this;
		}

		simple_iterator & operator-=(const difference_type n)
		{
			this->_ptr -= n;
			return this;
		}

		simple_iterator operator+(const difference_type n)
		{
			return simple_operator(this->_ptr + n);
		}

		simple_iterator operator-(const difference_type n)
		{
			return simple_operator(this->_ptr - n);
		}

		//
		pointer operator->()
		{
			return this->_ptr;
		}

		reference operator*()
		{
			return *(this->_ptr);
		}

		reference operator[](difference_type n)
		{
			return this->_ptr[n];
		}

		simple_operator operator++( int )
		{
			simple_operator tmp = *this;

			this->_ptr++;
			return tmp;
		}

		simple_operator operator++()
		{
			this->_ptr++;
			return tmp;
		}

		simple_operator operator--( int )
		{
			simple_operator tmp = *this;

			this->_ptr--;
			return tmp;
		}

		simple_operator operator--()
		{
			this->_ptr--;
			return tmp;
		}
};

}

#endif
