#include "Button.h"
#include "DxLib.h"
#include "Mouse.h"

Button::Button(int X1, int X2, int Y1, int Y2){

	x1 = X1, x2 = X2, y1 = Y1, y2 = Y2;
	OnMouse = OnClick = BeenOnClick = 0;
	Color = GetColor(255, 255, 255);

}

Button::~Button()
{
}

void Button::Update()
{

	Mouse::ins()->Update();
	//マウスのカーソルがボタン内に入っていたら
	if (Mouse::ins()->x > x1 && Mouse::ins()->x < x2 && Mouse::ins()->y > y1 && Mouse::ins()->y < y2)
			OnMouse = 1;
	else	OnMouse = 0;

	if (OnMouse && Mouse::ins()->Click)	OnClick = Mouse::ins()->Click;
	else								OnClick = 0;

	if (OnClick)	BeenOnClick++;
	else			BeenOnClick = 0;

	if (OnMouse)		BeenOnMouse++;

}

void Button::Draw()
{

	DrawLine(x1, y1, x2, y1, Color);
	DrawLine(x1, y1, x1, y2, Color);
	DrawLine(x2, y2, x2, y1, Color);
	DrawLine(x2, y2, x1, y2, Color);

}
