#include "Scheduler.h"
#include <cstring>

Scheduler::Scheduler()
{
	// default constructor
	tickCount = 0;
	idCount = 0;
	totalProcessors = 20;
	availableProcessors = totalProcessors;
}

bool Scheduler::insertJob(int id, char* description, int procs, int ticks){
	// inserts a new job into the wait queue if 
	// 0 < procs < availableProcessors and 
	// ticks > 0
	
	if (procs > 0)
	{
		if (procs <= totalProcessors)
		{
			if (ticks > 0)
			{
				waitingJobs.insertJob(Job(id, description, procs, ticks));
				return true;
			}
			else 
				cout << "job.ticks <= 0: job not inserted" << endl;
		}
		else 
			cout << "job.n_procs > totalProcessors: job not inserted" << endl;
	}
	else
		cout << "job.n_availableProcessors <= 0: job not inserted" << endl;
	
	return false;
}
bool Scheduler::checkAvailability(int availableProcessorsWanted){
	// checks if the system can afford to process the next job
	if (availableProcessorsWanted <= availableProcessors)
		return true;
	else
		return false;
}
void Scheduler::runJob(Job &jobToRun){
	// inserts job from the waitqueue into the runqueue
	availableProcessors -= jobToRun.n_procs;
	runningJobs.insertJob(jobToRun);
	waitingJobs.deleteShortest();
	
}
void Scheduler::decrementTimer(){
	/*
	our design relies on a single incrementing single timer 
	rather than each job needing its own timer to be managed.
	this function is name as such to meet the requirements but
	will only increment the system timer
	*/
	tickCount++;
}
void Scheduler::releaseProcs(int procsToRelease){
	// intrement the processor counter when a job is retired
	availableProcessors += procsToRelease;
}


bool Scheduler::tick(){
	string jobString;
	string addJob;
	Job leastTickJob;
	Job jobEndingSoonest;
	char* tokenBuffer = nullptr;
	char* newJobDesc = nullptr;
	int newJobProcs = 0;
	int newJobTicks = 0;
	
	std::cout << "Do you have a job to add? (y/n)\n";
	std::cin >> addJob;

	if (addJob == "y"){							// insert job into wait quueue
		cout << "\nEnter the job in the format job_description,n_procs,n_ticks" << endl;
		cout << "type \'exit\' to leave" << endl;
		std::cin >> jobString;
		if (jobString.find("exit") != std::string::npos)
			return true;
			//break;
		
		char* jobChar = &jobString[0u];
		
		
		tokenBuffer = strtok(jobChar, ",");
		if(tokenBuffer != nullptr)
			newJobDesc = tokenBuffer;
		else{
			cout << "input invalid: missing job description" << endl;
			return false;
		}
		
		tokenBuffer = strtok(NULL, ",");
		if(tokenBuffer != nullptr)
			newJobProcs = atoi(tokenBuffer);
		else{
			cout << "input invalid: missing job.n_procs" << endl;
			return false;
		}
		
		tokenBuffer = strtok(NULL, ",");
		if(tokenBuffer != nullptr)
			newJobTicks = atoi(tokenBuffer);
		else{
			cout << "input invalid: missing job.n_ticks" << endl;
			return false;
		}
		
		
		idCount++;
		if(insertJob(idCount, newJobDesc, newJobProcs, newJobTicks) == false)
			return false;
		cout << "Unique job ID number: " << idCount << endl;
	}
	else{
		cout << "No job added to waitingJobs this tick" << endl;
	}
	
	while(waitingJobs.isEmpty() != true){ 		// insert jobs into runQueue from waitQueue
		leastTickJob = waitingJobs.findShortest();
		if (checkAvailability(leastTickJob.n_procs)){
			cout << "Jobs added to runningJobs this tick: ";
			cout << leastTickJob.job_description << " "; 
			cout << leastTickJob.n_procs << " "; 
			cout << leastTickJob.n_ticks << endl;
			leastTickJob.end_time = tickCount + leastTickJob.n_ticks;
			runJob(leastTickJob);
		}
		else{
			// no more jobs to be inserted into 
			break;
		}
	}
	
	while(runningJobs.isEmpty() != true){ 		// retire jobs that are done running in running queue
		jobEndingSoonest = runningJobs.findShortest();
		if (jobEndingSoonest.end_time <= tickCount){
			releaseProcs(jobEndingSoonest.n_procs);
			// availableProcessors = availableProcessors + j.n_procs;
			cout << "Jobs removed from runningJobs this tick: ";
			cout << jobEndingSoonest.job_description << " ";
			cout << jobEndingSoonest.n_procs << " ";
			cout << jobEndingSoonest.n_ticks << endl;
			runningJobs.deleteShortest();
		}
		else{
			break;
		}
	}
	decrementTimer();
	return false;
}

void Scheduler::readFromFile(char* filename){
	std::ifstream myfile;
	string jobString;
	char* newJobDesc = nullptr;
	
	int newJobProcs = 0;
	int newJobTicks = 0;
	Job leastTickJob;
	Job jobEndingSoonest;
	
	myfile.open(filename);
	
	while (getline(myfile,jobString)){				// get a new line and parse into new job
		char* jobChar = &jobString[0u];
		
		newJobDesc = strtok(jobChar, ",");
		newJobProcs = atoi(strtok(NULL, ","));
		newJobTicks = atoi(strtok(NULL, ","));
		idCount++;
		insertJob(idCount, newJobDesc, newJobProcs, newJobTicks);
		
		cout << "Unique job ID number: " << idCount << endl;
		
		while(waitingJobs.isEmpty() != true){ 		// insert jobs into runQueue from waitQueue
			leastTickJob = waitingJobs.findShortest();
			if (checkAvailability(leastTickJob.n_procs)){
				cout << "Jobs added to runningJobs this tick: ";
				cout << leastTickJob.job_description << " "; 
				cout << leastTickJob.n_procs << " "; 
				cout << leastTickJob.n_ticks << endl;
				leastTickJob.end_time = tickCount + leastTickJob.n_ticks;
				runJob(leastTickJob);
			}
			else{
				// no more jobs to be inserted into 
				break;
			}
		}
		
		while(runningJobs.isEmpty() != true){ 		// retire jobs that are done running in running queue
			jobEndingSoonest = runningJobs.findShortest();
			if (jobEndingSoonest.end_time <= tickCount){
				releaseProcs(jobEndingSoonest.n_procs);
				// availableProcessors = availableProcessors + j.n_procs;
				cout << "Jobs removed from runningJobs this tick: ";
				cout << jobEndingSoonest.job_description << " ";
				cout << jobEndingSoonest.n_procs << " ";
				cout << jobEndingSoonest.n_ticks << endl;
				runningJobs.deleteShortest();
			}
			else{
				break;
			}
		}
		decrementTimer();
	}
	
	while(runningJobs.isEmpty() != true){
		while(waitingJobs.isEmpty() != true){ 		// insert jobs into runQueue from waitQueue
			leastTickJob = waitingJobs.findShortest();
			if (checkAvailability(leastTickJob.n_procs)){
				cout << "Jobs added to runningJobs this tick: ";
				cout << leastTickJob.job_description << " "; 
				cout << leastTickJob.n_procs << " "; 
				cout << leastTickJob.n_ticks << endl;
				leastTickJob.end_time = tickCount + leastTickJob.n_ticks;
				runJob(leastTickJob);
			}
			else{
				// no more jobs to be inserted into 
				break;
			}
		}

		while(runningJobs.isEmpty() != true){ 		// retire jobs that are done running in running queue
			jobEndingSoonest = runningJobs.findShortest();
			if (jobEndingSoonest.end_time <= tickCount){
				releaseProcs(jobEndingSoonest.n_procs);
				// availableProcessors = availableProcessors + j.n_procs;
				cout << "Jobs removed from runningJobs this tick: ";
				cout << jobEndingSoonest.job_description << " ";
				cout << jobEndingSoonest.n_procs << " ";
				cout << jobEndingSoonest.n_ticks << endl;
				runningJobs.deleteShortest();
			}
			else{
				break;
			}
		}
		decrementTimer();	
	}
}