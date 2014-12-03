struct termios full (struct termios tattr ,int com)
{
  printf("\tAcquisisco informazioni sulla Seriale ....");
  tcgetattr (com, &tattr);
  tattr.c_cflag &= ~CSIZE;
  printf("\t\033[1;32mAcquisite!\033[0m\n");
  printf("\tDisabilito i Flag di Lettura non necessari ....");
  tattr.c_iflag &= ~(INLCR|IGNCR|ICRNL|IXON);
  tattr.c_oflag &= ~OPOST;
  printf("\t\033[1;32mDisabilitati!\033[0m\n");
  printf("\tAbilito la lettura a 7bit ....");
  tattr.c_cflag = CS7 | CREAD | CLOCAL; 
  printf("\t\t\t\033[1;32mAbilitata!\033[0m\n");
  printf("\tPrevengo output errati ....");
  tattr.c_lflag &= ~(ICANON|ECHO);
  printf("\t\t\t\033[1;32mPrevenuti!\033[0m\n");
  printf("\tImposto un solo stop bit ....");
  tattr.c_cflag &= ~CSTOPB;
  printf("\t\t\t\033[1;32mImpostato!\033[0m\n");
  printf("\tSetup timeout seriale e caratteri ....");	
  tattr.c_cc[VMIN] = 1;			
  tattr.c_cc[VTIME] = 0;
  printf("\t\t\033[1;32mSetup avvenuto!\033[0m\n");
  printf("\tSetto la velocità di lettura! ....");		
  cfsetispeed (&tattr, B9600);		
  printf("\t\t\033[1;32mSetup avvenuto!\033[0m\n");
 
  printf("\n\tApplico i Cambiamenti ....");
  tcsetattr (com, TCSANOW, &tattr);	
  printf("\t\t\t\033[1;32mApplicati!\033[0m\n\n\n");
  return tattr;
}
 
struct termios silent (struct termios tattr ,int com)
{
 
  tcgetattr (com, &tattr);
  tattr.c_cflag &= ~CSIZE;
  tattr.c_iflag &= ~(INLCR|IGNCR|ICRNL|IXON);
  tattr.c_oflag &= ~OPOST;
  tattr.c_cflag = CS7 | CREAD | CLOCAL; 
  tattr.c_lflag &= ~(ICANON|ECHO);
  tattr.c_cflag &= ~CSTOPB;
  tattr.c_cc[VMIN] = 1;			
  tattr.c_cc[VTIME] = 0;
  cfsetispeed (&tattr, B9600);		
  tcsetattr (com, TCSANOW, &tattr);
  return tattr;
}
 
int init (int com)
{
    if ((com = open ("/dev/ttyS0",O_RDWR | O_SYNC))==-1)			
     {
       perror ("\t\t\033[1;31mNon posso aprire la seriale\033[0m"); 
       exit(1);				
     }
    return com;
}
 
int sread (int com, char input, int i)
{  
    i++;
    printf("\t%d°  -  ",i);
    do        
    {
      read(com,&input,1);        
      printf("%c",input);
    }while(input!='\n');
    return i;
}
 
void help ()
{
     printf("\n\t\t\t\t      \033[1;36mHELP\033[0m\n\n");
     printf("\n     Programm Developed by Davide Olgiati.\n");
     printf("     Serial Killer is an open sources programm using the termios.h library.\n");
}
