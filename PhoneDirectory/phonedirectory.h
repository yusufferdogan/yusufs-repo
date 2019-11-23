#ifndef PHONEDIRECTORY_H
#define PHONEDIRECTORY_H
class PhoneDirectory{
private:
  string* name;
  string* number;
  int created;
  int died;
  int size;
public:
  void setSize(int size);
  void getsize();
  /*-----------------------*/
  PhoneDirectory(int size);
  ~PhoneDirectory();
  const bool operator=  (const PhoneDirectory&);
  const bool operator== (const PhoneDirectory&)const;
  friend ostream  &operator<< (ostream &outputStream, PhoneDirectory&);
  friend istream  &operator>> (istream &inputStream,  PhoneDirectory&);
  const void operator=  (const Employee& e1) ;
  const  int operator()(int x,int y)const;
};
#endif
