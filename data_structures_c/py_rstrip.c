void py_rstrip(inp)
    char inp[];
{
    int len = strlen(inp);
    int i = 0;
    int loc_non_space = 0;
    while(1){
      if(inp[i] == '\0'){
        break;
      }
      if(inp[i] != ' '){
        loc_non_space = i;
      }
      i++;
    }
      int j = 0;
    inp[loc_non_space + 1] = '\0';
}