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
	int AbleFrame[8][8] = { 0 };//駒が動ける範囲（味方の座標も含む）
	int IsFrame[8][8] = { 0 };//味方の駒があるかどうか
	int IsEFrame[8][8] = { 0 };//敵の駒があるかどうか

	void Update();
	void Draw();
	void Initialize();

};

