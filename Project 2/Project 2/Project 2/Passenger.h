#include <string>
using namespace std;

#ifndef Passenger_H
#define Passenger_H

class Passenger
{
public:
	//Constructors and destructor
	Passenger();
	Passenger(string firstname, string lastname);
	Passenger(const Passenger& orig);
	~Passenger();

	string getFirstName();
	string getLastName();
	Passenger *getNext();
	void setFirstName(string firstname);
	void setLastName(string lastname);
	void setNext(Passenger * next);
	string print() const;

private:
	string FirstName;
	string LastName;
	Passenger * Next;

};

#endif
