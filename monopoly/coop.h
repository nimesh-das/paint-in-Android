#ifndef __COOP_H_
#define __COOP_H_
#include <iostream>
#include "unownable.h"

class Coop: public Unownable {
   public:
	 Coop(); //
	 Coop(std::string cellName, int indexOfProperty, Board *leboard);
	 //~Coop();
	 void QueryPlayer(Player *p);
	 void sellOptionsCoop(Player *p);

};

#endif
