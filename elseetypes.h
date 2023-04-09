char SpeedParser (char *ifile)
{      while (*ifile ==  0 || *ifile ==  9  || *ifile == 12 ||*ifile ==  20 || *ifile ==  32  || *ifile ==  13 || *ifile == 15 || *ifile == 37)
        {
          ifile ++;
        } 
}

// There must be a better way to handle the new lines. TO-DO, create a buffer override of somesort. Possibly make call buffer 