/*
 * music_scanner_daemon.hpp
 *
 *  Created on: Aug 21, 2017
 *      Author: harry
 */

#ifndef FILE_SCANNER_HPP_
#define FILE_SCANNER_HPP_

#define MUSIC_SCANNER_MQ_SIZE 1000
/*
 * loads the following common audio formats by default
 * "(.*\\.mp3|wav|m4a|ogg|wma|aif|flac)"
 */
#define MUSIC_FILE_SUFFIX ".*(mp3|wav|m4a|ogg|wma|aif|flac)"

#include <string>
#include <iostream>
#include <map>
#include <experimental/filesystem>
#include <fstream>
#include <boost/interprocess/ipc/message_queue.hpp>
#include "is_file_type.hpp"
class file_scanner
{
public:
	void update();
	void set_path(const std::string & path);
	void set_regex(const std::string & regex);
	void set_seperator(const std::string & seperator);
	template <typename T>
	void printout(T& outhandle);

	virtual void to_file();
	virtual void to_file(const std::string & filename);
	virtual void create_message_queue();
	virtual void create_message_queue(const std::string & name);

	file_scanner();
	file_scanner(const std::string & path);

	virtual ~file_scanner();

private:
	std::string outfile{"music_scanner_output.txt"};
	std::string mq_name{"music_scanner_mq"};
	std::string to_file_seperator{","};

	std::fstream filehandle;
	is_file_type is_music;
	std::string scan_path;
	std::multimap<std::string,std::string> file_location;
};
#endif /* FILE_SCANNER_HPP_ */
