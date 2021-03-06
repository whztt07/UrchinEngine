#ifndef URCHINENGINE_NAVMESHAGENT_H
#define URCHINENGINE_NAVMESHAGENT_H

#include "UrchinCommon.h"

namespace urchin {

    class NavMeshAgent
    {
        public:
            NavMeshAgent();
            NavMeshAgent(float, float);

            float getAgentHeight() const;
            float getAgentRadius() const;

            CylinderShape<float> getAgentCylinder() const;
            BoxShape<float> getAgentBox() const;

            float computeExpandDistance(const Vector3<float> &) const;

        private:
            float agentHeight;
            float agentRadius;
    };

}

#endif
