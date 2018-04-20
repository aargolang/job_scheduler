#include "ProcessingQueue.h"
#include "Job.h"

ProcessingQueue::ProcessingQueue(){

}
ProcessingQueue::~ProcessingQueue(){
	
}
void ProcessingQueue::insertJob(Job j){
	heap.push(j);
}
Job ProcessingQueue::findShortest(){
	return heap.top();
}
