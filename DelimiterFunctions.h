#include <stdio.h>
#include <pdf_flags.h>
#include <html_flags.h>
#include <PDF/include/PDF_Names.h>
#include <PDF/include/PDF_Objects.h>
#include <elseetypes.h>

enum doc_types{HTML, EPUB, MOBI, PDF};

 char Resolve_Delimiter(char *ifile, char *delimiter) 
    {   int doc_type;   //Dummy variable TO-DO, implement struct for this data
        if (doc_type == HTML)
        {
            Resolve_HTML(*ifile,  *delimiter);
        }
         if (doc_type == EPUB)
        {
            Resolve_EPUB( *ifile,  *delimiter);
        }
         if (doc_type == MOBI)
        {
            Resolve_MOBI( *ifile,  *delimiter);
        }
         if (doc_type == PDF)
        {
            Resolve_PDF( *ifile,  *delimiter);
        }
    }



   static char Resolve_HTML(char *ifile, char *delimiter)
    {

    }

   static char Resolve_EPUB(char *ifile, char *delimiter)
    {
       
    }
   static char Resolve_MOBI(char *ifile, char *delimiter)
    {

    }
    static char Resolve_PDF( char *ifile, char  *delimiter)
    {   
        NameProcessor(*ifile, "obj");
        if (*ifile != "end")
        {
            printf("PDF ERROR: Object improperly closed; PDF cannot be interpreted");
            return 255; 
        }

    }