#include <iostream>
#include "phonedirectory.h"
using namespace std;
PhoneDirectory::PhoneDirectory()
{
  *name   = new string[size];
  *number = new string[size];
}
PhoneDirectory::~PhoneDirectory()
{
  delete [] name;
  delete [] number;
}
void PhoneDirectory::setSize(int size)
{
  this->size = size;
}
void PhoneDirectory::getsize()
{
  return size;
}
const PhoneDirectory PhoneDirectory::operator=  (const PhoneDirectory& other)
{
  if (this != &other) {  // protect against invalid self-assignment
      // 1: allocate new memory and copy the elements
      int* new_name = new int[other.size];
      std::copy(other.array, other.array + other.size, new_array);

      // 2: deallocate old memory
      ~PhoneDirectory();

      // 3: assign the new memory to the object
      array = new_name;
      size = other.size;
    }
    // by convention, always return *this
    return *this;
}
const bool PhoneDirectory::operator== (const PhoneDirectory&other)const
{
  for (size_t i = 0; i < size; i++) {
    if (name != other.name || number != other.number) {
      return false;
    }
  }
  return true;
}
const string* PhoneDirectory::operator()(string Number)const //enter a name and it returns the number of this name
{
  if (name == Name) {
    return number*;
  }
}
/*--------------------------------------------------*/
ostream  &operator<< (ostream &outputStream, PhoneDirectory&)
{
  for (size_t i = 0; i < size; i++) {
    cout << name[i];
    cout << number[i];
  }
}
istream  &operator>> (istream &inputStream,  PhoneDirectory&)
{

}
