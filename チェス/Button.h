#pragma once

class Button
{

	int x1, x2, y1, y2;
	int Color;

public:

	int OnMouse;
	int OnClick;
	int BeenOnMouse;
	int BeenOnClick;

	Button(int x1, int x2, int y1, int y2);
	~Button();

	void Update();
	void Draw();

};

