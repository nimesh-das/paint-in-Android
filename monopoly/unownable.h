#ifndef __UNOWNABLE_H_
#define __UNOWNABLE_H_
#include <iostream>
#include "cell.h"

class Unownable: public Cell {
   public:
	 Unownable(); //
	 Unownable(std::string cellName, int indexOfProperty, Board *leboard);
	 virtual ~Unownable();

};

#endif
