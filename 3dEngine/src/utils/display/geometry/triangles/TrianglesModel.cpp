#include <GL/glew.h>

#include "TrianglesModel.h"

namespace urchin
{

	TrianglesModel::TrianglesModel(const std::vector<Point3<float>> &points, const std::vector<IndexedTriangle3D<float>> &triangles):
			points(points),
			triangles(triangles)
	{
		initialize();
	}

	Matrix4<float> TrianglesModel::retrieveModelMatrix() const
	{
		return {};
	}

	std::vector<Point3<float>> TrianglesModel::retrieveVertexArray() const
	{
		std::vector<Point3<float>> vertexArray;
		vertexArray.reserve(triangles.size()*3);

		for(const auto &triangle : triangles)
		{
			vertexArray.push_back(points[triangle.getIndex(0)]);
			vertexArray.push_back(points[triangle.getIndex(1)]);
			vertexArray.push_back(points[triangle.getIndex(2)]);
		}

		return vertexArray;
	}

	void TrianglesModel::drawGeometry() const
	{
		glDrawArrays(GL_TRIANGLES, 0, triangles.size()*3);
	}

}
