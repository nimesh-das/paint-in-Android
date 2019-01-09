#include <iostream>
#include "cell.h"
#include "player.h"
#include "board.h"
using namespace std;


Cell::Cell(): cellName(""), Owner('X'), whoOwns(NULL), indexOnBoard(-1), Owned(0), leboard(NULL) {
	  for(int i = 0; i < 6; i++) {
          WhosOnTop[i] = NULL;
	  }
}

Cell::Cell(string cellName, int indexOnBoard, Board *leboard, char Owner, Player* whoOwns, bool Owned): cellName(cellName), indexOnBoard(indexOnBoard), leboard(leboard), Owner(Owner), whoOwns(whoOwns), Owned(Owned) {
	  for(int i = 0; i < 6; i++) {
         WhosOnTop[i] = NULL;
	  }
}

void Cell::notifyBoard_fromCell() {
   cout << "Only to be used by SLC" << endl;
}

Cell *Cell::WhichCell(string prop) {
       return leboard->giveMePropOnStr(prop);
}

Cell::~Cell() { }

void Cell::QueryPlayer(Player *p) { }

int Cell::getPriceToBuy() { cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
void Cell::setPriceToBuy(int priceToBuy) { cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
int Cell::getSellPrice() { cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
//void Cell::setSellPrice(int sellPrice) { cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
int Cell::getRent() { cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
void Cell::setRent(int rent) { cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
int Cell::getsellPrice() { cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }

void Cell::setSellPrice(int sellprice) { cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
bool Cell::isItMortgaged() { cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
void Cell::setMortgaged(bool mortgaged) { cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }

std::string Cell::getBlock() {cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	int Cell::get_IC() {cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	int Cell::getNum_Im() {cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	void Cell::setBlock(std::string blck) {cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	void Cell::set_IC(int ic) {cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	void Cell::setNum_Imp(int numIm){cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	int Cell::getMaxNumBlockAr1(){cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	int Cell::getMaxNumBlockAr2(){cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	int Cell::getMaxNumBlockEng(){cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	int Cell::getMaxNumBlockHealth(){cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	int Cell::getMaxNumBlockEnv(){cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	int Cell::getMaxNumBlockSci1(){cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	int Cell::getMaxNumBlockSci2(){cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	int Cell::getMaxNumBlockMath(){cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	void Cell::setMaxNumBlockAr1(int numB){cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
   void Cell::setMaxNumBlockAr2(int numB){cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	void Cell::setMaxNumBlockEng(int numB) { cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	void Cell::setMaxNumBlockHealth(int numB){cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	void Cell::setMaxNumBlockEnv(int numB){cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	void Cell::setMaxNumBlockSci1(int numB){cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	void Cell::setMaxNumBlockSci2(int numB){cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	void Cell::setMaxNumBlockMath(int numB){ cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl;}

	 int Cell::getTotLeft() {cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
   void Cell::setTotLeft(int TotLeft) {cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	int Cell::getTotalOwned() {cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl;
	return 0;}
	void Cell::setTotalOwned(int TotOwned) {cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }
	int Cell::CalcUsageFees() {cout << "The fact that you're here means that you cannot use this function on the particular building, or it doesn't make sense to do so." << endl; }

std::string Cell::getCellName() {
     return this->cellName;
}

Board *Cell::getleboard() {
     return leboard;
}

char Cell::getOwnerID() {
     return this->Owner;
}

Player *Cell::getOwner() {
     return whoOwns;
}

void Cell::checkWhosOnTop() {
   cout << "Players on top: ";
	  for(int i = 0; i < 6; i++) {
        if (!WhosOnTop[i]) {
            break;
		  }
    	     cout << WhosOnTop[i]->getID() << ", ";
	  }
	cout << endl;
}

int Cell::getIndexOnBoard() {
   return this->indexOnBoard; 
}

void Cell::setCellName(std::string name) {
     this->cellName = name;
}

void Cell::setOwner(Player *p) {
     this->whoOwns = p;
}

void Cell::setOwnerID(char Owner) {
     this->Owner = Owner;
}

bool Cell::checkOwned() {
    return Owned;
}

void Cell::setOwned(bool change) {
    Owned = change;
}


