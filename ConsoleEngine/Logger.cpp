#include "Logger.h"

Logger* Logger::singleton;

Logger * Logger::getInstance()
{
	return singleton;
}

void Logger::AddMsg(std::string message)
{
	msg.push_back(message);
	out << message.c_str() << std::endl;

	if (msg.size() > 5)
		msg.pop_front();
}

void Logger::PrintMsg()
{

	if (msg.size() == 0) return;

	std::cout << "\n";
	for (std::list<std::string>::iterator it = msg.begin(); it != msg.end(); it++)
	{
		std::cout << it->c_str()  << "\n";
	}
}

Logger::Logger()
{
	if (singleton == NULL)
		singleton = this;

	out.open("output.txt", std::ofstream::out);

}


Logger::~Logger()
{
	msg.clear();
	out.close();
}
