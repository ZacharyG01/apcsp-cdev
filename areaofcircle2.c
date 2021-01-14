#include <stdio.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main
float areaofcircle(float radius)
{
 float area = M_PI *  radius * radius;
 return area;
}



int main(int argc, char* argv[]) 
{
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
  float start = 5.2;
  int reps = 3;
  
  // for testing only - do not change
  getTestInput(argc, argv, &start, &reps);

  
  
  // add your code below to call areaOfCircle function with values between
  // start and end

char inputlower[256];
float inputlower2;
char inputupper[256];
float inputupper2;



printf("input lower: ");
fgets(inputlower, 256, stdin);
sscanf(inputlower, "%f", &inputlower2);

printf("input upper: ");
fgets(inputupper, 256, stdin);
sscanf(inputupper, "%f", &inputupper2);






for (float i = 0; i < inputupper2-inputlower2; i++) {
   printf("area of radius %f : %f\n", inputlower2+i, areaofcircle(inputlower2+i));
}

}
