// Skladovy System Andrusyak.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include <string>
#include <fstream>
#include "Material.h"
#include "IronCover.h"
#include "PlasticWrap.h"
using namespace std;


void CheckID(Material** Materials, int num_of_mat, int id) {
	for (int i = 0; i < num_of_mat; i++) {
		if (Materials[i]->GetId() == id) throw "\nID jiz existuje. Zopakujte.";
	}
}

void AddMaterial(Material** Materials, int &num_of_mat, string &all_history) {
	int id;
	int choice;
	string name;
	string description;
	int date;
	int quantity;

	cout << "\nPridani materialu:" << endl;
	cout << "1. Zelezna vika." << endl;
	cout << "2. Plastove obaly." << endl;
	cout << "3. Jiny typ materialu." << endl;
	cout << "4. Zpatky." << endl;
	cout << "Vyberte: ";

	cin >> choice;

	switch (choice) {
		case 1: {
			try {
				int radius;
				int height;
				cout << "Zadejte ID materialu: "; cin >> id;
				CheckID(Materials, num_of_mat, id);
				cout << "Zadejte nazev materialu: "; cin >> name;
				cout << "Zadejte popis materialu: "; cin >> description;
				cout << "Zadejte polomer vika: "; cin >> radius;
				cout << "Zadejte vysku vika: "; cin >> height;
				cout << "Zadejte datum naskladneni ve formatu DDMMRRRR: "; cin >> date;
				cout << "Zadejte pocet kusu: "; cin >> quantity;

				Materials[num_of_mat] = new IronCover(id, name, description, radius, height, date, quantity);
				Materials[num_of_mat]->AddMatHistory(id, name, quantity, date, all_history);
				num_of_mat++;
			}
			catch (const char *err) {
				cout << err << endl;
			}
			break;
		}
		case 2: {
			try {
				string color;
				float weight;
				cout << "Zadejte ID materialu: "; cin >> id;
				CheckID(Materials, num_of_mat, id);
				cout << "Zadejte nazev materialu: "; cin >> name;
				cout << "Zadejte popis materialu: "; cin >> description;
				cout << "Zadejte barvu obalu: "; cin >> color;
				cout << "Zadejte vahu obalu: "; cin >> weight;
				cout << "Zadejte datum naskladneni ve formatu DDMMRRRR: "; cin >> date;
				cout << "Zadejte pocet kusu: "; cin >> quantity;

				Materials[num_of_mat] = new PlasticWrap(id, name, description, color, weight, date, quantity);
				Materials[num_of_mat]->AddMatHistory(id, name, quantity, date, all_history);
				num_of_mat++;
			}
			catch (const char *err) {
				cout << err << endl;
			}
			break;
		}
		case 3: {
			try {
				cout << "Zadejte ID materialu: "; cin >> id;
				CheckID(Materials, num_of_mat, id);
				cout << "Zadejte nazev materialu: "; cin >> name;
				cout << "Zadejte popis materialu: "; cin >> description;
				cout << "Zadejte datum naskladneni ve formatu DDMMRRRR: "; cin >> date;
				cout << "Zadejte pocet kusu: "; cin >> quantity;

				Materials[num_of_mat] = new Material(id, name, description, date, quantity);
				Materials[num_of_mat]->AddMatHistory(id, name, quantity, date, all_history);
				num_of_mat++;
			}
			catch (const char *err) {
				cout << err << endl;
			}
			break;
		}
		case 4:
			break;
		default: 
			cout << "Zadejte spravny vyber!" << endl;
	}
		
}

void SearchMat(Material** Materials, int &num_of_mat) {

	int choice;
	bool mat_found = false;

	cout << "\nPodle ceho chcete najit zbozi?" << endl;
	cout << "1. Podle ID." << endl;
	cout << "2. Podle nazvu." << endl;
	cout << "3. Podle data naskladneni." << endl;
	cout << "4. Zpatky." << endl;
	cout << "Vyberte: "; 
		
	cin >> choice;	

	switch (choice) {
	case 1: {
		int id;
		cout << "Zadejte ID pro vyhledavani: "; cin >> id;
		for (int i = 0; i < num_of_mat; i++) {
			if (Materials[i]->GetId() == id) {
				cout << "\nHledany material: " << endl;
				Materials[i]->print_MatInfo();
				mat_found = true;
			}
		}
		if (!mat_found) cout << "\nMaterial se nenasel.";
		break;
	}
	case 2: {
		string name;
		cout << "Zadejte nazev pro vyhledavani: "; cin >> name;
		for (int i = 0; i < num_of_mat; i++) {
			if (Materials[i]->GetName() == name) {
				cout << "\nHledany material(nebo vice): " << endl;
				Materials[i]->print_MatInfo();
				mat_found = true;
			}
		}
		if (!mat_found) cout << "\nMaterial se nenasel.";
		break;
	}
	case 3: {
		int date;
		cout << "Zadejte datum naskladneni ve formatu DDMMRRRR: "; cin >> date;
		for (int i = 0; i < num_of_mat; i++) {
			if (Materials[i]->GetDate() == date) {
				cout << "\nHledany material(nebo vice): " << endl;
				Materials[i]->print_MatInfo();
				mat_found = true;
			}
		}
		if (!mat_found) cout << "\nMaterial se nenasel.";
		break;
	}
	case 4:
		break;
	default: 
		cout << "\nZadejte spravny vyber!" << endl;
	}

}

void RemovalMat(Material** Materials, int &num_of_mat, string &all_history) {

	int id;
	int quantity;
	cout << "Zadejte ID materialu: "; cin >> id;

	for (int i = 0; i < num_of_mat; i++) {
		if (Materials[i]->GetId() == id) {
			cout << "\nHledany material se jmenuje " << Materials[i]->GetName() << " a ma ve skladu " << Materials[i]->GetQuantity() << " kusu" << endl;
			cout << "Kolik kusu chcete vyskladnit?: "; cin >> quantity;
			if (Materials[i]->RemovalMaterial(Materials[i]->GetId(), Materials[i]->GetName(), quantity, all_history)){
				delete Materials[i];
				num_of_mat--;
				cout << "\nMaterial byl kompletne vyskladnen." << endl;
				for (int j = i; j < num_of_mat; j++) {
					Materials[j] = Materials[j + 1];
				}
			}
		}
	}
}

void printHistory(Material** Materials, int &num_of_mat, string& all_history) {
	int choice;
	bool mat_found = false;

	cout << "\nJakou historii chcete vypsat?" << endl;
	cout << "1. Pro konkretni material." << endl;
	cout << "2. Komletne celou historii." << endl;
	cout << "3. Zpatky." << endl;
	cout << "Vyberte: ";  cin >> choice;
		
	switch (choice) {
	case 1: {
		int id;
		cout << "Zadejte ID pro vyhledavani: "; cin >> id;
		for (int i = 0; i < num_of_mat; i++) {
			if (Materials[i]->GetId() == id) {
				cout << "\nHistorie hledaneho materialu: " << endl;
				Materials[i]->print_MatHistroy();
				mat_found = true;
			}
		}
		if (!mat_found) cout << "\nMaterial se nenasel.";
		break;
	}
	case 2: {
		cout << "\nHistorie naskladneni a vyskaldneni: " << endl;
		cout << all_history;
	}
	case 3:
		break;
	default:
		cout << "\nZadejte spravny vyber!" << endl;
	}
	
}


int main()
{

	Material* Materials[20];
	string all_history;
		
	int choice;
	int num_of_mat = 0;


	/*              Jenom pro zkousku vyhledavani a vypisovani (neni historie)
	Materials[0] = new IronCover(1, "Viko1", "Vika na pouziti", 25, 5, 14122019, 100);
	Materials[1] = new PlasticWrap(2, "Obal45", "Obal na pouziti", "Cerna", 2.5 , 13122019, 25);
	Materials[2] = new Material(3, "Neco jineho", "Srouby pro obaly", 10012020, 1200);
	Materials[3] = new Material(4, "Viko1", "Spatna vika(vyhodit)", 19122019, 20);
	int num_of_mat = 4;  */


	while (true) {
		cout << "\nCo chcete udelat?" << endl;
		cout << "1. Naskladneni zbozi." << endl;
		cout << "2. Vyskladneni zbozi." << endl;
		cout << "3. Vyhledavani zbozi." << endl;
		cout << "4. Vypsat zbozi (nazev a pocet kusu)." << endl;
		cout << "5. Vypsat vse zbozi kompletne." << endl;
		cout << "6. Vypsat historii naskladneni a vyskladneni." << endl;
		cout << "7. Zapsat historii do souboru." << endl;
		cout << "Vyberte: ";  cin >> choice;

		switch (choice) {
			case 1: {
				AddMaterial(Materials, num_of_mat, all_history);
				break;
			}
			case 2: {
				RemovalMat(Materials, num_of_mat, all_history);
				break;
			}
			case 3: {
				SearchMat(Materials, num_of_mat);
				break;
			}
			case 4: {
				for (int i = 0; i < num_of_mat; i++) {
					Materials[i]->print_ShortInfo();
				}
				break;
			}
			case 5: {
				for (int i = 0; i < num_of_mat; i++) {
					Materials[i]->print_MatInfo();
				}
				break;
			}
			case 6: {
				printHistory(Materials, num_of_mat, all_history);
				break;
			}
			case 7: {
				ofstream out("history.txt");
				out << all_history;
				out.close();
				cout << "Historie byla vypsana do HISTORY.TXT" << endl;
				break;
			}
			default:
				cout << "\nZadejte spravny vyber!" << endl;
		}
	}

	return 0;
}