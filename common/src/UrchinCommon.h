#ifndef ENGINE_URCHINCOMMON_H
#define ENGINE_URCHINCOMMON_H

#include "tools/file/PropertyFileHandler.h"
#include "tools/logger/Logger.h"
#include "tools/logger/FileLogger.h"
#include "tools/ConfigService.h"
#include "tools/xml/XmlParser.h"
#include "tools/xml/XmlWriter.h"
#include "tools/xml/XmlAttribute.h"
#include "tools/xml/XmlChunk.h"

#include "pattern/observer/Observable.h"
#include "pattern/observer/Observer.h"
#include "pattern/singleton/Singleton.h"
#include "pattern/singleton/SingletonManager.h"
#include "pattern/singleton/SingletonInterface.h"

#include "io/Converter.h"
#include "io/StringUtil.h"
#include "system/FileSystem.h"
#include "system/FileHandler.h"
#include "math/algebra/matrix/Matrix2.h"
#include "math/algebra/matrix/Matrix3.h"
#include "math/algebra/matrix/Matrix4.h"
#include "math/algebra/point/Point2.h"
#include "math/algebra/point/Point3.h"
#include "math/algebra/point/Point4.h"
#include "math/algebra/vector/Vector2.h"
#include "math/algebra/vector/Vector3.h"
#include "math/algebra/vector/Vector4.h"
#include "math/algebra/Quaternion.h"
#include "math/algebra/Transform.h"
#include "math/algebra/MathValue.h"
#include "math/geometry/2d/Line2D.h"
#include "math/geometry/2d/shape/ConvexShape2D.h"
#include "math/geometry/2d/shape/RectangleShape.h"
#include "math/geometry/2d/shape/ConvexHullShape2D.h"
#include "math/geometry/2d/object/ConvexObject2D.h"
#include "math/geometry/2d/object/ConvexHull2D.h"
#include "math/geometry/2d/object/LineSegment2D.h"
#include "math/geometry/2d/object/Rectangle.h"
#include "math/geometry/3d/Line3D.h"
#include "math/geometry/3d/Ray.h"
#include "math/geometry/3d/Plane.h"
#include "math/geometry/3d/IndexedTriangle3D.h"
#include "math/geometry/3d/shape/ConvexShape3D.h"
#include "math/geometry/3d/shape/BoxShape.h"
#include "math/geometry/3d/shape/SphereShape.h"
#include "math/geometry/3d/shape/TriangleShape3D.h"
#include "math/geometry/3d/shape/CapsuleShape.h"
#include "math/geometry/3d/shape/CylinderShape.h"
#include "math/geometry/3d/object/ConvexObject3D.h"
#include "math/geometry/3d/object/AABBox.h"
#include "math/geometry/3d/object/ConvexHull3D.h"
#include "math/geometry/3d/object/Frustum.h"
#include "math/geometry/3d/object/LineSegment3D.h"
#include "math/geometry/3d/object/OBBox.h"
#include "math/geometry/3d/object/Sphere.h"
#include "math/geometry/3d/object/Triangle3D.h"
#include "math/geometry/3d/object/Tetrahedron.h"
#include "math/geometry/3d/object/Capsule.h"
#include "math/geometry/3d/object/Cylinder.h"
#include "math/algorithm/MathAlgorithm.h"
#include "math/algorithm/PascalTriangle.h"
#include "math/trigonometry/AngleConverter.h"

#endif
