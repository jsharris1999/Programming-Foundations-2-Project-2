#include "Manifest.h"
#include <string>
#include <iostream>
#include <cstdlib>

Manifest::Manifest()
{
	Head = NULL;
}

Manifest::Manifest(const Manifest & list)
{
	Passenger *copy = new Passenger();
	Head = copy;

	Passenger *ptr = list.Head;
	while (ptr != NULL)
	{
		copy->setNext(new Passenger());
		copy = copy->getNext();
		copy->setFirstName(ptr->getFirstName());
		copy->setLastName(ptr->getLastName());
		copy->setNext(NULL);
		ptr = ptr->getNext();
	}

	copy = Head;
	Head = copy->getNext();
	delete copy;
}

Manifest::~Manifest()
{
	Passenger *ptr = Head;
	while (ptr != NULL)
	{
		Passenger *temp = ptr->getNext();
		delete ptr;
		ptr = temp;
	}
}

bool Manifest::search(string firstname, string lastname)
{
	Passenger *ptr = Head;
	while ((ptr != NULL) && ((ptr->getFirstName() != firstname) || (ptr->getLastName() != lastname)))
	{
		ptr = ptr->getNext();
	}
	if (ptr == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Manifest::insert(string firstname, string lastname)
{
	if (search(firstname, lastname) == true)
	{
		return false;
	}
	Passenger *ptr = new Passenger(firstname, lastname);
	if (Head == NULL || (ptr->getLastName() < Head->getLastName()))
	{
		ptr->setNext(Head);
		Head = ptr;
	}
	else
	{
		Passenger *tempptr = Head;
		Passenger *prev = Head;
		while((tempptr != NULL) && (ptr->getLastName() > tempptr->getLastName()))
		{
			prev = tempptr;
			tempptr = tempptr->getNext();
		}
		ptr->setNext(tempptr);
		prev->setNext(ptr);
	}
	return true;
}

bool Manifest::remove(string firstname, string lastname)
{
	Passenger *ptr = Head;
	Passenger *prev = Head;
	while ((ptr != NULL) && (ptr->getFirstName() != firstname) && (ptr->getLastName() != lastname))
	{
		prev = ptr;
		ptr = ptr->getNext();
	}
	if (ptr == Head)
	{
		Head = ptr->getNext();
		delete ptr;
		return true;
	}
	if (ptr != NULL)
	{
		prev->setNext(ptr->getNext());
		delete ptr;
		return true;
	}
	return false;
}

string Manifest::print() const
{
	string list = "";
	Passenger *ptr = Head;
	while (ptr != NULL)
	{
		list += ptr->print();
		ptr = ptr->getNext();
	}
	return list;
}