/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:57:01 by alorain           #+#    #+#             */
/*   Updated: 2022/09/19 19:22:08 by alorain          ###   ########.fr       */
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
				this->_finish = this->_start;
				this->_endOfStorage = this->_start;
				this->_size = 0;
			}

			explicit Vector (size_type n, const T& val = T(),
					 const Allocator& alloc = Allocator())
			{
				pointer tmp;
				this->_alloc = alloc;
				pointer tmpStart = this->_alloc.allocate(n);
				this->_start = tmpStart;
				this->_finish = this->_start + n;
				this->_endOfStorage = this->_start + n;
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
				this->_endOfStorage = &this->_start[i];
			}

			Vector (const Vector& x)
			{
				difference_type size = x.end() - x.begin();
				this->_alloc = x._alloc;
				pointer tmpStart = this->_alloc.allocate(size);
				this->_start = tmpStart;
				this->_finish = &(*(this->_start + size));
				this->_endOfStorage = &(*(this->_start + size));
				pointer tmp_start = this->_start;
				for (iterator tmp = x.begin(); tmp != x.end();tmp++)
				{
					this->_alloc.construct(tmp_start++, *tmp);
				}
			}

			~Vector (void)
			{
				this->_alloc.deallocate(this->_start, this->_endOfStorage - this->_start);
			}

			Vector & operator=(const Vector & assign)
			{
				this->_alloc.deallocate(this->_start, this->_finish - this->_start);
				this->_alloc = assign._alloc;
				difference_type size = assign.end() - assign.begin();
				this->_alloc = assign._alloc;
				pointer tmpStart = this->_alloc.allocate(size);
				this->_start = tmpStart;
				this->_finish = &(*(this->_start + size));
				pointer tmp_start = this->_start;
				for (iterator tmp = assign.begin(); tmp != assign.end();tmp++)
				{
					this->_alloc.construct(tmp_start++, *tmp);
				}
				return *this;
			}

			iterator begin(void) const
			{
				return iterator(this->_start);
			}

			iterator end(void) const
			{
				return iterator(this->_finish);
			}

			size_type size(void) const
			{
				return this->_finish - this->_start;
			}

			difference_type max_size(void) const
			{
				return this->_alloc.max_size();
			}

			size_type capacity(void) const
			{
				return this->_endOfStorage - this->_start;
			}

			void resize(size_type n, value_type val = value_type())
			{
				pointer tmpNewStart;
				if (n < this->capacity())
				{
					tmpNewStart	= this->_alloc.allocate(this->capacity());
					this->_endOfStorage = tmpNewStart + this->capacity();
				}
				else
				{
					tmpNewStart	= this->_alloc.allocate(n);
					this->_endOfStorage = tmpNewStart + n;
				}
				pointer tmp, tmpStart;
				size_type i;
				for (tmp = tmpNewStart, tmpStart = this->_start, i = 0;
					tmpStart != this->_finish && i < n ; i++, tmp++, tmpStart++)
				{
					this->_alloc.construct(tmp, *tmpStart);
				}
				while (i++ < n)
				{
					this->_alloc.construct(tmp++, val);
				}
				this->_alloc.deallocate(this->_start, this->_endOfStorage - this->_start);
				this->_start = tmpNewStart;
				this->_finish = this->_start + n;
			}

			bool empty(void) const
			{
				return (this->_size() == 0);
			}

			void reserve(size_type n)
			{
				if (n > this->capacity())
				{
					difference_type size = this->size();
					pointer tmpNewStart	= this->_alloc.allocate(n);
					pointer tmp, tmpStart;
					for (tmp = tmpNewStart, tmpStart = this->_start;
						tmpStart != this->_finish; tmp++, tmpStart++)
					{
						this->_alloc.construct(tmp, *tmpStart);
					}
					this->_alloc.deallocate(this->_start, this->_endOfStorage - this->_start);
					this->_start = tmpNewStart;
					this->_finish = this->_start + size;
					this->_endOfStorage = this->_start + n;
				}
			}

			void shrink_to_fit(void)
			{
				if (this->capacity() != this->size())
				{
					size_type size = this->size();
					pointer tmpStart = this->_start;
					pointer tmpNewStart = this->_alloc.allocate(size); 
					for (int i = 0;tmpStart != this->_finish; tmpStart++, i++)
					{
						this->_alloc.construct(tmpNewStart + i, *tmpStart);
					}
					this->_alloc.deallocate(this->_start, this->_endOfStorage - this->_start);
					this->_start = tmpNewStart;
					this->_finish = this->_start + size;
					this->_endOfStorage = this->_start + size;
				}
			}
			
			

			


		protected:

		private:
			pointer _start;
			pointer _finish;
			pointer _endOfStorage;
			size_t	_size;
			allocator_type _alloc;

	};

}
#endif
