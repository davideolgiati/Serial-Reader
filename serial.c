#include stdio.h
#include stdlib.h
#include termios.h
#include fcntl.h
#include stdbool.h
#include unistd.h
#include serial.h
 
int main(int argc, char argv[])
{
char input, reply;
bool question = 1;
int com,i=0,ch;			
struct termios tattr;		
const char options = ho;
 
 
  system(clear);
  ch = (getopt(argc, argv, options));
  switch (ch)
  {
   case 'h'
     help();
     return 0;
     break;
   case 'o'
     printf(ntttt033[1;31mONE-SHOT MODE033[0mnn);
     com=init(com);
     tattr=silent(tattr, com);
     sread(com, input, i);
     return 0;
     break;
  }
  com=init(com);
  tattr=full(tattr, com);
  do
  {
   i=sread(com, input, i);
   printf(Do you want to continue[YesNo]);
   scanf(%c,&reply);
   if (reply!=n && reply!=y && reply!=Y && reply!=s && reply!=S)
   {
    printf(nBey Beyn);
    question = 0;
   }
  }while(question)
  return 0;				
}
