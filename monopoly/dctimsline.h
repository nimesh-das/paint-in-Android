#ifndef __DCTIMSLINE_H_
#define __DCTIMSLINE_H_
#include <iostream>
#include "unownable.h"

class DcTimsLine: public Unownable {
   public:
	 DcTimsLine(); //
	 DcTimsLine(std::string cellName, int indexOfProperty, Board *leboard);
	 //~Coop();
	 void QueryPlayer(Player *p);
	 void sellOptionsDC_Tims_Line(Player *p);

};

#endif
