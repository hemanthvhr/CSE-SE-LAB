#include <stdio.h>
#include <stdlib.h>
void main()
{
  char file[30] = "team_manager.txt";
  int i,j;
  char name1[11],name2[11],id[15];
  FILE *fp = fopen(file,"w");
  for(i=0;i<3;i++)
  {
    id[0] = i+1;
    id[1] = '1';id[2]='2';id[3]='3';
    id[4]='\0';
    fprintf(fp,"%14s ",id);
    scanf("%s %s",name1,name2);
    getchar();
    fprintf(fp,"%10s %10s ",name1,name2);
    scanf("%d",&j);getchar();
    fprintf(fp,"%c",j);
    scanf("%d",&j);getchar();
    fprintf(fp,"%c",j);

  }
}
