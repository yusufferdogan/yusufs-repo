#include <iostream>
#include <fstream>
class NPuzzle{
public:
  void printReport();
  void shuffle();
  char moveRandom();
  char moveIntelligent();
  void solvePuzzle();
  void FindCoord(int*,int*);
  private:
  class Board{
  public:
    void print();
    void readFromfile();
    void writeToFile();
    void reset();
    void setsize(int,int);
    void move(char);
    bool isSolved();
    bool isDirectionValid(char);
private:
    int area[9][9];
    int width;
    int height;
    int coord_x;
    int coord_y;
   char Move;
  };
  Board obj;
};
using namespace std;

int main(int argc, char const *argv[]) {
  /*if (argc == 1) {
  }
  else {
  }*/
  return 0;
}
void NPuzzle::Board ::setsize(int h1,int w1){
    height = h1;
    width  = w1;
}
void NPuzzle::Board ::print(){
  NPuzzle::Board::setsize(5,6);
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

//void NPuzzle::reset(){
//}
void NPuzzle::Board::move(char Move)
{
  switch (Move){
    case 'W':
    case 'w':
      if (coord_y -1 >= 0 && area[coord_y-1][coord_x] != 0)
      {
        swap(area[coord_y][coord_x],area[coord_y-1][coord_x]);
        coord_y -= 1;
      }
      break;
    case 's':
    case 'S':
      if(coord_y+1 < height && area[coord_y+1][coord_x] != 0)
        {
          swap(area[coord_y][coord_x],area[coord_y+1][coord_x]);
          coord_y += 1;
        }
      break;
    case 'A':
    case 'a':
      if(coord_x -1 >= 0 && area[coord_y][coord_x-1] != 0)
        {
          swap(area[coord_y][coord_x],area[coord_y][coord_x-1]);
          coord_x -= 1;
        }
      break;
    case 'd':
    case 'D':
      if(coord_x+1 < width && area[coord_y][coord_x+1] != 0)
        {
          swap(area[coord_y][coord_x],area[coord_y][coord_x+1]);
          coord_x += 1;
        }
      break;
  }
}
void NPuzzle::Board ::writeToFile(){
  string savefile;
  int temp[81];
  cout << "enter a file name to save the current board configuration" << endl;
  cin >> savefile;
  ofstream sboard;
  sboard.open(savefile);
  if (sboard.is_open())//checks the file is open or not
  {
    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
          if (area[i][j] == -1)
          {
            sboard << "bb" << " ";
          }
          else if (area[i][j] < 10)
          {
            sboard << "0" << area[i][j] << " ";
          }
          else if (temp[i] >= 10)
          {
            sboard << area[i][j] << " ";
          }
        }
        sboard << endl;
      }
  }
  sboard.close();
  cout << "BOARD CONFİGURATİON İS SAVED TO : " << savefile << endl;
  NPuzzle::Board ::print();
}
void NPuzzle::Board ::readFromfile(){
  ifstream board;
  int temp[81];
  string filename;
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
  width = i / height;
  //total/height = width
  int k = 0;
  for(int i = 0;i < height ;i++){
      for(int j = 0;j < width ;j++){
        area[i][j] = temp[k++];
      }
    }
   board.close(); //closing file
   FindCoord(&coord_x,&coord_y);
   NPuzzle::Board ::print();
}
void NPuzzle::FindCoord(int *coord_x,int *coord_y){
  for(int i = 0;i < height ;i++){
    for(int j = 0;j < width ;j++){
      if(area[i][j] == -1) {
      //-1 means empty place
        *coord_y = i;
        *coord_x = j;
      }
    }
  }
}
void NPuzzle::shuffle(){
  int index;
  const char moving[4] = {'w','s','a','d'};
  do{
  	for (int i = 0; i < height*width; ++i)
  	{
  		index = rand()%4;
  		move(moving[index]);
  	}
  }
  while(!isDirectionValid(moving[index]));
}
int Compare(int *arr){
  int min = arr[0];
    for (int i = 0; i < 4; i++)
    {
        if (min >= arr[i])
            min = arr[i];
    }
    for (int i = 0; i < 4; i++)
    {
        if (min == arr[i])
            return i;
    }
}
bool isDirectionValid(char Move)
{
   switch (Move){
    case 'W':
    case 'w':
      if (coord_y -1 >= 0 && area[coord_y-1][coord_x] != 0)
          return true;
      break;
    case 's':
    case 'S':
      if(coord_y + 1 < height && area[coord_y+1][coord_x] != 0)
        {
          return true;
        }
      break;
    case 'A':
    case 'a':
      if(coord_x -1 >= 0 && area[coord_y][coord_x-1] != 0)
        {
          return true;
        }
      break;
    case 'd':
    case 'D':
      if(coord_x+1 < width && area[coord_y][coord_x+1] != 0)
        {
          return true;
        }
      break;
    case 'f':
    case 'F':
      return true;
    break;
    case 'i':
    case 'I':
      return true;
    break;
    case 't':
    case 'T':
      return true;
    break;
    case 'E':
    case 'e':
      return true;
    break;
    case 'v':
    case 'V':
      return true;
    break;
    case 'l':
    case 'L':
      return true;
    break;
      default:
      return false;
  }
}
