#pragma once
#include "Button.h"
#include "Chess.h"

class Player
{

	Player();

public:
	~Player();

	static Player* ins() {

		static Player ins;
		return &ins;

	}

	//駒が置ける座標
	int AbleFrame[8][8] = { 0 };//駒が動ける範囲（味方の座標も含む）
	int IsFrame[8][8] = { 0 };//味方の駒があるかどうか
	int IsEFrame[8][8] = { 0 };//敵の駒があるかどうか

	//駒選択しなおしボタン
	Button *Retryframe;
	int retryx = 10;
	int retryy = 80;

	//駒決定ボタン
	Button *Decision;
	int dec_x = 10;
	int dec_y = 150;

	//一回目にクリックされた座標
	int Click1x, Click1y;
	int ClickNum = 0;
	Frame frame1;//一回目にクリックした駒
	Frame frame2;//二回目にクリックした駒

	//二回目にクリックした座標
	int Click2x, Click2y;

	Button* boad[8][8];

	void Update();
	void Draw();
	void Initialize();

};

