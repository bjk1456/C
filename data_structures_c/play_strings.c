void process(line)
    char line[];
{
    int num_chars;
    int i = 0;
    int k;
    int nums;
    char tenth[1000];
    char no_space[1000];
    for(k = 0; k <= 1000; k++){
      no_space[k] = '\0';
       tenth[k] = '\0';
    }
      
    char type[1000];
    strcpy(type,"String: \0");
    printf("\nString: %s\n",line);
    while(1){
      if(line[i] == '\0'){
        break;
      }
      if(line[i] == ' '){
        char hyp = '-';
        char temp[2] = {hyp, '\0'};
        strcat(no_space, temp);
      } else{
        no_space[i] = line[i];
        }
        
      i++;
      if(i == 10){
        strcat(tenth, "The ninth character is: ");
        char ch = line[9];
        char temp[2] = {ch, '\0'}; 
    // Create a temporary string to hold the character
    
        strcat(tenth, temp);
      }
    }
      printf("%s%d\n", "Count=", i);
      if(tenth[0]) printf("%s\n", tenth);
      printf("%s\n", strcat(type,no_space));
}

/*
Expected output from your program:
String: Hi there and welcome to LBS290
Count=30
The ninth character is: a
String: Hi-there-and-welcome-to-LBS290

String: I love C
Count=8
String: I-love-C
*/