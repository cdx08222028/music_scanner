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
#include <experimental/filesystem>

class music_type
{
	public:
	std::smatch results;
	bool is_music(std::string f_name);
	bool operator()(std::string f_name);
	bool operator()(std::experimental::filesystem::path f_name);
	//TODO: Add initializer to configure variables
	void set_suffix();
	music_type();
	~music_type();
	private:
	std::regex music_f_suff;
};


#endif /* MUSIC_TYPE_HPP_ */
