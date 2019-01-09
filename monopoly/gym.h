#ifndef __GYM_H_
#define __GYM_H_
#include <iostream>
#include "ownable.h"

class Board;
class Player;
class Die;

class Gym: public Ownable {
   
	std::string Block;
	static int TotalLeft;
	static int TotalOwned;
	Die *dice;
	int num_improvements;

	public:
	Gym();
	Gym(std::string cellName, int indexOnBoard, Board *leboard, int purchaseCost, int sellPrice);
	//~Gym();
   int getTotLeft();
   void setTotLeft(int TotalLeft);
	int getTotalOwned();
	void setTotalOwned(int TotalOwned);
	int CalcUsageFees();
	void QueryPlayer(Player *p);
	int getNum_Im();
	std::string getBlock();
	
};

#endif
