#include "pch.h"
#include "table.h"
#include "procedures.h"

#include <iostream>
#include <string>

using namespace std;

void modifyTable(Table* table, int newSize) {
	int iterationLength = table->getSize();
	if (newSize < 1) {
		cout << "niepoprawne parametry" << endl;
		return;
	}
	else if (newSize < table->getSize()) {
		string warning = "Wpisana dlugosc tablicy jest mniejsza niz aktualna, istnieje ryzyko utraty danych z tablicy, czy chcesz kontynuowac?(tak/nie) ";
		string answer;

		do {
			cout << warning;
			cin >> answer;
		} while (answer.compare("tak") != 0 && answer.compare("nie") != 0);

		if (answer.compare("nie") == 0) {
			return;
		}

		iterationLength = newSize;
	}

	int* new_table = new int[newSize];

	for (int i = 0; i < iterationLength; i++) {
		new_table[i] = table->getTable()[i];
	}

	table->setTable(new_table);
	table->setSize(newSize);
}

void modifyTable(Table table, int newSize) {
	int iterationLength = table.getSize();
	if (newSize < 1) {
		cout << "niepoprawne parametry" << endl;
		return;
	}
	else if (newSize < table.getSize()) {
		string warning = "Wpisana dlugosc tablicy jest mniejsza niz aktualna, istnieje ryzyko utraty danych z tablicy, czy chcesz kontynuowac?(tak/nie) ";
		string answer;

		do {
			cout << warning;
			cin >> answer;
		} while (answer.compare("tak") != 0 && answer.compare("nie") != 0);

		if (answer.compare("nie") == 0) {
			return;
		}

		iterationLength = newSize;
	}

	int* new_table = new int[newSize];

	for (int i = 0; i < iterationLength; i++) {
		new_table[i] = table.getTable()[i];
	}

	table.setTable(new_table);
	table.setSize(newSize);
}