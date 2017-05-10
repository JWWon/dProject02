#include "Korean.h"

void Korean::addOrder() {
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
		cout << "±èÄ¡Âî°³¸¦ ÁÖ¹®ÇÏ¼Ì½À´Ï´Ù." << endl;
		newOrder.orderedFood = "±èÄ¡Âî°³";
		break;
	case 2:
		cout << "ºñºö¹äÀ» ÁÖ¹®ÇÏ¼Ì½À´Ï´Ù." << endl;
		newOrder.orderedFood = "ºñºö¹ä";
		break;
	case 3:
		cout << "ºÒ°í±â¸¦ ÁÖ¹®ÇÏ¼Ì½À´Ï´Ù." << endl;
		newOrder.orderedFood = "ºÒ°í±â";
		break;
	case 4:
		return;
	default:
		cout << "Àß¸øµÈ ¸í·ÉÀÔ´Ï´Ù." << endl;
		return;
	}

	recievedOrders.push_back(newOrder);
}