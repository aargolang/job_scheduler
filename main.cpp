#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include "Scheduler.h"
#include "Job.h"
// #include "JobQueue.h"

using std::cout;
using std::endl;
using std::string;

int main(int argc, string argv[])
{
	// Job(id, description, processors needed, ticks needed)

	Scheduler a;
	a.tickCount = 0;
	a.idCount = 0;
	if (argc == 1){
		char moreUsers = 'y';
		string newDescription;
		int newProcessors;
		int newTicks;
		while(moreUsers == 'y'){
			cout << "\nEnter the job description" << endl;
			std::cin >> newDescription;
			cout << "\nEnter the number of processors you need\n";
			std::cin >> newProcessors;
			cout << "\nEnter the number of ticks your process will take\n";
			std::cin >> newTicks;
			Job newJob;
			newJob.job_description = newDescription;
			newJob.n_procs = newProcessors;
			newJob.n_ticks = newTicks;
			newJob.job_id = a.idCount;
			a.idCount++;

			cout << "\nDo any other users want to enter jobs? (y/n)\n";
			std::cin >> moreUsers;
		}
	}
	else {
		string line;
		std::ifstream jobFile (argv[1]);
		while (std::getline (jobFile, line)){
			string delimiter = " ";
			size_t position = 0;
		}

	}
    return 0;
}
