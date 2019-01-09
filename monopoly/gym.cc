#include <iostream>
#include "gym.h"
#include "player.h"
#include "die.h"
using namespace std;

int Gym::TotalLeft = 0;
int Gym::TotalOwned = 0;

Gym::Gym(): Ownable() {
		  this->setPriceToBuy(150);
		  this->setSellPrice(75);
		  this->setMortgaged(0);
		  this->setRent(0);
}

Gym::Gym(string cellName, int indexOnBoard, Board *leboard, int purchaseCost, int sellPrice): Ownable(cellName, indexOnBoard, leboard, purchaseCost, sellPrice), num_improvements(0), Block("Gym") { }

//Gym::~Gym() { }

int Gym::getTotLeft() {
		  return TotalLeft;
}

string Gym::getBlock() {
       return Block; 
}

int Gym::getNum_Im() {
    return num_improvements;
}

void Gym::setTotLeft(int TotalLeft) {
		  this->TotalLeft = TotalLeft;
}

int Gym::getTotalOwned() {
		  return TotalOwned;
}

void Gym::setTotalOwned(int TotalOwned) {
		  this->TotalOwned = TotalOwned;
}

void Gym::QueryPlayer(Player *p) {
		  
		  Player *owner = this->getOwner();
		  
		  cout << "~~~~ Work out hard fellas!~~~~~~~~" << endl;
		  
		  if (this->isItMortgaged()) {
					 if (this->getOwner() == p) {
								cout << "You have this property mortgaged." << endl;  
					 }   else {
								cout << "This property is mortgaged so " << p->getID() << " doesn't have to pay rent!" << endl; 
					 }
		  }   
		 // int amt = CalcUsageFees();
		  else if ((this->checkOwned()) && (owner != p)) {
		          int amt = CalcUsageFees();
					 cout << "This residence is owned by " << owner->getID() << "." << endl;
					 cout << p->getID() << " has to pay a rent amount of " << amt << " ." << endl; 
					 p->payRentTo(owner, amt);
		  }
}

int Gym::CalcUsageFees() {
		  Player *owner = this->getOwner();
		 if (owner) { 
		  int totGymsOwned_byOwner = owner->getnumGyms();
		  int rollSum = owner->rollDice();
		  int rnt = (totGymsOwned_byOwner == 1) ? 4*rollSum : (totGymsOwned_byOwner == 2) ? 10*rollSum : 0;
		  this->setRent(rnt);
		  return rnt;
	 }
}
