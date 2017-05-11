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

	// 파일 입출력
	void load_user_file();
	void load_store_file();
	void load_location_file();
	void save_user_file();

	void run();

	// 로그인 기능
	bool clientLogin();
	bool managerLogin();

	// 고객
	void clientMenu(); //메인화면
	void findStoreByName();		//이름으로 가게찾기
	void findStoreByCategory();	//카테고리로 가게찾기
	void changeMyLocation();	//내 위치정보 변경

	void orderFood(Store* store); //주문화면

	// 관리자
	void managerMenu(); //메인화면
	void showOrderList();	//주문 목록 확인하기
	void changeRadius();	//배달 가능 반경 변경
	
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

