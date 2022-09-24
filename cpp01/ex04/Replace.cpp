/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:47:12 by mrojas-e          #+#    #+#             */
/*   Updated: 2022/09/24 19:36:51 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

//============CONSTRUCTOR=========//

/*	This constructor  will open our file and check if the file is empty,
	and at the end it appends the new file extention to ".replace"*/
myReplace::myReplace(std::string filename, std::string str1, std::string str2):_str1(str1), _str2(str2){

	_readFile.open(filename.c_str());
	if(_readFile.is_open())
	{
		std::streambuf* ptr_to_buf = _readFile.rdbuf();		//read readfiles input into a buffer
		char c;
		std::streamsize size = ptr_to_buf->sgetn(&c, 1);	//reads one char at a time 
		if(size == 0)
		{
			std::cout <<RED<< "File Error: file is empty" <<RESET<< std::endl;
			std::exit(1);
		}
		ptr_to_buf->sputbackc(c);							//returns the character stored in buffer back to its place
		_writeFile.open(filename.append(".replace"));
		//_writeFile.open(filename + ".replace");			//same result as previous line 
	}
}

//============METHODS=========//

/* This Function will check if there is any error while accessing  file and return
	true or false if the file opens or not*/
bool	myReplace::check_file(){

	if(_readFile.fail() ||_writeFile.fail())
		return (false);
	else if (_readFile.is_open() && _writeFile.is_open())
		return (true);
	return (false);
}

/*	This function will read from our file and find the string that will be change
	and replace it with the second string, while keeping track of the index where
	it should repeat the process until it reaches the EOF */
void	myReplace::do_replace(){

	std::string line;
	std::size_t word_index;
	while (!_str1.empty() && std::getline(_readFile, line))	//reads line by line from file into the string "line"
	{
		word_index = line.find(_str1);
		while (word_index != std::string::npos)
		{
			line.erase(word_index, _str1.length());
			line.insert(word_index, _str2);
			word_index += _str2.size();
			word_index = line.find(_str1, word_index);
		}
		if(!_readFile.eof())
			_writeFile << line << std::endl;
		else
			_writeFile << line;
	}
}

//============DESTRUCTOR=========//

myReplace::~myReplace(){

	if(_readFile.is_open())
		_readFile.close();
	if(_writeFile.is_open())
		_writeFile.close();
}
