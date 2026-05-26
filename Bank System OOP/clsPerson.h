#pragma once

#include <iostream>
using namespace std;

class clsPerson
{

private:

	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	clsPerson(string firstName, string lastName, string email, string phone) {

		_FirstName = firstName;
		_LastName = lastName;
		_Email = email;
		_Phone = phone;

	}

	void setFirstName(string firstName) {

		_FirstName = firstName;

	}

	string getFirstName() {

		return _FirstName;

	}

	__declspec(property(get = getFirstName, put = setFirstName)) string firstName;

	void setLastName(string lastName) {

		_LastName = lastName;

	}

	string getLastName() {

		return _LastName;

	}

	__declspec(property(get = getLastName, put = setLastName)) string lastName;

	void setEmail(string email) {

		_Email = email;

	}

	string getEmail() {

		return _Email;

	}

	__declspec(property(get = getEmail, put = setEmail)) string email;

	void setPhone(string phone) {

		_Phone = phone;

	}

	string getPhone() {

		return _Phone;

	}

	__declspec(property(get = getPhone, put = setPhone)) string phone;

	string getFullName() {

		return _FirstName + " " + _LastName;

	}

};

