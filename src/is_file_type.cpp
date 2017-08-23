/*
 * music_type.cpp
 *
 *  Created on: Aug 21, 2017
 *      Author: harry
 */

#include "is_file_type.hpp"
is_file_type::is_file_type ()
{
	//Will match any file by default
	file_suffix="(.*\\..*)";
}
is_file_type::~is_file_type ()
{

}
bool is_file_type::check(const std::string & f_name)
{
	return std::regex_match(f_name, file_suffix);
}
bool is_file_type::operator()(const std::string & f_name)
{
	return check(f_name);
}

bool is_file_type::operator()(const std::experimental::filesystem::path & f_name)
{
	return check(f_name.c_str());
}
void is_file_type::set_suffix_regex(const std::string & suffix)
{
	file_suffix=suffix;
}
