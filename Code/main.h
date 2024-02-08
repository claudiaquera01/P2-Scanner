#ifndef MAIN_HEADER
#define MAIN_HEADER

#include "errors.h"
#include "scanner.h"
#include "debug.h"
#include "datastructures.h"
#include "dfatables.h"

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 8191
//^2**13 - 1

#define BUFFER_THRESHOLD 0.75
// when buffer is BUFFER_THRESHOLD, write to file

char *processFile(const char *filename);

/*
    based on the name of the file, creates the name of the output file

*/
char *get_file_name(const char *argv1);

#endif
