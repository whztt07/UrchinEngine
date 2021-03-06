#ifndef URCHINENGINE_MAPEDITOR_WATERCONTROLLER_H
#define URCHINENGINE_MAPEDITOR_WATERCONTROLLER_H

#include <list>
#include "UrchinCommon.h"
#include "UrchinMapHandler.h"
#include "Urchin3dEngine.h"

namespace urchin
{

    class WaterController
    {
        public:
            explicit WaterController(MapHandler *);

            bool isModified() const;
            void resetModified();

            std::list<const SceneWater *> getSceneWaters() const;
            void addSceneWater(SceneWater *);
            void removeSceneWater(const SceneWater *);

            const SceneWater *updateSceneWaterGeneral(const SceneWater *, const Point3<float> &, float, float);
            const SceneWater *updateSceneWaterSurface(const SceneWater *, const Vector3<float> &, const std::string &, const std::string &, float, float, float, float);
            const SceneWater *updateSceneWaterUnderWater(const SceneWater *, float, float);

        private:
            void markModified();
            SceneWater *findSceneWater(const SceneWater *);

            bool bIsModified;
            MapHandler *mapHandler;
    };

}

#endif
