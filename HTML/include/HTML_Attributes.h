

// hrefs must be specfied before any elements that have attriubtes that takes urls
//Return attribute of target 

//A base p156 element that is the first base p156 element with an href p157 content attribute in a document tree has a frozen base URL

// size attribute gives size of media 
//color is a maskicon link type and must only be specified on link with a rel attribute which contains a keyword
//Type makes interpreter assume resource is of given type 

//link element can have various functions but could be used for title, address of resouce, lnagauge, media reference or relatioship as specified by rel
char Global_Attributes(char *iFile) 
{
    const char accesskey[10] = "accesskey";
    const char autocapitalize[15] = "autocapitalize";
    const char autofocus[10] = "autofocus";
    const char contenteditable[17] = "contenteditable";
    const char dir[4] = "dir";
    const char draggable[10] = "draggable";
    const char enterkeyhint[13] = "enterkeyhint";
    const char hidden[7] = "hidden";
    const char inputmode[10] = "inputmode";
    const char is[3] = "is";
    const char itemid[7] = "itemid"; // unique for each item
    const char itemprop[9] = "itemprop";    // Allows 
    const char itemref[8] = "itemref";
    const char itemscope[10] = "itemscope"; //initializes item
    const char itemtype[19] = "itemtype";   // defines type of argument
    const char lang[5] = "lang";
    const char nonce[6] = "nonce";
    const char spellcheck[11] = "spellcheck";
    const char style[16] = "tabindex";
    const char tabindex[19] = "tabindex";
    const char title[16] = "title";
    const char translate[110] = "translate";
}


char Input_Attributes(char *iFile) {
    const char maxlength[10] = "maxlength";
    const char minlength[10] = "minlength";
    const char readonly[9] = "readonly";
    const char required[9] = "required";
    const char multiple[9] = "multiple";
    const char pattern[8] = "pattern";
    const char min[4] = "min";
    const char max[4] = "max";
    const char step[5] = "step";
    const char list[5] = "list";
    const char placeholder[12] = "placeholder";
}

char FormControl_Attributes(char *iFile) {
    const char name[5] = "name";
    const char dirname[8] = "dirname";
    const char maxlength[10] = "maxlength";
    const char minlength[10] = "minlength";
    const char disabled[9] = "disabled";
    const char autocomplete[13] = "autocomplete";
    const char action[7] = "action";      //following are form submission 
    const char enctype[8] = "enctype";
    const char method[7] = "method";
    const char novalidate[11] = "novalidate";
    const char target[7] = "target";
    const char formaction[11] = "formaction";  //followeing are form button types
    const char formenctype[12] = "formenctype";
    const char formmethod[11] = "formmethod";
    const char formnovalidate[15] = "formnovalidate";
    const char formtarget[11] = "formtarget";
}
char Edit_Attributes(char *iFile) {
    const char cite[5] = "cite";
    const char datetime[9] = "datetime";
}
char Boolean_Attributes(char *iFile) 
{
    const char checked[8] = "checked";
    const char disabled[9] = "disabled";
}

char Embed_Attributes(char *iFile)
{
    const char border[7] = "border";
    const char object_fit[11] = "object-fit";
    const char margin_right[13] = "margin-right";
    const char margin_left[12] = "margin-left";
    const char float_html[10] = "float";
    const char vertical_align[15] = "vertical-align";
    const char margin_top[11] = "margin-top";
    const char margin_bottom[14] = "margin-bottom";
    const char width[6] = "width";
    const char height[7] = "height";
    const char style[6] = "style";
}

char FormControlAttributes(char *iFile) 
{
    const char colSpan[8] = "colSpan";
    const char rowSpan[8] = "rowSpan";
    const char headers[8] = "headers";
    const char cellIndex[10] = "cellIndex";
    const char scope[6] = "scope";
    const char abbr[5] = "abbr";
}

char Source_Attributes(char *iFile)
{
    const char source_size_list[17] = "source-size-list";
    const char source_size[12] = "source-size";
    const char source_size_value[18] = "source-size-value";
    // TO-DO Sourceset Attributes

}

char EventHandler_Attributes(char *iFile) 
{
// Seems like a pain; probably will do as necessary
}


/*

char FormControlAttributes(char *iFile) {
const char maxlength[5] = "maxlength";
const char maxlength[5] = "maxlength";
const char maxlength[5] = "maxlength";
const char maxlength[5] = "maxlength";
const char maxlength[5] = "maxlength";
const char maxlength[5] = "maxlength";
const char maxlength[5] = "maxlength";
const char maxlength[5] = "maxlength";
const char maxlength[5] = "maxlength";
}

*/


