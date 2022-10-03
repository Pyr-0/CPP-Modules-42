/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 01:57:45 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/10/03 02:07:07 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_H_
# define MUTANT_STACK_H_

# include <stack>
# include <iterator>


//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

template <typename T>
class MutantStack : public std::stack<T> {
private:
	typedef typename std::stack<T>::container_type  Base_;

public:
	typedef typename Base_::iterator			  iterator;
	typedef typename Base_::const_iterator		const_iterator;
	typedef typename Base_::reverse_iterator	const_reverse_iterator;
	typedef typename Base_::reverse_iterator	reverse_iterator;

	iterator begin(void) { return this->c.begin(); }
	iterator end(void) { return this->c.end(); }
	const_iterator cbegin(void) const { return this->c.begin(); }
	const_iterator cend(void) const { return this->c.end(); }
	const_reverse_iterator rbegin(void) const { return this->c.rbegin(); }
	const_reverse_iterator rend(void) const { return this->c.rend(); }
	reverse_iterator rbegin(void) { return this->c.rbegin(); }
	reverse_iterator rend(void) { return this->c.rend(); }
};

#endif