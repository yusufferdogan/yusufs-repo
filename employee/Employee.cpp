#include <iostream>
#include <vector>
#include "Employee.h"
using namespace std;
/*-----------------------------------------------------------------*/
void Employee::SetProjectNumber()
{
  int count = 0;
  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 4; j++) {
      ProjectNumber[i][j] = count++;
    }
  }
}
/*-----------------------------------------------------------------*/
int    Employee::getid()           {return id;}
int    Employee::getage()          {return age;}
string Employee::getname()         {return name;}
string Employee::getdepartment()   {return department;}
double Employee::getsalary()       {return salary;}
/*-----------------------------------------------------------------*/
const bool Employee::operator==(const Employee& e2)const
{
  if (id == e2.id && age == e2.age && name == e2.name
  && department == e2.department && salary == salary) {
    return true;
  }
  else return false;
}
/*-----------------------------------------------------------------*/
const int Employee::operator()(const int x,const int y)const
{
  return ProjectNumber[y][x];
}
const void Employee::operator=(const Employee& e2)
{
   id          = e2.id ;
   age         = e2.age ;
   name        = e2.name ;
   department  = e2.department ;
   salary      = e2.salary ;
}
const void Employee::operator++(int)
{
  id++;
  age++;
  salary++;
}
const void Employee::operator++()
{
  ++id;
  ++age;
  ++salary;
}
const Employee Employee::operator+(const Employee& e2)const
{
  int    sum_id   = id + e2.id;
  string sum_name = name+e2.name;
  string sum_dep  = department+e2.department;
  int    sum_age  = age+e2.age;
  double sum_sal  = salary+e2.salary;
  return Employee(sum_id,sum_name,sum_age,sum_dep,sum_sal);
}
const Employee Employee::operator-(const Employee& e2)const
{
  int    sum_id   = id - e2.id;
  string sum_name = name;          //= name-e2.name;
  string sum_dep  = department;   //= department-e2.department;
  int    sum_age  = age-e2.age;
  double sum_sal  = salary-e2.salary;
  return Employee(sum_id,sum_name,sum_age,sum_dep,sum_sal);
}
ostream  &operator<<(ostream &outputStream, Employee& e1){
  cout << " id: "<< e1.id << " age: " << e1.age << " name: ";
  cout << e1.name << " department: " << e1.department ;
  cout << " salary: " << e1.salary << "\n";
  return outputStream;
}
istream  &operator>>(istream &inputStream,  Employee& e1){
  cin >> e1.id;
  cin >> e1.name;
  cin >> e1.age;
  cin >> e1.department;
  cin >> e1.salary;
  return inputStream;
}
