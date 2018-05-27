#include "Scene.h"

Scene::Scene(){

	scene = eScene_None;

}

void Scene::ChangeScene(eScene nextScene)
{

	scene = nextScene;

}

eScene Scene::GetScene()
{

	return scene;

}

void Scene::SetScene(eScene Scene)
{

	scene = Scene;

}