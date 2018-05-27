#include "Config.h"
#include "DxLib.h"
#include "Scene.h"

Config::Config(){
}

Config::~Config(){
}

void Config::Update()
{

	MenuButton->Update();
	if (MenuButton->OnClick)	Scene::ins()->ChangeScene(eScene_Menu);

}

void Config::Draw()
{

	MenuButton->Draw();
	DrawFormatString(100, 100, GetColor(255, 255, 255), "Config");

}