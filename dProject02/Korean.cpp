#include "Korean.h"

void Korean::addOrder() {
	int command;

	cout << "      MENU" << endl;
	cout << "-----------------" << endl;
	cout << "1. ��ġ�" << endl;
	cout << "2. �����" << endl;
	cout << "3. �Ұ��" << endl;
	cout << "0. �ֹ����" << endl;
	cout << "choose menu ->";
	cin >> command;

	Order newOrder;
	//newOrder.orderedUserId = loginedUser->getID();
	cout << endl;
	switch (command) {
	case 1:
		cout << "��ġ��� �ֹ��ϼ̽��ϴ�." << endl;
		newOrder.orderedFood = "��ġ�";
		break;
	case 2:
		cout << "������� �ֹ��ϼ̽��ϴ�." << endl;
		newOrder.orderedFood = "�����";
		break;
	case 3:
		cout << "�Ұ�⸦ �ֹ��ϼ̽��ϴ�." << endl;
		newOrder.orderedFood = "�Ұ��";
		break;
	case 4:
		return;
	default:
		cout << "�߸��� ����Դϴ�." << endl;
		return;
	}

	recievedOrders.push_back(newOrder);
}