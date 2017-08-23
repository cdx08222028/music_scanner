/*
 * music_scanner_daemon.cpp
 *
 *  Created on: Aug 21, 2017
 *      Author: harry
 */

#include "file_scanner.hpp"

namespace fs = std::experimental::filesystem;
file_scanner::file_scanner()
{
	//defaults
	mq_name="music_scanner_mq";
	outfile = "music_scanner_output.txt";
	to_file_seperator = ',';
	is_music.set_suffix_regex(MUSIC_FILE_SUFFIX);
	scan_path = fs::current_path();
}
file_scanner::~file_scanner()
{
	boost::interprocess::message_queue::remove(mq_name.c_str());
	filehandle.close();
}
void file_scanner::set_path(const std::string & path)
{
	scan_path=path;
}
void file_scanner::set_regex(const std::string & regex)
{
	is_music.set_suffix_regex(regex);
}

void file_scanner::set_seperator(const std::string & seperator)
{
	to_file_seperator=seperator;
}

template <typename T>
void file_scanner::printout(T& outhandle)
{
	for (auto iter=file_location.begin();iter != file_location.end(); iter++)
	{
		outhandle << iter->first
				<< to_file_seperator
				<< iter->second
				<< "\n";
	}
}
/*
 * TODO:run https://github.com/apetrone/simplefilewatcher or QtFileWatcher
 * when change is detected schedule a rescan after activity has died down...
 */

void file_scanner::update()
{
	using namespace std;
	//fstream does not create file by default, must add arguments
	filehandle.open(outfile, fstream::in | fstream::out | fstream::trunc);
	for (auto & p : fs::recursive_directory_iterator(scan_path))
	{
		if(is_music(p.path()))
		{
			file_location.insert(pair<string,string>
			(p.path().parent_path().string(),p.path().filename().string()));
		}
	}
	filehandle.close();
}
void file_scanner::to_file()
{
	using namespace std;
	filehandle.open(outfile, fstream::in | fstream::out | fstream::trunc);
	printout(filehandle);
	filehandle.close();
}
void file_scanner::to_file(const std::string & filename)
{
	filehandle.close();
	outfile=filename;
	to_file();
}

void file_scanner::create_message_queue()
{
	using namespace boost::interprocess;
	message_queue::remove(mq_name.c_str());
	message_queue temp(create_only     //only create
			,mq_name.c_str()          //name
			,MUSIC_SCANNER_MQ_SIZE     //max message number
			,sizeof(char)              //max message size
	);
}

void file_scanner::create_message_queue(const std::string & name)
{
	using namespace boost::interprocess;
	message_queue::remove(mq_name.c_str());
	mq_name=name;
	create_message_queue();
}
