#include "Deck.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <time.h>

Deck::Deck() {
	MyDeck = new Stack(BLACKJACKCARDSIZE);
	DeckInit();
}

Deck::~Deck() {
	delete MyDeck;
}

void Deck::DeckInit(void) {
	for (int i = 0; i < 10; i++) {
		MyDeck->Push(Card(i+1, Heart));		// ��Ʈī�� ����
		MyDeck->Push(Card(i+1, Dia));		// ���̾�ī�� ����
		MyDeck->Push(Card(i+1, Club));		// Ŭ�ι�ī�� ����
		MyDeck->Push(Card(i+1, Spade));		// �����̵�ī�� ����
	}
	for (int i = 0; i < 3; i++) {
		MyDeck->Push(Card(10, Heart));		// ��Ʈī�� ����
		MyDeck->Push(Card(10, Dia));		// ���̾�ī�� ����
		MyDeck->Push(Card(10, Club));		// Ŭ�ι�ī�� ����
		MyDeck->Push(Card(10, Spade));		// �����̵�ī�� ����
	}
}

void Deck::Shuffle(void) {
	// index ���� ������ �����Ͽ� Shuffle

	Card temp;
	int x, y;
	srand((unsigned int)time(NULL));

	for (int i = 0; i < SHUFFLECOUNT; i++) {
		x = rand() % BLACKJACKCARDSIZE;
		y = rand() % BLACKJACKCARDSIZE;

		if (x != y) {
			temp = MyDeck->GetCardInfo(x);
			MyDeck->SetCardInfo(x, MyDeck->GetCardInfo(y));
			MyDeck->SetCardInfo(y, temp);
		}
	}
}

Card Deck::Draw(void) {
	Card temp = MyDeck->Pop();
	
	// ī�� ���� ���� ��, ���ο� ī�弼Ʈ ���� �� ����
	if (temp.GetValue() == 0 && temp.GetType() == 0) {
		std::cout << "ī�尡 �����Ǿ����ϴ�!" << std::endl;
		std::cout << "���ο� Ʈ���� ī�� ���!" << std::endl;
		this->DeckInit();
		this->Shuffle();

		temp = MyDeck->Pop();

		return temp;
	}
	return temp;
}