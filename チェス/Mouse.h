#pragma once

class Mouse
{

	Mouse();

	int ImageHandle;

public:
	~Mouse();

	static Mouse* ins() {

		static Mouse ins;
		return &ins;

	}

	void Update();
	void Draw();

	int x, y;
	int Click;
	int LClick;

};

