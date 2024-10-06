void itob(n, s)
int n;
char s[];
{
    void reverse();
    int i = 0;
    int quot = 0;
    int rem = 0;
  	char t[11];
    int new = 0;
    int j = 0;
    
    while(n > 0){
      rem = n % 2;
      new = n / 2;
      n = new;
      s[i] = rem + '0';
      i++;
    }
   if(s[i] == '0'){
     s[i] = '\0';
   }
  else{
    s[i++] = '\0';
  }
   reverse(s);
  /**
    strcpy(s,"101010");
    */
}
void itoh(n, s)
int n;
char s[];
{
    void reverse();
    char base_16[1000];
    int i = 0;
    int quot = 0;
    int rem = 0;
    int new = 0;
    int j = 0;
    for(;j <= 1000; j++){
      s[j] = '\0';
    }
    while(n > 0){
      rem = n % 16;
      new = n / 16;
      n = new;
      if(rem == 10){
         s[i] = 'a';
      } 
      else if(rem == 11){
         s[i] = 'b';
      } 
      else if(rem == 14){
         s[i] = 'e';
      } 
      else if(rem == 15){
         s[i] = 'f';
      }
      else {
      s[i] = rem + '0';
      }
      i++;
    }
  reverse(s);
  /**
    strcpy(s,"2a");
    */
}