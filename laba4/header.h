#ifndef STACK_H

#define STACK_H


#include <stdlib.h>

#include <stdio.h>



#ifdef __linux__


#include <sys/sem.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <termios.h>
#include <pthread.h>


struct ThreadInfo

{
	
	pthread_t thread;

};



struct MutexInfo

{

	pthread_mutex_t mutex;
	int count;
};

void *printID(void *arg);


#else


#include <Windows.h>
#include <process.h>
#include <conio.h>	

CRITICAL_SECTION cs;

struct ThreadInfo

{

	HANDLE thread;
};



struct MutexInfo

{

	int count;
};

DWORD WINAPI printID();

#endif



struct Cell

{
	
	struct ThreadInfo information;

	struct Cell *next;
};



	void init(struct MutexInfo *);
	struct ThreadInfo createNewThread(struct MutexInfo *);

	void deleteOneThread(struct ThreadInfo);

	void deleteAll(struct Cell **);

	void push(struct Cell**,struct ThreadInfo);

	struct ThreadInfo pop(struct Cell**);

	int get_button();



#endif
