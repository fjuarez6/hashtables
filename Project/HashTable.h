#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
using namespace std;

// CONSTANTS: CAPACITY, STEP_SIZE

/*
	An empty index should be marked -1.
	An index that was occupied and then deleted should be marked -2.
	All the indices in the table should be initially seto to -1.
*/

class HashTable
{
	// Overloaded insertion operator (friend function)
	friend ostream& operator<<(ostream& out, const HashTable& other);

public:
	// Default constructor => O(n)
	HashTable();
	// Overloaded constructor for different capacity => O(n)
	HashTable(int capacity);

	// Function getNumOfElements => O(1)
	int getNumOfElements() const;
	// Function getCapacity => O(1)
	int getCapacity() const;

	// Function insert => O(1)
	void insert(int num);
	// Function delete => O(1)
	void deleteNum(int num);

	// Function search => O(1)
	bool search(int num) const;

	// Function rehash => O(n)
	void rehash();

	// Overloaded subscript [ ] operator => O(1)
	int operator[](int indx) const;

	// Function emptyTable
	void emptyTable();

	// The Big Three: 
		// overloaded assignment operator => O(n)
	HashTable& operator=(const HashTable other);
		// copy constructor => O(n)
	HashTable(const HashTable& other);
		// destructor => O(1)
	~HashTable();
	
private:
	
	// Function hashValue that passes j => O(1)
	int hashValue(int j) const;
	
	int *table;				//pointer to the hash table
    int numOfElements;		//number of items in the hash table
    int capacity;			//maximum length of the hash table	
};

#endif
