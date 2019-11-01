#include <iostream>
#include <fstream>
class NPuzzle{
public:
  void print();
  void printReport();
  void readFromfile();
  void writeToFile();
  void shuffle();
  void setsize();
  char moveRandom();
  char moveIntelligent();
  void move();
  void solvePuzzle();
  void reset();
  class Board{
  public:
    void print();
    void readFromfile();
    void writeToFile();
    void reset();
    void setsize();
    void move();
    bool isSolved();
private:
    int board[9][9];
  };
private:
  int area[9][9];
  int width;
  int height;
  int coord_x;
  int coord_y;

};
using namespace std;

int main(int argc, char const *argv[]) {

  return 0;
}
void NPuzzle::print(){
  for (int i = 0; i < width; ++i)
  {
    cout << "----";
  }
  cout << "-" << endl;
   for(int i = 0;i < height ;i++){
       for(int j = 0;j < width ;j++){
           if(area[i][j] == -1){
               cout << "| bb";
           }
           else {
               if (area[i][j] < 10)
               {
                 cout << "|" << " 0"  << area[i][j] ;
               }
               else
                 cout << "|" << " " << area[i][j] ;
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
void NPuzzle::setsize(int h1,int w1){
    height = h1;
    width  = w1;
}
void NPuzzle::reset(){

}
