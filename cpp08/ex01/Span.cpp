/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:44:21 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/10/03 15:56:15 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span(const std::size_t &size):size_(size){
	elems_.reserve(size); //from the beginning we are creating specific space in our VECTOR for the elements we will use.
}

Span::Span(const Span &copy):size_(copy.size_), elems_(copy.elems_){}

Span::Span(int first, int last, int jump)
{
	unsigned int _n_contents = 0;
	int f, l;
	if (last > first)
	{
		f = first;
		l = last;
	}
	else
	{
		f = last;
		l = first;
	}
	size_= std::abs((last - first) / jump);
	elems_.reserve(size_);
	for (int i = f; i < l; i += jump)
		elems_.push_back(i);
	_n_contents = size_;
}

Span::~Span(void) {}

Span &Span::operator=(const Span &rhs) {
	if (this == &rhs)
		return *this;
	size_ = rhs.size_;
	elems_ = rhs.elems_;
	return *this;
}

void Span::addNumber(int i) {
		if (elems_.size() >= size_ )
			throw std::length_error("[ Length Error ] container is full!");
		elems_.push_back(i);

}

void	Span::addNumber(my_iter start, my_iter end)
{
	if (end < start)
		throw std::runtime_error("[ Range Error ] last number must be bigger than first!");
		return ;
	for (my_iter i = start; i != end; i++)
		addNumber(*i);
}

/*	We use the sort and max algorithms from the STL*/
unsigned int Span::shortestSpan(void) const{

	int	shortest_span = std::numeric_limits<int>::max();
	std::vector<int> tempVector = elems_;
		if (elems_.size() <= 1)
			throw std::runtime_error("[ Span Error ] container must have more than one!");

	if(tempVector.size() > 1)
	{
		std::sort(tempVector.begin(), tempVector.end());
		std::vector<int>::iterator first = tempVector.begin();
		std::vector<int>::iterator second = tempVector.begin() + 1;
		for (;second != tempVector.end(); first++, second++){
			if((*second - *first) < shortest_span)
				shortest_span = (*second - *first);
		}
	}
	return shortest_span;
}

unsigned int Span::longestSpan(void) const{

	if (elems_.size() <= 1)
		throw std::runtime_error("[ Span Error ] Container must have more than one!");
	int highest_val = *std::max_element(elems_.begin(), elems_.end());
	int lowest_val = *std::min_element(elems_.begin(), elems_.end());
	return static_cast<std::size_t>(std::abs(highest_val - lowest_val));
}

std::vector<int> const & Span::getelems(void)const{
	return this->elems_;
}

std::ostream & operator<<(std::ostream & o, Span const & ref){
	o << ref.getelems()[0] << std::endl;
	return (o);
}
