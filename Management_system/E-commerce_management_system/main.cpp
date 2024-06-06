#include "MsystemF.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#pragma warning(suppress : 4996)
using namespace std;

void Start();
void Get_User();
void Get_Item();
int MainMenu();
void General_User();
int General_User_menu();
void ShowItem();
void SearchItem();
void Admin_User();
int Admin_User_Menu();
int ModItemS();
void ModItem();
void Mod_Name();
void Mod_price();
void Mod_quantity();
void Mod_listed();
void Add_Item();
int User_Manage();
void User_Add();
void User_Delete();



int main()
{
	Get_User();
	Get_Item();
	Start();
	return 0;
}

/*-------------------------Start-------------------------*/
void Start()
{
	system("cls");
	bool start = false;
	while (!start) {
		switch (MainMenu())
		{
		case 1:
			system("cls");
			General_User();
			break;
		case 2:
			system("cls");
			Admin_User();
			break;
		case 3:
			start = true;
			break;
		default:
			cout << "You have to choose within the range" << endl;
			break;
		}
	}
}
/*-------------------------GetUser-------------------------*/
void Get_User()
{
	ifstream output ("User.txt");
	if (!output) { exit(0); };
	string name, password;
	while (!output.eof())
	{
		output >> name >> password;
		UserData.push_back(G_User(name, password));
	}
}
/*-------------------------GetItem-------------------------*/
void Get_Item()
{
	ifstream output("Item.txt");
	if (!output) { exit(0); };
	string Item_name;
	int Item_ID, Item_price, Item_quantity, Item_listed;
	while (!output.eof())
	{
		output >> Item_name >> Item_ID >> Item_price >> Item_quantity >> Item_listed;
	}
}
/*-------------------------Menu-------------------------*/
int MainMenu()
{
	cout << "     welcome to use E-c manage system" << endl;
	cout << "        1.General user login" << endl;
	cout << "        2.Admin user login" << endl;
	cout << "        3.Exit" << endl;
	cout << "Please enter operation" << endl;
	int op;
	cin >> op;
	return op;
}
/*-------------------------General User-------------------------*/
void General_User()
{
	system("cls");
	if (!WNGlogin)
	{
		cout << "Please input user ID" << endl;
		string ID; cin >> ID;
		for (auto& i : UserData)
		{
			if (i.GetUsername() == ID)
			{
				cout << "Please input user password" << endl;
				string password; cin >> password;
				if (i.GetUserpassword() == password)
				{
					WNGlogin = true;
					system("cls");
					General_User_menu();
					return;
					break;
				}
				else
				{
					cout << "The password is wrong" << endl;
					system("pause");
					system("cls");
					return;
				}
			}
		}
		cout << "No ID matches";
		system("pause");
		system("cls");
		return;
	}
	bool start = false;
	while (!start) {
		switch (General_User_menu())
		{
		case 1:
			system("cls");
			ShowItem();
			break;
		case 2:
			system("cls");
			SearchItem();
			break;
		case 3:
			system("cls");
			start = true;
			WNGlogin = false;
			break;
		default:
			cout << "You have to choose within the range" << endl;
			break;
		}
	}
	return;
}
/*-------------------------General user menu-------------------------*/
int General_User_menu()
{
	cout << "     1.Show all Item     " << endl;
	cout << "     2.Serch Item     " << endl;
	cout << "     3.Exit" << endl;
	cout << "Please enter operation" << endl;
	int op;
	cin >> op;
	return op;
}
/*-------------------------Show Item-------------------------*/
void ShowItem()
{
	for (auto& i : ItemData)
	{  
		if (i.GetItemlisted() == 1)
			cout << "Name: " << i.GetItemname() << " " << "ID : " << i.GetItemID() << " " << "Price : " << i.GetItemprice() << " " << "Quantity: " << i.GetItemquantity() << endl;
		else continue;
	}
	system("cls");
	return;
}
/*-------------------------General user Search-------------------------*/
void SearchItem()
{
	cout << "Please enter one of the name or ID what you want search" << endl;
	cout << "example to name : sword : enter any key" << endl;
	cout << "example to ID : enter any key : 123456 " << endl;
	string name; int ID;
	cin >> name >> ID;
	for (auto& i : ItemData)
	{
		if (name == i.GetItemname() || ID == i.GetItemID())
		{
			if (i.GetItemlisted() == 1)
			{
				cout << i.GetItemname() << " " << i.GetItemID() << " " << i.GetItemprice() << " " << i.GetItemquantity();
				break;
			}
			else
			{
				cout << "It's already sold out!";
				break;
			}
		}
		else
		{
			cout << "This Item does not exist!";
		}
	}
	system("cls");
	return;
}
/*-------------------------Admin User-------------------------*/
void Admin_User()
{
	if (!WNAlogin)
	{
		cout << "Please input Admin ID" << endl;
		string ID; cin >> ID;
		if (ID == "Admin")
		{
			cout << "Please input User password" << endl;
			string password; cin >> password;
			if (password == "123456") {
				WNAlogin = true;
				system("cls");
			}
			else
			{
				cout << "The password doesn't match";
				system("pause");
				system("cls");
				return;
			}
		}
		else
		{
			cout << "The ID doesn't match" << endl;;
			system("pause");
			system("cls");
			return;
		}
	}
	bool start = false;
	while (!start) {
		switch (Admin_User_Menu())
		{
		case 1:
			system("cls");
			ModItem();
			break;
		case 2:
			system("cls");
			Add_Item();
			break;
		case 3:
			system("cls");
			SearchItem();
			break;
		case 4:
			system("cls");
			switch (User_Manage())
			{
			case 1:
				system("cls");
				User_Add();
				break;
			case 2:
				system("cls");
				User_Delete();
				break;
			case 3:
				system("cls");
				Admin_User_Menu();
				break;
			default:
				break;
			}
			break;
		case 5:
			system("cls");
			start = true;
			WNAlogin = false;
			break;
		default:
			cout << "You have to choose within the range" << endl;
			break;
		}
	}
	return;
}
/*-------------------------Admin user menu-------------------------*/
int Admin_User_Menu()
{
	cout << "     1.Modification of Item     " << endl;
	cout << "     2.Add a Item     " << endl;
	cout << "     3.Search a Item     " << endl;
	cout << "     4.Manage a User     " << endl;
	cout << "     5.Exit" << endl;
	cout << "Please enter operation" << endl;
	int op;
	cin >> op;
	return op;
}
/*-------------------------Admin user modItem-------------------------*/
int ModItemS()
{
	cout << "     1.Change the name of the Item    " << endl;
	cout << "     2.Change the price of the item      " << endl;
	cout << "     3.Change the number of Item     " << endl;
	cout << "     4.Set wether it is saleble or not     " << endl;
	cout << "     5.Exit" << endl;
	int op;
	cin >> op;
	return op;
}
/*-------------------------Admin user modItem-------------------------*/
void ModItem()
{
	switch (ModItemS())
	{
	case 1:
		system("cls");
		Mod_Name();
		break;
	case 2:
		system("cls");
		Mod_price();
		break;
	case 3:
		system("cls");
		Mod_quantity();
		break;
	case 4:
		system("cls");
		Mod_listed();
		break;
	case 5:
		system("cls");
		Admin_User();
		break;
	default:
		cout << "You have to choose within the range" << endl;
		break;
	}
}
/*-------------------------Mod Item name-------------------------*/
void Mod_Name()
{
	cout << "Please enter the name you want to change" << endl;
	string Wname; cin >> Wname;
	cout << "Please enter the name you want to change to" << endl;
	string Tname; cin >> Tname;
	for (auto& i : ItemData)
	{
		if (i.GetItemname() == Wname)
		{
			i.GetIname(Tname);
			break;
		}
	}
}
/*-------------------------Mod Item price-------------------------*/
void Mod_price()
{
	cout << "Please enter the name you want to change" << endl;
	string Wname; cin >> Wname;
	cout << "Please Enter how much you want to change to" << endl;
	int price; cin >> price;
	for (auto& i : ItemData)
	{
		if (i.GetItemname() == Wname)
		{
			i.GetIprice(price);
			break;
		}
	}
}
/*-------------------------Mod Item quantity-------------------------*/
void Mod_quantity()
{
	cout << "Please enter the name you want to change" << endl;
	string Wname; cin >> Wname;
	cout << "Please enter how many we have left" << endl;
	int quantity; cin >> quantity;
	for (auto& i : ItemData)
	{
		if (i.GetItemname() == Wname)
		{
			i.GetIquantity(quantity);
			break;
		}
	}
}
/*-------------------------Mod Item listed-------------------------*/
void Mod_listed()
{
	cout << "Please enter the name you want to change" << endl;
	string Wname; cin >> Wname;
	cout << "Please enter the name you want to change to" << endl;
	int listed; cin >> listed;
	for (auto& i : ItemData)
	{
		if (i.GetItemname() == Wname)
		{
			i.GetIlisted(listed);
			break;
		}
	}
}
/*-------------------------Admin user add_Item-------------------------*/
void Add_Item()
{
	string Item_name;
	int Item_ID, Item_price, Item_quantity, Item_listed;
	ofstream input("Item.txt", ios::app);
	if (!input) { exit(0); };
	cout << "Please input Iteme name, ID, price, quantitiy and ITstate";
	cin >> Item_name >> Item_ID >> Item_price >> Item_quantity >> Item_listed;
	input << endl << Item_name << " " << Item_ID << " " << Item_price << " " << Item_quantity << " " << Item_listed;
	system("cls");
	return;
}
/*-------------------------Admin user manageU-------------------------*/
int User_Manage()
{
	cout << "     1.Add user     " << endl;
	cout << "     2.Delete user     " << endl;
	cout << "     3.Exit" << endl;
	cout << "Please enter operation" << endl;
	int op;
	cin >> op;
	return op;
}
/*-------------------------Admin user add user-------------------------*/
void User_Add()
{
	string name, password;
	ofstream input("User.txt", ios::app);
	if (!input) { exit(0); };
	cout << "Please input name and password:" << endl;
	cin >> name >> password;
	input << endl << name << " " << password;
	system("cls");
	return;
}
/*-------------------------Admin user delete user-------------------------*/
void User_Delete()
{
	string DeleteName; 
	cout << "Please enter the name you want to delete" << endl;
	cin >> DeleteName;
	for (auto &i : UserData)
	{
		if (i.GetUsername() == DeleteName)
		{
			int cnt = 0;
			for (auto name = UserData.begin(); name != UserData.end(); name++)
			{
				if (name->GetUsername() == DeleteName)
				{
					UserData.erase(UserData.begin() + cnt);
					break;
				}
				cnt++;
			}
			ofstream input("User.txt", ios::trunc);
			if (!input) { exit(0); };
			for (auto &j : UserData)
			{
				input << endl << j.GetUsername() << " " << j.GetUserpassword();
			}
			system("cls");
			Admin_User();
		}
	}
	cout << "No name found to delete";
	system("pause");
	system("cls");
	return;
}