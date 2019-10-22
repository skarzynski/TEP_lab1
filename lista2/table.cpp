#include "pch.h"
#include <iostream>
#include "table.h"
#include <string>

using namespace std;

Table::Table() {
	this->name = "default_name";
	this->tableLength = 10;

	cout << "bezp: " << this->name << endl;

	this->table = new int[this->tableLength];
}

Table::Table(string name, int tableLength) {
	if (name == "" || tableLength < 1) {
		cout << "niepoprawne parametry" << endl;
		return;
	}
	this->name = name;
	this->tableLength = tableLength;
	
	cout << "parametr: " << this->name << endl;

	this->table = new int[this->tableLength];
}

Table::Table(Table &otherTable) {
	if (&otherTable == nullptr) {
		cout << "niepoprawne parametry" << endl;
		return;
	}
	this->name = otherTable.name + "_copy";
	this->tableLength = otherTable.tableLength;
	this->table = new int[this->tableLength];

	for (int i = 0; i < this->tableLength; i++) {
		this->table[i] = otherTable.table[i];
	}

	cout << "kopiuj: " << this->name << endl;
}

Table::~Table() {
	delete[] this->table;

	cout << "usuwam: " << this->name << endl;
}

void Table::setName(string name) {
	this->name = name;
}

bool Table::setNewSize(int tableLength) {
	int iterationLength = this->tableLength;
	if (tableLength < 1) {
		cout << "niepoprawne parametry" << endl;
		return false;
	}
	else if (tableLength < this->tableLength) {
		string warning = "Wpisana dlugosc tablicy jest mniejsza niz aktualna, istnieje ryzyko utraty danych z tablicy, czy chcesz kontynuowac?(tak/nie) ";
		string answer;

		do {
			cout << warning;
			cin >> answer;
		} while (answer.compare("tak") != 0 && answer.compare("nie") != 0);

		if (answer.compare("nie") == 0) {
			return false;
		}

		iterationLength = tableLength;
	}

	int* new_table = new int[tableLength];

	for (int i = 0; i < iterationLength; i++) {
		new_table[i] = this->table[i];
	}

	delete[] this->table;
	this->table = new_table;
	this->tableLength = tableLength;

	return true;
}

Table* Table::cloneTable() {
	return new Table(*this);
}

void Table::showTable() {
	cout << endl << "name: " << this->name << endl;
	cout << "length: " << this->tableLength << endl;
	for (int i = 0; i < this->tableLength; i++) {
		cout << this->table[i] << " ";
	}
	cout << endl;
}