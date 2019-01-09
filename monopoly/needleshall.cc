#include <iostream>
#include "needleshall.h"
#include "player.h"
#include <cstdlib>
#include <ctime>
#include "board.h"

using namespace std;

NeedlesHall::NeedlesHall(): Unownable() { }

NeedlesHall::NeedlesHall(string cellName, int indexOfProperty, Board *leboard): Unownable(cellName, indexOfProperty, leboard) { }

void NeedlesHall::QueryPlayer(Player *p) {
     
   cout << "~~~~ A kid just runs out yelling 'I LOST MY PASSWORD TO MY OSAP ACCOUNT NOOOOOOOOOOOOOOOOO'~~~~~~~~~" << endl;

	  srand(static_cast<unsigned int>(time(0)));
	  
	  int x = rand() % 18;

	  if (x == 0) {
	     cout << "Landed on needles hall. Player lost $200!" << endl;
        if (p->getBalance() >= 200) {
		     p->decrBalance(200);
		  } else {
           this->SellOptionsNeedlesHall(p, 200);
		  }
	  } else if (x == 1) {
        cout << "Landed on needles hall. Player gained $200!" << endl;
		  p->incrBalance(200);
	  } else if ((x >= 2) && (x <= 3)) {
        cout << "Landed on needles hall. Player lost $100!" << endl;
		  if (p->getBalance() >= 100) {
		     p->decrBalance(100);
		  } else {
          this->SellOptionsNeedlesHall(p, 100);
		  }
	  } else if ((x >= 4) && (x <= 5)) {
        cout << "Landed on needles hall. Player gained $100!" << endl;
		  p->incrBalance(100);
	  } else if ((x >= 6) && (x <= 8)) {
        cout << "Landed on needles hall. Player lost $50!" << endl;
		  if (p->getBalance() >= 50) {
		     p->decrBalance(50);
		  } else {
           this->SellOptionsNeedlesHall(p, 50);
		  }
	  } else if ((x >= 9) && (x <= 11)) {
        cout << "Landed on needles hall. Player gained $50!" << endl;
		  p->incrBalance(50);
	  } else if ((x >= 12) && (x <= 17)) {
        cout << "Landed on needles hall. Player gained $25!" << endl;
		  p->incrBalance(25);
	  } else {
        cout << "Something went wrong" << endl;
	  }

	  int chance = rand() % 100;
   if (Board::getNumRollUpRim() > 0) { 
	  if (chance == 12) {
        cout << "You just won a roll up the rim cup! If at any time you get stuck in line, you can use this to get out of line!" << endl;
		  p->incNumRollUpRim();
		  int tot = Board::getNumRollUpRim();
		  tot--;
		  Board::setNumRollUpRim(tot);
	  }
	}
}

void NeedlesHall::SellOptionsNeedlesHall(Player *p, int rentAmount) { //
		  if (p->getAssets() >= rentAmount) {
					 cout << "You need cash for rent. You can get it by selling a property or an improvement, mortgaging some property, ";
					 cout << "or by trading property for money. What would you like to do? If you'd like to trade, type in 'trade player property amount', otherwise to sell improvement";
					 cout << " type in 'unimprove property', to sell a property, type in 'sell property', and finally to mortgage a property, type in 'mortgage property'." << endl;
					 string inp;
					 getline(cin, inp);
					 stringstream ss;
					 ss << inp;
					 string word;
					 ss >> word;
					 if (word == "trade") {
								string playr;
								ss >> playr;
								string prop;
								ss >> prop;
								int amt;
								ss >> amt;
								Player *smPl = Player::findPlayer(playr);
								Cell *smProp = WhichCell(prop);
								
									if (p->canTradeProp(smPl, smProp, amt)) {
                                  
													 cout << "Player " << p->getID() << " wants to trade their property in exchange for some cash with Player " << playr << ". " << p->getID() << " is offering " << prop << " and requesting " << amt << " << in return. Player " << playr << ", do you accept this offer? type in 'accept' to accept' and 'reject' to reject" << endl;
                                              string answe;
															 cin >> answe;
															 if (answe == "accept") {
                                                     //cout << "Trade successful!" << endl;
																	  	p->makeTrade(smPl, smProp, amt);
																	  //continue;
															 } else {
                                                   cout << "Trade rejected. Sorry" << endl;
																	this->SellOptionsNeedlesHall(p, rentAmount);
																	//continue;
															 }
 
													 } else {
                                           cout << "Invalid trade" << endl;
														 //continue;
													 }
								
								//p->makeTrade(smPl, smProp, amt);
								
								
								if (p->getBalance() >= (rentAmount)) {
										  p->decrBalance(rentAmount);
										  //receiver->incrBalance(rentAmount);
								} else {
										  this->SellOptionsNeedlesHall(p, rentAmount);
								}
					 } else if (word == "unimprove") {
								string prop2;
								ss >> prop2;
								Cell *smProp2 = WhichCell(prop2);
								p->sellImprovement(smProp2);
								if (p->getBalance() >= (rentAmount)) {
										  p->decrBalance(rentAmount);
										  //receiver->incrBalance(rentAmount);
								} else {
										  this->SellOptionsNeedlesHall(p, rentAmount);
								}
					 }  else if (word == "sell") {
								string prop3;
								ss >> prop3;
								Cell *smProp3 = WhichCell(prop3);
								p->sellProperty(smProp3);
								if (p->getBalance() >= (rentAmount)) {
										  p->decrBalance(rentAmount);
										 // receiver->incrBalance(rentAmount);
								} else {
										  this->SellOptionsNeedlesHall(p, rentAmount);
								}
					 }  else if (word == "mortgage") {
								string prop4;
								ss >> prop4;
								Cell *smProp4 = WhichCell(prop4);
								p->mortgage(smProp4);
								if (p->getBalance() >= (rentAmount)) {
										  p->decrBalance(rentAmount);
										 // receiver->incrBalance(rentAmount);
								} else {
										  this->SellOptionsNeedlesHall(p, rentAmount);
								}
					 }
		  } else {
					 cout << "You must declare bankruptcy. Not enough rent. Type in 'declareBankruptcy'" << endl;
					 string useless;
					 cin >> useless;
					 p->declareBankruptcy();
		  }
}


