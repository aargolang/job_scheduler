#include <iostream>
#include <string>
#include "Scheduler.h"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[])
{
	char *argument;
	Scheduler sch;
		
	if (argc > 1){
		argument = argv[1];
		sch.readFromFile(argument);
	}
	else {
		cout << "no arguments\nto test run \"./a jobs.txt\"" << endl;
		sch.tick();
	}
	
	
    return 0;
}
