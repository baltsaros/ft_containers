/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:58:23 by abuzdin           #+#    #+#             */
/*   Updated: 2023/01/23 07:58:24 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {
	template <class T1, class T2>
	struct pair {
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair(): first(), second() {}
		pair(const T1&x, const T2& y): first(x), second(y) {}
		template <class U1, class U2>
		pair(const pair<U1, U2>& p): first(p.first), second(p.second) {}
		pair(const pair& p): first(p.first), second(p.second) {}

		pair&	operator=(const pair& other) {
			first = other.first;
			second = other.second;
			return (*this);
		}
	};

	template <class T1, class T2>
	pair<T1, T2>	make_pair(T1 t, T2 u) {
		return (pair<T1, T2>(t, u));
	}

	template <class T1, class T2>
	bool	operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
	}

	template <class T1, class T2>
	bool	operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T1, class T2>
	bool	operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		bool	ret;

		ret = lhs.first < rhs.first;
		if (!ret)
			ret = lhs.second < rhs.second;
		return (ret);
	}

	template <class T1, class T2>
	bool	operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		bool	ret;

		ret = lhs < rhs;
		if (!ret)
			ret = lhs == rhs;
		return (ret);
	}

	template <class T1, class T2>
	bool	operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (!(lhs <= rhs));
	}

	template <class T1, class T2>
	bool	operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (!(lhs < rhs));
	}
};

#endif