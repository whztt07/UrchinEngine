#ifndef URCHINENGINE_MAPEDITOR_SCENEDISPLAYER_H
#define URCHINENGINE_MAPEDITOR_SCENEDISPLAYER_H

#include <vector>
#include <QWidget>
#include "UrchinCommon.h"
#include "UrchinPhysicsEngine.h"
#include "Urchin3dEngine.h"
#include "UrchinSoundEngine.h"
#include "UrchinMapHandler.h"

#include "scene/displayer/SceneFreeCamera.h"
#include "scene/displayer/objects/BodyShapeDisplayer.h"
#include "scene/displayer/lights/LightScopeDisplayer.h"
#include "scene/displayer/sounds/SoundTriggerDisplayer.h"
#include "scene/displayer/ai/NavMeshDisplayer.h"

namespace urchin
{

	class SceneDisplayer
	{
		public:
			enum ViewProperties
			{
				MODEL_PHYSICS = 0,
				LIGHT_SCOPE,
				SOUND_TRIGGER,
				NAV_MESH,

				LAST_VIEW_PROPERTIES
			};

			explicit SceneDisplayer(QWidget *);
			~SceneDisplayer();

			void initializeFromExistingMap(const std::string &, const std::string &);
			void initializeFromNewMap(const std::string &, const std::string &, const std::string &);

			void setViewProperties(SceneDisplayer::ViewProperties, bool);
			void setHighlightSceneObject(const SceneObject *);
			void setHighlightCompoundShapeComponent(std::shared_ptr<const LocalizedCollisionShape>);
			void setHighlightSceneLight(const SceneLight *);
			void setHighlightSceneSound(const SceneSound *);

			void paint();
			void resize(unsigned int width, unsigned int height);

			SceneManager *getSceneManager() const;
			PhysicsWorld *getPhysicsWorld() const;
			MapHandler *getMapHandler() const;

		private:
			void initializeEngineResources(const std::string &);
			void initializeScene();

			void refreshRigidBodyShapeModel();
			void refreshLightScopeModel();
			void refreshSoundTriggerModel();
			void refreshNavMeshModel();

			bool isInitialized;
			QWidget *parentWidget;

			//3d
			SceneManager *sceneManager;
			SceneFreeCamera *camera;
			BodyShapeDisplayer *bodyShapeDisplayer;
			LightScopeDisplayer *lightScopeDisplayer;
			SoundTriggerDisplayer *soundTriggerDisplayer;
			NavMeshDisplayer *navMeshDisplayer;

			//physics
			PhysicsWorld *physicsWorld;

			//AI
			AIManager *aiManager;

			//sound
			SoundManager *soundManager;

			//map handler
			MapHandler *mapHandler;

			//scene specifics
			bool viewProperties[LAST_VIEW_PROPERTIES];
			const SceneObject *highlightSceneObject;
			const SceneLight *highlightSceneLight;
			const SceneSound *highlightSceneSound;
	};

}

#endif
