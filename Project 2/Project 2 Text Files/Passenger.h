#include <string>
#include <cmath>
using namespace std;

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