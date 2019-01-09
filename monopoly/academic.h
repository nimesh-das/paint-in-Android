#ifndef __ACADEMIC_H_
#define __ACADEMIC_H_
#include <iostream>
#include <string>
#include "ownable.h"

class Board;
class Player;

class Academic: public Ownable {
   std::string Block;
	static int MaxNumBlockAr1;
	static int MaxNumBlockAr2;
   static int MaxNumBlockEng;
	static int MaxNumBlockHealth;
	static int MaxNumBlockEnv;
	static int MaxNumBlockSci1;
	static int MaxNumBlockSci2;
	static int MaxNumBlockMath;
	int IC;
	int num_improvements;
	int tuition_perImprovement[6];	
	public:
	Academic();
	Academic(std::string name, int indexOnBoard, Board *leboard, int purchaseCost, int sellPrice, std::string Block, int IC);
	//~Academic();
   std::string getBlock();
	int get_IC();
	int getNum_Im();
	void setBlock(std::string blck);
	void set_IC(int ic);
	void setNum_Imp(int numIm);
	int getMaxNumBlockAr1();
	int getMaxNumBlockAr2();
	int getMaxNumBlockEng();
	int getMaxNumBlockHealth();
	int getMaxNumBlockEnv();
	int getMaxNumBlockSci1();
	int getMaxNumBlockSci2();
	int getMaxNumBlockMath();
	void setMaxNumBlockAr1(int numB);
   void setMaxNumBlockAr2(int numB);
	void setMaxNumBlockEng(int numB);
	void setMaxNumBlockHealth(int numB);
	void setMaxNumBlockEnv(int numB);
	void setMaxNumBlockSci1(int numB);
	void setMaxNumBlockSci2(int numB);
	void setMaxNumBlockMath(int numB);
	void QueryPlayer(Player *p);
	int CalcRent();
	void SellOptionsRent(Player *p, Player *receiver, int rentAmount);
};

#endif
