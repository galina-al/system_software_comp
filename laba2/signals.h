#ifndef LIB_H

#define LIB_H




#include <stdio.h>

#include "stack.h"



void addProcess(struct Cell **);

void deleteOneProcess(struct ProcessInfo);

void deleteAll(struct Cell **);

void Init();


int get_button();



#endif
