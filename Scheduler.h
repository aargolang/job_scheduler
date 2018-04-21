#ifndef SCHEDULER
#define SCHEDULER

#include <iostream>
#include <fstream>

#include "Job.h"
#include "JobQueue.h"
#include "ProcessingQueue.h"

using std::cout;
using std::endl;



class Scheduler
{
public:

Scheduler();

bool insertJob(int id, char* description, int procs, int ticks);
bool checkAvailability(int processorsWanted);
void runJob(Job &jobToRun);
void decrementTimer();
void releaseProcs(int procsToRelease);

int tickCount;
int idCount;
int availableProcessors;
int totalProcessors;
bool tick();
void readFromFile(char* filename);

//private:
	JobQueue waitingJobs;
	ProcessingQueue runningJobs;

};

#endif
