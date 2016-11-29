#include "HashTable.h"

// Overloaded insertion operator (friend function)
ostream& operator<<(ostream& out, const HashTable& other)
{
	for (int i = 0; i < other.capacity; ++i)
	{
		if (other.table[i] != -1 && other.table[i] != -2)
			out << "Index " << i << ": " << other.table[i] << endl;
	}
	return out;
}

// Default constructor => O(n)
HashTable::HashTable()
{
	capacity = CAPACITY;
	table = new int[capacity];

	for (int i = 0; i < capacity; ++i)
	{
		table[i] = -1;
	}
}

// Overloaded constructor for different capacity => O(n)
HashTable::HashTable(int newCapacity)
{
	capacity = newCapacity;
	table = new int[capacity];

	for (int i = 0; i < capacity; ++i)
	{
		table[i] = -1;
	}
}

// Function getNumOfElements => O(1)
int HashTable::getNumOfElements() const
{
	return numOfElements;
}

// Function getCapacity => O(1)
int HashTable::getCapacity() const
{
	return capacity;
}

// Function insert => O(1)
void HashTable::insert(int num)
{
	bool emptyIndx = false;
	int j = 0;

	while (!emptyIndx)
	{
		int i = hashValue(num, j);

		if (table[i] == -1 || table[i] == -1)
		{
			emptyIndx = true;
			table[i] = num;
			++numOfElements;
		}
		else
			++j;
	}
}

// Function delete => O(1)
void HashTable::deleteNum(int num)
{
	if (numOfElements == 0)
		cerr << "There are no elements in the hash table.";
	else
	{
		int j = 0;
		int i = hashValue(num, j);

		table[i] = -2;
	}
}

// Function search => O(1)
bool HashTable::search(int num) const
{
	if (numOfElements == 0)
		cerr << "There are no elements in the hash table.";
	else
	{
		bool found = false;
		int j = 0;

		while (!found)
		{
			int i = hashValue(num, j);

			if (table[i] == num)
			{
				found = true;
				return found;
			}
			else
				++j;
		}
	}

	return false;
}

// Function rehash => O(n)
void HashTable::rehash()
{

}

// Overloaded subscript [ ] operator => O(1)
int HashTable::operator[](int indx) const
{
	return table[indx];
}

// Function emptyTable
void HashTable::emptyTable()
{
	delete[] table;
	table = nullptr;
}

// The Big Three: 
// overloaded assignment operator => O(n)
HashTable HashTable::operator=(const HashTable& other)
{
	return other;
}

// copy constructor => O(n)
HashTable::HashTable(const HashTable& other)
{
	capacity = other.capacity;
	table = new int[capacity];

	for (int i = 0; i < other.capacity; ++i)
	{
		table[i] = other.table[i];
	}

	numOfElements = other.numOfElements;
}

// destructor => O(1)
HashTable::~HashTable()
{
	emptyTable();
}

int HashTable::hashValue(int key, int j) const
{
	int squareJ = pow(j, 2);
	return ((key + squareJ) % capacity);
}