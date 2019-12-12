#ifndef ABSTRACTBOARD_H
#define ABSTRACTBOARD_H
using namespace std;
#include <iostream>
namespace yusuf
{
  class AbstractBoard{
  protected:
    // Variables
    int  width;
    int  height;
    int  coord_x;
    int  coord_y;
    int  numberofboards;
    int  LastMove;
    int  Numberofmoves;
    int  Numberofobj;
    int  moveCount;
    char Move;
  public:
    // functions
    void setsize();
    int  NumberOfBoards();
    char lastMove();
    int  NumberOfMoves();
    int  getx();
    int  gety();
    void setmove(char);
    virtual void print();
    virtual void writeToFile(string) ;
    virtual bool isSolved() ;
    virtual void readFromfile()=0;
    virtual void reset()=0;
    virtual void move()=0;
    virtual void FindCoord();
    virtual void setboard()=0 ;
    virtual int  operator()(int x,int y)=0 ;
    virtual bool operator==(AbstractBoard&);
  };
}

#endif //ABSTRACTBOARD_H
