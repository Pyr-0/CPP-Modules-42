/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:58:54 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/10/03 15:34:28 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "easyfind.hpp"

void	test1(){

	
	std::cout <<std::endl;
	std::cout <<GREEN<< "TESTING SINGLE CONTAINERS RANDOMLY" <<RESET<<std::endl;
	std::cout <<GREEN<< " [RUN MULTIPLE TIMES FOR TESTING]" <<RESET<<std::endl;
	std::cout <<std::endl;
	std::vector<int> v;

	for(int i = -1; i < 10; ++i)
	v.push_back(i);

	//easyfind() will only return number found or error if not 
	std::vector<int>::const_iterator it;
	try{
		it = easyfind(v, (arc4random() % 10 + 1));
		std::cout <<YLLW<< *it <<RESET<< std::endl;
	}catch(std::exception &e){
		std::cerr <<RED<< e.what()<< RESET<<std::endl;
	}
	std::cout <<std::endl;
}

void	test2(){

	// // for testing we create a container of type Vector
	std::cout <<std::endl;
	std::cout <<GREEN<< "TEST ONE VECTOR CONTAINER WITH SPECIFIC NUMBER" <<RESET<<std::endl;
	std::vector<int> vc;
	
// We fill it with numbers
	for (int i = 0; i < 10; ++i)
		vc.push_back(i);

// We create the iterator and print each element inside
	std::vector<int>::const_iterator iter = vc.begin();
	for (; iter != vc.end(); ++iter)
		std::cout <<YLLW<< *iter <<RESET<< std::endl;
	// We implement our easyfind function and look for the wrong number
	std::vector<int>::const_iterator v_iter = easyfind<std::vector<int> >(vc, 5);
	try{
		std::cout <<RED<<"Looking for "<< *v_iter <<RESET<< std::endl;
		if(v_iter != vc.end())
			std::cout <<RED<< *v_iter << YLLW<<" Was found!" <<RESET<< std::endl;
	}catch (std::exception &e){
		std::cerr <<RED<< e.what()<< RESET<<std::endl;
	}
	std::cout <<std::endl;
}

void	test3(){

	std::cout <<std::endl;
	std::cout <<GREEN<< "Testing Multiple containers with an overflow" <<RESET<<std::endl;

	/*	The idea of the test is to create 3 different container types and 
		to fill them up with values, then to create an iterator and apply
		our easy find function to it and finding each member until we reach overflow
		and catch our exception */

	std::vector<int> v_container;
	std::list<int> l_container;
	std::deque<int> d_container;

	for (int i = 1; i <= 10; ++i) {
		v_container.push_back(i);
		l_container.push_back(i);
		d_container.push_back(i);
	}

	std::cout <<GREEN<< "===== Test with Vector =====" <<RESET<< std::endl;
	try{
		for (int i = 1; i <= 15; ++i){
			std::vector<int>::const_iterator v_it = easyfind(v_container, i);
			if (v_it != v_container.end())
			std::cout <<GREEN<< i << YLLW<<" Was found!" <<RESET<< std::endl;
		}
	}catch (std::exception &e){
		std::cerr <<RED<< e.what()<<RESET<< std::endl;
	}
	std::cout << std::endl;

	std::cout <<GREEN<< "===== Test with List =====" <<RESET<< std::endl;
	try{
		for (int i = 1; i <= 15; ++i){
			std::list<int>::const_iterator l_it = easyfind(l_container, i);
			if (l_it != l_container.end())
			std::cout <<GREEN<< i << YLLW<<" Was found!" <<RESET<< std::endl;
		}
	}catch (std::exception &e){
		std::cerr <<RED<< e.what()<<RESET<< std::endl;
	}
	std::cout << std::endl;

	std::cout <<GREEN<< "===== Test with Deque =====" <<RESET<< std::endl;
	try{
		for (int i = 1; i <= 15; ++i){
			std::deque<int>::const_iterator d_it = easyfind(d_container, i);
			if (d_it != d_container.end())
			std::cout <<GREEN<< i << YLLW<<" Was found!" <<RESET<< std::endl;
		}
	}catch (std::exception &e){
		std::cerr <<RED<< e.what()<<RESET<< std::endl;
	}
	std::cout << std::endl;
	std::cout <<std::endl;
}

int	main(){

		test1();
		test2();
		//test3();
}