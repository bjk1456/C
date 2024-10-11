void py_lstrip(inp)
    char inp[];
{
    int i;
    int last_loc;
    while(1){
    if ( inp[last_loc] != ' ' ) {
      break;
    }
    last_loc++;
    }

  
  int j = last_loc;
  int null_loc;
  int k;
  while(1){
    if(inp[j] == '\0') break;
    inp[k] = inp[j];
    j++;
    k++;
  }
  while(1){
    if(inp[null_loc] == '\0'){
      break;
    }
    null_loc++;
  }
  inp[null_loc - last_loc] = '\0';
      
  

}