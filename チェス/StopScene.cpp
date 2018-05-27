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

	DrawFormatString(100, 10, GetColor(255, 255, 255), "一時停止中");
	DrawFormatString(100, 25, GetColor(255, 255, 255), "メニュー画面に戻りますか？");

}
