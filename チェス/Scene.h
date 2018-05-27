#pragma once

typedef enum
{

	eScene_Menu,
	eScene_Game,
	eScene_Config,

	eScene_None,

}eScene;


class Scene
{

	Scene();

	eScene scene;

public:

	static Scene* ins() {

		static Scene ins;
		return &ins;

	}

	void ChangeScene(eScene nextScene);

	eScene GetScene();
	void SetScene(eScene scene);

};

