#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>
#include "serial.h"
 
int main(int argc, char argv[])
{
char input, reply;
bool question = 1;
int com,rtn=0,ch;			
struct termios tattr;		
const char options = ho;
 
 
  system("clear");
  ch = (getopt(argc, argv, options));
  switch (ch)
  {
   case 'h'
     help();
     return 0;
     break;
   case 'o'
     printf("\n\t\t\t\t\033[1;31mONE-SHOT MODE\033[0mnn");
     com=init(com);
     tattr=silent(tattr, com);
     rtn=sread(com, input, rtn);
     return 0;
     break;
  }
  com=init(com);
  tattr=full(tattr, com);
  do
  {
   rtn=sread(com, input, rtn);
   printf("Do you want to continue\t[Y]es or [N]o");
   scanf("%c",&reply);
   if (reply!="\n" && reply!="y" && reply!="Y" && reply!="s" && reply!="S")
   {
    printf("\nBey Bey\n");
    question = 0;
   }
  }while(question)
  return 0;				
}
