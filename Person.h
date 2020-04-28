/*
* Koray Kural
* 150170053
* 26/04/2020
*/
#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
  string name;
  string surname;
public:
  Person(string name, string surname);
  void print();
  string get_name() const;
  string get_surname() const;
  void set_name(string name);
  void set_surname(string surname);
};

Person::Person(string in_name, string in_surname)
{
  name = in_name;
  surname = in_surname;
}

void Person::print()
{
  cout <<name << " " << surname << " ";
}

string Person::get_name() const
{
  return name;
}

string Person::get_surname() const
{
  return surname;
}

void Person::set_name(string in_name)
{
  name = in_name;
}

void Person::set_surname(string in_surname)
{
  surname = in_surname;
}