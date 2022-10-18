/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <augustinlorain@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:26:49 by alorain           #+#    #+#             */
/*   Updated: 2022/10/18 16:17:36 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

//# include "vector.hpp"
# include "iterator_traits.hpp"

namespace ft
{

template <typename Iterator>
class normal_iterator 
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

		normal_iterator(void) : _iter(Iterator()) {}
		
		explicit normal_iterator(pointer ptr) : _iter(ptr) {}

		template <typename Iter>
			normal_iterator(const normal_iterator<Iter> & iter) : _iter(iter.base()) {}

		~normal_iterator(void) {}

		//binary arithmetic operator
		normal_iterator & operator+=(const difference_type n)
		{
			this->_iter += n;
			return *this;
		}

		normal_iterator & operator-=(const difference_type n)
		{
			this->_iter -= n;
			return *this;
		}

		normal_iterator operator+(const difference_type n) const
		{
			return normal_iterator(this->_iter + n);
		}

		normal_iterator operator-(const difference_type n) const
		{
			return normal_iterator(this->_iter - n);
		}

		difference_type operator-(const normal_iterator& Iter) const
		{
			return this->_iter - Iter._iter;
		}

		//
		pointer operator->(void) const
		{
			return this->_iter;
		}

		reference operator*(void) const
		{
			return *(this->_iter);
		}

		reference operator[](difference_type n) const
		{
			return this->_iter[n];
		}

		normal_iterator operator++( int )
		{
			normal_iterator tmp = *this;

			this->_iter++;
			return tmp;
		}

		normal_iterator operator++()
		{
			this->_iter++;
			return *this;
		}

		normal_iterator operator--( int )
		{
			normal_iterator tmp = *this;

			--this->_iter;
			return tmp;
		}

		normal_iterator& operator--()
		{
			--this->_iter;
			return *this;
		}

		const Iterator& base(void) const
		{
			return this->_iter;
		}

};

//FORWARD ITERATOR REQUIREMENTS

template<typename ItLeft, typename ItRight>
inline bool
operator==(const normal_iterator<ItLeft>& lhs,
		const normal_iterator<ItRight>& rhs)
{
	return lhs.base() == rhs.base();
}

template<typename It>
inline bool
operator==(const normal_iterator<It>& lhs,
		const normal_iterator<It>& rhs)
{
	return lhs.base() == rhs.base();
}

template<typename ItLeft, typename ItRight>
inline bool
operator!=(const normal_iterator<ItLeft>& lhs,
		const normal_iterator<ItRight>& rhs)
{
	return lhs.base() != rhs.base();
}

template<typename It>
inline bool
operator!=(const normal_iterator<It>& lhs,
		const normal_iterator<It>& rhs)
{
	return lhs.base() != rhs.base();
}

//RANDOM ACCESS ITERATOR REQUIREMENTS

template<typename ItLeft, typename ItRight>
inline bool
operator<(const normal_iterator<ItLeft>& lhs,
		const normal_iterator<ItRight>& rhs)
{
	return lhs.base() < rhs.base();
}

template<typename It>
inline bool
operator<(const normal_iterator<It>& lhs,
		const normal_iterator<It>& rhs)
{
	return lhs.base() < rhs.base();
}

template<typename ItLeft, typename ItRight>
inline bool
operator>(const normal_iterator<ItLeft>& lhs,
		const normal_iterator<ItRight>& rhs)
{
	return lhs.base() > rhs.base();
}

template<typename It>
inline bool
operator>(const normal_iterator<It>& lhs,
		const normal_iterator<It>& rhs)
{
	return lhs.base() > rhs.base();
}

template<typename ItLeft, typename ItRight>
inline bool
operator<=(const normal_iterator<ItLeft>& lhs,
		const normal_iterator<ItRight>& rhs)
{
	return !(lhs.base() > rhs.base());
}

template<typename It>
inline bool
operator<=(const normal_iterator<It>& lhs,
		const normal_iterator<It>& rhs)
{
	return !(lhs.base() > rhs.base());
}

template<typename ItLeft, typename ItRight>
inline bool
operator>=(const normal_iterator<ItLeft>& lhs,
		const normal_iterator<ItRight>& rhs)
{
	return !(lhs.base() < rhs.base());
}

template<typename It>
inline bool
operator>=(const normal_iterator<It>& lhs,
		const normal_iterator<It>& rhs)
{
	return !(lhs.base() < rhs.base());
}

template<typename ItLeft, typename ItRight>
inline typename normal_iterator<ItLeft>::difference_type
operator-(const normal_iterator<ItLeft>& lhs,
		const normal_iterator<ItRight>& rhs)
{
	return lhs.base() - rhs.base();
}

template<typename ItLeft, typename ItRight>
inline typename normal_iterator<ItLeft>::difference_type
operator+(const normal_iterator<ItLeft>& lhs,
		const normal_iterator<ItRight>& rhs)
{
	return lhs.base() + rhs.base();
}

template<typename It>
inline normal_iterator<It>
operator+(typename normal_iterator<It>::difference_type n,
		const normal_iterator<It>& lhs)
{
	return normal_iterator<It>(lhs.base() + n);
}

template <typename Iterator>
class reverse_iterator : public iterator< typename iterator_traits<Iterator>::iterator_category,
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

		reverse_iterator(void) : _iter() {}
		
		explicit reverse_iterator(Iterator iter) : _iter(iter) {}

		explicit reverse_iterator(const reverse_iterator& x) : _iter(x._iter) {}

		template <typename T>
		reverse_iterator(const reverse_iterator<T>& iter) : _iter(iter.base()) {}

		reverse_iterator & operator=(const reverse_iterator & rhs)
		{
			this->_iter = rhs._iter; 
			return *this;
		}

		//binary arithmetic operator

		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(this->_iter - n);
		}

		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(this->_iter + n);
		}

		reverse_iterator & operator+=(difference_type n)
		{
			this->_iter -= n;
			return *this;
		}

		reverse_iterator & operator-=(difference_type n)
		{
			this->_iter += n;
			return *this;
		}

		pointer operator->() const
		{
			return &(this->operator*());
		}

		reference operator*() const
		{
			Iterator tmp = this->_iter;
			return *--tmp;
		}

		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}

		reverse_iterator operator++( int )
		{
			reverse_iterator tmp = *this;

			--this->_iter;
			return tmp;
		}

		reverse_iterator operator++()
		{
			--this->_iter;
			return *this;
		}

		reverse_iterator operator--( int )
		{
			reverse_iterator tmp = *this;

			++this->_iter;
			return tmp;
		}

		reverse_iterator& operator--()
		{
			++this->_iter;
			return *this;
		}

		const Iterator& base(void) const
		{
			return this->_iter;
		}

};

template<typename _Iterator>
 inline bool
 operator==(const reverse_iterator<_Iterator>& __x,
		const reverse_iterator<_Iterator>& __y)
 { return __x.base() == __y.base(); }

template<typename _Iterator>
 inline bool
 operator<(const reverse_iterator<_Iterator>& __x,
	   const reverse_iterator<_Iterator>& __y)
 { return __y.base() < __x.base(); }

template<typename _Iterator>
 inline bool
 operator!=(const reverse_iterator<_Iterator>& __x,
		const reverse_iterator<_Iterator>& __y)
 { return !(__x == __y); }

template<typename _Iterator>
 inline bool
 operator>(const reverse_iterator<_Iterator>& __x,
	   const reverse_iterator<_Iterator>& __y)
 { return __y < __x; }

template<typename _Iterator>
 inline bool
 operator<=(const reverse_iterator<_Iterator>& __x,
		const reverse_iterator<_Iterator>& __y)
 { return !(__y < __x); }

template<typename _Iterator>
 inline bool
 operator>=(const reverse_iterator<_Iterator>& __x,
		const reverse_iterator<_Iterator>& __y)
 { return !(__x < __y); }

template<typename _Iterator>
 inline typename reverse_iterator<_Iterator>::difference_type
 operator-(const reverse_iterator<_Iterator>& __x,
	   const reverse_iterator<_Iterator>& __y)
 { return __y.base() - __x.base(); }

template<typename _Iterator>
 inline reverse_iterator<_Iterator>
 operator+(typename reverse_iterator<_Iterator>::difference_type __n,
	   const reverse_iterator<_Iterator>& __x)
 { return reverse_iterator<_Iterator>(__x.base() - __n); }


template<typename _IteratorL, typename _IteratorR>
 inline bool
 operator==(const reverse_iterator<_IteratorL>& __x,
		const reverse_iterator<_IteratorR>& __y)
 { return __x.base() == __y.base(); }

template<typename _IteratorL, typename _IteratorR>
 inline bool
 operator<(const reverse_iterator<_IteratorL>& __x,
	   const reverse_iterator<_IteratorR>& __y)
 { return __y.base() < __x.base(); }

template<typename _IteratorL, typename _IteratorR>
 inline bool
 operator!=(const reverse_iterator<_IteratorL>& __x,
		const reverse_iterator<_IteratorR>& __y)
 { return !(__x == __y); }

template<typename _IteratorL, typename _IteratorR>
 inline bool
 operator>(const reverse_iterator<_IteratorL>& __x,
	   const reverse_iterator<_IteratorR>& __y)
 { return __y < __x; }

template<typename _IteratorL, typename _IteratorR>
 inline bool
 operator<=(const reverse_iterator<_IteratorL>& __x,
		const reverse_iterator<_IteratorR>& __y)
 { return !(__y < __x); }

template<typename _IteratorL, typename _IteratorR>
 inline bool
 operator>=(const reverse_iterator<_IteratorL>& __x,
		const reverse_iterator<_IteratorR>& __y)
 { return !(__x < __y); }

template<typename _IteratorL, typename _IteratorR>
 inline typename reverse_iterator<_IteratorL>::difference_type
 operator-(const reverse_iterator<_IteratorL>& __x,
	   const reverse_iterator<_IteratorR>& __y)
 { return __y.base() - __x.base(); }


}

#endif
