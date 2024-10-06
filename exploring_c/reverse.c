void reverse(t)
char t[];
{
  char reversed[1000];
  int f;
  int i;
  int b = 0;
  int c = 0;
  int s_length = 0;
  
 char to_reverse[1000];
  
for(i = 0; i <= 1000; i++){
  if(t[i] == '\0'){
    break;
  }
  to_reverse[i] = t[i];
  s_length++;
}
for(i = s_length-1; i >= 0; i--){
    reversed[b] = to_reverse[i];
    b++;
}
  for(i = 0; i <= 1000; i++){
    if(i < s_length){
      t[i] = reversed[i];
    }
    else {
    t[i]= '\0';
    }
  }
  
  
}