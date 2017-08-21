/*
 * music_type.cpp
 *
 *  Created on: Aug 21, 2017
 *      Author: harry
 */

#include "music_type.hpp"
music_type::music_type ()
{
	/*
	 * loads the following common audio formats by default
	 */
	music_f_suff="(.*\.mp3|wav|m4a|ogg|wma|aif|flac)";
}
music_type::~music_type ()
{

}
bool music_type::is_music (std::string f_name)
{
	return std::regex_match(f_name, music_f_suff);
}
bool music_type::operator ()(std::string f_name)
{
	return is_music(f_name);
}

