#pragma once
#include <iostream>

using namespace std;

class Table {

private:

	string name;
	int tableLength;
	int* table;

public:

	Table();
	Table(string name, int tableLength);
	Table(Table &otherTable);

	~Table();

	void setName(string name);
	bool setNewSize(int tableLength);
	Table* cloneTable();

	void showTable();

};