#include "Card.h"
#include <iostream>

using namespace std;

// Card Ŭ���� �⺻ ������ (Default: 0 | Heart)
Card::Card() {
	this->cardValue = 0;
	this->cType = Heart;
}

// Card Ŭ���� ������ (������� �ʱ�ȭ)
Card::Card(int cV, int cT) {
	this->cardValue = cV;
	this->cType = cT;
}

// Card Ŭ���� ���� ������
Card::Card(const Card& origin) {
	this->cardValue = origin.cardValue;
	this->cType = origin.cType;
}

// Card Ŭ���� �Ҹ���
Card::~Card() {};

// ������� cardValue Set �Լ�
void Card::SetValue(int v) {
	this->cardValue = v;
}

// ������� cType Set �Լ�
void Card::SetType(int v) {
	this->cType = v;
}

// ������� cardValue Get �Լ�
int Card::GetValue(void) {
	return this->cardValue;
}

// ������� cType Get �Լ�
int Card::GetType(void) {
	return this->cType;
}

// Card ��� �Լ� (format eg) "��Ʈ1"
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