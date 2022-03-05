#pragma once

#include <iostream>
#include "stdafx.h"
#include <string>
using namespace std;


class Material {
private:
	int id;
	string name;
	string description;
	int date;
	int quantity;
	string history;

public:
	Material(int id, string name, string description, int date, int quantity) {
		this->id = id;
		this->name = name;
		this->description = description;
		this->date = date;
		this->quantity = quantity;
	}

	Material(const Material& Source) {
		this->id = Source.GetId();
		this->name = Source.GetName();
		this->description = Source.GetDescription();
		this->date = Source.GetDate();
		this->quantity = Source.GetQuantity();
	}

	virtual void print_MatInfo() {
		cout << "\nID materialu: " << GetId() << endl;
		cout << "Nazev materialu: " << GetName() << endl;
		cout << "Popis materialu: " << GetDescription() << endl;
		cout << "Datum naskladneni: " << GetDate() << endl;
		cout << "Pocet kusu: " << GetQuantity() << endl;
	}

	void print_ShortInfo() {
		cout << "Material " << GetName() << " s poctem kusu - " << GetQuantity() << endl;
	}

	// history - historie pro jeden objekt, all_history - historie pro vsechny upravy
	void AddMatHistory(int id, string name, int quantity, int date, string &all_history) {
		history += "\nMaterial byl naskladnen. ID - " + to_string(id) + ", nazev - " + name + ", pocet kusu - " + to_string(quantity) + ", datum - " + to_string(date);
		all_history += "\nMaterial byl naskladnen. ID - " + to_string(id) + ", nazev - " + name + ", pocet kusu - " + to_string(quantity) + ", datum - " + to_string(date);
	}

	void RemMatHistory(int id, string name, int quantity, string &all_history) {
		history += "\nZe skladu bylo vyskladneno " + to_string(quantity) + " kusu materialu s ID " + to_string(id) + " a nazvem " + name + ".";
		all_history += "\nZe skladu bylo vyskladneno " + to_string(quantity) + " kusu materialu s ID " + to_string(id) + " a nazvem " + name + ".";
	}

	void print_MatHistroy() {
		cout << history << endl;
	}

	bool RemovalMaterial(int id, string name, int quantity, string &all_history) {
		if (quantity > GetQuantity()) {
			cout << "Zadal/a jste vic kusu nez je ve skladu!";
			return false;
		}
		else if (quantity < GetQuantity()) {
			this->quantity -= quantity;
			RemMatHistory(id, name, quantity, all_history);
			cout << "Uvedeny pocet kusu byl vyskladnen." << endl;
			return false;
		}
		else if (quantity == GetQuantity()) {
			RemMatHistory(id, name, quantity, all_history);
			return true;
		}
		else return false;
	}


	int GetId() const {
		return id;
	}

	string GetName() const {
		return name;
	}

	string GetDescription() const {
		return description;
	}

	int GetDate() const {
		return date;
	}

	int GetQuantity() const {
		return quantity;
	}
};