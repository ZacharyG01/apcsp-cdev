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


void createStudent(char* fname, char* lname, int age, int id)
{
  Student* student1 =(Student*)malloc(sizeof(Student));
  student1->firstName = (char*)malloc(strlen(fname)+1);
  student1->lastName = (char*)malloc(strlen(lname)+1);
  strcpy(student1->firstName, fname);
  strcpy(student1->lastName, lname);
  student1->age = age;
  student1->id = id;
  students[numStudents] = student1;
  numStudents++;
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
}

void deleteStudent(Student* student)
{
 if (student != 0) {
  free(student->firstName);
  free(student->lastName);
  free(student);
  student = 0;
}

  // free the memory associated with a student including the strings
}

void deleteStudents()
{
  for (int i = 0; i < numStudents; i++) { 
    deleteStudent(students[i]);
    students[i] = 0;

}
numStudents = 0;

  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
}


void saveStudents(int key)
{

  FILE* fp;
  char buff[256];
  char buff2[256];
  char buff3[256];
  char buff4[256];
  
  fp = fopen(STUFILE, "w");
  if (fp)
  {
    for (int i = 0; i < numStudents; i++) {
      // copy the data into a string first, might be useful if you
      // want to do something to the string before saving it to the file...
      sprintf(buff,"%s", students[i]->firstName);
      caesarEncrypt(buff, key);
      fprintf(fp, "%s ", buff);
      sprintf(buff2,"%s", students[i]->lastName);
      caesarEncrypt(buff2, key);
      fprintf(fp, "%s ", buff2);
      sprintf(buff3,"%d", students[i]->age);
      caesarEncrypt(buff3, key);
      fprintf(fp, "%s ", buff3);
      sprintf(buff4,"%ld", students[i]->id);
      caesarEncrypt(buff4, key);
      fprintf(fp, "%s\n", buff4);
    }
    printf("Saved %d students", numStudents);
    fclose(fp);
}
// save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532
  // the best way to do this is to convert the student data to a string using sprintf and then
  // (optionally) encrypt the whole string before writing it to disk (see cdemo/fileio3.c)
}


void loadStudents(int key)
{
  deleteStudents();
  {
  FILE* fp;

  fp = fopen(STUFILE, "r");
  if (fp)
  {
    while (1)
    {
      char firstName[100]; char lastName[100]; int age; int id; char tmpage[100]; char tmpid[100];
      if (fscanf(fp, "%s %s %d %d\n", firstName, lastName, &age, &id) == 4)
      {
        caesarDecrypt(firstName, key);
        caesarDecrypt(lastName, key);
        sprintf(tmpage, "%d", age);
        sprintf(tmpid, "%d", id);
        caesarDecrypt(tmpage, key);
        caesarDecrypt(tmpid, key);
        createStudent(firstName, lastName, atoi(tmpage), atoi(tmpid));
      }
      else
        break;
    }
    fclose(fp);
  }
  else
  {
    printf("no file found\n");
  }
}
  // load the students from the data file overwriting all exisiting students in memory
  //  - make sure you first deleteStudents before loading new ones
  //  - when loading it is best to load data into four strings and then (optionally) decrypt the
  //    strings
  //  - call createStudent to correctly create the students
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




