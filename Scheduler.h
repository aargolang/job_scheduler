#ifndef SCHEDULER
#define SCHEDULER

#include <iostream>
#include <fstream>

#include "Job.h"
#include "JobQueue.h"

using std::cout;
using std::endl;



class Scheduler
{
public:

Scheduler();
int tickCount;
int idCount;
void tick();
void readFromFile(string filename, Scheduler a);

private:
	JobQueue waitingJobs;
	

};

#endif
