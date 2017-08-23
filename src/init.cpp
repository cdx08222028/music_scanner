//============================================================================
// Name        : music_scanner_daemon.cpp
// Author      : Harry He
// Version     : V0.0.2
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
#include <fstream>

#include "file_scanner.hpp"
#include "is_file_type.hpp"

int main()
{
	file_scanner scanner;
	scanner.set_path("/home/harry");
	scanner.update();
	scanner.to_file();
}
