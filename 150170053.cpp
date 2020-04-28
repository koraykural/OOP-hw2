/*
* Koray Kural
* 150170053
* 26/04/2020
*/
#include <iostream>
#include "Business.h"

using namespace std;

int main(){
    // Create owners of the business
    Owner o1 = Owner("Owner_name1", "surname1");
    Owner o2 = Owner("Owner_name2", "surname2");
    Owner* owner_arr = new Owner[2];
    owner_arr[0] = o1;
    owner_arr[1] = o2;

    // Crete the business itself
    Business atlas = Business("Atlas", "Maslak Istanbul/Turkey", owner_arr, 2);
    
    // Print owner info to screen: name, surname, ownership
    atlas.list_owners();

    // Add new employees
    Courier c1 = Courier("Courier", "surname1", "car");
    Courier c2 = Courier("Courier", "surname2", "motorcycle");
    Courier c3 = Courier("Courier", "surname3", "motorcycle");  

    atlas.hire_courier(c1);
    atlas.hire_courier(c2);
    atlas.hire_courier(c3);


    // Print business info to screen
    atlas();

    // Get courier with index 1 and remove it from the list/array
    Courier cour = atlas[1];
    atlas.fire_courier(cour);
    
    // Print remaining couriers
    atlas.list_couriers();
    
    // Print current maximum shipment capacity
    cout << atlas.calculate_shipment_capacity() << std::endl;
    return 0;
}