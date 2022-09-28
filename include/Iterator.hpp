/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <augustinlorain@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:26:49 by alorain           #+#    #+#             */
/*   Updated: 2022/09/28 19:18:46 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "vector.hpp"
# include "iterator_traits.hpp"

namespace ft
{

template <typename Iterator>
class simple_iterator //: public iterator< typename iterator_traits<Iterator>::iterator_category,
					  //  				 typename iterator_traits<Iterator>::value_type,
					  //  				 typename iterator_traits<Iterator>::difference_type,
					  //  				 typename iterator_traits<Iterator>::pointer,
					  //  				 typename iterator_traits<Iterator>::reference >
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

		template <typename Iter>
		simple_iterator(const simple_iterator<Iter> & iter) : _iter(iter.base()) {}

		~simple_iterator(void) {}

		simple_iterator & operator=(const simple_iterator & rhs)
		{
			this->_iter = rhs._iter; 
			return *this;
		}

		// comparaison operator overload
		//bool operator!=(const simple_iterator & rhs)
		//{
		//	if (this->_iter == rhs._iter)
		//		return false;
		//	return true;
		//}

		//bool operator==(const simple_iterator & rhs)
		//{
		//	if (this->_iter != rhs._iter)
		//		return false;
		//	return true;
		//}

		//bool operator<(const simple_iterator & rhs)
		//{
		//	if (this->_iter >= rhs._iter)
		//		return false;
		//	return true;
		//}

		//bool operator<=(const simple_iterator & rhs)
		//{
		//	if (this->_iter > rhs._iter)
		//		return false;
		//	return true;
		//}

		//bool operator>(const simple_iterator & rhs)
		//{
		//	if (this->_iter <= rhs._iter)
		//		return false;
		//	return true;
		//}

		//bool operator>=(const simple_iterator & rhs)
		//{
		//	if (this->_iter < rhs._iter)
		//		return false;
		//	return true;
		//}
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

		simple_iterator operator+(const difference_type n) const
		{
			return simple_iterator(this->_iter + n);
		}

		simple_iterator operator-(const difference_type n) const
		{
			return simple_iterator(this->_iter - n);
		}

		difference_type operator-(const simple_iterator& Iter)
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

		Iterator& base(void) const
		{
			return this->_iter;
		}

};

//FORWARD ITERATOR REQUIREMENTS

template<typename ItLeft, typename ItRight>
inline bool
operator==(const simple_iterator<ItLeft>& lhs,
		const simple_iterator<ItRight>& rhs)
{
	return lhs.base() == rhs.base();
}

template<typename It>
inline bool
operator==(const simple_iterator<It>& lhs,
		const simple_iterator<It>& rhs)
{
	return lhs.base() == rhs.base();
}

template<typename ItLeft, typename ItRight>
inline bool
operator!=(const simple_iterator<ItLeft>& lhs,
		const simple_iterator<ItRight>& rhs)
{
	return lhs.base() != rhs.base();
}

template<typename It>
inline bool
operator!=(const simple_iterator<It>& lhs,
		const simple_iterator<It>& rhs)
{
	return lhs.base() != rhs.base();
}

//RANDOM ACCESS ITERATOR REQUIREMENTS

template<typename ItLeft, typename ItRight>
inline bool
operator<(const simple_iterator<ItLeft>& lhs,
		const simple_iterator<ItRight>& rhs)
{
	return lhs.base() < rhs.base();
}

template<typename It>
inline bool
operator<(const simple_iterator<It>& lhs,
		const simple_iterator<It>& rhs)
{
	return lhs.base() < rhs.base();
}

template<typename ItLeft, typename ItRight>
inline bool
operator>(const simple_iterator<ItLeft>& lhs,
		const simple_iterator<ItRight>& rhs)
{
	return lhs.base() > rhs.base();
}

template<typename It>
inline bool
operator>(const simple_iterator<It>& lhs,
		const simple_iterator<It>& rhs)
{
	return lhs.base() > rhs.base();
}

template<typename ItLeft, typename ItRight>
inline bool
operator<=(const simple_iterator<ItLeft>& lhs,
		const simple_iterator<ItRight>& rhs)
{
	return !(lhs.base() > rhs.base());
}

template<typename It>
inline bool
operator<=(const simple_iterator<It>& lhs,
		const simple_iterator<It>& rhs)
{
	return !(lhs.base() > rhs.base());
}

template<typename ItLeft, typename ItRight>
inline bool
operator>=(const simple_iterator<ItLeft>& lhs,
		const simple_iterator<ItRight>& rhs)
{
	return !(lhs.base() < rhs.base());
}

template<typename It>
inline bool
operator>=(const simple_iterator<It>& lhs,
		const simple_iterator<It>& rhs)
{
	return !(lhs.base() < rhs.base());
}

template<typename ItLeft, typename ItRight>
inline typename simple_iterator<ItLeft>::difference_type
operator-(const simple_iterator<ItLeft>& lhs,
		const simple_iterator<ItRight>& rhs)
{
	return lhs.base() - rhs.base();
}

template<typename ItLeft, typename ItRight>
inline typename simple_iterator<ItLeft>::difference_type
operator+(const simple_iterator<ItLeft>& lhs,
		const simple_iterator<ItRight>& rhs)
{
	return lhs.base() + rhs.base();
}

template<typename It>
inline simple_iterator<It>
operator+(typename simple_iterator<It>::difference_type n,
		const simple_iterator<It>& lhs)
{
	return simple_iterator<It>(lhs.base() + n);
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

		reverse_iterator(void) : _iter(Iterator()) {}
		
		explicit reverse_iterator(pointer ptr) : _iter(ptr) {}

		template <typename T>
		reverse_iterator(reverse_iterator<T> & iter) : _iter(iter.base()) {}

		reverse_iterator & operator=(const reverse_iterator & rhs)
		{
			this->_iter = rhs._iter; 
			return *this;
		}

		// comparaison operator overload
		//bool operator!=(const reverse_iterator & rhs)
		//{
		//	if (this->_iter == rhs._iter)
		//		return false;
		//	return true;
		//}

		//bool operator==(const reverse_iterator & rhs)
		//{
		//	if (this->_iter != rhs._iter)
		//		return false;
		//	return true;
		//}

		//bool operator<(const reverse_iterator & rhs)
		//{
		//	if (this->_iter >= rhs._iter)
		//		return false;
		//	return true;
		//}

		//bool operator<=(const reverse_iterator & rhs)
		//{
		//	if (this->_iter > rhs._iter)
		//		return false;
		//	return true;
		//}

		//bool operator>(const reverse_iterator & rhs)
		//{
		//	if (this->_iter <= rhs._iter)
		//		return false;
		//	return true;
		//}

		//bool operator>=(const reverse_iterator & rhs)
		//{
		//	if (this->_iter < rhs._iter)
		//		return false;
		//	return true;
		//}
		//

		//binary arithmetic operator
		reverse_iterator & operator+=(const difference_type n)
		{
			this->_iter -= n;
			return this;
		}

		reverse_iterator & operator-=(const difference_type n)
		{
			this->_iter += n;
			return this;
		}

		reverse_iterator operator+(const difference_type n) const
		{
			return reverse_iterator(this->_iter - n);
		}

		reverse_iterator operator-(const difference_type n) const
		{
			return reverse_iterator(this->_iter + n);
		}

		difference_type operator-(const reverse_iterator& Iter)
		{
			return this->_iter + Iter._iter;
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

		reference operator[](difference_type n)
		{
			return this->_iter[n];
		}

		reverse_iterator operator++( int )
		{
			reverse_iterator tmp = *this;

			this->_iter--;
			return tmp;
		}

		reverse_iterator operator++()
		{
			this->_iter--;
			return *this;
		}

		reverse_iterator operator--( int )
		{
			reverse_iterator tmp = *this;

			this->_iter++;
			return tmp;
		}

		reverse_iterator operator--()
		{
			this->_iter++;
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
operator==(const reverse_iterator<ItLeft>& lhs,
		const reverse_iterator<ItRight>& rhs)
{
	return lhs.base() == rhs.base();
}

template<typename It>
inline bool
operator==(const reverse_iterator<It>& lhs,
		const reverse_iterator<It>& rhs)
{
	return lhs.base() == rhs.base();
}

template<typename ItLeft, typename ItRight>
inline bool
operator!=(const reverse_iterator<ItLeft>& lhs,
		const reverse_iterator<ItRight>& rhs)
{
	return lhs.base() != rhs.base();
}

template<typename It>
inline bool
operator!=(const reverse_iterator<It>& lhs,
		const reverse_iterator<It>& rhs)
{
	return lhs.base() != rhs.base();
}

//RANDOM ACCESS ITERATOR REQUIREMENTS

template<typename ItLeft, typename ItRight>
inline bool
operator<(const reverse_iterator<ItLeft>& lhs,
		const reverse_iterator<ItRight>& rhs)
{
	return rhs.base() < lhs.base();
}

template<typename It>
inline bool
operator<(const reverse_iterator<It>& lhs,
		const reverse_iterator<It>& rhs)
{
	return rhs.base() < lhs.base();
}

template<typename ItLeft, typename ItRight>
inline bool
operator>(const reverse_iterator<ItLeft>& lhs,
		const reverse_iterator<ItRight>& rhs)
{
	return lhs.base() < rhs.base();
}

template<typename It>
inline bool
operator>(const reverse_iterator<It>& lhs,
		const reverse_iterator<It>& rhs)
{
	return lhs.base() < rhs.base();
}

template<typename ItLeft, typename ItRight>
inline bool
operator<=(const reverse_iterator<ItLeft>& lhs,
		const reverse_iterator<ItRight>& rhs)
{
	return !(rhs.base() < lhs.base());
}

template<typename It>
inline bool
operator<=(const reverse_iterator<It>& lhs,
		const reverse_iterator<It>& rhs)
{
	return !(rhs.base() < lhs.base());
}

template<typename ItLeft, typename ItRight>
inline bool
operator>=(const reverse_iterator<ItLeft>& lhs,
		const reverse_iterator<ItRight>& rhs)
{
	return !(lhs.base() < rhs.base());
}

template<typename It>
inline bool
operator>=(const reverse_iterator<It>& lhs,
		const reverse_iterator<It>& rhs)
{
	return !(lhs.base() < rhs.base());
}

template<typename ItLeft, typename ItRight>
inline typename reverse_iterator<ItLeft>::difference_type
operator-(const reverse_iterator<ItLeft>& lhs,
		const reverse_iterator<ItRight>& rhs)
{
	return rhs.base() - lhs.base();
}

template<typename It>
inline reverse_iterator<It>
operator+(typename reverse_iterator<It>::difference_type n,
		const reverse_iterator<It>& lhs)
{
	return reverse_iterator<It>(lhs.base() + n);
}


}

#endif
