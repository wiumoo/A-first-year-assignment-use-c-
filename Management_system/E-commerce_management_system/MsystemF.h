#include <string>
#include <vector>
#pragma warning(suppress : 4996)

using namespace std;

class G_User
{
public:
	G_User() : User_name(User_name), User_password(User_password) {};
	G_User(string name, string password) : User_name(name), User_password(password) {};
	string GetUsername() const { return User_name; };
	string GetUserpassword() const { return User_password; };
	void GetName(const string name) { this->User_name = name; };
	void GetPassword(const string password) { this->User_password = password; };
private:
	string User_name;
	string User_password;
};
class A_User
{
public:
	A_User(string name, string password) : User_name("admin"), User_password(to_string(123456)) {};
	string GetUsername() const { return User_name; };
	string GetUserpassword() const { return User_password; };
private:
	string User_name;
	string User_password;
};
class Item
{
public:

	void GetIname(const string name) { this->Item_name = name; };
	void GetIprice(const int price) { this->Item_price = price; };
	void GetIquantity(const int quantity) { this->Item_quantity = quantity; };
	void GetIlisted(const int listed) { this->Item_listed = listed; };

	string GetItemname() const { return Item_name; };
	int GetItemID() const { return Item_ID; };
	int GetItemprice() const { return Item_price; };
	int GetItemquantity() const { return Item_quantity; };
	int GetItemlisted() const { return Item_listed; };
private:
	string Item_name;
	int Item_ID;
	int Item_price;
	int Item_quantity;
	int Item_listed;

};

vector<G_User>UserData;
vector<Item>ItemData;

bool WNGlogin = false;
bool WNAlogin = false;