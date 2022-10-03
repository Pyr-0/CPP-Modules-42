/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 01:57:17 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/10/03 02:17:06 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>
#include <string>

void basic_test(void) {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout <<BLUE<< mstack.top() <<RESET<< std::endl;
	mstack.pop();
	std::cout<<BLUE << mstack.size() <<RESET<< std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout <<YLLW<< *it <<RESET<< std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

void list_test(void) {
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout <<BLUE<< mstack.back() << RESET<<std::endl;
	mstack.pop_back();
	std::cout<<BLUE << mstack.size() << RESET<<std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout <<YLLW<< *it <<RESET<< std::endl;
	++it;
	}
	std::list<int> s(mstack);
}

void iterator_test(void) {
	MutantStack<std::string> mstack;
	mstack.push("hello");
	mstack.push("I'm");
	mstack.push("milton");
	mstack.push("have a good day!");

	std::cout <<GREEN<< "===== iterator =====" <<RESET<< std::endl;
	MutantStack<std::string>::iterator it = mstack.begin();
	MutantStack<std::string>::iterator end = mstack.end();
	for (; it != end; ++it)
		std::cout <<YLLW<< *it << RESET<<std::endl;
	std::cout << std::endl;

	std::cout <<GREEN<< "===== const_iterator =====" <<RESET<< std::endl;
	MutantStack<std::string>::const_iterator cit = mstack.cbegin();
	MutantStack<std::string>::const_iterator cend = mstack.cend();
	for (; cit != cend; ++cit)
		std::cout <<YLLW<< *cit <<RESET<< std::endl;
	std::cout << std::endl;

	std::cout <<GREEN<< "===== const_reverse_iterator =====" <<RESET<< std::endl;
	MutantStack<std::string>::const_reverse_iterator cnit = mstack.rbegin();
	MutantStack<std::string>::const_reverse_iterator cnend = mstack.rend();
	for (; cnit != cnend; ++cnit)
		std::cout <<YLLW<< *cnit << RESET<<std::endl;
	std::cout << std::endl;

	std::cout <<GREEN<< "===== reverse_iterator =====" <<RESET<< std::endl;
	MutantStack<std::string>::reverse_iterator rit = mstack.rbegin();
	MutantStack<std::string>::reverse_iterator rend = mstack.rend();
	for (; rit != rend; ++rit)
		std::cout<<YLLW << *rit <<RESET<< std::endl;
	std::cout << std::endl;
}

int main()
{
	std::cout <<GREEN<<GREEN<< "===== basic test =====" <<RESET<<RESET<< std::endl;
	basic_test();
	std::cout << std::endl;

	std::cout <<GREEN<< "===== list test =====" <<RESET<< std::endl;
	list_test();

	std::cout <<GREEN<< "===== All terators Test =====" <<RESET<<std::endl<< std::endl;
	iterator_test();
		
}