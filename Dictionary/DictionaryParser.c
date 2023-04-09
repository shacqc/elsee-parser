#include <dictionaryobjects.h>
#include <stdio.h>
#include <stdbool.h>
int DicSearch()
{   
    short *end; // this shall search for the terminator
    char i;
    char *buffer;
    char *state_length;  //Length of sentence
    char *word_storage[255]; //for storing senteces to process
    bool terminator_found;
    bool def_found;

    char (*declarations)[];

    while (def_found == 0)
    {   
         declarations = buffer;
         end = buffer;  //buffer is a byte sized entry so end shall be used to compare 2-byte sized values
        if(*declarations == 'def')
        {
            def_found = 1;
        }
        while(terminator_found != 1 && def_found != 1)
        {   
            *word_storage[i] = *buffer; 
            i++;
            if(*end == "/>") // In case of failure, equivalent value is 12094
            {      
                word_storage[i] = '/0'; //Be sure to remember to process any white space characters as 32 instead of null
                terminator_found = 1; 
            }   
        }
    }
}

