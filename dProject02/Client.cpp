#include "Client.h"
#include <iostream>
using namespace std;
void Client::printInfo() {
	cout << userName << "ดิ" << endl;
}

void Client::setName(string k_name) { userName = k_name; }
string Client::getName() { return userName; }

void Client::setLocationID(int k_locID) { locationId = k_locID; }
int Client::getLocationID() { return locationId; }

void Client::setStoreID(int k_storeID) {}
int Client::getStoreID() { return 0; }