#include "define.h"
#include <string.h>
void main()
{
  int n,i,x,study;
  char name[NAME+1];
  char id[4],pass[MAX_PASS];
  n = IITS*2*28;
  FILE *fpa,*fpi;
  fpa = fopen(AUTHENTICATE,"w");
  fpi = fopen(PLAYER,"w");
  for(i=0;i<n;i++)
  {
    scanf("%[^\n]%*c",name);
    getchar();
    scanf("%d",study);
    getchar();
    id[0] = i%3+1;
    id[1] = 1;
    id[2] = (i<(n/2))?1:2;
    id[3] = (i/100);
    id[4] = (i/10)-10*(id[3]);
    id[5] = i%10;
    switch(i%21)
    {
      case 3:
      case 4:
      case 5:
      case 9:
      case 10:
      case 11:
      case 15:
      case 16:
      case 17: id[1] = 2;
        break;
    }
    id[1] = id[1] +((i<6)||(i>83 && i<90))?2:;
    strncpy(pass,id,6);
    pass[7] = '1';
    pass[8] = '2';
    pass[9] = '3';
    pass[10] = '\0';
    fprintf(fpa,"%s%14s\n",id,pass);
    fprintf(fpi,"%30s\n%d",name,study);
  }
}
