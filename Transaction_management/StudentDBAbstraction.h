#pragma once
#include"DBAbstraction.h"

class StudentDBAbstraction:DBAbstraction {

public:
	StudentDBAbstraction(string pathToFile);
	void insertFirstBatch();
	//void insertSecondBatchInATransaction();		// not working
	//void insertSecondBatchInATransactionv2();		// not working
	void printAllStudents();
	void insertSecondBatchInATransactionv3();

private:
	void createStudentsTable();
};
