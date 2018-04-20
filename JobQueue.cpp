#include "JobQueue.h"
// #include "Job.h"

JobQueue::JobQueue(){

}
JobQueue::~JobQueue(){
	
}
void JobQueue::insertJob(Job j){
	heap.push(j);
}
void JobQueue::deleteShortest(){
	heap.pop();
}
bool JobQueue::isEmpty(){
	return heap.empty();
}
Job JobQueue::findShortest(){
	return heap.top();
}
