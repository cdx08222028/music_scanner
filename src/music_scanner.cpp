/*
 * music_scanner_daemon.cpp
 *
 *  Created on: Aug 21, 2017
 *      Author: harry
 */

#include "music_scanner.hpp"
#include "music_type.hpp"
namespace fs = std::experimental::filesystem;
music_scanner::music_scanner()
{
	//TODO: Set default outfile
	path = "/home";
}
music_scanner::~music_scanner()
{
	//TODO: Close file IO
}
void music_scanner::printout()
{
	music_type is_music;
	for (auto & p : fs::recursive_directory_iterator(path))
		if(is_music(p.path()))
		{
			std::cout << p << std::endl;
		}
}
