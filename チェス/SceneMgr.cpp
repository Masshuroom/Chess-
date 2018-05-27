#include "SceneMgr.h"

SceneMgr::SceneMgr(){

	mScene = (BaseScene*) new Menu();

}
SceneMgr::~SceneMgr(){
}

void SceneMgr::Update()
{

	if (Scene::ins()->GetScene() != eScene_None) {//ƒV[ƒ“•ÏX‚³‚ê‚½‚ç

		mScene->Finalize();
		delete mScene;

		switch (Scene::ins()->GetScene()) {

		case eScene_Menu:
			mScene = (BaseScene*) new Menu();
			break;

		case eScene_Game:
			mScene = (BaseScene*) new Game();
			break;

		case eScene_Config:
			mScene = (BaseScene*) new Config();
			break;

		}

		mScene->Initialize();
		Scene::ins()->SetScene(eScene_None);

	}

	mScene->Update();

}

void SceneMgr::Draw()
{

	mScene->Draw();

}