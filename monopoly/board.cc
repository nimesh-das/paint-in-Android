#include <iostream>
#include "board.h"
#include "cell.h"
#include "academic.h"
#include "residence.h"
#include "gym.h"
#include "goose.h"
#include "needleshall.h"
#include "slc.h"
#include "coop.h"
#include "tuition.h"
#include "dctimsline.h"
#include "collectosap.h"
#include "gototims.h"
#include <string>

using namespace std;

int Board::MAXROLL_UP_RIM = 4;
Board* Board::instance = NULL;
bool Board::gameisrunning = 0;

void Board::destroyRollUpRims() {
      
		MAXROLL_UP_RIM = 4;
		
		if (numPlayers == 6) {
         p1->setnumRollup(0);
			p2->setnumRollup(0);
			p3->setnumRollup(0);
			p4->setnumRollup(0);
			p5->setnumRollup(0);
			p6->setnumRollup(0);
		} else if (numPlayers == 5) {
         p1->setnumRollup(0);
			p2->setnumRollup(0);
			p3->setnumRollup(0);
			p4->setnumRollup(0);
			p5->setnumRollup(0);
		} else if (numPlayers == 4) {
         p1->setnumRollup(0);
			p2->setnumRollup(0);
			p3->setnumRollup(0);
			p4->setnumRollup(0);
		} else if (numPlayers == 3) {
         p1->setnumRollup(0);
			p2->setnumRollup(0);
			p3->setnumRollup(0);
		} else if (numPlayers == 2) {
         p1->setnumRollup(0);
			p2->setnumRollup(0);
		}

}

Board::~Board() { //


		  if (numPlayers == 2) {
					 p1->detach(this);
					 p2->detach(this);
		  } else if (numPlayers == 3) {
					 p1->detach(this);
					 p2->detach(this);
					 p3->detach(this);
		  } else if (numPlayers == 4) {
					 p1->detach(this);
					 p2->detach(this);
					 p3->detach(this);
					 p4->detach(this);
		  } else if (numPlayers == 5) {
					 p1->detach(this);
					 p2->detach(this);
					 p3->detach(this);
					 p4->detach(this);
					 p5->detach(this);
		  } else if (numPlayers == 6) {
					 p1->detach(this);
					 p2->detach(this);
					 p3->detach(this);
					 p4->detach(this);
					 p5->detach(this);
					 p6->detach(this);
		  }

          for(int i = 0; i < 40; i++) {
		     delete cells[i];
		  }

		  for(int i = 0; i < 58; i++) {
					 delete [] board[i];
		  }
}

void Board::addPlayer(Player *p) { //
		  if (numPlayers < 6) {
					 subject[numPlayers] = p;
					 numPlayers++;
		  }
}

void Board::updateTotalTurns() { //
		  totalTurns++;
}

void Board::decTotalTurns() { //
     totalTurns--;
}

void Board::calcWhosTurn() { //
		  //    cout << "totalturns: " << totalTurns << " " << "numPlayers: " << numPlayers << endl;
		  WhosTurn = (totalTurns % numPlayers);
		  //	 cout << "WhosTurn: " << WhosTurn << endl;
}

Player *Board::WhoRolls() { //
		  if (WhosTurn == 0) {
					 if (numPlayers == 2) {
								return p2;
					 } else if (numPlayers == 3) {
								return p3;
					 } else if (numPlayers == 4) {
								return p4;
					 } else if (numPlayers == 5) {
								return p5;
					 } else {
								return p6;
					 }
		  } else if (WhosTurn == 1) {
					 return p1;
		  } else if (WhosTurn == 2) {
					 return p2;
		  } else if (WhosTurn == 3) {
					 return p3;
		  } else if (WhosTurn == 4) {
					 return p4;
		  } else if (WhosTurn == 5) {
					 return p5;
		  }
}

Board::Board(Player *p1, Player *p2, Player *p3, Player *p4, Player *p5, Player *p6): p1(p1), p2(p2), p3(p3), p4(p4), p5(p5), p6(p6) { //
		  
		  lastMoved = NULL; 
		  totalTurns = 1;
		  WhosTurn = 1;
		  initializeCells();

		  if (p6) {
					 //   cout << "p6 c" << endl;
					 numPlayers = 6;

					 p1->attach(this);
					 p1->setBoard(this);

					 p2->attach(this);
					 p2->setBoard(this);

					 p3->attach(this);
					 p3->setBoard(this);

					 p4->attach(this);
					 p4->setBoard(this);

					 p5->attach(this);
					 p5->setBoard(this);

					 p6->attach(this);
					 p6->setBoard(this);


					 subject[0] = p1;
					 subject[1] = p2;
					 subject[2] = p3;
					 subject[3] = p4;
					 subject[4] = p5;
					 subject[5] = p6;

		  } else if (p5) {
					 //    cout << "p5 c" << endl;
					 numPlayers = 5;

					 p1->attach(this);
					 p1->setBoard(this);

					 p2->attach(this);
					 p2->setBoard(this);

					 p3->attach(this);
					 p3->setBoard(this);

					 p4->attach(this);
					 p4->setBoard(this);

					 p5->attach(this);
					 p5->setBoard(this);

					 subject[0] = p1;
					 subject[1] = p2;
					 subject[2] = p3;
					 subject[3] = p4;
					 subject[4] = p5;

		  } else if (p4) {
					 //     cout << "p4 c" << endl;
					 numPlayers = 4;

					 p1->attach(this);
					 p1->setBoard(this);

					 p2->attach(this);
					 p2->setBoard(this);

					 p3->attach(this);
					 p3->setBoard(this);

					 p4->attach(this);
					 p4->setBoard(this);

					 subject[0] = p1;
					 subject[1] = p2;
					 subject[2] = p3;
					 subject[3] = p4;

		  } else if (p3) {
					 //  cout << "p3 c" << endl;
					 numPlayers = 3;

					 p1->attach(this);
					 p1->setBoard(this);

					 p2->attach(this);
					 p2->setBoard(this);

					 p3->attach(this);
					 p3->setBoard(this);

					 //    cout << "p3 attach finished" << endl;
					 subject[0] = p1;
					 subject[1] = p2;
					 subject[2] = p3;


		  } else if (p2) {
					 //     cout << "p2 c" << endl;
					 numPlayers = 2;
					 //	  cout << "so its during the p1 attachment" << endl;
					 p1->attach(this);
					 p1->setBoard(this);
					 //	  cout << "do we attach p1" << endl;
					 p2->attach(this);
					 p2->setBoard(this);
					 //	  cout << "do we attach p2" << endl;

					 subject[0] = p1;
					 subject[1] = p2;

		  } else {
					 //   cout << "p1 c" << endl;
					 numPlayers = 0;

		  }

		  //	cout << "even go here" << endl;

		  TotalMoney = 15140;

		  board = new char*[58];

		  for(int i = 0; i < 58; i++) {
					 board[i] = new char[89];
		  }

		  for(int i = 0; i < 58; i++) {
					 for(int j = 0; j < 89; j++) {
								board[i][j] = ' ';
					 }
		  }

		  for(int row = 0; row < 58; row++) {
					 for(int col = 0; col < 89; col++) {
								if (row == 0) {
										  board[row][col] = '-';
								} else if (((row == 5) || (row == 52) || (row == 57)) && ((col != 0) && (col != 88)))  {
										  if ((col%8) != 0) {
													 board[row][col] = '-';
										  } 
								} else if (((row == 24) || (row == 32)) && ((col >= 24) && (col <= 64))) {
										  board[row][col] = '-';
								} else if (((row > 24) && (row < 32)) && ((col == 24) || (col == 64))) {
										  board[row][col] = '|';
								} else if ((row == 26) && (((col >= 27) && (col <= 29)) || ((col >= 33) && (col <= 35)) || ((col >= 39) && (col <= 43)) || ((col >= 46) && (col <= 48)) || ((col >= 52) && (col <= 54)) || ((col >= 58) && (col <= 60)))) {
										  board[row][col] = '#';
								} else if ((row == 27) && ((col == 27) || (col == 30) || (col == 33) || (col == 36) || (col == 42) || (col == 45) || (col == 49) || (col == 51) || (col == 55) || (col == 57) || (col == 61))) {
										  board[row][col] = '#';
								} else if ((row == 28) && (((col >= 27) && (col <= 30)) || ((col >= 33) && (col <= 36)) || (col == 41) || (col == 45) || (col == 49) || (col == 51) || (col == 55) || (col == 57) || (col == 61))) {
										  board[row][col] = '#';
								} else if ((row == 29) && ((col == 27) || (col == 31) || (col == 33) || (col == 37) || (col == 40) || (col == 45) || (col == 49) || (col == 51) || (col == 55) || (col == 57) || (col == 61))) {
										  board[row][col] = '#';
								} else if ((row == 30) && (((col >= 27) && (col <= 30)) || ((col >= 33) && (col <= 36)) || (col == 39) || ((col >= 46) && (col <= 48)) || ((col >= 52) && (col <= 54)) || ((col >= 58) && (col <= 60)))) {
										  board[row][col] = '#';
								} else if ((row > 0) && (col == 0)) {
										  board[row][col] = '|';
								} else if ((row > 0) && (col == 88)) {
										  board[row][col] = '|';
								} else if ((row > 0) && (col == 8)) {
										  board[row][col] = '|';
								} else if ((row > 0) && (col == 80)) {
										  board[row][col] = '|';
								} else if ((((row > 0) && (row <= 5)) || (row >= 52) && (row <= 57)) && ((col != 80) && (col != 8) && ((col%8) == 0))) {
										  board[row][col] = '|';
								} else if (((row == 7) || (row == 10) || (row == 12) || (row == 15) || (row == 20) || (row == 22) || (row == 25) || (row == 30) || (row == 35) || (row == 37) || (row == 40) || (row == 45) || (row == 47)) && (col > 80)) {
										  board[row][col] = '-';
								} else if (((row == 7) || (row == 10) || (row == 12) || (row == 15) || (row == 20) || (row == 22) || (row == 25) || (row == 30) || (row == 32) || (row == 35) || (row == 37) || (row == 40) || (row == 45) || (row == 47)) && (col < 8) && (col > 0)) {
										  board[row][col] = '-';
								} else if ((row == 2) && (((col > 8) && (col < 16)) || ((col > 24) && (col < 32)) || ((col > 32) && (col < 40)) || ((col > 48) && (col < 56)) || ((col > 56) && (col < 64)) || ((col > 72) && (col < 80)))) {
										  board[row][col] = '-';
								} else if ((row == 54) && (((col > 8) && (col < 16)) || ((col > 16) && (col < 24)) || ((col > 32) && (col < 40)) || ((col > 56) && (col < 64)) || ((col > 72) && (col < 80)))) {
										  board[row][col] = '-';
								} else if (row == 53) {
										  if (col == 1) {
													 board[row][col] = 'D';
										  } else if (col == 2) {
													 board[row][col] = 'C';
										  } else if (col == 4) {
													 board[row][col] = 'T';
										  } else if (col == 5) {
													 board[row][col] = 'i'; 
										  } else if (col == 6) {
													 board[row][col] = 'm';
										  } else if (col == 7) {
													 board[row][col] = 's';
										  } else if (col == 25) {
													 board[row][col] = 'N';
										  } else if (col == 26) {
													 board[row][col] = 'E';
										  } else if (col == 27) {
													 board[row][col] = 'E';
										  } else if (col == 28) {
													 board[row][col] = 'D';
										  } else if (col == 29) {
													 board[row][col] = 'L';
										  } else if (col == 30) {
													 board[row][col] = 'E';
										  } else if (col == 31) {
													 board[row][col] = 'S';
										  } else if (col == 41) {
													 board[row][col] = 'M';
										  } else if (col == 42) {
													 board[row][col] = 'K';
										  } else if (col == 43) {
													 board[row][col] = 'V';
										  } else if (col == 49) {
													 board[row][col] = 'T';
										  } else if (col == 50) {
													 board[row][col] = 'U';
										  } else if (col == 51) {
													 board[row][col] = 'I';
										  } else if (col == 52) {
													 board[row][col] = 'T';
										  } else if (col == 53) {
													 board[row][col] = 'I';
										  } else if (col == 54) {
													 board[row][col] = 'O';
										  } else if (col == 55) {
													 board[row][col] = 'N';
										  } else if (col == 65) {
													 board[row][col] = 'S';
										  } else if (col == 66) {
													 board[row][col] = 'L';
										  } else if (col == 67) {
													 board[row][col] = 'C';
										  } else if (col == 81) {
													 board[row][col] = 'C';
										  } else if (col == 82) {
													 board[row][col] = 'O';
										  } else if (col == 83) {
													 board[row][col] = 'L';
										  } else if (col == 84) {
													 board[row][col] = 'L';
										  } else if (col == 85) {
													 board[row][col] = 'E';
										  } else if (col == 86) {
													 board[row][col] = 'C';
										  } else if (col == 87) {
													 board[row][col] = 'T';
										  } 
								} else if (row == 54) {
										  if (col == 1) {
													 board[row][col] = 'L';
										  } else if (col == 2) {
													 board[row][col] = 'i';
										  } else if (col == 3) {
													 board[row][col] = 'n';
										  } else if (col == 4) {
													 board[row][col] = 'e'; 
										  } else if (col == 25) {
													 board[row][col] = 'H';
										  } else if (col == 26) {
													 board[row][col] = 'A';
										  } else if (col == 27) {
													 board[row][col] = 'L';
										  } else if (col == 28) {
													 board[row][col] = 'L';
										  } else if (col == 81) {
													 board[row][col] = 'O';
										  } else if (col == 82) {
													 board[row][col] = 'S';
										  } else if (col == 83) {
													 board[row][col] = 'A';
										  } else if (col == 84) {
													 board[row][col] = 'P';
										  }  
								} else if (row == 55) {
										  if (col == 9) {
													 board[row][col] = 'H';
										  } else if (col == 10) {
													 board[row][col] = 'H';
										  } else if (col == 17) {
													 board[row][col] = 'P';
										  } else if (col == 18) {
													 board[row][col] = 'A'; 
										  } else if (col == 19) {
													 board[row][col] = 'S';
										  } else if (col == 33) {
													 board[row][col] = 'E';
										  } else if (col == 34) {
													 board[row][col] = 'C';
										  } else if (col == 35) {
													 board[row][col] = 'H';
										  } else if (col == 57) {
													 board[row][col] = 'M';
										  } else if (col == 58) {
													 board[row][col] = 'L';
										  } else if (col == 73) {
													 board[row][col] = 'A';
										  } else if (col == 74) {
													 board[row][col] = 'L';
										  } 
								} else if (row == 8) {
										  if (col == 1) {
													 board[row][col] = 'O';
										  } else if (col == 2) {
													 board[row][col] = 'P';
										  } else if (col == 3) {
													 board[row][col] = 'T';
										  } else if (col == 81) {
													 board[row][col] = 'E';
										  } else if (col == 82) {
													 board[row][col] = 'I';
										  } else if (col == 83) {
													 board[row][col] = 'T';
										  }
								} else if (row == 13) {
										  if (col == 1) {
													 board[row][col] = 'B';
										  } else if (col == 2) {
													 board[row][col] = 'M';
										  } else if (col == 3) {
													 board[row][col] = 'H';
										  } else if (col == 81) {
													 board[row][col] = 'E';
										  } else if (col == 82) {
													 board[row][col] = 'S';
										  } else if (col == 83) {
													 board[row][col] = 'C';
										  }
								} else if (row == 16) {
										  if (col == 1) {
													 board[row][col] = 'S';
										  } else if (col == 2) {
													 board[row][col] = 'L';
										  } else if (col == 3) {
													 board[row][col] = 'C';
										  } else if (col == 81) {
													 board[row][col] = 'S';
										  } else if (col == 82) {
													 board[row][col] = 'L';
										  } else if (col == 83) {
													 board[row][col] = 'C';
										  }
								} else if (row == 23) {
										  if (col == 1) {
													 board[row][col] = 'L';
										  } else if (col == 2) {
													 board[row][col] = 'H';
										  } else if (col == 3) {
													 board[row][col] = 'I';
										  } else if (col == 81) {
													 board[row][col] = 'C';
										  } else if (col == 82) {
													 board[row][col] = '2';
										  } 
								} else if (row == 26) {
										  if (col == 1) {
													 board[row][col] = 'U';
										  } else if (col == 2) {
													 board[row][col] = 'W';
										  } else if (col == 3) {
													 board[row][col] = 'P';
										  } else if (col == 81) {
													 board[row][col] = 'R';
										  } else if (col == 82) {
													 board[row][col] = 'E';
										  } else if (col == 83) {
													 board[row][col] = 'V';
										  }
								} else if (row == 31) {
										  if (col == 81) {
													 board[row][col] = 'N';
										  } else if (col == 82) {
													 board[row][col] = 'E';
										  } else if (col == 83) {
													 board[row][col] = 'E';
										  } else if (col == 84) {
													 board[row][col] = 'D';
										  } else if (col == 85) {
													 board[row][col] = 'L';
										  } else if (col == 86) {
													 board[row][col] = 'E';
										  } else if (col == 87) {
													 board[row][col] = 'S';
										  }
								} else if (row == 32) {
										  if (col == 81) {
													 board[row][col] = 'H';
										  } else if (col == 82) {
													 board[row][col] = 'A';
										  } else if (col == 83) {
													 board[row][col] = 'L';
										  } else if (col == 84) {
													 board[row][col] = 'L';
										  } 
								} else if (row == 33) {
										  if (col == 1) {
													 board[row][col] = 'C';
										  } else if (col == 2) {
													 board[row][col] = 'P';
										  } else if (col == 3) {
													 board[row][col] = 'H';
										  } 
								} else if (row == 38) {
										  if (col == 1) {
													 board[row][col] = 'D';
										  } else if (col == 2) {
													 board[row][col] = 'W';
										  } else if (col == 3) {
													 board[row][col] = 'E';
										  } else if (col == 81) {
													 board[row][col] = 'M';
										  } else if (col == 82) {
													 board[row][col] = 'C';
										  } 
								} else if (row == 41) {
										  if (col == 1) {
													 board[row][col] = 'P';
										  } else if (col == 2) {
													 board[row][col] = 'A';
										  } else if (col == 3) {
													 board[row][col] = 'C';
										  } else if (col == 81) {
													 board[row][col] = 'C';
										  } else if (col == 82) {
													 board[row][col] = 'O';
										  } else if (col == 83) {
													 board[row][col] = 'O';
										  } else if (col == 84) {
													 board[row][col] = 'P';
										  }
								} else if (row == 42) {
										  if (col == 81) {
													 board[row][col] = 'F';
										  } else if (col == 82) {
													 board[row][col] = 'E';
										  } else if (col == 83) {
													 board[row][col] = 'E';
										  } 
								} else if (row == 48) {
										  if (col == 1) {
													 board[row][col] = 'R';
										  } else if (col == 2) {
													 board[row][col] = 'C';
										  } else if (col == 3) {
													 board[row][col] = 'H';
										  } else if (col == 81) {
													 board[row][col] = 'D';
										  } else if (col == 82) {
													 board[row][col] = 'C';
										  } 
								} else if (row == 1) {
										  if (col == 1) {
													 board[row][col] = 'G';
										  } else if (col == 2) {
													 board[row][col] = 'o';
										  } else if (col == 3) {
													 board[row][col] = 'o';
										  } else if (col == 4) {
													 board[row][col] = 's'; 
										  } else if (col == 5) {
													 board[row][col] = 'e';
										  } else if (col == 17) {
													 board[row][col] = 'N';
										  } else if (col == 18) {
													 board[row][col] = 'E';
										  } else if (col == 19) {
													 board[row][col] = 'E';
										  } else if (col == 20) {
													 board[row][col] = 'D';
										  } else if (col == 21) {
													 board[row][col] = 'L';
										  } else if (col == 22) {
													 board[row][col] = 'E';
										  } else if (col == 23) {
													 board[row][col] = 'S';
										  } else if (col == 41) {
													 board[row][col] = 'V';
										  } else if (col == 42) {
													 board[row][col] = '1';
										  } else if (col == 65) {
													 board[row][col] = 'C';
										  } else if (col == 66) {
													 board[row][col] = 'I';
										  } else if (col == 67) {
													 board[row][col] = 'F';
										  } else if (col == 81) {
													 board[row][col] = 'G';
										  } else if (col == 82) {
													 board[row][col] = 'O';
										  } else if (col == 84) {
													 board[row][col] = 'T';
										  } else if (col == 85) {
													 board[row][col] = 'O';
										  }
								} else if (row == 2) {
										  if (col == 1) {
													 board[row][col] = 'N';
										  } else if (col == 2) {
													 board[row][col] = 'e';
										  } else if (col == 3) {
													 board[row][col] = 's';
										  } else if (col == 4) {
													 board[row][col] = 't'; 
										  } else if (col == 5) {
													 board[row][col] = 'i';
										  } else if (col == 6) {
													 board[row][col] = 'n';
										  } else if (col == 7) {
													 board[row][col] = 'g';
										  } else if (col == 17) {
													 board[row][col] = 'H';
										  } else if (col == 18) {
													 board[row][col] = 'A';
										  } else if (col == 19) {
													 board[row][col] = 'L';
										  } else if (col == 20) {
													 board[row][col] = 'L';
										  } else if (col == 81) {
													 board[row][col] = 'T';
										  } else if (col == 82) {
													 board[row][col] = 'I';
										  } else if (col == 83) {
													 board[row][col] = 'M';
										  } else if (col == 84) {
													 board[row][col] = 'S';
										  } 
								} else if (row == 3) {
										  if (col == 9) {
													 board[row][col] = 'E';
										  } else if (col == 10) {
													 board[row][col] = 'V';
										  } else if (col == 11) {
													 board[row][col] = '1';
										  } else if (col == 25) {
													 board[row][col] = 'E'; 
										  } else if (col == 26) {
													 board[row][col] = 'V';
										  } else if (col == 27) {
													 board[row][col] = '2';
										  } else if (col == 33) {
													 board[row][col] = 'E';
										  } else if (col == 34) {
													 board[row][col] = 'V';
										  } else if (col == 35) {
													 board[row][col] = '3';
										  } else if (col == 49) {
													 board[row][col] = 'P';
										  } else if (col == 50) {
													 board[row][col] = 'H';
										  } else if (col == 51) {
													 board[row][col] = 'Y';
										  } else if (col == 52) {
													 board[row][col] = 'S';
										  } else if (col == 57) {
													 board[row][col] = 'B';
										  } else if (col == 58) {
													 board[row][col] = '1';
										  } else if (col == 73) {
													 board[row][col] = 'B';
										  } else if (col == 74) {
													 board[row][col] = '2';
										  }
								}
					 }
		  }

		  if (numPlayers == 6) {
					 p1->calculate_coordinates();
					 p2->calculate_coordinates();
					 p3->calculate_coordinates();
					 p4->calculate_coordinates();
					 p5->calculate_coordinates();
					 p6->calculate_coordinates();
					 //notify();
		  } else if (numPlayers == 5) {
					 p1->calculate_coordinates();
					 p2->calculate_coordinates();
					 p3->calculate_coordinates();
					 p4->calculate_coordinates();
					 p5->calculate_coordinates();
					 //notify();
		  } else if (numPlayers == 4) {

					 p1->calculate_coordinates();
					 p2->calculate_coordinates();
					 p3->calculate_coordinates();
					 p4->calculate_coordinates();
					 /*
						 cout << "p1x:" << p1->getx() << " " << "p1y:" << p1->gety() << endl;
						 cout << "p2x:" << p2->getx() << " " << "p2y:" << p2->gety() << endl;
						 cout << "p3x:" << p3->getx() << " " << "p3y:" << p3->gety() << endl;
						 cout << "p4x:" << p4->getx() << " " << "p4y:" << p4->gety() << endl;
					  */
					 //notify();
		  } else if (numPlayers == 3) {
					 p1->calculate_coordinates();
					 p2->calculate_coordinates();
					 p3->calculate_coordinates();
					 //notify();
		  } else if (numPlayers == 2) {
					 p1->calculate_coordinates();
					 p2->calculate_coordinates();
					 // notify();
		  }
}

void Board::startgame() { //
		  gameisrunning = 1;
		  TotalMoney = 15140;
		  MAXROLL_UP_RIM = 4;
}

void Board::cleanup() { //
		  delete instance;
}

bool Board::gameover() { //
		  return !gameisrunning;
}

Board *Board::getInstance() { //
		  if (!instance) {
					 instance = new Board();
					 atexit(cleanup);
		  }
		  return instance;
}

int Board::BankAmount() { //
		  return TotalMoney;
}

int Board::getNumPlayers() { //
		  return numPlayers;
}

void Board::setBankAmount(int amt) { //
		  TotalMoney = amt;
}

void Board::setNumPlayers(int numP) { //
		  numPlayers = numP;
}

void Board::improveProp(Cell *property) { //
     string ac = property->getCellName();
		int numIm = property->getNum_Im();
		if (ac == "AL") {
			if (numIm == 0) {
				board[53][73] = 'I';
			} else if (numIm == 1) {
				board[53][74] = 'I';
			} else if (numIm == 2) {
				board[53][75] = 'I';
			} else if (numIm == 3) {
				board[53][76] = 'I';
			} else if (numIm == 4) {
				board[53][77] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "ML") {
			
			if (numIm == 0) {
				board[53][57] = 'I';
			} else if (numIm == 1) {
				board[53][58] = 'I';
			} else if (numIm == 2) {
				board[53][59] = 'I'; 
			} else if (numIm == 3) {
				board[53][60] = 'I';
			} else if (numIm == 4) {
				board[53][61] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "ECH") {
			
			if (numIm == 0) {
				board[53][33] = 'I';
			} else if (numIm == 1) {
				board[53][34] = 'I';
			} else if (numIm == 2) {
				board[53][35] = 'I';
			} else if (numIm == 3) {
				board[53][36] = 'I';
			} else if (numIm == 4) {
				board[53][37] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "PAS") {
			
			if (numIm == 0) {
				board[53][17] = 'I';
			} else if (numIm == 1) {
				board[53][18] = 'I';
			} else if (numIm == 2) {
				board[53][19] = 'I';
			} else if (numIm == 3) {
				board[53][20] = 'I';
			} else if (numIm == 4) {
				board[53][21] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "HH") {
			
			if (numIm == 0) {
				board[53][9] = 'I';
			} else if (numIm == 1) {
				board[53][10] = 'I';
			} else if (numIm == 2) {
				board[53][11] = 'I';
			} else if (numIm == 3) {
				board[53][12] = 'I';
			} else if (numIm == 4) {
				board[53][13] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "RCH") {
			
			if (numIm == 0) {
				board[46][1] = 'I';
			} else if (numIm == 1) {
				board[46][2] = 'I';
			} else if (numIm == 2) {
				board[46][3] = 'I';
			} else if (numIm == 3) {
				board[46][4] = 'I';
			} else if (numIm == 4) {
				board[46][5] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "DWE") {
			
			if (numIm == 0) {
				board[36][1] = 'I';
			} else if (numIm == 1) {
				board[36][2] = 'I';
			} else if (numIm == 2) {
				board[36][3] = 'I';
			} else if (numIm == 3) {
				board[36][4] = 'I';
			} else if (numIm == 4) {
				board[36][5] = 'W'; 
			} else if (numIm == 5) {

			}
		} else if (ac == "CPH") {
			
			if (numIm == 0) {
				board[31][1] = 'I';
			} else if (numIm == 1) {
				board[31][2] = 'I';
			} else if (numIm == 2) {
				board[31][3] = 'I'; 
			} else if (numIm == 3) {
				board[31][4] = 'I';
			} else if (numIm == 4) {
				board[31][5] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "LHI") {
			
			if (numIm == 0) {
				board[21][1] = 'I';
			} else if (numIm == 1) {
				board[21][2] = 'I';
			} else if (numIm == 2) {
				board[21][3] = 'I';
			} else if (numIm == 3) {
				board[21][4] = 'I';
			} else if (numIm == 4) {
				board[21][5] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "BMH") {
			
			if (numIm == 0) {
				board[11][1] = 'I';
			} else if (numIm == 1) {
				board[11][2] = 'I'; 
			} else if (numIm == 2) {
				board[11][3] = 'I';
			} else if (numIm == 3) {
				board[11][4] = 'I';
			} else if (numIm == 4) {
				board[11][5] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "OPT") {
			
			if (numIm == 0) {
				board[6][1] = 'I';
			} else if (numIm == 1) {
				board[6][2] = 'I';
			} else if (numIm == 2) {
				board[6][3] = 'I';
			} else if (numIm == 3) {
				board[6][4] = 'I';
			} else if (numIm == 4) {
				board[6][5] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "EV1") {
			
			if (numIm == 0) {
				board[1][9] = 'I';
			} else if (numIm == 1) {
				board[1][10] = 'I';
			} else if (numIm == 2) {
				board[1][11] = 'I'; 
			} else if (numIm == 3) {
				board[1][12] = 'I';
			} else if (numIm == 4) {
				board[1][13] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "EV2") {
			
			if (numIm == 0) {
				board[1][25] = 'I';
			} else if (numIm == 1) {
				board[1][26] = 'I'; 
			} else if (numIm == 2) {
				board[1][27] = 'I';
			} else if (numIm == 3) {
				board[1][28] = 'I';
			} else if (numIm == 4) {
				board[1][29] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "EV3") {
			
			if (numIm == 0) {
				board[1][33] = 'I';
			} else if (numIm == 1) {
				board[1][34] = 'I';
			} else if (numIm == 2) {
				board[1][35] = 'I';
			} else if (numIm == 3) {
				board[1][36] = 'I';
			} else if (numIm == 4) {
				board[1][37] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "PHYS") {
			
			if (numIm == 0) {
				board[1][49] = 'I';
			} else if (numIm == 1) {
				board[1][50] = 'I';
			} else if (numIm == 2) {
				board[1][51] = 'I';
			} else if (numIm == 3) {
				board[1][52] = 'I';
			} else if (numIm == 4) {
				board[1][53] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "B1") {
			
			if (numIm == 0) {
				board[1][57] = 'I';
			} else if (numIm == 1) {
				board[1][58] = 'I'; 
			} else if (numIm == 2) {
				board[1][59] = 'I';
			} else if (numIm == 3) {
				board[1][60] = 'I';
			} else if (numIm == 4) {
				board[1][61] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "B2") {
			
			if (numIm == 0) {
				board[1][73] = 'I';
			} else if (numIm == 1) {
				board[1][74] = 'I';
			} else if (numIm == 2) {
				board[1][75] = 'I';
			} else if (numIm == 3) {
				board[1][76] = 'I'; 
			} else if (numIm == 4) {
				board[1][77] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "EIT") {
			
			if (numIm == 0) {
				board[6][81] = 'I';
			} else if (numIm == 1) {
				board[6][82] = 'I'; 
			} else if (numIm == 2) {
				board[6][83] = 'I';
			} else if (numIm == 3) {
				board[6][84] = 'I';
			} else if (numIm == 4) {
				board[6][85] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "ESC") {
			
			if (numIm == 0) {
				board[11][81] = 'I';
			} else if (numIm == 1) {
				board[11][82] = 'I';
			} else if (numIm == 2) {
				board[11][83] = 'I';
			} else if (numIm == 3) {
				board[11][84] = 'I';
			} else if (numIm == 4) {
				board[11][85] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "C2") {
			
			if (numIm == 0) {
				board[21][81] = 'I';
			} else if (numIm == 1) {
				board[21][82] = 'I';
			} else if (numIm == 2) {
				board[21][83] = 'I';
			} else if (numIm == 3) {
				board[21][84] = 'I';
			} else if (numIm == 4) {
				board[21][85] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "MC") {
			
			if (numIm == 0) {
				board[36][81] = 'I';
			} else if (numIm == 1) {
				board[36][82] = 'I';
			} else if (numIm == 2) {
				board[36][83] = 'I';
			} else if (numIm == 3) {
				board[36][84] = 'I'; 
			} else if (numIm == 4) {
				board[36][85] = 'W';
			} else if (numIm == 5) {

			}
		} else if (ac == "DC") {
			
			if (numIm == 0) {
				board[46][81] = 'I';
			} else if (numIm == 1) {
				board[46][82] = 'I';
			} else if (numIm == 2) {
				board[46][83] = 'I';
			} else if (numIm == 3) {
				board[46][84] = 'I';
			} else if (numIm == 4) {
				board[46][85] = 'W';
			} else if (numIm == 5) {

			}
		}
}

void Board::unimproveProp(Cell *property) { //
     string ac = property->getCellName();
		int numIm = property->getNum_Im();
		if (ac == "AL") {
			if (numIm == 0) {
				//board[53][73] = 'I';
			} else if (numIm == 1) {
				board[53][73] = ' ';
				//board[53][74] = 'I';
			} else if (numIm == 2) {
				board[53][74] = ' ';
				//board[53][75] = 'I';
			} else if (numIm == 3) {
				board[53][75] = ' ';
				//board[53][76] = 'I';
			} else if (numIm == 4) {
				board[53][76] = ' ';
				//board[53][77] = 'W';
			} else if (numIm == 5) {
                board[53][77] = ' ';
			}
		} else if (ac == "ML") {
			
			if (numIm == 0) {
				//board[53][57] = 'I';
			} else if (numIm == 1) {
				board[53][57] = ' ';
				//board[53][58] = 'I';
			} else if (numIm == 2) {
				board[53][58] = ' ';
				//board[53][59] = 'I'; 
			} else if (numIm == 3) {
				board[53][59] = ' '; 
				//board[53][60] = 'I';
			} else if (numIm == 4) {
				board[53][60] = ' ';
				//board[53][61] = 'W';
			} else if (numIm == 5) {
                board[53][61] = ' ';
			}
		} else if (ac == "ECH") {
			
			if (numIm == 0) {
				//board[53][33] = 'I';
			} else if (numIm == 1) {
				board[53][33] = ' ';
				//board[53][34] = 'I';
			} else if (numIm == 2) {
				board[53][34] = ' ';
				//board[53][35] = 'I';
			} else if (numIm == 3) {
				board[53][35] = ' ';
				//board[53][36] = 'I';
			} else if (numIm == 4) {
				board[53][36] = ' ';
				//board[53][37] = 'W';
			} else if (numIm == 5) {
                board[53][37] = ' ';
			}
		} else if (ac == "PAS") {
			
			if (numIm == 0) {
				//board[53][17] = 'I';
			} else if (numIm == 1) {
				board[53][17] = ' ';
				//board[53][18] = 'I';
			} else if (numIm == 2) {
				board[53][18] = ' ';
				//board[53][19] = 'I';
			} else if (numIm == 3) {
				board[53][19] = ' ';
				//board[53][20] = 'I';
			} else if (numIm == 4) {
				board[53][20] = ' ';
				//board[53][21] = 'W';
			} else if (numIm == 5) {
               board[53][21] = ' ';
			}
		} else if (ac == "HH") {
			
			if (numIm == 0) {
				//board[53][9] = 'I';
			} else if (numIm == 1) {
				board[53][9] = ' ';
				//board[53][10] = 'I';
			} else if (numIm == 2) {
				board[53][10] = ' ';
				//board[53][11] = 'I';
			} else if (numIm == 3) {
				board[53][11] = ' ';
				//board[53][12] = 'I';
			} else if (numIm == 4) {
				board[53][12] = ' ';
				//board[53][13] = 'W';
			} else if (numIm == 5) {
                board[53][13] = ' ';
			}
		} else if (ac == "RCH") {
			
			if (numIm == 0) {
				//board[46][1] = 'I';
			} else if (numIm == 1) {
				board[46][1] = ' ';
				//board[46][2] = 'I';
			} else if (numIm == 2) {
				board[46][2] = ' ';
				//board[46][3] = 'I';
			} else if (numIm == 3) {
				board[46][3] = ' ';
				//board[46][4] = 'I';
			} else if (numIm == 4) {
				board[46][4] = ' ';
				//board[46][5] = 'W';
			} else if (numIm == 5) {
                board[46][5] = ' ';
			}
		} else if (ac == "DWE") {
			
			if (numIm == 0) {
				//board[36][1] = 'I';
			} else if (numIm == 1) {
				board[36][1] = ' ';
				//board[36][2] = 'I';
			} else if (numIm == 2) {
				board[36][2] = ' ';
				//board[36][3] = 'I';
			} else if (numIm == 3) {
				board[36][3] = ' ';
				//board[36][4] = 'I';
			} else if (numIm == 4) {
				board[36][4] = ' ';
				//board[36][5] = 'W'; 
			} else if (numIm == 5) {
                board[36][5] = ' ';
			}
		} else if (ac == "CPH") {
			
			if (numIm == 0) {
				//board[31][1] = 'I';
			} else if (numIm == 1) {
				board[31][1] = ' ';
				//board[31][2] = 'I';
			} else if (numIm == 2) {
				board[31][2] = ' ';
				//board[31][3] = 'I'; 
			} else if (numIm == 3) {
				board[31][3] = ' ';
				//board[31][4] = 'I';
			} else if (numIm == 4) {
				board[31][4] = ' ';
				//board[31][5] = 'W';
			} else if (numIm == 5) {
                board[31][5] = ' ';
			}
		} else if (ac == "LHI") {
			
			if (numIm == 0) {
				//board[21][1] = 'I';
			} else if (numIm == 1) {
				board[21][1] = ' ';
				//board[21][2] = 'I';
			} else if (numIm == 2) {
				board[21][2] = ' ';
				//board[21][3] = 'I';
			} else if (numIm == 3) {
				board[21][3] = ' ';
				//board[21][4] = 'I';
			} else if (numIm == 4) {
				board[21][4] = ' ';
				//board[21][5] = 'W';
			} else if (numIm == 5) {
                board[21][5] = ' ';
			}
		} else if (ac == "BMH") {
			
			if (numIm == 0) {
				//board[11][1] = 'I';
			} else if (numIm == 1) {
				board[11][1] = ' ';
				//board[11][2] = 'I'; 
			} else if (numIm == 2) {
				board[11][2] = ' ';
				//board[11][3] = 'I';
			} else if (numIm == 3) {
				board[11][3] = ' ';
				//board[11][4] = 'I';
			} else if (numIm == 4) {
				board[11][4] = ' ';
				//board[11][5] = 'W';
			} else if (numIm == 5) {
                board[11][5] = ' ';
			}
		} else if (ac == "OPT") {
			
			if (numIm == 0) {
				//board[6][1] = 'I';
			} else if (numIm == 1) {
				board[6][1] = ' ';
				//board[6][2] = 'I';
			} else if (numIm == 2) {
				board[6][2] = ' ';
				//board[6][3] = 'I';
			} else if (numIm == 3) {
				board[6][3] = ' ';
				//board[6][4] = 'I';
			} else if (numIm == 4) {
				board[6][4] = ' ';
				//board[6][5] = 'W';
			} else if (numIm == 5) {
                board[6][5] = ' ';  
			}
		} else if (ac == "EV1") {
			
			if (numIm == 0) {
				//board[1][9] = 'I';
			} else if (numIm == 1) {
				board[1][9] = ' ';
				//board[1][10] = 'I';
			} else if (numIm == 2) {
				board[1][10] = ' ';
				//board[1][11] = 'I'; 
			} else if (numIm == 3) {
				board[1][11] = ' ';
				//board[1][12] = 'I';
			} else if (numIm == 4) {
				board[1][12] = ' ';
				//board[1][13] = 'W';
			} else if (numIm == 5) {
                board[1][13] = ' ';
			}
		} else if (ac == "EV2") {
			
			if (numIm == 0) {
				//board[1][25] = 'I';
			} else if (numIm == 1) {
				board[1][25] = ' ';
				//board[1][26] = 'I'; 
			} else if (numIm == 2) {
				board[1][26] = ' '; 
				//board[1][27] = 'I';
			} else if (numIm == 3) {
				board[1][27] = ' ';
				//board[1][28] = 'I';
			} else if (numIm == 4) {
				board[1][28] = ' ';
				//board[1][29] = 'W';
			} else if (numIm == 5) {
                board[1][29] = ' ';
			}
		} else if (ac == "EV3") {
			
			if (numIm == 0) {
				//board[1][33] = 'I';
			} else if (numIm == 1) {
				board[1][33] = ' ';
				//board[1][34] = 'I';
			} else if (numIm == 2) {
				board[1][34] = ' ';
				//board[1][35] = 'I';
			} else if (numIm == 3) {
				board[1][35] = ' ';
				//board[1][36] = 'I';
			} else if (numIm == 4) {
				board[1][36] = ' ';
				//board[1][37] = 'W';
			} else if (numIm == 5) {
                board[1][37] = ' ';
			}
		} else if (ac == "PHYS") {
			
			if (numIm == 0) {
				//board[1][49] = 'I';
			} else if (numIm == 1) {
				board[1][49] = ' ';
				//board[1][50] = 'I';
			} else if (numIm == 2) {
				board[1][50] = ' ';
				//board[1][51] = 'I';
			} else if (numIm == 3) {
				board[1][51] = ' ';
				//board[1][52] = 'I';
			} else if (numIm == 4) {
				board[1][52] = ' ';
				//board[1][53] = 'W';
			} else if (numIm == 5) {
                board[1][53] = ' ';
			}
		} else if (ac == "B1") {
			
			if (numIm == 0) {
				//board[1][57] = 'I';
			} else if (numIm == 1) {
				board[1][57] = ' ';
				//board[1][58] = 'I'; 
			} else if (numIm == 2) {
				board[1][58] = ' ';
				//board[1][59] = 'I';
			} else if (numIm == 3) {
				board[1][59] = ' ';
				//board[1][60] = 'I';
			} else if (numIm == 4) {
				board[1][60] = ' ';
				//board[1][61] = 'W';
			} else if (numIm == 5) {
                board[1][61] = ' ';
			}
		} else if (ac == "B2") {
			
			if (numIm == 0) {
				//board[1][73] = 'I';
			} else if (numIm == 1) {
				board[1][73] = ' ';
				//board[1][74] = 'I';
			} else if (numIm == 2) {
				board[1][74] = ' ';
				//board[1][75] = 'I';
			} else if (numIm == 3) {
				board[1][75] = ' ';
				//board[1][76] = 'I'; 
			} else if (numIm == 4) {
				board[1][76] = ' ';
				//board[1][77] = 'W';
			} else if (numIm == 5) {
                board[1][77] = ' ';
			}
		} else if (ac == "EIT") {
			
			if (numIm == 0) {
				//board[6][81] = 'I';
			} else if (numIm == 1) {
				board[6][81] = ' ';
				//board[6][82] = 'I'; 
			} else if (numIm == 2) {
				board[6][82] = ' ';
				//board[6][83] = 'I';
			} else if (numIm == 3) {
				board[6][83] = ' ';
				//board[6][84] = 'I';
			} else if (numIm == 4) {
				board[6][84] = ' ';
				//board[6][85] = 'W';
			} else if (numIm == 5) {
                board[6][85] = ' ';
			}
		} else if (ac == "ESC") {
			
			if (numIm == 0) {
				//board[11][81] = 'I';
			} else if (numIm == 1) {
				board[11][81] = ' ';
				//board[11][82] = 'I';
			} else if (numIm == 2) {
				board[11][82] = ' ';
				//board[11][83] = 'I';
			} else if (numIm == 3) {
				board[11][83] = ' ';
				//board[11][84] = 'I';
			} else if (numIm == 4) {
				board[11][84] = ' ';
				//board[11][85] = 'W';
			} else if (numIm == 5) {
                board[11][85] = ' ';
			}
		} else if (ac == "C2") {
			
			if (numIm == 0) {
				//board[21][81] = 'I';
			} else if (numIm == 1) {
				board[21][81] = ' ';
				//board[21][82] = 'I';
			} else if (numIm == 2) {
				board[21][82] = ' ';
				//board[21][83] = 'I';
			} else if (numIm == 3) {
				board[21][83] = ' ';
				//board[21][84] = 'I';
			} else if (numIm == 4) {
				board[21][84] = ' ';
				//board[21][85] = 'W';
			} else if (numIm == 5) {
                board[21][85] = ' ';
			}
		} else if (ac == "MC") {
			
			if (numIm == 0) {
				//board[36][81] = 'I';
			} else if (numIm == 1) {
				board[36][81] = ' ';
				//board[36][82] = 'I';
			} else if (numIm == 2) {
				board[36][82] = ' ';
				//board[36][83] = 'I';
			} else if (numIm == 3) {
				board[36][83] = ' ';
				//board[36][84] = 'I'; 
			} else if (numIm == 4) {
				board[36][84] = ' '; 
				//board[36][85] = 'W';
			} else if (numIm == 5) {
                board[36][85] = ' ';
			}
		} else if (ac == "DC") {
			
			if (numIm == 0) {
				//board[46][81] = 'I';
			} else if (numIm == 1) {
				board[46][81] = ' ';
				//board[46][82] = 'I';
			} else if (numIm == 2) {
				board[46][82] = ' ';
				//board[46][83] = 'I';
			} else if (numIm == 3) {
				board[46][83] = ' ';
				//board[46][84] = 'I';
			} else if (numIm == 4) {
				board[46][84] = ' ';
				//board[46][85] = 'W';
			} else if (numIm == 5) {
                board[46][85] = ' ';
			}
		}
}

void Board::decWhosTurn() {
   WhosTurn--;
}

//void Board::decTotalTurns() {
  //  totalTurns--;
//}

void Board::notifySLCRandom() {
      Player *pl = lastMoved;
		int a = pl->getx();
		int b = pl->gety();
		string s;
		s = identify(b, a);
		char c = pl->getID();
		cout << "Player " << c << " was just randomized by SLC's magic awesomeness and landed on " << s << "." << endl;
		Cell *landedOn = giveMePropOnStr(s);
		landedOn->QueryPlayer(pl);
}

int Board::getNumRollUpRim() {
    return MAXROLL_UP_RIM;
}

void Board::setNumRollUpRim(int num) {
    MAXROLL_UP_RIM = num;
}

void Board::notify() { //
		  //cout << "sup notify" << endl;

		  // for(int i = 0; i < numPlayers; i++) {
		  //  if (subject[i]->getPosn()
		  //		cout << "printing subject id: " << subject[i]->getID() << endl;
		  //	}

		  //cout << "1" << endl;
		  Player *pl = lastMoved;
		  //cout << "2" << endl;
		  int rolledsum = pl->getRolledSum();
		  //cout << "3" << endl;
		  int a = pl->getx();
		  //cout << "a: " << a << endl;
		  //cout << "4" << endl;
		  int b = pl->gety();
		  //cout << "b: " << b << endl;
		  //cout << "5" << endl;
		  string s;
		  //cout << "RIGHT HERE EH" << endl;
		  s = identify(b, a);
		  //cout << "6" << endl;
		  char c = pl->getID();
		  
		  if (lastMoved->amIinline()) {
          cout << "Player " << c << " in line. Following procedures to leave" << endl;
		  } else {
  		     cout << "Player " << c << " just rolled a " << rolledsum << "." << " Moved to " << s << "." << endl;
			}
		//  if ((pl->getLastPosn() >= 28) && (pl->getLastPosn() <= 39)) {
        //     if (pl->getPosn() >= 0) {
          //       cout << "You also just collected $200 OSAP upon crossing" << endl;
				// }
		 // }
       // cout << "Right before this point?" << endl;
        Cell *landedOn = giveMePropOnStr(s);
		  landedOn->QueryPlayer(pl);
		  //cout << s << endl;
		  

		  /*
			  for(int i = 0; i < numPlayers; i++) {
			  if ((subject[i]->getLastx() != subject[i]->getx()) || (subject[i]->getLasty() != subject[i]->gety())) {
			  cout << "----------------- i = " << i << "------------------" << endl;
			  cout << "do you go inside" << endl;
			  int x = subject[i]->getx();
			  cout << "subject[i]->getx():" << subject[i]->getx() << endl;
			  int y = subject[i]->gety();
			  cout << "subject[i]->gety():" << subject[i]->gety() << endl;
		  //board[x][y] = '.';//subject[i]->getID();
		  //cout << "Player: " << "moved to: " << identify(x,y) << "." << endl;
			*/ 
		  //}
		  //}
}

void Board::printBoard() { //
		  for(int i = 0; i < 58; i++) {
					 for(int j = 0; j < 89; j++) {
								cout << board[i][j];
					 }
					 cout << endl;
		  }
}

Cell *Board::giveMePropOnStr(std::string prop) {
  // cout << "did we even go inside this func giveMePropOnStr" << endl;  
	  for(int i = 0; i < 40; i++) {
	     // cout << "i: " << i << endl;
		  if (cells[i]->getCellName() == prop) {
		 //     cout << "cells[i]->getCellName: " << cells[i]->getCellName() << endl;
		     return cells[i];
		 }
	 }
	 
	 return NULL;
 }

std::string Board::identify(int x, int y) { //
		  if (((x >= 0) && (x <= 8)) && ((y >= 0) && (y <= 5))) {
		    // cout << "1" << endl;
					 return "GooseNesting";
		  } else if (((x > 8) && (x <= 16)) && ((y >= 0) && (y <= 5))) {
		  //   cout << "2" << endl;
					 return "EV1";
		  } else if (((x > 16) && (x <= 24)) && ((y >= 0) && (y <= 5))) {
		//	  cout << "3" << endl;
				    return "NeedlesHall";
		  } else if (((x > 24) && (x <= 32)) && ((y >= 0) && (y <= 5))) {
		//	  cout << "4" << endl;		
					return "EV2";
		  } else if (((x > 32) && (x <= 40)) && ((y >= 0) && (y <= 5))) {
		//	  cout << "5" << endl;		 
					 return "EV3";
		  } else if (((x > 40) && (x <= 48)) && ((y >= 0) && (y <= 5))) {
		//	  cout << "6" << endl;		 
					 return "V1";
		  } else if (((x > 48) && (x <= 56)) && ((y >= 0) && (y <= 5))) {
		//	  cout << "7" << endl;		 
					 return "PHYS";
		  } else if (((x > 56) && (x <= 64)) && ((y >= 0) && (y <= 5))) {
		//	  cout << "8" << endl;		
					return "B1";
		  } else if (((x > 64) && (x <= 72)) && ((y >= 0) && (y <= 5))) {
		//	  cout << "9" << endl;		
					return "CIF";
		  } else if (((x > 72) && (x <= 80)) && ((y >= 0) && (y <= 5))) {
		//	  cout << "10" << endl;		
					return "B2";
		  } else if (((x > 80) && (x <= 88)) && ((y >= 0) && (y <= 5))) {
		//	  cout << "11" << endl;
					return "GoToTims";
		  }

		  else if (((x >= 0) && (x <= 8)) && ((y > 5) && (y <= 10))) {
		//	  cout << "12" << endl;	
					return "OPT";
		  } else if (((x >= 80) && (x <= 88)) && ((y > 5) && (y <= 10))) {
		//	  cout << "13" << endl;	
					return "EIT";
		  } else if (((x >= 0) && (x <= 8)) && ((y > 10) && (y <= 15))) {
		//	  cout << "14" << endl;	
					return "BMH";
		  } else if (((x >= 80) && (x <= 88)) && ((y > 10) && (y <= 15))) {
		//	  cout << "15" << endl;	
					return "ESC";
		  } else if (((x >= 0) && (x <= 8)) && ((y > 15) && (y <= 20))) {
		//	  cout << "16" << endl;	
					return "SLC";
		  } else if (((x >= 80) && (x <= 88)) && ((y > 15) && (y <= 20))) {
		//	  cout << "17" << endl;		
					return "SLC";
		  }  else if (((x >= 0) && (x <= 8)) && ((y > 20) && (y <= 25))) {
		//	  cout << "18" << endl;	 
					 return "LHI";
		  } else if (((x >= 80) && (x <= 88)) && ((y > 20) && (y <= 25))) {
		//			 cout << "19" << endl;	 
					 return "C2";
		  }  else if (((x >= 0) && (x <= 8)) && ((y > 25) && (y <= 30))) {
		//			 cout << "20" << endl;	 
					 return "UWP";
		  } else if (((x >= 80) && (x <= 88)) && ((y > 25) && (y <= 30))) {
		//			 cout << "21" << endl;	 
					 return "REV";
		  }  else if (((x >= 0) && (x <= 8)) && ((y > 30) && (y <= 35))) {
		//			 cout << "22" << endl;	 
					 return "CPH";
		  } else if (((x >= 80) && (x <= 88)) && ((y > 30) && (y <= 35))) {
		//			 cout << "23" << endl;	 
					 return "NeedlesHall";
		  }  else if (((x >= 0) && (x <= 8)) && ((y > 35) && (y <= 40))) {
		//			 cout << "24" << endl;	 
					 return "DWE";
		  } else if (((x >= 80) && (x <= 88)) && ((y > 35) && (y <= 40))) {
		//			 cout << "25" << endl;	 
					 return "MC";
		  }  else if (((x >= 0) && (x <= 8)) && ((y > 40) && (y <= 45))) {
		//			 cout << "26" << endl;	 
					 return "PAC";
		  } else if (((x >= 80) && (x <= 88)) && ((y > 40) && (y <= 45))) {
		//			 cout << "27" << endl;	 
					 return "Coop";
		  }  else if (((x >= 0) && (x <= 8)) && ((y > 45) && (y <= 52))) {
		//			 cout << "28" << endl;	 
					 return "RCH";
		  } else if (((x >= 80) && (x <= 88)) && ((y > 45) && (y <= 52))) {
		//			 cout << "29" << endl;	 
					 return "DC";
		  }

		  else if (((x >= 0) && (x <= 8)) && ((y > 52) && (y <= 58))) {
		//			 cout << "30" << endl;	 
					 return "DCTimsLine";
		  } else if (((x > 8) && (x <= 16)) && ((y > 52) && (y <= 58))) {
		//			 cout << "31" << endl;	 
					 return "HH";
		  } else if (((x > 16) && (x <= 24)) && ((y >= 52) && (y <= 58))) {
	  //				 cout << "32" << endl;	 
					 return "PAS";
		  } else if (((x > 24) && (x <= 32)) && ((y >= 52) && (y <= 58))) {
		//			 cout << "33" << endl;	 
					 return "NeedlesHall";
		  } else if (((x > 32) && (x <= 40)) && ((y >= 52) && (y <= 58))) {
		//			 cout << "34" << endl;	 
					 return "ECH";
		  } else if (((x > 40) && (x <= 48)) && ((y >= 52) && (y <= 58))) {
		//			 cout << "35" << endl;	 
					 return "MKV";
		  } else if (((x > 48) && (x <= 56)) && ((y >= 52) && (y <= 58))) {
		//			 cout << "36" << endl;	 
					 return "Tuition";
		  } else if (((x > 56) && (x <= 64)) && ((y >= 52) && (y <= 58))) {
		//			 cout << "37" << endl;	 
					 return "ML";
		  } else if (((x > 64) && (x <= 72)) && ((y >= 52) && (y <= 58))) {
		//			 cout << "38" << endl;	 
					 return "SLC";
		  } else if (((x > 72) && (x <= 80)) && ((y >= 52) && (y <= 58))) {
		//			 cout << "39" << endl;	 
					 return "AL";
		  } else if (((x > 80) && (x <= 88)) && ((y >= 52) && (y <= 58))) {
		//			 cout << "40" << endl;	 
					 return "CollectOsap";
		  }
}


void Board::initializeCells() {

     cells[0] = new CollectOsap("CollectOsap", 0, this);
	  cells[1] = new Academic("AL", 1, this, 40, 20, "Arts1", 50);
	  cells[2] = new SLC("SLC", 2, this);
	  cells[3] = new Academic("ML", 3, this, 60, 30, "Arts1", 50);
	  cells[4] = new Tuition("Tuition", 4, this);
	  cells[5] = new Residence("MKV", 5, this, 200, 100);
	  cells[6] = new Academic("ECH", 6, this, 100, 50, "Arts2", 50);
	  cells[7] = new NeedlesHall("NeedlesHall", 7, this);
	  cells[8] = new Academic("PAS", 8, this, 100, 50, "Arts2", 50);
	  cells[9] = new Academic("HH", 9, this, 120, 60, "Arts2", 50);
	  cells[10] = new DcTimsLine("DCTimsLine", 10, this);
	  cells[11] = new Academic("RCH", 11, this, 140, 70, "Eng", 100);
	  cells[12] = new Gym("PAC", 12, this, 150, 75);
	  cells[13] = new Academic("DWE", 13, this, 140, 70, "Eng", 100);
	  cells[14] = new Academic("CPH", 14, this, 160, 80, "Eng", 100);
	  cells[15] = new Residence("UWP", 15, this, 200, 100);
	  cells[16] = new Academic("LHI", 16, this, 180, 90, "Health", 100);
	  cells[17] = new SLC("SLC", 17, this);
	  cells[18] = new Academic("BMH", 18, this, 180, 90, "Health", 100);
	  cells[19] = new Academic("OPT", 19, this, 200, 100, "Health", 100);
	  cells[20] = new Goose("GooseNesting", 20, this);
	  cells[21] = new Academic("EV1", 21, this, 220, 110, "Env", 150);
	  cells[22] = new NeedlesHall("NeedlesHall", 22, this);
	  cells[23] = new Academic("EV2", 23, this, 220, 110, "Env", 150);
	  cells[24] = new Academic("EV3", 24, this, 240, 120, "Env", 150);
	  cells[25] = new Residence("V1", 25, this, 200, 100);
	  cells[26] = new Academic("PHYS", 26, this, 260, 130, "Sci1", 150);
	  cells[27] = new Academic("B1", 27, this, 260, 130, "Sci1", 150);
	  cells[28] = new Gym("CIF", 28, this, 150, 75);
	  cells[29] = new Academic("B2", 29, this, 280, 140, "Sci1", 150);
	  cells[30] = new GoToTims("GoToTims", 30, this);
	  cells[31] = new Academic("EIT", 31, this, 300, 150, "Sci2", 200);
	  cells[32] = new Academic("ESC", 32, this, 300, 150, "Sci2", 200);
	  cells[33] = new SLC("SLC", 33, this);
	  cells[34] = new Academic("C2", 34, this, 320, 160, "Sci2", 200);
	  cells[35] = new Residence("REV", 35, this, 200, 100);
	  cells[36] = new NeedlesHall("NeedlesHall", 36, this);
	  cells[37] = new Academic("MC", 37, this, 350, 175, "Math", 200);
	  cells[38] = new Coop("Coop", 38, this);
	  cells[39] = new Academic("DC", 39, this, 400, 200, "Math", 200);

}


