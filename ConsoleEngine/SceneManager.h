#pragma once
#include"Scene.h"
#include <vector>
// Handles states of current and previuos scenes
class SceneManager
{
public:
	// Returns instance of itslef
	static SceneManager* getInstance();
	// Loads next scene
	// Loading next scene does not remove the old one,
	// It still remains in the memory and can be accesed later on
	void LoadNextScene(Scene* scene);
	// Goes back to the previuos scene
	// Loading previuos scene does not remove the current one,
	// It still remains in the memory and can be accessed later on
	void LoadPreviesScene();
	// Returns the Current scene
	Scene* getCurrentScene();
	SceneManager();
	~SceneManager();
private:
	std::vector<Scene*> levels;
	static SceneManager* singelton;

	
};

