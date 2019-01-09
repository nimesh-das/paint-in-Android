#include <iostream>
#include "goose.h"
#include "player.h"
using namespace std;

Goose::Goose(): Unownable() { }

Goose::Goose(string cellName, int indexOfProperty, Board *leboard): Unownable(cellName, indexOfProperty, leboard) { }

//Goose::~Goose() { }

void Goose::QueryPlayer(Player *p) {
     cout << p->getID() << "just got attacked by geese! But it's ok, nothing else happened..." << endl;	
}


