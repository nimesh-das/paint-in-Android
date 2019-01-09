#include <iostream>
#include "gototims.h"
#include "player.h"
using namespace std;

GoToTims::GoToTims(): Unownable() { }

GoToTims::GoToTims(string cellName, int indexOfProperty, Board *leboard): Unownable(cellName, indexOfProperty, leboard) { }

GoToTims::~GoToTims() { }

void GoToTims::QueryPlayer(Player *p) {
     cout << p->getID() << " Has to be moved to the DC Tim's Line. Osap is not collected. Sorry." << endl;	
	  p->MoveToTims(); 
}


