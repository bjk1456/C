static int num = 0;
int bump()
{

  return num++;
  // Do something :)
}
void start(int restart)
{
  num = restart;
}