#include <string>
#include <iostream>
#include "Passenger.h"
using namespace std;

Passenger::Passenger()
{
	FirstName = "N/A";
	LastName = "N/A";
	Next = NULL;
}

Passenger::Passenger(string firstname, string lastname)
{
	FirstName = firstname;
	LastName = lastname;
	Next = NULL;
}

Passenger::Passenger(const Passenger& orig)
{
	FirstName = orig.FirstName;
	LastName = orig.LastName;
	Next = orig.Next;
}

Passenger::~Passenger()
{
}

string Passenger::getFirstName()
{
	return FirstName;
}

string Passenger::getLastName()
{
	return LastName;
}

Passenger* Passenger::getNext()
{
	return Next;
}

void Passenger::setFirstName(string firstname)
{
	FirstName = firstname;
}

void Passenger::setLastName(string lastname)
{
	LastName = lastname;
}

void Passenger::setNext(Passenger * next)
{
	Next = next;
}

string Passenger::print() const
{
	return FirstName + " " + LastName + ", ";
}