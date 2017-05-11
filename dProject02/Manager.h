#include "User.h"
#pragma once
class Manager :	public User
{
public:
	Manager() {}
	~Manager() {}

	//가상함수 GETTER SETTER
	virtual void printInfo();
	
	virtual void setName(string k_name);
	virtual string getName();

	virtual void setLocationID(int k_locID);
	virtual int getLocationID();

	virtual void setStoreID(int k_storeID);
	virtual int getStoreID();
private:
	int storeId;
};