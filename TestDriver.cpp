#include <iostream>
#include <queue>
#include <string>
#include "Scheduler.h"
#include "Job.h"
#include "JobQueue.h"
#include "ProcessingQueue.h"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

int main(int argc, char* argv[])
{
	/*
	JobQueue p;
	
	p.insertJob(Job(0,"j1",0,5,30));
	p.insertJob(Job(0,"j2",0,2,10));
	p.insertJob(Job(0,"j3",0,9,15));
	p.insertJob(Job(0,"j4",0,1,45));
	
	cout << p.findShortest().job_description << endl;
	p.deleteShortest();
	cout << p.findShortest().job_description << endl;
	p.deleteShortest();
	cout << p.findShortest().job_description << endl;
	p.deleteShortest();
	cout << p.findShortest().job_description << endl;
	p.deleteShortest();
	
	
	
	*/
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
