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

	DrawFormatString(100, 10, GetColor(255, 255, 255), "�ꎞ��~��");
	DrawFormatString(100, 25, GetColor(255, 255, 255), "���j���[��ʂɖ߂�܂����H");

}
