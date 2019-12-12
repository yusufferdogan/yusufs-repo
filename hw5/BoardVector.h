#ifndef BOARDVECTOR_H
#define BOARDVECTOR_H
#include <iostream>
#include <vector>
#include "AbstractBoard.h"
#include "BoardVector.h"
using namespace std;
namespace yusuf
{
  class BoardVector : public AbstractBoard{
  protected:
    vector <vector<int>> Vector;
  public:
    BoardVector();
   ~BoardVector();
    void readFromfile() ;
    void reset() ;
    void move() ;
    void setboard() ;
    int  operator()(int y,int x);
  };
}
#endif //BOARDVECTOR_H
