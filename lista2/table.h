#pragma once
#include <iostream>

using namespace std;

const string BAD_PARAMS = "Niepoprawne parametry";
const string WARNING_TAB_LENGTH = "Wpisana dlugosc tablicy jest mniejsza niz aktualna, istnieje ryzyko utraty danych z tablicy, czy chcesz kontynuowac?(tak/nie) ";
const string BAD_PASS_SET = "Haslo nie spelnia wymagan";

class Table {

private:

	string name;			//nazwa tablicy
	string password;		//hasło (min. 5 znaków, 1 mała litera, 1 wielka litera, 1 znak specjalny, 1 cyfra)
	int tableLength;		//długość tablicy
	int* table;				//wskaźnik na tablicę

public:

	Table();				//konstruktor bezparametrowy z domyślnymi wartościami
	Table(string name, int tableLength, string password);  //konstruktor z parametrami
	Table(Table &otherTable);			//konstruktor kopiujący

	~Table();				//destruktor

	string getName();					//metoda zwraca nazwę tablicy
	void setName(string newName);		//metoda zmienia nazwę tablicy
	void setPassword(string newPassword);	//metoda ustawia nowe hasło (musi się różnić o dwa znaki)
	int getSize();						//metoda zwraca długość tablicy
	bool setNewSize(int newSize);		//metoda zmienia długość tablicy
	int* getTable();					//metoda zwraca tablicę
	void setTable(int* newTable);		//metoda ustawia nową tablicę
	Table* cloneTable();				//metoda klonująca obiekt (Zbędna. Powiela funkcjonalność konstruktora kopiującego)
	void setSize(int newSize);			//metoda zmienia parametr tableLength

	void showTable();					//metoda wyœwietlająca nazwę, długość i zawartość tablicy
	bool checkPassword(string password); //sprawdza czy hasło jest poprawne
	bool checkNewPassword(string oldPassword, string newPassword); //sprawdza czy hasło różni się od poprzedniego o dwa znaki

};