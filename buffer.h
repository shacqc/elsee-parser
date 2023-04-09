#include <stdbool.h>
#include <delimiterfunctions.h>
//Made into a struct in the case where multiple parsers are needed for simultaneous files are ofileen or multiple parsers are needed for whatever reason.
// Considering this is a buffer; it would greatly reduce overhead to not have to jump for these frequent functions
#define BUFFERSIZE 255

char inline out_viewer(char *ifile,char *ofile, char line, char delimiter_flag)
{   if (*ifile > 48)  //Just in case compiler doesn't optimize; it any non-delimiter characters should already be checked for bore this is executed
    {
            return *ifile;
    }
    else if (*ifile ==  0 || *ifile ==  9  || *ifile == 12 ||*ifile ==  20 || *ifile ==  32) //This returns the space byte; this prevents any absurdity from string operations
        {
            return 32; 
        }
    else if ( *ifile == 13 || *ifile == 15 || *ifile == 37)
        {
        
            *ofile = 12142;  // I am guessing that this will store an int. This should store a literal '/n' Solved by 47 (/) mutltipied by 258 (shift left by 8) + 110 (n)
            delimiter_flag++;
        }
} 

int linebuffer(char *ifile, char *ofile, int current_pos, int doc_types)
{   
    char delimiter_flag = 1;     //Files are delimited by default; Once a text argument is give; set delimiter_flag to zero .
    char line = current_pos%BUFFERSIZE;  //size of a buffer is usually by default 255 bytes long, the maximum value of 1 byte or a char
    int line_num = current_pos/BUFFERSIZE;
    char *place_holder =  (ofile - current_pos); // Decrementing to beginning of line despite being currently unnecessary but is there in case a backwards reference is ever needed; also, remember this is an int value.
    for (char line = 0; line  < BUFFERSIZE +1; line++)
    {
        while (delimiter_flag == 0 && *ifile%32 <  27 && *ifile > 47) //If it is probabilistically a displayable ASCII value, 
        {
            *ofile = out_viewer(ifile, ofile, line, delimiter_flag);
            ifile++; 
        }
        if (*ifile == 47)
        {      
            delimiter_flag++;
            ifile++;
            if  (*ifile == 110  || *ifile == 114)
            {
                line = 256;
                delimiter_flag--;
            }
            else if(*ifile == 62 || *ifile == 47 || *ifile == 116 || *ifile == 40 || *ifile == 41)   // Checking for literal values
            {
                *ofile = *ifile;
                delimiter_flag--;
            }

              //TO-DO Delimiter Function is needed; Grudrisse at the bottom
        }
    }
 
    if (delimiter(ifile) == 0)
    {
        *ofile = out_viewer(ifile, ofile, line, delimiter_flag);
    }
    line_num++; //Nextline
    line = 0;
    ofile =  place_holder + (line_num*255); //This will set the output file to the next line   
}

char inline delimiter(char *ifile)

{ // delimiter processor should check count the length of the argument and increment ifile pointer
    char *delimiter_args[255]; //No User should reasonably use more than this many delimiters per document; this allows a loop series with multiple delimiters
    char *delimiter = delimiter_args;
    char place_holder = ifile;
    int length = 1; 
    while (*delimiter != 0 && delimiter != delimiter_args) // Until 
    {   
        switch(*ifile){
            case 40:
                while (*ifile != 41)
                {
                    ifile++;
                    length++;
                }
            case 60:
                while (*ifile != 62)
                {
                    ifile++;
                    length++;
                }
        case 91:
            while (*ifile != 93)
            {
                ifile++;
                length++;
            }
        case 123:
                while (*ifile != 125)
                {
                    ifile++;
                    length++;
                }
        case 47:
                while (*ifile != 32)
                {
                    ifile++;
                    length++;
            }
            }
    if (length == 1) // This is likely an uncommon chracter within a text; just print it
    {
        return 0;
    }
    ifile -= length; //reset iFile
    *delimiter = length;
    delimiter++;
    char Resolve_Delimiter(char *ifile, char *delimiter);  
    }
}