#include "Passenger.h"
#include <time.h>
#include <iostream>
#include <cmath>
using namespace std;

class Manifest
{
public: 
	Manifest();
	Manifest(const Manifest & list);
	~Manifest();

	bool search(string firstname, string lastname);
	bool insert(string firstname, string lastname);
	bool remove(string firstname, string lastname);
	string print() const;

private:
	Passenger * Head;
};