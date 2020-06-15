#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//掲示板の構造体
typedef struct boardContent{
		char newsnum[5];
		char newstitle[30];
		char newsday[15];
		char repotername[20];
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


Content upload(int num){
	Content pos={0,};
	char newsnum;
	int i;

	fflush(stdin);
	
	//게시번호
	newsnum=num;
	itoa(newsnum,pos.newsnum,10);
	pos.newsnum[sizeof(newsnum)]='\n';

	//타이틀입력
	puts("Title : ");
	fgets(pos.newstitle,sizeof(pos.newstitle),stdin);

	//작성자
	puts("Name : ");
	fgets(pos.repotername,sizeof(pos.repotername),stdin);

	//내용
	puts("Contents : ");
	fgets(pos.contents,sizeof(pos.newstitle),stdin);

	//날짜 초기화.입력
	for(i=0;i<sizeof(pos.newsday);i++){
		pos.newsday[i]=0;
	}
	strcpy(pos.newsday,getdate());

	return pos;
}

void resetstr(char* str){
	int len=strlen(str);
	int i;
	for(i=0; i>len; i++){
		str[i]=0;
	}
	return;
}

int reading(FILE* fstream, Content* board){
	Content* p=board;
	int num=0;

	printf("모든 게시판 내용을 출력합니다\n\n");
	
	while(fgets(p->newsnum,sizeof(p->newsnum),fstream)!=NULL){
		fgets(p->newstitle,sizeof(p->newstitle),fstream);
		fgets(p->contents,sizeof(p->contents),fstream);
		fgets(p->repotername,sizeof(p->repotername),fstream);
		fgets(p->newsday,sizeof(p->newsday),fstream);
		num++;
		p++;
	}

	return num;
}

void menu(Content* contents, int num){
	int i;
	int space;
	char select;
	Content *p=contents;
	char str[400]={0,};
	printf("   Number		Tiltle			Writer	Up.Date\n");
	printf("------------------------------------------------------------------\n");
	for(i=0;i<num;i++){
		strcpy(str,p->newsnum);
		str[strlen(str)-1]=0;
		printf("     %-3s   ", str);
		resetstr(str);
		strcpy(str,p->newstitle);
		str[strlen(str)-1]=0;
		printf("%-3s", str);
		resetstr(str);
		strcpy(str,p->repotername);
		str[strlen(str)-1]=0;
		for(space=0; space<25-(strlen(p->newstitle));space++){
			printf(" ");
		}
		printf("%20s", str);
		resetstr(str);
		strcpy(str,p->newsday);
		str[strlen(str)-1]=0;
		printf("%10s\n", str);
		p++;
	}
	printf("------------------------------------------------------------------\n");

}

void writing(Content* board, int* textnum){
	FILE* fstream= fopen("board.txt","a");
	int newsnum=*textnum;
	int i;
	Content* contents=board;

	for(i=0;i<newsnum;i++){
		contents++;
	}
	*contents=upload(i);
	
	fputs(contents->newsnum,fstream);
	fputs(contents->newstitle,fstream);
	fputs(contents->contents,fstream);
	fputs(contents->repotername,fstream);
	fputs(contents->newsday,fstream);


	fclose(fstream);
	return;
}


int main(){

	FILE* fstream;
	int newsnum;
	int select=0;
	Content contents[15]={0,};

	//초기화


	
	

	while(select!=11){
		fstream = fopen("board.txt","rt+");
		if(fstream!=NULL)
			printf("파일 오픈 성공\n");
		else{
			printf("open Failed\n");
			return;
		}

		newsnum=reading(fstream, &contents[0]);
		menu(&contents[0], newsnum);
		printf("pleas select Action\n 0-9:reading n'th text, 10:writing, 11:exit\n");

		scanf("%d", &select);

		if(0<=select && select<10){
			printf("%s", contents[select].contents);
		}
		else if(select==10){
			writing(&contents[0], &newsnum);
		}
		else
			;
		fclose(fstream);
	}
	return 0;
}