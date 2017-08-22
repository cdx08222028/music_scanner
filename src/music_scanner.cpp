/*
 * music_scanner_daemon.cpp
 *
 *  Created on: Aug 21, 2017
 *      Author: harry
 */

#include "music_scanner.hpp"

using namespace boost::interprocess;
namespace fs = std::experimental::filesystem;
music_scanner::music_scanner()
{
	mq_name="music_scanner_mq";
	/*
	 * TODO: use timed send to see if anything is accessing queue, if something is
	 * accessing the message queue then open the text file and read from top
	 * May need to use boost::serialization & Protocol Buffers for more complex data later...
	 */
	message_queue::remove(mq_name.c_str());
	message_queue temp(create_only     //only create
			,mq_name.c_str()          //name
			,MUSIC_SCANNER_MQ_SIZE     //max message number
			,sizeof(char)              //max message size
	);
	outfile = "music_scanner_output.txt";
	to_file_seperator = ",";
	path = "/home/harry";
	//fstream does not create file by default, must add arguments
	filehandle.open(outfile, std::fstream::in | std::fstream::out | std::fstream::trunc);
}
music_scanner::~music_scanner()
{
	message_queue::remove(mq_name.c_str());
	filehandle.close();
	//TODO: Close file IO
}
void music_scanner::printout()
{
	//TODO setup a quick read of the printout file.
}
/*
 * TODO:run https://github.com/apetrone/simplefilewatcher or QtFileWatcher
 * when change is detected schedule a rescan after activity has died down...
 */
void music_scanner::tofile()
{
	for (auto & p : fs::recursive_directory_iterator(path))
	{
		if(is_music(p.path()))
		{
			std::cout<<p.path()<<std::endl;
			filehandle << p.path().parent_path().string() << to_file_seperator << p.path().filename().string() << "\n";
		}
	}
}
