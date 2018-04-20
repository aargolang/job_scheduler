#ifndef JOB
#define JOB

#include <iostream>
#include <string>

using std::string;

class Job
{
public:
	
	Job(int id=0, const char* description="NULL", int procs=0, int ticks=0, int end=0)	{
		job_id = id;
		job_description = string(description);
		n_procs = procs;
		n_ticks = ticks;
		end_time = end;
	}
	Job(int id, string description, int procs, int ticks, int end)	{
		job_id = id;
		job_description = description;
		n_procs = procs;
		n_ticks = ticks;
		end_time = end;
	}

	int job_id;
	string job_description;
	int n_procs;
	int n_ticks;
	int end_time;

};

#endif
