#include <iostream>

#ifndef person
#include "Person.h"
#define person
#endif

using namespace std;

class Owner : private Person
{
private:
  double ownership;
public:
  Owner();
  Owner(const Owner &in_owner);
  Owner(string name, string surname, float ownership);
  void print_owner();
  void set_ownership(int percentage);
};

Owner::Owner():Person("","")
{
  ownership = 0;
}

Owner::Owner(const Owner &in_owner):Person(in_owner.get_name(), in_owner.get_surname())
{
  ownership = in_owner.ownership;
}

Owner::Owner(string name, string surname, float in_ownership = 0):Person(name, surname)
{
  ownership = in_ownership;
}

void Owner::print_owner()
{
  print_person();
  cout << ownership << endl;
}

void Owner::set_ownership(int percentage)
{
  ownership = percentage;
}