OBJS = main.o Scheduler.o JobQueue.o ProcessingQueue.o
CC = g++
CPPFLAGS = -Wall -c -g -std=c++11
LFLAGS = -Wall -g

a: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o a

main.o:	main.cpp Job.h
	$(CC) $(CPPFLAGS) main.cpp 

Scheduler.o: Scheduler.h Scheduler.cpp
	$(CC) $(CPPFLAGS) Scheduler.cpp

Job.o: JobQueue.h
	$(CC) $(CPPFLAGS)
	
JobQueue.o: JobQueue.h JobQueue.cpp
	$(CC) $(CPPFLAGS) JobQueue.cpp
	
ProcessingQueue.o: ProcessingQueue.h ProcessingQueue.cpp
	$(CC) $(CPPFLAGS) ProcessingQueue.cpp
	
clean: 
	rm -f *.o 
	rm -f a
