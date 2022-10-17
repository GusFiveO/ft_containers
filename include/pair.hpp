/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:33:53 by alorain           #+#    #+#             */
/*   Updated: 2022/10/17 20:38:52 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template<typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type	first;
		second_type	second;

		pair(void)
		: first(), second() {}

		pair(const first_type& a, const second_type& b)
		: first(a), second(b) {}
		
		template<typename U1, typename U2>
		pair(const pair<U1, U2>& p)
		: first(p.first), second(p.second) {}

		pair&
		operator=(pair assign)
		{
			if (&assign != this)
			{
				first = assign.first;
				second = assign.second;
			}
			return *this;
		}
	};

	template<class T1, class T2> 
	inline bool
    operator==(const pair<T1, T2>& x, const pair<T1, T2>& y)
    { 
		return x.first == y.first && x.second == y.second; 
	}

	template<class T1, class T2>
    inline bool
    operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
    { 
		return x.first < y.first
         || (!(y.first < x.first) && x.second < y.second); 
	}

	template<class T1, class T2>
    inline bool
    operator!=(const pair<T1, T2>& x, const pair<T1, T2>& y)
    {
		return !(x == y);
	}

	template<class T1, class T2>
    inline bool
    operator>(const pair<T1, T2>& x, const pair<T1, T2>& y)
    { 
		return y < x; 
	}

	template<class T1, class T2>
    inline bool
    operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y)
    { 
		return !(y < x); 
	}

	template<class T1, class T2>
    inline bool
    operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y)
    { 
		return !(x < y); 
	}
	
	template<typename T1, typename T2>
	inline pair<T1, T2>
	make_pair(T1 x, T2 y)
	{
		return pair<T1, T2>(x, y);
	}

}

#endif
