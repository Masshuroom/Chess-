#pragma once

class Cursor
{

	Cursor();

public:
	~Cursor();

	static Cursor* ins() {

		static Cursor ins;
		return &ins;

	}

	int Joy_x, Joy_y;

};

