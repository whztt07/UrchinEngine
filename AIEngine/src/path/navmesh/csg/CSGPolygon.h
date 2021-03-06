#ifndef URCHINENGINE_CSGPOLYGON_H
#define URCHINENGINE_CSGPOLYGON_H

#include <string>
#include <vector>
#include "UrchinCommon.h"

namespace urchin
{

	template<class T> class CSGPolygon
	{
		public:
			CSGPolygon(std::string name, const std::vector<Point2<T>> &);
			CSGPolygon(std::string name, std::vector<Point2<T>> &&);
			CSGPolygon(const CSGPolygon &);
			CSGPolygon(CSGPolygon &&) noexcept;
			CSGPolygon& operator=(CSGPolygon &&) noexcept;

			const std::string &getName() const;
			const std::vector<Point2<T>> &getCwPoints() const;

			T computeArea() const;
			bool pointInsidePolygon(const Point2<T> &) const;
			bool pointInsideOrOnPolygon(const Point2<T> &) const;

			void expand(T);
			void simplify(T, T);

		private:
			void checkCwPoints() const;
			bool pointInsidePolygon(const Point2<T> &, bool) const;

			std::string name;
			mutable std::vector<Point2<T>> cwPoints;

	};

	template<class T> std::ostream& operator <<(std::ostream &, const CSGPolygon<T> &);

}

#endif
