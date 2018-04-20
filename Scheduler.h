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
int processors;
void tick();
void readFromFile(char* filename);

private:
	JobQueue waitingJobs;
	JobQueue runningJobs;

};

#endif
