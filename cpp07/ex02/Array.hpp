/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:29:52 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/27 13:24:58 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <iostream>

//============COLORS!=======//
#define						RED "\e[31m"
#define						GREEN "\e[32m"
#define						BLUE "\e[36m"
#define						LILA "\e[35m"
#define						YLLW "\e[33m"
#define						RESET "\e[0m"

template <typename T>
class	Array{
	
	private:

		T *arr_data_;
		unsigned int n_;

	public:
		Array():arr_data_(NULL), n_(0){}

		Array(unsigned int n):n_(n){

			arr_data_ = new T[n];
		}

		Array(const Array& copy){

			this->arr_data_ = NULL;
			*this = copy;
		}

		~Array(){

			if (arr_data_ != NULL)
				delete [] arr_data_;
		}

		Array & operator=( const Array & rhs ){

			if (this == &rhs){
				return *this;
			}
			this->n_ = rhs.n_;
			if (this->arr_data_ != NULL){
				delete [] this->arr_data_;
			}
			this->arr_data_ = new T[this->n_];
			for (int i = 0; i < n_; i++){
				this->arr_data_[i] = rhs.arr_data_[i];
			}
			return *this;
		}

		T & operator[](int i){

			if (i < 0 || (unsigned int)i >= n_)
				throw BadNumException();
			return arr_data_[i];
		}

		const T & operator[](int i) const{
			if (i < 0 || (unsigned int)i >= n_){
				throw BadNumException();
			}
			return arr_data_[i];
		}

		unsigned int size() const{
			return n_;
		}

	 class BadNumException : public std::exception{
		public:
			const char * what() const throw(){
				return "Bad index : Out of bounds ";
			}
	};
	
	unsigned int	size( void ) const{
		 return (_n);
	}
};


#endif
