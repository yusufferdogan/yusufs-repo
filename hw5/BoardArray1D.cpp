#include "AbstractBoard.h"
#include "BoardArray1D.h"
#include <iostream>
#include <fstream>
using namespace std;
namespace yusuf{
  BoardArray1D::BoardArray1D()
  {
    Numberofobj = 0;
    Move = 's';
    moveCount = 0;
    char c;
    cout << "do you wanna enter filename for BoardArray1D ? (y/n)\n";
    cin >> c;
    if (c == 'y') {
      readFromfile();
    }
    else if (c == 'n'){
      cout << "Enter the height and width for BoardArray1D" << endl;  // taking size
      setsize();
      Array1D = new int[height*width];
      setboard();
      print();
    }
    Numberofobj++;
  }
  BoardArray1D::~BoardArray1D()
  {
    delete [] Array1D ;
    Numberofobj--;
  }
  void BoardArray1D::setboard()
  {
    int k = 1;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (k == height*width) {
          Array1D[i*height + j] = -1;
        }
        else{
          Array1D[i*height + j] = k++;
        }
      }
    }
    coord_x = width  -1;
    coord_y = height -1;
  }
  void BoardArray1D::reset(){
    //takes the board to final solution
    AbstractBoard& obj = *this;
    int goal[9][9];
    int k = 1;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (obj(i,j) != 0 || obj(i,j) != -1) {
          goal[i][j] = k++;
        }
        else {
          goal[i][j] = obj(i,j);
        }
      }
    }
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        Array1D[i*height+j] = goal[i][j];
      }
    }
  }
  void BoardArray1D::move()
  {
    //move the blank
    FindCoord();
    switch (Move){
      case 'u':
      case 'U':
      //up
        if (coord_y -1 >= 0 && Array1D[(coord_y-1)*height+coord_x+1] != 0)
        {
          swap(Array1D[coord_y*height+coord_x+1],Array1D[(coord_y-1)*height+coord_x+1]);
          coord_y -= 1;
        }
        break;
      case 'd':
      case 'D':
      //down
        if(coord_y+1 < height && (Array1D[(coord_y+1)*height+coord_x+1])!= 0)
          {
            swap(Array1D[coord_y*height+coord_x+1],Array1D[(coord_y+1)*height+coord_x+1]);
            coord_y += 1;
          }
        break;
      case 'l':
      case 'L':
        if(coord_x -1 >= 0 && Array1D[coord_y*height+coord_x] != 0)
          {
            swap(Array1D[coord_y*height+coord_x+1],Array1D[coord_y*height+coord_x]);
            coord_x -= 1;
          }
        break;
      case 'R':
      case 'r':
        if(coord_x+1 < width && Array1D[coord_y*height+coord_x+2] != 0)
          {
            swap(Array1D[coord_y*height+coord_x+1],Array1D[coord_y*height+coord_x+2]);
            coord_x += 1;
          }
        break;
    }
    moveCount++;
  }
  void BoardArray1D::readFromfile(){
    string filename;
    std::cout << "enter filename" << '\n';
    cin >> filename;
    ifstream Rboard;
    Rboard.open(filename);
    int temp[81];
    width  = 0;
    height = 0;
    char x[4];
    int i = 0;
    delete [] Array1D ;
    if (Rboard.is_open())//checks the file is open or not
    {
      while(!Rboard.eof()){
        while(Rboard >> x){
          //taking numbers
        	temp[i++] = ('b' == x[0]) ? -1 : atoi(x);
          if (Rboard.peek() != 32 )//checking the newline
          {
            height++;
          }
        }
      }
    }
    else {
      cout << "file could not founded\n";
      exit(1);
    }
    width = i / height;
    Array1D = new int[height*width];
    int k = 0;
    for(int i = 0;i < height ;i++){
        for(int j = 0;j < width ;j++){
        Array1D[i*height+j] = temp[k++];
        }
      }
     Rboard.close(); //closing file
     FindCoord();
     print();
  }
  int BoardArray1D::operator()(int y,int x)
  {
    return Array1D[y*height+x];
  }

}
