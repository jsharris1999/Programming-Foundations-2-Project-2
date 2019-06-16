#include "Manifest.h"
#include "Passenger.h"
#include <time.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	string command = "0";
	string filename = "0";
	string UserFirstName = "N/A";
	string UserLastName = "N/A";
	bool Check = false;
	Manifest PassengerList = Manifest();
	ifstream fin;
	ofstream fout;
	cout << "Please enter the name of the file that contains the passenger data." << endl;
	cin >> filename;
	cin.ignore();
	fin.open(filename);
	fout.open("Output.txt");
	while (command != "5")
	{
		/*
		fout << "Welcome to Razorback Airlines." << endl;
		fout << "Valid commands are:" << endl;
		fout << "1: Book a Flight" << endl;
		fout << "2: Cancel a Booking" << endl;
		fout << "3: Confirm a Booking" << endl;
		fout << "4: View the list of Passengers" << endl;
		fout << "5: Quit the Program" << endl;
		fout << "Please enter the number corresponding to a command you wish to select." << endl;
		*/
		fin >> command;
		fin.ignore();
		while (((command != "1") == 1) && ((command != "2") == 1) && ((command != "3") == 1) && ((command != "4") == 1) && ((command != "5") == 1))
		{
			command = "0";
			fout << "That command is not valid." << endl;
			fin >> command;
			fin.ignore();
		}
		if (command == "1")
		{
			//fout << "Please enter your first name." << endl;
			fin >> UserFirstName;
			fin.ignore();
			//fout << "Please enter your last name." << endl;
			fin >> UserLastName;
			fin.ignore();
			Check = PassengerList.insert(UserFirstName, UserLastName);
			if (Check == true)
			{
				fout << "Your flight has been booked successfully." << endl;
			}
			else
			{
				fout << "Declined booking for " << UserFirstName << " " << UserLastName << "." << endl;
			}
			command = "0";
		}
		else if (command == "2")
		{
			//fout << "Please enter your first name." << endl;
			fin >> UserFirstName;
			fin.ignore();
			//fout << "Please enter your last name." << endl;
			fin >> UserLastName;
			fin.ignore();
			Check = PassengerList.remove(UserFirstName, UserLastName);
			if (Check == true)
			{
				fout << "Your booking has been cancelled successfully." << endl;
			}
			else
			{
				fout << "Could not cancel booking for " << UserFirstName << " " << UserLastName << "." << endl;
			}
			command = "0";
		}
		else if (command == "3")
		{
			//fout << "Please enter your first name." << endl;
			fin >> UserFirstName;
			fin.ignore();
			//fout << "Please enter your last name." << endl;
			fin >> UserLastName;
			fin.ignore();
			Check = PassengerList.search(UserFirstName, UserLastName);
			if (Check == true)
			{
				fout << "Confirmed booking for " << UserFirstName << " " << UserLastName << "." << endl;
			}
			else
			{
				fout << UserFirstName << " " << UserLastName << " was not found." << endl;
			}
			command = "0";
		}
		else if (command == "4")
		{
			fout << "Here is the current list of passengers sorted by their last names." << endl;
			fout << PassengerList.print() << endl;
			command = "0";
		}
		else if (command == "5")
		{
			fout << "Thank you for using our flight service." << endl;
		}
	}
	fin.close();
	fout.close();
	cout << "Thank you for using our flight service." << endl;
	return 0;
}