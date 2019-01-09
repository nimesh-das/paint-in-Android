#include <iostream>
#include "academic.h"
#include "player.h"
#include <sstream>
using namespace std;

int Academic::MaxNumBlockAr1 = 2;
int Academic::MaxNumBlockAr2 = 3;
int Academic::MaxNumBlockEng = 3;
int Academic::MaxNumBlockHealth = 3;
int Academic::MaxNumBlockEnv = 3;
int Academic::MaxNumBlockSci1 = 3;
int Academic::MaxNumBlockSci2 = 3;
int Academic::MaxNumBlockMath = 2;

Academic::Academic(): Ownable(), Block(""), IC(0), num_improvements(0) {
		  for(int i = 0; i < 5; i++) {
					 tuition_perImprovement[i] = 0;
		  }
}
Academic::Academic(string name, int indexOnBoard, Board *leboard, int purchaseCost, int sellPrice, string Block, int IC): Ownable(name, indexOnBoard, leboard, purchaseCost, sellPrice), Block(Block), IC(IC), num_improvements(0) {
		 if (name == "AL") {
		   
			tuition_perImprovement[0] = 2;
			tuition_perImprovement[1] = 10;
			tuition_perImprovement[2] = 30;
			tuition_perImprovement[3] = 90;
			tuition_perImprovement[4] = 160;
			tuition_perImprovement[5] = 250;
		  
	 	 }
		    else if (name == "ML") {

			tuition_perImprovement[0] = 4;
			tuition_perImprovement[1] = 20;
			tuition_perImprovement[2] = 60;
			tuition_perImprovement[3] = 180;
			tuition_perImprovement[4] = 320;
			tuition_perImprovement[5] = 450;
     
		 }  else if (name == "ECH") {

		 	tuition_perImprovement[0] = 6;
			tuition_perImprovement[1] = 30;
			tuition_perImprovement[2] = 90;
			tuition_perImprovement[3] = 270;
			tuition_perImprovement[4] = 400;
			tuition_perImprovement[5] = 550;

		  } else if (name == "PAS") {

		  	tuition_perImprovement[0] = 6;
			tuition_perImprovement[1] = 30;
			tuition_perImprovement[2] = 90;
			tuition_perImprovement[3] = 270;
			tuition_perImprovement[4] = 400;
			tuition_perImprovement[5] = 550;

		  } else if (name == "HH") {

		  	tuition_perImprovement[0] = 8;
			tuition_perImprovement[1] = 40;
			tuition_perImprovement[2] = 100;
			tuition_perImprovement[3] = 300;
			tuition_perImprovement[4] = 450;
			tuition_perImprovement[5] = 600;

		  } else if (name == "RCH") {

		  	tuition_perImprovement[0] = 10;
			tuition_perImprovement[1] = 50;
			tuition_perImprovement[2] = 150;
			tuition_perImprovement[3] = 450;
			tuition_perImprovement[4] = 625;
			tuition_perImprovement[5] = 750;

		  } else if (name == "DWE") {

		  	tuition_perImprovement[0] = 10;
			tuition_perImprovement[1] = 50;
			tuition_perImprovement[2] = 150;
			tuition_perImprovement[3] = 450;
			tuition_perImprovement[4] = 625;
			tuition_perImprovement[5] = 750;

		  } else if (name == "CPH") {

		   tuition_perImprovement[0] = 12;
			tuition_perImprovement[1] = 60;
			tuition_perImprovement[2] = 180;
			tuition_perImprovement[3] = 500;
			tuition_perImprovement[4] = 700;
			tuition_perImprovement[5] = 900;

		  } else if (name == "LHI") {

		   tuition_perImprovement[0] = 14;
			tuition_perImprovement[1] = 70;
			tuition_perImprovement[2] = 200;
			tuition_perImprovement[3] = 550;
			tuition_perImprovement[4] = 750;
			tuition_perImprovement[5] = 950;

		  } else if (name == "BMH") {

		   tuition_perImprovement[0] = 14;
			tuition_perImprovement[1] = 70;
			tuition_perImprovement[2] = 200;
			tuition_perImprovement[3] = 550;
			tuition_perImprovement[4] = 750;
			tuition_perImprovement[5] = 950;

		  } else if (name == "OPT") {

		   tuition_perImprovement[0] = 16;
			tuition_perImprovement[1] = 80;
			tuition_perImprovement[2] = 220;
			tuition_perImprovement[3] = 600;
			tuition_perImprovement[4] = 800;
			tuition_perImprovement[5] = 1000;

		  } else if (name == "EV1") {

		   tuition_perImprovement[0] = 18;
			tuition_perImprovement[1] = 90;
			tuition_perImprovement[2] = 250;
			tuition_perImprovement[3] = 700;
			tuition_perImprovement[4] = 875;
			tuition_perImprovement[5] = 1050;

		  } else if (name == "EV2") {

		   tuition_perImprovement[0] = 18;
			tuition_perImprovement[1] = 90;
			tuition_perImprovement[2] = 250;
			tuition_perImprovement[3] = 700;
			tuition_perImprovement[4] = 875;
			tuition_perImprovement[5] = 1050;

		  } else if (name == "EV3") {

		   tuition_perImprovement[0] = 20;
			tuition_perImprovement[1] = 100;
			tuition_perImprovement[2] = 300;
			tuition_perImprovement[3] = 750;
			tuition_perImprovement[4] = 925;
			tuition_perImprovement[5] = 1100;

		  } else if (name == "PHYS") {

		   tuition_perImprovement[0] = 22;
			tuition_perImprovement[1] = 110;
			tuition_perImprovement[2] = 330;
			tuition_perImprovement[3] = 800;
			tuition_perImprovement[4] = 975;
			tuition_perImprovement[5] = 1150;

		  } else if (name == "B1") {

		   tuition_perImprovement[0] = 22;
			tuition_perImprovement[1] = 110;
			tuition_perImprovement[2] = 330;
			tuition_perImprovement[3] = 800;
			tuition_perImprovement[4] = 975;
			tuition_perImprovement[5] = 1150;

		  } else if (name == "B2") {

		   tuition_perImprovement[0] = 24;
			tuition_perImprovement[1] = 120;
			tuition_perImprovement[2] = 360;
			tuition_perImprovement[3] = 850;
			tuition_perImprovement[4] = 1025;
			tuition_perImprovement[5] = 1200;

		  } else if (name == "EIT") {

		   tuition_perImprovement[0] = 26;
			tuition_perImprovement[1] = 130;
			tuition_perImprovement[2] = 390;
			tuition_perImprovement[3] = 900;
			tuition_perImprovement[4] = 1100;
			tuition_perImprovement[5] = 1275;

		  } else if (name == "ESC") {

		   tuition_perImprovement[0] = 26;
			tuition_perImprovement[1] = 130;
			tuition_perImprovement[2] = 390;
			tuition_perImprovement[3] = 900;
			tuition_perImprovement[4] = 1100;
			tuition_perImprovement[5] = 1275;

		  } else if (name == "C2") {

		   tuition_perImprovement[0] = 28;
			tuition_perImprovement[1] = 150;
			tuition_perImprovement[2] = 450;
			tuition_perImprovement[3] = 1000;
			tuition_perImprovement[4] = 1200;
			tuition_perImprovement[5] = 1400;

		  } else if (name == "MC") {

		   tuition_perImprovement[0] = 35;
			tuition_perImprovement[1] = 175;
			tuition_perImprovement[2] = 500;
			tuition_perImprovement[3] = 1100;
			tuition_perImprovement[4] = 1300;
			tuition_perImprovement[5] = 1500;

		  } else if (name == "DC") {

		   tuition_perImprovement[0] = 50;
			tuition_perImprovement[1] = 200;
			tuition_perImprovement[2] = 600;
			tuition_perImprovement[3] = 1400;
			tuition_perImprovement[4] = 1700;
			tuition_perImprovement[5] = 2000;

		  } else {
           cout << "Sorry, wrong name for building" << endl;
		  }
}

//~Academic();

std::string Academic::getBlock() {
		  return Block;
}

int Academic::get_IC() {
		  return IC;
}

int Academic::getNum_Im() {
		  return num_improvements;
}

void Academic::setBlock(std::string blck) {
		  Block = blck;     
}

void Academic::set_IC(int ic) {
		  IC = ic;  
}

void Academic::setNum_Imp(int numIm) {
		  num_improvements = numIm;
}


int Academic::getMaxNumBlockAr1() {
		  return MaxNumBlockAr1;
}


int Academic::getMaxNumBlockAr2() {
		  return MaxNumBlockAr2;
}


int Academic::getMaxNumBlockEng() {
		  return MaxNumBlockEng;
}


int Academic::getMaxNumBlockHealth() {
		  return MaxNumBlockHealth; 
}


int Academic::getMaxNumBlockEnv() {
		  return MaxNumBlockEnv;
}

int Academic::getMaxNumBlockSci1() {
		  return MaxNumBlockSci1;
}


int Academic::getMaxNumBlockSci2() {
		  return MaxNumBlockSci2;
}


int Academic::getMaxNumBlockMath() {
		  return MaxNumBlockMath;
}


void Academic::setMaxNumBlockAr1(int numB) {
		  MaxNumBlockAr1 = numB;
}


void Academic::setMaxNumBlockAr2(int numB) {
		  MaxNumBlockAr2 = numB;
}

void Academic::setMaxNumBlockEng(int numB) {
		  MaxNumBlockEng = numB;
}


void Academic::setMaxNumBlockHealth(int numB) {
		  MaxNumBlockHealth = numB;
}

void Academic::setMaxNumBlockEnv(int numB) {
		  MaxNumBlockEnv = numB;
}


void Academic::setMaxNumBlockSci1(int numB) {
		  MaxNumBlockSci1 = numB;
}


void Academic::setMaxNumBlockSci2(int numB) {
		  MaxNumBlockSci2 = numB;
}

void Academic::setMaxNumBlockMath(int numB) {
		  MaxNumBlockMath = numB;
}


void Academic::QueryPlayer(Player *p) {
		  
        cout << "~~ Study hard fellas!~~ " << endl;

		  Player *owner = this->getOwner();
		  
		  if (this->isItMortgaged()) {
					 if (this->getOwner() == p) {
								cout << "You have this property mortgaged." << endl; 
								//cout << "Would you like to unmortgage it?" << endl;
								//string resp;
								//cin >> resp;
								//if (resp == "yes") {
                         //   unmortgageProperty(this);
								//} else {
                        //  cout << "OK, no problem!" << endl;
								//}
					 }   else {
								cout << "This property is mortgaged so " << p->getID() << " doesn't have to pay rent!" << endl; 
				}
		  }   
		  
		  //int amt = this->CalcRent();
		  
		  else if ((this->checkOwned()) && (owner != p)) {
		          int amt = this->CalcRent();
					 cout << "This residence is owned by " << owner->getID() << "." << endl;
					 cout << p->getID() << " has to pay a rent of amount of " << amt << "." << endl; 
					 if (p->getBalance() >= amt) {
					    p->payRentTo(owner, amt);
					 } else {
                  SellOptionsRent(p, owner, amt);
					 }
		  }
        
		  /*

		  else if (owner == p) {
             
				 if (getNum_Im() <= 4) {
                cout << "Would you like to improve this building?" << endl;
					 string response;
					 cin >> response;
					 if (response == "yes") {
					    cout << "Improvement made!" << endl;
                   p->buyImprovement(this);
					 } else {
                   cout << "Ok, no problem!" << endl;
					 }
				 }
             


		  }
		  */

		  /*

		  else if (!this->checkOwned()) {
					 if (p->canBuyProp(this)) {    
								cout << "This property is not owned! Would you like to buy it? The price of this building is " << this->getPrice() << " ." << endl;
								string response;
								cin >> response;
								if (response == "yes") {
										  p->buyProperty(this);
								}
					 } else {
								cout << "This property is not owned! So no rent fees!" << endl;
					 }
		  }
		  */
}

void Academic::SellOptionsRent(Player *p, Player *receiver, int rentAmount) { //
	
	if (p->getAssets() >= rentAmount) {
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
                                                     //cout << "Trade successful!" << endl;
																	  	p->makeTrade(smPl, smProp, amt);
																	  //continue;
															 } else {
                                                   cout << "Trade rejected. Sorry" << endl;
																	//this->SellOptionsRent(p, receiver, rentAmount);
																	continue;
															 }
 
									} else {
                              cout << "Invalid trade" << endl;
											 continue;
									}
								
								//p->makeTrade(smPl, smProp, amt);
								
								
								if (p->getBalance() >= (rentAmount)) {
										  cout << "Payout successful!" << endl;
										  p->decrBalance(rentAmount);
										  receiver->incrBalance(rentAmount);
										  break;
								} else {
										 cout << "Either not enough or something went wrong!" << endl;
										 continue;
										 // this->SellOptionsRent(p, receiver, rentAmount);
								}
					 } else if (word == "unimprove") {
								string prop2;
								ss >> prop2;
								Cell *smProp2 = WhichCell(prop2);
								p->sellImprovement(smProp2);
								if (p->getBalance() >= (rentAmount)) {
										  cout << "Payout successful!" << endl;
										  p->decrBalance(rentAmount);
										  receiver->incrBalance(rentAmount);
										  break;
								} else {
										  cout << "Sorry, not enough!" << endl;
										  continue;
										  //this->SellOptionsRent(p, receiver, rentAmount);
								}
					 }  else if (word == "sell") {
								string prop3;
								ss >> prop3;
								Cell *smProp3 = WhichCell(prop3);
								p->sellProperty(smProp3);
								if (p->getBalance() >= (rentAmount)) {
										  cout << "Payout successful!" << endl;
										  p->decrBalance(rentAmount);
										  receiver->incrBalance(rentAmount);
										  break;
								} else {
										cout << "Sorry, not enough!" << endl;
										continue;
										 // this->SellOptionsRent(p, receiver, rentAmount);
								}
					 }  else if (word == "mortgage") {
								string prop4;
								ss >> prop4;
								Cell *smProp4 = WhichCell(prop4);
								p->mortgage(smProp4);
								if (p->getBalance() >= (rentAmount)) {
										 cout << "Payout successful!" << endl;
										 p->decrBalance(rentAmount);
										  receiver->incrBalance(rentAmount);
										  break;
								} else {
										 cout << "Sorry, not enough!" << endl;
										 continue;
										  //this->SellOptionsRent(p, receiver, rentAmount);
								}
					 }
				}
		  } else {
					 cout << "You must declare bankruptcy. Not enough rent. Type in 'declareBankruptcy'" << endl;
					 string useless;
					 cin >> useless;
					 p->declareBankruptcy(receiver);
		  }
}


int Academic::CalcRent() {
		  if (this->checkOwned()) {
					 if (this->getNum_Im() == 0) {
								if (this->getCellName() == "AL") {
										  return 2;         
								} else if (this->getCellName() == "ML") {
										  return 4;
								} else if (this->getCellName() == "ECH") {
										  return 6;
								} else if (this->getCellName() == "PAS") {
										  return 6;
								} else if (this->getCellName() == "HH") {
										  return 8;
								} else if (this->getCellName() == "RCH") {
										  return 10;
								} else if (this->getCellName() == "DWE") {
										  return 10;
								} else if (this->getCellName() == "CPH") {
										  return 12;
								} else if (this->getCellName() == "LHI") {
										  return 14;
								} else if (this->getCellName() == "BMH") {
										  return 14;
								} else if (this->getCellName() == "OPT") {
										  return 16;
								} else if (this->getCellName() == "EV1") {
										  return 18;
								} else if (this->getCellName() == "EV2") {
										  return 18;
								} else if (this->getCellName() == "EV3") {
										  return 20;
								} else if (this->getCellName() == "PHYS") {
										  return 22;
								} else if (this->getCellName() == "B1") {
										  return 22;
								} else if (this->getCellName() == "B2") {
										  return 24;
								} else if (this->getCellName() == "EIT") {
										  return 26;
								} else if (this->getCellName() == "ESC") {
										  return 26;
								} else if (this->getCellName() == "C2") {
										  return 28;
								} else if (this->getCellName() == "MC") {
										  return 35;
								} else if (this->getCellName() == "DC") {
										  return 50;
								}
					 } else if (this->getNum_Im() == 1) {
								if (this->getCellName() == "AL") {
										  return 10;         
								} else if (this->getCellName() == "ML") {
										  return 20;
								} else if (this->getCellName() == "ECH") {
										  return 30;
								} else if (this->getCellName() == "PAS") {
										  return 30;
								} else if (this->getCellName() == "HH") {
										  return 40;
								} else if (this->getCellName() == "RCH") {
										  return 50;
								} else if (this->getCellName() == "DWE") {
										  return 50;
								} else if (this->getCellName() == "CPH") {
										  return 60;
								} else if (this->getCellName() == "LHI") {
										  return 70;
								} else if (this->getCellName() == "BMH") {
										  return 70;
								} else if (this->getCellName() == "OPT") {
										  return 80;
								} else if (this->getCellName() == "EV1") {
										  return 90;
								} else if (this->getCellName() == "EV2") {
										  return 90;
								} else if (this->getCellName() == "EV3") {
										  return 100;
								} else if (this->getCellName() == "PHYS") {
										  return 110;
								} else if (this->getCellName() == "B1") {
										  return 110;
								} else if (this->getCellName() == "B2") {
										  return 120;
								} else if (this->getCellName() == "EIT") {
										  return 130;
								} else if (this->getCellName() == "ESC") {
										  return 130;
								} else if (this->getCellName() == "C2") {
										  return 150;
								} else if (this->getCellName() == "MC") {
										  return 175;
								} else if (this->getCellName() == "DC") {
										  return 200;
								}
					 } else if (this->getNum_Im() == 2) {
								if (this->getCellName() == "AL") {
										  return 30;         
								} else if (this->getCellName() == "ML") {
										  return 60;
								} else if (this->getCellName() == "ECH") {
										  return 90;
								} else if (this->getCellName() == "PAS") {
										  return 90;
								} else if (this->getCellName() == "HH") {
										  return 100;
								} else if (this->getCellName() == "RCH") {
										  return 150;
								} else if (this->getCellName() == "DWE") {
										  return 150;
								} else if (this->getCellName() == "CPH") {
										  return 180;
								} else if (this->getCellName() == "LHI") {
										  return 200;
								} else if (this->getCellName() == "BMH") {
										  return 200;
								} else if (this->getCellName() == "OPT") {
										  return 220;
								} else if (this->getCellName() == "EV1") {
										  return 250;
								} else if (this->getCellName() == "EV2") {
										  return 250;
								} else if (this->getCellName() == "EV3") {
										  return 300;
								} else if (this->getCellName() == "PHYS") {
										  return 330;
								} else if (this->getCellName() == "B1") {
										  return 330;
								} else if (this->getCellName() == "B2") {
										  return 360;
								} else if (this->getCellName() == "EIT") {
										  return 390;
								} else if (this->getCellName() == "ESC") {
										  return 390;
								} else if (this->getCellName() == "C2") {
										  return 450;
								} else if (this->getCellName() == "MC") {
										  return 500;
								} else if (this->getCellName() == "DC") {
										  return 600;
								}
					 } else if (this->getNum_Im() == 4) {
								if (this->getCellName() == "AL") {
										  return 160;         
								} else if (this->getCellName() == "ML") {
										  return 320;
								} else if (this->getCellName() == "ECH") {
										  return 400;
								} else if (this->getCellName() == "PAS") {
										  return 400;
								} else if (this->getCellName() == "HH") {
										  return 450;
								} else if (this->getCellName() == "RCH") {
										  return 625;
								} else if (this->getCellName() == "DWE") {
										  return 625;
								} else if (this->getCellName() == "CPH") {
										  return 700;
								} else if (this->getCellName() == "LHI") {
										  return 750;
								} else if (this->getCellName() == "BMH") {
										  return 750;
								} else if (this->getCellName() == "OPT") {
										  return 800;
								} else if (this->getCellName() == "EV1") {
										  return 875;
								} else if (this->getCellName() == "EV2") {
										  return 875;
								} else if (this->getCellName() == "EV3") {
										  return 925;
								} else if (this->getCellName() == "PHYS") {
										  return 975;
								} else if (this->getCellName() == "B1") {
										  return 975;
								} else if (this->getCellName() == "B2") {
										  return 1025;
								} else if (this->getCellName() == "EIT") {
										  return 1100;
								} else if (this->getCellName() == "ESC") {
										  return 1100;
								} else if (this->getCellName() == "C2") {
										  return 1200;
								} else if (this->getCellName() == "MC") {
										  return 1300;
								} else if (this->getCellName() == "DC") {
										  return 1700;
								}
					 } else if (this->getNum_Im() == 5) {
								if (this->getCellName() == "AL") {
										  return 250;         
								} else if (this->getCellName() == "ML") {
										  return 450;
								} else if (this->getCellName() == "ECH") {
										  return 550;
								} else if (this->getCellName() == "PAS") {
										  return 550;
								} else if (this->getCellName() == "HH") {
										  return 600;
								} else if (this->getCellName() == "RCH") {
										  return 750;
								} else if (this->getCellName() == "DWE") {
										  return 750;
								} else if (this->getCellName() == "CPH") {
										  return 900;
								} else if (this->getCellName() == "LHI") {
										  return 950;
								} else if (this->getCellName() == "BMH") {
										  return 950;
								} else if (this->getCellName() == "OPT") {
										  return 1000;
								} else if (this->getCellName() == "EV1") {
										  return 1050;
								} else if (this->getCellName() == "EV2") {
										  return 1050;
								} else if (this->getCellName() == "EV3") {
										  return 1100;
								} else if (this->getCellName() == "PHYS") {
										  return 1150;
								} else if (this->getCellName() == "B1") {
										  return 1150;
								} else if (this->getCellName() == "B2") {
										  return 1200;
								} else if (this->getCellName() == "EIT") {
										  return 1275;
								} else if (this->getCellName() == "ESC") {
										  return 1400;
								} else if (this->getCellName() == "C2") {
										  return 1500;
								} else if (this->getCellName() == "MC") {
										  return 2000;
								} else if (this->getCellName() == "DC") {
										  return 200;
								}
					 }
		  } else {
					 return 0;
		  }
}

