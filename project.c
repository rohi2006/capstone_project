#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
#include<unistd.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
 
// Variable to keep track of
int i=0;
// Structure to store the student
struct sinfo {
    char fname[50];
    char lname[50];
    int roll;
    float cgpa;
    int cid[10];
} st[55];
FILE * fp;
 char tfname[50];
 char tlname[50];
 int troll,tcid[10];
 float tcgpa;
// Function to add the student
void add_student()
{   
    char p[] = "Add the Student Details";
    for(int i=0;i<strlen(p);i++)
    {
        printf(GREEN"%c",p[i]);
        Sleep(30);
    }
    printf("\n");
    printf(CYAN"-------------------------\n");
    printf(YELLOW"Enter the first "
           "name of student:"RESET);
    scanf("%s", st[i].fname);
    printf(YELLOW"\nEnter the last name"
           " of student:"RESET);
    scanf("%s", st[i].lname);
    printf(YELLOW"\nEnter the Roll Number:"RESET);
    scanf("%d", &st[i].roll);
    printf(YELLOW"\nEnter the CGPA "
           "you obtained:"RESET);
    scanf("%f", &st[i].cgpa);
    printf(YELLOW"\nEnter the course ID of each course:"RESET);
    for (int j = 0; j < 5; j++) {
        scanf("%d", &st[i].cid[j]);
    }
    FILE * fp;
    fp=fopen("abc.txt","a+");
    fprintf(fp,"%s %s %d %f ",st[i].fname,st[i].lname,st[i].roll,st[i].cgpa);
    //BY using files we can store the data when we run code parmanently
    //though the code is ended the executed data will be available in abc.txt file
    for(int j=0; j<5; j++)
    {
        fprintf(fp,"%d ",st[i].cid[j]);
    }
    fprintf(fp,"\n");
    fclose(fp);
    i = i + 1;
    printf("\n");
}
 
// Function to find the student
// by the roll number
void find_rl()
{
    char p[] = "Enter the Roll Number of the Student:";
    FILE *fp=fopen("abc.txt","r");
    printf("\n");
    int x,u=0;
    printf(GREEN"\n--------------------------------------\n");
    for(int i=0;i<strlen(p);i++)
    {
        printf(YELLOW"%c"RESET,p[i]);
        Sleep(30);
    }
    scanf("%d", &x);
    while(fscanf(fp,"%s %s %d %f %d %d %d %d %d\n",tfname,tlname,&troll,&tcgpa,&tcid[0],&tcid[1],&tcid[2],&tcid[3],&tcid[4]) != EOF) {
        if (x == troll) {
            u=1;
            printf(GREEN
                "The Students Details are\n");
            printf(BLUE
                "The name of the student is"GREEN" %s %s\n",
                tfname,tlname);
            printf(BLUE
                "The CGPA is"GREEN" %f\n",
                tcgpa);
            printf(BLUE"course IDs are:");
            for (int k = 0; k < 5; k++) {
            printf(GREEN"%d\t",tcid[k]);
            }
            printf("\n"RESET);
            break;
        }
    }
    fclose(fp);
    if(u == 0)
    {
        printf(RED"Student not found");
    }
    printf("\n"RESET);
    printf("Redirecting......");
    sleep(5);
}
 
// Function to find the student
// by the first name
void find_fn()
{
    char p[]="Enter the First Name:";
     FILE *fp=fopen("abc.txt","r");
    printf("\n");
    char a[50];
    printf(GREEN"\n---------------------------\n");
    for(int i=0;i<strlen(p);i++)
    {
        printf(YELLOW"%c"RESET,p[i]);
        Sleep(30);
    }
    scanf("%s",&a);
    int c,u=0;
 
    while(fscanf(fp,"%s %s %d %f %d %d %d %d %d\n",tfname,tlname,&troll,&tcgpa,&tcid[0],&tcid[1],&tcid[2],&tcid[3],&tcid[4]) != EOF) {
        c=strcmp(tfname, a);
        if (c == 0) {
            u=1;
            printf(MAGENTA
                "The Students Details are\n");
            printf(MAGENTA
                "The name of the student is "BLUE"%s %s\n",
                tfname,tlname);
            printf(MAGENTA
                "The Roll Number is"BLUE" %d\n ",
                troll);
            printf(MAGENTA
                "The CGPA is"BLUE" %f\n",
                tcgpa);
            printf(MAGENTA"the course IDs are:");
 
            for (int k = 0; k < 5; k++) {
                printf(BLUE
                    "%d\t",
                    tcid[k]);
            }
            printf("\n\n"RESET);
        }
       
    }
    fclose(fp);
    if(c!=0 && u==0)
    {
        printf(RED"First name not found\n");
    }
    printf("\n"RESET);
    printf("redirecting....");
    sleep(5);
}
 
// Function to find
// the students enrolled
// in a particular course
void find_c()
{
    char p[] = "Enter the course ID:";
    FILE *fp=fopen("abc.txt","r");
    printf("\n");
    int id;
    printf(GREEN"\n----------------------------\n");
    for(int i=0;i<strlen(p);i++)
    {
        printf(YELLOW"%c"RESET,p[i]);
        Sleep(30);
    }
    scanf("%d", &id);
    int c = 0;
 
        while(fscanf(fp,"%s %s %d %f %d %d %d %d %d\n",tfname,tlname,&troll,&tcgpa,&tcid[0],&tcid[1],&tcid[2],&tcid[3],&tcid[4]) != EOF)  {
            for(int d=0;d<5;d++){
            if (id == tcid[d]) {
 
                printf(CYAN
                    "The Student Details are\n");
                printf(YELLOW
                    "The name of the student is"BLUE" %s %s\n",
                    tfname,tlname);
                printf(YELLOW
                    "The Roll Number is "BLUE" %d\n",
                    troll);
                printf(YELLOW
                    "The CGPA is "BLUE" %f\n\n"RESET,
                    tcgpa);
                c = 1;
            }
          }  
        }
    fclose(fp);
    
    if(c == 0)
    {
        printf(RED"students not found\n");
    }
    printf("\n"RESET);
    printf("redirecting....");
    sleep(5);
}
 
// Function to print the details
// of students all the students
void all_s()
{
    char p[] = "Details of all the students";
    FILE *fp=fopen("abc.txt","r");
    int l;
    l=1;
    printf("\n");
    printf(GREEN"\n------------------------\n");
    for(int i=0;i<strlen(p);i++)
    {
        printf(YELLOW"%c"RESET,p[i]);
        Sleep(30);
    }
    printf("\n");
    while(fscanf(fp,"%s %s %d %f %d %d %d %d %d\n",tfname,tlname,&troll,&tcgpa,&tcid[0],&tcid[1],&tcid[2],&tcid[3],&tcid[4]) != EOF){
        printf(RED"%d",l);
        printf(MAGENTA"_The name of the student is "BLUE" %s %s\n",tfname,tlname);
        printf(MAGENTA"The roll number is"BLUE"  %d\n",troll);
        printf(MAGENTA"The CGPA is"BLUE"  %f\n",tcgpa);
        printf(MAGENTA"The course ids are\n");
        for (int k = 0; k < 5; k++) {
                printf(BLUE
                    "%d\t",
                    tcid[k]);
            }
        l++;
        printf("\n\n"RESET);
    }
    fclose(fp);
    printf("\nredirecting.....");
    sleep(5);
    printf("\n");
}

// Function to delete a student
// by the roll number
void del_s()
{
    char p[] = "Deleting a Student";
    for(int i=0;i<strlen(p);i++)
    {
        printf(YELLOW"%c"RESET,p[i]);
        Sleep(30);
    }
    FILE *fp=fopen("abc.txt","r");
    FILE *tp=fopen("temp.txt","a");
    printf("\n");
    printf("\n---------------------");
    int a,u=0;
    printf(RED"\nEnter the Roll Number"
           " which you want "
           "to delete:"RESET);
    scanf("%d", &a);
    while(fscanf(fp,"%s %s %d %f %d %d %d %d %d\n",tfname,tlname,&troll,&tcgpa,&tcid[0],&tcid[1],&tcid[2],&tcid[3],&tcid[4]) != EOF){
        if (a == troll) {
            u=1;
            printf(RED"student details deleted!!\n"RESET);
        }
        else
        {
            fprintf(tp, "%s %s %d %f %d %d %d %d %d\n",tfname,tlname,troll,tcgpa,tcid[0],tcid[1],tcid[2],tcid[3],tcid[4]);
        }
    }
    fclose(fp);
    fclose(tp);
    
    if(u == 0)
    {
        printf(RED"student not found"RESET);
    }
    else
    {
    fp = fopen("abc.txt", "w");
    fclose(fp);
    fp = fopen("abc.txt", "a");
    tp = fopen("temp.txt", "r");

    while(fscanf(tp, "%s %s %d %f %d %d %d %d %d\n",tfname,tlname,&troll,&tcgpa,&tcid[0],&tcid[1],&tcid[2],&tcid[3],&tcid[4]) != EOF)
    {
        fprintf(fp, "%s %s %d %f %d %d %d %d %d\n",tfname,tlname,troll,tcgpa,tcid[0],tcid[1],tcid[2],tcid[3],tcid[4]);
    }

    fclose(fp);
    fclose(tp);
     tp = fopen("temp.txt", "w");
    fclose(tp);
    }
    printf("\n");
    printf("redirecting.....");
    sleep(5);
}
 
// Function to update a students data
void up_s()
{
    char p[] = "Update the Details of Student";
    for(int i=0;i<strlen(p);i++)
    {
        printf(YELLOW"%c"RESET,p[i]);
        Sleep(30);
    }
   printf("\n");
   int sml=2;
   FILE * fp = fopen("abc.txt","r");
   FILE * tp = fopen("temp2.txt","a");
   char fn[50],ln[50];
   int r,c[10],x,z,u=0;
   printf(GREEN"enter the roll number of the student that you want to update:"RESET);
   scanf("%d",&x);
   float cg;
   while ( fscanf(fp,"%s %s %d %f %d %d %d %d %d\n",tfname,tlname,&troll,&tcgpa,&tcid[0],&tcid[1],&tcid[2],&tcid[3],&tcid[4]) != EOF)
   //EOF means end of file after reading all the lines in file while loop ceases 
   {
    if(x == troll)
    {
        u=1;
        printf(MAGENTA"\n1.First name\n2.last name\n3.roll number\n4.CGPA\n5.course ids\n");
        printf(BLUE"enter your choice:");
        scanf("%d",&z);
        switch (z)
        {
        case 1:
            printf(YELLOW"\nEnter a new first name:"RESET);
            scanf("%s",&fn);
            fprintf(tp,"%s %s %d %f %d %d %d %d %d\n",fn,tlname,troll,tcgpa,tcid[0],tcid[1],tcid[2],tcid[3],tcid[4]);
            break;
        
        case 2:
        printf(YELLOW"\nEnter a new last name:"RESET);
        scanf("%s",&ln);
        fprintf(tp,"%s %s %d %f %d %d %d %d %d\n",tfname,ln,troll,tcgpa,tcid[0],tcid[1],tcid[2],tcid[3],tcid[4]);
        break;

        case 3:
        printf(YELLOW"\nEnter a new roll number:"RESET);
        scanf("%d",&r);
        fprintf(tp,"%s %s %d %f %d %d %d %d %d\n",tfname,tlname,r,tcgpa,tcid[0],tcid[1],tcid[2],tcid[3],tcid[4]);
        break;

        case 4:
        printf(YELLOW"\nEnter a new CGPA:"RESET);
        scanf("%f",&cg);
        fprintf(tp,"%s %s %d %f %d %d %d %d %d\n",tfname,tlname,troll,cg,tcid[0],tcid[1],tcid[2],tcid[3],tcid[4]);
        break;

        case 5:
        printf(YELLOW"\nEnter a new course ids:"RESET);
        for(int i=0;i<5;i++)
        {
          scanf("%d",&c[i]);
        }
        fprintf(tp,"%s %s %d %f %d %d %d %d %d\n",tfname,tlname,troll,tcgpa,c[0],c[1],c[2],c[3],c[4]);
        break;


        default:
        printf(RED"\ninvalid choice"RESET);
        break;
        }
    }
    else
    {
        fprintf(tp,"%s %s %d %f %d %d %d %d %d\n",tfname,tlname,troll,tcgpa,tcid[0],tcid[1],tcid[2],tcid[3],tcid[4]);
    }
   }
   fclose(fp);
   fclose(tp);
   if(u == 0)
    {
        printf(RED"student not found"RESET);
    }
    else
    {
    fp = fopen("abc.txt", "w");
    fclose(fp);
    fp = fopen("abc.txt", "a");
    tp = fopen("temp2.txt", "r");

    while(fscanf(tp, "%s %s %d %f %d %d %d %d %d\n",tfname,tlname,&troll,&tcgpa,&tcid[0],&tcid[1],&tcid[2],&tcid[3],&tcid[4]) != EOF)
    {
        fprintf(fp, "%s %s %d %f %d %d %d %d %d\n",tfname,tlname,troll,tcgpa,tcid[0],tcid[1],tcid[2],tcid[3],tcid[4]);
    }

    fclose(fp);
    fclose(tp);
    printf(YELLOW"%c"GREEN"Details updated successully"YELLOW"%c"RESET,sml,sml);
    tp =fopen("temp2.txt","w");
    fclose(tp);
    
    }
    printf("\nredirecting.....");
    sleep(5);
    printf("\n\n");
}
 
// Driver code
//the compiler starts exicuting code  from here
void main()
 
{
    int choice,sml=2, count,k;
    while (k=1) {
        printf(YELLOW"%c" GREEN"WELCOME TO STUDENT INFORMATION SYSTEM"YELLOW"%c",sml,sml);
        printf(GREEN"\n<----------------------------->\n");
        printf(BLUE"The Task that you "
               "want to perform\n");
        printf(CYAN"1. Add the Student Details\n");
        printf(CYAN"2. Find the Student "
               "Details by Roll Number\n");
        printf(CYAN"3. Find the Student "
               "Details by First Name\n");
        printf(CYAN"4. Find the Student "
               "Details by Course Id\n");
        printf(CYAN"5. Details of "
               "all the students\n");
        printf(CYAN"6. Delete the Students Details"
               " by Roll Number\n");
        printf(CYAN"7. Update the Students Details"
               " by Roll Number\n");
        printf(CYAN"8. To Exit\n");
        printf(RESET"\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_student();
            break;
        case 2:
            find_rl();
            break;
        case 3:
            find_fn();
            break;
        case 4:
            find_c();
            break;
        case 5:
            all_s();
            break;
        case 6:
            del_s();
            break;
        case 7:
            up_s();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("invalid choice");
}
}
}
