/*
 * music_type.hpp
 *
 *  Created on: Aug 21, 2017
 *      Author: harry
 */

#ifndef MUSIC_TYPE_HPP_
#define MUSIC_TYPE_HPP_

#include <string>
#include <iostream>
#include <regex>

class music_type
{
	public:
	std::regex music_f_suff;
	bool is_music(std::string f_name);
	//TODO: Add initializer to configure variables
	music_type();
	~music_type();
	bool operator()(std::string f_name);
	private:
};



#endif /* MUSIC_TYPE_HPP_ */
