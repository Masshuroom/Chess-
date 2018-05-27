#pragma once
#include "Chess.h"
#include "DxLib.h"
#include "Button.h"

class Stage
{

	Stage();

	//一回目、二回目にクリックした座標
	int BeenClick, ClickNum;

	//ターン変更ボタン
	Button *turn;

	int Iro1 = GetColor(255,0,0);
	int Iro2 = GetColor(125,125,0);
	int Iro3 = GetColor(0,255,0);
	int Iro4 = GetColor(0,125,125);
	int Iro5 = GetColor(0,0,255);
	int Iro6 = GetColor(125,0,125);

	int _Iro1 = GetColor(2, 0, 0);
	int _Iro2 = GetColor(125, 125, 0);
	int _Iro3 = GetColor(0, 255, 0);
	int _Iro4 = GetColor(0, 125, 125);
	int _Iro5 = GetColor(0, 0, 255);
	int _Iro6 = GetColor(125, 0, 125);

public:
	//一コマ分の大きさ
	int Cell = 40;
	//チェス盤の座標位置
	int x = 100;
	int y = 100;
	//勝ちフラグ、負けフラグ
	int WinFlg = 0;
	int LoseFlg = 0;

public:
	~Stage();

	static Stage* ins() {

		static Stage ins;
		return &ins;

	}

	void Update(int* roll);
	void Draw();

	//駒をセットする
	void SetFrame(Roll roll, Frame frame, int x, int y);

	//駒をゲットする
	Frame GetFrame(Roll roll, int x, int y);
	
	//駒を消去する
	void DeleteFrame(int x, int y);

	//役割をセットする
	void SetRoll(Roll roll);

};

