#include "ProcessingQueue.h"
#include "Job.h"

ProcessingQueue::ProcessingQueue(){

}
ProcessingQueue::~ProcessingQueue(){
	
}
void ProcessingQueue::insertJob(Job j){
	heap.push(j);
}
void ProcessingQueue::deleteShortest(){
	heap.pop();
}
bool ProcessingQueue::isEmpty(){
	return heap.empty();
}
Job ProcessingQueue::findShortest(){
	return heap.top();
}
