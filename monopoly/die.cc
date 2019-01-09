#include <iostream>
#include "die.h"
using namespace std;

Die::Die():  die1(0), die2(0), NumRolls(0), sum(0) { }//cout << "waa" << endl; }

int Die::toss() {
   //cout << "go here" << endl;
	NumRolls++;
	//cout << "go here2" << endl;
	die1 = (rand() % 6) + 1;
	//cout << "go here3" << endl;
	die2 = (rand() % 6) + 1;
	//cout << "go here4" << endl;
	sum = die1 + die2;
	//cout << "go here5" << endl;
	return sum;
}

int Die::getDie1() {
 return die1; 
}

int Die::getDie2() {
 return die2; 
}

int Die::getSum() {
 return sum;
} 

bool Die::isDouble() {
 return (getDie1() == getDie2());
}


int Die::getNumRolls() {
 return NumRolls;
}

void Die::Reset() {
    sum = 0;
	 die1 = 0;
	 die2 = 0;
	 NumRolls = 0;
}

/*
int main() {
    srand(static_cast<unsigned int>(time(0)));
	 Die MyDice;
	 
 for(int i = 0; i < 10; i++) {
    MyDice.toss();
	 cout << MyDice.getSum() << endl;
 }
	 
}
*/
