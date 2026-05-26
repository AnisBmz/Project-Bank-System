#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;


class clsUser : public clsPerson
{

private:

	enum _enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 3 };

	_enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;

	struct stLoginRegisterRecord;

	string _LoginRecord(string separator = "#//#") {

		string userRegister = "";
		clsDate date;
		userRegister += clsDate::getSystemDateTimeString() + separator;
		userRegister += userName + separator;
		userRegister += clsUtil::encryptText(password) + separator;
		userRegister += to_string(permissions);

		return userRegister;

	}

	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string line, string separator = "#//#") {

		stLoginRegisterRecord loginRegisterRecord;

		vector <string> loginRegisterDataLine = clsString::split(line, separator);

		loginRegisterRecord.dateTime = loginRegisterDataLine[0];
		loginRegisterRecord.userName = loginRegisterDataLine[1];
		loginRegisterRecord.password = clsUtil::decryptText(loginRegisterDataLine[2]);
		loginRegisterRecord.permissions = stoi(loginRegisterDataLine[3]);

		return loginRegisterRecord;

	}

	static clsUser _ConvertLineToUserObject(string line, string separator = "#//#") {

		vector <string> vLine = clsString::split(line, separator);

		return clsUser(_enMode::UpdateMode, vLine[0], vLine[1], vLine[2], vLine[3], vLine[4],
			clsUtil::decryptText(vLine[5]), stoi(vLine[6]));
		
	}

	static string _ConvertUserDataToLine(clsUser user, string separator = "#//#") {

		string line = "";

		line += user.firstName + separator;
		line += user.lastName + separator;
		line += user.email + separator;
		line += user.phone + separator;
		line += user.userName + separator;
		line += clsUtil::encryptText(user.password) + separator;
		line += to_string(user.permissions);

		return line;

	}

	static clsUser _GetEmptyUserObject() {

		return clsUser(_enMode::EmptyMode, "", "", "", "", "", "", 0);

	}

	static vector <clsUser> _LoadUsersDataFromFile() {

		vector <clsUser> vUsersData;

		fstream file;

		file.open("Users.txt", ios::in);

		if (file.is_open())
		{

			string line = "";

			while (getline(file, line)) {

				if (!line.empty())
				{

					clsUser user = _ConvertLineToUserObject(line);
					vUsersData.push_back(user);

				}


			}

			file.close();

		}

		return vUsersData;
	 }

	void _SaveUserDataToFile(vector <clsUser> vUsersData) {

		fstream file;

		file.open("Users.txt", ios::out);

		if (file.is_open())
		{

			for (clsUser& user : vUsersData) {

				if (user._MarkedForDelete == false)
				{
					file << _ConvertUserDataToLine(user) << endl;
				}

			}

			file.close();

		}


	}

	void _Update() {

		vector <clsUser> vUsersData = _LoadUsersDataFromFile();

		for (clsUser& user : vUsersData) {

			if (user.userName == userName)
			{

				user = *this;
				break;

			}

		}

		_SaveUserDataToFile(vUsersData);

	}

	void _AddUserDataToFile(clsUser user) {

		fstream file;

		file.open("Users.txt", ios::out | ios::app);

		if (file.is_open())
		{

			file << endl << _ConvertUserDataToLine(user);
			file.close();

		}

	}

	void _AddNew() {

		_AddUserDataToFile(*this);

	}

public:

	enum enPermossions {
		pAll = -1, pShowClientsList = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClientInfo = 8,
		pFindClient = 16, pShowTransactions = 32, pManageUsers = 64, pShowLoginRegister = 128, pCurrencyExchange = 256
	};

	struct stLoginRegisterRecord {

		string dateTime = "";
		string userName = "";
		string password = "";
		int permissions = 0;

	};

	clsUser(_enMode mode, string firstName, string lastName, string email, string phone, string userName,
		string password, int permissions) : clsPerson(firstName, lastName, email, phone) {

		_Mode = mode;
		_UserName = userName;
		_Password = password;
		_Permissions = permissions;

	}

	void setUserName(string userName) {

		_UserName = userName;

	}

	string getUserName() {

		return _UserName;

	}

	__declspec(property(get = getUserName, put = setUserName)) string userName;

	void setPassword(string password) {

		_Password = password;

	}

	string getPassword() {

		return _Password;

	}

	__declspec(property(get = getPassword, put = setPassword)) string password;

	void setPermissions(int permissions) {

		_Permissions = permissions;

	}

	int getPermissions() {

		return _Permissions;

	}

	__declspec(property(get = getPermissions, put = setPermissions)) int permissions;

	bool isEmpty() {

		return _Mode == _enMode::EmptyMode;

	}

	static bool isUserExist(string userName) {

		clsUser user = find(userName);

		return !user.isEmpty();

	}

	static vector <clsUser> getUserList() {

		return _LoadUsersDataFromFile();

	}

	static clsUser find(string userName) {

		fstream file;

		file.open("Users.txt", ios::in);

		if (file.is_open())
		{

			string line = "";

			while (getline(file, line)) {

				clsUser user = _ConvertLineToUserObject(line);

				if (user.userName == userName)
				{

					file.close();
					return user;

				}

			}

			file.close();

		}

		return _GetEmptyUserObject();

	}

	static clsUser find(string userName, string password) {

		fstream file;

		file.open("Users.txt", ios::in);

		if (file.is_open())
		{

			string line = "";

			while (getline(file, line)) {

				clsUser user = _ConvertLineToUserObject(line);

				if (user.userName == userName && user.password == password)
				{

					file.close();
					return user;

				}

			}

			file.close();

		}

		return _GetEmptyUserObject();
	}

	enum enSaveResults { SaveSucceeded = 1, SaveFailedEmptyObject = 2, SaveFailedUserNameExist = 3 };

	enSaveResults save() {

		switch (_Mode) {

		case _enMode::EmptyMode:
			return enSaveResults::SaveFailedEmptyObject;

		case _enMode::UpdateMode:
			_Update();
			return enSaveResults::SaveSucceeded;

		case _enMode::AddNewMode:

			if (isUserExist(userName))
			{
				return enSaveResults::SaveFailedUserNameExist;

			}
			else {

				_AddNew();
				_Mode = _enMode::UpdateMode;
				return enSaveResults::SaveSucceeded;

			}

		}

	}

	static clsUser getAddNewUserObject(string userName) {

		return clsUser(_enMode::AddNewMode, "", "", "", "", userName, "", 0);

	}

	void addPermissions(enPermossions MainMenuPermissions) {


		switch (MainMenuPermissions) {

		case enPermossions::pAll:
			permissions = enPermossions::pAll;
			break;
		case enPermossions::pShowClientsList:
			permissions += enPermossions::pShowClientsList;
			break;

		case enPermossions::pAddNewClient:
			permissions += enPermossions::pAddNewClient;
			break;

		case enPermossions::pDeleteClient:
			permissions += enPermossions::pDeleteClient;
			break;

		case enPermossions::pUpdateClientInfo:
			permissions += enPermossions::pUpdateClientInfo;
			break;

		case enPermossions::pFindClient:
			permissions += enPermossions::pFindClient;
			break;

		case enPermossions::pShowTransactions:
			permissions += enPermossions::pShowTransactions;
			break;

		case enPermossions::pManageUsers:
			permissions += enPermossions::pManageUsers;
			break;

		case enPermossions::pShowLoginRegister:
			permissions += enPermossions::pShowLoginRegister;
			break;

		case enPermossions::pCurrencyExchange:
			permissions += enPermossions::pCurrencyExchange;
			break;

		}

	}

	bool isDelete() {

		vector <clsUser> vUsersData = _LoadUsersDataFromFile();

		for (clsUser& user : vUsersData) {

			if (user.userName == userName)
			{

				user._MarkedForDelete = true;	
				_SaveUserDataToFile(vUsersData);
				*this = _GetEmptyUserObject();
				return true;

			}

		}

		return false;

	}
	
	bool checkAccessPermissions(enPermossions Permission) {

		if (this->permissions == enPermossions::pAll)
		{
			return true;
		}
		if ((this->permissions & Permission) == Permission)
			return true;
		else 
		return false;

	}

	void registerLogin() {

		fstream file;
		string dataLine = _LoginRecord();
		file.open("LoginRegister.txt", ios::out | ios::app);

		if (file.is_open())
		{
			file << dataLine << endl;
			file.close();

		}

	}

	static vector <stLoginRegisterRecord> getLoginRegisterList() {

		vector <stLoginRegisterRecord> vLoginRegisterRecord;

		fstream file;

		file.open("LoginRegister.txt", ios::in);

		if (file.is_open())
		{

			string line = "";
			stLoginRegisterRecord loginRegisterRecord;

			while (getline(file, line)) {

				if (!line.empty())
				{

					loginRegisterRecord = _ConvertLoginRegisterLineToRecord(line);
					vLoginRegisterRecord.push_back(loginRegisterRecord);

				}


			}

			file.close();

		}

		return vLoginRegisterRecord;


	}

};

