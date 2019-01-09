#ifndef __GO_TO_TIMS_H_
#define __GO_TO_TIMS_H_
#include <iostream>
#include "unownable.h"

class GoToTims: public Unownable {
   public:
	 GoToTims(); //
	 GoToTims(std::string cellName, int indexOfProperty, Board *leboard);
	 ~GoToTims();
	 void QueryPlayer(Player *p);

};

#endif
