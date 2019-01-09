#include <iostream>
#include "unownable.h"
using namespace std;

Unownable::Unownable(): Cell() { }

Unownable::Unownable(string cellName, int indexOfProperty, Board *leboard): Cell(cellName, indexOfProperty, leboard) { }

Unownable::~Unownable() { }
