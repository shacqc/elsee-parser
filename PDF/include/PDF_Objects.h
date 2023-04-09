#include <string.h>

const char obj[4] = "obj";
const char Stream[7] = "stream";
const char boolean[8] = "boolean";
const char integer[12] = "IntegerItem";
const char string[11] = "StringItem";
const char names[6] = "names";
const char arrays[7] = "arrays";
const char Dictionaries[13] = "Dictionaries";
const char null[5] = "null";
const char Version[8] = "Version";


int strcmp(char *input, const char *Name)
{     //Personal made string compare since the buffer may not have null terminated byte
    while (*Name != '/0')       //It may be possible for a file argument to be improperly null terminated. In the case of those exceptions, we stop in the presence of the latter's null string
        {   int total;
            total = *input - *Name;
            input++;
            Name++;
            return total;
        }
}

char NameProcessor(char *ifile, char *argument)
{
    char *NameAddresses[255]; // Shall save the addresses of Name. These can be treated as null terminated.
    char  NamePointer = 0;

    if (strcmp (ifile, argument) == 0)
    {   
            SpeedParser(ifile);  //Will continue file pointer until a non-white space or non line character is found
        if (*ifile != "<<")
        {
            printf("PDF ERROR: Name or Object improperly declared; PDF cannot be interpreted");
            return 255; 
        }
        while(*ifile != ">" || *ifile != argument )
        {
            if (*ifile == "/")                                     /* Function will save the addresses of all name   */
            {
                NameAddresses[NamePointer] = ifile;    
                NamePointer++;
                SpeedParser(ifile);
            }    
                if (*ifile == "<<")                                     /* Function will save the addresses of all name   */
                {
                    NameProcessor(ifile, NameAddresses);
                }                                                                            
            }   
        if (*ifile == ">>")
        {
            NameResolv(ifile, NameAddresses);
        }
    }
}

    
char NameResolv(char *input, char *NameAddresses[255])
{                                                                   /*PDF Specifications never stated that the Names must occur in a specified order. As such, the
                                                                    code will search the entire Name Array for the proper values. This way, even if it is truly required, time would not be lost checking all the values
                                                                    Catalog requires Pages, Pages requires Kids, Parents, and Count */

    for (int i = 1; NameAddresses[i] != 0; i++)
    {
        if (strcmp(NameAddresses[i], "Type") == 0)
        {
            if (strcmp(NameAddresses[i+1], "Catalog") == 0)
            {    
                if (strcmp(NameAddresses[i+2], "Pages") == 0)
                {
                    if (strcmp(NameAddresses[i+1], "Kids") == 0 && strcmp(NameAddresses[i+2],"Parent") == 0 && strcmp(NameAddresses[i+2], "Count") == 0)
                    {

                    }
                    else if (CheckRequirement (*NameAddresses[255], "Kids") == 0 && CheckRequirement (*NameAddresses[255], "Count") == 0)
                    {
                        if (CheckRequirement (*NameAddresses[255], "Parent") == 0)  
                        {
                            for (int j = i + 1; i < 0; i++)
                            {
                                if (strcmp(NameAddresses[j], "Parent") == 0)
                                {
                                    return -1;  // This should return error; Only the root is permitted to have no parent
                                }
                            }
                        }
                    }
                    else 
                        {
                            return -1;
                        }
                } 
            }
        else if (strcmp(NameAddresses[i+1], "Pages") == 0)
        {
            if (strcmp(NameAddresses[i+1], "Kids") == 0 && strcmp(NameAddresses[i+2],"Parent") == 0 && strcmp(NameAddresses[i+2], "Count") == 0)
            {

            }
            else if (CheckRequirement (*NameAddresses[255], "Kids") == 0 && CheckRequirement (*NameAddresses[255], "Count") == 0)
            {
                if (CheckRequirement (*NameAddresses[255], "Parent") == 0)  
                {
                    for (int j = i + 1; i < 0; i++)
                    {
                        if (strcmp(NameAddresses[j], "Parent") == 0)
                        {
                        return -1;  // This should return error; Only the root is permitted to have no parent
                        }
                    }
                }
            }
            else 
            {
                return -1;
            }
        }   
        else 
        {
            if (strcmp(NameAddresses[i+1], "Page") == 0)
            {
                if (strcmp(NameAddresses[i+2], "Resources") == 0)
                {
                            
                }
                else 
                {
                CheckRequirement(*NameAddresses[255], "Resources") == 0;
                }
            }
        }

        }
        else if (strcmp(NameAddresses[i], "Length") == 0)
        {

        }
        
    }
}

char CheckRequirement(char *NameAddresses[255], const char Requirement)
{    
    for (int i = 0; NameAddresses[i] != 0; i ++)
    {
        strcmp(NameAddresses[i], Requirement);
    }
}


//1/72 per in is default glyph size in user space 
//PDFs have 14 standard fonts 

// Tr is text rendering mode 
// Tj defines line thickness


//BT establishes Text position and points where to produce glyphs

//MediaBox is Required but inheritable 

//Process all prerequisites before  processing text

// allocate stack based on number of total pages as referenced from parent, Root Parent should be at the bottom of the stack.
//The top of the stack shall have the first page while the bottom of the stack should store the very last page 
//(can be last +1 if stack is such size)
// You allocate lower recursed page trees first so they shall be higher in the stack based on the amount of pages within said stack
//After processing the last page, page tree reference on the stack should be replaced by its very last page
//Ultimately, for now, all non elements on the stack shall be replaced by all the pages that pertains to the root parent
//I can also put into consideration making a separate stack for pagetrees for future reference
//


//Media Box is what is used to display Pages

// Content Stream is what contains the content of pages

//Length argument of streams can be given through indirect object references 


/*
Page structures each need to be given a pointer to a media box size as these are inheritable from the page if not explictly given to the 
page.

Contents of a page are stored in the Contents object. These may be indireclty refered. Every page must cite parent and very 
Parent must cite a page. 

Page can inherita



<!DOCTYPE html><html lang=en><head><script src=//assets.adobedtm.com/526d5084b7f8f688ea81a3aba09755d76a81f8e8/satelliteLib-5b0c69cba9998404374755048324ea6deb6c9db5.js charset="UTF-8"></script><meta charset=utf-8><meta http-equiv=X-UA-Compatible content="IE=edge"><meta name=viewport content="width=device-width,initial-scale=1"><!--[if IE]><link rel="icon" href="/cedsci/ + favicon.ico"><![endif]--><link href=/cedsci/fonts/fa-regular-400.3a3398a6.woff2 rel=preload as=font crossorigin=""><link href=/cedsci/fonts/fa-solid-900.c500da19.woff2 rel=preload as=font crossorigin=""><link href=/cedsci/fonts/roboto-condensed-latin-400.3ada4464.woff2 rel=preload as=font crossorigin=""><link href=/cedsci/fonts/roboto-condensed-latin-700.6b222561.woff2 rel=preload as=font crossorigin=""><link href=/cedsci/fonts/roboto-latin-400.479970ff.woff2 rel=preload as=font crossorigin=""><link href=/cedsci/fonts/roboto-latin-500.020c97dc.woff2 rel=preload as=font crossorigin=""><link href=/cedsci/fonts/roboto-latin-700.2735a3a6.woff2 rel=preload as=font crossorigin=""><link href=/cedsci/css/Profile.57e55c9c.css rel=prefetch><link href=/cedsci/js/Profile.a61aa804.js charset="UTF-8" rel=prefetch><link href=/cedsci/css/Vendor.dd5aee75.css rel=preload as=style><link href=/cedsci/css/app.26038c41.css rel=preload as=style><link href=/cedsci/js/Vendor.21aa37a5.js charset="UTF-8" rel=modulepreload as=script><link href=/cedsci/js/app.fff62d1a.js charset="UTF-8" rel=modulepreload as=script><link href=/cedsci/css/Vendor.dd5aee75.css rel=stylesheet><link href=/cedsci/css/app.26038c41.css rel=stylesheet><link rel=icon type=image/png sizes=32x32
 href=/cedsci/img/icons/favicon-32x32.png><link rel=icon type=image/png sizes=16x16 href=/cedsci/img/icons/favicon-16x16.png><link rel=manifest href=/cedsci/manifest.json><meta name=theme-color content=#4DBA87>
 <meta name=apple-mobile-web-app-capable content=no><meta name=apple-mobile-web-app-status-bar-style content=default><meta name=apple-mobile-web-app-title content=cedsci-ui>
 <link rel=apple-touch-icon href=/cedsci/img/icons/apple-touch-icon-152x152.png>
 <link rel=mask-icon href=/cedsci/img/icons/safari-pinned-tab.svg color=#4DBA87>
 <meta name=msapplication-TileImage content=/cedsci/img/icons/msapplication-icon-144x144.png><meta name=msapplication-TileColor content=#000000>
  <script>!function(a)
  {var e="https://s.go-mpulse.net/boomerang/",t="addEventListener";if("False"=="True")a.BOOMR_config=a.BOOMR_config||{},a.BOOMR_config.PageParams=a.BOOMR_config.PageParams||{},a.BOOMR_config.PageParams.pci=!0,e="https://s2.go-mpulse.net/boomerang/";if(window.BOOMR_API_key="N5F9F-5SXNV-TJA4F-B6CEM-65LXH",function(){function n(e){a.BOOMR_onload=e&&e.timeStamp||(new Date).getTime()}if(!a.BOOMR||!a.BOOMR.version&&!a.BOOMR.snippetExecuted){a.BOOMR=a.BOOMR||{},a.BOOMR.snippetExecuted=!0;var i,_,o,r=document.createElement("iframe");if(a[t])a[t]("load",n,!1);else if(a.attachEvent)a.attachEvent("onload",n);r.src="javascript:void(0)",r.title="",r.role="presentation",(r.frameElement||r).style.cssText="width:0;height:0;border:0;display:none;",o=document.getElementsByTagName("script")[0],o.parentNode.insertBefore(r,o);try{_=r.contentWindow.document}catch(O){i=document.domain,r.src="javascript:var d=document.open();d.domain='"+i+"';void(0);",_=r.contentWindow.document}_.open()._l=function(){var a=this.createElement("script");if(i)this.domain=i;a.id="boomr-if-as",a.src=e+"N5F9F-5SXNV-TJA4F-B6CEM-65LXH",BOOMR_lstart=(new Date).getTime(),this.body.appendChild(a)},_.write("<bo"+'dy onload="document._l();">'),_.close()}}(),"".length>0)if(a&&"performance"in a&&a.performance&&"function"==typeof 
  a.performance.setResourceTimingBufferSize)a.performance.setResourceTimingBufferSize();!function(){if(BOOMR=a.BOOMR||{},BOOMR.plugins=BOOMR.plugins||{},!BOOMR.plugins.AK){var e=""=="true"?1:0,t="",n="eyaqbsecaeraaiabavmqagpytbp6w3mf-f-e2a4b6a7b-clienttons-s.akamaihd.net",i={"ak.v":"29","ak.cp":"852886","ak.ai":parseInt("545371",10),"ak.ol":"0","ak.cr":22,"ak.ipv":6,"ak.proto":"h2","ak.rid":"4d57d7a8","ak.r":28507,"ak.a2":e,"ak.m":"dscna","ak.n":"essl","ak.bpcip":"2601:c8:8201:2200::","ak.cport":42694,"ak.gh":"23.45.234.52","ak.quicv":"","ak.tlsv":"tls1.2","ak.0rtt":"","ak.csrc":"-","ak.acc":"","ak.t":"1609264517","ak.ak":"hOBiQwZUYzCg5VSAfCLimQ==aNbt9X1VuURY49xPkhjgE7gHp6L5eNEDj9pKQHtOcAFvrACW8r/RLCuDOgyxiJBDDND7jZODwGkaAvs9pnfbL/kC72PmOdesdKNTchi8O/fD4pq882cqHO4ZnQNuEMxIyp83G81pSH0e7R5rqNmW41Q/PSDJDDVbVoLJ83u0MOyeo0nXbBDLkT+QBtMtkAzywovaU/uWLNP5tPbpjD5oZFWJuao49ob4kIjGU5p+8O8wfhFchTe05fRSbgi9txxYXMol5S6PeRH0UKuNMFDMoYprPTiW9q1+KKCbYEuxjH0iSx9MgTVLb8pnlBXJPYpeCFYeQaBdT9puEsnCvCas3EusGllnblIvI9JqhwMJ9APgekFS3v/8rz5asfocpM85k9g0p18ov3v0GXUva0luKOoIfwEVh8bI9Y/1U1MZYKk=","ak.pv":"20","ak.dpoabenc":""};
  if(""!==t)i["ak.ruds"]=t;var _={i:!1,av:function(e){var t="http.initiator";if(e&&(!e[t]||"spa_hard"===e[t]))i["ak.feo"]=void 0!==a.aFeoApplied?1:0,BOOMR.addVar(i)},rv:function(){var a=["ak.bpcip","ak.cport","ak.cr","ak.csrc","ak.gh","ak.ipv","ak.m","ak.n","ak.ol","ak.proto","ak.quicv","ak.tlsv","ak.0rtt","ak.r","ak.acc","ak.t"];BOOMR.removeVar(a)}};BOOMR.plugins.AK={akVars:i,akDNSPreFetchDomain:n,init:function(){if(!_.i){var a=BOOMR.subscribe;a("before_beacon",_.av,null,null),a("onbeacon",_.rv,null,null),_.i=!0}return this},is_complete:function(){return!0}}}}()}(window);
  </script>
  </head>
  <body><noscript><strong>We're sorry but this website doesn't work properly without JavaScript enabled. Please enable it to continue.</strong></noscript><div id=app></div><script>_satellite.pageBottom();</script>
  <script type=module src=/cedsci/js/Vendor.21aa37a5.js charset="UTF-8"></script><script type=module src=/cedsci/js/app.fff62d1a.js charset="UTF-8"></script>
  <script>!function(){var e=document,t=e.createElement("script");if(!("noModule"in t)&&"onbeforeload"in t){var n=!1;e.addEventListener("beforeload",function(e){if(e.target===t)n=!0;
  else if(!e.target.hasAttribute("nomodule")||!n)return;e.preventDefault()},!0),t.type="module",t.src=".",e.head.appendChild(t),t.remove()}}();</script><script src=/cedsci/js/Vendor-legacy.64c7acc3.js charset="UTF-8" nomodule></script><script 
  src=/cedsci/js/app-legacy.adb61f4e.js charset="UTF-8" nomodule></script></body></html>

*/