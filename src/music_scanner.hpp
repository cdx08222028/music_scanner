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
#include <boost/interprocess/ipc/message_queue.hpp>
class music_scanner
{
	public:
	std::string mq_name;
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
