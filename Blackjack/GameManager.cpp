#include "GameManager.h"
#include <iostream>

using namespace std;

void GameManager::GameStart(Table* t) {
	t->dealer->InitforNewGame();
	t->p1->InitforNewGame();
	t->deck->Shuffle();

	while(!GetBetting(t->p1));
	DealCards(t);
	// ���� �ʿ��մϴ�
}

bool GameManager::GetBetting(Player* p1) {
	long long bMoney;
	cout << "��������: " << p1->GetMoneyInfo() << endl;

	cout << "���ñݾ�: ";
	cin >> bMoney;
	bMoney = p1->Betting(bMoney);

	if (bMoney < 0) {
		cout << "�������� ����" << endl << endl;
		return false;
	}
	else if (bMoney == 0) {
		cout << "���ñݾ��� 0������ Ŀ���մϴ�." << endl << endl;
		return false;
	}
	else {
		return true;
	}
}

void GameManager::DealCards(Table* t) {
	t->p1->GetCard(t->deck);
	
	cout << "My Card:";
	t->p1->ShowCard(t->p1->GetCardCount());
	cout << endl;

	t->dealer->GetCard(t->deck);
	
	cout << "Dealer Card:";
	t->dealer->ShowCard(1);
	cout << endl;
}