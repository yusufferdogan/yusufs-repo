#include <iostream>
#include <fstream>
#include "AbstractBoard.h"
using namespace std;
namespace yusuf
{
  void AbstractBoard::print()
  {
  //  using std::cout,std::endl;
    AbstractBoard& obj = *this;
    for (int i = 0; i < width; ++i)
    {
      cout << "----";
    }
    cout << "-" << endl;
     for(int i = 0;i < height ;i++){
         for(int j = 0;j < width ;j++){
             if(obj(i,j) == -1){//blank
                 cout << "| bb";
             }
             else {
                 if (obj(i,j) < 10)
                 {
                   cout << "|" << " 0"  << obj(i,j);
                 }
                 else
                   cout << "|" << " " << obj(i,j);
             }
             if(j == width-1){
                cout << "|" <<endl;
                cout << "-";
                for (int i = 0; i < width; ++i)
                {
                  cout << "----";
                }
                cout<< endl;
             }
         }
      }
      cout << "\n\n\n\n\n";
  }
  void AbstractBoard::writeToFile(std::string savefile)
  {
    AbstractBoard& obj = *this;
    ofstream sboard;
    sboard.open(savefile);
    if (sboard.is_open())//checks the file is open or not
    {
      for (int i = 0; i < height; i++)
      {
        for (int j = 0; j < width; j++)
        {
            if (obj(i,j) == -1)//blank
            {
              sboard << "bb" << " ";
            }
            else if (obj(i,j) < 10)
            {
              sboard << "0" << obj(i,j) << " ";
            }
            else if (obj(i,j) >= 10)
            {
              sboard << obj(i,j) << " ";
            }
          }
          sboard << endl;
        }
      }
    sboard.close();//close the board
    cout << "BOARD CONFİGURATİON İS SAVED TO : " << savefile << endl;
    print();
  }
  void AbstractBoard::setsize()//Array1D[i]
  {
    int h1,w1;
    do
    {
      cin >> h1;
      cin >> w1;
    } while(h1 < 3 || h1 > 9 || w1 < 3 || w1 > 9);

      height    = h1;
      width     = w1;
  }
  bool AbstractBoard::isSolved()
  {
    AbstractBoard& obj = *this;
    int goal[9][9];
    int k = 1;
    int count = 0;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (obj(i,j) == 0 || obj(i,j) == -1) {
          goal[i][j] = obj(i,j);
        }
        else {
          goal[i][j] = k++;;
        }
      }
    }
    for (int i = 0; i < height; i++) {
       for (int j = 0; j < width; j++) {
          if (goal[i][j] == obj(i,j))   {
            count++ ;
          }
        }
      }
    if (count == width*height) {
      return true;
    }
    else {
      return false;
    }
  }
  void AbstractBoard::FindCoord()
  {
    AbstractBoard& obj = *this;
    for(int i = 0;i < height ;i++)
    {
      for(int j = 0;j < width ;j++)
      {
        if(obj(i,j) == -1)
        {
        //-1 means empty place
        coord_y = i;//index of blank
        coord_x = j;
        }
      }
    }
  }
  bool AbstractBoard::operator==(AbstractBoard& other)
  {
    AbstractBoard& obj = *this;
    for(int i = 0;i < height ;i++)
    {
      for(int j = 0;j < width ;j++)
      {
        if(obj(i,j) != other(i,j))
        {
          return false;
        }
      }
    }
    return true;
  }
  int AbstractBoard::NumberOfBoards()
  {
    return Numberofobj;
  }
  char AbstractBoard::lastMove()
  {
    return Move;
  }
  int AbstractBoard::NumberOfMoves()
  {
    return moveCount;
  }
  int AbstractBoard::getx(){return coord_x;}
  int AbstractBoard::gety(){return coord_y;}
  void AbstractBoard::setmove(char c){Move = c;}
}
