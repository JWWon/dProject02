#include "Chinese.h"

void Chinese::addOrder() {
	int command;

	cout << "      MENU" << endl;
	cout << "-----------------" << endl;
	cout << "1. ±èÄ¡Âî°³" << endl;
	cout << "2. ºñºö¹ä" << endl;
	cout << "3. ºÒ°í±â" << endl;
	cout << "0. ÁÖ¹®Ãë¼Ò" << endl;
	cout << "choose menu ->";
	cin >> command;

	Order newOrder;
	//newOrder.orderedUserId = loginedUser->getID();
	cout << endl;
	switch (command) {
	case 1:
		cout << "Â¥Àå¸éÀ» ÁÖ¹®ÇÏ¼Ì½À´Ï´Ù." << endl;
		newOrder.orderedFood = "Â¥Àå¸é";
		break;
	case 2:
		cout << "Â«»ÍÀ» ÁÖ¹®ÇÏ¼Ì½À´Ï´Ù." << endl;
		newOrder.orderedFood = "Â«»Í";
		break;
	case 3:
		cout << "ÅÁ¼öÀ°À» ÁÖ¹®ÇÏ¼Ì½À´Ï´Ù." << endl;
		newOrder.orderedFood = "ÅÁ¼öÀ°";
		break;
	case 4:
		return;
	default:
		cout << "Àß¸øµÈ ¸í·ÉÀÔ´Ï´Ù." << endl;
		return;
	}

	recievedOrders.push_back(newOrder);
}

int Chinese::calculateDeliverTime(int userLat, int userLon, int storeLat, int storeLon) {
	double distance = sqrt(pow(storeLat - userLat, 2) + pow(storeLon - userLon, 2));

	return 20 + (int)distance; //(30 + °Å¸®)ºÐ
}