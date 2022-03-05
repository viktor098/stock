#pragma once

#include "Material.h"
#include <iostream>
#include "stdafx.h"
#include <string>
using namespace std;


class IronCover : public Material {
private:
	int radius;
	int height;

public:
	IronCover(int id, string name, string description, int radius, int height, int date, int quantity) : Material(id, name, description, date, quantity) {
		this->radius = radius;
		this->height = height;
	}

	IronCover(const IronCover& Source) : Material(Source) {
		this->radius = Source.GetRadius();
		this->height = Source.GetHeight();
	}

	void print_MatInfo() {
		cout << "\nID materialu: " << GetId() << endl;
		cout << "Nazev materialu: " << GetName() << endl;
		cout << "Popis materialu: " << GetDescription() << endl;
		cout << "Polomer vika: " << GetRadius() << endl;
		cout << "Vyska vika: " << GetHeight() << endl;
		cout << "Datum naskladneni: " << GetDate() << endl;
		cout << "Pocet kusu: " << GetQuantity() << endl;
	}

	int GetRadius() const {
		return radius;
	}

	int GetHeight() const {
		return height;
	}

};