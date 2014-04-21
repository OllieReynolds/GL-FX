#ifndef SCENE_HPP
#define SCENE_HPP

#include "camera.hpp"
#include "mesh.hpp"
#include "shader.hpp"
#include "skybox.h"
#include "panel.hpp"
#include "plane.hpp"
#include "audioplayer.hpp"

class Scene
{
public:
	Scene();
	~Scene();

	void create();
	void draw(GLFWwindow *window);
	void kill();

	static bool recompileShaders;

private:
	Camera*	camera;


	Mesh*	mesh;
	Plane*	plane;

	Skybox* skybox;

	Panel*	panel;

	Shader*	basicShader;
	Shader* skyboxShader;
	Shader* panelShader;
	Shader* planeShader;
	Shader* camShader;
	
};

#endif // SCENE_HPP