void expand(s, t)
char s[], t[];
{
  
  int i, j;
  
  for(i=0, j=0; s[i]; i++) {
    switch(s[i]){
      case ' ':
        t[j++] = ' ';
       break;
      case '\n':
        t[j++] = '\\';
        t[j++] = 'n';
       break;
       case '\t':
        t[j++] = '\\';
        t[j++] = 't';
       break;
      default:
     t[j++] = s[i];
       break;
      }
  }
  t[j] = '\0';
}