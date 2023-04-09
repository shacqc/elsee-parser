

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
uint32_t *obj;
struct PageIndex    //Initialized upon finding the the amount of total pages in Root Treee
{
char *(*PageStack);   //Stack of pointers to an address within the file. These addresses shall refers to objects and for now,
char *(*StreamStack);    // Stack of pointers to a set of content streams; These shall point to the reference files they pertain to
int NumPagesSinceLastTree;  
int numofTreeNodes;                // More specifically Streams, Arguments should go from Page Tree --> other Page Tree if necessary -> Page -> Stream
uint32_t Index = 1; //
uint32_t StackPointer;
char *Offset;
};

uint32_t PageProcessor(char *parser, FILE* PDF, struct Trailer *Trailer)
{
/*
parser through until reference is found

Check parser +4 to confirm it is an object;  Any next char
other than obj after the offfset from 4 is an error for now

Backets mark the entry of an object. The last end bracket defines the end of object

All left brackets adds one to the delimitter and right brackets subtract one

There needs to be a 0 for amount of open brackets by the time you hit end object.

After Catalog if found, it is appropriate to search for a parent. This should be initialzied to zero. If there 
is no parent referenced and the pointer to the parent is not 0, an error should be returned as only one root hsould be alowed
The object with no parent shall initailize the stack to the size of its page count which should reflect all the pages within the document


Even in the presence of not root page trees, the parser will agressively search for the root being referred to the the catalog
until found, process such arguments and then return to the location of the Catalog

if (*parser == "/Catalog") if after a type, a length argument should return stream if not inside a page processing function

If stream is found and not length, check referencing page
*/

/*

Seek End of File
Decrement pointer until Trailer tag is found
Initialize Trailer
Increment to line to Xref Offset
Jump the pointer to the value added to offset of the beginning of the File 
Parser through Xref Table and find catalogue first
Allocate Stack based on total Pages
Find every Page Tree through the xref tables
Add pages from left to right then add if it is a page three, decrement stack based on the amount of kids
you can then start a recursive function that will sort out the entire page tree and its recursions first 
or you can find the top level page trees first  and sort them out when accessed
After all Pages are found, you can find search for streams


PDf can either be loaded page per page

Page tree per page tree

Or all pages can be stored in memory and the stream be accessed retroactively

For now, it is best to prioritize finding all the page trees and their pages. left to right, 
assign a pointer to the address of every stream. Ultimately, there should be a pointer to each page and a pointer to their 
content streams 

Other streams can be premptively access for game mode
*/

    
    // Points to the second to last element of the stack; If Root Stack Tree is found, set to bottom of astack
    long Offset = ftell((FILE*)PDF);
    long EndofFile = fseek((FILE*)PDF, 0L, SEEK_END);
    parser = parser - 4;
    if(*parser =! "%%EOF")
    {
        //Invalid PDF File "EOF cannot be found"
    }
    
    while(*parser =! "trailer")
    {
        parser--;
        while (*parser =! "<<")
        {
            parser++;
        }
     //Assign Trailer

     while (*parser =! "startxref")
        {
        parser += 10;
        int crossref = atoi(parser);
        parser = (char*)(crossref + Offset); //Jump to the XRef Table 
        }
    parser += Offset + crossref(parser, Trailer -> Root);  //This will jump to the offset of the Document's Catalog
    // Set up Catalog, grab the Root Page Tree
    // parser += Offset + crossref(referencenumber to Rootpage tree);
    //Find all the page trees
   
    }

       
// There should be a pointer to a stream for every argument. Each Argument needs a media box, a reference to a font, and a stream 
// Another Option is an array of page struct with a pointer to these locatiions 
// All arguments should be a pointer to an object 

}

int crossref(char *parser, int SearchedValue)
{   

    long *(RefNumOffsets) = (long*)malloc(sizeof(int) * 10); 
    int *RefNumValues = (int*)malloc(sizeof(int) * 10); 
    int *RefNumPointer = 0;
    for(int i = sizeof(RefNumOffsets); i > 0; i++)
    {
        if (RefNumValues[i] > SearchedValue)
        {
            parser = (char *)RefNumOffsets[i - 1] + (RefNumValues[i - 1] - SearchedValue); //Will lead 
            return SearchedValue;
        } 
    }
    int index = 0;
    while (*parser <= SearchedValue)
        {   
            char *FirstRef = parser;
            while (*(parser + 4) < 47)
            {
                parser += 20;   //This will skip any offset which is made up of ASCII numbers
            }
            int ReferenceNumber = atoi(FirstRef);
            int NextReference = atoi(parser);
            RefNumValues[*RefNumPointer] = atoi(parser);
            RefNumOffsets[*RefNumPointer] = (long)parser;
            FirstRef += SearchedValue - ReferenceNumber;  
            
            if (ReferenceNumber + NextReference > SearchedValue)   // Checks if searched value is within range 
            {    
                 //Add 
                return atoi(FirstRef); // This will return the offset that needs to be loaded  
            }
            
        }
}

int KidsProcess(char *parser, struct PageIndex *PageIndex)
{

    //Find R, load reference number, feed to reference table parser, it should return an offset
        //Make an array to page trees within stack. By the end, you should be able to resolve last table
        // Resolve one child of Parent tree at a time. This will be recursive. Once you reached the bottom of the very bottom stack
        // You have found all the pages and the stream pointers should be pointing to their streams 
    char* Offset = PageIndex -> Offset;
    char **PageStack = PageIndex -> PageStack;
    char **StreamStack = PageIndex -> StreamStack;
    uint32_t StackPointer = PageIndex -> StackPointer;
    char *obj;
        //Parse through and search for objects
        // If Object is found, Process Argument. If Catalog, allocate a new stack. For now , there should only be one Catalog per document
        // Total page count is found in root tree, Set to top of stack 
        if  (*obj == 'Page')
            {
                PageIndex -> NumPagesSinceLastTree++;
            
                if(*parser == '/Content')
                        {
                         if (*(parser + 14) == 'R')
                            {
                                StreamStack[StackPointer]  = Offset + crossref(parser, atoi(parser + 10)); 
                                ProcessStream(PageIndex);
                            
                            }
                         else 
                            {

                            }
                        }
            }
        if (*obj = 'Pages')
            {   
                PageIndex -> NumPagesSinceLastTree = 0;
                while (*parser != '/Count')
                {
                    parser++;
                }
                parser += 6;
                int pagecount = atoi(parser);   //Save Pointer Count 
                
                while (*parser != '/Pages')   // Can be replaced with kids if Page Process Function is changed Accordingly
                {
                    parser--;
                }
                StackPointer -= pagecount; //Decrement Stack Pointer by Amount of Descendant Pages
                *PageStack[StackPointer + 1] = pagecount; // Save the amount of descedant pages at Element 1
                PageStack[StackPointer] = parser;  // Set element here to the value of the page tree
                PageStack[StackPointer + pagecount] = PageStack[StackPointer]; // Save the Offset the Stack Pointer for the sake of going to the next page tree in line 
                PageIndex -> numofTreeNodes++;
            }
  PageIndex ->StackPointer--;
}

int ProcessStream(struct PageIndex *PageIndex)
{
int length = 0;
int filter = 0;
char PointSize;
char FontFile; 
char **PageStack = PageIndex -> PageStack;
char **StreamStack = PageIndex -> StreamStack;
uint32_t StackPointer = PageIndex -> StackPointer;
char *parser = StreamStack[StackPointer];
while (*parser > 46)
{
    parser++;
}
while (*parser != 'endsteam')
    if(*parser == '/Length')
        {
            while(length != 0)
            {
                while(*parser != 'stream')
                {
                if (*parser == '/Length') 
                    {
                    parser += 7;
                    length = atoi(parser);
                    }
                }
            parser = (char *)PageStack[StackPointer];
            while(*parser != 'endobj')
                { if (*parser == '/Length') 
                    {
                    parser += 7;
                    length = atoi(parser);
                    }
                }
            }
            if(*parser != '/Length')
            {
                return 255;  //Return error as length argument is missing for stream
            }
        }
    if(*parser == '/Filter')
        {
            while(length != 0)
                {
                    while(*parser != 'stream')
                    {
                    if (*parser == '/Length') 
                        {
                        parser += 7;
                        length = atoi(parser);
                        }
                    }
                parser = (char *)PageStack[StackPointer];
                while(*parser != 'endobj')
                    { if (*parser == '/Length') 
                        {
                        parser += 7;
                        length = atoi(parser);
                        }
                    }
                }
                if(*parser != '/Length')
                {
                    return 255;  //Return error as argument is missing for stream
                }
            }
    if(filter || length != 0)
        {
        //Start the decoding and processing of text. Function would need to convert data into ascii characters and send it to Font Engine
        }
}

int atoi(char *NumberString)
{  
    char *StartPos = NumberString;
    int result;
    while (*NumberString > 47 && *NumberString < 48)
    {
        NumberString++;
    }
    NumberString--;
    while (NumberString != StartPos)
    {
        result += (*NumberString) - 48;   //atoi
    }
return result;
}



uint32_t ProcessPageTree(char *parser, struct PageIndex *PageIndex)
{
    (*PageIndex).numofTreeNodes = 0;  //Reinitialize to 0 each time
    uint32_t StackPointer = PageIndex -> StackPointer;
    char **Stack = PageIndex -> PageStack;
    char *LastTree;
    while(*parser != 'Kids')
    {
        parser++;
    }
    while(*parser != ']')
    {
           while(*parser != 'R')
            {
                parser ++;
            }   
                if (*(parser - 4) > 47 && *(parser - 4) < 48)
                {
                    parser = (char *)(PageIndex -> Offset + crossref(parser, atoi((parser - 4))));
                    KidsProcess(parser, PageIndex);
                } 
    }
    LastTree = (char *)Stack[StackPointer];
    for (int i = 0; i < PageIndex -> numofTreeNodes; i++)
    {
        StackPointer += *Stack[StackPointer + 1];
    }  
    
    while(parser != LastTree)
    {
        ProcessPageTree(parser, PageIndex);
    }
    StackPointer--;
    parser = (char*)Stack[StackPointer];
    
}


// Need current Offset of the stack
/*
B
Elment  1 Num of Pages
Element 0 Location of Page Tree
Elment -1 Offset to Next Same Generation Child in Parent

At the End of every Array, Add the  Offset of the page  to process it after the next page tree, This can be done after
the current Page's Page Count is retrieved. Load a to i page count as Element 1; the Element at number page count shall store 
Stack Number of Element 0

It can happen both right to left and left to right.

For left to right, Initialize Stack Pointer at the stop of the stack

Add pages and page trees from the left and decrement the stack once for pages
if a page Tree is found, Find the Page count, decrement the stack by it, save the number as Element 1, Put the address of the Page Tree
at element zero and put the address of current locatoin of the stack at the Element of the Page count or Element[*Element[1]]

after this, go the end of the stack by incrementing to Beginning of Stack plus 1 then adding each Total Page Count within each tree
and repeating for the total number of trees

Once the loop is finished, it should be at the "first" page tree to load pages from,
Repeat this process. This way, the very first pages shall be loaded in order and the first page tree of the root shall be processed

*/
struct Catalog
{

};

struct Trailer
{
    uint32_t Size;   // Returns total number of entries in corss reference table inclduing update sections, Highest obj number of xref object is this 
    uint32_t Prev;  // Offset to previous corss section is any  
    uint32_t Root;    // Catalog idreict reference
    uint32_t Encrypt;     // If found, return error
    uint32_t Info;    // Info on File
    uint32_t ID;      //File Identifiers
};

struct Trailer ProcessTrailer(char *parser)
{
struct Trailer Trailer;

char *entry = parser;
for (parser = entry; *parser != '>>'; parser++)
    {
        if (*parser = 'Size')
        {
            Trailer.Size = atoi(parser);
        }
    }
for (parser = entry; *parser != '>>'; parser++)
    {
        if (*parser = 'Prev')
        {
            Trailer.Prev = atoi(parser);
        }
    }
for (parser = entry; *parser != '>>'; parser++)
    {
        if (*parser = 'Root')
        {
            Trailer.Root = atoi(parser);
        }
    }
for (parser = entry; *parser != '>>'; parser++)
    {
        if (*parser = 'Encrypt')
        {
            Trailer.Encrypt = atoi(parser);
        }
    }

for (parser = entry; *parser != '>>'; parser++)
    {
        if (*parser = 'Info')
        {
            Trailer.Info = atoi(parser);
        }
    }
for (parser = entry; *parser != '>>'; parser++)
    {
        if (*parser = 'ID')
        {
            Trailer.ID = atoi(parser);
        }
    }
return Trailer;
}
