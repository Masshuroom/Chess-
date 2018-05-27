#pragma once
#include "Button.h"

typedef enum {

	player,
	enemy,

}Roll;

typedef enum {

	//à»â∫ÇÕé©êwãÓ
	King,
	Queen,
	Bishop,
	Nkight,
	Luke,
	Pawn,

	//à»â∫ÇÕìG
	_King,
	_Queen,
	_Bishop,
	_Nkight,
	_Luke,
	_Pawn,

	Able,
	None,

}Frame;

class Chess
{

	Chess();

	int roll;

	Button* finish;

public:
	~Chess();

	int ChessStage[8][8] = { None };

	static Chess *ins() {

		static Chess ins;
		return &ins;

	}

	void Update();
	void Draw();

};

