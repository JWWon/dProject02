#pragma once
#include "Store.h"
class Chinese :
	public Store
{
public:
	Chinese() {}
	~Chinese() {}

	virtual void addOrder();
	virtual int calculateDeliverTime(int userLat, int userLon, int storeLat, int storeLon);
};

