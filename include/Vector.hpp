/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:57:01 by alorain           #+#    #+#             */
/*   Updated: 2022/09/23 13:07:05 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP

# include <memory>

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
			typedef ft::simple_iterator<const_pointer> const_iterator;
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
				}
				while (i++ < n)
				{
					this->_alloc.construct(tmp++, val);
				}
				this->clear();
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
					this->clear();
					this->_alloc.deallocate(this->_start, this->_endOfStorage - this->_start);
					this->_start = tmpNewStart;
					this->_finish = this->_start + size;
					this->_endOfStorage = this->_start + n;
				}
			}

			//ACCESSORS

		protected:

			inline
			void _range_check(size_type n)
			{
				if (n >= this->size())
					throw std::out_of_range("vector::_range_check out of range");
			}

		public:

			reference operator[](size_type pos)
			{
				return *(this->_start + pos);
			}

			const_reference operator[](size_type pos) const
			{
				return *(this->_start + pos);
			}

			reference at(size_type pos)
			{
				_range_check(pos);
				return (*this)[pos];
			}
			
			const_reference at(size_type pos) const
			{
				_range_check(pos);
				return (*this)[pos];
			}

			reference front(void)
			{
				return *(this->begin());
			}

			const reference front(void) const
			{
				return *(this->begin());
			}

			reference back(void)
			{
				return *(this->end() - 1);
			}

			const reference back(void) const
			{
				return *(this->end() - 1);
			}

			pointer data(void)
			{
				return &front(); 
			}

			const_pointer data(void) const
			{
				return &front(); 
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

			iterator insert(iterator pos, const value_type& value)
			{
				size_type idx = pos - this->begin();
				size_type prevSize = this->size();

				if (this->capacity() == this->size())
					this->reserve(this->capacity() * 2);

				for (size_type i = this->size() - 1; i >= idx; i--)
					this->_alloc.construct(this->_start + i + 1, *(this->_start + i));
				this->_alloc.construct(this->_start + idx, value);
				this->_finish = this->_start + prevSize + 1; 
				return iterator(&(*this)[idx]);
			}

			void insert(iterator pos, size_type n, const value_type& val)
			{
				size_type idx = pos - this->begin();
				size_type prevSize = this->size();

				if (this->capacity() == this->size())
					this->reserve(this->capacity() + n);

				for (size_type i = this->size() - 1; i >= idx; i--)
					this->_alloc.construct(this->_start + i + n, *(this->_start + i));
				std::uninitialized_fill(this->_start + idx, this->_start + idx + n, val);
				this->_finish = this->_start + prevSize + n; 
			}

			template <typename InputIt>
			void insert (iterator pos, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first, InputIt last)
			{
				_insert_range(pos, first, last, typename ft::iterator_traits<InputIt>::iterator_category());
			}

		private:
			
			template<typename ForwardIt>
			void _insert_range(iterator pos, ForwardIt first, ForwardIt last, std::forward_iterator_tag)
			{
				size_type idx = pos - this->begin();
				size_type prevSize = this->size();
				size_type rangeLen = last - first;

				if (this->capacity() == this->size())
					this->reserve(this->capacity() + rangeLen);

				for (size_type i = this->size() - 1; i >= idx; i--)
					this->_alloc.construct(this->_start + i + rangeLen, *(this->_start + i));
				for (size_type i = 0; i < rangeLen; i++)
					this->_alloc.construct(this->_start + idx + i, *(first + i));
				this->_finish = this->_start + prevSize + rangeLen;
			}

			template<typename InputIt>
			void _insert_range(iterator pos, InputIt first, InputIt last, std::input_iterator_tag)
			{
				Vector tmp;

				tmp.reserve(this->_finish - pos);
				std::uninitialized_copy(pos, this->_finish, tmp.begin());
				for (pointer ptr = pos.base(); ptr != this->_finish; ptr++)
					this->_alloc.destroy(ptr);
				this->_finish = pos;
				for (; first != last; first++)
					this->push_back(*first);
				this->reserve(this->size() + tmp.size());
				std::uninitialized_copy(tmp.begin(), tmp.end(), this->_finish);
			}

		public:

			iterator erase(iterator pos)
			{
				if (pos + 1 != this->end())
					std::copy(pos + 1, this->end(), pos);
				this->_finish--;
				return pos;
			}

			iterator erase(iterator first, iterator last)
			{
				size_type dist = std::distance(first, last);
				if (first != last)
				{
					for (iterator tmp = std::copy(last, this->end(), first);
						tmp != this->end(); tmp++)
						this->_alloc.destroy(tmp.base());
				}
				this->_finish = this->_finish - dist;
				return last + 1;
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
