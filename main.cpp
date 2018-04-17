#include <iostream>
#include <queue>
#include <string>
#include "Scheduler.h"
#include "Job.h"
#include "JobQueue.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
	// Job(id, description, processors needed, ticks needed)
	
	JobQueue q;

	Job a(1,"asdf",2,6);
	Job b(1,"asdf",2,3);

	if(a<b)
		cout << "a is less" << endl;
	else if(b<a)
		cout << "b is less" << endl;

	Job j;

	cout << j.job_id << j.job_description << j.n_procs << j.n_ticks << endl;

    return 0;
}
