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
		string("'id' INTEGER, \n") +
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
		string("(1,'Saad', 'Khan'), \n") +
		string("(2, 'Zaid', 'Khan'), \n") +
		string("(3, 'Arsh', 'Nabi'); \n");

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

void StudentDBAbstraction::printAllStudents() { 
	string sql = "SELECT id, first, last FROM Students";

	sqlite3_stmt* myStatement;

	if (prepareQueryWithResults(sql, myStatement)) {
		cout << "All Students" << endl;
		
		int statusOfStep = sqlite3_step(myStatement);

		while (statusOfStep == SQLITE_ROW) {
			int id = sqlite3_column_int(myStatement, 0);
			string firstName = (char*)sqlite3_column_text(myStatement, 1);
			string lastName = (char*)sqlite3_column_text(myStatement, 2);
			
			cout << id << ". " << firstName << " " << lastName << endl;
			
			statusOfStep = sqlite3_step(myStatement);
		}
	}
}

