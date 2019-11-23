#include <iostream>
#include "space3D.h"
#include <cmath>
using namespace std;
SPACE3D::SPACE3D()
{
  this -> x = 0.0;
  this -> y = 0.0;
  this -> z = 0.0;
}
/*SPACE3D::SPACE3D(int x,int y,int z)
{
  this -> x = x;
  this -> y = y;
  this -> z = z;
}
SPACE3D::SPACE3D(int x,int y,double)
{
  this -> x = x;
  this -> y = y;
  this -> z = 0;
}
SPACE3D::SPACE3D(int x,double,double)
{
  this -> x = x;
  this -> y = 0;
  this -> z = 0;
}*/
SPACE3D::SPACE3D(double x,double y,double z)
{
  this -> x = x;
  this -> y = y;
  this -> z = z;
}
SPACE3D::SPACE3D(double x,double y)
{
  this -> x = x;
  this -> y = y;
  this -> z = 0.0;
}
SPACE3D::SPACE3D(double x)
{
  this -> x = x;
  this -> y = 0.0;
  this -> z = 0.0;
}
const bool SPACE3D::operator==  (const SPACE3D&other)const
{
  if (x==other.x && y==other.y && z==other.z ) {
    return true;
  }
  else return false;
}
const SPACE3D  SPACE3D::operator+   (const SPACE3D&other)const
{
  double X = x+other.x;
  double Y = y+other.y;
  double Z = z+other.z;
  return (X,Y,Z);
}
const SPACE3D  SPACE3D::operator-(const SPACE3D&other)const
{
  double X = x-other.x;
  double Y = y-other.y;
  double Z = z-other.z;
  return (X,Y,Z);
}
const void     SPACE3D::operator=   (const SPACE3D& other)
{
  x = other.x;
  y = other.y;
  z = other.z;
}
const void     SPACE3D::operator++  (int)
{
  x++;
  y++;
  z++;
}
const void     SPACE3D::operator++  ()
{
  ++x;
  ++y;
  ++z;
}
const double SPACE3D::operator()(const SPACE3D& other)//return distance
{
  //SPACE3D dif = *this - other;
  SPACE3D dif; //= this - other;
  dif.x = x-other.x;
  dif.y = y-other.y;
  dif.z = z-other.z;
  return sqrt(pow(dif.x,2)+pow(dif.y,2)+pow(dif.z,2));//distance
}
ostream  &operator<< (ostream &outputStream, SPACE3D&obj)
{
  outputStream << "x coordinate is : " << obj.x << endl;
  outputStream << "y coordinate is : " << obj.y << endl;
  outputStream << "z coordinate is : " << obj.z << endl;
  cout << "--------------------------------------------" << endl;
  return outputStream;
}
istream  &operator>> (istream &inputStream,  SPACE3D&obj)
{
  inputStream >> obj.x;
  inputStream >> obj.y;
  inputStream >> obj.z;
  return inputStream;
}
