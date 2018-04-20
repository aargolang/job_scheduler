#ifndef PROCQUEUE 
#define PROCQUEUE

#include <queue>
#include <vector>
#include <functional>
#include "Job.h"

using std::priority_queue;
using std::vector;
using std::greater;

struct compareEnd
{
	bool operator()(const Job lhs, const Job rhs) const
	{
		return lhs.end_time > rhs.end_time;
	}
};

class ProcessingQueue
{
public:
	ProcessingQueue();
	~ProcessingQueue();
	void insertJob(Job j);
	void deleteShortest();
	bool isEmpty();
	Job findShortest();

private:
	// from: https://stackoverflow.com/questions/2439283/how-can-i-create-min-stl-priority-queue
	priority_queue<Job, vector<Job>, compareEnd > heap;
};

#endif
