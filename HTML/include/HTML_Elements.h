#include <stdio.h>

char MetaDetaElements(char *iFile)
{   const char html[5] = "html";
    const char head[5] = "head";   //As the first element in an html 
    const char title[6] = "title";  // There can only be one Title in a header File
    const char link[5] = "link";  
    // links documents to other resources
       //Is part of flow content and phrasing content if within body, used in noscript element that is a child of the head
    //must have rel attribute or itemprop attribute, never both
    const char style[6] = "style"; //allows embed CSS style sheet  media defines which media it is defined to 
    const char meta[5] = "meta";  //if with itemprop, it can be used with flow or phrasing content, with name, meta content is expected 
    // If http is in encoding state or char set is present, it can be used. If encoding sate is not but it is in head or noscript child, it can laso be used 
    // author , description, generator, keywords
    //any sort of data
    const char base[5] = "base";  //links to other resources 
    // There can only be one base element ; No more than one are allowed. Otherwise, the others are ignored
    // It must have either a a href or target attribute or both 

}

char SectionElements(char *iFile)
{
    const char body[5] = "body";
    const char article[8] = "article";  // Flow Content, Sectioning Content, Palpable content 
    const char section[8] = "section";  //Should mainly be used only if the contents would be in document's outline
    const char aside[6] = "aside";  // Flow Content, Sectioning Content, Palpable content 
     const char hgroup[7] = "hgroup";
    const char h1[3] = "h1"; //h elmetns are used when is a child of head group or heading content is expected
    const char h2[3] = "h2"; // Seperate hader gorups are for explicity putting lower ranking headers together , no matter where, h1 is primary if theres no other h1
    const char h3[3] = "h3";
    const char h4[3] = "h4";
    const char h5[3] = "h5";
    const char h6[3] = "h6";
    const char header[7] = "header";  //flow content palable content  // Not required , used to wrap content of headers together f
    const char footer[7] = "footer";    //flow content palable content 
    const char address[8] = "address"; //flow content palable content , should be used for actual contact information
    const char nav[4] = "nav";  //Flow content,  links to other pages, uses href, can be used for email applciations 
}

char GroupingElements(char *iFile)
{
    const char p[2] = "p";  // Paragraph
    const char dl[3] = "dl"; //Description list
    const char dt[3] = "dt";    // Can be used before dd or inside dl, also inside div that are children of dl data type 
    const char dd[3] = "dd"; //data detail
    const char hr[3] = "hr";  // Transition in a text 
    const char pre[4] = "pre";  // Preformattted text 
    const char blockquote[11] = "blockquote";
    const char menu[5] = "menu";    
    const char li[3] = "li";        
     const char ol[3] = "ol";
    const char ul[3] = "ul";
    const char figure[7] = "figure";  //Flow content that represents  self ocntianed detail 
    const char figcaption[11] = "figcaption";  // First or last child of figure element
    const char main[5] = "main";
    const char div[4] = "div";  
}


char SemanticElements(char *iFile)
{
    const char a[2] = "a";  // Phrasing content and flow contnet, can be interactive if an href is included, also palable, no interactive cotnet 
    const char em[3] = "em";  // em is added for emphasis
    const char strong[7] = "strong"; // urgency 
    const char small[6] = "small";  // Disclaimers , meant for any short run of text that isn't essential for actual content.
    const char s[2] = "s";  // Unimportant 
    const char cite[5] = "cite";  // For citations 
    const char q[2] = "q";  // Quotations 
    const char dfn[4] = "dfn";  //Definition,    ancestor attributes do not affect it. Nearest ancesor  much contain the definition of the term given by the dfn elemtn 
    const char abbr[5] = "abbr"; //abbreviations 
    const char ruby[5] = "ruby";      // Handles East Asian characters
    const char rt[3] = "rt"; //Marks ruby text ccomopnent, end tag can be ommitted if immediately followed by a rt or rp elemtn
    const char rp[3] = "rp";    // Ruby parenthesis
    const char data[5] = "data";  // stores machine readable quantities 
    const char time[5] = "time";   //provides machine readable version of data time 
    const char code[5] = "code";    //Represents any piece of code 
    const char var[4] = "var";      // contains variables 
    const char samp[5] = "samp";    // Represents quoted output from anotehr porgram
    const char kbd[4] = "kbd";      // KeyBboard interface reference 
    const char sub[4] = "sub";  //represetns subscript 
    const char sup[4] = "sup";      // super script
    const char i[2] = "i";
    const char b[2] = "b";
    const char u[2] = "u";
    const char mark[5] = "mark";    // Marked or highlighted text for reference 
    const char bdi[4] = "bdi";  // Neglects semantics of right to left and left and right
    const char bdo[4] = "bdo";  // explicit direcitoning 
    const char span[5] = "span";    // Doesnt mean anything on its own, rpersents children of anything sub classes 
    const char br[3] = "br";    //line break
    const char wbr[4] = "wbr";  // line break opportunity /// if the argument is greater than size of entire buffer, line break at wbr
}

char EditElements(char *iFile) {
    const char ins[4] = "ins";  // Addition to an argument 
    const char del[4] = "del";  // Removal from document 
}
char TabularElements(char *iFile) {
    const char col[4] = "col";
    const char colgroup[9] = "colgroup";    //  // Start stag can be ommited if element is not imediatley preceded by another col group whose end tag is ommited 
// End tag can be ommitted if not folowed by ASCII whitespace or commit
    const char tr[3] = "tr";    // row
    const char th[3] = "th";    // represents header sell
    const char td[3] = "td";    // Child of tr, can be ommitted if no more contetnt in parent or if immediately followed by td and th
    const char thead[6] = "thead"; // end tag can be omitted if immediatley followed by tbody or tfoot 
    const char tbody[6] = "tbody";  //Block of row tht conissts of the data
    const char tfoot[6] = "tfoot"; // Only  child of its kind 
    const char table[6] = "table";  // Data with more than one dimension
    const char caption[8] = "caption";  // First child and Title of the table
}

char FormElements(char *iFile)
{
    const char progress[9] = "progress";
    const char optgroup[9] = "optgroup";
    const char textarea[9] = "textarea";
    const char meter[6] = "meter";
    const char input[6] = "input";  //A form control to allow the user edit the data 
    const char output[7] = "output";
    const char option[7] = "option";
    const char select[7] = "select";
    const char datalist[9] = "datalist";
    const char label[6] = "label";
    const char form[5] = "form";
    const char button[7] = "button";
    const char fieldset[9] = "fieldset";
    const char legend[7] = "legend";
}

char InteractiveElements(char *iFile)
{
    const char details[8] = "details";
    const char summary[8] = "summary";
    const char dialog[7] = "dialog";
}
char ScriptingElements(char *iFile)
{
    const char script[7] = "script";
    const char noscript[9] = "noscript";
    const char html_template[9] = "template";
    const char slot[5] = "slot";
    const char canvas[7] = "canvas";
}

char EmbeddedElements(char *iFile)
{
    const char picture[8] = "picture";  // Container of images with sources
    const char param[6] = "param";  //define parameters for plug in objects
    const char img[4] = "img";   // the actual image 
    const char video[6] = "video";
    const char embed[6] = "embed";
    const char iframe[7] = "iframe";
    const char source[7] = "source";    // Gives alternate means of data
    const char audio[6] = "audio";
    const char track[6] = "track";
    const char map[4] = "map";
    const char area[5] = "area";
};



/*    Html headers cannot be followed or initializd with comments  */
uint16_t head( )
{

}


uint16_t title( )
{


}

uint16_t html( )
{


}

uint16_t link( )
{


}

uint16_t style( )
{


}

uint16_t meta( )
{
    //look for attributes
    //if not item prop for meta arguments, look for head. Else, point to the parent 
    //This can occur for any data e
    for (int i = StackPointer; i >0;i++)
    {
        if(*StackPointer == "head")
        {

        }
    }
    if (head == NULL)
    {
        //Enact head push function. it should return error if a header already exists 
    }

}

uint16_t base( )
{


}

uint16_t body( )
{
}

uint16_t article( )
{

}

uint16_t aside( )
{
}

uint16_t header( )
{
}

uint16_t foter( )
{
}

uint16_t head( )
{
}

uint16_t head( )
{
}

uint16_t head( )
{
}

uint16_t head( )
{
}

uint16_t head( )
{
}

uint16_t head( )
{
}

uint16_t head( )
{
}

uint16_t head( )
{
}

uint16_t head( )
{
}

uint16_t head( )
{
}
uint16_t head( )
{
}






