#include "Employee.h"
#include <vector>
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
  vector <Employee> VectorOfEmployees;
  Employee e1(222,"ahmet",32,"test",2125.25),e2(201,"yusuf",25,"development",2500.45),e3;
  VectorOfEmployees.push_back(e1);
  VectorOfEmployees.push_back(e2);
  Employee sum = e1 + e2 ;
  VectorOfEmployees.push_back(sum);
  cout << e1;
  e1++;
  cout << e1;
  ++e1;
  cout << e1;
  return 0;
}
//cout << e2++;
//  e1 ()++;
//  e2 ()++;
//cout << e1;
//cout << e2;
//e3 = e1;
//cout << e3;
/*  for (size_t i = 0; i < VectorOfEmployees.size(); i++) {
  cout << VectorOfEmployees[i];
}*/
//  VectorOfEmployees.resize(1);
  //cout << "sizeof vector is : " << VectorOfEmployees.size() << endl;
 /*  if (e1 == e2) {
    cout << " 2 employees are equal\n";
  }
  else {
    cout << "not same\n";
  }*/
  /*cout << "resied to 1 \n\n\n\n\n";
  for (size_t i = 0; i < VectorOfEmployees.size(); i++) {
    cout << VectorOfEmployees[i];
  }
  cout << "sizeof vector is : " << VectorOfEmployees.size() << endl;*/
  //cout << e1 (0,0) << endl;
