#include "HashTable.h"

// Overloaded insertion operator (friend function)
ostream& operator<<(ostream& out, const HashTable& other)
{

}

// Default constructor => O(n)
HashTable::HashTable()
{

}

// Overloaded constructor for different capacity => O(n)
HashTable::HashTable(int capacity)
{

}

// Function getNumOfElements => O(1)
int HashTable::getNumOfElements() const
{

}

// Function getCapacity => O(1)
int HashTable::getCapacity() const
{

}

// Function insert => O(1)
void HashTable::insert(int num)
{

}

// Function delete => O(1)
void HashTable::deleteNum(int num)
{

}

// Function search => O(1)
bool HashTable::search(int num) const
{

}

// Function rehash => O(n)
void HashTable::rehash()
{

}

// Overloaded subscript [ ] operator => O(1)
int HashTable::operator[](int indx) const
{

}

// Function emptyTable
void HashTable::emptyTable()
{

}

// The Big Three: 
// overloaded assignment operator => O(n)
HashTable& HashTable::operator=(const HashTable other)
{

}

// copy constructor => O(n)
HashTable::HashTable(const HashTable& other)
{

}

// destructor => O(1)
HashTable::~HashTable()
{

}

int HashTable::hashValue(int j) const
{

}