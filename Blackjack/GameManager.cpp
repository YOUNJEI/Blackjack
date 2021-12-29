#include <iostream>
#include <vector>
#include <Windows.h>
#include "GameManager.h"

using namespace std;

void GameManager::GameStart(Table* t) {
	char c;
	int game_result;

	t->dealer->InitforNewGame();
	t->p1->InitforNewGame();
	t->deck->Shuffle();

	while(!GetBetting(t->p1));			// ����
	cout << endl;
	
	/* ���� �� 2�� */
	for(int i=0; i<2; i++)	DealCards(t);

	cout << "My Card:";
	t->p1->ShowCard(t->p1->GetCardCount());
	cout << endl;

	cout << "Dealer Card:";
	t->dealer->ShowCard(1);
	cout << endl;

	do {
		c = InputAction(t);

		switch (c) {
		case 's':
		case 'S':
			game_result = OpenCard(t);
			break;

		case 'h':
		case 'H':
			game_result = Hit(t);
			break;
		}
	} while (game_result == 2);

	switch (game_result) {
	case 1:					// �÷��̾� �¸�
		cout << "������ �ݾ�: " << t->p1->GetBetMoneyInfo() << endl;
		cout << t->p1->GetBetMoneyInfo()*2 << "ȹ��!" << endl;
		t->p1->AddMoney(t->p1->GetBetMoneyInfo() * 2);
		t->p1->AddwinCount();
		break;

	case 0:
		cout << "���º�!" << endl;
		cout << "������ �ݾ�: " << t->p1->GetBetMoneyInfo() << endl;
		t->p1->AddMoney(t->p1->GetBetMoneyInfo());
		break;

	case -1:
		cout << "������ �ݾ�: " << t->p1->GetBetMoneyInfo() << endl;
		cout << t->p1->GetBetMoneyInfo() << "����!" << endl;
		t->p1->AddlossCount();
		break;
	}
}

bool GameManager::GetBetting(Player* p1) {
	long long bMoney;
	cout << "��������: " << p1->GetMoneyInfo() << endl;
	cout << "���ñݾ�: ";
	cin >> bMoney;
	
	// cin �Է¿����� ���� ���ѷ��� �����ڵ�
	if (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		bMoney = 0;
	}

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
	t->dealer->GetCard(t->deck);
}

char GameManager::InputAction(Table* t) {
	char c;

	while (true) {
		cout << "S:Stand | H:Hit" << endl;
		cin >> c;

		switch (c) {
		case 's':
		case 'S':
		case 'h':
		case 'H':
			return c;

		default:
			break;
		}
	}
}

int GameManager::OpenCard(Table* t) {
	/* player �¸� �� 1 ����  */
	/* ���º� 0 ����		  */	
	/* dealer �¸� �� -1 ���� */
	cout << endl;
	cout << "********Card Open********" << endl;	Sleep(2000);
	cout << "Your Card: ";	t->p1->ShowCard(t->p1->GetCardCount()); cout << endl;
	cout << "Your Score: " << t->p1->GetScore() << endl	<<	endl;	Sleep(2000);

	if (t->dealer->GetScore() < 17) {
		cout << "Dealer:" << t->dealer->GetScore() << " ("; t->dealer->ShowCard(t->dealer->GetCardCount());	cout << ")" << endl;	Sleep(2000);
		while (t->dealer->GetScore() < 17) {
			cout << "Dealer New Card!" << endl;	Sleep(2000);
			if (t->dealer->GetCard(t->deck)) {
				cout << "Dealer Card: ";	t->dealer->ShowCard(t->dealer->GetCardCount());	cout << endl << endl;	Sleep(2000);
				cout << "Dealer bust!!" << endl;
				return 1;
			}
			else
			{
				cout << t->dealer->GetScore() << endl;
			}
		}
	}
	
	Sleep(2000);
	cout << "Dealer Card: ";	t->dealer->ShowCard(t->dealer->GetCardCount());	cout << endl;
	cout << "Dealer Score: " << t->dealer->GetScore() << endl << endl;
	Sleep(2000);

	if (t->p1->GetScore() > t->dealer->GetScore()) {
		cout << "You Win!!" << endl;
		return 1;
	}
	else if (t->p1->GetScore() == t->dealer->GetScore()) {
		if (t->p1->GetCardCount() > t->dealer->GetCardCount()) {
			cout << "You Win!!" << endl;
			return 1;
		}
		else if (t->p1->GetCardCount() == t->dealer->GetCardCount()) {
			cout << "Draw!!" << endl;
			return 0;
		}
		else {
			cout << "Dealer Win!!" << endl;
			return -1;
		}
	}
	else {
		cout << "Dealer Win!!" << endl;
		return -1;
	}
}

int GameManager::Hit(Table* t) {
	/* HIT									*/
	/* OVER 21 (BUST) return -1				*/
	/* If score is 21, return OpenCard		*/
	/* else return 2 (nothing, keep going)	*/

	t->p1->GetCard(t->deck);
	
	cout << endl;
	cout << t->p1->GetScore() << endl;

	if (t->p1->GetScore() > 21) {
		cout << "You Bust!!" << endl;
		return -1;
	}
	else if (t->p1->GetScore() == 21) return OpenCard(t);
	else return 2;
}