#include"StudentDBAbstraction.h"
#include<iostream>
#include<vector>

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

	if (querySuccess == false) {

		throw(string)"Error : Creating Students Table";
	}

}

