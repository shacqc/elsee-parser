


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int32_t *PlacementPointer = 0;  //Assume Maximum supported length of HTML is 

/*Placed at top of virtual page. Decremented for each properly closed element. Parent will point to the highest child on the stack
If the element has no children, it will point to the current location on the Placement Stack Pointer.

Calloc needs to be done based on size of HTML however that can be found

Semantic Elements describes text within.

Sectioning describes the location of these arguments 

*/
int tag (char *parser)
{   
    uint8_t *Stack[100]; //Pointer to character; this shall hold arguments for elements
    
    int tagged = 1;

    if(*parser == '<')
    {
        if (*parser == '>')
        {
            pushElement();
        }

        else if (*parser == '/>')
        {
            popElement(*Stack);
            {

            } 
                //set array until the mark of the tag ending ' >' 
                //Function to unlimit referenced tag from tag stack and any exceptions and process exit
        }

    }
        //set array until the mark of the tag ending ' >' 
        // add argument into stack 
        // Process argument in respect to other elements in the stack.  
        // push argument into stack. Arguments on the stack determine what is done to other elements
}


uint8_t *pushElement(uint8_t *parser, uint8_t *Stack, uint8_t StackPointer)
{
//Since all arguments are process explicitly by 
parser++;   
Stack[StackPointer];
StackPointer--;
}

uint8_t *popElement(uint8_t *Stack)
{
    // After a pop, arguments shall be processed for the highest parent Element
    // 
    if('head')
    {
        ProcessHead();
    }

    if ('body')
    {
        ProcessBody();
    } 
}

ProcessHead()
{
        
}

ProcessBody()
{

}

ProcessTable()
{

}

ProcessMetadata()
{
        
}

ProcessAttribute(char *parser)  // this is executed after if "id" is true for xhtml, both id and name for html
{
    while(*parser != '=')
    {
        parser++;
    }
    while (*parser != '"')
    {
        parser++;
    }

}

strcmp(char *parser, char arg)
{
    if (CaseSensitive == 0)
    {
        while (*parser > 64 && *parser < 91 || *parser > 97 && *parser < 126)
        {
            if (*parser == arg || *parser == arg + 32 || *parser == arg - 32)
            {
                parser++; 
            }
            else
            {
                return 0;
            }   
        }
    }
    else
    {
        while (*parser > 64 && *parser < 91 || *parser > 97 && *parser < 126)
        {
            if (*parser == arg)
            {
                parser++; 
            }
            else
            {
                return 0;
            }    
        }
    }
}