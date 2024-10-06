int sumseries(ival)
    int ival;
{
    int sum;
    int below = ival - 1;  
    int retval;
  
    if(ival <= 0) { return 0; }
    if(ival == 1) { return 1; }
    if(ival > 100) { return -1; }
    sum = sumseries(below);
    retval = sum + ival;
    return retval;
}