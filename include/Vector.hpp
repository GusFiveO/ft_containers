/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:57:01 by alorain           #+#    #+#             */
/*   Updated: 2022/09/21 11:52:34 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP

namespace ft
{

# include "Iterator.hpp"
# include "utils.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"

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
				size_type capacity = x.capacity();
				difference_type size = x.end() - x.begin();
				this->_alloc = x._alloc;
				pointer tmpStart = this->_alloc.allocate(size);
				this->_start = tmpStart;
				this->_finish = &(*(this->_start + size));
				this->_endOfStorage = &(*(this->_start + capacity));
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
				if (this == &assign)
					return *this;

				this->clear();
				this->_alloc.deallocate(this->_start, this->_endOfStorage - this->_start);
				this->_alloc = assign._alloc;
				difference_type size = assign.size();
				size_type capacity = assign.capacity();
				this->_alloc = assign._alloc;
				pointer tmpStart = this->_alloc.allocate(capacity);
				pointer tmp = tmpStart;
				for (iterator it = assign.begin(); it != assign.end(); it++)
				{
					this->_alloc.construct(tmp++, *it);
				}
				this->_start = tmpStart;
				this->_finish = this->_start + size;
				this->_endOfStorage = this->_start + capacity;
				return *this;
			}

			Allocator get_allocator(void) const
			{
				return this->_alloc;
			}

			void assign(size_type count, const T& value);
			
			template<class InputIt>
			void assign(typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first,
							 InputIt last);

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
				if (n == 0)
					return this->clear();
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
					this->_alloc.destroy(tmpStart);
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
						this->_alloc.destroy(tmpStart);
					}
					this->_alloc.deallocate(this->_start, this->_endOfStorage - this->_start);
					this->_start = tmpNewStart;
					this->_finish = this->_start + size;
					this->_endOfStorage = this->_start + n;
				}
			}
			
			//MODIFIERS

			void clear(void)
			{
				pointer tmpStart = this->_start;
				for (;tmpStart != this->_finish; tmpStart++)
					this->_alloc.destroy(tmpStart);
				this->_finish = this->_start;
			}

			void push_back(const T& value)
			{
				size_type capacity = this->capacity();
				size_type size = this->size();

				if (size + 1 > capacity)
				{
					if (capacity == 0)
						capacity = 1;
					pointer newStart = this->_alloc.allocate(capacity * 2);
					pointer tmpStart, tmpNewStart;
					for (tmpStart = this->_start, tmpNewStart = newStart;
							tmpStart != this->_finish; tmpStart++, tmpNewStart++)
					{
						this->_alloc.construct(tmpNewStart, *tmpStart);
					}
					this->_alloc.construct(tmpNewStart++, value);
					this->clear();
					this->_alloc.deallocate(this->_start, capacity);
					this->_start = newStart;
					this->_finish = newStart + size + 1;
					this->_endOfStorage = newStart + (capacity * 2);
				}
				else
					this->_alloc.construct(this->_finish++, value);
			}

			void pop_back(void)
			{
				this->_alloc.destroy(this->_finish--);
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
