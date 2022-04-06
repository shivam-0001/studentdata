#include<stdio.h>
#include<conio.h>
void adddata();
void delete();
void display();
void search();
struct student 
{
	int rollno;
	char name[14];
	float percent;	
};
int main(void)
{
	FILE *fp;
	printf("1.To add data");
	printf("\n2.To remove data");
	printf("\n3.to display data");
	printf("\n4.search");
	struct student s[5];
	int ch,i,res;
	printf("enter the choice");
	scanf("%d",&ch);
			
	switch(ch)
	{
		case 1:
			adddata();
			break;
			case 2:
				delete();
			break;
			case 3:
			display();
			break;
			case 4:
			search();
			break;
			default:
			printf("wrong choice");		
	}
	return 0;
}
void adddata()
{
	FILE *fp;
	int i;
	struct student s[5];
	fp=fopen("student.txt","a");
			if(fp==NULL)
			{
				printf("not created");
			}
			else
			{
				printf("created");
			}
	printf("enter the rollno,name,percent of students");
			for(i=0;i<2;i++)
			{
				scanf("%d%s%f",&s[i].rollno,&s[i].name,&s[i].percent);
				fprintf(fp,"%d%s%f",s[i].rollno,s[i].name,s[i].percent);
			}
			fclose(fp);
}
void delete()
{
	FILE *fp1;
	fp1=fopen("student.txt","a");
	remove("student.txt");
	fclose(fp1);
}
void display()
{
	int i;
	struct student s[5];
	FILE *fp2;
	fp2=fopen("student.txt","r");
	for(i=0;i<2;i++)
	{		
	fscanf(fp2,"%d%s%f",&s[i].rollno,&s[i].name,&s[i].percent);
	printf("rollno,name and percent=%d%d%f",s[i].rollno,s[i].name,s[i].percent);
}
fclose(fp2);
}
void search()
{
	struct student s[5];
	int i,flag=0,rollno;
	FILE *fp3;
	fp3=fopen("student.txt","r");
	printf("enter the rollno");
	scanf("%d",rollno);
	for(i=0;i<2;i++)
	{
		while(fscanf(fp3,"%d%s%f",&s[i].rollno,&s[i].name,&s[i].percent)!=EOF)
		{
			if(rollno==s[i].rollno)
		{
			flag=0;
			break;
		}
}
}
	if(flag==1)
	{
		printf("not found");
	}
	else
	{
		printf("found");
	}

	fclose(fp3);
}