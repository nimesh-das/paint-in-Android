#ifndef __CELL_H_
#define __CELL_H_
#include <iostream>

class Board;
class Player;


class Cell {
   private:
	 std::string cellName;
	 char Owner;
	 Player *whoOwns;
	 Player *WhosOnTop[6];
	 int indexOnBoard;
	 //Cell *cells[40];
	 bool Owned;
	 Board *leboard;
		 
	public:
	 Cell(); //
	 Cell(std::string cellName, int indexOnBoard, Board *leboard, char Owner='X', Player *whoOwns=NULL, bool Owned=0);
	 virtual ~Cell();
    virtual int getPriceToBuy();
	 virtual void setPriceToBuy(int priceToBuy);
	 virtual int getSellPrice();
	 //virtual void setSellPrice(int sellPrice);
	 virtual int getRent();
	 virtual void setRent(int rent);
	 virtual int getsellPrice();
	 virtual void setSellPrice(int sellprice);
	 virtual bool isItMortgaged();
	 virtual void setMortgaged(bool mortgaged);
	 virtual std::string getBlock();
	 virtual int get_IC();
	 virtual int getNum_Im();
	 virtual void setBlock(std::string blck);
	 virtual void set_IC(int ic);
	 virtual void setNum_Imp(int numIm);
	 virtual int getMaxNumBlockAr1();
	 virtual int getMaxNumBlockAr2();
	 virtual int getMaxNumBlockEng();
	 virtual int getMaxNumBlockHealth();
	 virtual int getMaxNumBlockEnv();
	 virtual int getMaxNumBlockSci1();
	 virtual int getMaxNumBlockSci2();
	 virtual int getMaxNumBlockMath();
	 virtual void setMaxNumBlockAr1(int numB);
    virtual void setMaxNumBlockAr2(int numB);
	 virtual void setMaxNumBlockEng(int numB);
	 virtual void setMaxNumBlockHealth(int numB);
	 virtual void setMaxNumBlockEnv(int numB);
	 virtual void setMaxNumBlockSci1(int numB);
	 virtual void setMaxNumBlockSci2(int numB);
	 virtual void setMaxNumBlockMath(int numB);
	 virtual int getTotLeft();
    virtual void setTotLeft(int TotalLeft);
	 virtual int getTotalOwned();
	 virtual void setTotalOwned(int TotalOwned);
	 virtual int CalcUsageFees();
	 virtual void QueryPlayer(Player *p);
	 virtual void notifyBoard_fromCell();
	 std::string getCellName(); //
	 char getOwnerID();//
	 Player *getOwner();//
    void checkWhosOnTop();
	 int getIndexOnBoard();
    void setCellName(std::string name); //
	 void setOwner(Player *p); //
	 void setOwnerID(char Owner); //
	 bool checkOwned();
	 void setOwned(bool change);
	 Board *getleboard();
	 Cell *WhichCell(std::string prop);
    //void initializeCells();
	 
};

#endif
