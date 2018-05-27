#include "StopScene.h"
#include "Scene.h"
#include "DxLib.h"
#include "Joypad.h"

StopScene::StopScene(){
}

StopScene::~StopScene(){
}

void StopScene::Update()
{

	

}

void StopScene::Draw()
{

	DrawFormatString(100, 10, GetColor(255, 255, 255), "ˆê’â~’†");
	DrawFormatString(100, 25, GetColor(255, 255, 255), "ƒƒjƒ…[‰æ–Ê‚É–ß‚è‚Ü‚·‚©H");

}
