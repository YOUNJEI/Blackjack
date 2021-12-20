#include "Card.h"
#include <iostream>

using namespace std;

Card::Card() {
	this->cardValue = 0;
	this->cType = Heart;
}
Card::Card(int cV, int cT) {
	this->cardValue = cV;
	this->cType = cT;
}

Card::Card(const Card& origin) {
	this->cardValue = origin.cardValue;
	this->cType = origin.cType;
}

Card::~Card() {};

void Card::SetValue(int v) {
	this->cardValue = v;
}

void Card::SetType(int v) {
	this->cType = v;
}

int Card::GetValue(void) {
	return this->cardValue;
}

int Card::GetType(void) {
	return this->cType;
}

void Card::Print(void) {
	switch (cType) {
	case 1:
		cout << "��Ʈ";
		break;

	case 2:
		cout << "���̾�";
		break;

	case 3:
		cout << "Ŭ�ι�";
		break;

	case 4:
		cout << "�����̵�";
		break;

	default:
		cout << "X";
		break;
	}

	cout << cardValue;
}