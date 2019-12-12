#include "AbstractBoard.h"
#include "BoardArray2D.h"
#include <iostream>
#include <fstream>
using namespace std;
namespace yusuf{
  BoardArray2D::BoardArray2D()
  {
    Numberofobj = 0;
    Move = 's';
    moveCount = 0;
    char c;
    cout << "do you wanna enter filename for BoardArray2D ? (y/n)\n";
    cin >> c;
    if (c == 'y') {
      readFromfile();
    }
    else if (c == 'n'){
      cout << "Enter the height and width for BoardArray2D" << endl;  // taking size
      setsize();
      Array2D = new int*[height];
      for(int i = 0; i < height; ++i) {
        Array2D[i] = new int[width];
      }
      setboard();
      print();
    }
    Numberofobj++;
  }
  BoardArray2D::~BoardArray2D()
  {
    for(int i = 0; i < height; ++i) {
      delete [] Array2D[i];
    }
    delete [] Array2D;
    Numberofobj--;
  }
  void BoardArray2D::setboard()
  {//setting board when no file
    int k = 1;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (k == height*width) {
          Array2D[i][j] = -1;
          k++;
        }
        else{
          Array2D[i][j] = k++;
        }
      }
    }
    coord_x = width  -1;
    coord_y = height -1;
  }
  void BoardArray2D::reset(){
    //takes the board to final solution
    int goal[9][9];
    int k = 1;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (Array2D[i][j] != 0 || Array2D[i][j] != -1) {
          goal[i][j] = k++;
        }
        else {
          goal[i][j] = Array2D[i][j];
        }
      }
    }
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        Array2D[i][j] = goal[i][j];
      }
    }
  }
  void BoardArray2D::move()
  {
    //move the blank
    switch (Move){
      case 'u':
      case 'U':
      //up
        if (coord_y -1 >= 0 && Array2D[coord_y-1][coord_x] != 0)
        {
          swap(Array2D[coord_y][coord_x],Array2D[coord_y-1][coord_x]);
          coord_y -= 1;
        }
        break;
      case 'd':
      case 'D':
      //down
        if(coord_y+1 < height && Array2D[coord_y+1][coord_x] != 0)
          {
            swap(Array2D[coord_y][coord_x],Array2D[coord_y+1][coord_x]);
            coord_y += 1;
          }
        break;
      case 'l':
      case 'L':
        if(coord_x -1 >= 0 && Array2D[coord_y][coord_x-1] != 0)
          {
            swap(Array2D[coord_y][coord_x],Array2D[coord_y][coord_x-1]);
            coord_x -= 1;
          }
        break;
      case 'R':
      case 'r':
        if(coord_x+1 < width && Array2D[coord_y][coord_x+1] != 0)
          {
            swap(Array2D[coord_y][coord_x],Array2D[coord_y][coord_x+1]);
            coord_x += 1;
          }
        break;
    }
    moveCount++;
  }
  void BoardArray2D::readFromfile()
  {
    string filename;
    std::cout << "enter filename" << '\n';
    cin >> filename;
    ifstream board;
    int temp[81];
    board.open(filename);
    width  = 0;
    height = 0;
    char x[4];
    int i = 0;
    for(int i = 0; i < height; ++i) {
      delete [] Array2D[i];
    }
    delete [] Array2D;
    if (board.is_open())//checks the file is open or not
    {
      while(!board.eof()){
        while(board >> x){
          //taking numbers
        	temp[i++] = ('b' == x[0]) ? -1 : atoi(x);
          if (board.peek() != 32 )//checking the newline
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
    Array2D = new int*[height];
    for(int i = 0; i < height; ++i) {
      Array2D[i] = new int[width];
    }
    int k = 0;
    for(int i = 0;i < height ;i++){
        for(int j = 0;j < width ;j++){
          Array2D[i][j] = temp[k++];
        }
      }
     board.close(); //closing file
     FindCoord();
     print();
  }
  int BoardArray2D::operator()(int y,int x)
  {
    return Array2D[y][x];
  }
}
