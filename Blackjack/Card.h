#ifndef __CARD_H__
#define __CARD_H__

/*
Ʈ���� ī�� ����
*/

#define Heart 1
#define Dia 2
#define Club 3
#define Spade 4

class Card
{
private:
	int cardValue;			// ī�� �� 1:A - 10:10JQK
	int cType;

public:
	Card();
	Card(int cV, int cT);
	Card(const Card&);
	~Card();

	void SetValue(int v);
	void SetType(int v);
	int GetValue(void);
	int GetType(void);
	void Print(void);
};

#endif