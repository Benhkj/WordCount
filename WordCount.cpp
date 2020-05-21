#include <stdio.h> 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define IN 1
#define OUT 0
int size;
//get content in file
char *getFileContent(char *fname)
{
	FILE *fp;
	char *str;
	char txt[1000];
	int fileSize;
	if ((fp=fopen(fname,"r"))==NULL){
		printf("error to open %s !\n",fname);
		return NULL;
	}
 
	fseek(fp,0,SEEK_END); 
 
	fileSize = ftell(fp);
	str=(char *)malloc(fileSize);
	str[0]=0;
 
	rewind(fp);
	while((fgets(txt,1000,fp))!=NULL){
		strcat(str,txt);
	}
	size=fileSize;
	fclose(fp);
	return str;
}
//get char number and word number in file
void getCharCntAndWordCnt(char *p)
{
	int char_num,word_num,state;
    char_num=word_num=0;
    state=OUT;
	for(int i=0;i<size;i++){
        char_num++;
		char c=*p;
        if(c=='\n' || c=='\t' || c==' '){
                state=OUT;
        }else if(state==OUT){
            state=IN;
            word_num++;
        }
		p++;
        }
 
    printf("word_num=%d\nchar_num=%d\n",word_num,char_num);

}
int main(int argc, char *argv[])
{
	char *p;
	char *fname="E:\\test.txt";
	p=getFileContent(fname);
	if (p!=NULL) puts(p);
	getCharCntAndWordCnt(p);
	return 0;
}
