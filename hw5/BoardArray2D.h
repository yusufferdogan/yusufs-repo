#ifndef BOARDARRAY2D_H
#define BOARDARRAY2D_H
#include <iostream>
#include "AbstractBoard.h"
using namespace std;
namespace yusuf
{
  class BoardArray2D : public AbstractBoard{
  protected:
    int **Array2D;
  public:
    BoardArray2D();
   ~BoardArray2D();
    void readFromfile() ;
    void reset() ;
    void move() ;
    void setboard() ;
    int  operator()(int y,int x);
  };
}
#endif //BOARDARRAY2D_H
