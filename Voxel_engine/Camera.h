#pragma once
#ifndef WINDOW_CAMERA_H
#define WINDOW_CAMERA_H

#include <glm/glm.hpp>
using namespace glm;

class Camera
{
	void updateVectors();
public:
	vec3 front;
	vec3 up;
	vec3 right;
	vec3 position;
	mat4 rotation;
	 
	float fov;

	Camera(vec3 position, float fov);

	void rotate(float x, float y, float z);

	mat4 getProjection();
	mat4 getView();

};

#endif // !WINDOW_CAMERA_H
