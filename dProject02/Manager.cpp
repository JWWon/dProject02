#include "Manager.h"
#include <iostream>
using namespace std;

void Manager::printInfo() {
	cout << "ю╫╫да║ : " << endl;
}

void Manager::setStoreID(int k_storeID) { storeId = k_storeID; }
int Manager::getStoreID() { return storeId; }

void Manager::setName(string k_name) {}
string Manager::getName() { return 0; }

void Manager::setLocationID(int k_locID) {}
int Manager::getLocationID() { return -1; }