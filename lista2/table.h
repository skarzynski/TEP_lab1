#pragma once
#include <iostream>

using namespace std;

class Table {

private:

	string name;			//nazwa tablicy
	int tableLength;		//d³ugoœæ tablicy
	int* table;				//wskaŸnik na tablicê

public:

	Table();				//konstruktor bezparametrowy z domyœlnymi wartoœciami
	Table(string name, int tableLength);  //konstruktor z parametrami
	Table(Table &otherTable);			//konstruktor kopiuj¹cy

	~Table();				//destruktor

	string getName();					//metoda zwraca nazwê tablicy
	void setName(string name);			//metoda zmienia nazwê tablicy
	int getSize();						//metoda zwraca d³ugoœæ tablicy
	bool setNewSize(int newSize);		//metoda zmienia d³ugoœæ tablicy
	int* getTable();					//metoda zwraca tablicê
	void setTable(int* newTable);		//metoda ustawia now¹ tablicê
	Table* cloneTable();				//metoda klonuj¹ca obiekt (Zbêdna. Powiela funkcjonalnoœæ konstruktora kopiuj¹cego)
	void setSize(int newSize);			//metoda zmienia parametr tableLength
	
	void showTable();					//metoda wyœwietlaj¹ca nazwê, d³ugoœæ i zawartoœæ tablicy

};