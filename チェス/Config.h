#pragma once

#include "BaseScene.h"
#include "Button.h"

class Config : public BaseScene
{

	int mbutton_x1 = 100;
	int mbutton_x2 = 150;
	int mbutton_y1 = 300;
	int mbutton_y2 = 350;

	Button* MenuButton = new Button(mbutton_x1, mbutton_x2, mbutton_y1, mbutton_y2);

public:
	Config();
	~Config();

	void Update();
	void Draw();

};

