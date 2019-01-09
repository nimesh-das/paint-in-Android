#ifndef __BOARD_H_
#define __BOARD_H_

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "player.h"

class Cell;
class Die;
class Academic;
class Residence;
class Gym;
class Goose;
class NeedlesHall;
class SLC;
class Coop;
class Tuition;
class DcTimsLine;
class CollectOsap;
class GoToTims;

struct Board: public Observer {
   static int MAXROLL_UP_RIM;
	static Board *instance;
	static bool gameisrunning;
	Player *p1;
	Player *p2;
	Player *p3;
	Player *p4;
	Player *p5;
	Player *p6;
	Player *subject[6];
	Player *lastMoved;
	int TotalMoney;
	int numPlayers;
	char **board;
	int totalTurns;
	int WhosTurn;
	Cell *cells[40];
	
	Board(Player *p1 = NULL, Player *p2 = NULL, Player *p3 = NULL, Player *p4 = NULL, Player *p5 = NULL, Player *p6 = NULL); //
	~Board();//
	static void cleanup(); //
	bool gameover(); //
	void startgame();  //
	void addPlayer(Player *p); //
	static Board *getInstance(); //
	int BankAmount(); //
	int getNumPlayers(); //
	void setBankAmount(int amt); //
	void setNumPlayers(int numP); //
	void notify(); //
	void printBoard(); //
	std::string identify(int x, int y); //
	void updateTotalTurns(); //
	void calcWhosTurn(); //
	Player *WhoRolls(); //
	void decTotalTurns(); //
	void improveProp(Cell *property); // 
	void unimproveProp(Cell *property);//
	void initializeCells(); //
	void decWhosTurn();
	void decTotalTurn();
	void destroyRollUpRims();
   Cell *giveMePropOnStr(std::string prop);
	void notifySLCRandom();
	static int getNumRollUpRim();
	static void setNumRollUpRim(int num);
};




#endif
