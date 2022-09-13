/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:57:01 by alorain           #+#    #+#             */
/*   Updated: 2022/09/13 19:19:54 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP

namespace ft
{

template<class T, class Allocator = std::allocator<T> >
class Vector 
	{
		public:
		// MEMBER TYPES

			typedef T 				value_type;
			typedef Allocator 		allocator_type;

			typedef typename Allocator::size_type 			size_type;
			typedef typename Allocator::difference_type 	difference_type;

			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference 	const_reference;

			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer 		const_pointer;

			//typedef	reverse_iterator;
			//typedef iterator;
			//typedef const_iterator;
			//typedef const_reverse_iterator;

			explicit Vector (const Allocator& alloc = Allocator())
			{
				this->_alloc = alloc;
				this->_start = alloc.allocate(0);
				this->_size = 0;
			}

			explicit Vector (size_type n, const T& val = T(),
					 const Allocator& alloc = Allocator()) : _size(n)
			{
				pointer tmp;
				this->_alloc = alloc;
				this->_start = this->_alloc.allocate(n);
				for (tmp = this->_start; tmp != this->_start + this->_size; tmp++)
					*tmp = val;
			}

			template <class InputIterator>
			Vector (InputIterator first, InputIterator last,
					 const Allocator& alloc = Allocator());

			Vector (const Vector& x) : _size(x._size), _start(x._start) {}

			~Vector (void)
			{
				this->_alloc.deallocate(this->_start, this->_size);
			}

			pointer begin(void) const
			{
				return this->_start;
			}

			pointer end(void) const
			{
				return this->_start + this->_size;
			}

		protected:
		private:
			pointer _start;
			size_t	_size;
			allocator_type _alloc;

	};

}
#endif
