#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>
#include <string>
#include "subject.h"
//#include "board.h"

class Board;
class Die;
class Cell;


class Player: public Subject {
    
	 std::string name;
	 static Player *player1;
	 static Player *player2;
    static Player *player3;
	 static Player *player4;
	 static Player *player5;
	 static Player *player6;
    static Board *gameBoard;
    int balance;
	 int assets;
	 char id;
	 Die *dice;
	 Cell *OwnedProperties[28];
	 bool inLine;
	 int x;
	 int y;
	 int position;
	 int lastposition;
	 int lastx;
	 int lasty;
	 int numRollUpRim;
	 int numResidence;
	 int numGyms;
	 int numProperties;
	 int rolledSum;
	 bool rollDoubles;
	 int RollDoubleCount;
	 int turnsIL;
	 bool ThirdTurnFree;
    bool canRoll;
	 bool dormant;
    bool danger;

	 public:
	 
	 Player(); //
	 void Move();//
	 bool getCanRoll();
	 void setCanRoll(bool canRoll);
	 static void cleanup1();//
	 static void cleanup2();//
	 static void cleanup3();//
	 static void cleanup4();//
	 static void cleanup5();//
	 static void cleanup6();//
    static Player *getPlayer1();//
	 static Player *getPlayer2();//
	 static Player *getPlayer3();//
	 static Player *getPlayer4();//
	 static Player *getPlayer5();//
	 static Player *getPlayer6();//
	 
	 bool canBuyProp(Cell *property); //
	 void buyProperty(Cell *property);//
	 bool canSellProp(Cell *property); //
	 void sellProperty(Cell *property);  //
	 int checkPropertyPrice(Cell *property); //
	 int checkPropertyIC(Cell *property);  //
	 int checkPropertyRent(Cell *property); //
	 void buyImprovement(Cell *property);  //
	 void sellImprovement(Cell *property);  //
	 bool CanBuyImprovement(Cell *property); //
	 bool CanSellImprovement(Cell *property);  //
	 bool haveMonopoly(std::string Block);  //
	 void declareBankruptcy(Player *receiver=NULL); //
	 bool makeTrade(Player *p, int cash, Cell *property); //
	 bool makeTrade(Player *p, Cell *property, int cash); //
    bool makeTrade(Player *p, Cell *propertyOffer, Cell *propertyRequest);
	 void mortgage(Cell *property); //
	 void unmortgage(Cell *property); //
	 void removeProperty(Cell *property); //
	 void obtainProp(Cell *property); //
	 
	 void setnumProperties(int num);
	 void MoveToCollectOsap();
	 bool inDanger();
	 void setinDanger(bool danger);
	 bool isDormant();
    void payRentTo(Player *receiver, int rentAmount); //
    int getBalance(); //
	 int getAssets();//
	 int getNetWorth(); //
	 void printAllPropertiesOwned(); //
	 char getID();//
	 int rollDice(); //
	 static Player* findPlayer(std::string plr);
    bool canDeclareBankruptcy();//
	 bool amIinline(); //
	 int getnumProperties(); //
	 void incNumProperties(); //
	 void incNumResidence();
	 void incNumGyms();
	 int getnumResidence();// 
	 int getnumGyms();//  
	 int getPosn(); //
	 void getoutofLine(); //
	 void payRentTo(Player *p);  //
	 int getNumRollup(); //
    std::string getName();
	 std::string getPlayerPosition();
	 void setName(std::string name);
	 void setInLine(bool iL); //
	 int getRolledSum(); //
	 void setRolledSum(int sum); //
	 void setID(char ID); //
	 void setAssets(int assets); //
	 void setBalance(int balance); //
	 void setPosn(int x, int y); //
	 void setnumRollup(int numRoll);  //
	 bool getRollDouble(); //
	 int getState(); //
	 void calculate_coordinates(); //
	 int getLastx(); //
	 int getLasty(); //
	 int getx(); //
	 int gety(); //
	 int getLastPosn();
	 void setLastPosn(int pos);
	 void setBoard(Board *gameBoard);//
	 void setDice(Die *dice); //
    void MoveToTims(); //
    void collectOsap(); //
	 void incrBalance(int amt);//
	 void decrBalance(int amt);//
	 void Move(int steps);//
	 void IncRollDoublesCount();//
	 void IncTurnsIL();//
	 int getTurnsIL();//
	 void setTurnsIL(int turns);//
	 void setRollDoubles(bool rolldoub);//
	 void incNumRollUpRim();//
	 void decNumRollUpRim();//
	 int getRollDoublesCount();//
	 void setRollDoublesCount(int rdc);//
	 int getThirdTurnFree();//
	 void setThirdTurnFree(bool ttf); //
	 //void SellOptionsTuition(); //
	 //void SellOptionsRent(Player *receiver, int rentAmount); //
	 Player *giveMePlayerOnStr(std::string player);//
	 Cell *giveMeOwndPropertyOnStr(std::string prop);//
	 int takeAction(); //
	 //void sellOptionsCoop();
	 void sellOptionsDC_Tims_Line();
	 //void takeAction();
    bool canTradeProp(Player *p, Cell *propertyOffer, Cell *propertyRequest);
	 bool canTradeProp(Player *p, int cashOffer, Cell *propertyRequest);
	 bool canTradeProp(Player *p, Cell *propertyRequest, int cashOffer);

};


#endif
