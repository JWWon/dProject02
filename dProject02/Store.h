#include "Order.h"
#include <list>
#pragma once
class Store
{
public:
	Store();
	~Store();

	virtual void addOrder() = 0;
	virtual int calculateDeliverTime(int userLat, int userLon, int storeLat, int storeLon) = 0;

	//GETTER SETTER
	void setStoreID(int id) { storeId = id; }
	int getStoreID() { return storeId;  }

	void setDistance(int distance) { availableDistance = distance; }
	int getDistance() { return availableDistance;  }

	void setStoreName(string name) { storeName = name;  }
	string getStoreName() { return storeName; }

	void setStoreType(string type) { storeType = type; }
	string getStoreType() { return storeType; }

	list<Order> getOrders() { return recievedOrders; }
	//END
protected:
	int storeId;
	int availableDistance;
	string storeName;
	string storeType;
	list<Order> recievedOrders;
};
