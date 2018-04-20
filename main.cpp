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



		string line;
		std::ifstream jobFile (argv[1]);
		while (std::getline (jobFile, line)){
			string delimiter = " ";
			size_t position = 0;
		}
    return 0;
}
