#include <iostream>
#include "coop.h"
#include "player.h"
#include <sstream>
using namespace std;

Coop::Coop(): Unownable() { }

Coop::Coop(string cellName, int indexOfProperty, Board *leboard): Unownable(cellName, indexOfProperty, leboard) { }

//Coop::~Coop() { }

void Coop::QueryPlayer(Player *p) {
     cout << p->getID() << " needs to pay $150 immediately to the bank." << endl;	
	  if (p->getBalance() >= 150) {
	      int bal = p->getBalance();
			bal -= 150;
			p->setBalance(bal);
        cout << "$150 paid successfully" << endl;
	  } else {
       sellOptionsCoop(p);
	  }
}

void Coop::sellOptionsCoop(Player *p) {
		  if (p->getAssets() >= 150) {
					 
					 cout << "You need cash for rent. You can get it by selling a property or an improvement, mortgaging some property, ";
					 cout << "or by trading property for money. What would you like to do? If you'd like to trade, type in 'trade player property amount', otherwise to sell improvement";
					 cout << " type in 'unimprove property', to sell a property, type in 'sell property', and finally to mortgage a property, type in 'mortgage property'." << endl;
					 
					 string inp;
					 
				while(getline(cin, inp)) {
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
                                                     cout << "Trade accepted!" << endl;
																	  	p->makeTrade(smPl, smProp, amt);
																  
															 } else {
                                                   cout << "Trade rejected. Sorry" << endl;
																	//this->sellOptionsCoop(p);
																	continue;
															 }
 
									} else {
                            cout << "Invalid trade" << endl;
									 continue;
								   }
								
							//	p->makeTrade(smPl, smProp, amt);
											
								if (p->getBalance() >= (150)) {
										  cout << "Payout successful!" << endl;
										  p->decrBalance(150);
										  break;
										  //receiver->incrBalance(rentAmount);
								} else {
										  cout << "Sorry, transaction incomplete or still need more!" << endl;
										  continue;
										  //this->sellOptionsCoop(p);
								}
					 } else if (word == "unimprove") {
								string prop2;
								ss >> prop2;
								Cell *smProp2 = WhichCell(prop2);
								p->sellImprovement(smProp2);
								if (p->getBalance() >= (150)) {
										  cout << "Payout successful!" << endl;
										  p->decrBalance(150);
										  break;
										  //receiver->incrBalance(rentAmount);
								} else {
										 cout << "Sorry, transaction incomplete or still need more!" << endl;
										 continue;
										 // this->sellOptionsCoop(p);
								}
					 }  else if (word == "sell") {
								string prop3;
								ss >> prop3;
								Cell *smProp3 = WhichCell(prop3);
								p->sellProperty(smProp3);
								if (p->getBalance() >= (150)) {
										  cout << "Payout successful!" << endl;
										  p->decrBalance(150);
										  break;
										  //receiver->incrBalance(150);
								} else {
										  cout << "Sorry, transaction incomplete or still need more!" << endl;
										  continue;
										  //this->sellOptionsCoop(p);
								}
					 }  else if (word == "mortgage") {
								string prop4;
								ss >> prop4;
								Cell *smProp4 = WhichCell(prop4);
								p->mortgage(smProp4);
								if (p->getBalance() >= (150)) {
										  cout << "Payout successful!" << endl;
										  p->decrBalance(150);
										  break;
										  //receiver->incrBalance(rentAmount);
								} else {
										 cout << "Sorry, transaction incomplete or still need more!" << endl;
										 continue;
										 // this->sellOptionsCoop(p);
								}
		    			 } else {
                     cout << "invalid input" << endl;
							continue;
						 }
				}
		  } else {
					 cout << "You must declare bankruptcy. Type in 'declareBankruptcy'" << endl;
					 string useless;
					 cin >> useless;
					 cout << "You're out of the game." << endl;
					 p->declareBankruptcy();

		  }
}


