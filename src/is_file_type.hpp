/*
 * music_type.hpp
 *
 *  Created on: Aug 21, 2017
 *      Author: harry
 */

#ifndef IS_FILE_TYPE_HPP_
#define IS_FILE_TYPE_HPP_

#include <string>
#include <iostream>
#include <regex>
#include <experimental/filesystem>

class is_file_type
{
	public:
	void set_suffix_regex(const std::string & suffix);
	virtual bool check(const std::string & f_name);
	virtual bool operator()(const std::string & f_name);
	virtual bool operator()(const std::experimental::filesystem::path & f_name);
	is_file_type();
	virtual ~is_file_type();
	private:
	std::regex file_suffix;
};


#endif /* IS_FILE_TYPE_HPP_ */
