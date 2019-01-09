#include <iostream>
#include "ownable.h"
using namespace std;

Ownable::Ownable(): Cell(), priceToBuy(-1), rent(0), sellPrice(-1), mortgaged(0) { }

Ownable::Ownable(std::string cellName, int indexOnBoard, Board *leboard, int priceToBuy, int sellPrice, int rent, bool mortgaged): Cell(cellName, indexOnBoard, leboard), priceToBuy(priceToBuy), sellPrice(sellPrice), rent(rent), mortgaged(mortgaged) { }

Ownable::~Ownable() { }

int Ownable::getPriceToBuy() {
    return priceToBuy;
}

void Ownable::setPriceToBuy(int priceToBuy) {
    this->priceToBuy = priceToBuy;
}

int Ownable::getSellPrice() {
    return sellPrice;
}
	
void Ownable::setSellPrice(int sellPrice) {
   this->sellPrice = sellPrice;
}

int Ownable::getRent() {
   return rent;
}
	
void Ownable::setRent(int rent) {
   this->rent = rent;
}

int Ownable::getsellPrice() {
   return sellPrice;
}
	
	
//void Ownable::setSellPrice(int sellprice) {
  //  this->sellPrice == sellprice;
//}
	
	
bool Ownable::isItMortgaged() {
    return mortgaged;
}
	
void Ownable::setMortgaged(bool mortgaged) {
   this->mortgaged = mortgaged;
}
