#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <vector>
using namespace std;
class Employee{
public:
  Employee(int i,string n,int a,string d,double s):id(i),name(n),age(a),department(d),salary(s),ptr(NULL){};
  Employee(){};
  /*---------------------------------------------------------------------------*/
  friend ostream  &operator<< (ostream &outputStream, Employee&);
  friend istream  &operator>> (istream &inputStream,  Employee&);
  /*---------------------------------------------------------------------------*/
  const bool operator==  (const Employee&)const;
  const Employee operator+   (const Employee&)const ;
  const Employee operator-   (const Employee&)const ;
  const void operator=  (const Employee& e1) ;
  const void   operator++  (int) ;
  const void   operator++  () ;
  const  int operator()(int x,int y)const;
  /*---------------------------------------------------------------------------*/
  int    getid();
  int    getage();
  string getname();
  string getdepartment();
  double getsalary();
  void   setEmployesAges(vector <Employee> VectorOfEmployees);
  void   SetProjectNumber();
private:
  int id;
  string name;
  int age;
  string department;
  double salary;
  int ProjectNumber[4][4];
  int *ptr;
};
#endif //EMPLOYEE_H
