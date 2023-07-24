#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "school_data_base.h"
    


int main()
{

int i=0;
SDB.Number_Of_Entries=-1;



// creating students for testing

// students 1
student stu1 ;

stu1.student_ID =111;
stu1.student_Year=5;
uint8_t stu1_courses_id [3]={100,7,8};
uint8_t stu1_grades [3]= {22,80,100};

for ( i=0;i<3;i++)
{
    stu1.Courses_ID[i]= stu1_courses_id [i];
}

for ( i=0;i<3;i++)
{
    stu1.Courses_Grade[i]= stu1_grades [i];
}


// student2
student stu2 ;

stu2.student_ID =112;
stu2.student_Year=10;
uint8_t stu2_courses_id [3]={105,70,6};
uint8_t stu2_grades [3]= {50,100,70};

for ( i=0;i<3;i++)
{
    stu2.Courses_ID[i]= stu2_courses_id [i];
}

for ( i=0;i<3;i++)
{
    stu2.Courses_Grade[i]= stu2_grades [i];
}


      // student 3
      student stu3 ;

stu3.student_ID =113;
stu3.student_Year=8;
uint8_t stu3_courses_id [3]={106,108,109};
uint8_t stu3_grades [3]= {90,95,77};

for ( i=0;i<3;i++)
{
    stu3.Courses_ID[i]= stu3_courses_id [i];
}

for ( i=0;i<3;i++)
{
    stu3.Courses_Grade[i]= stu3_grades [i];
}

      //

bool entry1=0;

entry1=SDB_AddEntry(stu1.student_ID,stu1.student_Year,stu1_courses_id,stu1_grades); // enter the first student to the array

 printf("  Full data base indecator =%d\n",SDB_IsFull());
 printf("  The size of the data base is %d\n",SDB_GetUsedSize());
 printf(" first entry indicator =%d\n",entry1);
 printf(" Hello world!\n");

 // enter second student

 bool entry2=0;

entry2=SDB_AddEntry(stu2.student_ID,stu2.student_Year,stu2_courses_id,stu2_grades); // enter the second student to the array

 printf("  Full data base indecator =%d\n",SDB_IsFull());
 printf("  The size of the data base is %d\n",SDB_GetUsedSize());
 printf(" second entry indicator =%d\n",entry2);
 printf(" Hello world!\n");

  //
bool entry3=0;

entry3=SDB_AddEntry(stu3.student_ID,stu3.student_Year,stu3_courses_id,stu3_grades); // enter the third student to the array

 printf("  Full data base indecator =%d\n",SDB_IsFull());
 printf("  The size of the data base is %d\n",SDB_GetUsedSize());
 printf(" third entry indicator =%d\n",entry3);
 printf(" Hello world!\n");

  //
 //

bool read_entry_indecator=0;

uint8_t read_year=0;
uint8_t* ptr_read_year= &read_year;
uint8_t read_courses_id [3]={0};
uint8_t read_grades [3]={0};



read_entry_indecator=ReadEntry(stu2.student_ID,ptr_read_year,read_courses_id,read_grades);


printf( "id =%d \n" ,stu2.student_ID);
printf("  the year is =%d\n",read_year);

for ( i=0;i<3;i++)
{
    printf(" the courses id is respetivly  %d\n",read_courses_id[i]);

}

for ( i=0;i<3;i++)
{
    printf(" the grades is respetivly =%d\n",read_grades[i]);

}

printf(" read entry indecator is %d\n",read_entry_indecator);


uint8_t entries_count=0;
uint8_t*ptr_entries_count=&entries_count;
uint8_t Id_list[SDB_GetUsedSize()];

SDB_GetIdList(ptr_entries_count,Id_list);
printf("  Hello world!\n");

for ( i=0;i<SDB_GetUsedSize();i++)
{
    printf(" ids =%d\n",Id_list[i]);
}
printf("  data base count is %d  \n",entries_count);


bool existt=0;

 existt=SDB_IsIdExist(1153);

 if (existt==1)
 {
     printf(" the entered id is existing \n");
 }
else
{
    printf(" the entered id is not  existing \n");
}


 printf("  Hello world!\n ");


 SDB_DeletEntry(stu1.student_ID);

 // geting the ids aftter deleting

 entries_count=0;// entries   count

uint8_t Id_list1[SDB_GetUsedSize()];

SDB_GetIdList(ptr_entries_count,Id_list1);


 for ( i=0;i<SDB_GetUsedSize();i++)

     {

    printf(" ids =%d\n",Id_list1[i]);


     }
  printf("  data base elements is %d  \n",SDB_GetUsedSize());


// read an elements in the array after deleting and printing


read_entry_indecator=ReadEntry(stu1.student_ID,ptr_read_year,read_courses_id,read_grades);


printf( "id =%d \n" ,stu1.student_ID);
printf("  the year is =%d\n",read_year);

for ( i=0;i<3;i++)
{
    printf(" the courses id is respetivly  %d\n",read_courses_id[i]);

}

for ( i=0;i<3;i++)
{
    printf(" the grades is respetivly =%d\n",read_grades[i]);

}

printf(" read entry indecator is %d\n",read_entry_indecator);

    return 0;
}
