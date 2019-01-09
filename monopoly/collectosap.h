#ifndef __COLLECTOSAP_H_
#define __COLLECTOSAP_H_
#include <iostream>
#include "unownable.h"

class CollectOsap: public Unownable {
    public:
	 CollectOsap(); //
	 CollectOsap(std::string cellName, int indexOfProperty, Board *leboard);
	 //~Coop();
	 void QueryPlayer(Player *p);

};

#endif
