#include "utility.h"

void utility::vecMultyple(glm::vec4* targt, glm::vec4 a, glm::vec4 b)
{
	targt->x = (a.y * b.z) - (a.z * b.y);
	targt->y = (a.x * b.z) - (a.z * b.x);
	targt->z = (a.x * b.y) - (a.y * b.x);
}
void utility::matrix_for_rotation_over_axis(glm::mat4* output, glm::vec3 a, glm::vec3 b, float angle)
{
	glm::vec3 axis = b - a;
	glm::mat4 Identity = glm::mat4(1.);
	glm::mat4 translate = glm::translate(Identity, a * -1.0f);
	glm::mat4 rotate = glm::rotate(Identity, angle, axis);
	*output = glm::inverse(translate) * rotate * translate;

}

void utility::display_massage()
{
	MessageBox(NULL, L"hallo \n I am roby the labratory robot \n unless you want to\n and then its okey", L"Info", MB_OK | MB_ICONINFORMATION);

	

}
