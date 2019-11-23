#ifndef  SPACE3D_H
#define  SPACE3D_H
#include <iostream>
#include <vector>
using namespace std;
class SPACE3D{
private:
  string name;
  double x;
  double y;
  double z;
public:
  SPACE3D();
  SPACE3D(double x,double y,double z);
  SPACE3D(double x,double y);
  SPACE3D(double x);
  const bool     operator==  (const SPACE3D&)const;
  const SPACE3D  operator+   (const SPACE3D&)const ;
  const SPACE3D  operator-   (const SPACE3D&)const ;
  const void     operator=   (const SPACE3D&) ;
  const void     operator++  (int) ;
  const void     operator++  () ;
  const double   operator()  (const SPACE3D&);
/*------------------------------------------------------*/
friend ostream  &operator<< (ostream &outputStream, SPACE3D&);
friend istream  &operator>> (istream &inputStream,  SPACE3D&);
};
#endif //SPACE3D
