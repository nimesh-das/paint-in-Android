#include <iostream>
#include "tuition.h"
#include "player.h"
#include <sstream>
using namespace std;

Tuition::Tuition(): Unownable() { }

Tuition::Tuition(string cellName, int indexOfProperty, Board *leboard): Unownable(cellName, indexOfProperty, leboard) { }


void Tuition::QueryPlayer(Player *p) {
      
		float bal = p->getBalance();
		float as = p->getAssets();
		float networth = bal+as;

     cout << p->getID() << " needs to pay $300 or 10% of their total worth immediately to the bank." << endl;
	  cout << p->getID() << " has total networth of amount " << networth << "." << endl;
	  cout << "Would you like to pay $300 ('pay300') or pay 10% ('pay10') ?" << endl;

	  string response;
	 while(cin >> response) {
	  //int networth = p->getAssets() + p->getBalance();
 	  if (response == "pay300") {
        if (p->getBalance() >= 300) {
		      cout << "Player " << p->getID() << " decided to pay $300." << endl;
		      int bal = p->getBalance();
				//int as = p->getAssets();
				bal -= 300;
				//as -= 300;
				p->setBalance(bal);
				break;
				//p->setAssets(as);
		  } else {
          cout << "Sorry, not enough money. You must pay 10% of your total net worth." << endl;
			 //int networth = p->getAssets() + p->getBalance();
			 if (p->getBalance() >= (networth/10)) {
           cout << "Payout successful. 10% paid." << endl;
				int bal = p->getBalance();
		  		//int as = p->getAssets();
		  		int tenPerc = networth/10;
				bal -= tenPerc;
				//as -= tenPerc;
				p->setBalance(bal);
				break;
		  		//p->setAssets(as);   
			 } else {
            cout << "Sorry, your balance is less than 10% of your total assets." << endl;
				SellOptionsTuition(p);
				break;
			 }
			 //as -= 0.1*as;
			 //p->setAssets(as);
		  }
	  } else if (response == "pay10") {
        cout << "Player will attempt to pay 10%." << endl;
		  if (p->getBalance() >= (networth/10)) {
		  		cout << "Payout successful. 10% paid." << endl;
				int bal = p->getBalance();
		  		//int as = p->getAssets();
		  		int tenPerc = networth/10;
				bal -= tenPerc;
				//as -= tenPerc;
				p->setBalance(bal);
				break;
		  		//p->setAssets(as);
	  } else {
           cout << "Sorry, your balance is less than 10% of your total assets." << endl;
			  SellOptionsTuition(p);
			  break;
	  }
	} else {
      cout << "Invalid input!" << endl;
		continue;
	}
  }
}

void Tuition::SellOptionsTuition(Player *p) { //
		  
		  float assets = p->getAssets();
		  
		  if (assets > 0) {
					 cout << "You need cash. You can get it by selling a property or an improvement, mortgaging some property, ";
					 cout << "or by trading property for money. What would you like to do? If you'd like to trade, type in 'trade player property amount', otherwise to sell improvement";
					 cout << " type in 'unimprove property', to sell a property, type in 'sell property', and finally to mortgage a property, type in 'mortgage property'." << endl;
					 string inp;
		while (getline(cin, inp)) {
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
                                                     cout << "Trade successful!" << endl;
																	  	p->makeTrade(smPl, smProp, amt);
																		//break;
																	  //continue;
															 } else {
                                                   cout << "Trade rejected. Sorry" << endl;
																	//this->SellOptionsTuition(p);
																	continue;
																	//continue;
															 }
 
								} else {
                               cout << "Invalid trade" << endl;
										 continue;
								}

								
							//	p->makeTrade(smPl, smProp, amt);
								
								
								if (p->getBalance() >= (assets/10)) {
										  cout << "Payout successful!" << endl;
										  int bal = p->getBalance();
										  bal -= (assets/10);
										  p->setBalance(bal);
										  // assets -= (assets*0.1);
										  break;
								} else {
										  //this->SellOptionsTuition(p);
										  cout << "Sorry, transaction not successful or not enough still!" << endl;
										  continue;
								}
					 } else if (word == "unimprove") {
								string prop2;
								ss >> prop2;
								Cell *smProp2 = WhichCell(prop2);
								p->sellImprovement(smProp2);
								if (p->getBalance() >= (assets/10)) {
										  cout << "Payout successful!" << endl;
										  int bal = p->getBalance();
										  bal -= (assets/10);
										  p->setBalance(bal);
										  break;
										  //balance -= (assets*0.1);
										  //  assets -= (assets*0.1);
								} else {
										 // this->SellOptionsTuition(p);
										 cout << "Sorry, transaction not successful or not enough still!" << endl;
										 continue;
								}
					 }  else if (word == "sell") {
								string prop3;
								ss >> prop3;
								Cell *smProp3 = WhichCell(prop3);
								p->sellProperty(smProp3);
								if (p->getBalance() >= (assets/10)) {
										  cout << "Payout successful!" << endl;
										  int bal = p->getBalance();
										  bal -= (assets/10);
										  p->setBalance(bal);
										  break;
										  //balance -= (assets*0.1);
										  //  assets -= (assets*0.1);
								} else {
								      cout << "Sorry, transaction not successful or not enough still!" << endl;
										 continue;
										 // this->SellOptionsTuition(p);
								}
					 }  else if (word == "mortgage") {
								string prop4;
								ss >> prop4;
								Cell *smProp4 = WhichCell(prop4);
								p->mortgage(smProp4);
						   	if (p->getBalance() >= (assets/10)) {
										  cout << "Payout successful!" << endl;
										  int bal = p->getBalance();
										  bal -= (assets/10);
										  p->setBalance(bal);
										  break;
										  //balance -= (assets*0.1);
										  //  assets -= (assets*0.1);
								} else {
										  cout << "Sorry, transaction not successful or not enough still!" << endl;
										  continue;
										  //this->SellOptionsTuition(p);
								}
					 } else {
                   cout << "invalid input." << endl;
						 continue;
					 }
				}
		  } else {
					 cout << "You must declare bankruptcy. Tuition fees are expensive. Type in 'declareBankruptcy" << endl;
					 string res;
					 cin >> res;
					 p->declareBankruptcy();
		  }
}
