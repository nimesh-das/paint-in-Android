#include <iostream>
#include "slc.h"
#include "player.h"
#include <cstdlib>
#include <ctime>
#include "board.h"
using namespace std;

SLC::SLC(): Unownable() { }

SLC::SLC(string cellName, int indexOfProperty, Board *leboard): Unownable(cellName, indexOfProperty, leboard) { }

//Coop::~Coop() { }


void SLC::notifyBoard_fromCell() {
    Board *ourboard = getleboard();
	 ourboard->notifySLCRandom();
}

void SLC::QueryPlayer(Player *p) {
   
   cout << "~~~ Tunes coming from SLC ~~~~~" << endl;

	srand(static_cast<unsigned int>(time(0))); 
	
	int x = rand() % 24;
	 
	 if (x == 0) {
       cout << "Move to Tims Line" << endl;
		 p->MoveToTims();
		 notifyBoard_fromCell();
	 } else if (x == 1) {
	    cout << "Collect Osap" << endl;
        p->collectOsap();
		  p->MoveToCollectOsap();
		  notifyBoard_fromCell();
	 } else if ((x >= 2) && (x <= 5)) {
	    cout << "Move up 3" << endl;
        p->Move(3);
		  notifyBoard_fromCell();
	 } else if ((x >= 6) && (x <= 9)) {
	    cout << "Move up 2" << endl;
        p->Move(2);
		  notifyBoard_fromCell();
	 } else if ((x >= 10) && (x <= 13)) {
       cout << "Move back 1" << endl;
        p->Move(-1);
		  notifyBoard_fromCell();
	 } else if ((x >= 14) && (x <= 17)) {
	    cout << "Move back 2" << endl;
        p->Move(-2);
		  notifyBoard_fromCell();
	 } else if ((x >= 18) && (x <= 20)) {
	    cout << "Move back 3" << endl;
        p->Move(-3);
		  notifyBoard_fromCell();
	 } else if ((x >= 21) && (x <= 23)) {
	    cout << "Move up 1" << endl;
        p->Move(1);
		  notifyBoard_fromCell();
	 } else {
         cout << "something went wrong" << endl;
	 }

	  int chance = rand() % 100;
    int tot = Board::getNumRollUpRim();
	 if (tot > 0) {
	  if (chance == 12) {
        cout << "You just won a roll up the rim cup! If at any time you get stuck in line, you can use this to get out of line!" << endl;
		  p->incNumRollUpRim();
		  tot--;
		  Board::setNumRollUpRim(tot);
	  }
   }
}


