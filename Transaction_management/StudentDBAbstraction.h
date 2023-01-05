#pragma once
#include"DBAbstraction.h"

class StudentDBAbstraction:DBAbstraction {

public:
	StudentDBAbstraction(string pathToFile);
	void insertFirstBatch();
	void printAllStudents();

private:
	void createStudentsTable();
};
