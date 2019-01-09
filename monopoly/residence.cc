#include <iostream>
#include "residence.h"
#include "player.h"
using namespace std;

int Residence::TotalLeft = 4;
int Residence::TotalOwned = 0;

Residence::Residence(): Ownable() {
		  this->setPriceToBuy(200);
		  this->setSellPrice(100);
		  this->setMortgaged(0);
		  this->setRent(0);
}

Residence::Residence(string cellName, int indexOnBoard, Board *leboard, int purchaseCost, int sellPrice): Ownable(cellName, indexOnBoard, leboard, purchaseCost, sellPrice), num_improvements(0), Block("Residence") { }

//Residence::~Residence() { }

int Residence::getTotLeft() {
		  return TotalLeft;
}

void Residence::setTotLeft(int TotalLeft) {
		  this->TotalLeft = TotalLeft;
}

int Residence::getTotalOwned() {
		  return TotalOwned;
}

string Residence::getBlock() {
        return Block;
}

int Residence::getNum_Im() {
       return num_improvements;
}

void Residence::setTotalOwned(int TotalOwned) {
		  this->TotalOwned = TotalOwned;
}

void Residence::QueryPlayer(Player *p) {
		  
		  Player *owner = this->getOwner();
		  
		  cout << "~~~~~~ I heard someone just ordered pizza on first floor! Lets go steal some!! ~~~~~~~~~~~" << endl;
		  
		  if (this->isItMortgaged()) {
					 if (owner == p) {
								cout << "You have this property mortgaged." << endl;  
					 }   else {
								cout << "This property is mortgaged so " << p->getID() << " doesn't have to pay rent!" << endl; 
					 }
		  }   
		  //int amt = CalcRent();
		  else if ((this->checkOwned()) && (owner != p)) {
		          int amt = CalcRent();
					 cout << "This residence is owned by " << owner->getID() << "." << endl;
					 cout << p->getID() << " has to pay a rent of amount of " << amt << " ." << endl; 
					 //p->balance -= amt;
					 //p->assets -= amt;
					 p->payRentTo(owner, amt);
		  }
}

int Residence::CalcRent() {
		  Player *owner = this->getOwner();
		  int totResOwned_byOwner = owner->getnumResidence();
		  int rnt = (totResOwned_byOwner == 1) ? 25 : (totResOwned_byOwner == 2) ? 50 : (totResOwned_byOwner == 3) ? 100 : 200;
		  this->setRent(rnt);
		  return rnt;
}
