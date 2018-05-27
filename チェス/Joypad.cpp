#include "Joypad.h"
#include "DxLib.h"

Joypad::Joypad(){
	x = y = 0;
}

Joypad::~Joypad(){
}

void Joypad::Update()
{

	pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	for (int i = 0; i < 28; i++) {

		if (pad & (1 << i)) {

			Pad[i] ++;

		}
		else {

			Pad[i] = 0;

		}

	}

	if (Pad[UP] >= 1)	y--;
	if (Pad[DOWN] >= 1)	y++;
	if (Pad[RIGHT] >= 1)x++;
	if (Pad[LEFT] >= 1) x--;

}

void Joypad::Draw()
{

	for(int i = 0; i < 28; i++)
	DrawFormatString(10, 10 + 15 * i, GetColor(255, 255, 255), "%d, %d", i, Pad[i]);
	DrawCircle(x, y, 2, GetColor(255, 255, 255), true);

}
