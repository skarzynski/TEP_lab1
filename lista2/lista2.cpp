// lista2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "table.h"
#include "procedures.h"

#include <iostream>

using namespace std;

int main() {
	Table t1;
	Table t2("test_param", 7, "P@s0");
	Table t3(t2);
	
	t1.showTable();
	t2.showTable();
	t3.showTable();

	t1.setName("new_name");
	t1.showTable();

	t2.setNewSize(5);
	t2.showTable();
	t3.showTable();
	t2.setNewSize(9);
	t2.showTable();

	Table* new_cloned_tab;
	new_cloned_tab = t2.cloneTable();

	(*new_cloned_tab).showTable();

	modifyTable(t1, 20);
	t1.showTable();
	modifyTable(&t1, 20);
	t1.showTable();

	t1.setPassword("password");
	t1.setPassword("P@ssw0rd");
	t1.changePassword("P@ssw0rdo");
	t1.changePassword("P@sww0rdo");
	

	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
