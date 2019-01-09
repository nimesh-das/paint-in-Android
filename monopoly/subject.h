#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include "observer.h"

const int maxObservers = 10;

class Subject {
	Observer *observers[maxObservers];
	int numObservers;  

 public:
	Subject();
	//add to observers, return true if successful
	bool attach(Observer *o);
	
	//remove from observer
	void detach(Observer *o);
	
	//iterate through all observers and call notify
	void notifyObservers();
	
	virtual ~Subject();
};

#endif
