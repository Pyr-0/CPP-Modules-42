/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:58:54 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/28 22:43:07 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "easyfind.hpp"


int	main(){

// // for testing we create a container of type Vector
// 	std::vector<int> vc;
	
// // We fill it with numbers 
// 	for (int i = 0; i < 20; ++i)
// 		vc.push_back(i);
		
	
// // We fill it with numbers 
// 	std::vector<int>::const_iterator iter = vc.begin();
// 	for (; iter != vc.end(); ++iter)
// 		std::cout << *iter << std::endl;
		
// 	try{
// 		easyfind<std::vector<int> >(vc, 40);
// 	}catch (std::exception &e){
// 		std::cerr << e.what()<< std::endl;
// 	}

	std::vector<int> v;

	for(int i = -1; i < 10; ++i)
	v.push_back(i);

	std::vector<int>::const_iterator it;
	try{
		it = easyfind(v, 2);
		std::cout << *it << std::endl;
	}catch(std::exception &e){
		std::cerr <<RED<< e.what()<< RESET<<std::endl;
	}
}

// #include <vector>
// #include <list>
// #include <deque>
// #include <iostream>

// #include "easyfind.hpp"

// int main(void) {
// 	std::vector<int> v_container;
// 	std::list<int> l_container;
// 	std::deque<int> d_container;

// 	for (int i = 0; i < 10; ++i) {
// 		v_container.push_back(i);
// 		l_container.push_back(i);
// 		d_container.push_back(i);
// 	}

// 	std::cout << "===== test with vector =====" << std::endl;
// 	for (int i = 0; i < 15; ++i) {
// 		std::vector<int>::const_iterator v_it = easyfind(v_container, i);
// 		if (v_it == v_container.end())
// 			std::cerr << i << " is not founded" << std::endl;
// 		else
// 			std::cout << i << " is founded!" << std::endl;
// 	}
// 	std::cout << std::endl;

// 	std::cout << "===== test with list =====" << std::endl;
// 	for (int i = 0; i < 15; ++i) {
// 		std::list<int>::const_iterator l_it = easyfind(l_container, i);
// 		if (l_it == l_container.end())
// 			std::cerr << i << " is not founded" << std::endl;
// 		else
// 			std::cout << i << " is founded!" << std::endl;
// 	}
// 	std::cout << std::endl;

// 	std::cout << "===== test with deque =====" << std::endl;
// 	for (int i = 0; i < 15; ++i) {
// 		std::deque<int>::const_iterator d_it = easyfind(d_container, i);
// 		if (d_it == d_container.end())
// 			std::cerr << i << " is not founded" << std::endl;
// 		else
// 			std::cout << i << " is founded!" << std::endl;
// 	}
// 	std::cout << std::endl;
// }