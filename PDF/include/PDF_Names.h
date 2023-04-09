#include <string.h>

int strcmp(char *input, const char *Name)
{     //Personal made string compare since the buffer may not have null terminated byte
    while (*Name == '/0')
    {   
        int total;
        total = input - Name;
        input++;
        Name++;
        return total;
    }
}

int PDF_name(char *iFile)
{
    strcmp(iFile, "Linearized");
    strcmp(iFile, "Dictionary");
    strcmp(iFile, "Name");
    strcmp(iFile, "NameNode");
    strcmp(iFile, "NumNode");
    strcmp(iFile, "Stream");
    strcmp(iFile, "Catalog");
    strcmp(iFile, "Filters");
    strcmp(iFile, "Resource");
    strcmp(iFile, "function");
    strcmp(iFile, "File_Trailer");

    File_Trailer(iFile);
    Linearization(iFile);
    Dictionary(iFile);
    Name(iFile);
    NameNode(iFile);
    NumNode(iFile);
    Streams(iFile);
    Catalog(iFile);
    Filters(iFile);
    Resource(iFile);
    function(iFile);
}


char Linearization(char *iFile){    
    const char L[2] = "L";
    const char H[2] = "H";
    const char O[2] = "O";
    const char E[2] = "E";
    const char N[2] = "N";
    const char T[2] = "T";

    strcmp(iFile, "T");
    strcmp(iFile, "L");
    strcmp(iFile, "H");
    strcmp(iFile, "O");
    strcmp(iFile, "E");
    strcmp(iFile, "N");
};


char Dictionary(char *iFile){
    const char Type[5] = "Type";
    const char Lang[5] = "Lang";
    const char Version[8] = "Version";
    const char Pages[6] = "Pages";
    const char Dests[6] = "Dests";
    const char Outlines[9] = "Outlines";
    const char DecodeParms[12] = "DecodeParms";
    const char SpiderInfo[11] = "SpiderInfo";
    const char Parent[7] = "Parent";
    const char Kids[5] = "Kids";

    strcmp(iFile, Type);
    strcmp(iFile, Lang);
    strcmp(iFile, Version);
    strcmp(iFile, Pages);
    strcmp(iFile, Dests);
    strcmp(iFile, Outlines); 
    strcmp(iFile, DecodeParms);
    strcmp(iFile, SpiderInfo);
    strcmp(iFile, Type);
    strcmp(iFile, Parent);
    strcmp(iFile, Kids);
    strcmp(iFile, Version);
};

char Name(char *iFile)
{
    const char Dests[6] = "Dests";
    const char AP[3] ="AP";
    const char JavaScript[11] = "JavaScript";
    const char Pages[6] = "Pages";
    const char Templates[10] = "Templates";
    const char IDS[4] ="IDS";
    const char URLS[5] = "URLS";
    const char EmbeddedFiles[14] = "EmbeddedFiles";

    strcmp(iFile, Dests);
    strcmp(iFile, AP);
    strcmp(iFile, JavaScript);
    strcmp(iFile, Pages);
    strcmp(iFile, Templates);
    strcmp(iFile, IDS);
    strcmp(iFile, URLS);
    strcmp(iFile, EmbeddedFiles);
};

char NameNode(char *iFile)
{
    const char Kids[5] = "Kids";
    const char names[6] = "Names";
    const char Limits[7] = "Limits";

    strcmp(iFile, Kids);
    strcmp(iFile, names);
    strcmp(iFile, Limits);
};

char NumNode(char *iFile)
{
    const char Kids[5] = "Kids";
    const char Nums[5] = "Nums";
    const char Limits[7] = "Limits";

    strcmp(iFile, Kids);
    strcmp(iFile, Nums);
    strcmp(iFile, Limits);
};


char Streams (char *iFile)
{
    const char Length[7] = "Length";
    const char filter[7] = "Filter";
    const char MarkInfo[9] = "MarkInfo";
    const char DecodeParms[12] = "DecodeParms";
    const char F[2] = "F";
    const char FFilter[8] = "FFilter";
    const char FDecodeParms[13] = "FDecodeParms";

    strcmp(iFile, Length);
    strcmp(iFile, DecodeParms);
    strcmp(iFile, F);
    strcmp(iFile, FFilter);
    strcmp(iFile, FDecodeParms);
    strcmp(iFile, MarkInfo);
};

char Catalog(char *iFile)
{
    const char type[5] = "Type";
    const char Version[8] = "Version";
    const char pages[6] = "Pages";
    const char PageLabels[11] = "PageLabels";
    const char names[6] = "Names";
    const char dests[6] = "Dests";
    const char ViewerPreferences[18] = "ViewerPreferences";
    const char PageLayout[11] = "PageLayout";
    const char PageMode[9] = "PageMode";
    const char outlines[9] = "Outlines";
    const char Threads[8] = "Threads";
    const char OpenAction[11] = "OpenAction";
    const char AA[3] = "AA";
    const char URI[4] = "URI";
    const char AcroForm[9] = "AcroForm";
    const char Metadata[9] = "Metadata";
    const char charTreeRoot[15] = "charTreeRoot";
    const char MarkInfo[9] = "MarkInfo";
    const char lang[5] = "Lang";
    const char SpiderInfo[11] = "SpiderInfo";
    const char OutputIntents[14] = "OutputIntents";

    strcmp(iFile, "Type");
    strcmp(iFile, "Version");
    strcmp(iFile, "Pages");
    strcmp(iFile, "PageLabels");
    strcmp(iFile, "Names");
    strcmp(iFile, "Dests");
    strcmp(iFile, "ViewerPreferences");
    strcmp(iFile, "PageLayout");
    strcmp(iFile, "PageMode");
    strcmp(iFile, "Outlines"); 
    strcmp(iFile, "Threads");
    strcmp(iFile, "OpenAction");
    strcmp(iFile, "AA");
    strcmp(iFile, "URI");
    strcmp(iFile, "AcroForm");
    strcmp(iFile, "Metadata");
    strcmp(iFile, "charTreeRoot");
    strcmp(iFile, "MarkInfo");
    strcmp(iFile, "Lang");
    strcmp(iFile, "SpiderInfo");
    strcmp(iFile, "OutputIntents");
};


char Filters(char *iFile)
{
    const char ASCIIHexDecode[15] = "ASCIIHexDecode";
    const char ASCII85Decode[14] = "ASCII85Decode";
    const char LZWDecode[10] = "LZWDecode";
    const char FlateDecode[12] = "FlateDecode";
    const char RunLengthDecode[16] = "RunLengthDecode";
    const char CCITTFaxDecode[15] = "CCITTFaxDecode";       
    const char JBIG2Decode[12] ="JBIG2Decode";
    const char DCTDecode[10] = "DCTDecode";

    strcmp(iFile, ASCIIHexDecode);
    strcmp(iFile, ASCII85Decode);
    strcmp(iFile, LZWDecode);
    strcmp(iFile, FlateDecode);
    strcmp(iFile, RunLengthDecode);
    strcmp(iFile, CCITTFaxDecode);  
    strcmp(iFile, JBIG2Decode);
    strcmp(iFile, JBIG2Decode);
};

char Resource(char *iFile)
{
    const char ExtGState[10] = "ExtGState";
    const char ColorSpace[11] = "ColorSpace";
    const char Pattern[8] = "Pattern";
    const char Shading[8] = "Shading";
    const char XObject[8] = "XObject";
    const char Font[5] = "Font";        
    const char ProcSet[8] ="ProcSet";
    const char Properties[11] = "Properties";

    strcmp(iFile, ExtGState);
    strcmp(iFile, ColorSpace);
    strcmp(iFile, Pattern);
    strcmp(iFile, Shading);
    strcmp(iFile, XObject);
    strcmp(iFile, Font); 
    strcmp(iFile, ProcSet);
    strcmp(iFile, Properties);
    };
    char function(char *iFile){
    const char FunctionType[13] = "FunctionType";
    const char Domain[7] = "Domain";
    const char Range[6] = "Range";
    strcmp(iFile, FunctionType);
    strcmp(iFile, Domain);
    strcmp(iFile, Range);
};

char File_Specification(char *iFile)
{
    const char ASCIIHexDecode[15] = "ASCIIHexDecode";
    const char ASCII85Decode[14] = "ASCII85Decode";
    const char LZWDecode[10] = "LZWDecode";
    const char FlateDecode[12] = "FlateDecode";
    const char RunLengthDecode[16] = "RunLengthDecode";
    const char CCITTFaxDecode[15] = "CCITTFaxDecode";    
    const char JBIG2Decode[12] ="JBIG2Decode";
    const char DCTDecode[10] = "DCTDecode";
    strcmp(iFile, DCTDecode);
    strcmp(iFile, ASCIIHexDecode);
    strcmp(iFile, ASCII85Decode);
    strcmp(iFile, LZWDecode);
    strcmp(iFile, FlateDecode);
    strcmp(iFile, RunLengthDecode);
    strcmp(iFile, CCITTFaxDecode);     
    strcmp(iFile, JBIG2Decode);
};


char File_Trailer(char *iFile)
{
    const char Size[5] = "Size";
    const char Prev[5] = "Prev";
    const char Root[5] = "Root";
    const char Encryption[12] ="Encryption";
    const char Info[5] = "Info";
    const char ID[3] ="ID";

    strcmp(iFile, Size);
    strcmp(iFile, Prev);
    strcmp(iFile, Root);
    strcmp(iFile, Encryption);
    strcmp(iFile, Info);
    strcmp(iFile, ID);
};

char Encryption(char *iFile)
{    
    const char Filter[7] = "Filter";
    const char Length[7] = "Length";
    const char V[2] = "V";
    const char R[2] = "R";
    const char O[2] = "O";
    const char U[2] = "U";
    const char P[2] = "P";

    strcmp(iFile, Filter);
    strcmp(iFile, Length);
    strcmp(iFile, V);
    strcmp(iFile, R);
    strcmp(iFile, O);
    strcmp(iFile, U);
    strcmp(iFile, P);
};

