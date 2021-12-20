#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(int size) {
	this->Size = size;
	this->cPos = -1;
	stack = new Card[size];
}

Stack::~Stack() { delete[] stack; };

bool Stack::isFull(void) {
	if (cPos >= Size-1)	return true;
	else					return false;
}

bool Stack::isEmpty(void) {
	if (cPos < 0)	return true;
	else			return false;
}

Card Stack::Pop(void) {
	try {
		if (isEmpty())	throw cPos;			// Stack�� ���������, ����ó��

		return stack[cPos--];
	} catch (int exception) {				// ����ó�� �κ�
		cout << "Stack is Empty!" << endl;
		return Card(0, 0);					// Card(0,0)�� ����ī��
	}
}

void Stack::Push(Card c) {
	try {
		if (isFull())	throw cPos;			// Stack�� ��á����, ����ó��

		stack[++cPos] = c;
	} catch (int exception) {
		cout << "Stack is Full!" << endl;
	}
}

int Stack::GetSize(void) {
	return Size;
}

Card Stack::Show(void) {
	return stack[cPos];
}

Card Stack::GetCardInfo(int idx) {
	return stack[idx];
}

void Stack::SetCardInfo(int idx, Card c) {
	stack[idx] = c;
}