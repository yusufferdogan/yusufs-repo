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
  e3 = sum;
  VectorOfEmployees.push_back(e3);
  for (size_t i = 0; i < VectorOfEmployees.size(); i++)
    cout << "Employee" << i << ": " <<VectorOfEmployees[i];
  cout << "---------------------------------------------------------------------\n";
  e1++;
  e2++;
  e3++;
  Employee e4 = e1-e2;
  VectorOfEmployees.push_back(e4);
  for (size_t i = 0; i < VectorOfEmployees.size(); i++)
      cout << "Employee" << i << ": " <<VectorOfEmployees[i];
  cout << "---------------------------------------------------------------------\n";
  if (e1 == e3)
    cout << " 2 employees are equal\n";
  else
    cout << "2 employees are not same\n";
  cout << e1 (0,0) << endl;
  return 0;
}
  //cout << "sizeof vector is : " << VectorOfEmployees.size() << endl;
  /*cout << "resied to 1 \n\n\n\n\n";
  for (size_t i = 0; i < VectorOfEmployees.size(); i++) {
    cout << VectorOfEmployees[i];
  }
  cout << "sizeof vector is : " << VectorOfEmployees.size() << endl;*/
  //
