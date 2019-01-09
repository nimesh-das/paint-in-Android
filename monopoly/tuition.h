#ifndef __TUITION_H_
#define __TUITION_H_
#include <iostream>
#include "unownable.h"

class Tuition: public Unownable {
   public:
	 Tuition(); //
	 Tuition(std::string cellName, int indexOfProperty, Board *leboard);
	 //~Coop();
	 void QueryPlayer(Player *p);
	 void SellOptionsTuition(Player *p);

};

#endif
