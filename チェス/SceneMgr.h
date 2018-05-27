#pragma once

#include "Scene.h"
#include "BaseScene.h"
#include "Menu.h"
#include "Game.h"
#include "Config.h"

class SceneMgr
{

public:

	BaseScene * mScene;

	void Update();
	void Draw();

	SceneMgr();
	~SceneMgr();

};

