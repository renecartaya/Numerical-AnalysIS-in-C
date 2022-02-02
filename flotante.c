#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  /*
   * Rene Cartaya 06-39329
   */
  printf("\nCon una presicion de 6 digitos en la parte flotante:\n");
  float f = 1.999999;
  float g = 1.999999;
  printf("%f %f\n",f,g);
  printf("Suma %f\n",f+g);
  printf("Resta %f\n",f-g);
  printf("Mult %f\n",f*g);
  printf("Div  %f\n",f/g);
  
  printf("\nCon una presicion de 7 digitos en la parte flotante:\n");
  f = 1.9999999;
  g = 1.9999999;
  printf("%f %f\n",f,g);
  printf("Suma %f\n",f+g);
  printf("Resta %f\n",f-g);
  printf("Mult %f\n",f*g);
  printf("Div  %f\n",f/g);
  
  system("PAUSE");	
  return 0;
}