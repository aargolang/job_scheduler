#ifndef JOBQUEUE
#define JOBQUEUE

#include <queue>
#include <vector>
#include <functional>
#include "Job.h"

using std::priority_queue;
using std::vector;
using std::greater;

struct compareJob
{
	bool operator()(const Job lhs, const Job rhs) const
	{
		return lhs.n_ticks > rhs.n_ticks;
	}
};

class JobQueue
{
public:
	JobQueue();
	~JobQueue();
	void insertJob(Job j);
	void deleteShortest();
	bool isEmpty();
	Job findShortest();

private:
	// from: https://stackoverflow.com/questions/2439283/how-can-i-create-min-stl-priority-queue
	priority_queue<Job, vector<Job>, compareJob > heap;
};

#endif
