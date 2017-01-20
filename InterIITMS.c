#include "define.h"
#include <sgtty.h>
#include <string.h>
void echo_off();
void echo_on();
int authenticate(int g,char *A,char* B);
void resetpass(char *A,int g);
void playerinfo(char *A);
void organiser(char *A);
void player(char *A);
void team_manager(char *A);
int schedule(char *c);
int scoreboard(char *c);
FILE *fpa,*fpi,*fpo,*fpm,*fps,*fpn;
void main()
{
  int i,g;
  char user[MAX_USER],password[MAX_PASS];
  printf(" Inter IIT Management System 2016\n\n");
  printf(" IIT Kanpur\n\n");
  while(1){
  printf("Important Informantion - \n");
  printf("I - Intstiute ID \n \n");
  printf("II - username - <playerid>\n Default Password is - <username>123\n\n");
  do{
  printf("Login as \n Player - 1\n Organiser - 2\n Team Manager - 3\n Exit System - 4\n");
  scanf("%d",&g);
  getchar();
  }
  while((g<1)||(g>4));
  if(g==4) return;
  do{
  printf("\nEnter User Name - ");
  scanf("%s",user);
  printf("\nEnter your Password - ")
  echo_off();
  scanf("%s",password);
  echo_on();
  i = authenticate(g,user,password);
  }
  while(i==0);
  switch(g)
  {
    case 1 : organiser(user);
             break;
    case 2 : player(user);
             break;
    case 3 : team_manager(user);
  }
  }
}
void echo_off()
{
  struct sgttyb state;
  (void)ioctl(0, (int)TIOCGETP, (char *)&state);
  state.sg_flags &= ~ECHO;
  (void)ioctl(0, (int)TIOCSETP, (char *)&state);
}
void echo_on()
{
  struct sgttyb state;
  (void)ioctl(0, (int)TIOCGETP, (char *)&state);
  state.sg_flags |= ECHO;
  (void)ioctl(0, (int)TIOCSETP, (char *)&state);
}
int authenticate(int g,char *A,char* B)
{
  int i,x = strlen(B);
  char buff[MAX_PASS],*a,*b;
  switch(g)
  {
    case 1:{
             int y = 100*(int)A[3]+10*(int)A[4]+(int)A[5];
             fpa = fopen(AUTHENTICATE,"r");
             fseek(fpa,21*y+6,SEEK_SET);
             fscanf(fpa,"%[^\n]%14s",buff);//Important !! READING whitespace
             fclose(fpa);
             a = strrev(buff);
             b = strrev(B);
             i = strncmp(a,b,x);
             return (!i)?1:0;
           } break;
    case 2:{

           }
    case 3:{
             i = (int)A[0];
             fpm = fopen(TEAM_M,"r");
             fseek(fpm,(i-1)*39,SEEK_SET);
             fscanf(fpm,"%s",buff);
             fclose(fpm);
             i = strncmp(buff,B);
             return (!i)?1:0;
           }

  }
}
void resetpass(char *A,int g)
{
  char *password[MAX_PASS],buf[MAX_PASS];
  int i;
  do{
  printf("\nEnter your Password - ")
  echo_off();
  scanf("%s",password);
  echo_on();
  i = authenticate(g,A,password);
  } while(i==0);
  do{
  printf("\nEnter Your new password - ");
  scanf("%s",buf);
  printf("\nEnter again - ");
  scanf("%s",password);
  } while(strcmp(buf,password));
  switch(g)
  {
    case 1:
     {
      int y = 100*(int)A[3]+10*(int)A[4]+(int)A[5];
      fpa = fopen(AUTHENTICATE,"r+");
      fseek(fpa,20*y+6,SEEK_SET);
      fprintf(fpa,"%14s",password);
      fclose(fpa);
     }
    break;
    case 2:
        {

        }
    break;
    case 3:
  }
  printf("\nPassword Changed Succesully");
}
void playerinfo(char *A)
{
  char name[NAME];
  int study,sport;
  int y = 100*(int)A[3]+10*(int)A[4]+(int)A[5];
  fpi = fopen(PLAYER,"r");
  fseek(fpi,31*y,SEEK_SET);
  fscanf(fpi,"%[^\n]%s",name);
  study = getw(fpi);
  fclose(fpi);
  printf("\nID - %s",A);
  printf("\nNAME - %s\n",name);
  printf("INSTITUTE - IIT %s\n",iit[(int)A[0]]);
  char gend = ((int)A[2] == 1)?"Male" : "Female";
  printf("Gender - %s\n",gend);
  printf("CLASS - %c year in Engineering\n",study);
  sport = A[1];
  printf("Sports -   ");
  (sport%2)?printf("HOCKEY  ");:printf("CRICKET  ");
  if(sports/2 == 1) printf("CAPTAIN");
  printf("\n");
  printf("Age - %c Years\n\n",study+17);
}







