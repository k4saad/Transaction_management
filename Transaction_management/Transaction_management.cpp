#include <iostream>
#include<string>
#include"StudentDBAbstraction.h"

using namespace std;

int main()
{
   
	StudentDBAbstraction studentsDb(":memory:");
	studentsDb.insertFirstBatch();
	studentsDb.printAllStudents();
	return 0;
}


