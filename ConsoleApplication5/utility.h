#pragma once
#include <GL/freeglut.h>
#include<glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
namespace utility
/*
* utility for transformation:
* the matrix_for_rotation_over_axis function use to create a tranformtion matrix for rotation
* the axis that the tranformtion is around is a line that pull batwin the 2 point a and b
* the result will store in output
* the vecMultyple use to find the normal of a plane that lay batwin 2 vector and do it by multple the 2 vector
*/
{
	void vecMultyple(glm::vec4* targt, glm::vec4 a, glm::vec4 b);
	void matrix_for_rotation_over_axis(glm::mat4* output, glm::vec3 a, glm::vec3 b, float angle);
};

