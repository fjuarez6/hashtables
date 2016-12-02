#include "HashTable.h"

// Overloaded insertion operator (friend function)
ostream& operator<<(ostream& out, const HashTable& other)
{
	for (int i = 0; i < other.capacity; ++i)
	{
		if (other.table[i] != -1 && other.table[i] != -2)
			out << "Index " << i << ": " << other.table[i] << endl;
		else
			out << "Index " << i << ":" << endl;
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
	bool freeIndx = false;
	int j = 0;

	while (!freeIndx)
	{
		int i = hashValue(num, j);

		if (table[i] == -1 || table[i] == -2)
		{
			freeIndx = true;
			table[i] = num;
			++numOfElements;
		}
		else
			++j;
	}

	int treshhold = capacity * 2 / 3;
	if (numOfElements == treshhold)
		rehash();
}

// Function delete => O(1)
void HashTable::deleteNum(int num)
{
	if (numOfElements == 0)
		cerr << "There are no elements in the hash table.";
	else
	{
		int j = 0;
		bool found = false;

		while (!found)
		{
			int i = hashValue(num, j);

			if (table[i] == num)
			{
				found = true;
				table[i] = -2;
			}
			else
				++j;
		}
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
	int newCapacity = ((capacity * 2) + 1);
	int *newTable = new int[newCapacity];
	int oldCapacity = capacity;
	capacity = newCapacity;


	for (int k = 0; k < newCapacity; ++k)
	{
		newTable[k] = -1;
	}

	for (int i = 0; i < oldCapacity; ++i)
	{
		int num = table[i];

		if (num != -1)
		{
			int j = 0;
			bool freeIndx = false;

			while (!freeIndx)
			{
				int indx = hashValue(num, j);

				if (newTable[indx] == -1)
				{
					freeIndx = true;
					newTable[indx] = num;
				}
				else
					++j;
			}
		}
	}

	delete[] table;

	table = newTable;
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
HashTable& HashTable::operator=(const HashTable& other)
{
	if (this != &other)
	{
		delete[] table;
		table = new int[other.capacity];
		capacity = other.capacity;
		numOfElements = other.numOfElements;

		for (int i = 0; i < capacity; ++i)
		{
			table[i] = other.table[i];
		}
	}
	return *this;
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
	// quadratic proving
	//return ((key + (j * j)) % capacity);

	//doublehash
	return (((key) + j * (7 - (key % 7))) % capacity);

}