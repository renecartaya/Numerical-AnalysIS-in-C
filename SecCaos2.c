#include<stdio.h>
#include<stdlib.h>
#include<math.h>

main(){
       double x,a,a_0,a_N;
       int n,N;
       FILE *fp;
       fp=fopen("logistico.dat","w");
       
       printf("Programa para Generar Secuencias de Numeros Caoticos\n");
       printf("El Programa se basa en la generalizacion de un mapamlogistico\n");
       
       printf("Introduzca la cantidad de números que desea generar N= \n");
       scanf("%d",&N);
       
       printf("Introduzca la cota inferior de a_0= \n");
       scanf("%lf",&a_0);
       
       printf("Introduzca la cota superior de a_N= \n");
       scanf("%lf",&a_N);
         
       for (a=a_0;a<a_N;a+=0.01){
       x=(double)rand()/RAND_MAX;
       for(n=0;n<N;++n){
       x=a*x*(1-x);
       if(n>100);
       fprintf(fp,"%lf %lf\n",a,x);
     }
}
}
