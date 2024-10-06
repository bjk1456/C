int lower(c) /* convert c to lower case; ASCII only */
{
  int ans;
  ans = (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
  return ans;
}