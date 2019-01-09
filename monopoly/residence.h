#ifndef __RESIDENCE_H_
#define __RESIDENCE_H_
#include <iostream>
#include "ownable.h"

class Board;
class Player;

class Residence: public Ownable {
   std::string Block;
	static int TotalLeft;
	static int TotalOwned;
	int num_improvements;

	public:
	Residence();
	Residence(std::string cellName, int indexOnBoard, Board *leboard, int purchaseCost, int sellPrice);
	//~Residence();
   int getTotLeft();
   void setTotLeft(int TotalLeft);
	int getTotalOwned();
	void setTotalOwned(int TotalOwned);
	int CalcRent();
	void QueryPlayer(Player *p);
	int getNum_Im();
	std::string getBlock();
	 
};

#endif
