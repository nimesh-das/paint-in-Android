#include <iostream>
#include "player.h"
#include "board.h"
#include "die.h"
#include "cell.h"
#include <sstream>
using namespace std;

Player *Player::player1 = NULL;
Player *Player::player2 = NULL;
Player *Player::player3 = NULL;
Player *Player::player4 = NULL;
Player *Player::player5 = NULL;
Player *Player::player6 = NULL;
Board *Player::gameBoard = NULL;

Player::Player(): balance(1500), assets(0), id('X'), name("X"), dice(NULL), x(0), y(0), inLine(0), position(0), lastposition(0), lastx(0), lasty(0), numRollUpRim(0), numResidence(0), turnsIL(0), numGyms(0), numProperties(0), rolledSum(0), rollDoubles(0), RollDoubleCount(0), ThirdTurnFree(0), canRoll(1), dormant(0), danger(0) { 
		  //  cout << "player being created" << endl;
		  for(int i = 0; i < 28; i++) {
					 OwnedProperties[i] = NULL;
					 //	  cout << "ownedproperties" << endl;
		  }
} //

void Player::setName(string name) {
		  this->name = name;
}

bool Player::isDormant() {
     return dormant;
}

bool Player::getCanRoll() {
     return canRoll;
}

void Player::setCanRoll(bool canroll) {
     this->canRoll = canroll;
}

int Player::getLastPosn() {
		  return lastposition;
}

void Player::setLastPosn(int pos) {
		  lastposition = pos;
}

void Player::setRolledSum(int sum) {
		  rolledSum = sum;
} //

int Player::rollDice() { 
		  //     cout << "so we try to roll dice" << endl;
		  rolledSum = dice->toss();
		  return rolledSum;
}//

void Player::setDice(Die *dice) { 
		  this->dice = dice;
}//

void Player::cleanup1() { 
		  delete player1;
}//

void Player::cleanup2() { 
		  delete player2;
}//

void Player::cleanup3() { 
		  delete player3;
}//

void Player::cleanup4() { 
		  delete player4;
}//

void Player::cleanup5() { 
		  delete player5;
}//

void Player::cleanup6() { 
		  delete player6;
}//

int Player::getBalance() { 
		  return balance;
}//

int Player::getNetWorth() { 
		  return assets; 
}//

void Player::printAllPropertiesOwned() { 
		  for(int i = 0; i < numProperties; i++) {
					 cout << this->id << " has " << OwnedProperties[i]->getCellName() << " ";
		  }
		  cout << endl;
}//

char Player::getID() { 
		  return id;
}//

bool Player::canDeclareBankruptcy() { 
		  if (assets < 0) {
					 return 1;
		  } else {
					 return 0;
		  }
}//

Player *Player::getPlayer1() { 
		  if (!player1) {
					 player1 = new Player();
					 atexit(cleanup1);
		  }

		  return player1;
}//

Player *Player::getPlayer2() { 
		  if (!player2) {
					 player2 = new Player();
					 atexit(cleanup2);
		  }

		  return player2;
}//

void Player::IncRollDoublesCount() {
		  RollDoubleCount++;
}//

void Player::IncTurnsIL() {
		  turnsIL++;
}//

int Player::getTurnsIL() {
		  return turnsIL;
}//

void Player::setTurnsIL(int turns) {
		  turnsIL = turns;
}//

void Player::setRollDoubles(bool rolldoub) {
		  rollDoubles = rolldoub;
}//


void Player::decNumRollUpRim() {
		  numRollUpRim--;
}//

int Player::getRollDoublesCount() {
		  return RollDoubleCount;
}//

void Player::setRollDoublesCount(int rdc) {
		  RollDoubleCount = rdc;
}//

int Player::getThirdTurnFree() {
		  return ThirdTurnFree;
}//

void Player::setThirdTurnFree(bool ttf) {
		  ThirdTurnFree = ttf;
}//


Player *Player::getPlayer3() { 
		  if (!player3) {
					 player3 = new Player();
					 atexit(cleanup3);
		  }

		  return player3;
}//

Player *Player::getPlayer4() { 
		  if (!player4) {
					 player4 = new Player();
					 atexit(cleanup4);
		  }

		  return player4;
}//

Player *Player::getPlayer5() { 
		  if (!player5) {
					 player5 = new Player();
					 atexit(cleanup5);
		  }

		  return player5;
}//


Player *Player::getPlayer6() { 

		  if (!player6) {
					 player6 = new Player();
					 atexit(cleanup6);
		  }

		  return player6;

}//


void Player::calculate_coordinates() { 
		  this->lastx = this->x;
		  this->lasty = this->y;

		  if (position == 0) {
					 if (gameBoard->board[55][82] == ' ' ) {
								gameBoard->board[55][82] = this->id;
								this->x = 55;
								this->y = 82;
					 } else if (gameBoard->board[55][83] == ' ') {
								gameBoard->board[55][83] = this->id;
								this->x = 55;
								this->y = 83;
					 } else if (gameBoard->board[55][84] == ' ') {
								gameBoard->board[55][84] = this->id;
								this->x = 55;
								this->y = 84;
					 } else if (gameBoard->board[55][85] == ' ') {
								gameBoard->board[55][85] = this->id;
								this->x = 55;
								this->y = 85;
					 } else if (gameBoard->board[56][82] == ' ') {
								gameBoard->board[56][82] = this->id;
								this->x = 56;
								this->y = 82;
					 } else if (gameBoard->board[56][83] == ' ') {
								gameBoard->board[56][83] = this->id;
								this->x = 56;
								this->y = 83;
					 }
		  } else if (position == 1) {
					 if (gameBoard->board[55][76] == ' ') {
								gameBoard->board[55][76] = this->id;
								this->x = 55;
								this->y = 76;
					 } else if (gameBoard->board[55][77] == ' ') {
								gameBoard->board[55][77] = this->id;
								this->x = 55;
								this->y = 77;
					 } else if (gameBoard->board[55][78] == ' ') {
								gameBoard->board[55][78] = this->id;
								this->x = 55;
								this->y = 78;
					 } else if (gameBoard->board[56][74] == ' ') {
								gameBoard->board[56][74] = this->id;
								this->x = 56;
								this->y = 74;
					 } else if (gameBoard->board[56][75] == ' ') {
								gameBoard->board[56][75] = this->id;
								this->x = 56;
								this->y = 75;
					 } else if (gameBoard->board[56][76] == ' ') {
								gameBoard->board[56][76] = this->id;
								this->x = 56;
								this->y = 76;
					 }
		  } else if (position == 2) { 
					 if (gameBoard->board[55][66] == ' ') {
								gameBoard->board[55][66] = this->id;
								this->x = 55;
								this->y = 66;
					 } else if (gameBoard->board[55][67] == ' ') {
								gameBoard->board[55][67] = this->id;
								this->x = 55;
								this->y = 67;
					 } else if (gameBoard->board[55][68] == ' ') {
								gameBoard->board[55][68] = this->id;
								this->x = 55;
								this->y = 68;
					 } else if (gameBoard->board[55][69] == ' ') {
								gameBoard->board[55][69] = this->id;
								this->x = 55;
								this->y = 69;
					 } else if (gameBoard->board[56][66] == ' ') {
								gameBoard->board[56][66] = this->id;
								this->x = 56;
								this->y = 66;
					 } else if (gameBoard->board[56][67] == ' ') {
								gameBoard->board[56][67] = this->id;
								this->x = 56;
								this->y = 67;
					 }
		  } else if (position == 3) {
					 if (gameBoard->board[55][60] == ' ') {
								gameBoard->board[55][60] = this->id;
								this->x = 55;
								this->y = 60;
					 } else if (gameBoard->board[55][61] == ' ') {
								gameBoard->board[55][61] = this->id;
								this->x = 55;
								this->y = 61;
					 } else if (gameBoard->board[55][62] == ' ') {
								gameBoard->board[55][62] = this->id;
								this->x = 55;
								this->y = 62;
					 } else if (gameBoard->board[56][60] == ' ') {
								gameBoard->board[56][60] = this->id;
								this->x = 56;
								this->y = 60;
					 } else if (gameBoard->board[56][61] == ' ') {
								gameBoard->board[56][61] = this->id;
								this->x = 56;
								this->y = 61;
					 } else if (gameBoard->board[56][62] == ' ') {
								gameBoard->board[56][62] = this->id;
								this->x = 56;
								this->y = 62;
					 }
		  } else if (position == 4) {
					 if (gameBoard->board[55][50] == ' ') {
								gameBoard->board[55][50] = this->id;
								this->x = 55;
								this->y = 50;
					 } else if (gameBoard->board[55][51] == ' ') {
								gameBoard->board[55][51] = this->id;
								this->x = 55;
								this->y = 51;
					 } else if (gameBoard->board[55][52] == ' ') {
								gameBoard->board[55][52] = this->id;
								this->x = 55;
								this->y = 52;
					 } else if (gameBoard->board[55][53] == ' ') {
								gameBoard->board[55][53] = this->id;
								this->x = 55;
								this->y = 53;
					 } else if (gameBoard->board[56][50] == ' ') {
								gameBoard->board[56][50] = this->id;
								this->x = 56;
								this->y = 50;
					 } else if (gameBoard->board[56][51] == ' ') {
								gameBoard->board[56][51] = this->id;
								this->x = 56;
								this->y = 51;
					 }
		  } else if (position == 5) {
					 if (gameBoard->board[55][42] == ' ') {
								gameBoard->board[55][42] = this->id;
								this->x = 55;
								this->y = 42;
					 } else if (gameBoard->board[55][43] == ' ') {
								gameBoard->board[55][43] = this->id;
								this->x = 55;
								this->y = 43;
					 } else if (gameBoard->board[55][44] == ' ') {
								gameBoard->board[55][44] = this->id;
								this->x = 55;
								this->y = 44;
					 } else if (gameBoard->board[55][45] == ' ') {
								gameBoard->board[55][45] = this->id;
								this->x = 55;
								this->y = 45;
					 } else if (gameBoard->board[56][42] == ' ') {
								gameBoard->board[56][42] = this->id;
								this->x = 56;
								this->y = 42;
					 } else if (gameBoard->board[56][43] == ' ') {
								gameBoard->board[56][43] = this->id;
								this->x = 56;
								this->y = 43;
					 }
		  } else if (position == 6) {
					 if (gameBoard->board[55][37] == ' ') {
								gameBoard->board[55][37] = this->id;
								this->x = 55;
								this->y = 37;
					 } else if (gameBoard->board[55][38] == ' ') {
								gameBoard->board[55][38] = this->id;
								this->x = 55;
								this->y = 38;
					 } else if (gameBoard->board[56][33] == ' ') {
								gameBoard->board[56][33] = this->id;
								this->x = 56;
								this->y = 33;
					 } else if (gameBoard->board[56][34] == ' ') {
								gameBoard->board[56][34] = this->id;
								this->x = 56;
								this->y = 34;
					 } else if (gameBoard->board[56][35] == ' ') {
								gameBoard->board[56][35] = this->id;
								this->x = 56;
								this->y = 35;
					 } else if (gameBoard->board[56][36] == ' ') {
								gameBoard->board[56][36] = this->id;
								this->x = 56;
								this->y = 36;
					 }
		  } else if (position == 7) {
					 //    cout << "So we go to pos 7? " << endl;
					 if (gameBoard->board[55][26] == ' ') {
								//    cout << "a" << endl;
								gameBoard->board[55][26] = this->id;
								cout << gameBoard->board[55][26] << endl;
								this->x = 55;
								this->y = 26;
					 } else if (gameBoard->board[55][27] == ' ') {
								gameBoard->board[55][27] = this->id;
								//  cout << "b" << endl;
								this->x = 55;
								this->y = 27;
					 } else if (gameBoard->board[55][28] == ' ') {
								gameBoard->board[55][28] = this->id;
								this->x = 55;
								this->y = 28;
					 } else if (gameBoard->board[55][29] == ' ') {
								gameBoard->board[55][29] = this->id;
								this->x = 55;
								this->y = 29;
					 } else if (gameBoard->board[55][30] == ' ') {
								gameBoard->board[55][30] = this->id;
								this->x = 55;
								this->y = 30;
					 } else if (gameBoard->board[56][31] == ' ') {
								gameBoard->board[56][31] = this->id;
								this->x = 56;
								this->y = 31;
					 }
		  } else if (position == 8) {
					 if (gameBoard->board[55][21] == ' ') {
								gameBoard->board[55][21] = this->id;
								this->x = 55;
								this->y = 21;
					 } else if (gameBoard->board[55][22] == ' ') {
								gameBoard->board[55][22] = this->id;
								this->x = 55;
								this->y = 22;
					 } else if (gameBoard->board[56][17] == ' ') {
								gameBoard->board[56][17] = this->id;
								this->x = 56;
								this->y = 17;
					 } else if (gameBoard->board[56][18] == ' ') {
								gameBoard->board[56][18] = this->id;
								this->x = 56;
								this->y = 18;
					 } else if (gameBoard->board[56][19] == ' ') {
								gameBoard->board[56][19] = this->id;
								this->x = 56;
								this->y = 19;
					 } else if (gameBoard->board[56][20] == ' ') {
								gameBoard->board[56][20] = this->id;
								this->x = 56;
								this->y = 20;
					 }
		  } else if (position == 9) {
					 if (gameBoard->board[55][12] == ' ') {
								gameBoard->board[55][12] = this->id;
								this->x = 55;
								this->y = 12;
					 } else if (gameBoard->board[55][13] == ' ') {
								gameBoard->board[55][13] = this->id;
								this->x = 55;
								this->y = 13;
					 } else if (gameBoard->board[55][14] == ' ') {
								gameBoard->board[55][14] = this->id;
								this->x = 55;
								this->y = 14;
					 } else if (gameBoard->board[56][12] == ' ') {
								gameBoard->board[56][12] = this->id;
								this->x = 56;
								this->y = 12;
					 } else if (gameBoard->board[56][13] == ' ') {
								gameBoard->board[56][13] = this->id;
								this->x = 56;
								this->y = 13;
					 } else if (gameBoard->board[56][14] == ' ') {
								gameBoard->board[56][14] = this->id;
								this->x = 56;
								this->y = 14;
					 }
		  } else if (position == 10) {
					 if (gameBoard->board[55][2] == ' ') {
								gameBoard->board[55][2] = this->id;
								this->x = 55;
								this->y = 2;
					 } else if (gameBoard->board[55][3] == ' ') {
								gameBoard->board[55][3] = this->id;
								this->x = 55;
								this->y = 3;
					 } else if (gameBoard->board[55][4] == ' ') {
								gameBoard->board[55][4] = this->id;
								this->x = 55;
								this->y = 4;
					 } else if (gameBoard->board[55][5] == ' ') {
								gameBoard->board[55][5] = this->id;
								this->x = 55;
								this->y = 5;
					 } else if (gameBoard->board[55][6] == ' ') {
								gameBoard->board[55][6] = this->id;
								this->x = 55;
								this->y = 6;
					 } else if (gameBoard->board[56][2] == ' ') {
								gameBoard->board[56][2] = this->id;
								this->x = 56;
								this->y = 2;
					 }
		  } else if (position == 11) {
					 if (gameBoard->board[50][2] == ' ') {
								gameBoard->board[50][2] = this->id;
								this->x = 50;
								this->y = 2;
					 } else if (gameBoard->board[50][3] == ' ') {
								gameBoard->board[50][3] = this->id;
								this->x = 50;
								this->y = 3;
					 } else if (gameBoard->board[50][4] == ' ') {
								gameBoard->board[50][4] = this->id;
								this->x = 50;
								this->y = 4;
					 } else if (gameBoard->board[50][5] == ' ') {
								gameBoard->board[50][5] = this->id;
								this->x = 50;
								this->y = 5;
					 } else if (gameBoard->board[50][6] == ' ') {
								gameBoard->board[50][6] = this->id;
								this->x = 50;
								this->y = 6;
					 } else if (gameBoard->board[51][2] == ' ') {
								gameBoard->board[51][2] = this->id;
								this->x = 51;
								this->y = 2;
					 }
		  } else if (position == 12) {
					 if (gameBoard->board[44][2] == ' ') {
								gameBoard->board[44][2] = this->id;
								this->x = 44;
								this->y = 2;
					 } else if (gameBoard->board[44][3] == ' ') {
								gameBoard->board[44][3] = this->id;
								this->x = 44;
								this->y = 3;
					 } else if (gameBoard->board[44][4] == ' ') {
								gameBoard->board[44][4] = this->id;
								this->x = 44;
								this->y = 4;
					 } else if (gameBoard->board[44][5] == ' ') {
								gameBoard->board[44][5] = this->id;
								this->x = 44;
								this->y = 5;
					 } else if (gameBoard->board[44][6] == ' ') {
								gameBoard->board[44][6] = this->id;
								this->x = 44;
								this->y = 6;
					 } else if (gameBoard->board[45][2] == ' ') {
								gameBoard->board[45][2] = this->id;
								this->x = 45;
								this->y = 2;
					 }
		  } else if (position == 13) {
					 if (gameBoard->board[38][5] == ' ') {
								gameBoard->board[38][5] = this->id;
								this->x = 38;
								this->y = 5;
					 } else if (gameBoard->board[38][6] == ' ') {
								gameBoard->board[38][6] = this->id;
								this->x = 38;
								this->y = 6;
					 } else if (gameBoard->board[39][2] == ' ') {
								gameBoard->board[39][2] = this->id;
								this->x = 39;
								this->y = 2;
					 } else if (gameBoard->board[39][3] == ' ') {
								gameBoard->board[39][3] = this->id;
								this->x = 39;
								this->y = 3;
					 } else if (gameBoard->board[39][4] == ' ') {
								gameBoard->board[39][4] = this->id;
								this->x = 39;
								this->y = 4;
					 } else if (gameBoard->board[39][5] == ' ') {
								gameBoard->board[39][5] = this->id;
								this->x = 39;
								this->y = 5;
					 }
		  } else if (position == 14) {
					 if (gameBoard->board[33][5] == ' ') {
								gameBoard->board[33][5] = this->id;
								this->x = 33;
								this->y = 5;
					 } else if (gameBoard->board[33][6] == ' ') {
								gameBoard->board[33][6] = this->id;
								this->x = 33;
								this->y = 6;
					 } else if (gameBoard->board[34][2] == ' ') {
								gameBoard->board[34][2] = this->id;
								this->x = 34;
								this->y = 2;
					 } else if (gameBoard->board[34][3] == ' ') {
								gameBoard->board[34][3] = this->id;
								this->x = 34;
								this->y = 3;
					 } else if (gameBoard->board[34][4] == ' ') {
								gameBoard->board[34][4] = this->id;
								this->x = 34;
								this->y = 4;
					 } else if (gameBoard->board[34][5] == ' ') {
								gameBoard->board[34][5] = this->id;
								this->x = 34;
								this->y = 5;
					 }
		  } else if (position == 15) {
					 if (gameBoard->board[28][2] == ' ') {
								gameBoard->board[28][2] = this->id;
								this->x = 28;
								this->y = 2;
					 } else if (gameBoard->board[28][3] == ' ') {
								gameBoard->board[28][3] = this->id;
								this->x = 28;
								this->y = 3;
					 } else if (gameBoard->board[28][4] == ' ') {
								gameBoard->board[28][4] = this->id;
								this->x = 28;
								this->y = 4;
					 } else if (gameBoard->board[28][5] == ' ') {
								gameBoard->board[28][5] = this->id;
								this->x = 28;
								this->y = 5;
					 } else if (gameBoard->board[28][6] == ' ') {
								gameBoard->board[28][6] = this->id;
								this->x = 28;
								this->y = 6;
					 } else if (gameBoard->board[29][2] == ' ') {
								gameBoard->board[29][2] = this->id;
								this->x = 29;
								this->y = 2;
					 }
		  } else if (position == 16) {
					 if (gameBoard->board[23][5] == ' ') {
								gameBoard->board[23][5] = this->id;
								this->x = 23;
								this->y = 5;
					 } else if (gameBoard->board[23][6] == ' ') {
								gameBoard->board[23][6] = this->id;
								this->x = 23;
								this->y = 6;
					 } else if (gameBoard->board[24][2] == ' ') {
								gameBoard->board[24][2] = this->id;
								this->x = 24;
								this->y = 2;
					 } else if (gameBoard->board[24][3] == ' ') {
								gameBoard->board[24][3] = this->id;
								this->x = 24;
								this->y = 3;
					 } else if (gameBoard->board[24][4] == ' ') {
								gameBoard->board[24][4] = this->id;
								this->x = 24;
								this->y = 4;
					 } else if (gameBoard->board[24][5] == ' ') {
								gameBoard->board[24][5] = this->id;
								this->x = 24;
								this->y = 5;
					 }
		  } else if (position == 17) {
					 if (gameBoard->board[18][2] == ' ') {
								gameBoard->board[18][2] = this->id;
								this->x = 18;
								this->y = 2;
					 } else if (gameBoard->board[18][3] == ' ') {
								gameBoard->board[18][3] = this->id;
								this->x = 18;
								this->y = 3;
					 } else if (gameBoard->board[18][4] == ' ') {
								gameBoard->board[18][4] = this->id;
								this->x = 18;
								this->y = 4;
					 } else if (gameBoard->board[18][5] == ' ') {
								gameBoard->board[18][5] = this->id;
								this->x = 18;
								this->y = 5;
					 } else if (gameBoard->board[19][2] == ' ') {
								gameBoard->board[19][2] = this->id;
								this->x = 19;
								this->y = 2;
					 } else if (gameBoard->board[19][3] == ' ') {
								gameBoard->board[19][3] = this->id;
								this->x = 19;
								this->y = 3;
					 }
		  } else if (position == 18) {
					 if (gameBoard->board[13][5] == ' ') {
								gameBoard->board[13][5] = this->id;
								this->x = 13;
								this->y = 5;
					 } else if (gameBoard->board[13][6] == ' ') {
								gameBoard->board[13][6] = this->id;
								this->x = 13;
								this->y = 6;
					 } else if (gameBoard->board[14][2] == ' ') {
								gameBoard->board[14][2] = this->id;
								this->x = 14;
								this->y = 2;
					 } else if (gameBoard->board[14][3] == ' ') {
								gameBoard->board[14][3] = this->id;
								this->x = 14;
								this->y = 3;
					 } else if (gameBoard->board[14][4] == ' ') {
								gameBoard->board[14][4] = this->id;
								this->x = 14;
								this->y = 4;
					 } else if (gameBoard->board[14][5] == ' ') {
								gameBoard->board[14][5] = this->id;
								this->x = 14;
								this->y = 5;
					 }
		  } else if (position == 19) {
					 if (gameBoard->board[8][5] == ' ') {
								gameBoard->board[8][5] = this->id;
								this->x = 8;
								this->y = 5;
					 } else if (gameBoard->board[8][6] == ' ') {
								gameBoard->board[8][6] = this->id;
								this->x = 8;
								this->y = 6;
					 } else if (gameBoard->board[9][2] == ' ') {
								gameBoard->board[9][2] = this->id;
								this->x = 9;
								this->y = 2;
					 } else if (gameBoard->board[9][3] == ' ') {
								gameBoard->board[9][3] = this->id;
								this->x = 9;
								this->y = 3;
					 } else if (gameBoard->board[9][4] == ' ') {
								gameBoard->board[9][4] = this->id;
								this->x = 9;
								this->y = 4;
					 } else if (gameBoard->board[9][5] == ' ') {
								gameBoard->board[9][5] = this->id;
								this->x = 9;
								this->y = 5;
					 }
		  } else if (position == 20) {
					 if (gameBoard->board[4][1] == ' ') {
								gameBoard->board[4][1] = this->id;
								this->x = 4;
								this->y = 1;
					 } else if (gameBoard->board[4][2] == ' ') {
								gameBoard->board[4][2] = this->id;
								this->x = 4;
								this->y = 2;
					 } else if (gameBoard->board[4][3] == ' ') {
								gameBoard->board[4][3] = this->id;
								this->x = 4;
								this->y = 3;
					 } else if (gameBoard->board[4][4] == ' ') {
								gameBoard->board[4][4] = this->id;
								this->x = 4;
								this->y = 4;
					 } else if (gameBoard->board[5][1] == ' ') {
								gameBoard->board[5][1] = this->id;
								this->x = 5;
								this->y = 1;
					 } else if (gameBoard->board[5][2] == ' ') {
								gameBoard->board[5][2] = this->id;
								this->x = 5;
								this->y = 2;
					 } 
		  } else if (position == 21) {
					 if (gameBoard->board[4][10] == ' ') {
								gameBoard->board[4][10] = this->id;
								this->x = 4;
								this->y = 10;
					 } else if (gameBoard->board[4][11] == ' ') {
								gameBoard->board[4][11] = this->id;
								this->x = 4;
								this->y = 11;
					 } else if (gameBoard->board[4][12] == ' ') {
								gameBoard->board[4][12] = this->id;
								this->x = 4;
								this->y = 12;
					 } else if (gameBoard->board[4][13] == ' ') {
								gameBoard->board[4][13] = this->id;
								this->x = 4;
								this->y = 13;
					 } else if (gameBoard->board[4][14] == ' ') {
								gameBoard->board[4][14] = this->id;
								this->x = 4;
								this->y = 14;
					 } else if (gameBoard->board[5][10] == ' ') {
								gameBoard->board[5][10] = this->id;
								this->x = 5;
								this->y = 10;
					 }
		  } else if (position == 22) {
					 if (gameBoard->board[4][18] == ' ') {
								gameBoard->board[4][18] = this->id;
								this->x = 4;
								this->y = 18;
					 } else if (gameBoard->board[4][19] == ' ') {
								gameBoard->board[4][19] = this->id;
								this->x = 4;
								this->y = 19;
					 } else if (gameBoard->board[4][20] == ' ') {
								gameBoard->board[4][20] = this->id;
								this->x = 4;
								this->y = 20;
					 } else if (gameBoard->board[4][21] == ' ') {
								gameBoard->board[4][21] = this->id;
								this->x = 4;
								this->y = 21;
					 } else if (gameBoard->board[4][22] == ' ') {
								gameBoard->board[4][22] = this->id;
								this->x = 4;
								this->y = 22;
					 } else if (gameBoard->board[5][18] == ' ') {
								gameBoard->board[5][18] = this->id;
								this->x = 5;
								this->y = 18;
					 }
		  } else if (position == 23) {
					 if (gameBoard->board[4][26] == ' ') {
								gameBoard->board[4][26] = this->id;
								this->x = 4;
								this->y = 26;
					 } else if (gameBoard->board[4][27] == ' ') {
								gameBoard->board[4][27] = this->id;
								this->x = 4;
								this->y = 27;
					 } else if (gameBoard->board[4][28] == ' ') {
								gameBoard->board[4][28] = this->id;
								this->x = 4;
								this->y = 28;
					 } else if (gameBoard->board[4][29] == ' ') {
								gameBoard->board[4][29] = this->id;
								this->x = 4;
								this->y = 29;
					 } else if (gameBoard->board[4][30] == ' ') {
								gameBoard->board[4][30] = this->id;
								this->x = 4;
								this->y = 30;
					 } else if (gameBoard->board[5][26] == ' ') {
								gameBoard->board[5][26] = this->id;
								this->x = 5;
								this->y = 26;
					 }
		  } else if (position == 24) {
					 if (gameBoard->board[4][34] == ' ') {
								gameBoard->board[4][34] = this->id;
								this->x = 4;
								this->y = 34;
					 } else if (gameBoard->board[4][35] == ' ') {
								gameBoard->board[4][35] = this->id;
								this->x = 4;
								this->y = 35;
					 } else if (gameBoard->board[4][36] == ' ') {
								gameBoard->board[4][36] = this->id;
								this->x = 4;
								this->y = 36;
					 } else if (gameBoard->board[4][37] == ' ') {
								gameBoard->board[4][37] = this->id;
								this->x = 4;
								this->y = 37;
					 } else if (gameBoard->board[4][38] == ' ') {
								gameBoard->board[4][38] = this->id;
								this->x = 4;
								this->y = 38;
					 } else if (gameBoard->board[5][34] == ' ') {
								gameBoard->board[5][34] = this->id;
								this->x = 5;
								this->y = 34;
					 }
		  } else if (position == 25) {
					 if (gameBoard->board[4][42] == ' ') {
								gameBoard->board[4][42] = this->id;
								this->x = 4;
								this->y = 42;
					 } else if (gameBoard->board[4][43] == ' ') {
								gameBoard->board[4][43] = this->id;
								this->x = 4;
								this->y = 43;
					 } else if (gameBoard->board[4][44] == ' ') {
								gameBoard->board[4][44] = this->id;
								this->x = 4;
								this->y = 44;
					 } else if (gameBoard->board[4][45] == ' ') {
								gameBoard->board[4][45] = this->id;
								this->x = 4;
								this->y = 45;
					 } else if (gameBoard->board[4][46] == ' ') {
								gameBoard->board[4][46] = this->id;
								this->x = 4;
								this->y = 46;
					 } else if (gameBoard->board[5][42] == ' ') {
								gameBoard->board[5][42] = this->id;
								this->x = 5;
								this->y = 42;
					 }
		  } else if (position == 26) {
					 if (gameBoard->board[4][50] == ' ') {
								gameBoard->board[4][50] = this->id;
								this->x = 4;
								this->y = 50;
					 } else if (gameBoard->board[4][51] == ' ') {
								gameBoard->board[4][51] = this->id;
								this->x = 4;
								this->y = 51;
					 } else if (gameBoard->board[4][52] == ' ') {
								gameBoard->board[4][52] = this->id;
								this->x = 4;
								this->y = 52;
					 } else if (gameBoard->board[4][53] == ' ') {
								gameBoard->board[4][53] = this->id;
								this->x = 4;
								this->y = 53;
					 } else if (gameBoard->board[4][54] == ' ') {
								gameBoard->board[4][54] = this->id;
								this->x = 4;
								this->y = 54;
					 } else if (gameBoard->board[5][50] == ' ') {
								gameBoard->board[5][50] = this->id;
								this->x = 5;
								this->y = 50;
					 }
		  } else if (position == 27) {
					 if (gameBoard->board[4][58] == ' ') {
								gameBoard->board[4][58] = this->id;
								this->x = 4;
								this->y = 58;
					 } else if (gameBoard->board[4][59] == ' ') {
								gameBoard->board[4][59] = this->id;
								this->x = 4;
								this->y = 59;
					 } else if (gameBoard->board[4][60] == ' ') {
								gameBoard->board[4][60] = this->id;
								this->x = 4;
								this->y = 60;
					 } else if (gameBoard->board[4][61] == ' ') {
								gameBoard->board[4][61] = this->id;
								this->x = 4;
								this->y = 61;
					 } else if (gameBoard->board[4][62] == ' ') {
								gameBoard->board[4][62] = this->id;
								this->x = 4;
								this->y = 62;
					 } else if (gameBoard->board[5][58] == ' ') {
								gameBoard->board[5][58] = this->id;
								this->x = 5;
								this->y = 58;
					 }
		  } else if (position == 28) {
					 if (gameBoard->board[4][66] == ' ') {
								gameBoard->board[4][66] = this->id;
								this->x = 4;
								this->y = 66;
					 } else if (gameBoard->board[4][67] == ' ') {
								gameBoard->board[4][67] = this->id;
								this->x = 4;
								this->y = 67;
					 } else if (gameBoard->board[4][68] == ' ') {
								gameBoard->board[4][68] = this->id;
								this->x = 4;
								this->y = 68;
					 } else if (gameBoard->board[4][69] == ' ') {
								gameBoard->board[4][69] = this->id;
								this->x = 4;
								this->y = 69;
					 } else if (gameBoard->board[4][70] == ' ') {
								gameBoard->board[4][70] = this->id;
								this->x = 4;
								this->y = 70;
					 } else if (gameBoard->board[5][66] == ' ') {
								gameBoard->board[5][66] = this->id;
								this->x = 5;
								this->y = 66;
					 }
		  } else if (position == 29) {
					 if (gameBoard->board[4][74] == ' ') {
								gameBoard->board[4][74] = this->id;
								this->x = 4;
								this->y = 74;
					 } else if (gameBoard->board[4][75] == ' ') {
								gameBoard->board[4][75] = this->id;
								this->x = 4;
								this->y = 75;
					 } else if (gameBoard->board[4][76] == ' ') {
								gameBoard->board[4][76] = this->id;
								this->x = 4;
								this->y = 76;
					 } else if (gameBoard->board[4][77] == ' ') {
								gameBoard->board[4][77] = this->id;
								this->x = 4;
								this->y = 77;
					 } else if (gameBoard->board[4][78] == ' ') {
								gameBoard->board[4][78] = this->id;
								this->x = 4;
								this->y = 78;
					 } else if (gameBoard->board[5][74] == ' ') {
								gameBoard->board[5][74] = this->id;
								this->x = 5;
								this->y = 74;
					 }
		  } else if (position == 30) {
					 if (gameBoard->board[4][82] == ' ') {
								gameBoard->board[4][82] = this->id;
								this->x = 4;
								this->y = 82;
					 } else if (gameBoard->board[4][83] == ' ') {
								gameBoard->board[4][83] = this->id;
								this->x = 4;
								this->y = 83;
					 } else if (gameBoard->board[4][84] == ' ') {
								gameBoard->board[4][84] = this->id;
								this->x = 4;
								this->y = 84;
					 } else if (gameBoard->board[4][85] == ' ') {
								gameBoard->board[4][85] = this->id;
								this->x = 4;
								this->y = 85;
					 } else if (gameBoard->board[4][86] == ' ') {
								gameBoard->board[4][86] = this->id;
								this->x = 4;
								this->y = 86;
					 } else if (gameBoard->board[5][82] == ' ') {
								gameBoard->board[5][82] = this->id;
								this->x = 5;
								this->y = 82;
					 }
		  } else if (position == 31) {
					 if (gameBoard->board[9][82] == ' ') {
								gameBoard->board[9][82] = this->id;
								this->x = 9;
								this->y = 82;
					 } else if (gameBoard->board[9][83] == ' ') {
								gameBoard->board[9][83] = this->id;
								this->x = 9;
								this->y = 83;
					 } else if (gameBoard->board[9][84] == ' ') {
								gameBoard->board[9][84] = this->id;
								this->x = 9;
								this->y = 84;
					 } else if (gameBoard->board[9][85] == ' ') {
								gameBoard->board[9][85] = this->id;
								this->x = 9;
								this->y = 85;
					 } else if (gameBoard->board[9][86] == ' ') {
								gameBoard->board[9][86] = this->id;
								this->x = 9;
								this->y = 86;
					 } else if (gameBoard->board[10][82] == ' ') {
								gameBoard->board[10][82] = this->id;
								this->x = 10;
								this->y = 82;
					 }
		  } else if (position == 32) {
					 if (gameBoard->board[14][82] == ' ') {
								gameBoard->board[14][82] = this->id;
								this->x = 14;
								this->y = 82;
					 } else if (gameBoard->board[14][83] == ' ') {
								gameBoard->board[14][83] = this->id;
								this->x = 14;
								this->y = 83;
					 } else if (gameBoard->board[14][84] == ' ') {
								gameBoard->board[14][84] = this->id;
								this->x = 14;
								this->y = 84;
					 } else if (gameBoard->board[14][85] == ' ') {
								gameBoard->board[14][85] = this->id;
								this->x = 14;
								this->y = 85;
					 } else if (gameBoard->board[14][86] == ' ') {
								gameBoard->board[14][86] = this->id;
								this->x = 14;
								this->y = 86;
					 } else if (gameBoard->board[14][82] == ' ') {
								gameBoard->board[14][82] = this->id;
								this->x = 14;
								this->y = 83;
					 }
		  } else if (position == 33) {
					 if (gameBoard->board[19][82] == ' ') {
								gameBoard->board[19][82] = this->id;
								this->x = 19;
								this->y = 82;
					 } else if (gameBoard->board[19][83] == ' ') {
								gameBoard->board[19][83] = this->id;
								this->x = 19;
								this->y = 83;
					 } else if (gameBoard->board[19][84] == ' ') {
								gameBoard->board[19][84] = this->id;
								this->x = 19;
								this->y = 84;
					 } else if (gameBoard->board[19][85] == ' ') {
								gameBoard->board[19][85] = this->id;
								this->x = 19;
								this->y = 85;
					 } else if (gameBoard->board[19][86] == ' ') {
								gameBoard->board[19][86] = this->id;
								this->x = 19;
								this->y = 86;
					 } else if (gameBoard->board[20][82] == ' ') {
								gameBoard->board[20][82] = this->id;
								this->x = 20;
								this->y = 82;
					 }
		  } else if (position == 34) {
					 if (gameBoard->board[24][82] == ' ') {
								gameBoard->board[24][82] = this->id;
								this->x = 24;
								this->y = 82;
					 } else if (gameBoard->board[24][83] == ' ') {
								gameBoard->board[24][83] = this->id;
								this->x = 24;
								this->y = 83;
					 } else if (gameBoard->board[24][84] == ' ') {
								gameBoard->board[24][84] = this->id;
								this->x = 24;
								this->y = 84;
					 } else if (gameBoard->board[24][85] == ' ') {
								gameBoard->board[24][85] = this->id;
								this->x = 24;
								this->y = 85;
					 } else if (gameBoard->board[24][86] == ' ') {
								gameBoard->board[24][86] = this->id;
								this->x = 24;
								this->y = 86;
					 } else if (gameBoard->board[25][82] == ' ') {
								gameBoard->board[25][82] = this->id;
								this->x = 25;
								this->y = 82;
					 }
		  } else if (position == 35) {
					 if (gameBoard->board[29][82] == ' ') {
								gameBoard->board[29][82] = this->id;
								this->x = 29;
								this->y = 82;
					 } else if (gameBoard->board[29][83] == ' ') {
								gameBoard->board[29][83] = this->id;
								this->x = 29;
								this->y = 83;
					 } else if (gameBoard->board[29][84] == ' ') {
								gameBoard->board[29][84] = this->id;
								this->x = 29;
								this->y = 84;
					 } else if (gameBoard->board[29][85] == ' ') {
								gameBoard->board[29][85] = this->id;
								this->x = 29;
								this->y = 85;
					 } else if (gameBoard->board[29][86] == ' ') {
								gameBoard->board[29][86] = this->id;
								this->x = 29;
								this->y = 86;
					 } else if (gameBoard->board[30][82] == ' ') {
								gameBoard->board[30][82] = this->id;
								this->x = 30;
								this->y = 82;
					 }
		  } else if (position == 36) {
					 if (gameBoard->board[34][82] == ' ') {
								gameBoard->board[34][82] = this->id;
								this->x = 34;
								this->y = 82;
					 } else if (gameBoard->board[34][83] == ' ') {
								gameBoard->board[34][83] = this->id;
								this->x = 34;
								this->y = 83;
					 } else if (gameBoard->board[34][84] == ' ') {
								gameBoard->board[34][84] = this->id;
								this->x = 34;
								this->y = 84;
					 } else if (gameBoard->board[34][85] == ' ') {
								gameBoard->board[34][85] = this->id;
								this->x = 34;
								this->y = 85;
					 } else if (gameBoard->board[34][86] == ' ') {
								gameBoard->board[34][86] = this->id;
								this->x = 34;
								this->y = 86;
					 } else if (gameBoard->board[35][82] == ' ') {
								gameBoard->board[35][82] = this->id;
								this->x = 35;
								this->y = 82;
					 }
		  } else if (position == 37) {
					 if (gameBoard->board[39][82] == ' ') {
								gameBoard->board[39][82] = this->id;
								this->x = 39;
								this->y = 82;
					 } else if (gameBoard->board[39][83] == ' ') {
								gameBoard->board[39][83] = this->id;
								this->x = 39;
								this->y = 83;
					 } else if (gameBoard->board[39][84] == ' ') {
								gameBoard->board[39][84] = this->id;
								this->x = 39;
								this->y = 84;
					 } else if (gameBoard->board[39][85] == ' ') {
								gameBoard->board[39][85] = this->id;
								this->x = 39;
								this->y = 85;
					 } else if (gameBoard->board[39][86] == ' ') {
								gameBoard->board[39][86] = this->id;
								this->x = 39;
								this->y = 86;
					 } else if (gameBoard->board[40][82] == ' ') {
								gameBoard->board[40][82] = this->id;
								this->x = 40;
								this->y = 82;
					 }
		  } else if (position == 38) {
					 if (gameBoard->board[44][82] == ' ') {
								gameBoard->board[44][82] = this->id;
								this->x = 44;
								this->y = 82;
					 } else if (gameBoard->board[44][83] == ' ') {
								gameBoard->board[44][83] = this->id;
								this->x = 44;
								this->y = 83;
					 } else if (gameBoard->board[44][84] == ' ') {
								gameBoard->board[44][84] = this->id;
								this->x = 44;
								this->y = 84;
					 } else if (gameBoard->board[44][85] == ' ') {
								gameBoard->board[44][85] = this->id;
								this->x = 44;
								this->y = 85;
					 } else if (gameBoard->board[44][86] == ' ') {
								gameBoard->board[44][86] = this->id;
								this->x = 44;
								this->y = 86;
					 } else if (gameBoard->board[45][82] == ' ') {
								gameBoard->board[45][82] = this->id;
								this->x = 45;
								this->y = 82;
					 }
		  } else if (position == 39) {
					 if (gameBoard->board[50][82] == ' ') {
								gameBoard->board[50][82] = this->id;
								this->x = 50;
								this->y = 82;
					 } else if (gameBoard->board[50][83] == ' ') {
								gameBoard->board[50][83] = this->id;
								this->x = 50;
								this->y = 83;
					 } else if (gameBoard->board[50][84] == ' ') {
								gameBoard->board[50][84] = this->id;
								this->x = 50;
								this->y = 84;
					 } else if (gameBoard->board[50][85] == ' ') {
								gameBoard->board[50][85] = this->id;
								this->x = 50;
								this->y = 85;
					 } else if (gameBoard->board[50][86] == ' ') {
								gameBoard->board[50][86] = this->id;
								this->x = 50;
								this->y = 86;
					 } else if (gameBoard->board[51][82] == ' ') {
								gameBoard->board[51][82] = this->id;
								this->x = 51;
								this->y = 82;
					 }
		  }

		  //cout << "x: " << this->x << endl;
		  //cout << "y: " << this->y << endl;
}

void Player::setBoard(Board *gameBoard) {
		  this->gameBoard = gameBoard;
} //


void Player::Move() { //
		  // cout << "IN MOVE" << endl;
		  if (!this->amIinline()) { 
					 lastposition = this->position;
					 gameBoard->lastMoved = this;
					 gameBoard->board[x][y] = ' ';
					 // cout << "x: " << x << "y: " << y << endl;
					 // cout << "old_pos: " << old_position << endl;
					 if ((lastposition + this->rolledSum) >= 40) {
								collectOsap();
					 }
					 this->position = (lastposition + this->rolledSum) % 40;
					 // cout << "new pos: " << position << endl;
					 this->calculate_coordinates();
					 // cout << "calculating coordinates!" << endl;
					 gameBoard->updateTotalTurns();
					 gameBoard->calcWhosTurn();
		  } else {
					 gameBoard->lastMoved = this;
					 gameBoard->updateTotalTurns();
					 gameBoard->calcWhosTurn();
		  }
}

void Player::incrBalance(int amt) {//
		  balance += amt;
		  //assets += amt;
}

void Player::decrBalance(int amt) {//
		  balance -= amt;
		  //	assets -= amt;
}

void Player::Move(int steps) {//
		  // cout << "IN MOVE" << endl;
		  if (!this->amIinline()) { 
					 lastposition = this->position;
					 gameBoard->lastMoved = this;
					 gameBoard->board[x][y] = ' ';
					 // cout << "x: " << x << "y: " << y << endl;
					 // cout << "old_pos: " << old_position << endl;
					 if ((lastposition + steps) > 40) {
								collectOsap();
					 }
                
					 if ((lastposition + steps) < 0) {
                    steps += 40;
						  this->position = lastposition + steps;
					 } else {
                    this->position = (lastposition + steps) % 40;
					 }
					 // cout << "new pos: " << position << endl;
					 this->calculate_coordinates();
					 // cout << "calculating coordinates!" << endl;
					// gameBoard->updateTotalTurns();
					 //gameBoard->printBoard();
					// gameBoard->calcWhosTurn();
		  } else {
					 gameBoard->lastMoved = this;
					 //gameBoard->updateTotalTurns();
					 //gameBoard->calcWhosTurn();
		  }
}

void Player::collectOsap() {
		  	cout << "Player " << id << " has completed a full square around the Building Buyer 7000 board. They collect $200 Osap. " << endl;
		  balance += 200;
		  //	assets += 200;
}//

Player *Player::giveMePlayerOnStr(std::string player) {
		  if (player == "player1") {
					 return getPlayer1();
		  } else if (player == "player2") {
					 return getPlayer2();
		  } else if (player == "player3") {
					 return getPlayer3();
		  } else if (player == "player4") {
					 return getPlayer4();
		  } else if (player == "player5") {
					 return getPlayer5();
		  } else {
					 return getPlayer6();
		  }
}//

Cell *Player::giveMeOwndPropertyOnStr(std::string prop) {
		  for(int i = 0; i < 28; i++) {
					 if (OwnedProperties[i]->getCellName() == prop) {
								return OwnedProperties[i];
					 }
		  }
		  return NULL;
}//


/*
void Player::SellOptionsRent(Player *receiver, int rentAmount) { //
		  if (assets >= rentAmount) {
					 cout << "You need cash for rent. You can get it by selling a property or an improvement, mortgaging some property, ";
					 cout << "or by trading property for money. What would you like to do? If you'd like to trade, type in 'makeTrade player property amount', otherwise to sell improvement";
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
								Player *smPl = giveMePlayerOnStr(playr);
								Cell *smProp = giveMeOwndPropertyOnStr(prop);
								makeTrade(smPl, smProp, amt);
								if (balance >= (rentAmount)) {
										  decrBalance(rentAmount);
										  receiver->incrBalance(rentAmount);
								} else {
										  this->SellOptionsRent(receiver, rentAmount);
								}
					 } else if (word == "unimprove") {
								string prop2;
								ss >> prop2;
								Cell *smProp2 = giveMeOwndPropertyOnStr(prop2);
								sellImprovement(smProp2);
								if (balance >= (rentAmount)) {
										  decrBalance(rentAmount);
										  receiver->incrBalance(rentAmount);
								} else {
										  this->SellOptionsRent(receiver, rentAmount);
								}
					 }  else if (word == "sell") {
								string prop3;
								ss >> prop3;
								Cell *smProp3 = giveMeOwndPropertyOnStr(prop3);
								sellProperty(smProp3);
								if (balance >= (rentAmount)) {
										  decrBalance(rentAmount);
										  receiver->incrBalance(rentAmount);
								} else {
										  this->SellOptionsRent(receiver, rentAmount);
								}
					 }  else if (word == "mortgage") {
								string prop4;
								ss >> prop4;
								Cell *smProp4 = giveMeOwndPropertyOnStr(prop4);
								mortgage(smProp4);
								if (balance >= (rentAmount)) {
										  decrBalance(rentAmount);
										  receiver->incrBalance(rentAmount);
								} else {
										  this->SellOptionsRent(receiver, rentAmount);
								}
					 }
		  } else {
					 cout << "You must declare bankruptcy. Not enough rent. Type in 'declareBankruptcy'" << endl;
					 string useless;
					 cin >> useless;
					 declareBankruptcy();
		  }
}
*/


void Player::sellOptionsDC_Tims_Line() {
		  if (assets > 50) {
					 cout << "You need cash. You can get it by selling a property or an improvement, mortgaging some property, ";
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
								Player *smPl = giveMePlayerOnStr(playr);
								Cell *smProp = giveMeOwndPropertyOnStr(prop);
								makeTrade(smPl, smProp, amt);
								if (balance >= 50) {

										  balance -= 50;
										  //  assets -= 50;
										  this->setInLine(0);
										  this->setThirdTurnFree(0);
								} else {
										  this->sellOptionsDC_Tims_Line();
										  cout << "You're free!" << endl;
								}
					 } else if (word == "unimprove") {
								string prop2;
								ss >> prop2;
								Cell *smProp2 = giveMeOwndPropertyOnStr(prop2);
								sellImprovement(smProp2);
								if (balance >= 50) {
										  balance -= 50;
										  // assets -= 50;
										  this->setInLine(0);
										  this->setThirdTurnFree(0);
										  cout << "You're free!" << endl;
								} else {
										  this->sellOptionsDC_Tims_Line();
								}
					 }  else if (word == "sell") {
								string prop3;
								ss >> prop3;
								Cell *smProp3 = giveMeOwndPropertyOnStr(prop3);
								sellProperty(smProp3);
								if (balance >= 50) {
										  balance -= 50;
										  // assets -= 50;
										  this->setInLine(0);
										  this->setThirdTurnFree(0);
										  cout << "You're free!" << endl;
								} else {
										  this->sellOptionsDC_Tims_Line();
								}
					 }  else if (word == "mortgage") {
								string prop4;
								ss >> prop4;
								Cell *smProp4 = giveMeOwndPropertyOnStr(prop4);
								mortgage(smProp4);
								if (balance >= 50) {
										  balance -= 50;
										  //  assets -= 50;
										  this->setInLine(0);
										  this->setThirdTurnFree(0);
										  cout << "You're free!" << endl;
								} else {
										  this->sellOptionsDC_Tims_Line();
								}
					 }
		  } else {
					 cout << "You must declare bankruptcy. Not enough for DC TIMS. Type in 'declareBankruptcy" << endl;
					 string garbage;
					 cin >> garbage;
					 declareBankruptcy();
		  }
}

/*
void Player::SellOptionsTuition() { //
		  if (assets > 0) {
					 cout << "You need cash. You can get it by selling a property or an improvement, mortgaging some property, ";
					 cout << "or by trading property for money. What would you like to do? If you'd like to trade, type in 'makeTrade player property amount', otherwise to sell improvement";
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
								Player *smPl = giveMePlayerOnStr(playr);
								Cell *smProp = giveMeOwndPropertyOnStr(prop);
								makeTrade(smPl, smProp, amt);
								if (balance >= (assets*0.1)) {
										  balance -= (assets*0.1);
										  // assets -= (assets*0.1);
								} else {
										  this->SellOptionsTuition();
								}
					 } else if (word == "unimprove") {
								string prop2;
								ss >> prop2;
								Cell *smProp2 = giveMeOwndPropertyOnStr(prop2);
								sellImprovement(smProp2);
								if (balance >= (assets*0.1)) {
										  balance -= (assets*0.1);
										  //  assets -= (assets*0.1);
								} else {
										  this->SellOptionsTuition();
								}
					 }  else if (word == "sell") {
								string prop3;
								ss >> prop3;
								Cell *smProp3 = giveMeOwndPropertyOnStr(prop3);
								sellProperty(smProp3);
								if (balance >= (assets*0.1)) {
										  balance -= (assets*0.1);
										  // assets -= (assets*0.1);
								} else {
										  this->SellOptionsTuition();
								}
					 }  else if (word == "mortgage") {
								string prop4;
								ss >> prop4;
								Cell *smProp4 = giveMeOwndPropertyOnStr(prop4);
								mortgage(smProp4);
								if (balance >= (assets*0.1)) {
										  balance -= (assets*0.1);
										  // assets -= (assets*0.1);
								} else {
										  this->SellOptionsTuition();
								}
					 }
		  } else {
					 cout << "You must declare bankruptcy. Tuition fees are expensive. Type in 'declareBankruptcy" << endl;
					 declareBankruptcy();
		  }
}
*/


void Player::MoveToTims() {
		  lastposition = this->position;
		  gameBoard->lastMoved = this;
		  gameBoard->board[x][y] = ' ';
		  this->position = 10;
		  this->setInLine(1);
		  //this->setCanRoll(0);
		  this->calculate_coordinates();
		  //gameBoard->updateTotalTurns();
		  //gameBoard->calcWhosTurn();
} //

void Player::MoveToCollectOsap() {
       lastposition = this->position;
		 gameBoard->lastMoved = this;
		 gameBoard->board[x][y] = ' ';
		 this->position = 0;
		 this->calculate_coordinates();
}

bool Player::getRollDouble() { //
		  return rollDoubles;
} 

void Player::setnumRollup(int numRoll) {  //
		  numRollUpRim = numRoll;
} 

void Player::setPosn(int x, int y) {  //
		  lastx = this->x;
		  lasty = this->y;
		  this->x = x;
		  this->y = y;
} 

void Player::setAssets(int assets) {
		  this->assets = assets;
} //

void Player::setID(char ID) {
		  this->id = ID;
} //

int Player::getRolledSum() {
		  return rolledSum;
} //

void Player::setInLine(bool iL) {
		  inLine = iL;//
}//

void Player::incNumProperties() { 
		  numProperties++;
}//

//bool canBuyProp(Cell *property);

void Player::incNumResidence() {
      numResidence++;
}

void Player::incNumGyms() {
      numGyms++;
}

void Player::buyProperty(Cell *property) { //

		  if (canBuyProp(property)) {
					 //if (getPlayerPosition() == property->getCellName()) {
					 OwnedProperties[numProperties] = property;
					 numProperties++;
					 property->setOwner(this);
					 property->setOwnerID(this->getID());
					 property->setOwned(true);
					 balance -= property->getPriceToBuy();
					 assets += property->getPriceToBuy();
					 if ((property->getCellName() == "UWP") || (property->getCellName() == "V1") || (property->getCellName() == "MKV") || (property->getCellName() == "REV")) {
                        numResidence++;
					 }
					 if ((property->getCellName() == "PAC") || (property->getCellName() == "CIF")) {
                        numGyms++;
					 }
					 cout << "Congratulations, Player " << this->getID() << ", you have just bought " << property->getCellName() << "." << endl;
					 cout << "Your balance is: " << this->getBalance() << "." << endl;
					 cout << "Your assets are: " << this->getAssets() << "." << endl;
					 printAllPropertiesOwned();
					 //	} else {
					 //cout << "You can't buy this property, because you need to be on it to buy it!" << endl;
					 //	}
		  } else {
					 cout << "Sorry, cannot buy this property" << endl;
		  }
}

bool Player::canSellProp(Cell *property) { 

		  if (this == property->getOwner()) {
					 if (!property->isItMortgaged()) {
								if ((getPlayerPosition() == property->getCellName()) || (inDanger())) {
										  if (property->getNum_Im() <= 0) {
										      return true;
										  } else {
                                   cout << "All improvements must be sold before selling properties!" << endl;
										  }
								} else {
                            cout << "Position off. You need to be on the property to sell it, unless you're in danger!" << endl; 
								}
					 } else {
                  cout << "Property can't be mortgaged as you're trying to sell it!" << endl;
					 }
		  } else {
          cout << "Not the owner!" << endl;
		  }

		  return false;
}//

bool Player::inDanger() {
   return danger;
}

void Player::setinDanger(bool danger) {
   this->danger = danger; 
}

void Player::sellProperty(Cell *property) { 
		  if (canSellProp(property)) {
					 property->setOwner(NULL);
					 property->setOwnerID('X');
					 property->setOwned(false);
					 balance += property->getSellPrice();
					 assets -= property->getPriceToBuy();
					 removeProperty(property);
					 cout << "Player " << this->getID() << ", you have just sold " << property->getCellName() << "." << endl;
					 cout << "Your balance is: " << this->getBalance() << "." << endl;
					 cout << "Your assets are: " << this->getAssets() << "." << endl;
		  } else {
					 cout << "You cannot sell this property" << endl;
		  }
}//

int Player::checkPropertyPrice(Cell *property) { 
		  return property->getPriceToBuy();
} //


int Player::checkPropertyIC(Cell *property) { 
		  return property->get_IC();
} //

int Player::checkPropertyRent(Cell *property) { 
		  return property->getRent();
} //


void Player::buyImprovement(Cell *property) { 
		  cout << "are we even going here" << endl;
		  if (CanBuyImprovement(property)) {
					cout << "Did we go inside the can!" << endl;
					 gameBoard->improveProp(property);
					 int numIm = property->getNum_Im();
					 numIm++;
					 property->setNum_Imp(numIm);
					 balance-= property->get_IC();
					 assets += property->get_IC();
					 cout << "Congratulations, you have purchased an improvement on " << property->getCellName() << " ." << endl;
					 gameBoard->printBoard();
		  }
} //

void Player::sellImprovement(Cell *property) { 
		  if (CanSellImprovement(property)) {
					 gameBoard->unimproveProp(property);
					 int numIm = property->getNum_Im();
					 numIm--;
					 property->setNum_Imp(numIm);
					 balance+= ((property->get_IC()) / 2);
					 assets -= ((property->get_IC()) / 2);
					 cout << "You have sold an improvement on " << property->getCellName() << " ." << endl;
					 gameBoard->printBoard();
		  }
} //

bool Player::CanBuyImprovement(Cell *property) { 
		  cout << "Yea so what's going on here guys?!" << endl;
		  string blck = property->getBlock();
		  cout << "blck: " << blck << endl;
		  cout << "Wer here tho?" << endl;
		  if (haveMonopoly(blck)) {
		  cout << "what about here?!" << endl;
					 if (!inLine) {
					 cout << "Or here?" << endl;
								if (balance >= property->get_IC()) {
								cout << "or herereerere" << endl;
										  if (property->getNum_Im() <= 4) {
													 if (getPlayerPosition() == property->getCellName()) {
																return true;
													 } else {
																cout << "in order to make improvements, you have to be on the property" << endl;
													 }
										  } else {
													 cout << "Sorry, maxed out all improvements!" << endl;
										  }
								} else {
										  cout << "Sorry, not enough money!" << endl;
										  return 0;
								}
					 } else {
								cout << "Sorry, you're in line!" << endl;
								return 0;
					 }
		  } else {
					 cout << "Sorry, in order to buy improvements, you need to own a monopoly" << endl;
					 return false; 
		  }


		  return false;

} //


bool Player::CanSellImprovement(Cell *property) { 
		  string blck = property->getBlock();
		  if (haveMonopoly(blck)) {
					 if (!inLine) {
								if (getPlayerPosition() == property->getCellName()) {
										  return true;
								}
					 }
		  }    

		  return false;

} //


bool Player::haveMonopoly(std::string Block) { 
     cout << "Verifying block: " << Block << endl;
	  cout << "So what's going on here?!" << endl;
		  int numOfBlocktype = 0;
		  cout << "numOfBlocktype initially: " << numOfBlocktype << endl;
        cout << "numProperties owned: " << numProperties << endl;
		  for(int i = 0; i < numProperties; i++) {
		           cout << "i: " << i << endl;
					 if (OwnedProperties[i]) {
								if ((OwnedProperties[i]->getBlock() == Block)) {
										  cout << "gettingblock: " << OwnedProperties[i]->getBlock() << endl;
										  numOfBlocktype++;
										  cout << "numBlocktype: " << numOfBlocktype << endl;
									}
					 }
		  }

		  if ((Block == "Arts1") && (numOfBlocktype == 2)) {
		     cout << "her arrr" << endl;
					 return true;
		  } else if ((Block == "Arts2") && (numOfBlocktype == 3)) {
					 cout << "here arr22" << endl;
					 return true;
		  } else if ((Block == "Eng") && (numOfBlocktype == 3)) {
					cout << "here arrr45" << endl;
					return true;
		  } else if ((Block == "Health") && (numOfBlocktype == 3)) {
					cout << "here arr4576" << endl;
					return true;
		  } else if ((Block == "Env") && (numOfBlocktype == 3)) {
					 cout << "here arr455" << endl;
					 return true;
		  } else if ((Block == "Sci1") && (numOfBlocktype == 3)) {
					 cout << "here a3345" << endl;
					 return true; 
		  } else if ((Block == "Sci2") && (numOfBlocktype == 3)) {
					 cout << "asdasdas" << endl;
					 return true;
		  } else if ((Block == "Math") && (numOfBlocktype == 2)) {
					 cout << "asdasdas" << endl;
					 return true;
		  } else {
					 cout << "asdasdas" << endl;
					 return false;
		  }

} //

void Player::declareBankruptcy(Player *receiver) { //

		  int numPropOfGiver = getnumProperties();

		  if (receiver != NULL) {	  

					 int numPropOfReceiver = receiver->getnumProperties();
					 int debtReceiver = 0;

					 for(int i = 0; i < numPropOfGiver; i++) {

								int costof_MortgagedProperty = OwnedProperties[i]->getPriceToBuy();		 

								if (OwnedProperties[i]->isItMortgaged()) {
										  cout << OwnedProperties[i]->getCellName() << " is mortgaged. Player " << receiver->getID() << " must pay 10% immediately to the bank." << endl;
										  cout << "However, player " << receiver->getID() << " can choose to pay the principal, which is half the cost of the property and unmortgage the building now. If not, the 10% + principal must be paid again on a later time when the property is unmortgaged. So unmortgage now? Type 'yes' for acceptance and 'no' for rejection" << endl;

										  string response;
										  cin >> response;

										  if (response == "yes") {
													 cout << "Congrats! You own the now unmortgaged property " << OwnedProperties[i]->getCellName() << "." << endl;
													 debtReceiver += ((0.1*costof_MortgagedProperty) + (0.5*costof_MortgagedProperty));
													 OwnedProperties[i]->setMortgaged(0);
													 receiver->obtainProp(OwnedProperties[i]);
													 OwnedProperties[i] = NULL;

										  } else {
													 cout << "Ok! You own the (still mortgaged) property, but you must pay the entire (10% of property cost + principal) should you later decide to unmortgage the property. Anndd that 10% that you originally paid, well that's gone to the bank for nothing!" << endl;
													 debtReceiver += 0.1*costof_MortgagedProperty;
													 receiver->obtainProp(OwnedProperties[i]);
													 OwnedProperties[i] = NULL;
										  }
								} else {  
										  cout << "Congrats! You own the property " << OwnedProperties[i]->getCellName() << "." << endl;
										  receiver->obtainProp(OwnedProperties[i]);
										  OwnedProperties[i] = NULL;

								}
					 }

					 int receiverBal = receiver->getBalance();
					 int receiverAs = receiver->getAssets();
					 receiverBal += balance;
					 receiverAs += balance;
					 receiverBal -= debtReceiver;
					 receiverAs -= debtReceiver;
					 receiver->setBalance(receiverBal);
					 receiver->setAssets(receiverAs);



		  } else {
					 for (int i = 0; i < numPropOfGiver; i++) {
								OwnedProperties[i]->setOwned(0);
								OwnedProperties[i]->setOwnerID('X');
								OwnedProperties[i]->setOwner(NULL);
								OwnedProperties[i]->setRent(0);
								OwnedProperties[i] = NULL;
					 }
		  }

		  

		  gameBoard->destroyRollUpRims();
	     setID('X');
		  setName("Bankrupt");
        assets = 0;
		  balance = 0;
		  inLine = 0;
		  position = 0;
		  rolledSum = 0;
		  x = 0;
		  y = 0;
		  lastx = 0;
		  lasty = 0;
		  numRollUpRim = 0;
		  numResidence = 0;
		  numGyms = 0;
		  numProperties = 0;
		  rollDoubles = 0;
		  RollDoubleCount = 0;
		  turnsIL = 0;
		  ThirdTurnFree = 0;
		  canRoll = 0;
		  dormant = 1;
		  int totplayers = gameBoard->getNumPlayers();
		  totplayers--;
		  gameBoard->setNumPlayers(totplayers);

}

void Player::obtainProp(Cell *property) { 
//cout << "INSIDE OBTAIN PROP" << endl;
		  OwnedProperties[numProperties] = property;
		  numProperties++;
		  property->setOwnerID(this->id);
		  property->setOwner(this);
		  printAllPropertiesOwned();

}//

bool Player::canTradeProp(Player *p, Cell *propertyOffer, Cell *propertyRequest) {
    //cout << "We going inside?" << endl;
	   // cout << "ownerid: " << propertyOffer->getOwnerID() << endl;
	 if ((propertyOffer->getOwner() == this) && (propertyRequest->getOwner() == p)) {
        //   cout << "HOW ABOUT HERE" << endl;
			if ((!propertyOffer->isItMortgaged()) && (!propertyRequest->isItMortgaged())) {
          //   cout << "OR HERE" << endl;
				 if (!this->amIinline() && (!p->amIinline())) {
                return true;
				 }  else {
                    cout << "Can't be in line while trading!" << endl;
						  return false;
					 }
	  		    }  else {
                  cout << "Properties can't be mortgaged while trading!" << endl;
						return false;
				 }

			} else {
             cout << "You need to own the properties to trade them" << endl;
				 return false;
	  }

	  return false;
}

bool Player::canTradeProp(Player *p, int cashOffer, Cell *propertyRequest) {
       if (!propertyRequest->isItMortgaged()) { 
           if ((!this->amIinline()) && (!p->amIinline())) {
               if (propertyRequest->getOwner() == p) {
                   return true;
					}  else {
                   cout << "Property owner mismatch!" << endl;
					    return false;
					}
			  } else {
                  cout << "Cannot be in line while making trade!" << endl;
			         return false;
			  }
		 } else {
            cout << "Cannot trade mortgaged properties" << endl;
	         return false;
	 }
  return false;
}

bool Player::canTradeProp(Player *p, Cell *propertyOffer, int cash) {
         
			 if (!propertyOffer->isItMortgaged()) { 
             if ((!this->amIinline()) && (!p->amIinline())) {
               if (propertyOffer->getOwner() == this) {
					    if (p->getBalance() >= cash) {
                       return true;
						 } else {
                      cout << "Player does not have enough" << endl;
						 }
					}  else {
                   cout << "Property owner mismatch!" << endl;
					    return false;
					}
			  } else {
                  cout << "Cannot be in line while making trade!" << endl;
			         return false;
			  }
		 } else {
            cout << "Cannot trade mortgaged properties" << endl;
	         return false;
	 }
  return false;
			// canTradeProp(p, cashOffer, propertyRequest);
}


bool Player::makeTrade(Player *p, Cell *propertyOffer, Cell *propertyRequest) {
	//	  cout << "Player " << this->getID() << " has just made a trade request to Player " << p->getID() << " offerring them property " << propertyOffer->getCellName() << " for property " << propertyRequest->getCellName() << "." << endl;
	//	  cout << "Does Player " << p->getID() << " accept or reject?" << endl;
		  //	string response;
		  //	cin >> response;
		  //	if (response == "accept") {
	//	  cout << "Player has accepted offer! trade complete!" << endl;
		            if (canTradeProp(p, propertyOffer, propertyRequest)) {
					    	cout << "Trade successful!" << endl;
						 	//obtainProp(propertyRequest);
		 				 	this->removeProperty(propertyOffer);
							obtainProp(propertyRequest);
							//numProperties++;
							//balance -= cash;
		  			    	assets += propertyRequest->getPriceToBuy();
		  				 	assets -= propertyOffer->getPriceToBuy();
		  				 	//int receiverBal = p->getBalance();
		  				 	int receiverAs = p->getAssets();
		  				 	//receiverBal += cash;
		  				 	receiverAs += propertyOffer->getPriceToBuy();
		  				 	receiverAs -= propertyRequest->getPriceToBuy();
		  			    	//p->setBalance(receiverBal);
		             	p->setAssets(receiverAs);
		             	p->removeProperty(propertyRequest);
		             	p->obtainProp(propertyOffer);
							//int receivernumProp = receiver->getnumProperties();
							//receivernumProp++;
							//i////receiver->setnumProperties(receivernumProp);
		             	return true;
					 }   else {
                    cout << "Trade unsuccessful" << endl;
					 }
	  		     

		  //	} else {
		  //		cout << "Player has rejected offer. No trade" << endl;
		  //		return false;
		  //	}
}

void Player::setnumProperties(int num) {
     numProperties = num;
}

bool Player::makeTrade(Player *p, int cash, Cell *property) { //
 
		  //	cout << "Player " << this->getID() << " has just made a trade request to Player " << p->getID() << " offerring them cash amount " << cash << " for property " << property->getCellName() << "." << endl;
		  //	cout << "Does Player " << p->getID() << " accept or reject?" << endl;
		  //	string response;
		  //	cin >> response;
		  //	if (response == "accept") {
		  //		cout << "Player has accepted offer! trade complete!" << endl;
		        if (canTradeProp(p, cash, property)) {
                   cout << "Trade successful" << endl;
						 obtainProp(property);
    					 balance -= cash;
		  			    assets += property->getPriceToBuy();
		             int receiverBal = p->getBalance();
		             int receiverAs = p->getAssets();
		             receiverBal += cash;
		             receiverAs -= property->getPriceToBuy();
		             p->setBalance(receiverBal);
		             p->setAssets(receiverAs);
		             p->removeProperty(property);
		             return true;
					} else {
                   cout << "Invalid trade" << endl;
						 return false;
					}
			  
	 
       		  
		  	  //	} else {
		  //		cout << "Player has rejected offer. No trade" << endl;
		  //		return false;
		  //	}

}//

void Player::removeProperty(Cell *property) { 

		  int indexOfProperty = 0;

		  bool match = 0;

		  for(int i = 0; i < numProperties; i++) {
					 
					 if (OwnedProperties[i]->getCellName() == property->getCellName()) {
								match = 1;
								indexOfProperty = i;
								break;
					 }
		  }

		  if (match) {
					 
					 for(int i = indexOfProperty; i < numProperties-1; i++) {
								OwnedProperties[i] = OwnedProperties[i+1];
					 }

					 OwnedProperties[numProperties-1] = NULL;
					 numProperties--;
					 //OwnedProperties[i]->setOwner(NULL);

		  }

}//


bool Player::makeTrade(Player *p, Cell *proper, int cash) { //

         
			         if (canTradeProp(p, proper, cash)) {
                   cout << "Trade successful" << endl;
						 removeProperty(proper);
    					 balance += cash;
		  			    assets -= proper->getPriceToBuy();
		             int receiverBal = p->getBalance();
		             int receiverAs = p->getAssets();
		             receiverBal -= cash;
		             receiverAs += proper->getPriceToBuy();
		             p->setBalance(receiverBal);
		             p->setAssets(receiverAs);
		             p->obtainProp(proper);
		             return true;
					} else {
                   cout << "Invalid trade" << endl;
						 return false;
					}
	
			
			
			// makeTrade(p, cash, proper);
		  //	cout << "Player " << this->getID() << " has just made a trade request to Player " << p->getID() << " by offering their property of " << proper->getCellName() << " for an amount of " << cash << " in exchange." << endl;
		  //	cout << "Does Player " << p->getID() << " accept or reject this offer?" << endl;

		  //	string response;
		  //	cin >> response;

		  //	if (response == "accept") {
		  //		cout << "Player has accepted offer! Trade complete!" << endl;
		 /*
		  removeProperty(proper);
		  p->obtainProp(proper);
		  //numProperties--;
		  balance += cash;
		  assets -= proper->getPriceToBuy();
		  int receiverBal = p->getBalance();
		  int receiverAs = p->getAssets();
		  receiverBal -= cash;
		  receiverAs += proper->getPriceToBuy();
		  p->setBalance(receiverBal);
		  p->setAssets(receiverAs);
		 */
		 //p->removeProperty(property);
		  //	} else {
		  //cout << "Player has rejected offer. No trade" << endl;
		  //	}

}


void Player::mortgage(Cell *property) { //

		  if (property->getOwner() == this) {
            if (!property->isItMortgaged()) {
					 int im = property->getNum_Im();

					 if (im <= 0) { 
					   	cout << "You have just mortgaged " << property->getCellName() << endl;  
							property->setMortgaged(1);
							balance += (property->getPriceToBuy() / 2);
							assets -= (property->getPriceToBuy());

					 } else {
								cout << "All improvements must be sold before mortgaging properties" << endl;
				 }
		    } else {
           cout << "You already have this property mortgaged. Cannot remortgage properties!" << endl;
		  }
 	  } else {
 			 cout << "You are not the owner!" << endl;
 	}
}

void Player::unmortgage(Cell *property) { //
		  if (property->getOwner() == this) {
					 if (property->isItMortgaged()) {
								if (balance >= ((property->getPriceToBuy() / 2) + (property->getPriceToBuy()/ 2))) {
										  property->setMortgaged(0);
										  cout << "Alright, this property is unmortgaged. People can start paying you rent now!" << endl;
										  balance -= ((property->getPriceToBuy() / 2) + (property->getPriceToBuy() / 10));
										  assets += property->getPriceToBuy();
								} 	else {
										  cout << "Sorry, not enough money to unmortgage property!" << endl;
								}
					 } else {
								cout << "This property is not even mortgaged!" << endl;
					 }
		  } else {
					 cout << "You are not the owner!" << endl;
		  }
}




int Player::getState() { 

}//

int Player::getNumRollup() { 
		  return numRollUpRim;
} //

void Player::getoutofLine() { 
}//

int Player::getPosn() { 
		  return position;
}//

int Player::getnumProperties() { 
		  return numProperties;
}//

int Player::getnumResidence() { 
		  return numResidence;
}//

int Player::getnumGyms() { 
		  return numGyms;
}//

bool Player::amIinline() { 
		  return inLine;
}//

int Player::getLastx() { 
		  return lastx;
}//

int Player::getLasty() { 
		  return lasty;
}//

int Player::getx() { 
		  return x;
}//

int Player::gety() { 
		  return y;
}//

void Player::setBalance(int bal) { 
		  this->balance = bal;
}//

void Player::incNumRollUpRim() {
		  numRollUpRim++;
}//

void Player::payRentTo(Player *receiver, int rentAmount) { 
		  if (balance >= rentAmount) {
					 balance -= rentAmount;
					 cout << "Rent paid successfully" << endl;
					 //assets -= rentAmount;
					 int receiverBal = receiver->getBalance();
					 int receiverAs = receiver->getAssets();
					 receiverBal += rentAmount;
					 receiverAs += rentAmount;
					 receiver->setBalance(receiverBal);
					 receiver->setAssets(receiverAs);
		  }  else {
					 cout << "What is going on in here?!!" << endl;
				//SellOptionsRent(receiver, rentAmount);
		  }
}//

std::string Player::getPlayerPosition() {
		  int a = this->getx();
		  int b = this->gety();
		  //		cout << "Are we going to getPlayerPosition? " << endl;
		  string s = gameBoard->identify(b,a);
		  return s;
}

bool Player::canBuyProp(Cell *property) { 
		  if (!property->checkOwned()) {
					 if (balance >= property->getPriceToBuy()) {
								if (getPlayerPosition() == property->getCellName()) { 
										  return true;
								} else {
										  //			   cout << "playerPosition: " << getPlayerPosition() << "property name: " << property->getCellName() << endl;
										  cout << "position off" << endl;
										  return false;
								}
					 } else {
								cout << "not enough cash, sorry" << endl;
								return false;
					 }
		  } else {
					 cout << "Property owned" << endl;
					 return false;
		  }
		  cout << "WTF" << endl;
		  return false;
}//

Player *Player::findPlayer(string plr) {

		  if (player1->getID() == plr[0]) {
					 return player1;
		  } else if (player2->getID() == plr[0])  {
					 return player2;
		  } else if (player3) {
					 if (player3->getID() == plr[0]) {
								return player3;
					 }
		  } else if (player4) {
					 if (player4->getID() == plr[0]) {
								return player4;
					 }
		  } else if (player5) {
					 if (player5->getID() == plr[0])  {
								return player5;
					 }
		  } else if (player6) {
					 if (player6->getID() == plr[0]) {
								return player6;  
					 }
		  }

		  return NULL;

}

std::string Player::getName() {
		  return name;
}

int Player::takeAction() {//
		  string word;
		  if (!amIinline()) {
					 cout << "What would you like to do? If you want to trade, type in 'trade player offer receive', if you'd like to buy, type 'buy property', if you'd like to sell, type 'sell property', if you'd like to improve a property, type 'improve property', if you'd like to sell an improvement on a property, type 'unimprove property', if you'd like to mortgage a property, type 'mortgage property', if you'd like to unmortgage a property, type 'unmortgage property', if you'd like to determine what your assets are type in 'assets', if you're bankrupt, type in 'bankrupt', if you'd like to do nothing type in 'next'" << endl;
					 string action;
					 getline(cin, action);
					 cout << "Did the getline work!: " << action << endl;
					 stringstream ss;
					 ss << action;
					 //string word;
					 ss >> word;
					 if (word == "trade") {
								cout << "We're trading in takeAction!" << endl;
								string plr;
								string offer;
								string expect;
								int cashOffer;
								ss >> plr;
								Player *receiver = findPlayer(plr);
								ss >> cashOffer;
								if (ss.fail()) { // going inside this if means offer is a property, not an int
										  ss.clear();
										  ss.ignore();
										  ss >> offer; // we know offer is a property
										  ss >> cashOffer; // checking to see if expect is int
										  if (ss.fail()) { // expect is not an int
													 ss.clear();
													 ss.ignore();
													 ss >> expect;  // expect is a property, offer is a property;
													 Cell *propToGive =  giveMeOwndPropertyOnStr(offer);
													 Cell *propToReceive = giveMeOwndPropertyOnStr(expect);
													 makeTrade(receiver, propToGive, propToReceive);
													 return 1;
										  } else { // expect is an int, offer is a property
													 Cell *propToGive = giveMeOwndPropertyOnStr(offer);
													 makeTrade(receiver, propToGive, cashOffer);
													 return 1;
										  } 			 
								} else { // offer is an int, offer is cash
										  // this is OFFER (it's cash)
										  ss >> expect; // expect must be property, other case doesn't apply
										  Cell *propToReceive = giveMeOwndPropertyOnStr(expect);
										  makeTrade(receiver, cashOffer, propToReceive);
										  return 1;

								}

					 }   else if (word == "improve") {
								cout << "We're improving inside takeAction!" << endl;
								string propToImprove;
								ss >> propToImprove;
								Cell *ImProp = giveMeOwndPropertyOnStr(propToImprove);
								buyImprovement(ImProp);
								return 1;
					 } else if (word == "unimprove") {
								cout << "We're unimproving inside takeAction!" << endl;
								string propToUnimprove;
								ss >> propToUnimprove;
								Cell *UnimProp = giveMeOwndPropertyOnStr(propToUnimprove);
								sellImprovement(UnimProp);
								return 1;
					 } else if (word == "mortgage") {
								cout << "We're mortgaging inside takeAction!" << endl;
								string propToMortgage;
								ss >> propToMortgage;
								Cell *mortgagedProp = giveMeOwndPropertyOnStr(propToMortgage);
								mortgage(mortgagedProp);
								return 1;
					 } else if (word == "unmortgage") {
								cout << "We're unmortgaging inside takeAction!" << endl;
								string propToUnmortgage;
								ss >> propToUnmortgage;
								Cell *unmortgagedProp = giveMeOwndPropertyOnStr(propToUnmortgage);
								unmortgage(unmortgagedProp);
								return 1;
					 } else if (word == "bankrupt") {
								cout << "We're bankrupting inside takeAction!" << endl;
								if  (canDeclareBankruptcy()) {
										  declareBankruptcy();
										  return 1;
								} else {
										  cout << "We're not doing much here!" << endl;
										  cout << "Sorry, you can't declare bankruptcy! Your assets are still positive" << endl;
								}
					 } else if (word == "assets") {
								cout << "We're finding our assets in takeAction!" << endl;
								return getAssets();
					 } else if (word == "save") {
								cout << "We're trying save in takeAction!" << endl;
								cout << "Coming soon" << endl;
								return 1;
					 } else if (word == "next") {
								cout << "takeAction next" << endl;
								cout << "Should do nothing?" << endl;
								return 1;
					 } else if (word == "buy") {
								cout << "takeAction buy" << endl;
								string candidateProp;
								ss >> candidateProp;
								Cell *Propbuy = giveMeOwndPropertyOnStr(candidateProp);
								buyProperty(Propbuy);
								return 1;
					 } else if (word == "sell") {
								cout << "takeAction sell" << endl;   
								string ProptoSell;
								ss >> ProptoSell;
								Cell *PropSell = giveMeOwndPropertyOnStr(ProptoSell);
								sellProperty(PropSell);
								return 1;
					 }
		  } else {
					 cout << "Sorry, you're in line!" << endl;
					 return 1;
		  }

		  cout << "Are we exiting this fn?" << endl;
		  cout << "Word: " << word << endl;
		  return 0;
}

int Player::getAssets() {
		  return assets;
} //



int main(int argc, char *argv[]) {

 if (argc == 3) {
   /*
	ifstream the_file(argv[2]);
	 if (!the_file.is_open()) {
       cout << "Could not open file!" << endl;
	 } else {
      int totPlayers = 0;
		string line;
		while(the_file >> line) {
        
		}
		
	 }
	 */

} else {
   
		  srand(static_cast<unsigned int>(time(0)));

		  Die sumdice;


		  cout << "Welcome to Building Buyer 7000! How many players will be playing this game?" << endl;

		  int numP;

		  cin >> numP;

		  if (numP == 2) {

					 Player *p1 = Player::getPlayer1();
					 Player *p2 = Player::getPlayer2();

					 p1->setDice(&sumdice);
					 p2->setDice(&sumdice);

					 cout << "Submit the names of Player 1 and Player 2, 1 per line" << endl;

					 string name1;
					 string name2;

					 cin >> name1;
					 cin >> name2;

					 p1->setName(name1);
					 p2->setName(name2);

					 cout << "Please submit the player pieces Player 1 and Player 2 will represent, respectively. " << endl;
					 cout << "Here are your options: 'G', 'B', 'D', 'P', 'S', '$', 'L', 'T'" << endl;

					 char piece1;
					 char piece2;

					 cin >> piece1;
					 cin >> piece2;

					 p1->setID(piece1);
					 p2->setID(piece2);

					 Board b(p1, p2);
					 b.initializeCells();

					 string input;

					 cout << "Alright, start rolling!" << endl;

					 Player *lastRolled = NULL;

					 //string garbage;
					 //cin >> garbage;

					 while (getline(cin,input)) {
								// This is for test
								// string test;
								// stringstream tt;
                        // tt << input;
								// This is the real one
				      if (b.getNumPlayers() == 1) {
                           cout << "Game Over!" << endl;
							  if (p1->getID() != 'X') {
							      cout << "Winner is: " << p1->getID() << endl;
									break;
							 } else {
                           cout << "Winner is: " << p2->getID() << endl;
									break;
							 }
						}
								stringstream ss;
								ss << input;
								string firstword;
								ss >> firstword;
								
								if (firstword == "roll") {
										  Player *roller = b.WhoRolls();
										  if (roller->isDormant()) {
                                      cout << "Turn being skipped as Player " << roller->getID() << " dormant." << endl;
												  b.updateTotalTurns();
												  b.calcWhosTurn();
												  continue;
										  }  else {
										   //cout << "here6" << endl;
										   lastRolled = roller;
										   if (!roller->amIinline()) {
											   roller->rollDice();
											}
										     roller->Move();
										  }
						//				  cout << "roller getplayerPosition: " << roller->getPlayerPosition() << endl;
										  
										  if ((roller->getPlayerPosition() == "SLC") || (roller->getPlayerPosition() == "GoToTims")) {
											//		 cout << "HERE SKALDJASKLDJASKLDJASKLDKASJL" << endl;
													 string prev = roller->getPlayerPosition();
													 //b.printBoard();
													 b.notify();
													 string newpos = roller->getPlayerPosition();
													 b.printBoard();
													 if (prev == "SLC") {
																cout << "Randomized at SLC!!! Player " << roller->getID() << " has been relocated to " << newpos << "." << endl;
													 } else {
																cout << roller->getID() << " HAS BEEN SENT TO TIMS LINE NOO" << endl;
													 }
													 // b.notify();
										  } else {
										     // cout << "here askdljaskldaskldasjlkdsajkldas" << endl;
													 b.printBoard();
													 b.notify();
													 
												//	 cout << "here7" << endl;
										  }
										  //	if ((roller->getPlayerPosition() == "SLC") || (roller->getPlayerPosition() == "GoToTims")) {
										  //    b.printBoard();
										  //}
										  //roller->takeAction();
										  //  roller->takeAction();
								} else if (firstword == "next") {
										  continue;
								} else if (firstword == "trade") {
										  cout << "We're trading in main!" << endl;

										  //string trade_useless;
										  //ss >> trade_useless;

										  string plr;
										  string offer;
										  string expect;
										  int cashOffer;

										  ss >> plr;
										  //cout << "just stringstreamed into plr, : " << plr << endl;
										  Player *receiver = Player::findPlayer(plr);
										  //cout << "receiverid: " << receiver->getID() << endl;
										  ss >> cashOffer;
										//  cout << "just stringstreamed into cashOffer: " << cashOffer << endl;
										  if (ss.fail()) {

													 ss.clear();
													 //ss.ignore();
													 ss >> offer; // we know offer is a property
										//			 cout << "just stringstreamed into offer inside first ss.fail: " << offer << endl;
													 ss >> cashOffer;
										//			 cout << "just stringstreamed into cashOffer: " << cashOffer << endl;

													 if (ss.fail()) {

																ss.clear();
																//ss.ignore();
																ss >> expect; // we know expect is a property
										//						cout << "second ss.fail: expect - " << expect << endl;
																// Trading Propertyies
										//						cout << "Alright, so want to trade properties!" << endl;
										//						cout << "offer: " << offer << endl;
										//						cout << "expect: " << expect << endl;
																Cell *propToGive = b.giveMePropOnStr(offer);
										//						cout << "propTogive: " << propToGive->getCellName() << endl;
																Cell *propToReceive = b.giveMePropOnStr(expect);
										//						cout << "propToReceive: " << propToReceive->getCellName() << endl;
										//						cout << "WE GOING HERE" << endl;

																//cout << "Player " << lastRolled->getID() << " wants to trade properties with Player " << plr << ". " << lastRolled->getID() << " is offering " << offer << " and requesting " << expect << " in return. " << Player " << plr << ", do you accept this offer? type in 'accept' to accept' and 'reject' to reject" << endl;
                                               if (lastRolled->canTradeProp(receiver, propToGive, propToReceive)) {
                                               	cout << "Player " << lastRolled->getID() << " wants to trade properties with Player " << plr << ". " << lastRolled->getID() << " is offering " << offer << " and requesting " << expect << " in return. Player " << plr << ", do you accept this offer? type in 'accept' to accept' and 'reject' to reject" << endl;
																string answer;
																cin >> answer;

																if (answer == "accept") {
																      //  cout << "Trade successful!" << endl;
																		  lastRolled->makeTrade(receiver, propToGive, propToReceive);
																        continue;
																} else {
																		  cout << "Sorry, offer rejected!" << endl;
																        continue;
																}
																    
																} else {
                                                   cout << "Invalid Trade" << endl;
																   continue;
																}
																//return 1;
													 } else { // we know expect is an int in cashOffer, offer is property
													  //ss >> expect;
													  Cell *propToGive = b.giveMePropOnStr(offer);
													 cout << "Alright so we want to trade property for cash!" << endl;
											       
												if (lastRolled->canTradeProp(receiver, propToGive, cashOffer)) {
                                  
													 cout << "Player " << lastRolled->getID() << " wants to trade their property in exchange for some cash with Player " << plr << ". " << lastRolled->getID() << " is offering " << offer << " and requesting " << cashOffer << " << in return. Player " << plr << ", do you accept this offer? type in 'accept' to accept' and 'reject' to reject" << endl;
                                              string answe;
															 cin >> answe;
															 if (answe == "accept") {
                                                     //cout << "Trade successful!" << endl;
																	  lastRolled->makeTrade(receiver, propToGive, cashOffer);
																	  continue;
															 } else {
                                                   cout << "Trade rejected. Sorry" << endl;
																	continue;
															 }
 
													 } else {
                                           cout << "Invalid trade" << endl;
														 continue;
													 }
												}
										  } else {
													 ss >> expect; // offer is an int, expect is a property
													 Cell *propToReceive = b.giveMePropOnStr(expect);
													 
											    if (lastRolled->canTradeProp(receiver, cashOffer, propToReceive)) {		 

													 cout << "Alright, so we are trading cash for property!" << endl;
													 cout << "Player " << lastRolled->getID() << " wants to trade their cash in exchange for some Property with Player " << plr << ". " << lastRolled->getID() << " is offering " << cashOffer << " and requesting " << expect << " in return. Player " << plr << ", do you accept this offer? type in 'accept' to accept' and 'reject' to reject" << endl;
                                              string answe;
															 cin >> answe;
															 if (answe == "accept") {
                                                     cout << "Trade successful!" << endl;
																	  lastRolled->makeTrade(receiver, cashOffer, propToReceive);
																	  continue;
															 } else {
                                                   cout << "Trade rejected. Sorry" << endl;
																	continue;
															 }
													 continue;
													 //return 1;
										  } else {
                                    cout << "Invalid trade" << endl;
												continue;
										  }
									}
								} else if (firstword == "improve") {

										  cout << "We're improving inside main!" << endl;
										  //string improve_useless;
										  //ss >> improve_useless;

										  string propToImprove;
										  ss >> propToImprove;
										 // cout << "are we still improving?" << endl;
										  Cell *ImProp = b.giveMePropOnStr(propToImprove);
										  //cout << "checking correct property to improve: " << ImProp->getCellName() << endl;
										  lastRolled->buyImprovement(ImProp);
										  continue;
										  //return 1;

								} else if (firstword == "unimprove") {
										  cout << "We're unimproving inside main!" << endl;
										  //string unimprove_useless;
										  //ss >> unimprove_useless;
										  string propToUnimprove;
										  ss >> propToUnimprove;
										  Cell *UnimProp = b.giveMePropOnStr(propToUnimprove);
										  lastRolled->sellImprovement(UnimProp);
								} else if (firstword == "mortgage") {
										  cout << "We're mortgagin inside main!" << endl;

										  //string mortgage_useless;
										  //ss >> mortgage_useless;

										  string propToMortgage;
										  ss >> propToMortgage;
										  Cell *mortgagedProp = b.giveMePropOnStr(propToMortgage);
										  lastRolled->mortgage(mortgagedProp);
										  continue;
										  //return 1;

								} else if (firstword == "unmortgage") {
										  cout << "We're unmortgaging inside main!" << endl;

										  //string unmortgage_useless;
										  //ss >> unmortgage_useless;

										  string propToUnmortgage;
										  ss >> propToUnmortgage;
										  Cell *unmortgagedProp = b.giveMePropOnStr(propToUnmortgage);
										  lastRolled->unmortgage(unmortgagedProp);

								} else if (firstword == "bankrupt") {
										  if (lastRolled->canDeclareBankruptcy()) {
													 lastRolled->declareBankruptcy();
										  }

								} else if (firstword == "assets") {
										  cout << "Balance: " << lastRolled->getBalance() << "." << endl;
										  cout << "Assets: " <<  lastRolled->getAssets() << "." << endl;
								} else if (firstword == "save") {
										  cout << "coming soon" << endl;
								} else if (firstword == "buy") {
										  cout << "Buying in main!" << endl;
										  //string buy_useless;
										  //ss >> buy_useless;

										  string candidateProp;
										  ss >> candidateProp;

										  //	cout << "Did wekhq get till here?" << endl;

										  Cell *Propbuy = b.giveMePropOnStr(candidateProp);
										  if (Propbuy == NULL) { 
                                    cout << "Nope, can't do that!" << endl;
												continue;
										  }

										  //	cout << "How about here?" << endl;
										  lastRolled->buyProperty(Propbuy);
								} else if (firstword == "sell") {
										  cout << "selling in main!" << endl;
										  //string sell_useless;
										  //ss >> sell_useless;

										  string ProptoSell;
										  ss >> ProptoSell;
										  Cell *PropSell = b.giveMePropOnStr(ProptoSell);
										  if (PropSell == NULL) {
                                    cout << "Nope, can't do that!" << endl;
												continue;
										  }
										  lastRolled->sellProperty(PropSell);
								}

								else {
										  continue;
										  // cout << "input: " << input << endl;
										  // cout << "Wrong input" << endl;
								}
					 }
				}
         } 
	   }				
	 
	 
	 /*while (cin >> input) {
 						if (input == "roll") {
						Player *roller = b.WhoRolls();
						while(roller->amIinline()) {
						roller->IncTurnsIL();
						if (roller->getTurnsIL() >= 3) {
						cout << "You've been in line for 3 turns straight. You must use the 'Roll Up the Rim' Cup or pay an amount of $50. Type in 'use' to use the RUTRC or 'pay' to pay $50." << endl;
						string resp;
						cin >> resp;
						if (resp == "use") {
						if (roller->getNumRollup() > 0) {
						cout << "I'll take that, and you're free from the line!" << endl;
						roller->decNumRollUpRim();
						roller->setInLine(0);
						roller->setTurnsIL(0);
						roller->setThirdTurnFree(1);
						break;
						} else {
						cout << "Sorry, you don't have one. Type in 'pay' to pay $50 and get out; If you don't have enough... we'll tell you what happens next." << endl;
						string resp3;
						cin >> resp3;
						if (roller->getBalance() >= 50) {
						cout << "I'll take that $50. You are free from the line!" << endl;
						roller->setInLine(0);
						int bal_tmp = roller->getBalance();
						int as_tmp = roller->getAssets();
						bal_tmp -= 50;
						as_tmp -= 50;
						roller->setBalance(bal_tmp);
						roller->setAssets(as_tmp);
						roller->setTurnsIL(0);
						roller->setThirdTurnFree(1);
						break;
						} else {
						cout << "Sorry, you're in line, you don't have RollupRimCup or the money to get out." << endl;
						roller->sellOptionsDC_Tims_Line();
						break;
						}
						}
						} else if (resp == "pay") {
						if (roller->getBalance() >= 50) {
						cout << "I'll take that $50. You are free from the line!" << endl;
						roller->setInLine(0);
						int bal_tmp2 = roller->getBalance();
						int as_tmp2 = roller->getAssets();
						bal_tmp2 -= 50;
						as_tmp2 -= 50;
						roller->setBalance(bal_tmp2);
						roller->setAssets(as_tmp2);
						roller->setTurnsIL(0);
						roller->setThirdTurnFree(1);
						break;
						} else {
						cout << "Sorry, you're in line, you don't have RollupRimCup or the money to get out." << endl;
						roller->sellOptionsDC_Tims_Line();
						break;
						}
						}
						} else {
						cout << "You are currently in line of the DC Tim's Coffee Shop, therefore you cannot roll until you get out. The only way to get out is by paying $50 (type 'pay'), or by trying to roll another set of doubles (type in 'rollagain')" << endl;
						bool they_haveit = (roller->getNumRollup() > 0);
						if (they_haveit) {
						cout << "..... But wait a second! So it turns out you're pretty lucky. I checked your pockets and you have a roll up the rim cup, which you won while back at one of the Tim's Shops. You can use this to get out of line. Do you want to use it? If so, type in 'use'" << endl;
						string response;
						cin >> response;
						if (response == "use") {
						roller->decNumRollUpRim();
						roller->setInLine(0);
						roller->setTurnsIL(0);
						break;
						} else {
					 cout << "Alright, then you can either pay or roll again. What would you like to do? Type in 'pay' to pay and 'rollagain' to roll again." << endl;

					 string resp5;
					 cin >> resp5;

					 if (resp5 == "pay") {
								if (roller->getBalance() >= 50) {
										  cout << "I'll take that $50. You are free from the line!" << endl;
										  roller->setInLine(0);
										  int bal_tmp3 = roller->getBalance();
										  int as_tmp3 = roller->getAssets();
										  bal_tmp3 -= 50;
										  as_tmp3 -= 50;
										  roller->setBalance(bal_tmp3);
										  roller->setAssets(as_tmp3);
										  roller->setTurnsIL(0);
										  break;
								} else {
										  cout << "Sorry, you don't have $50. You don't have any roll up rim cups. You must roll again. Type in 'rollagain'" << endl;
										  string resp6;
										  cin >> resp6;
										  roller->rollDice();
										  int rollSum = roller->getRolledSum();
										  if (roller->getRollDouble()) {
													 cout << "Phew, you rolled a double! The rolled sum was " << rollSum << ". You can get out of line!" << endl;
													 roller->setInLine(0);
													 roller->setTurnsIL(0);
													 break;
										  } else {
													 cout << "Sorry, no doubles. You rolled a " << rollSum << ". Better luck next turn." << endl;
													 break;
										  }
								}
					 }  else if (response == "rollagain") {
								roller->rollDice();
								int rollSum = roller->getRolledSum();
								if (roller->getRollDouble()) {
										  cout << "Phew, you rolled a double! The rolled sum was " << rollSum << ". You can get out of line!" << endl;
										  roller->setInLine(0);
										  roller->setTurnsIL(0);
										  break;
								} else {
										  cout << "Sorry, no doubles. You rolled a " << rollSum << ". Better luck next turn." << endl;
										  break;
								}
					 }
		  }
		  }  else {

					 string resp5;
					 cin >> resp5;

					 if (resp5 == "pay") {
								if (roller->getBalance() >= 50) {
										  cout << "I'll take that $50. You are free from the line!" << endl;
										  roller->setInLine(0);
										  int bal_tmp4 = roller->getBalance();
										  int as_tmp4 = roller->getAssets();
										  bal_tmp4 -= 50;
										  as_tmp4 -= 50;
										  roller->setBalance(bal_tmp4);
										  roller->setAssets(as_tmp4);
										  roller->setTurnsIL(0);
										  break;
								} else {
										  cout << "Sorry, you don't have $50. You don't have any roll up rim cups. You must roll again. Type in 'rollagain'" << endl;
										  string resp6;
										  cin >> resp6;
										  roller->rollDice();
										  int rollSum2 = roller->getRolledSum();
										  if (roller->getRollDouble()) {
													 cout << "Phew, you rolled a double! The rolled sum was " << rollSum2 << ". You can get out of line!" << endl;
													 roller->setInLine(0);
													 roller->setTurnsIL(0);
													 break;
										  } else {
													 cout << "Sorry, no doubles. You rolled a " << rollSum2 << ". Better luck next time." << endl;
													 break;
										  }
								}
					 }  else if (resp5 == "rollagain") {
								roller->rollDice();
								int rollSum3 = roller->getRolledSum(); 
								if (roller->getRollDouble()) {
										  cout << "Phew, you rolled a double! The rolled sum was " << rollSum3 << ". You can get out of line!" << endl;
										  roller->setInLine(0);
										  roller->setTurnsIL(0);
										  break;
								} else {
										  cout << "Sorry, no doubles. You rolled a " << rollSum3 << ". Better luck next time." << endl;
										  break;
								}
					 } else {
								cout << "shouldn't go here!" << endl;
					 }
		  }
		  }
		  }  

		  if (!roller->getThirdTurnFree()) {

					 while(!roller->amIinline()) {
								int rlledSum;
								roller->rollDice();
								rlledSum = roller->getRolledSum();
								cout << "Player " << roller->getID() << "rolled a " << rlledSum << "." << endl;
								roller->Move();
								b.printBoard();
								b.notify();
								roller->takeAction();
								if(roller->getRollDouble()) {
										  roller->IncRollDoublesCount();
										  roller->setRollDoubles(1);
										  if (roller->getRollDoublesCount() >= 3) {
													 cout << "Rolled a double again!!!" << " Sorry, you are sent to DC Tim's Line. On your next turn, you can only get out if you use a 'Roll up the Rim' Cup, pay $50 or roll another set of doubles!" << endl;
													 roller->MoveToTims();
													 b.printBoard();
													 roller->setInLine(1);
													 roller->setRollDoublesCount(0);
													 roller->setRollDoubles(0);
													 break;
													 // sent to DC Tim's Line
										  } else {
													 cout << "Rolled a double! Roll again!" << endl;
													 b.decWhosTurn();
													 b.decTotalTurns();
													 break;
													 //rlledSum += roller->rollDice();
										  }
								} else {
										  roller->setRollDoublesCount(0);
										  roller->setRollDoubles(0);
										  break;
								}
					 }
		  } else {
					 roller->Move();
					 b.printBoard();
					 b.notify();
		  }
		  //roller->rollDice();
		  //roller->Move();
		  //b.printBoard();
		  //b.notify();
		  // roller->takeAction();
		  }
		  }
		  */
		  
     
  

//	return 0;




/*
	else if (numP == 3) {

	Player *p1 = Player::getPlayer1();
	Player *p2 = Player::getPlayer2();
	Player *p3 = Player::getPlayer3();

	p1->setDice(&sumdice);
	p2->setDice(&sumdice);
	p3->setDice(&sumdice);

	cout << "Please submit the player pieces Player 1, Player 2 and Player 3 will represent. Here are your options: 'G' - Goose, 'B' - GRT BUS, 'D' - Tim Hortons Doughnut, 'P' - Professor, 'S' - Student, '$' - Money, 'L' - Laptop, 'T' - Pink tie" << endl;

	char piece1;
	char piece2;
	char piece3;

	cin >> piece1 >> piece2 >> piece3;

	p1->setID(piece1);
	p2->setID(piece2);
	p3->setID(piece3);

	Board b(p1, p2, p3);

	string input;

	cout << "Alright, start rolling!" << endl;

	while (cin >> input) {
	if (input == "roll") {
	Player *roller = b.WhoRolls();
	roller->rollDice();
	roller->Move();
	b.printBoard();
	b.notify();
//  roller->takeAction();
}
}

} else if (numP == 4) {

Player *p1 = Player::getPlayer1();
Player *p2 = Player::getPlayer2();
Player *p3 = Player::getPlayer3();
Player *p4 = Player::getPlayer4();

p1->setDice(&sumdice);
p2->setDice(&sumdice);
p3->setDice(&sumdice);
p4->setDice(&sumdice);

cout << "Please submit the player pieces Player 1, Player 2, Player 3 and Player 4 will represent. Here are your options: 'G' - Goose, 'B' - GRT BUS, 'D' - Tim Hortons Doughnut, 'P' - Professor, 'S' - Student, '$' - Money, 'L' - Laptop, 'T' - Pink tie" << endl;

char piece1;
char piece2;
char piece3;
char piece4;

cin >> piece1 >> piece2 >> piece3 >> piece4;

p1->setID(piece1);
p2->setID(piece2);
p3->setID(piece3);
p4->setID(piece4);

Board b(p1, p2, p3, p4);

string input;

cout << "Alright, start rolling!" << endl;

while (cin >> input) {
		  if (input == "roll") {
					 Player *roller = b.WhoRolls();
					 roller->rollDice();
					 roller->Move();
					 b.printBoard();
					 b.notify();
					 //  roller->takeAction();
		  }
}

} else if (numP == 5) {

		  Player *p1 = Player::getPlayer1();
		  Player *p2 = Player::getPlayer2();
		  Player *p3 = Player::getPlayer3();
		  Player *p4 = Player::getPlayer4();
		  Player *p5 = Player::getPlayer5();	

		  p1->setDice(&sumdice);
		  p2->setDice(&sumdice);
		  p3->setDice(&sumdice);
		  p4->setDice(&sumdice);
		  p5->setDice(&sumdice);

		  cout << "Please submit the player pieces Player 1, Player 2, Player 3, Player 4 and Player 5 will represent. Here are your options: 'G' - Goose, 'B' - GRT BUS, 'D' - Tim Hortons Doughnut, 'P' - Professor, 'S' - Student, '$' - Money, 'L' - Laptop, 'T' - Pink tie" << endl;

		  char piece1;
		  char piece2;
		  char piece3;
		  char piece4;
		  char piece5;

		  cin >> piece1 >> piece2 >> piece3 >> piece4 >> piece5;

		  p1->setID(piece1);
		  p2->setID(piece2);
		  p3->setID(piece3);
		  p4->setID(piece4);
		  p5->setID(piece5);

		  Board b(p1, p2, p3, p4, p5);

		  string input;

		  cout << "Alright, start rolling!" << endl;

		  while (cin >> input) {
					 if (input == "roll") {
								Player *roller = b.WhoRolls();
								roller->rollDice();
								roller->Move();
								b.printBoard();
								b.notify();
								//  roller->takeAction();
					 }
		  }

} else if (numP == 6) {

		  Player *p1 = Player::getPlayer1();
		  Player *p2 = Player::getPlayer2();
		  Player *p3 = Player::getPlayer3();
		  Player *p4 = Player::getPlayer4();
		  Player *p5 = Player::getPlayer5();
		  Player *p6 = Player::getPlayer6();

		  p1->setDice(&sumdice);
		  p2->setDice(&sumdice);
		  p3->setDice(&sumdice);
		  p4->setDice(&sumdice);
		  p5->setDice(&sumdice);
		  p6->setDice(&sumdice);

		  cout << "Please submit the player pieces Player 1, Player 2, Player 3, Player 4, Player 5 and Player 6 will represent. Here are your options: 'G' - Goose, 'B' - GRT BUS, 'D' - Tim Hortons Doughnut, 'P' - Professor, 'S' - Student, '$' - Money, 'L' - Laptop, 'T' - Pink tie" << endl;

		  char piece1;
		  char piece2;
		  char piece3;
		  char piece4;
		  char piece5;
		  char piece6;

		  cin >> piece1 >> piece2 >> piece3 >> piece4 >> piece5 >> piece6;

		  p1->setID(piece1);
		  p2->setID(piece2);
		  p3->setID(piece3);
		  p4->setID(piece4);
		  p5->setID(piece5);
		  p6->setID(piece6);

		  Board b(p1, p2, p3, p4, p5, p6);

		  string input;

		  cout << "Alright, start rolling!" << endl;

		  while (cin >> input) {
					 if (input == "roll") {
								Player *roller = b.WhoRolls();
								//cout << "The roller we have here is: " << roller->getID() << endl;
								roller->rollDice();
								roller->Move();
								b.printBoard();
								b.notify();
								//cout << "The roller we have here is: " << roller->getID() << endl;
								//roller->takeAction();
					 }
		  }

} else {

		  cout << "Sorry, there is a limit to a maximum of 6 players and a minimum of 2" << endl;

}


//Board c;
//c.printBoard();
//cout << "p2" << endl;
//Player *p3;
//cout << "p3" << endl;
//	Board b(p1, p2, p3, p4);

//b.printBoard();

//cout << "REAL FUN" << endl;


//cout << "b" << endl;
//b.printBoard();
//cout << "print" << endl;
}


int main() {
		  Board sumBoard;
		  //Board *sumBoard = Board::getInstance();
		  sumBoard.printBoard();
}
*/
