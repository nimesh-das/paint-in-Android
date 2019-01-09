#ifndef __NEEDLESHALL_H_
#define __NEEDLESHALL_H_
#include <iostream>
#include "unownable.h"

class NeedlesHall: public Unownable {
   
	public:
	 NeedlesHall(); //
	 NeedlesHall(std::string cellName, int indexOfProperty, Board *leboard);
	 //~Coop();
	 void QueryPlayer(Player *p);
	 void SellOptionsNeedlesHall(Player *p, int rentAmount);

};

#endif
