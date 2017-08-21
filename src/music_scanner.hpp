/*
 * music_scanner_daemon.hpp
 *
 *  Created on: Aug 21, 2017
 *      Author: harry
 */

#ifndef MUSIC_SCANNER_HPP_
#define MUSIC_SCANNER_HPP_

#include <string>
#include <iostream>
#include <experimental/filesystem>

class music_scanner
{
	public:
	std::string path;
	std::string outfile;
	void printout();
	void tofile();
	//TODO: Add initializer to configure variables
	music_scanner();
	~music_scanner();
	private:
};



#endif /* MUSIC_SCANNER_HPP_ */
