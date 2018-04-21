#include "Scheduler.h"
#include <cstring>

Scheduler::Scheduler()
{
	// default constructor
	tickCount = 0;
	idCount = 0;
	processors = 20;	
}

void Scheduler::tick(){
	bool quit = false;
	string jobString;
	string addJob;
	while (quit == false){
		std::cout << "Do you have a job to add? (y/n)\n";
		std::cin >> addJob;

		if (addJob == "y"){							// insert job into wait quueue
			cout << "\nEnter the job in the format job_description,n_procs,n_ticks" << endl;
			std::cin >> jobString;
			if (jobString.find("exit") != std::string::npos){
				break;
			}
			Job newJob;
			char* jobChar = &jobString[0u];
			newJob.job_description = strtok(jobChar, ",");
			newJob.n_procs = atoi(strtok(NULL, ","));
			newJob.n_ticks = atoi(strtok(NULL, "\n"));
			idCount++;
			newJob.job_id = idCount;
			waitingJobs.insertJob(newJob);
			cout << "Unique job ID number: " << newJob.job_id << endl;
		}
		else{
			cout << "No job added to waitingJobs this tick" << endl;
		}
		Job j;
		while(waitingJobs.isEmpty() != true){ 		// insert jobs into runQueue from waitQueue
			j = waitingJobs.findShortest();
			if (j.n_procs <= processors){
				cout << "Jobs added to runningJobs this tick: ";
				cout << j.job_description << " " << j.n_procs << " " << j.n_ticks <<endl;
				j.end_time = tickCount + j.n_ticks;
				runningJobs.insertJob(j);
				processors = processors - j.n_procs;
				waitingJobs.deleteShortest();
			}
			else{
				// print error if not inserted 
				break;
			}
		}
		while(runningJobs.isEmpty() != true){ 		// retire jobs that are done running in running queue
			j = runningJobs.findShortest();
			if (j.end_time <= tickCount){
				processors = processors + j.n_procs;
				cout << "Jobs removed from runningJobs this tick: ";
				cout << j.job_description << " " << j.n_procs << " " << j.n_ticks <<endl;
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
	while (getline(myfile,jobString)){				// get a new line and parse into new job
		Job newJob;
		char* jobChar = &jobString[0u];
		newJob.job_description = strtok(jobChar, ",");
		newJob.n_procs = atoi(strtok(NULL, ","));
		newJob.n_ticks = atoi(strtok(NULL, ","));
		idCount++;		
		newJob.job_id = idCount;
		waitingJobs.insertJob(newJob);
		cout << "Unique job ID number: " << newJob.job_id << endl;
		Job j;
		while(waitingJobs.isEmpty() != true){		// insert jobs into runQueue that can fir during this tick
			j = waitingJobs.findShortest();
			if (j.n_procs <= processors){
				j.end_time = tickCount + j.n_ticks;
				runningJobs.insertJob(j);
				processors = processors - j.n_procs;
				waitingJobs.deleteShortest();
				cout << "Jobs added to runningJobs this tick: ";
				cout << j.job_description << " " << j.n_procs << " " << j.n_ticks <<endl;
			}
			else{
				break;
			}
		}
		while(runningJobs.isEmpty() != true){		//
			j = runningJobs.findShortest();
			if (j.end_time == tickCount){
				processors = processors + j.n_procs;
				runningJobs.deleteShortest();
				cout << "Jobs removed from runningJobs this tick: ";
				cout << j.job_description << " " << j.n_procs << " " << j.n_ticks <<endl;
			}
			else{
				break;
			}
		}
		tickCount++;
	}
	
	Job j;
	while(runningJobs.isEmpty() != true){
				while(waitingJobs.isEmpty() != true){		// insert jobs into runQueue that can fir during this tick
			j = waitingJobs.findShortest();
			if (j.n_procs <= processors){
				j.end_time = tickCount + j.n_ticks;
				runningJobs.insertJob(j);
				processors = processors - j.n_procs;
				waitingJobs.deleteShortest();
				cout << "Jobs added to runningJobs this tick: ";
				cout << j.job_description << " " << j.n_procs << " " << j.n_ticks <<endl;
			}
			else{
				break;
			}
		}
		while(runningJobs.isEmpty() != true){
			j = runningJobs.findShortest();
			if (j.end_time == tickCount){
				processors = processors + j.n_procs;
				runningJobs.deleteShortest();
				cout << "Jobs removed from runningJobs this tick: ";
				cout << j.job_description << " " << j.n_procs << " " << j.n_ticks <<endl;
			}
			else{
				break;
			}
		}
		tickCount++;
		
	}
	tick();
}