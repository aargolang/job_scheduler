#include "Scheduler.h"
#include <cstring>

Scheduler::Scheduler()
{
	// default constructor
	
}

void Scheduler::tick(){
	tickCount = 0;
	idCount = 0;
	processors = 20;
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
		Job j;
		while(waitingJobs.isEmpty() != true){
			j = waitingJobs.findShortest();
			if (j.n_procs <= processors){
				j.end_time = tickCount + j.n_ticks;
				runningJobs.insertJob(j);
				processors = processors - j.n_procs;
				waitingJobs.deleteShortest();
			}
			else{
				break;
			}
		}
		while(runningJobs.isEmpty() != true){
			j = runningJobs.findShortest();
			if (j.end_time == tickCount){
				processors = processors + j.n_procs;
				cout << j.job_description << " " << j.n_ticks << " " << j.end_time <<endl;
				runningJobs.deleteShortest();
			}
			else{
				break;
			}
		}
		tickCount++;
	}
}

void Scheduler::readFromFile(char* filename){
	std::ifstream myfile;
	myfile.open(filename);
	string jobString;
	tickCount++;
	while (std::getline(myfile, jobString)){
		Job newJob;
		char* jobChar = &jobString[0u];
		newJob.job_description = strtok(jobChar, ",");
		newJob.n_procs = atoi(strtok(jobChar, ","));
		newJob.n_ticks = atoi(strtok(jobChar, ","));
		idCount++;		
		newJob.job_id = idCount;
		waitingJobs.insertJob(newJob);
		Job j;
		while(waitingJobs.isEmpty() != true){
			j = waitingJobs.findShortest();
			if (j.n_procs <= processors){
				j.end_time = tickCount + j.n_ticks;
				runningJobs.insertJob(j);
				processors = processors - j.n_procs;
				waitingJobs.deleteShortest();
			}
			else{
				break;
			}
		}
		while(runningJobs.isEmpty() != true){
			j = runningJobs.findShortest();
			if (j.end_time == tickCount){
				processors = processors + j.n_procs;
				cout << j.job_description << " " << j.n_ticks << " " << j.end_time <<endl;
				runningJobs.deleteShortest();
			}
			else{
				break;
			}
		}
		tickCount++;
	}
	tick();
}