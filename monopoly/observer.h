#ifndef __OBSERVER_H__
#define __OBSERVER_H__

class Observer {
	public:
	//pure virtual method notify, 
	//subclases must implement to be concrete
	virtual void notify() = 0;
	virtual ~Observer();
};

#endif
