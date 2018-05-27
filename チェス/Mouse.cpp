#include "Mouse.h"
#include "DxLib.h"

Mouse::Mouse(){
	x = y = 0;
	Click = 0;
	ImageHandle = LoadGraph("Mouse.jpg");
}

Mouse::~Mouse(){
}

void Mouse::Update()
{

	GetMousePoint(&x, &y);
	if (GetMouseInput() == MOUSE_INPUT_LEFT)	Click = 1;
	else										Click = 0;
	if (GetMouseInput() == MOUSE_INPUT_RIGHT)	LClick = 1;
	else										LClick = 0;

}

void Mouse::Draw()
{

	DrawRotaGraph(x-3, y-3, 0.05, 0, ImageHandle, true);

}