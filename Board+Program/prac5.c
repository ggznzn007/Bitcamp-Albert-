#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Class
typedef struct boardContent{
		char newsnum[5];
		char newstitle[30];
		char newsday[15];
		char repotername[10];
		char contents[400];
}Content;

//Date
char* getdate(){
	char timecont[15]="";
	char charcont[15]="";
	int date;
	int i;

	time_t now;
	struct tm *d;
	now=time(NULL);
	d=localtime(&now);

	date=d->tm_year-100;
	itoa(date, charcont,10);
	strcpy(timecont,charcont);
	for(i=0;i<sizeof(charcont);i++){
		charcont[i]=0;
	}
	strcat(timecont,".");

	itoa(d->tm_mon+1, charcont, 10);
	strcat(timecont,charcont);
	for(i=0;i<sizeof(charcont);i++){
		charcont[i]=0;
	}
	strcat(timecont,".");

	itoa(d->tm_mday, charcont, 10);
	strcat(timecont,charcont);

	i=strlen(timecont);
	timecont[i]='\n';
	
	return timecont;
}

void resetstr(char* str){
	int len=strlen(str);
	int i;
	for(i=0; i>len; i++){
		str[i]=0;
	}
	return;
}

//Content Upload
Content* upload(int* num){
	FILE * src=fopen("src.txt","a+");
	Content pos={0,};
	char str[400]={0,};
	char title[50]={0,};
	char textnum[5]={0,};
	char text[401]={0,};
	char reporter[14]={0,};
	char date[15]={0,};
	char newsnum;

	fflush(stdin);
	
	//Contetn number
	newsnum=(*num)+1;;
	(*num)=newsnum;
	itoa(newsnum,textnum,10);
	textnum[strlen(textnum)]=31;
	fputs(textnum,src);

	printf("Title:");
	fgets(title,sizeof(title),stdin);
	title[strlen(title)-1]=0;
	title[strlen(title)]=31;
	fputs(title,src);

	printf("Text Content:if you want input LF(Line Feed), please Enter the 'Shift+]'\n");
	fgets(text,sizeof(text),stdin);

	while((text[strlen(text)-2])!=29){
		resetstr(str);
		fgets(str,sizeof(str),stdin);
		strcat(text,str);
		if((strlen(text))==401){
			break;
		}
	}
	text[strlen(text)-1]=0;
	text[strlen(text)]=31;
	fputs(text,src);

	printf("Name:");
	fgets(reporter,sizeof(reporter),stdin);
	reporter[strlen(reporter)-1]=0;
	reporter[strlen(reporter)]=31;
	fputs(reporter,src);

	//Get date
	strcpy(date,getdate());
	date[strlen(date)-1]=31;
	date[strlen(date)]=30;
	fputs(date,src);

	strcpy(pos.newsnum,textnum);
	strcpy(pos.newstitle,title);
	strcpy(pos.contents,text);
	strcpy(pos.repotername,reporter);
	strcpy(pos.newsday,date);

	fclose(src);
	return &pos;
}

//File reading & Menu
int reading(Content* board){
	Content*p=board;
	FILE * src=fopen("src.txt","a+");

	int ch;
	int i=0;
	int space;
	int newsnum=0;
	char str[401]={0,};

	//File open
	if(src==NULL){
		puts("File open!");
		return;
	}

	//Get menu
	printf("Loading Contents...\n");
	printf("   Number		Tiltle			Writer	Up.Date\n");
	printf("------------------------------------------------------------------\n");
	while((ch=fgetc(src))!=EOF){
		while(ch!=30){

			//Get Content's number
			while(ch!=31){
				p->newsnum[i]=ch;
				i++;
				ch=fgetc(src);
			}
			p->newsnum[i]=0;
			i=0;
			ch=fgetc(src);

			//Get Title
			while(ch!=31){
				p->newstitle[i]=ch;
				i++;
				ch=fgetc(src);
			}
			p->newstitle[i]=0;
			i=0;
			ch=fgetc(src);
			
			//Get Text Content
			while(ch!=31){
				p->contents[i]=ch;
				i++;
				ch=fgetc(src);
			}
			p->contents[i]=0;
			i=0;
			ch=fgetc(src);

			//Get Name
			while(ch!=31){
				p->repotername[i]=ch;
				i++;
				ch=fgetc(src);
			}
			p->repotername[i]=0;
			i=0;
			ch=fgetc(src);

			//Get Date
			while(ch!=31){
				p->newsday[i]=ch;
				i++;
				ch=fgetc(src);
			}
			p->newsday[i]=0;
			i=0;
			ch=fgetc(src);

			//Menu printing
			printf("     %-3s   ", p->newsnum);
			printf("%-3s", p->newstitle);
			for(space=0; space<25-(strlen(p->newstitle));space++){
				printf(" ");
			}
			printf("%18s", p->repotername);
			printf("%10s\n", p->newsday);
		}
		newsnum++;
		p++;
	}
	printf("------------------------------------------------------------------\n");

	if(feof(src)!=0)
		puts("Loading Complete!");
	else
		puts("File loading Failed!");
	
	fclose(src);
	return newsnum;	
}


int main(void)
{
	int newsnum=0;
	int select=0;
	Content contents[15]={0,};
	Content* point;

	newsnum=(reading(&contents[0])-1);

	while(select!=12){
		
		//menu(&contents[0], newsnum);
		printf("\npleas select Action\n 0-9:reading n'th text\n 10:get menu\n 11:writing\n 12:exit\n");

		scanf("%d", &select);

		if(0<=select && select<10){
			printf("\n\n%s\n", contents[select].contents);
			printf("------------------------------------------------------------------\n");
		}
		else if(select==10){
			reading(&contents[0]);
		}
		else if(select==11){
			//writing(&contents[0], &newsnum);
			point=upload(&newsnum);
			contents[newsnum]= *point;
		}
		else
			printf("error\n");
	}


	//fclose(des);
	return 0;
}