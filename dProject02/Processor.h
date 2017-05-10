#include "Manager.h"
#include "Client.h"
#include "Location.h"
#include "Chinese.h"
#include "Korean.h"

#pragma once
class Processor
{
public:
	Processor();
	Processor(User* _userdb, Store* _storedb, Location* locationdb);
	~Processor();

	virtual void processOrder(User* logineduser) = 0;

protected:
	User* userDBPtr;
	Store* storeDBPtr;
	Location* locationDBPtr;
};

