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

	//�Q�[���p�b�h�̍X�V
	Joypad::ins()->Update();
	if (Joypad::ins()->Pad[STOP] == 1)Stop++, Stop %= 2;

	//�ꎞ��~����Ă邩�H
	if (Stop)	StopScene::ins()->Update();
	else//����ĂȂ�������X�V���s��
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