/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:12:46 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/21 13:36:40 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/*	a "uintprt_t" It's an unsigned integer type exactly the size of a pointer.
	Whenever you need to do something unusual with a pointer - 
	like for example invert all bits (don't ask why) you cast it
	to uintptr_t and manipulate it as a usual integer number, then cast back.
	Is capable to hold a void ptr */

/*	we get a data+ and make it into a void ptr, making something specific into something broad UPCASTING*/
uintptr_t serialize(Data* ptr){

	return reinterpret_cast<uintptr_t>(ptr);
}

/*	we get a void * and make it into a Data* , making something specific into something broad DOWNCASTING*/
Data* deserialize(uintptr_t raw){

	return reinterpret_cast<Data*>(raw);
}

