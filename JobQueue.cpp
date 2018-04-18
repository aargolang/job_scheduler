#include "JobQueue.h"
// #include "Job.h"

JobQueue::JobQueue(){

}
JobQueue::~JobQueue(){
	
}
void JobQueue::insertJob(Job j){
	heap.push(j);
}
Job JobQueue::findShortest(){
	return heap.top();
}
