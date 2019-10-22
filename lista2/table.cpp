﻿#include "pch.h"
#include "table.h"

#include <string>
#include <iostream>

using namespace std;

/*-----------------------------
Konstruktory i desktruktor
-----------------------------*/

Table::Table() {
	this->name = "default_name";
	this->tableLength = 10;
	this->password = "P@ssw0rd";

	cout << "bezp: " << this->name << endl;

	this->table = new int[this->tableLength];
}

Table::Table(string name, int tableLength, string password) {
	if (name == "" || tableLength < 1 || tableLength > 1000) {
		cout << "niepoprawne parametry" << endl;
		return;
	}
	else if (!checkPassword(password)) {
		cout << "haslo nie spelnia wymagan" << endl;
	}
	this->name = name;
	this->tableLength = tableLength;
	this->password = password;

	cout << "parametr: " << this->name << endl;

	this->table = new int[this->tableLength];
}

Table::Table(Table &otherTable) {
	if (&otherTable == nullptr) {
		cout << "niepoprawne parametry" << endl;
		return;
	}
	this->name = otherTable.name + "_copy";
	this->password = otherTable.password;
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

/*-----------------------------
Metody
-----------------------------*/

string Table::getName() {
	return this->name;
}

void Table::setName(string newName) {
	if (newName == "") {
		return;
	}
	this->name = newName;
}

void Table::setPassword(string newPassword) {
	//TODO:
}

int Table::getSize() {
	return this->tableLength;
}

bool Table::setNewSize(int newSize) {
	int iterationLength = this->tableLength;
	if (newSize < 1 || newSize > 1000) {
		cout << "niepoprawne parametry" << endl;
		return false;
	}
	else if (newSize < this->tableLength) {
		string warning = "Wpisana dlugosc tablicy jest mniejsza niz aktualna, istnieje ryzyko utraty danych z tablicy, czy chcesz kontynuowac?(tak/nie) ";
		string answer;

		do {
			cout << warning;
			cin >> answer;
		} while (answer != "tak" && answer != "nie");

		if (answer == "nie") {
			return false;
		}

		iterationLength = newSize;
	}

	int* new_table = new int[newSize];

	for (int i = 0; i < iterationLength; i++) {
		new_table[i] = this->table[i];
	}

	delete[] this->table;
	this->table = new_table;
	this->tableLength = newSize;

	return true;
}

int* Table::getTable() {
	return this->table;
}

void Table::setTable(int* newTable) {
	if (newTable == nullptr) {
		cout << "niepoprawne parametry" << endl;
		return;
	}
	delete[] this->table;
	this->table = newTable;
}

Table* Table::cloneTable() {
	return new Table(*this);
}

void Table::setSize(int newSize) {
	if (newSize < 1 || newSize > 1000) {
		cout << "niepoprawne parametry" << endl;
		return;
	}
	this->tableLength = newSize;
}

void Table::showTable() {
	cout << endl << "name: " << this->name << endl;
	cout << "length: " << this->tableLength << endl;
	for (int i = 0; i < this->tableLength; i++) {
		cout << this->table[i] << " ";
	}
	cout << endl;
}

bool Table::checkPassword(string password) {
	int score = 0; //jeśli hasło jest poprawene score == 5
	bool isNumber = false;
	bool isUpper = false;
	bool isLower = false;
	bool isSpecial = false;

	if (password.length() >= 5) {
		score++;
	}

	for (int i = 0; i < password.length(); i++) {
		if (isdigit(password[i])) {
			isNumber = true;
		}
		else if (islower(password[i])) {
			isLower = true;
		}
		else if (isupper(password[i])) {
			isUpper = true;
		}
		else {
			isSpecial = true;
		}
	}

	if (isNumber) {
		score++;
	}
	if (isUpper) {
		score++;
	}
	if (isLower) {
		score++;
	}
	if (isSpecial) {
		score++;
	}

	if (score == 5) {
		return true;
	}
	return false;
}

bool Table::checkNewPassword(string oldPassword, string newPassword) {
	return false;
}