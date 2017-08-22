/*
 * music_scanner_daemon.hpp
 *
 *  Created on: Aug 21, 2017
 *      Author: harry
 */

#ifndef MUSIC_SCANNER_HPP_
#define MUSIC_SCANNER_HPP_
#define MUSIC_SCANNER_MQ_SIZE 1000
#include <string>
#include <iostream>
#include <experimental/filesystem>
#include <fstream>
#include <boost/interprocess/ipc/message_queue.hpp>
#include "music_type.hpp"
class music_scanner
{
	public:

	std::string path;
	std::string outfile;
	void printout();
	void tofile();
	void set_file_seperator();
	void set_file_handle();
	void set_message_queue();
	void set_is_music_regex();
	//TODO: Add initializer to configure variables
	music_scanner();
	~music_scanner();
	private:
	music_type is_music;
	std::string mq_name;
	std::fstream filehandle;
	std::string to_file_seperator;
};



#endif /* MUSIC_SCANNER_HPP_ */
