#pragma once
#include "DxLib.h"

#define UP 3
#define DOWN 0
#define RIGHT 2
#define LEFT 1
#define MARU 5
#define SANKAKU 4
#define SIKAKU 7
#define BATU 6
#define STOP 13
#define START 12

class Joypad
{

	Joypad();
	int pad;

public:
	~Joypad();

	static Joypad *ins() {

		static Joypad ins;
		return &ins;

	}

	void Update();
	void Draw();

public:

	int Pad[28] = { 0 };

	int x, y;

};

