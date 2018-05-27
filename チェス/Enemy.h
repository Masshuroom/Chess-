#pragma once
#include "Chess.h"

class Enemy
{

	Enemy();

public:
	~Enemy();

	static Enemy* ins() {

		static Enemy ins;
		return &ins;

	}

	int Ranx, Rany;
	int Onx, Ony;
	Frame NowFrame;
	int Ablex, Abley;
	int AbleFrame[8][8] = { 0 };//�������͈́i�����̍��W���܂ށj
	int IsFrame[8][8] = { 0 };//�����̋���邩�ǂ���
	int IsEFrame[8][8] = { 0 };//�G�̋���邩�ǂ���

	void Update();
	void Draw();
	void Initialize();

};

