/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:46:44 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 19:37:12 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl complaint;

	complaint.complain("debug");
	complaint.complain("info");
	complaint.complain("warning");
	complaint.complain("error");
	complaint.complain("");
}