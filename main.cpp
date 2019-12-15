#include "edges.h"
#include "euler_characteristic.h"
#include <igl/read_triangle_mesh.h>
#include <igl/opengl/glfw/Viewer.h>
#include <vector>
#include <openvr.h>
using namespace std;

#include "utils.h"


bool key_down(igl::opengl::glfw::Viewer& viewer, unsigned char key, int modifier)
{
	std::cout << "detected" << key << std::endl;
	if (key == 'E')
	{
		viewer.core.camera_translation = viewer.core.camera_translation + Eigen::Vector3f(0, 0.05, 0);
	}
	if (key == 'Q')
	{
		viewer.core.camera_translation = viewer.core.camera_translation + Eigen::Vector3f(0, -0.05, 0);
	}
	if (key == 'A')
	{
		viewer.core.camera_translation = viewer.core.camera_translation + Eigen::Vector3f(0.05, 0, 0);
	}
	if (key == 'D')
	{
		viewer.core.camera_translation = viewer.core.camera_translation + Eigen::Vector3f(-0.05, 0, 0);
	}
	if (key == 'W')
	{
		viewer.core.camera_translation = viewer.core.camera_translation + Eigen::Vector3f(0, 0, 0.05);
	}
	if (key == 'S')
	{
		viewer.core.camera_translation = viewer.core.camera_translation + Eigen::Vector3f(0, 0, -0.05);
	}
	if (key == '4')
	{
		viewer.core.trackball_angle = viewer.core.trackball_angle * Eigen::Quaternionf(0.1, 0, 0, 0);
	}
	if (key == '5')
	{
		viewer.core.trackball_angle = viewer.core.trackball_angle * Eigen::Quaternionf(-0.1, 0, 0, 0);
	}
	return false;
}

int main(int argc, char *argv[])
{
	Eigen::MatrixXd V;
	Eigen::MatrixXi F;
	// Load in a mesh
	igl::read_triangle_mesh(argc > 1 ? argv[1] : "../shared/data/bunny.off", V, F);


	// Create a libigl Viewer object 
	igl::opengl::glfw::Viewer viewer;
	// Set the vertices and faces for the viewer
	viewer.data().set_mesh(V, F);

	viewer.callback_key_down = &key_down;


	// Launch a viewer instance
	viewer.launch();
	return 0;
}