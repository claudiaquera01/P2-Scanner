#ifndef ERRORS_H
#define ERRORS_H

//Error codes at Main
#define MAIN_ERROR_CANT_READ_FILE 1
#define MAIN_ERROR_MISSING_FILENAME 2

// Error codes at SCANNER
#define SCANNER_SUCCESS 0
#define SCANNER_ERROR_NONALPHABETCHAR 5

//Error messages at MAIN
extern const char* ERROR_MESSAGE_CANT_READ_FILE;
extern const char* ERROR_MESSAGE_MISSING_FILENAME;

// Error messages at SCANNER
extern const char* ERROR_MESSAGE_SCANNER_SUCCESS;
extern const char* ERROR_MESSAGE_RROR_NONALPHABETCHAR;

#endif
