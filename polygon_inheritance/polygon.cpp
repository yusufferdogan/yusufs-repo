#include <iostream>
#include <cmath>
using namespace std;

class Polygon{
protected:
  int x,y;
  int area;
  void SetCoordinates(int a,int b){x = a;y = b;}
  void PrintCoordinates(){
    cout << "My centers coordinates are :" << x << "," << y << endl;
  }
public:
  virtual void Printname()=0;
  virtual void Printarea()=0;
  //virtual void PrintCoordinates()=0;
  virtual void Print()=0;
};

class Triangle : public Polygon{
protected:
  int side1;
  int side2;
  int side3;
public:
  Triangle(int x,int y,int side1,int side2,int side3)
  {
    SetCoordinates(x,y);
    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
  }
  void Printname()
  {
    cout << "This is a triangle \n";
    PrintCoordinates();
    cout << "My sides are : " << side1 << "," << side2 << "," << side3 << endl;
  }
  void Printarea()
  {
    int u = (side1+side2+side3)/2;
    area = sqrt(u*(u-side1)*(u-side2)*(u-side3));
    cout << "My area is : " << area << endl;
  }
  void Print()
  {
    Printname();
    Printarea();
    cout << "-------------------------------\n";
  }
};
class Rectangle : public Polygon{
protected:
  int side1;
  int side2;
public:
  Rectangle(int x,int y,int side1,int side2)
  {
    SetCoordinates(x,y);
    this->side1 = side1;
    this->side2 = side2;
  }
  void Printname()
  {
    cout << "This is a Rectangle \n";
    PrintCoordinates();
    cout << "my sides are : " << side1 << "," << side2 << endl;
  }
  void Printarea()
  {
    area = side1*side2;
    cout << "My area is : " << area << endl;
  }
  void Print()
  {
    Printname();
    Printarea();
    cout << "-------------------------------\n";
  }
};
class Square : public Rectangle{
public:
  Square(int x,int y,int side):Rectangle(x,y,side1,side2)
  {
    side1 = side;
    side2 = side;
  }
  void Printname()
  {
    cout << "This is a Square \n";
    PrintCoordinates();
    cout << "my sides are : " << side1 << "," << side2 << endl;
  }
  void Printarea()
  {
    Rectangle::Printarea();
  }
  void Print()
  {
    Printname();
    Printarea();
    cout << "-------------------------------\n";
  }
};
int main(int argc, char const *argv[]) {
  Polygon *pbase[3];
  pbase[0] = new Triangle (-1,-2,5,12,13);
  pbase[1] = new Rectangle(0,0,8,9);
  pbase[2] = new Square   (9,-7,5);
  for (size_t i = 0; i < 3; i++) {
    pbase[i] -> Print();
  }
  return 0;
}
