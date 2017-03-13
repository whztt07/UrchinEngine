#ifndef ENGINE_NAVMESHGENERATOR_H
#define ENGINE_NAVMESHGENERATOR_H

#include <memory>
#include <vector>

#include "input/AIWorld.h"
#include "path/navmesh/NavMeshConfig.h"
#include "path/navmesh/model/NavMesh.h"
#include "path/navmesh/model/NavPolygon.h"
#include "path/navmesh/polyhedron/Polyhedron.h"
#include "path/navmesh/triangulation/Triangulation.h"

namespace urchin
{

	struct PolyhedronFace
	{
		unsigned int polyhedronIndex;
		unsigned int faceIndex;
	};

	class NavMeshGenerator
	{
		public:
			NavMeshGenerator(std::shared_ptr<AIWorld>, NavMeshConfig);

			std::shared_ptr<NavMesh> generate();

		private:
			std::vector<Polyhedron> createPolyhedrons();
			Polyhedron createPolyhedronFor(const std::string &, OBBox<float> *);

			std::vector<PolyhedronFace> findWalkableFaces(const std::vector<Polyhedron> &);

			NavPolygon createNavigationPolygonFor(const PolyhedronFace &, const std::vector<Polyhedron> &);
			std::vector<Point2<float>> flatPointsOnYAxis(const std::vector<Point3<float>> &) const;
			void addObstacles(const std::vector<Polyhedron> &, unsigned int, Triangulation &);
			std::vector<Point3<float>> elevateTriangulatedPoints(const Triangulation &, const Face &);
			std::vector<IndexedTriangle3D<float>> toIndexedTriangle3D(const std::vector<IndexedTriangle2D<float>> &);

			std::shared_ptr<AIWorld> aiWorld;
			NavMeshConfig navMeshConfig;
	};

}

#endif
