#include<stdio.h>
#include<conio.h>
#include<string.h>
float Grading_system(float Marks);
char* Grading_name(float Marks);
void print_star();
int Grading_point(float Marks);
int main() {
    printf("                                                              Welcome To Our 'SLIET' SGPA Calculator Program                                    ");
    printf("                                                                                                  Made By Ansh Girdher                                              \n");
printf("\n");
    int Subjects;
    start:
    printf("\n");
    printf("How many subjects are there in our currently pursuing/pursued semester (which is used to calculate SGPA) :- ");
    scanf("%d", &Subjects);
    printf("\n");
    print_star();

    char Subject_Name[50][50];

    for (int i = 0; i < Subjects; i++) {
        printf("Enter a Name of Subject %d: ", i + 1);
        fflush(stdin);
        fgets(Subject_Name[i], sizeof(Subject_Name[i]), stdin);
        strtok(Subject_Name[i], "\n");
    }
    printf("\n");
    print_star();
    float Marks[Subjects];
     char Grades[Subjects][3];
     int Grade_point[Subjects][2];
     int Credit_point[Subjects];
     start_again:
    for (int i = 0; i < Subjects; i++)
    {
      
       printf("\nEnter a Obtained Marks of %s Subject Out of 100 :- ",Subject_Name[i]);
       scanf("%f",&Marks[i]);
       if (Marks[i]>100 || Marks[i]<0)
       {
         printf("                                                                  Invalid Marks!!Please Try Again\n");
       }
       if (Marks[i]>100 || Marks[i]<0)
       {
         print_star();
       }
      if (Marks[i]>100 || Marks[i]<0)
       {
        goto start_again;
       }  
    }
    printf("\n");
    print_star();
    for (int i = 0; i < Subjects; i++)
    {
       printf("Enter a Credit Point of %s Subject :- ",Subject_Name[i]);
       scanf("%d",&Credit_point[i]);
    }
    printf("\n");
    print_star();
    int obtained=0;
    for (int i = 0; i < Subjects; i++)
    {
       obtained+=Credit_point[i];
    }
    printf("The Total Credit Points is : %d",obtained);
    
    printf("\n");
    print_star();
    
    for (int i = 0; i < Subjects; i++)
    {
        Grading_system(Marks[i]);
        strcpy(Grades[i], Grading_name(Marks[i]));
    }
         printf("                                                                       Subject-wise Grades:-                                              \n");
    for (int i = 0; i < Subjects; i++) {
        printf("%s : %s\n", Subject_Name[i], Grades[i]);
    }
     printf("\n");
    print_star();

for (int i = 0; i < Subjects; i++)
{
   Grading_point(Marks[i]);
}
 printf("                                                                     Subject-wise Grade Point:-                                              \n");
register int result;
for (int i = 0; i < Subjects; i++)
{
    result= Grading_point(Marks[i]);
   printf("%s : %d\n",Subject_Name[i],result);
}
printf("\n");
    print_star();
    printf("\n                                                     List of every subject for which you have obtained credits.\n");
    
    for (int i = 0; i < Subjects; i++)
    {
      char credits[]="Credits";
      register int result2= Grading_point(Marks[i])*Credit_point[i];
      printf("%s : %d %s\n",Subject_Name[i],result2,credits);
    }
    printf("\n");
    print_star();
    int total_credit=0;
    for (int i = 0; i < Subjects; i++)
    {
      total_credit+=Grading_point(Marks[i])*Credit_point[i];
    }
    printf("The Total credits of all subjects are :- %d\n",total_credit);
    printf("\n");
    print_star();
    float final_result= (float)total_credit/obtained;
    printf("The Semester Grade Point Average(SGPA) is :- %.2f\n",final_result);
    int start_end;
    printf("\nIf you want to exit, type '0'or to start, type '1' : ");
    scanf("%d",&start_end);
    if (start_end==1)
    {
      print_star();
      printf("\n                                                                          Starting Again!!\n");
    }
    
    
    if (start_end==0)
    {
        goto exit;
        
    }
    else if (start_end==1)
    {
       goto start;
    }
    exit:
    printf("\n");
    printf("                                                                   Great!Thanks for using our Program                                           ");

    
    getch();
    return 0;
}
float Grading_system(float Marks){
  Grading_name(Marks);
}
int Grading_point(float Marks){
    if (Marks>=81 && Marks<=100)
    {
        return 10;
    }
    else if (Marks>=70 && Marks<=80)
    {
       return 9;
    }
    else if (Marks>=61 && Marks<=69)
    {
       return 8;
    }
    else if (Marks>=56 && Marks<=60)
    {
       return 7;
    }
    else if (Marks>=51 && Marks<=55)
    {
       return 6;
    }
    else if (Marks>=41 && Marks<=50)
    {
       return 5;
    }
    else if (Marks>=35 && Marks<=40)
    {
       return 4;
    }
    else if (Marks>=33 && Marks<=34)
    {
       return 2;
    }
    else if (Marks<33)
    {
       return 0;
    } 
}
char* Grading_name(float Marks){
    static char grade1[]="A+";
    static char grade2[]="A";
    static char grade3[]="B+";
    static char grade4[]="B";
    static char grade5[]="C+";
    static char grade6[]="C";
    static char grade7[]="D";
    static char grade8[]="E";
    static char grade9[]="F";
    if (Marks>=81 && Marks<=100)
    {
        return grade1;
    }
    else if (Marks>=70 && Marks<=80)
    {
       return grade2;
    }
    else if (Marks>=61 && Marks<=69)
    {
       return grade3;
    }
    else if (Marks>=56 && Marks<=60)
    {
       return grade4;
    }
    else if (Marks>=51 && Marks<=55)
    {
       return grade5;
    }
    else if (Marks>=41 && Marks<=50)
    {
       return grade6;
    }
    else if (Marks>=35 && Marks<=40)
    {
       return grade7;
    }
    else if (Marks>=33 && Marks<=34)
    {
       return grade8;
    }
    else if (Marks<33)
    {
       return grade9;
    } 
}
void print_star()
{
    for (int i = 0; i < 160; i++)
    {
        printf("*");
    }
    printf("\n");
}