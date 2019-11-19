#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <vector>
using namespace std;
class Employee{
public:
  Employee(int i,string n,int a,string d,double s):id(i),name(n),age(a),department(d),salary(s),ptr(NULL){};
  Employee(){};
  bool     operator==  (Employee&);
  Employee operator+   (Employee& e2);
  friend ostream  &operator<< (ostream &outputStream, Employee& e1);
  friend istream  &operator>> (istream &inputStream, Employee& e1);
  void operator=  (Employee& e1);
  void   operator++  (int);
  void   operator++  ();
  void   SetProjectNumber();
  int    operator()(int x,int y)const;
  int    getid();
  int    getage();
  string getname();
  string getdepartment();
  double getsalary();
  void setEmployesAges(vector <Employee> VectorOfEmployees);
private:
  int id;
  string name;
  int age;
  string department;
  double salary;
  int ProjectNumber[4][4];
  int *ptr;
};
#endif
