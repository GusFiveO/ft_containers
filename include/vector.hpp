/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: augustinlorain <augustinlorain@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:57:01 by alorain           #+#    #+#             */
/*   Updated: 2022/10/20 15:23:58 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP

# include <memory>

# include "Iterator.hpp"
# include "iterator_traits.hpp"
# include "utils.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "algorithm.hpp"
# include <stdexcept>

namespace ft
{


template<class T, class Allocator = std::allocator<T> >
class vector 
	{
		public:
		// MEMBER TYPES

			typedef T 										value_type;
			typedef Allocator 								allocator_type;

			typedef typename Allocator::size_type 			size_type;
			typedef typename Allocator::difference_type 	difference_type;

			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference 	const_reference;

			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer 		const_pointer;

			typedef ft::normal_iterator<pointer>			iterator;
			typedef ft::normal_iterator<const_pointer>		const_iterator;

			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		public:

			explicit vector (const Allocator& alloc = Allocator())
			{
				this->_alloc = alloc;
				this->_start = this->_alloc.allocate(0);
				this->_finish = this->_start;
				this->_endOfStorage = this->_start;
			}

			explicit vector (size_type n, const T& val = T(),
					 const Allocator& alloc = Allocator())
			{
				pointer tmp;
				this->_alloc = alloc;
				pointer tmpStart = this->_alloc.allocate(n);
				this->_start = tmpStart;
				this->_finish = this->_start + n;
				this->_endOfStorage = this->_start + n;
				for (tmp = this->_start; tmp != this->_finish; tmp++)
					this->_alloc.construct(tmp, val);
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0,
					 const Allocator& alloc = Allocator())
			{
				this->_alloc = alloc;
				this->_start = this->_alloc.allocate(0);
				this->_finish = this->_start;
				this->_endOfStorage = this->_start;
				_assign_range(first, last, typename ft::iterator_traits<InputIterator>::iterator_category());
			}

			vector (const vector& x)
			{
				size_type capacity = x.capacity();
				difference_type size = x.end() - x.begin();
				this->_alloc = x._alloc;
				pointer tmpStart = this->_alloc.allocate(capacity);
				this->_start = tmpStart;
				this->_finish = &(*(this->_start + size));
				this->_endOfStorage = &(*(this->_start + capacity));
				std::uninitialized_copy(x.begin(), x.end(), this->_start);
			}

			~vector (void)
			{
				for (pointer tmp = this->_start; tmp != this->_finish; tmp++)
					this->_alloc.destroy(tmp);
				this->_alloc.deallocate(this->_start, this->_endOfStorage - this->_start);
			}

			vector & operator=(const vector & assign)
			{
				if (this == &assign)
					return *this;
				difference_type size = assign.size();
				difference_type capacity = assign.size();

				this->clear();
				if (this->capacity() < assign.size())
				{
					this->_alloc.deallocate(this->_start, this->_endOfStorage - this->_start);
					this->_alloc = assign._alloc;
					this->_alloc = assign._alloc;
					pointer tmpStart = this->_alloc.allocate(size);
					this->_start = tmpStart;
				}
				else
				{
					for (pointer tmp = this->_start; tmp != this->_finish; tmp++)
						this->_alloc.destroy(tmp);
					capacity = this->capacity();
				}
				std::uninitialized_copy(assign.begin(), assign.end(), this->_start);
				this->_finish = this->_start + size;
				this->_endOfStorage = this->_start + capacity;
				return *this;
			}

			Allocator get_allocator(void) const
			{
				return this->_alloc;
			}

			void assign(size_type count, const T& value)
			{
				vector tmp(count, value);

				if (this->capacity() > this->size() + count)
				{
					tmp.reserve(this->capacity());
				}
				this->swap(tmp);
			}
			
			template<class InputIt>
			void assign(typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first,
							 InputIt last)
			{
				_assign_range(first, last, typename ft::iterator_traits<InputIt>::iterator_category());
			}

		private:
			
			template<typename InputIt>
			void _assign_range(InputIt first, InputIt last, std::input_iterator_tag)
			{
				vector tmp;

				for (; first != last; first++)
					tmp.push_back(*first);
				this->swap(tmp);
			}

			template<typename ForwIt>
			void _assign_range(ForwIt first, ForwIt last, std::forward_iterator_tag)
			{
				size_type dist = std::distance(first, last);
				this->clear();
				if (this->capacity() < this->size() + dist)
				{
					this->_alloc.deallocate(this->_start, this->_endOfStorage - this->_start);
					this->_start = this->_alloc.allocate(dist); 
					this->_endOfStorage = this->_start + (dist);
				}
				std::uninitialized_copy(first, last, this->_start);
				this->_finish = this->_start + (dist);
			}

		public:

			iterator begin(void)
			{
				return iterator(this->_start);
			}

			iterator end(void)
			{
				return iterator(this->_finish);
			}

			const_iterator begin(void) const
			{
				return const_iterator(this->_start);
			}

			const_iterator end(void) const
			{
				return const_iterator(this->_finish);
			}

			const_iterator cbegin(void) const
			{
				return const_iterator(this->_start);
			}

			const_iterator cend(void) const
			{
				return const_iterator(this->_finish);
			}

			reverse_iterator rbegin(void)
			{
				return reverse_iterator(this->end());
			}

			reverse_iterator rend(void)
			{
				return reverse_iterator(this->begin());
			}

			const_reverse_iterator rbegin(void) const
			{
				return const_reverse_iterator(this->end());
			}

			const_reverse_iterator rend(void) const
			{
				return const_reverse_iterator(this->begin());
			}

			const_reverse_iterator crbegin(void) const
			{
				return const_reverse_iterator(this->end());
			}

			const_reverse_iterator crend(void) const
			{
				return const_reverse_iterator(this->_start);
			}

			size_type size(void) const
			{
				return size_type(this->_finish - this->_start);
			}

			size_type max_size(void) const
			{
				return this->_alloc.max_size();
			}

			size_type capacity(void) const
			{
				return this->_endOfStorage - this->_start;
			}

			void resize(size_type n, value_type val = value_type())
			{
				if (size() > n)
				{
					for (pointer ptr = this->_start + n; ptr != this->_finish; ptr++)
						this->_alloc.destroy(ptr);
				}
				else
				{
					reserve(n);
					std::uninitialized_fill(this->_finish, this->_start + n, val);
				}
				this->_finish = this->_start + n;
			}

			bool empty(void) const
			{
				return (_start == _finish);
			}

			void reserve(size_type n)
			{
				if (n > max_size())
					throw (std::length_error("vector::reserve"));
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
			void _range_check(size_type n) const
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
				return this->_start[pos];
			}
			
			const_reference at(size_type pos) const
			{
				_range_check(pos);
				return this->_start[pos];
			}

			reference front(void)
			{
				return *(this->begin());
			}

			const_reference front(void) const
			{
				return *(this->begin());
			}

			reference back(void)
			{
				return *(this->end() - 1);
			}

			const_reference back(void) const
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
				if (this->size() == this->capacity())
				{
					if (this->size())
						this->reserve(this->size() * 2);
					else
						this->reserve(1);
				}
				this->_alloc.construct(this->_finish, value);
				_finish++;
			}

			void pop_back(void)
			{
				if (!empty())
				{
					--this->_finish;
					this->_alloc.destroy(this->_finish);
				}
			}

			iterator insert(iterator pos, const value_type& value)
			{
				size_type idx = pos - this->begin();
				size_type prevSize = this->size();

				if (this->capacity() == this->size())
				{
					if (!this->capacity())
						this->reserve(1);
					else
						this->reserve(this->capacity() * 2);
				}

				std::copy_backward(this->_start + idx, this->_finish, this->_finish + 1);
				this->_alloc.construct(this->_start + idx, value);
				this->_finish = this->_start + prevSize + 1; 
				return iterator(this->_start + idx); 
			}

			void insert(iterator pos, size_type n, const value_type& val)
			{
					if (size() + n > capacity())
					{
						vector	tmp;

						if (n < size())
							tmp.reserve(size() * 2);
						else
							tmp.reserve(size() + n);
						tmp._finish = std::uninitialized_copy(this->_start, pos.base(), tmp._start);
						tmp._finish = std::uninitialized_fill_n(tmp._finish, n, val);
						tmp._finish = std::uninitialized_copy(pos.base(), this->_finish, tmp._finish);
						swap(tmp);
					}
					else
					{
						pointer p = this->_finish;

						resize(size() + n, *_start);

						std::copy_backward(pos.base(), p, this->_finish);
						std::fill_n(pos.base(), n, val);

					}
			}

			template <typename InputIt>
			void insert (iterator pos, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first, InputIt last)
			{
				return	_insert_range(pos, first, last, typename ft::iterator_traits<InputIt>::iterator_category());
			}

		private:
			
			template<typename ForwardIt>
			void _insert_range(iterator pos, ForwardIt first, ForwardIt last, std::forward_iterator_tag)
			{
					size_type	n = std::distance(first, last);

					if (size() + n > capacity())
					{
						vector	tmp;

						tmp.reserve(size() + n);
						tmp._finish = std::uninitialized_copy(this->_start, pos.base(), tmp._start);
						tmp._finish = std::uninitialized_copy(first, last, tmp._finish);
						tmp._finish = std::uninitialized_copy(pos.base(), this->_finish, tmp._finish);
						swap(tmp);
					}
					else
					{
						pointer p = this->_finish;

						resize(size() + n, *first);
					//	reserve(size() + n);
					//	for (pointer ptr = this->_finish + n; ptr != this->_finish; ptr--)
					//		_alloc.construct(ptr, *this->_start);
						std::copy_backward(pos.base(), p, this->_finish);
						std::copy(first, last, pos.base());
					}
			}

			template<typename InputIt>
			void _insert_range(iterator pos, InputIt first, InputIt last, std::input_iterator_tag)
			{
				vector tmp;
				size_type idx = pos - this->begin();

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
				return erase(pos, pos + 1);
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
				return first;
			}

			void swap(vector& other)
			{
				std::swap(this->_start, other._start);
				std::swap(this->_finish, other._finish);
				std::swap(this->_endOfStorage, other._endOfStorage);
				std::swap(this->_alloc, other._alloc);
			}
		



		protected:

		private:
			T* _start;
			T* _finish;
			T* _endOfStorage;
			allocator_type _alloc;

	};

template<typename T, typename Allocator>
inline bool
operator==(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
{
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template<typename T, typename Allocator>
inline bool
operator<(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
{
	return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<typename T, typename Allocator>
inline bool
operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
{
	return !(lhs == rhs);
}

template<typename T, typename Allocator>
inline bool
operator>(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
{
	return (rhs < lhs);
}

template<typename T, typename Allocator>
inline bool
operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
{
	return !(rhs < lhs);
}
 
template<typename T, typename Allocator>
inline bool
operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
{
	return !(lhs < rhs);
}

template<class T, class Alloc>
void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs)
{
	lhs.swap(rhs);
}

}
#endif
