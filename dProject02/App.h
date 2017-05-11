#pragma once
#include "Processor.h"
#include <fstream>
#include <sstream>
#include <list>

class App
{
public:
	App();
	~App();

	// ���� �����
	void load_user_file();
	void load_store_file();
	void load_location_file();
	void save_user_file();

	void run();

	// �α��� ���
	bool clientLogin();
	bool managerLogin();

	// ��
	void clientMenu(); //����ȭ��
	void findStoreByName();		//�̸����� ����ã��
	void findStoreByCategory();	//ī�װ��� ����ã��
	void changeMyLocation();	//�� ��ġ���� ����

	void orderFood(Store* store); //�ֹ�ȭ��

	// ������
	void managerMenu(); //����ȭ��
	void showOrderList();	//�ֹ� ��� Ȯ���ϱ�
	void changeRadius();	//��� ���� �ݰ� ����
	
private:
	list<User*> users;
	int users_length;
	list<Store*> stores;
	int stores_length;
	list<Location*> locations;
	int locations_length;

	User* loginedUser;
	Processor* pc;
};

