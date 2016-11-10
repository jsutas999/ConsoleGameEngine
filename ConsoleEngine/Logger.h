#pragma once
#include <list>
#include <fstream>
#include <iostream>
// Message logging to screen and external files
class Logger
{
public:
	// Returns instance of it self
	static Logger* getInstance();
	// Adds a new message that is printed to the screen and output file
	void AddMsg(std::string msg);
	// Prints all the messages from the list;
	void PrintMsg();
	Logger();
	~Logger();

private:
	std::list<std::string> msg;
	static Logger* singleton;
	std::ofstream out;
};

