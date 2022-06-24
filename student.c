#include<stdio.h>
#include<conio.h>
void insert_record();
void display_record();
void search_record();
void update_record();
struct student
{
    int reg;
    char sec[10];
    char name[40];
    int marks;
};
    struct student s ;
void main()
{
    int ch;
    while(ch!=5){
        printf("\t \t WELCOME TO STUDENT DATABASE SYSTEM \n");
        printf("\t-----AVAILABLE FUNCTIONS-----\n");
        printf("\t\t1. Insert student record\n");
        printf("\t\t2. Display student record\n");
        printf("\t\t3. Search student record\n");
        printf("\t\t4. Update student record\n ");
        printf("\t\t5. Exit\n");
        printf("\t enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                  insert_record();
                  break;
            case 2:
                 display_record();
                 break;
            case 3:
                 search_record();
                 break;  
            case 4:
                  update_record();
                break;
            case 5:
                 break;
            default:
                 printf("\t\twrong choice entered!\n");
        }
         printf("\npress any key to continue\t");
         getch();

    }
}
void insert_record()
{
    FILE*fp;
    fp= fopen("stu.txt","ab+");
    if(fp==NULL){
        printf("cannot open file");
        return;
    }
    printf("\n\n\t-----PREVIOUSLY STORED DATA-----\t");
    display_record();
    printf("\n\n\t-----ENTER NEW STUDENT DATA-----\t");
    printf("\nenter student register number:");
    scanf("%d", &s.reg);
    fflush(stdin);
    printf("\nenter student name:");
    gets(s.name);
    printf("\nenter student section:");
    gets(s.sec);
    printf("\nenter total marks of the student:");
    scanf("%d",&s.marks);
    fwrite(&s,sizeof(s),1,fp);
    {
        printf("\t\t\n-----STUDENT RECORD ENTERED SUCCESSFULLY!!-----\n");
    }
    fclose(fp);
}
void display_record()
{
    FILE *fp;
    fp= fopen("stu.txt","rb");
    if(fp==NULL){
        printf("cannot open file");
        return;
    }
    printf("\t\t\n-----THE STUDENT DETAILS ARE AS FOLLOWS-----\t\t\n");
    printf("\n\t Register No. \t Name of Student \t Section \t Marks \n\t");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        printf("%-7d %-22s  %-14s %-9d \n",s.reg,s.name,s.sec,s.marks);
    }
    fclose(fp);
}
void search_record()
{
   int ro,flag=0;
  FILE*fp;
    fp= fopen("stu.txt","ab+");
    if(fp==NULL){
        printf("cannot open file");
        return;  
    }
    printf("Enter the student register number which you want to search:");
    scanf("%d",&ro);
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.reg==ro)
        {
            flag=1;
            printf("\t\nSEARCH IS SUCCESSFULL AND STUDENT RECORD IS AS FOLLOWING\n\n");
            printf("\n Register No. \t Name of Student \t Section \t Marks \t\n\n");
            printf("%d \t %s \t %s \t %d\n ",s.reg,s.name,s.sec,s.marks);   
        }
    }
    if(flag==0)
    {
        printf("\nNo such student record found!!\t\n");
    }
    fclose(fp);
}

void update_record()
{
    int ro,flag=0;
    FILE *fp;
    fp= fopen("stu.txt","ab+");
    if(fp==NULL){
        printf("cannot open file");
        return;
    }
    printf("\t\nEnter the register number of the student whose record you want to update:\n");
    scanf("%d",&ro);
    printf("\t\t\n-----PREVIOUSLY STORED RECORD OF GIVEN REGISTER NUMBER-----\n\t");
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.reg==ro)
        {
            flag=1;
            printf("\n Register No. \t Name of Student \t Section \t Marks \n");
            printf("%d \t %s \t %s \t %d\n",s.reg,s.name,s.sec,s.marks);
            printf("\t\t\n-----NOW ENTER THE NEW RECORD-----\t\t\n");
            printf("\nUpdated student register number:\t");
            scanf("%d",&s.reg);
            fflush(stdin);
            printf("\nUpdated student name:\t");
            gets(s.name);
            printf("\nUpdated student section:\t");
            gets(s.sec);
            printf("\nUpdated student marks:\t");
            scanf("%d",&s.marks);
            fseek(fp,-(long)sizeof(s),1);
            fwrite(&s,sizeof(s),1,fp);
            printf("\t\t\n-----RECORD UPDATED SUCESSFULLY CHECK THE DISPLAY-----\n");
        }
    }
    if (flag==0)
    {
        printf("Something went wrong!");
    }
    fclose(fp);
}


 