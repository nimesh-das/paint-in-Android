#ifndef __SLC_H_
#define __SLC_H_
#include <iostream>
#include "unownable.h"

class SLC: public Unownable {
   public:
	 SLC(); //
	 SLC(std::string cellName, int indexOfProperty, Board *leboard);
	 //~Coop();
	 void QueryPlayer(Player *p);
	 void notifyBoard_fromCell();

};

#endif
