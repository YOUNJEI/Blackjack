/* Blackjack ver 0.2 */
// Aī�� (1 or 11) ���� ���� ���� �Ϸ�

// To do -> ���ӹݺ�, money, �·� ���� �ʿ�

/* ����������Ʈ 2021.12.29 */

#include <iostream>
#include "GameManager.h"

using namespace std;

int main(void) {
	Deck d;
	Player dealer, p1;
	Table t1(&d, &dealer, &p1);
	GameManager Handle;

	cout << "Blackjack ver 0.1" << endl;
	
	Handle.GameStart(&t1);
		
	return 0;
}