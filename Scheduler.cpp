#include "Scheduler.h"
#include <cstring>

Scheduler::Scheduler()
{
	// default constructor
	
}

void Scheduler::tick(){
	tickCount = 0;
	idCount = 0;
	bool quit = false;
	char* jobString = nullptr;
	int newProcessors;
	int newTicks;
	char addJob;
	while (quit == false){
		std::cout << "Do you have a job to add? (y/n)\n";
		std::cin >> addJob;
		if (addJob == 'y'){
			cout << "\nEnter the job in the format <job_description,n_procs,n_ticks>" << endl;
			std::cin >> jobString;
			if (std::strstr(jobString, "quit") == nullptr){
				break;
			}
			Job newJob;
			newJob.job_description = strtok(jobString, ",");
			newJob.n_procs = atoi(strtok(jobString, ","));
			newJob.n_ticks = atoi(strtok(jobString, ","));
			idCount++;
			newJob.job_id = idCount;
			waitingJobs.insertJob(newJob);
		}
	}
}

void Scheduler::readFromFile(std::string filename, Scheduler a){
	std::ifstream myfile;
	myfile.open(filename);
	string jobString;
	while (std::getline(myfile, jobString)){
		Job newJob;
		char* jobChar = &jobString[0u];
		newJob.job_description = strtok(jobChar, ",");
		newJob.n_procs = atoi(strtok(jobChar, ","));
		newJob.n_ticks = atoi(strtok(jobChar, ","));
		idCount++;		
		newJob.job_id = a.idCount;
		waitingJobs.insertJob(newJob);
	}
}