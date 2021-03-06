#ifndef URCHINENGINE_BODYMANAGER_H
#define URCHINENGINE_BODYMANAGER_H

#include <mutex>

#include "body/AbstractBody.h"
#include "body/work/AbstractWorkBody.h"

namespace urchin
{

	/**
	* A bodies manager allowing to manage bodies modifications coming from two different thread. Indeed, the user
	* can add/remove/update bodies from thread 1 while physics engine update the same bodies on thread 2.
	*/
	class BodyManager : public Observable
	{
		public:
			BodyManager();
			~BodyManager() override;

			enum NotificationType
			{
				ADD_WORK_BODY, //A body has been added to the world
				REMOVE_WORK_BODY, //A body has been removed from the world
			};

			void addBody(AbstractBody *);
			void removeBody(AbstractBody *);
			AbstractWorkBody *getLastUpdatedWorkBody() const;

			void setupWorkBodies();
			void applyWorkBodies();

			const std::vector<AbstractWorkBody *> &getWorkBodies() const;

		private:
			void createNewWorkBody(AbstractBody *);
			std::vector<AbstractBody *>::iterator deleteBody(AbstractBody *, const std::vector<AbstractBody *>::iterator &);
			void deleteWorkBody(AbstractBody *body);

			std::vector<AbstractBody *> bodies;
			std::vector<AbstractWorkBody *> workBodies;

			mutable std::mutex bodiesMutex;

			AbstractWorkBody *lastUpdatedWorkBody;
	};

}

#endif
