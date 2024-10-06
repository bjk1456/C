int htoi(char s[]) { /* convert s to integer */
    int i, n;

    n = 0;
    int len = 0;
    char buf[1000];
    int a;
    int pre = 0;
  int tally = 0;
    for(a = 0; a <= 1000; a++){
      if(s[a] == '\0'){
        break;
      }
      len += 1;
    }
   int c = 0;
   
   while(len >= 0){
     int exp = 1; 
      if((s[c] == 'f') || (s[c] == 'F')){
       pre = 15;
     }
     else if(s[c] == 'a'){
       pre = 10;
     }
      else if(s[c] == 'b'){
       pre = 11;
     }
      else if(s[c] == 'c'){
       pre = 12;
     }
     else if(s[c] == 'e'){
       pre = 14;
     }
     else if(s[c] == '1'){
       pre = 1;
     }
     else if(s[c] == '2'){
       pre = 2;
     }
    else if(s[c] == '3'){
       pre = 3;
     }
    else if(s[c] == '7'){
       pre = 7;
     }
     else{
       pre = atoi(s[c]);
     }
     
     int exp_i = len;
     while(exp_i > 1){
       exp = exp * 16;
       exp_i--;
       }
     if(len == 1){
       tally += pre;
     }
     else{
     tally += (pre * exp);
     }
     len--;
     c++;

       
   }
    
    return(tally);
}