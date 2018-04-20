#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <fstream>
#include "Scheduler.h"
#include "Job.h"
// #include "JobQueue.h"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

int main(int argc, char* argv[])
{
	char *argument;
	Scheduler sch;
	
	
	if (argc > 1){
		argument = argv[1];
		sch.readFromFile(argument);
	}
	else {
		cout << "no arguments" << endl;
		sch.tick();
	}

	
	
    return 0;
}
