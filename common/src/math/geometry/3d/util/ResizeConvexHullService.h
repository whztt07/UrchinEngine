#ifndef ENGINE_RESIZECONVEXHULLSERVICE_H
#define ENGINE_RESIZECONVEXHULLSERVICE_H

#include <memory>
#include <vector>

#include "pattern/singleton/Singleton.h"
#include "math/geometry/3d/shape/ConvexHullShape3D.h"
#include "math/geometry/3d/object/ConvexHull3D.h"
#include "math/geometry/3d/Plane.h"
#include "math/algebra/point/Point3.h"

namespace urchin
{

	template<class T> class ResizeConvexHullService : public Singleton<ResizeConvexHullService<T>>
	{
		public:
			friend class Singleton<ResizeConvexHullService<T>>;

			std::unique_ptr<ConvexHullShape3D<T>> resizeConvexHullShape(const ConvexHullShape3D<T> &, T) const;
			std::unique_ptr<ConvexHull3D<T>> resizeConvexHull(const ConvexHull3D<T> &, T) const;

		private:
			ResizeConvexHullService();
			virtual ~ResizeConvexHullService();

			void buildPlanesFromConvexHullShape(const ConvexHullShape3D<T> &, std::vector<Plane<T>> &) const;
			bool isPlaneAlreadyExist(const std::vector<Plane<T>> &, const Plane<T> &) const;
			void shiftPlanes(const std::vector<Plane<T>> &, std::vector<Plane<T>> &, T) const;
			bool isPointInsidePlanes(const std::vector<Plane<T>> &, const Point3<T> &) const;
	};

}

#endif
