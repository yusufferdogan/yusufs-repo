#include "AbstractBoard.h"
#include "BoardVector.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
namespace yusuf
{
  BoardVector::BoardVector()
  {
    Numberofobj = 0;
    Move = 's';
    moveCount = 0;
    char c;
    cout << "do you wanna enter filename for BoardVector ? (y/n)\n";
    cin >> c;
    if (c == 'y') {
      readFromfile();
    }
    else if (c == 'n'){
      cout << "Enter the height and width for BoardVector" << endl;  // taking size
      // creating 2d vector
      setsize();
      Vector.resize(height);
      for (int i = 0; i < height; i++) {
        Vector[i].resize(width);
      }
      setboard();
      print();
    }
    Numberofobj++;
  }
  BoardVector::~BoardVector()
  //destructor of BoardVector
  {
    for(int i = 0; i < width; i++) {
      Vector[i].clear();
    }
    Vector.clear();
    Numberofobj--;
  }
  void BoardVector::setboard()
  {//setting board when no file
    int k = 1;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (k == height*width) {
          Vector[i][j] = -1;
          k++;
        }
        else{
          Vector[i][j] = k++;
        }
      }
    }
    coord_x = width  -1;
    coord_y = height -1;
  }
  void BoardVector::reset(){
    //takes the board to final solution
    int goal[9][9];
    int k = 1;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (Vector[i][j] != 0 || Vector[i][j] != -1) {
          goal[i][j] = k++;
        }
        else {
          goal[i][j] = Vector[i][j];
        }
      }
    }
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        Vector[i][j] = goal[i][j];
      }
    }
  }
  void BoardVector::move()
  {
    //move the blank
    switch (Move){
      case 'u':
      case 'U':
      //up
        if (coord_y -1 >= 0 && Vector[coord_y-1][coord_x] != 0)
        {
          swap(Vector[coord_y][coord_x],Vector[coord_y-1][coord_x]);
          coord_y -= 1;
        }
        break;
      case 'd':
      case 'D':
      //down
        if(coord_y+1 < height && Vector[coord_y+1][coord_x] != 0)
          {
            swap(Vector[coord_y][coord_x],Vector[coord_y+1][coord_x]);
            coord_y += 1;
          }
        break;
      case 'l':
      case 'L':
        if(coord_x -1 >= 0 && Vector[coord_y][coord_x-1] != 0)
          {
            swap(Vector[coord_y][coord_x],Vector[coord_y][coord_x-1]);
            coord_x -= 1;
          }
        break;
      case 'R':
      case 'r':
        if(coord_x+1 < width && Vector[coord_y][coord_x+1] != 0)
          {
            swap(Vector[coord_y][coord_x],Vector[coord_y][coord_x+1]);
            coord_x += 1;
          }
        break;
    }
    moveCount++;
  }
  void BoardVector::readFromfile()
  {
    for(int i = 0; i < width; i++) {
      //erasing the current board and creates the new one
      Vector[i].clear();
    }
    Vector.clear();
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
    Vector.resize(height);
    for (int i = 0; i < height; i++)
    {
      Vector[i].resize(width);
    }
    int k = 0;
    for(int i = 0;i < height ;i++){
        for(int j = 0;j < width ;j++){
          Vector[i][j] = temp[k++];
        }
      }
     board.close(); //closing file
     FindCoord();
     print();
  }
  int BoardVector::operator()(int y,int x)
  {
    return Vector[y][x];
  }
}
