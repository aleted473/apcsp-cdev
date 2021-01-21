//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};

struct Student {
    char* firstName;
    char* lastName;
    unsigned int age;
    long id;
};

void createStudent(char* fname, char* lname, int age, int id)
{
   





 struct Student *new_student = (Student* )malloc(sizeof(Student));

 new_student->firstName = (char*)malloc(sizeof(&fname));
 new_student->lastName = (char*)malloc(sizeof(&lname));

 strcpy(new_student->firstName, fname);
 strcpy(new_student->lastName, lname);
 new_student->age = age;
 new_student->id = id;

 for (int i = 0; i< 100; i++)
  {
     if (students[i] == NULL)
     {	
      students[i] = new_student;
      break;
     }
   
  }  
  numStudents++;
}


void deleteStudent(Student* student)
{
  free(student);
}


void deleteStudents()
{
  for (int i = 0; i < 100; i++)
  {
    free(students[i]);
    students[i] = 0;
  }	  
  numStudents = 0;
}


void saveStudents(int key)
{
  FILE *fptr;

  fptr = fopen("studentdata.txt", "w");

  fprintf(fptr, "tom thumb 15 1234 \njames dean 21 2345 \nkaty jones 18 4532\n");

  char buffer[100];

  if (fptr)
  {       
    for (int i = 0; i < numStudents; i++)
    {
	sprintf(buffer, "%s %s %d %ld", students[i]->firstName, students[i]->lastName, students[i]->age, students[i]->id);
	if (key != 0)
        {
          caesarEncrypt(buffer, key);
        }
	printf("saving: %s\n", buffer);
        fprintf(fptr, "%s\n", buffer);	
    }

  fclose(fptr);

  }
}

void loadStudents(int key)
{
  if (numStudents > 0)
  {
    deleteStudents();
  }

  int cazzo = (numStudents + 3);

  FILE *fptr; 
 
  fptr = fopen("studentdata.txt", "r");

  if (fptr)
  {
  
  printf("loaded students");
  
   for (int i = 0; i < cazzo; i++)
   {
 
     char input_firstName[20];
     char input_lastName[20];
     char input_age[20];
     char input_id[20];
     int int_input_age;
     long long_input_id;

      fscanf(fptr, "%s %s %s %s", input_firstName, input_lastName, &input_age, &input_id);
      if (key != 0)
      {
     
        caesarDecrypt(input_firstName, key);
        caesarDecrypt(input_lastName, key);
        caesarDecrypt(input_age, key);
        caesarDecrypt(input_id, key);
 

        
      } 

     sscanf(input_age, "%d", &int_input_age);
     sscanf(input_id, "%ld", &long_input_id);
     createStudent(input_firstName, input_lastName, int_input_age, long_input_id); 

   }
   
  }
  fclose(fptr);

}

void printStudent(Student* student)
{

  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




