#pragma once

#include "Material.h"
#include <iostream>
#include "stdafx.h"
#include <string>
using namespace std;


class PlasticWrap : public Material {
private:
	string color;
	float weight;

public:
	PlasticWrap(int id, string name, string description, string color, float weight, int date, int quantity) : Material(id, name, description, date, quantity) {
		this->color = color;
		this->weight = weight;
	}

	PlasticWrap(const PlasticWrap& Source) : Material(Source) {
		this->color = Source.GetColor();
		this->weight = Source.GetWeight();
	}

	void print_MatInfo() {
		cout << "\nID materialu: " << GetId() << endl;
		cout << "Nazev materialu: " << GetName() << endl;
		cout << "Popis materialu: " << GetDescription() << endl;
		cout << "Barva obalu: " << GetColor() << endl;
		cout << "Vaha obalu: " << GetWeight() << endl;
		cout << "Datum naskladneni: " << GetDate() << endl;
		cout << "Pocet kusu: " << GetQuantity() << endl;
	}

	string GetColor() const {
		return color;
	}

	float GetWeight() const {
		return weight;
	}
};
