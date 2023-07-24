
#define "school_data_base.h
bool SDB_IsFull()
{
    if(SDB.Number_Of_Entries==(Max_Size_Data_Base-1))
    {
       return 1;
    }
    else
    {
        return 0;
    }
}

uint8_t SDB_GetUsedSize()
{
 return ((SDB.Number_Of_Entries)+1);

}

bool SDB_AddEntry(uint8_t id,uint8_t year,uint8_t*subjects,uint8_t*grades)
{


    int add_indecator1=0;
    int add_indecator2=0;

    int i=0;

    if (SDB_IsFull()==1)
    {
        printf(" The Data Base is Full \n");

        return 0;
    }



    SDB.Number_Of_Entries++;
    SDB.Students_array[SDB.Number_Of_Entries].student_ID=id;
    SDB.Students_array[SDB.Number_Of_Entries].student_Year=year;
    for(i=0; i<3;i++)
    {
        SDB.Students_array[SDB.Number_Of_Entries].Courses_ID[i]=subjects[i];
        SDB.Students_array[SDB.Number_Of_Entries].Courses_Grade[i]=grades[i];
    }


    //check the adding to the data base is correct


     if((SDB.Students_array[SDB.Number_Of_Entries].student_ID==id)&&(SDB.Students_array[SDB.Number_Of_Entries].student_Year==year))// check the adding is co
     {
      add_indecator1=1;
     }

     for(i=0; i<3;i++)
    {
       if((SDB.Students_array[SDB.Number_Of_Entries].Courses_ID[i]==subjects[i])&&(SDB.Students_array[SDB.Number_Of_Entries].Courses_Grade[i]=grades[i]))
       {
         add_indecator2++;
       }
    }

    if((add_indecator1==1)&&(add_indecator2==3))

    {
        return 1;

    }

   else
    {
    return 0;
    }
}


bool ReadEntry (uint8_t id,uint8_t* year,uint8_t*subjects,uint8_t*grades)

{

 bool Read_return=0;
  int i=0;
  int j=0;

 for(i=0; i<=SDB.Number_Of_Entries;i++)
 {

     if(SDB.Students_array[i].student_ID==id)
      {
    Read_return=1;
    (*year)=SDB.Students_array[i].student_Year; //assign by pointer

         for(j=0;j<3;j++)
         {
        subjects[j]=SDB.Students_array[i].Courses_ID[j];
        grades[j]=SDB.Students_array[i].Courses_Grade[j];
         }

      }


 }

 if (Read_return==0)
 {
     printf("the student not found\n ");
     (*year)=0;
     for(j=0;j<3;j++)
         {
        subjects[j]=0;
        grades[j]=0;
         }

 }

return Read_return;
}

void SDB_GetIdList(uint8_t*countt,uint8_t*listt)
{

    int i=0;
    (*countt)=SDB.Number_Of_Entries+1;

     for(i=0; i<=SDB.Number_Of_Entries;i++)
     {
         listt[i]=SDB.Students_array[i].student_ID;
     }



}


bool SDB_IsIdExist(uint8_t id)
{


int id_return=0;
    int i=0;
    for(i=0;i<=SDB.Number_Of_Entries;i++)
    {
    if(SDB.Students_array[i].student_ID==id)
     {
        id_return=1;
     }

    }

    return id_return;
}


void SDB_DeletEntry(uint8_t id)
{

    int i=0;
    int j=0;
    uint8_t temp_id=0;

    int delet_indicator=0;
    int delet_index=0;

    for(i=0;i<=SDB.Number_Of_Entries;i++)

     {
         if(SDB.Students_array[i].student_ID==id)

         {

             delet_index=i;
             delet_indicator=1;
             //SDB.Students_array[i].student_ID=50;

         }

     }



     if (delet_indicator==1)

        {

     for(j=delet_index;j<=SDB.Number_Of_Entries;j++) //shifting the data base

           {


         SDB.Students_array[j]=SDB.Students_array[j+1];

            }

         }


    if (delet_indicator==1)

     {
        SDB.Number_Of_Entries--;
     }


      if (delet_indicator==0)
             {
             printf("the enterd id which wanted to be deleted is not found \n ");
             }

}
