#include "DxLib.h"
#include "SceneMgr.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	DxLib_Init(), ChangeWindowMode(true), SetDrawScreen(DX_SCREEN_BACK);

	SceneMgr scene;

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

		scene.Update();
		scene.Draw();

	}

	DxLib_End();

}