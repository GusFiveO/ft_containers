/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:17:36 by alorain           #+#    #+#             */
/*   Updated: 2022/10/19 15:51:48 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{


template<typename T, typename Container = ft::vector<T> >
class stack
{
	public:

		typedef Container							container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

		template<typename T1, typename Container1>
        friend bool
        operator==(const stack<T1, Container1>&, const stack<T1, Container1>&);
 
		template<typename T1, typename Container1>
        friend bool
        operator<(const stack<T1, Container1>&, const stack<T1, Container1>&);


	protected:
		Container _c;

	public:
		explicit stack(const Container& c = Container())
		: _c(c) {};

		stack(const stack& other)
		: _c(other._c) {}

		~stack(void) {}

		bool
		empty(void)
		{
			return this->_c.empty();
		}

		size_type
		size(void)
		{
			return this->_c.size();
		}

		reference
		top()
		{
			return this->_c.back();
		}

		const_reference
		top() const
		{
			return this->_c.back();
		}

		void
		push(const value_type& x)
		{
			this->_c.push_back(x);
		}

		void
		pop()
		{
			this->_c.pop_back();
		}
		
};

template<typename T, typename Container>
inline bool
operator==(const stack<T, Container>& lhs,
			const stack<T, Container>& rhs)
{
	return lhs._c == rhs._c;
}

template<typename T, typename Container>
inline bool
operator<(const stack<T, Container>& lhs,
			const stack<T, Container>& rhs)
{
	return lhs._c < rhs._c;
}

template<typename T, typename Container>
inline bool
operator!=(const stack<T, Container>& lhs,
			const stack<T, Container>& rhs)
{
	return !(lhs == rhs);
}

template<typename T, typename Container>
inline bool
operator>(const stack<T, Container>& lhs,
			const stack<T, Container>& rhs)
{
	return rhs < lhs;
}

template<typename T, typename Container>
inline bool
operator<=(const stack<T, Container>& lhs,
			const stack<T, Container>& rhs)
{
	return !(rhs < lhs);
}

template<typename T, typename Container>
inline bool
operator>=(const stack<T, Container>& lhs,
			const stack<T, Container>& rhs)
{
	return !(lhs < rhs);
}


}

#endif
