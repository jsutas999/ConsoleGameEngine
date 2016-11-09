#pragma once
#include<list>
#include<iostream>
class Logger
{
public:
	static Logger* getInstance();
	void AddMsg(std::string msg);
	void PrintMsg();
	Logger();
	~Logger();

private:
	std::list<std::string> msg;
	static Logger* singleton;
};

