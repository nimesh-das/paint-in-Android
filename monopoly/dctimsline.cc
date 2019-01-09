#include <iostream>
#include "dctimsline.h"
#include "player.h"
#include <sstream>
using namespace std;

DcTimsLine::DcTimsLine(): Unownable() { }

DcTimsLine::DcTimsLine(string cellName, int indexOfProperty, Board *leboard): Unownable(cellName, indexOfProperty, leboard) { }

//Coop::~Coop() { }

void DcTimsLine::sellOptionsDC_Tims_Line(Player *p) {
		  
		  int assets = p->getAssets();
		  int balance = p->getBalance();
		  
		  if (assets > 50) {
					 cout << "You need cash. You can get it by selling a property or an improvement, mortgaging some property, ";
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
								// gotta do some stuff here
                        
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
																	//this->sellOptionsDC_Tims_Line(p);
																	continue;
							    							 }
 
							} else {
                       cout << "Invalid trade" << endl;
							 continue;
							}

							
								if (balance >= 50) {
                            cout << "Taking that 50, you're free!" << endl;
										  balance -= 50;
										  p->setBalance(balance);
										  //  assets -= 50;
										  p->setInLine(0);
										  p->setTurnsIL(0);
										  p->setRollDoublesCount(0);
										  p->setThirdTurnFree(1);
										  p->setinDanger(0);
										  break;
								} else {
										  //this->sellOptionsDC_Tims_Line(p);
										  //cout << "You're free!" << endl;
										 cout << "Sorry, still not enough, need more!" << endl;
										 continue;
								}
					 } else if (word == "unimprove") {
								string prop2;
								ss >> prop2;
								Cell *smProp2 = WhichCell(prop2);
								p->sellImprovement(smProp2);
								if (balance >= 50) {
										 cout << "Taking that 50, you're free!" << endl;
										  balance -= 50;
										  p->setBalance(balance);
										  p->setTurnsIL(0);
										  p->setInLine(0);
										  p->setRollDoublesCount(0);
										  p->setThirdTurnFree(1);
										  p->setinDanger(0);
										  break;
										  //cout << "You're free!" << endl;
								} else {
										 // this->sellOptionsDC_Tims_Line(p);
										 cout << "Sorry, still not enough, need more!" << endl;
										 continue;
								}
					 }  else if (word == "sell") {
								string prop3;
								ss >> prop3;
								Cell *smProp3 = WhichCell(prop3);
								p->sellProperty(smProp3);
								if (balance >= 50) {
										  cout << "Taking that 50, you're free!" << endl;
										  balance -= 50;
										  p->setBalance(balance);
										  p->setTurnsIL(0);
										  p->setInLine(0);
										  p->setRollDoublesCount(0);
										  p->setinDanger(0);
										  p->setThirdTurnFree(1);
										  //cout << "You're free!" << endl;
										  break;
								} else {
										 // this->sellOptionsDC_Tims_Line(p);
										 cout << "Sorry, still not enough!" << endl;
										 continue;
								}
					 }  else if (word == "mortgage") {
								string prop4;
								ss >> prop4;
								Cell *smProp4 = WhichCell(prop4);
								p->mortgage(smProp4);
								if (balance >= 50) {
										  cout << "Taking that 50, you're free!" << endl;
										  balance -= 50;
										  p->setBalance(balance);
										  p->setTurnsIL(0);
										  p->setInLine(0);
										  p->setRollDoublesCount(0);
										  p->setThirdTurnFree(1);
										  p->setinDanger(0);
										  break;
								} else {
										  //this->sellOptionsDC_Tims_Line(p);
										  cout << "Sorry, still not enough!" << endl;
										  continue;
								}
					 } else {
                    cout << "Sorry, invalid input!" << endl;
						  continue;
					 }
				}
		  } else {
					 cout << "You must declare bankruptcy. Not enough for DC TIMS. Type in 'declareBankruptcy" << endl;
					 string garbage;
					 cin >> garbage;
					 p->declareBankruptcy();
					 //break;
		  }
//	}
}

void DcTimsLine::QueryPlayer(Player *p) {
    if (p->amIinline()) {
       cout << "Still in line eh, sorry." << endl;
		 p->IncTurnsIL();
		 if (p->getTurnsIL() >= 3) {
          cout << "gotta get out this time or get outta the game. must pay $50 or use roll up rim, type 'use' to use rolluprimcup, or type 'pay' to pay" << endl;
			 string inp;
	while (cin >> inp) {
		 if (inp == "use") { 
			    if (p->getNumRollup() > 0) {
                cout << "used rolluprim! out of line!" << endl;
				    p->decNumRollUpRim();
					// p->Move(p->getRolledSum());
					 p->setTurnsIL(0);
					 p->setInLine(0);
					 p->setRollDoublesCount(0);
					 p->setRollDoubles(0);
					 p->setinDanger(0);
					 break;
			 } else {
               cout << "sorry none left, gotta pay" << endl;
					if (p->getBalance() >= 50) {
                  cout << "Taking YO MONEY!!!! 50 DOLLAH!" << endl;
						int bal = p->getBalance();
						bal -= 50;
						p->setBalance(bal);
						cout << "payout successful" << endl;
					//	p->Move(p->getRolledSum());
						p->setTurnsIL(0);
						p->setInLine(0);
						p->setRollDoublesCount(0);
						p->setRollDoubles(0);
						p->setinDanger(0);
						break;
					} else {
                  cout << "gotta trade some stuff" << endl;
						p->setinDanger(1);
					   sellOptionsDC_Tims_Line(p);
						break;
					}
			 }
		 } else if (inp == "pay") {
           if (p->getBalance() >= 50) {
                int bal = p->getBalance();
					 bal -= 50;
					 p->setBalance(bal);
					 cout << "payout successful" << endl;
					// p->Move(p->getRolledSum());
					 p->setTurnsIL(0);
					 p->setInLine(0);
					 p->setRollDoublesCount(0);
					 p->setRollDoubles(0);
					 p->setinDanger(0);
					 break;
			  } else {
              cout << "gotta trade some stuff" << endl;
				  p->setinDanger(1);
				  sellOptionsDC_Tims_Line(p);
				  break;
			  }
		   } else {
             cout << "Invalid input!" << endl;
				 continue;
			}
		}
	 } else {
    cout << "you gotta roll double, use roll up rim or pay $50; type 'roll', to roll, 'use' to use rolluprim, and 'pay' to pay $50" << endl;
	 string respons;
 while (cin >> respons) {
    cout << "What would you like to do? 'roll', 'pay', 'use'?" << endl;
	 if (respons == "roll") {
    p->rollDice();
	 if (p->getRollDouble()) {
       cout << "awesome, you're out! you rolled a double" << endl;
		 //p->Move(p->getRolledSum());
		 p->setTurnsIL(0);
		 p->setInLine(0);
		 p->setRollDoublesCount(0);
		 p->setRollDoubles(1);
		 p->setinDanger(0);
		 break;
	  } else {
       cout << "Sorry, no double, better luck next time!" << endl;
		 break;
	  }
	} else if (respons == "pay") {
       if (p->getBalance() >= 50) {
          int bal = p->getBalance();
			 bal -= 50;
			 p->setBalance(bal);
			 cout << "Payout Successful! You're outta line!" << endl;
			 //p->Move(p->getRolledSum());
			 p->setTurnsIL(0);
			 p->setInLine(0);
			 p->setRollDoublesCount(0);
			 p->setRollDoubles(0);
			 p->setinDanger(0);
			 break;
		 } else {
         cout << "gotta sell some stuff maybe" << endl;
			p->setinDanger(1);
			sellOptionsDC_Tims_Line(p);
			break;
		 }
	} else if (respons == "use") {
          if (p->getNumRollup() > 0) { 
			  cout << "Awesome used up roll up rim!" << endl;
			  p->decNumRollUpRim();
			  //p->Move(p->getRolledSum());
			  p->setTurnsIL(0);
			  p->setInLine(0);
			  p->setRollDoublesCount(0);
			  p->setRollDoubles(0);
			  p->setinDanger(0);
		} else {
        cout << "Sorry, none left" << endl;
		  continue;
		}
     }
	}
  }
 } else {
   cout << "long lineeeeeeeeeeeeee" << endl;
  }
}

