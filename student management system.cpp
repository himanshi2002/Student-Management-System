# include<stdio.h>
#include<stdlib.h>
# include<conio.h>
void insert_record();
void display_record();
void search_record();
void del_record();
void sort_record();

struct Student // data types for the student
{
	int roll;
	char sec[10];
	char name[40];
	int marks;
	float grade;
};
struct Student s;
void main()
{
	int ch; // take the choice
	while (ch!=7)
	{
		printf("\t******************************************\n");
		printf("\t\t Welcome To Student Management System\n");
		printf("\t******************************************\n\n\n");
		printf("\t*****Please Choose One****\n\n\n");
		printf("\t\t 1. Insert Student Records\n");
		printf("\t\t 2. Display Student Records\n");
		printf("\t\t 3. Search Student Records\n");
		printf("\t\t 4. Delete Student Records\n");
		printf("\t\t 5. Update Student Records\n");
		printf("\t\t 6. Sort Student Records\n");
		printf("\t\t 7. Exit\n\n");
		printf("\t\tEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				clrscr();
				insert_record();
				break;
			case 2:
				clrscr();
				display_record();
				break;
			case 3:
				clrscr();
				search_record();
				break;
			case 4:
				clrscr();
				del_record();
				break;
			case 5:
				clrscr();
				update_record();
				break;
			case 6:
				clrscr();
				sort_record();
				break;
			case 7:
				exit(1);
			default:
				printf("\n\t\t Wrong Choice Entered");
		}
		printf("\n\t\tPress Any Key To Continue");
		getch();
		
	}
}

void insert_record()
{// when we are working with file we need a buffer to read or write in a file so to point that buffer we need pointer. 
	FILE *fp;
	fp=fopen("D:\c programs\student.txt","ab+");// ab+ will open the file in append mode or will create a file if the file does not exist.
	if(fp=NULL)
	{
		printf("\n\t\t Cannot Open File");
		return;
	}
	printf("\t*****Previously Stored Data*****");
	display_record();
	printf("\n\n\t*****Enter New Student Data*****\n\n");
	printf("\n\t\t Enter Student Roll Number: ");
	scanf("%d",&s.roll);
	fflush(stdlin); //the input and outpu get stores in the buffer so to give another input we need to clear the buffer before.
	// this will flush the previous memory
	printf("\n\t\t Enter Student Name: ");
	gets(s.name);
	printf("\n\t\t Enter Student Section: ");
	gets(s.sec);
	printf("\n\t\t Enter Student Total Marks: ");
	scanf("%d",&s.marks);
	printf("\n\t\t Enter Student Grade: ");
	scanf("%f",&s.grade);
	fwrite(&s,sizeof(s),1,fp); // address of structure,size of the structure how many bytes it's taking,how many times we want to perform writing
	{
		printf("\n\n\t Student Record Added Successfully\n");
	}
	fclose(fp);
	printf("\n\t\t Updated Record!!\n");
	display_record();
	
}

void display_record()
{
	FILE fp;
	fp=fopen("D:\c programs\student.txt","rb");
	if(fp==NULL)
	{
		printf("\n\t\t ERROR: Cannot Open File");
		return;
	}
	printf("\n\n\t*****Students Details Are Follows*****");
	printf("\nRoll NO.\tName of Student\tSection\t\tMarks\t\tGrades\n\n");
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		printf("%d\t%s\t%s   \t\t%d\t\t%f\n",s.roll,s.name,s.sec,s.marks,s.grade);
	}
	fclose(fp);
}

void search_record()
{
	int ro,flag=0;
	FILE *fp;
	fp=fopen("D:\c programs\student.txt","rb");
	if(fp==NULL)
	{
		printf("\n\t\t Error: Cannot Open File!!");
		return;
	}
	printf("\n\n\t Enter Student Roll Number You Want To Search: ");
	scanf("%d",&ro);
	while(fread(&s,sizeof(s),1,fp)>0&&flag==0)
	{
		if(s.roll==ro)
		{
			flag=1
			printf("Student Record Are As Follows:\n");
			printf("\nRoll No.\t Student Name\t Section\t\t Marks\t\t Grade\n\n");
			printf("%d\t%s\t%s   \t\t%d\t\t%f\n",s.roll,s.name,s.sec,s.marks,s.grade);
		}
		if (flag==0)
		{
			printf("\n\n\t No Such Record Found!!!\n");
		}
		fclose(fp);
	}
}

void del_record()
{
	char name[40];
	unsigned flag=0 // that can never be negative
	FILE *fp,*ft;
	fp=fopen("D:\c programs\student.txt","rb");
	if (fp==NULL)
	{
		printf("\n\t\tError: Cannot Find File!!");
		return;
	}
	printf("\n\t*****Previous Stored Data*****");
	dispaly_record();
	printf("\n\n Enter Student Name Which You Want To Delete:");
	scanf("%s",&name);
	ft=fopen("D:\c programs\student1.txt","ab+");
	while(fread(&s,sizeof(s),1,fp)==1)
	{
		if (strcmp(name,s.name)!=0)
		{
			printf("\n\t\t Record Deleted Successfully!!\n");
			fwrite(&s,sizeof(s),1,ft);
		}
		else
		{
			flag=1;
		}
		if (flag==0)
		{
			printf("\n\n\t\t No Record Found!!");
		}
		fclose(fp);
		fclose(ft);
		remove("D:\c programs\student.txt");
		rename("D:\c programs\student1.txt","D:\c programs\student.txt");
		printf("\n\t\t Updated Successfully!!\n");
		display_record();
	 }
}
void update_record()
{
	int ro,flag=0;
	FILE *fp;
	fp=fopen("D:\c programs\student.txt");
	if (fp==NULL)
	{
		printf("\n\t\t Error:Cannot Find File!!");
		return;
	}
	printf("\n\n\t Enter Roll Number Of Student Record You Want To Update:");
	scanf("%d",&ro);
	printf("\n\t\t *****Previously Stored Record Of Given Roll Number*****");
	while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
	{
		if(s.roll==ro)
		{
			flag=1;
			printf("\nRoll No.\t Student Name\t Section\t\t Marks\t\t Grade\n\n");
			printf("%d\t%s\t%s   \t\t%d\t\t%f\n",s.roll,s.name,s.sec,s.marks,s.grade);
			printf("\n\t\t***Now Enter The New Record***");
			printf("\n\t\tUpdated Student Roll Number:");
			scanf("%d",&s.roll);
			fflush(stdin);
			printf("\n\t\tUpdated Student Name:");
			gets(s.name);
			printf("\n\t\tUpdated Student Section:");
			gets(s.sec);
			printf("\n\t\tUpdated Student Marks:");
			scanf("%d",&s.marks);
			printf("\n\t\tUpdated Student Grade:");
			scanf("%f",&s.grade);
			fseek(fp,-(long)sizeof(s),1);
			fwrite(&s,sizeof(s),1,fp);
			printf("\n\n\t\tRecord Updated Successfully\n");
		}
		if (flag==0)
		{
			printf("\n\t\tError:Something Went Wrong!!");
		}
		fclose(fp);
	}
}

void sort_record()
{
	struct Student temp;
	struct Student arr[50];
	int i,j,k=0;
	FILE *fp;
	fp=fopen("D:\c programs\student.txt","rb");
	if (fp==NULL)
	{
		printf("\n\t\tError: Cannot Open File!!!\n");
	}
	i=0;
	while(fread(&arr[i],sizeof(arr[i]),1,fp)==1)
	{
		i++;
		k++;
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<k-i-1;j++)
		{
			if(arr[j].roll>arr[j+1].roll)
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("\n\t\tAfter Sorting Student Details!!\n\n");
	for(i=0;i<k;i++)
	{
		printf("%d\t\t%s\t\t%s\t\t%d\t\t%f\n",arr[i].roll,arr[i].name,arr[i].sec,arr[i].marks,arr[i].grade);
		
	}
	fclose(fp);
}
