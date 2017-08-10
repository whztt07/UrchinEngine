#ifndef ENGINE_RESIZEPOLYGON2DSERVICETEST_H
#define ENGINE_RESIZEPOLYGON2DSERVICETEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/Test.h>

class ResizePolygon2DServiceTest : public CppUnit::TestFixture
{
    public:
        static CppUnit::Test *suite();

        void reduceTriangle();
        void reduceWithEdgesAcceptance();
};

#endif
