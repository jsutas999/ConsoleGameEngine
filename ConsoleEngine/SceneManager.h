#pragma once
#include"Scene.h"
#include <vector>
class SceneManager
{
public:
	static SceneManager* getInstance();
	void LoadNextScene(Scene* scene);
	void LoadPreviesScene();
	Scene* getCurrentScene();
	SceneManager();
	~SceneManager();
private:
	std::vector<Scene*> levels;
	static SceneManager* singelton;

	
};

