/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:45:59 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/10/03 15:55:54 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H_
# define SPAN_H_

#include <vector>
#include <algorithm>
#include <exception>
#include <limits>
#include <iostream>

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

typedef std::vector<int>::iterator my_iter;
class Span {

	private:
		Span(void);

		unsigned int size_;						// this is N, is the counter needs to be positive  numbers
		std::vector<int> elems_;				//this is the container , dynamic Array where we will store our numbers
	public:
		Span(const std::size_t &size);
		Span(const Span &copy);
		Span(int first, int last, int jump);
		~Span(void);
		Span &operator=(const Span &rhs);

		void	addNumber(int i);
		void	addNumber(int i, int j);
		void	addNumber(std::vector<int> anotherVector);
		void	addNumber(my_iter start, my_iter end);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		std::vector<int> const &getelems(void)const;
};

std::ostream & operator<<(std::ostream & o, Span const & ref);
#endif