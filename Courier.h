#include <iostream>

#ifndef person
#include "Person.h"
#define person
#endif

using namespace std;

class Courier : private Person
{
private:
  string vehicle;
  int transport_capacity;
public:
  Courier();
  Courier(string name, string surname, string vehicle);
  Courier(const Courier &in_courier);
  void print_courier();
  int get_transport_capacity() const;
  bool operator==(Courier& rhs);
};

Courier::Courier():Person("","")
{
  vehicle = "";
  transport_capacity = 0;
}
Courier::Courier(string name, string surname, string in_vehicle):Person(name, surname)
{
  if(in_vehicle == "car") {
    vehicle = in_vehicle;
    transport_capacity = 200;
  }
  else if(in_vehicle == "motorcycle") {
    vehicle = in_vehicle;
    transport_capacity = 35;
  }
  else if(in_vehicle == "bicycle") {
    vehicle = in_vehicle;
    transport_capacity = 10;
  } 
  else {
    // Give error
    cerr << "Unknown vehicle type" << endl;
  }
}

Courier::Courier(const Courier &in_courier):Person(in_courier.get_name(), in_courier.get_surname())
{
  vehicle = in_courier.vehicle;
  transport_capacity = in_courier.transport_capacity;
}

void Courier::print_courier()
{
  print_person();
  cout << vehicle << endl;
}

int Courier::get_transport_capacity() const
{
  return transport_capacity;
}

bool Courier::operator==(Courier &rhs)
{
  return get_name() == rhs.get_name() && get_surname() == rhs.get_surname();
}