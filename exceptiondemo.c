#include "stdio.h"
#include "exceptiondemo.h"
#include "CException.h"
#include "exception.h"

#define R_IS_0 1
#define R_IS_NEG 2

float FindArea(float radius){
  
  if(radius==0)
    Throw(createException("radius cant be 0",R_IS_0));
  else if(radius<0)
    Throw(createException("radius cant be negative",R_IS_NEG));
  return 22.0/7.0*radius*radius;
  
}
void tryException(float radius){
  CEXCEPTION_T   ex;
  float area;
  Try
  {
   area=FindArea(radius);
   printf("The circle with the radius %f has the area of %f",radius,area);
  }
  Catch(ex)
  {
    dumpException(ex);
    
  }
  
}

