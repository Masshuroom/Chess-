#include "Game.h"
#include "DxLib.h"
#include "Mouse.h"
#include "Scene.h"
#include "StopScene.h"
#include "Joypad.h"
#include "Chess.h"
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

Game::Game(){
}

Game::~Game(){}

void Game::Update()
{

	Joypad::ins()->Update();
	if (Joypad::ins()->Pad[STOP] == 1)	Stop++, Stop %= 2;
	if (Stop)	StopScene::ins()->Update();
	else {
		MenuButton->Update();
		if (MenuButton->OnClick)	Scene::ins()->ChangeScene(eScene_Menu);
		Chess::ins()->Update();
		if (Stage::ins()->LoseFlg || Stage::ins()->WinFlg) {//Ÿ•‰‚ªI‚í‚Á‚½‚ç‰Šú‰»‚·‚é
			Stage::ins()->LoseFlg = Stage::ins()->WinFlg = 0;
			Player::ins()->Initialize();
			Enemy::ins()->Initialize();
		}
	}

}

void Game::Draw()
{

	if (Stop)	StopScene::ins()->Draw();
	else {

		MenuButton->Draw();
		//DrawFormatString(100, 100, GetColor(255, 255, 255), "Game, OnMouse : %d", MenuButton->OnMouse);
	
		Chess::ins()->Draw();

	}

}