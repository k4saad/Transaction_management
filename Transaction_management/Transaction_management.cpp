#include <iostream>
#include<string>
#include"StudentDBAbstraction.h"

using namespace std;

int main()
{
   
	StudentDBAbstraction studentsDb(":memory:");
	studentsDb.insertFirstBatch();
	return 0;
}


