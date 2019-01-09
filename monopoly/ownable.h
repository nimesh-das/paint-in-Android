#ifndef __OWNABLE_H_
#define __OWNABLE_H_
#include <iostream>
#include "cell.h"

class Board;
class Player;


class Ownable: public Cell {
   
	int priceToBuy;
	int rent;
	int sellPrice;
	bool mortgaged;
	
	public:
	Ownable();
	Ownable(std::string cellName, int indexOnBoard, Board *leboard, int priceToBuy, int sellPrice, int rent=0, bool mortgaged=0);
	virtual ~Ownable();
	//virtual void QueryPlayer(Player *p);
   int getPriceToBuy();
	void setPriceToBuy(int priceToBuy);
	int getSellPrice();
	int getRent();
	void setRent(int rent);
	int getsellPrice();
	void setSellPrice(int sellprice);
	bool isItMortgaged();
	void setMortgaged(bool mortgaged);
	 
};

#endif
