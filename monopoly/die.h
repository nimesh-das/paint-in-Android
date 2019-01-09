#ifndef __DIE_H_
#define __DIE_H_
#include <iostream>
#include <cstdlib>
#include <ctime>

class Die {
 private:
  int die1;
  int die2;
  int NumRolls;
  int sum;

public:
  Die();
  
  int toss();
  void Reset();
      
  int getDie1();
  int getDie2();
  int getSum();
  bool isDouble();
  int getNumRolls();
  
};


#endif
