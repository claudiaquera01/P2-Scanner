#ifndef TOKEN_HEADER
#define TOKEN_HEADER



#include <stdlib.h>

#include <string.h>
#include <stdbool.h>


#include "utils.h"



#define MAX_LEXEME_LENGTH 100






typedef enum {
    CAT_NUMBER,
    CAT_IDENTIFIER,
    CAT_KEYWORD,
    CAT_LITERAL,
    CAT_OPERAND,
    CAT_SPECIALCHAR,
    CAT_NONRECOGNIZED
} TokenCategory;

// Define token structure
typedef struct { //TODO: <- there is a name mussing here after struct (use something like struct_token)
    char lexeme[MAX_LEXEME_LENGTH];
    TokenCategory category;
    int line_number; // For DEBUG mode
} Token;




/*
Represents a Deterministic Finite Automata (DFA, https://en.wikipedia.org/wiki/Deterministic_finite_automaton)

alphabet is a reference to a string containing all valid symbols of the alphabet 
of the automata (sigma). alphabet is a reference and DFA does NOT own it. 
Assumes that the characters in alphaber are SORTED increasingly. Also assumes alphabet 
is constant. 

len_alphabet is the length of the alphabet. 

Each state is represented as an integer. The state 0 is reserved for the rejecting state. 
Also note that the state 1 us the deafult state for the initial state (q0), 
although it can be changed. 

num_states is the number of valid states and represents the states (q). 
It counts the number of valid states NOT includeing the rejecting state. 
ex: if num_states == 1, then there will only be the rejecting state (0) and 
the state 1. if num_states == 4, then ther will be the rejecting state (0) 
and the states 1, 2, 3, 4. 

final_states is a list of all the accepting states (F). It should NOT include 0. 
len_final_states is the length of final_states. DFA holds ownership of final_states

current_state is the current state of the automata. 

transition_table (delta) is a matrix that holds all necessary information to 
traverse the DFA. It can be accessed as transition_table[state * (len_alphabet) + symbol_index]
DFA holds ownership of transition_table

alive is true if the automata has NOT reached the rejectiong state (0). 

*/
typedef struct struct_dfa {

    char* alphabet; 
    int len_alphabet; 

    int num_states;     
    int* transition_table; 
    int initial_state; 
    int current_state; 

    int* final_states; 
    int len_final_states; 

    bool alive; 

} DFA; 



//functions

/*
initializes the DFA with the given data. DFA does NOT take ownership of alphabet but DOES take
ownership of final_states. read the definition of DFA for more info
*/
void initialize_dfa(DFA* dfa, char* _alphabet, int _num_states, int* _final_states, int _len_final_states) {

    dfa->alphabet = _alphabet; 
    dfa->len_alphabet = strlen(dfa->alphabet); 

    dfa->num_states = _num_states; 
    dfa->transition_table = (int*)calloc(sizeof(int), dfa->len_alphabet * dfa->num_states); 
    // ^ all the table is initialized to 0. this way, if a connection is not defined, the 
    // DFA will automatically reject the string

    dfa->final_states = _final_states; 
    dfa->len_final_states = _len_final_states; 

    dfa->initial_state = 1; // deafult values
    dfa->current_state = 1; 

    dfa->alive = true; 

}


/*
uses binary search to determinate the index of the element element in list. 
list must be sorted and len is the length of the list. 

returns the index of element or -1 if the element is not found in the list

this will be used in the dfa for moving the state with the transition table

*/
int get_symbol_index_BS(char* list, int len, char element) {
    
    int l = 0; //left
    int r = len - 1; //right
    int m; //middle

    while(l <= r) {
        m = (l + r) >> 1; // floor  l+r / 2
        if(list[m] < element) {
            l = m + 1; 
        } else if (element < list[m]) {
            r = m - 1; 
        } else { // elemnet == list[m]
            return m; 
        }

    }

    return -1; //unsuccessfull

}


/*
frees all the contents inside the dfa. does NOT free alphabet nor the dfa itself .
*/
void free_dfa(DFA* dfa) {

    free(dfa->transition_table); 
    free(dfa->final_states); 

}




























#endif