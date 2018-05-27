#pragma once

#include "BaseScene.h"
#include "Button.h"

class Menu : public BaseScene
{

	int Stop = 0;

	//カーソルの座標
	int x, y;

	int button_reach = 10;

	//ボタン
	int Gbutton_x1 = 100;
	int Gbutton_x2 = 150;
	int Gbutton_y1 = 100;
	int Gbutton_y2 = 150;
	Button *GameButton = new Button(Gbutton_x1, Gbutton_x2, Gbutton_y1, Gbutton_y2);

	int Cbutton_x1 = 200;
	int Cbutton_x2 = 250;
	int Cbutton_y1 = 100;
	int Cbutton_y2 = 150;
	Button *ConfigButton = new Button(Cbutton_x1, Cbutton_x2, Cbutton_y1, Cbutton_y2);

public:
	Menu();
	~Menu();

	void Update();
	void Draw();

};

