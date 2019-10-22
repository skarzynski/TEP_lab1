#pragma once
#include <iostream>

using namespace std;

class Table {

private:

	string name;			//nazwa tablicy
	int tableLength;		//d�ugo�� tablicy
	int* table;				//wska�nik na tablic�

public:

	Table();				//konstruktor bezparametrowy z domy�lnymi warto�ciami
	Table(string name, int tableLength);  //konstruktor z parametrami
	Table(Table &otherTable);			//konstruktor kopiuj�cy

	~Table();				//destruktor

	string getName();					//metoda zwraca nazw� tablicy
	void setName(string name);			//metoda zmienia nazw� tablicy
	int getSize();						//metoda zwraca d�ugo�� tablicy
	bool setNewSize(int newSize);		//metoda zmienia d�ugo�� tablicy
	int* getTable();					//metoda zwraca tablic�
	void setTable(int* newTable);		//metoda ustawia now� tablic�
	Table* cloneTable();				//metoda klonuj�ca obiekt (Zb�dna. Powiela funkcjonalno�� konstruktora kopiuj�cego)
	void setSize(int newSize);			//metoda zmienia parametr tableLength
	
	void showTable();					//metoda wy�wietlaj�ca nazw�, d�ugo�� i zawarto�� tablicy

};