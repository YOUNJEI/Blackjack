/* Blackjack ver 0.3.2 */
// Blackjack (21) �¸� ���� ����
// Future -> ������ (�÷��̾� �̸�, ��, �·� ��)
// Future2 -> GUI ����
/* ����������Ʈ 2022.01.02 */

#include <iostream>
#include <Windows.h>
#include "GameManager.h"

using namespace std;

int main(void) {
	Deck d;
	Player dealer, p1;
	Table t1(&d, &dealer, &p1);
	GameManager Handle;
	char c;

	cout << "Blackjack ver 0.3.2" << endl;
	
	do {
		// ���� ����
		Handle.GameStart(&t1);

		// ���� ���� ��
		Sleep(2000);
		cout << endl;
		cout << "��������: " << p1.GetMoneyInfo() << endl;
		cout << "�¸�: " << p1.GetwinCount() << "\t" << "�й�: " << p1.GetlossCount() << endl;
		cout << "�·�: ";
		if (p1.GetwinCount() + p1.GetlossCount() != 0)
			cout << ((double)p1.GetwinCount() / (p1.GetwinCount() + p1.GetlossCount())) * 100 << "%" << endl << endl;
		else
			cout << "0.00%" << endl << endl;

		cout << "****�������� �����Ͻðڽ��ϱ�?****" << endl;
		cout << "������: 1" << endl;
		cout << "��������: 2" << endl;
		cin >> c;
		cout << endl;
	} while (c!='2');

	return 0;
}