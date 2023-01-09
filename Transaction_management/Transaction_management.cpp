#include <iostream>
#include<string>
#include"StudentDBAbstraction.h"

using namespace std;

int main()
{
   
	StudentDBAbstraction studentsDb(":memory:");
	studentsDb.insertFirstBatch();
	studentsDb.printAllStudents();
	//studentsDb.insertSecondBatchInATransaction();
	//studentsDb.insertSecondBatchInATransactionv2();
	studentsDb.insertSecondBatchInATransactionv3();
	studentsDb.printAllStudents();
	

	return 0;
}


