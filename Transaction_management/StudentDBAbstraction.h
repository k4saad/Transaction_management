#pragma once
#include"DBAbstraction.h"

class StudentDBAbstraction:DBAbstraction {

public:
	StudentDBAbstraction(string pathToFile);

private:
	void createStudentsTable();
};
