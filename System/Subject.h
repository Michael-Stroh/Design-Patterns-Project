/**
   @file Subject.h
   @class Subject
   @authors Alex
   @version 1.0.0
   @brief The pure virtual class that all other subjects will inherit from
 */

#ifndef SUBJECT_H
#define SUBJECT_H

#include "RaceState.h"

class Subject {

	public:
		/**
				Constructor
			*/
		Subject();

		/**
				Destructor
			*/
		~Subject();

		/**

				@param An instance of RaceTeam, to be attached to the subject
		*/
		 void attach(RaceTeam *);						 

		/**

				@param An instance of RaceTeam, to be detached from the subject
			*/
		void detach(RaceTeam *);

		/**

			@brief: Detaches all observers
			*/
		void detachAll();

		/**

				@param An instance of RaceState, to inform all observers of any changes
			*/
		virtual void notify(RaceState *) = 0;

	protected:
		/**
				@brief A vector containing all of the observers for the class
			*/
		vector<RaceTeam *> observerList;
};

#endif
