#include "Store.h"
#pragma once
class Korean :	public Store
{
public:
	Korean() {}
	~Korean() {}

	virtual void addOrder();
	virtual int calculateDeliverTime(int userLat, int userLon, int storeLat, int storeLon);
};

