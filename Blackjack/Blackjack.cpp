/* Blackjack ver 0.4.1 */
// �Ļ�� �����ʱ�ȭ ����
// Future -> ����ٿ� ����
// Future2 -> GUI ����
/* ����������Ʈ 2022.01.15 */

#include <iostream>
#include <Windows.h>
#include "GameManager.h"
#include "SaveHelper.h"

using namespace std;

int main(void) {
	Deck d;
	Player dealer, p1;
	Table t1(&d, &dealer, &p1);
	GameManager Handle;
	SaveHelper sH("savedata.txt");
	char c;

	cout << "Blackjack ver 0.4.1" << endl;
	cout << "���嵥���͸� �ҷ��ɴϴ�.." << endl;
	
	if (sH.LoadData(&p1) == false)
		cout << "������ �ҷ����� ����" << endl;
	else {
		cout << "�����͸� �ҷ��Խ��ϴ�." << endl;
		cout << "�¸�: " << p1.GetwinCount() << "\t" << "�й�: " << p1.GetlossCount() << endl;
		cout << "�·�: ";
		if (p1.GetwinCount() + p1.GetlossCount() != 0)
			cout << ((double)p1.GetwinCount() / (p1.GetwinCount() + p1.GetlossCount())) * 100 << "%" << endl << endl;
		else
			cout << "0.00%" << endl << endl;
	}
	
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

	sH.SaveData(&p1);

	return 0;
}