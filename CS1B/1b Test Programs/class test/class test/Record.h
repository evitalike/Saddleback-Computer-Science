#pragma once
#include <string>
#include <iostream>

class Record
{
	private:
		int id;
		std::string first;
		std::string last;
		std::string address;
		std::string city;
		std::string state;
	public:
		Record(int id, std::string first, std::string last, std::string address, std::string city, std::string state);
		Record();
		~Record();
		int getID();
		std::string getFirst();
		std::string getLast();
		std::string getAddress();
		std::string getCity();
		std::string getState();
		void showID(int id);
		void showFirst(std::string first);
		void showLast(std::string last);
		void showAddress(std::string address);
		void showCity(std::string city);
		void showState(std::string state);
};