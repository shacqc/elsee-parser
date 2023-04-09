#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <buffer.h>


bool object_flag;    //Activated when obj argument is given; ends when endobj argument is given
bool stream_flag;    //Activated when stream argument is given; ends when endstream argument is given
bool lendef_flag;   //Activated when length argument is given; ends when endstream argument is given
unsigned int length; //Length of File


int file_check(FILE *current_byte, int *correct_value)
{    
    unsigned char fptest[sizeof(correct_value)];
    unsigned int test;
    for (int i = 0; i < 9; i++)
        {
            fptest[i] = fgetc(current_byte);
        }
        
    sscanf(fptest, "%s", &test);

    if (test == *correct_value)
        {   
            return 0;
        }
    else 
        {
            printf("Error, this is not a valid HTML file; header is invalid", *correct_value, test);
            return -1;
        }
}

int Parser(FILE *fp, FILE *op)
{   
    //fopen file of choice
    unsigned const char HTML[9] = {33, 68, 79, 67, 84, 89, 80, 69};  // This is the <!DOCTYPE> part of the header
    fp = fopen("/home/shaq/Books/Economy/Karl Marx - Capital_ Volume I. 1-Progress Publishers (1995).pdf", "r");
    file_check(fp, HTML);
    linebuffer(fp, op, 0, HTML);  
    
}
