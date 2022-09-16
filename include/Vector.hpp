/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:57:01 by alorain           #+#    #+#             */
/*   Updated: 2022/09/16 19:32:37 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP

namespace ft
{

# include "Iterator.hpp"
# include "utils.hpp"

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
			typedef ft::simple_iterator<pointer> iterator;
			//typedef const_iterator;
			//typedef const_reverse_iterator;
		public:

			explicit Vector (const Allocator& alloc = Allocator())
			{
				this->_alloc = alloc;
				this->_start = this->_alloc.allocate(0);
				this->_size = 0;
			}

			explicit Vector (size_type n, const T& val = T(),
					 const Allocator& alloc = Allocator())
			{
				pointer tmp;
				this->_alloc = alloc;
				this->_start = this->_alloc.allocate(n);
				this->_finish = this->_start + n;
				for (tmp = this->_start; tmp != this->_finish; tmp++)
					*tmp = val;
			}

			template <class InputIterator>
			Vector (InputIterator first, InputIterator last,
					 const Allocator& alloc = Allocator())
			{
				difference_type size = last - first;
				difference_type i = 0;
				this->_alloc = alloc;
				this->_start = this->_alloc.allocate(size);
				while (i < size)
				{
					this->_start[i++] = *first++;
				}
				this->_finish = &this->_start[i];
			}

			Vector (const Vector& x)
			{
				difference_type size = x.end() - x.begin();
				this->_alloc = x._alloc;
				this->_start = this->_alloc.allocate(size);
				std::cout << this->_finish - this->_start << std::endl;
				std::cout << size << std::endl;
				for (iterator tmp = x.begin(); tmp != x.end();tmp++)
				{
					this->_alloc.construct(this->_start++, *tmp);
				}
			}

			~Vector (void)
			{
				this->_alloc.deallocate(this->_start, this->_finish - this->_start);
			}

			Vector & operator=(const Vector & assign);

			iterator begin(void) const
			{
				return iterator(this->_start);
			}

			iterator end(void) const
			{
				return iterator(this->_finish);
			}

		protected:

		private:
			pointer _start;
			pointer _finish;
			size_t	_size;
			allocator_type _alloc;

	};

}
#endif
