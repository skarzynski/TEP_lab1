#include "pch.h"
#include "table.h"
#include "procedures.h"

#include <iostream>
#include <string>

using namespace std;

string const WARNING = "Wpisana dlugosc tablicy jest mniejsza niz aktualna, istnieje ryzyko utraty danych z tablicy, czy chcesz kontynuowac?(tak/nie) ";

void modifyTable(Table* table, int newSize) {
	if (table == nullptr || newSize < 1 || newSize > 1000) {
		cout << "niepoprawne parametry" << endl;
		return;
	}
	int iterationLength = table->getSize();
	if (newSize < table->getSize()) {
		string answer;

		do {
			cout << WARNING;
			cin >> answer;
		} while (answer != "tak" && answer != "nie");

		if (answer == "nie") {
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
	if (newSize < 1 || newSize > 1000) {
		cout << "niepoprawne parametry" << endl;
		return;
	}
	int iterationLength = table.getSize();
	if (newSize < table.getSize()) {
		string answer;

		do {
			cout << WARNING;
			cin >> answer;
		} while (answer != "tak" && answer != "nie");

		if (answer == "nie") {
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