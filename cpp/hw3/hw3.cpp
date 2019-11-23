#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class NPuzzle{
public:
  void printReport();
  void shuffle();
  void moveRandom();
  char IntelligentMove();
  void solvePuzzle();
  void print();
  void readFromfile(string name);
  void writeToFile(string name);
  void reset();
  void setsize();
  void move();
  bool isSolved();
  void menu(int argc, char const *argv[]);
  private:
  class Board{
  public:

    void print()const;
    void printReport()const;
    void readFromfile(string name);
    void writeToFile(string name)const;
    void reset();
    void setsize();
    void move();
    bool isSolved()const;
    bool isDirectionValid();
    void FindCoord();
    void setboard();

    void setwidth(int w){w = width;}
    void setheight(int h){h = height;}
    void setCoordinates(int x,int y){coord_x = x,coord_y = y;}
    void setMove(char m)    {Move = m;}

    char getmove()          {return Move;}
    int  getwidth()         {return width;}
    int  getheight()        {return height;}
    int  getnum(int x,int y){return area[y][x];}
    int  getx(){return coord_x;}
    int gety(){return coord_y;}

    private:
    int area[9][9];
    int width;
    int height;
    int coord_x;
    int coord_y;
   char Move;
  };
  NPuzzle ::Board obj;
};
int main(int argc, char const *argv[])
{
  NPuzzle game;
  srand(time(NULL));
  game.menu(argc,argv);
  return 0;
}
void NPuzzle::menu(int argc, char const *argv[])
{
  if (argc == 1){
        setsize();
        obj.setboard();
        shuffle();
        print();
  }
  else if (argc == 2) {
    readFromfile(argv[1]);
  }
  else{
    cout << "too much argument count program aborted\n" << endl;
    exit(1);
   }
  char movement;
  string savefile,loadfile;
  char Intelligentmove;

  int count = 0;
  int IntelligentMoveCount;

   while( !isSolved() ){
   // game loop that continues untill the game end
      cout << "Enter your letter to move empty cell " << endl; ;
      cout << "-- A for left \n-- D for Right \n-- W for Up\n-- S for down \n";
      cout << "-- F for Shuffle \n-- I for intelligent move \n--" ;
      cout << " V for completing board with intelligence\n-- T for move number \n";
      cout << "-- E for saving current board configuration \n--";
      cout << " L for loading board configuration in the file" << endl;
      do{
        cout << "invalid direction enter move again"  << endl;
        cin >> movement;
        obj.setMove(movement);
      }
      while(!obj.isDirectionValid());
      if (movement == 't' || movement == 'T')
      {
      	cout << "number of moves is : " << count << endl;
      }
      else if (movement == 'E' || movement == 'e')
      {
        cout << "enter a file name to save the current board configuration\n" ;
        cin >> savefile;
        writeToFile(savefile);
      }
      else if (movement == 'L' || movement == 'l')
      {
        cout << "enter a file name to load the board configuration from that file\n" ;
        cin >> loadfile;
        readFromfile(loadfile);
      }
      else if (movement == 'i' || movement == 'I')
      {
        Intelligentmove = IntelligentMove();
        cout << " intelligent move chooses : " << Intelligentmove << endl;
        obj.setMove(Intelligentmove);
        move();
        print();
      }
     else if (movement == 'v' || movement == 'V')
      {
        solvePuzzle();
      }
      else if(movement == 'f' || movement == 'F'){
      //shuffle
        shuffle();
        obj.FindCoord();
        print();
      }
      else {
        obj.move();
        print();
      }
      count ++;
   }
   if (isSolved()) {
     cout << "you have won the game\n" ;
    }
}
void NPuzzle::solvePuzzle(){
    int IntelligentMoveCount = 1;
    char Intelligentmove;
    const char moving[4] = {'w','s','a','d'};
    while(IntelligentMoveCount  < 2000 && !obj.isSolved()){
      if (IntelligentMoveCount%5 == 0)
      {
        moveRandom();
      }
      else{
        Intelligentmove = IntelligentMove();
        cout << "intelligent move chooses : " << Intelligentmove << endl;
        obj.setMove(Intelligentmove);
        obj.move();
      }
      cout << " count : " << IntelligentMoveCount++ << endl;
      obj.print();
  }
}
void NPuzzle::Board::setboard(){
  int k = 1;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (k == height*width) {
        area[i][j] = -1;
        k++;
      }
      else{
        area[i][j] = k++;
      }
    }
  }
  setCoordinates(width-1,height-1);
}
bool NPuzzle::Board::isSolved()const{
  int goal[9][9];
  int k = 1;
  int count = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (area[i][j] == 0 || area[i][j] == -1) {
        goal[i][j] = area[i][j];
      }
      else {
        goal[i][j] = k++;;
      }
    }
  }
  for (int i = 0; i < height; i++) {
     for (int j = 0; j < width; j++) {
        if (goal[i][j] == area[i][j])   {
          cout << count ++ << endl;
        }
      }
    }
  //cout << "count : " << count << endl;
  if (count == width*height) {
    return true;
  }
  else {
    return false;
  }
}
void NPuzzle::Board::setsize(){
  int h1,w1;
  do{
    cout << "enter the height and width" << endl;  // taking size
    cin >> h1;
    cin >> w1;
  }
  while(h1 < 3 || h1 > 9 || w1 < 3 || w1 > 9);
  //obj.setwidth(w1);
  //obj.setheight(w1);
    height = h1;
    width  = w1;
}
void NPuzzle::Board::print()const{
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
void NPuzzle::Board::reset(){
  int goal[9][9];
  int k = 1;
  int count = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (area[i][j] != 0 || area[i][j] != -1) {
        goal[i][j] = k++;
      }
      else {
        goal[i][j] = area[i][j];
      }
    }
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      area[i][j] = goal[i][j];
    }
  }
}
void NPuzzle::Board::move()
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
void NPuzzle::Board ::writeToFile(string savefile)const
{
  int temp[81];
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
void NPuzzle::Board ::readFromfile(string filename){
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
  width = i / height;
  //total/height = width
  int k = 0;
  for(int i = 0;i < height ;i++){
      for(int j = 0;j < width ;j++){
        area[i][j] = temp[k++];
      }
    }
   board.close(); //closing file
   //setwidth(width);
   //setheight(height);
   FindCoord();
   NPuzzle::Board ::print();
}
void NPuzzle::Board::FindCoord(){
  for(int i = 0;i < height ;i++){
    for(int j = 0;j < width ;j++){
      if(area[i][j] == -1) {
      //-1 means empty place
        setCoordinates(j,i);
      }
    }
  }
}
void NPuzzle::shuffle(){
  int index;
  const char moving[4] = {'w','s','a','d'};
  	for (int i = 0; i < obj.getwidth()*obj.getheight(); ++i){
      do {
        index = rand()%4;
        obj.setMove(moving[index]);
        obj.move();
        //obj.print();
      }
      while(obj.isDirectionValid());
    }
}
void NPuzzle::printReport(){
  cout << "solution is not found and number of moves is : " << obj.getmove() << endl;
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
    return 0;
}
bool NPuzzle::Board::isDirectionValid()
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
  return false;
}
char NPuzzle::IntelligentMove(){
  int sum[4] = {100,100,100,100};
  int moveCount = 0;
  int answer;
  int temp_x,temp_y,temp;
  int width = obj.getwidth();
  int height = obj.getheight();
  int coord_x = obj.getx();
  int coord_y = obj.gety();
  static int oldAnswer;

  obj.setMove('w');
  if (obj.isDirectionValid()) {//yukarı gidebilirmi check
    obj.move();
    for (int i = 0; i < height; ++i)
    {
      for (int j = 0; j < width; ++j)
      {
         temp = obj.getnum(coord_x,coord_y);
         temp_y = temp%height;
         temp_x = temp - (temp_y*width)-1;
         sum[0] += abs(temp_y - (coord_y)) + abs(temp_x - coord_x);
      }
    }
    obj.setMove('s');
    obj.move();
    sum[0]+= moveCount;
  }

  obj.setMove('s');
if (obj.isDirectionValid()){
    obj.move();
      for (int i = 0; i < height; ++i)
      {
        for (int j = 0; j < width; ++j)
        {
           temp = obj.getnum(coord_x,coord_y);
           temp_y = temp%height;
           temp_x = temp - (temp_y*width)-1;
           sum[1] += abs(temp_y - (coord_y)) + abs(temp_x - coord_x);
        }
    }
    obj.setMove('w');
    obj.move();
    sum[1]+= moveCount;
  }
    obj.setMove('a');
  if (obj.isDirectionValid()){
    obj.move();
    for (int i = 0; i < height; ++i)
    {
      for (int j = 0; j < width; ++j)
      {
         temp = obj.getnum(coord_x,coord_y);
         temp_y = temp%height;
         temp_x = temp - (temp_y*width)-1;
         sum[2] += abs(temp_y - (coord_y)) + abs(temp_x - coord_x);
      }
    }
    obj.setMove('d');
    obj.move();
    sum[2]+= moveCount;
  }
  obj.setMove('d');
  if (obj.isDirectionValid()){
    obj.move();
    for (int i = 0; i < height; ++i)
    {
      for (int j = 0; j < width; ++j)
      {
         temp = obj.getnum(coord_x,coord_y);
         temp_y = temp%height;
         temp_x = temp - (temp_y*width)-1;
         sum[3] += abs(temp_y - (coord_y)) + abs(temp_x - coord_x);
      }
    }
    obj.setMove('a');
    obj.move();
    sum[3]+= moveCount;
  }
  moveCount++;
  answer = Compare(sum);//find the min number
  if ((oldAnswer ==  0 && answer == 1) || (oldAnswer ==  1 && answer == 0))
  {
      answer += 2;
  }
  else if ((oldAnswer ==  2 && answer == 3) || (oldAnswer ==  3 && answer == 2))
  {
      answer -= 2;
  }
  for (int i = 0; i < 4; ++i)
  {
    sum[i] = 100;
  }
  oldAnswer = answer;
  switch(answer){
    case 0:
      return 's';
    break;
    case 1:
      return 'w';
    break;
    case 2:
      return 'd';
    break;
    case 3:
      return 'a';
    break;
  }
  return 'a';
}
void NPuzzle::print(){
  obj.print();
}
void NPuzzle::readFromfile(string name){
  obj.readFromfile(name);
}
void NPuzzle::writeToFile(string name){
  obj.writeToFile(name);
}
void NPuzzle::reset(){
  obj.reset();
}
void NPuzzle::setsize(){
  obj.setsize();
}
void NPuzzle::move(){
  obj.move();
}
bool NPuzzle::isSolved(){
  if (obj.isSolved()) {
    return true;
  }
  else
  return false;
}
void NPuzzle::moveRandom(){
  const char moving[4] = {'w','s','a','d'};
  auto index = rand()%4;
  cout << "random move is : " << moving[index] << endl;
  obj.setMove(moving[index]);
  obj.move();
}
