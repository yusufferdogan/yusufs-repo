/*
Ahmet Yusuf ERDOĞAN HW5
Loadfile dosyaları ile  GlobalFunc test edebilirsiniz
Ben burda bütün metotları test etmeye çalıştım ama edemediğim varsa siz edebilirsiniz
Mainden argüman alma şeklinde yapmadım pdf te öyle bişi yazmıyordu
*/
#include "AbstractBoard.h"
#include "BoardArray1D.h"
#include "BoardArray2D.h"
#include "BoardVector.h"
#include <iostream>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
using namespace yusuf;
bool GlobalFunc(AbstractBoard** pBoard,int size){
  // int this function i tried to compare the board and if they are sequance of each other
  // it returns true .You can see it in the test files
  int x ,x1, y, y1;
  bool flag = true;
  for (int i = 0; i < size-1; i++)
  // compare until the last board
  {
    // finding coodinates
    pBoard[i]->FindCoord();
    // taking coodinates
    x = pBoard[i]->getx();
    y = pBoard[i]->gety();

    // i am gonna compare this two boards
    pBoard[i+1]->FindCoord();
    x1 = pBoard[i+1]->getx();
    y1 = pBoard[i+1]->gety();
    // checking coodinates
    if ((x == x1 && y == y+1) ||  (x == x1 && y == y-1) || (x == x1-1 && y == y1) ||(x == x1+1 && y == y1)) {
      flag = true;
    }
    else
     flag = false;
  }
  return flag;
}
int main(int argc, char const *argv[]) {
  AbstractBoard* pBoard[5];
  pBoard[0] = new BoardArray1D();
  pBoard[1] = new BoardArray2D();
  pBoard[2] = new BoardVector();
  // testing Gloabal func
  // i can compare different type of boards
  if (GlobalFunc(pBoard,3)) {
    cout << "Global func returned true\n";
  }
  else{
    cout << "Global func returned false\n";
  }
  cout << "----------------------------------\n";
  //pBoard[0]-> setmove('r');// you can test the move func here
  //pBoard[0]-> move();
  //pBoard[0]-> print();
  for (int i = 0; i < 3; ++i)
  {
    pBoard[i]->isSolved();
    pBoard[i]->print();
    cout << "NumberOfBoards is : "  << pBoard[i]-> NumberOfBoards() << endl;
    cout << "lastMove is : "        << pBoard[i]-> lastMove()       << endl;
    cout << "NumberOfMoves is : "   << pBoard[i]-> NumberOfMoves()  << endl;
    cout << "-----------------------------------" << endl;
  }
  if (pBoard[0] == pBoard[3]) {
    cout << "Two Boards are equal\n";
  }
  else {
    cout << "Two Boards are not equal\n";
  }
  return 0;
}
