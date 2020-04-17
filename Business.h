#include <iostream>
#include <string>
#include "Courier.h"
#include "Owner.h"
#include "MyVector.h"

using namespace std;

class Business
{
private:
  string name;
  string address;
  Owner *owners;
  int num_of_owners;
  MyVector<Courier> couriers;

public:
  Business(string name, string address, Owner *owners, int num_of_owners);
  ~Business();
  void hire_courier(Courier &in_courier);
  void fire_courier(Courier &in_courier);
  void list_owners();
  void list_couriers();
  int calculate_shipment_capacity();
  const Courier operator[](int i);
  void operator()();
};

Business::Business(string in_name, string in_address, Owner *in_owners, int in_num_of_owners)
{
  name = in_name;
  address = in_address;
  owners = in_owners;
  num_of_owners = in_num_of_owners;

  // Calculate and set percentage of ownerships
  for (int i = 0; i < num_of_owners; i++)
  {
    owners[i].set_ownership(100.0 / num_of_owners);
  }
}

Business::~Business()
{
  delete [] owners;
}

void Business::hire_courier(Courier &in_courier)
{
  couriers.push(in_courier);
}

void Business::fire_courier(Courier &in_courier)
{
  for (int i = 0; i < couriers.size(); i++)
  {
    if(couriers.get(i) == in_courier) {
      couriers.remove(i);
      break;
    }
  }
}

void Business::list_owners()
{
  for (int i = 0; i < num_of_owners; i++)
  {
    owners[i].print_owner();
  }
}

void Business::list_couriers()
{
  for (int i = 0; i < couriers.size(); i++)
  {
    couriers.get(i).print_courier();
  }
}

int Business::calculate_shipment_capacity()
{
  int total = 0;
  for (int i = 0; i < couriers.size(); i++)
  {
    total += couriers.get(i).get_transport_capacity();
  }
  return total;
}

const Courier Business::operator[](int i)
{
  return couriers.get(i);
}

void Business::operator()()
{
  cout << name << " " << address << endl;
  list_owners();
  list_couriers();
}