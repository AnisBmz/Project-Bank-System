#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
using namespace std;

class clsBankClient : public clsPerson
{

private:

	enum _enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 3 };
	_enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLineToClientObjet(string line, string separator = "#//#") {

			vector <string> vTransfersLogRecord = clsString::split(line, separator);
			return clsBankClient (_enMode::UpdateMode, vTransfersLogRecord[0], vTransfersLogRecord[1], vTransfersLogRecord[2], vTransfersLogRecord[3], vTransfersLogRecord[4], vTransfersLogRecord[5], stod(vTransfersLogRecord[6]));

	}

	static clsBankClient _GetEmptyClientObject() {

		return clsBankClient (_enMode::EmptyMode, "", "", "", "", "", "", 0);

	}

	string _ConvertClientObjetToLine(clsBankClient clientData, string separator = "#//#") {

		string line = "";

		line += clientData.firstName + separator;
		line += clientData.lastName + separator;
		line += clientData.email + separator;
		line += clientData.phone + separator;
		line += clientData.accountNumber + separator;
		line += clientData.pinCode + separator;
		line += to_string(clientData.accountBalance);

		return line;

	}

	static vector <clsBankClient> _LoatClientsDataFromFile() {

		vector <clsBankClient> vTransfersLogRecord;

		fstream file;

		file.open("Clients.txt", ios::in);

		if (file.is_open())
		{

			string line;

			while (getline(file, line)) {

				if (!line.empty())
				{
					clsBankClient bankClient = _ConvertLineToClientObjet(line);
					vTransfersLogRecord.push_back(bankClient);
				}

			}

			file.close();

		}
		return vTransfersLogRecord;

	}

	void _SaveClientDataToFile(vector <clsBankClient> _vClients) {

		fstream file;

		file.open("Clients.txt", ios::out);

		string dataLine = "";

		if (file.is_open())
		{

		
			for (clsBankClient& _Client : _vClients) {

				dataLine = _ConvertClientObjetToLine(_Client);

				if (_Client._MarkedForDelete == false)
				{

					file << dataLine << endl;

				}

			}

			file.close();

		}

	}

	void _Update() {

		vector <clsBankClient> vClients = _LoatClientsDataFromFile();

		for (clsBankClient& client : vClients) {

			if (client.accountNumber == accountNumber)
			{
				client = *this;
				break;
			}

		}
		_SaveClientDataToFile(vClients);

	}

	void _AddClientDataToFile(clsBankClient newClient) {

		fstream file;

		file.open("Clients.txt", ios::out | ios::app);

		string dataLine = "";

		if (file.is_open())
		{

			dataLine = _ConvertClientObjetToLine(newClient);

			file << endl << dataLine;

			file.close();

		}

	}

	void _AddNew() {

		_AddClientDataToFile(*this);

	}

	string _PrepareTransferLog(clsBankClient destinationClient, double amount , string userName, string separator = "#//#") {

		string Dataline = "";
		Dataline += clsDate::getSystemDateTimeString() + separator;
		Dataline += this->accountNumber + separator;
		Dataline += destinationClient.accountNumber + separator;
		Dataline += to_string(amount) + separator;
		Dataline += to_string(this->accountBalance) + separator;
		Dataline += to_string(destinationClient.accountBalance) + separator;
		Dataline += userName;


		return Dataline;
	}

	void _RegisterTransferLog(clsBankClient destinationClient, double amount, string userName) {

		fstream file;
		string Dataline = _PrepareTransferLog(destinationClient, amount, userName);

		file.open("TransferLog.txt", ios::out | ios::app);

		if (file.is_open())
		{


			file << Dataline << endl;

			file.close();

		}

	}

	struct stTransferLogRecord;

	static stTransferLogRecord _ConvertTransferLogLineToRecord(string line, string separator = "#//#") {

		vector <string> vTransferLogRecordLine = clsString::split(line, separator);

		stTransferLogRecord transferLogRecord;

		transferLogRecord.dateTime = vTransferLogRecordLine[0];
		transferLogRecord.sourceAccountNumber = vTransferLogRecordLine[1];
		transferLogRecord.destinationAccountNumber = vTransferLogRecordLine[2];
		transferLogRecord.amount = stod(vTransferLogRecordLine[3]);
		transferLogRecord.srcBalanceAfter = stod(vTransferLogRecordLine[4]);
		transferLogRecord.destBalanceAfter = stod(vTransferLogRecordLine[5]);
		transferLogRecord.userName = vTransferLogRecordLine[6];

		return transferLogRecord;
	}

public:

	struct stTransferLogRecord {

		string dateTime = "";
		string sourceAccountNumber = "";
		string destinationAccountNumber = "";
		string userName = "";
		double amount = 0;
		double srcBalanceAfter = 0;
		double destBalanceAfter = 0;

	};

	clsBankClient(_enMode mode, string firstName, string lastName, string email, string phone, string accentNumber,
				  string pinCode, double accentBalance) : clsPerson (firstName, lastName, email, phone) 
	{

		_Mode = mode;
		_AccountNumber = accentNumber;
		_PinCode = pinCode;
		_AccountBalance = accentBalance;

	}

	bool isEmpty() {

		return _Mode == _enMode::EmptyMode;

	}

	string getAccountNumber() {

		return _AccountNumber;

	}

	__declspec(property(get = getAccountNumber)) string accountNumber;

	void setPinCode(string pinCode) {

		_PinCode = pinCode;

	}

	string getPinCode() {

		return _PinCode;

	}

	__declspec(property(get = getPinCode, put = setPinCode)) string pinCode;

	void setAccountBalance(double accentBalance) {

		_AccountBalance = accentBalance;

	}

	double getAccountBalance() {

		return _AccountBalance;

	}

	__declspec(property(get = getAccountBalance, put = setAccountBalance)) double accountBalance;

	static clsBankClient find(string accentNumber) {

		fstream file;

		file.open("Clients.txt", ios::in);

		if (file.is_open())
		{

			string line;

			while (getline(file, line)) {

				clsBankClient bankClient = _ConvertLineToClientObjet(line);

				if (bankClient.accountNumber == accentNumber)
				{

					file.close();
					return bankClient;

				}

			}

			file.close();

		}

		return _GetEmptyClientObject();

	}

	static clsBankClient find(string accentNumber, string pinCode) {

		fstream file;

		file.open("Clients.txt", ios::in);

		if (file.is_open())
		{

			string line;

			while (getline(file, line)) {

				clsBankClient bankClient = _ConvertLineToClientObjet(line);

				if (bankClient.accountNumber == accentNumber && bankClient.pinCode == pinCode)
				{

					file.close();
					return bankClient;

				}

			}

			file.close();

		}

		return _GetEmptyClientObject();

	}

	static bool isClientExist(string accentNumber) {

		clsBankClient client = find(accentNumber);

		return !client.isEmpty();

	}

	enum enSaveResults {SaveSucceeded = 1, SaveFailedEmptyObject = 2, SaveFailedAccountNumberExist = 3};

	enSaveResults save() {

		switch (_Mode) {

		case  _enMode::EmptyMode:

			return enSaveResults::SaveFailedEmptyObject;

		case  _enMode::UpdateMode:

			_Update();
			return enSaveResults::SaveSucceeded;

		case _enMode::AddNewMode:

			if (clsBankClient::isClientExist(accountNumber)) {

				return enSaveResults::SaveFailedAccountNumberExist;

			}
			else {

				_AddNew();
				return enSaveResults::SaveSucceeded;

			}

		}

	}

	static clsBankClient getNewClientObject(string accentNumber) {

		return clsBankClient(_enMode::AddNewMode, "", "", "", "", accentNumber, "", 0);

	}

	bool isDelete() {

		vector <clsBankClient> vClients = _LoatClientsDataFromFile();

		for (clsBankClient &client : vClients)
		{

			if (client.accountNumber == accountNumber)
			{

				client._MarkedForDelete = true;
				_SaveClientDataToFile(vClients);
				*this = _GetEmptyClientObject();
				return true;

			}

		}

		return false;

	}

	static vector <clsBankClient> getClientsList() {

		return  _LoatClientsDataFromFile();

	}

	static double getTotalBalances() {

		vector <clsBankClient> vClients = clsBankClient::getClientsList();

		double totalBalances = 0;

		for (clsBankClient& client : vClients) {

			totalBalances += client.accountBalance;

		}


		return totalBalances;

	}

	void deposit(double amount) {

		accountBalance += amount;
		save();

	}

	bool withdraw(double amount) {

		if (amount > accountBalance)
		{
			return false;
		}
		else {

			accountBalance -= amount;
			save();

		}

	}

	bool transfer(clsBankClient &destinationClient, double amount, string userName) {

		if (accountBalance < amount)
		{
			return false;
		}
		this->withdraw(amount);
		destinationClient.deposit(amount);

		this->_RegisterTransferLog(destinationClient, amount, userName);

		return true;

	}

	static vector <stTransferLogRecord> getTransfersLofList() {

		vector <stTransferLogRecord> vTransfersLogRecord;

		fstream file;

		file.open("TransferLog.txt", ios::in);

		if (file.is_open())
		{

			string line;
			stTransferLogRecord transferRecord;

			while (getline(file, line)) {

				if (!line.empty())
				{
					transferRecord = _ConvertTransferLogLineToRecord(line);
					vTransfersLogRecord.push_back(transferRecord);
				}

			}

			file.close();

		}
		return vTransfersLogRecord;

	}

};

