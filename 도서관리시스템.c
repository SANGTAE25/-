/*book 구조체 배열 : barr, book 구조체 : book          Author : 이상태
show Menu 메뉴, readBookInfo입력  showBookInfo 출력  searchBook 검색 */
#include <stdio.h>
#include <string.h>
typedef struct book
{	char name[20];
	char rea[20];
	char pub[20];
	char wri[20];
	int pri;
	int borr;
}Book;
int showMenu(int opt);
void readBookInfo(Book * barr, int i,char * regist,int * count);
void showBookInfo(Book * barr, int i,int * count);
void searchBookInfo(Book  * barr, int i,char * name2);
void rentalBookInfo(char * ren, char * renbook,int i, int * count, Book * barr);
void cancelBookInfo(char * cancel, Book * barr,char * ans,int i, int * count);
int main(void)
{	int opt;
	Book barr[50];
	int i;
	char regist[50];
	char search;
	char name2[50];
	char ren[50];
	char cancel[50];
	char ans[50];
	int count;
	char renbook[50];
		while(1)
	{
		opt=showMenu(opt);
			if(opt==1)
		{	
			readBookInfo(barr,i,regist,&count);
		}
		else if(opt==2)	
		{
			showBookInfo(barr,i,&count);
		}
		else if(opt==3)
		{
			searchBookInfo(barr,i,name2);
		}
		else if(opt==4)
		{
			rentalBookInfo(ren,renbook,i,&count,barr);
		}
		else if(opt==5)
		{
			cancelBookInfo(cancel,barr,ans,i,&count);
		}
		else
		{
			break;
		}
	}
	return 0;
}int showMenu(int opt)
{	printf("==========<MENU>==========\n");
	printf("1. 책등록\n2. 책 확인\n3. 책 검색\n4. 책 대여\n5. 책반납 \n6. 종료하겠습니다\n");
	printf("==========================\n\n");
	printf("번호를 선택하여 주세요");
	scanf("%d",&opt);
	printf("\n");
	return opt;
}void readBookInfo(Book * barr,int i,char * regist,int * count)
{	for(i=0; i<100; i++)
	{
		printf("책을 등록하시겠습니까?  (예/아니오)  ");
		scanf("%s",regist);
		printf("\n");
		if(!strcmp(regist,"예"))
		{
			printf("\n");
			printf("=====<책을 등록하여 주세요>=====\n");	
			printf("책이름: ");
			scanf("%s",barr[i].name);
			printf("출판일: ");
			scanf("%s",barr[i].rea);
			printf("출판사: ");
			scanf("%s",barr[i].pub);
			printf("글쓴이: ");
			scanf("%s",barr[i].wri);
			printf("가격: ");
			scanf("%d",&barr[i].pri);
			printf("================================\n\n");
		}
		else
		{
			* count = i;
			break;
		}
	}
}void showBookInfo(Book * barr, int i,int * count)
{	 printf("\n=====<등록한 책정보>=====\n");
	printf("%s",barr[0].name);
	for(i=0; i<*count; i++)
	{
		printf("책이름: %s\n",barr[i].name);
		printf("출판일: %s\n",barr[i].rea);
		printf("출판사: %s\n",barr[i].pub);
		printf("글쓴이: %s\n",barr[i].wri);
		printf("가격: %d원\n\n",barr[i].pri);
	}
	printf("==========================\n\n");
}void searchBookInfo(Book * barr, int i,char * name2)
{	printf("책 이름을 입력해 주세여  ");
	scanf("%s",name2);
	for(i=0; i<5; i++)
	{
		if(!strcmp(name2,barr[i].name))
			{
				printf("\n=====<검색한 책 정보>=====\n");
				printf("책이름: %s\n", barr[i].name);
				printf("출판일: %s\n", barr[i].rea);
				printf("출판사: %s\n", barr[i].pub);
 				printf("글쓴이: %s\n", barr[i].wri);
				printf("가격: %d원\n", barr[i].pri);
				printf("==========================\n");
				printf("\n");
				break;
			}
	}
}void rentalBookInfo(char * ren,char * renbook,int i,int * count,Book * barr)
{	printf("책 대여를 하시겠습니까?  (예/아니오)  ");
	scanf("%s",ren);
	printf("\n");
	if(!strcmp(ren,"예"))
	{
		printf("대여할 책을 선택해 주십시오");
		scanf("%s",renbook);
		printf("\n");
		for(i=0; i<*count; i++)
		{
			if(!strcmp(renbook,barr[i].name))
			{
				if(barr[i].borr==1)
				{
					printf("\n대여를 할 수 없습니다\n\n");
				}
				else
				{
					printf("대여가 완료되었습니다\n\n");
					printf("=====<%s 대여완료>=====\n\n", barr[i].name);
					printf("책이름: %s\n", barr[i].name);
					printf("출판일: %s\n", barr[i].rea);
					printf("출판사: %s\n", barr[i].pub);
					printf("글쓴이: %s\n", barr[i].wri);
					printf("가격: %d\n",barr[i].pri);
					printf("=======================\n");
					printf("\n");
					barr[i].borr=1;
				}
			}
				}
				}
			
			else
			{
				printf("대여를 취소하였습니다\n");
			}
}void cancelBookInfo(char * cancel,Book * barr,char * ans,int i, int * count)
{	printf("책 반납을 하시겠습니까? (예/아니오) ");
	scanf("%s",ans);
	if(!strcmp(ans,"예"))
	{
		for(i=0; i<*count ; i++)
		{
			printf("반납할 책을 적어주세요");
			scanf("%s",cancel);
			if(!strcmp(cancel,barr[i].name))
			{
				barr[i].borr = 0;
				printf("\n");
				printf("반납이 완료되었습니다.\n");
				printf("=====<%s 반납완료>=====\n\n", barr[i].name);
            printf("책이름: %s\n", barr[i].name);
            printf("출판일: %s\n", barr[i].rea);
            printf("출판사: %s\n", barr[i].pub);
            printf("글쓴이: %s\n", barr[i].wri);
            printf("가격: %d\n",barr[i].pri);
            printf("=======================\n");
            printf("\n");
				break;
			}
			else
			{
				printf("\n반납할 책을 다시 적어주세요\n\n");
				break;
			}
		}
	}		
	else
	{
		printf("반납을 취소하였습니다\n\n");
	}
}
