#ifndef __GOOSE_H_
#define __GOOSE_H_
#include <iostream>
#include "unownable.h"

class Goose: public Unownable {
   public:
	 Goose(); 
	 Goose(std::string cellName, int indexOfProperty, Board *leboard);
	 //~Goose();
	 void QueryPlayer(Player *p);

};

#endif
