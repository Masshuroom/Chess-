#include "Menu.h"
#include "DxLib.h"
#include "Joypad.h"
#include "StopScene.h"
#include "Joypad.h"
#include "Cursor.h"
#include "Mouse.h"
#include "Scene.h"

Menu::Menu(){

	x = y = 0;

}

Menu::~Menu(){
}

void Menu::Update()
{

	//ゲームパッドの更新
	Joypad::ins()->Update();
	if (Joypad::ins()->Pad[STOP] == 1)Stop++, Stop %= 2;

	//一時停止されてるか？
	if (Stop)	StopScene::ins()->Update();
	else//されてなかったら更新を行う
	{

		GameButton->Update();
		ConfigButton->Update();

		if (GameButton->OnClick)Scene::ins()->ChangeScene(eScene_Game);
		if (ConfigButton->OnClick)Scene::ins()->ChangeScene(eScene_Config);

	}

}

void Menu::Draw()
{

	if (Stop)	StopScene::ins()->Draw();
	else {

		Joypad::ins()->Draw();
		Mouse::ins()->Draw();
		GameButton->Draw();
		ConfigButton->Draw();

	}

}