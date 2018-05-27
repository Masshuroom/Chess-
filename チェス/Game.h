#pragma once

#include "BaseScene.h"
#include "Button.h"

class Game : public BaseScene
{

	int mbutton_x1 = 500;
	int mbutton_x2 = 550;
	int mbutton_y1 = 300;
	int mbutton_y2 = 350;
	Button *MenuButton = new Button(mbutton_x1, mbutton_x2, mbutton_y1, mbutton_y2);

	int Stop = 0;

public:
	Game();
	~Game();

	void Update();
	void Draw();

};

