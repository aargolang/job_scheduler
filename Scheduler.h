#ifndef SCHEDULER
#define SCHEDULER

#include <iostream>

#include "Job.h"
#include "JobQueue.h"

using std::cout;
using std::endl;



class Scheduler
{
public:

Scheduler();

private:
	JobQueue waitingJobs;


};

#endif
