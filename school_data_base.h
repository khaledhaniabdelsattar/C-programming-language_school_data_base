
#ifndef "school_data_base.h"
#define "school_data_base.h"

#define Max_Size_Data_Base 10


struct student
{
  uint8_t student_ID;
  uint8_t student_Year;
  uint8_t Courses_ID[3];
  uint8_t Courses_Grade[3];
};

typedef struct student student;


struct Student_Data_Base
{
   student  Students_array[Max_Size_Data_Base]; //Arrays of students;
  int8_t Number_Of_Entries;
  //int a [3];
};

typedef struct Student_Data_Base Student_Data_Base;

bool SDB_IsFull();
uint8_t SDB_GetUsedSize();
bool SDB_AddEntry(uint8_t id,uint8_t year,uint8_t*subjects,uint8_t*grades);
bool ReadEntry (uint8_t id,uint8_t* year,uint8_t*subjects,uint8_t*grades);
bool SDB_IsIdExist(uint8_t id);
void SDB_DeletEntry(uint8_t id);



#endif
