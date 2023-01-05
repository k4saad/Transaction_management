#include"StudentDBAbstraction.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;

StudentDBAbstraction::StudentDBAbstraction(string pathToFile) : DBAbstraction(pathToFile) {
	
	createStudentsTable();
}

void StudentDBAbstraction::createStudentsTable() {

	string sql =
		string("CREATE TABLE IF NOT EXISTS 'Students' (\n") +
		string("'id' TEXT, \n") +
		string("'first' TEXT, \n") +
		string("'last' TEXT, \n") +
		string("PRIMARY KEY ('id')\n") +
		string(");\n");

	cout << "Query : " << endl << sql << endl;

	bool querySuccess = executeQueryNoResultsBack(sql);
	try {
		if (querySuccess == false) {

			throw (string)"Error : Creating Students Table";
		}
	}
	catch (string e) {
		cout << e << endl;
	}
}

void StudentDBAbstraction::insertFirstBatch() {

	string sql =

		string("INSERT INTO Students('id', 'first', 'last') VALUES \n") +
		string("('1','Saad', 'Khan'), \n") +
		string("('2', 'Zaid', 'Khan'), \n") +
		string("('3', 'Arsh', 'Nabi'); \n");

	cout << "Query : " << endl << sql << endl;

	bool querySuccess = executeQueryNoResultsBack(sql);
	try {
		if (querySuccess == false) {
			throw (string)"Error : Inserting Student";
		}
	}
	catch (string e) {
		cout << e << endl;
	}
}

