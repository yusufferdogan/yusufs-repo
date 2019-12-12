#ifndef BOARDARRAY1D_H
#define BOARDARRAY1D_H
#include <iostream>
#include "AbstractBoard.h"
using namespace std;
namespace yusuf
{
  class BoardArray1D : public AbstractBoard{
  protected:
    int *Array1D;
  public:
    BoardArray1D();
   ~BoardArray1D();
    //BoardArray1D(BoardArray1D&);
    void readFromfile() ;
    void reset() ;
    void move() ;
    void setboard() ;
    int  operator()(int y,int x);
  };
}
#endif //BOARDARRAY1D_H
