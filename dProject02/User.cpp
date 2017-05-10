#include "User.h"

User::User() {

}
User::~User() {

}

bool User::checkUserInfo(string k_id, string k_password, int k_userType) {
	if (id == k_id && password == k_password && userType == k_userType)
		return true;
	else {
		return false;
	}
}