#include "Chess.h"
#include "DxLib.h"
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"

Chess::Chess() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			ChessStage[i][j] = None;
}

Chess::~Chess(){
}

void Chess::Update()
{
	if (Stage::ins()->LoseFlg != 1 || Stage::ins()->WinFlg != 1) {
		Stage::ins()->Update(&roll);
		if (roll == player)	Player::ins()->Update();
		if (roll == enemy)	Enemy::ins()->Update();
	}
	if (Stage::ins()->LoseFlg == 1 || Stage::ins()->WinFlg == 1) {
		Scene::ins()->ChangeScene(eScene_Menu);
	}
}

void Chess::Draw()
{
	if (roll == player)	Player::ins()->Draw();
	if (roll == enemy)	Enemy::ins()->Draw();
	Stage::ins()->Draw();
	DrawFormatString(100, 0, GetColor(255, 255, 255), "Win:%d, Lose:%d", Stage::ins()->WinFlg, Stage::ins()->LoseFlg);
}