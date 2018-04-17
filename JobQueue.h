#ifndef JOBQUEUE
#define JOBQUEUE

#include <queue>
#include <vector>
// #include "Job.h"

using std::priority_queue;
using std::vector;
using std::greater;

class JobQueue
{
public:
	JobQueue();
	~JobQueue();
	// void insertJob(Job j);
	void insertJob(int j);
	// Job findShortest();
	int findShortest();

private:
	// from: https://stackoverflow.com/questions/2439283/how-can-i-create-min-stl-priority-queue
	// priority_queue<Job, vector<Job>, greater<Job> > heap;
	priority_queue<int, vector<int>, greater<int> > heap;
};

#endif
