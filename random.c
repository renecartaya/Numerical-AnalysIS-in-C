#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int i,k,N,ndiv, dist[1000];
float nmin, nmax, try;

FILE *fp;

main()
{
  //printf("Generando numeros pseudos-aleatorios con rand ()\n");
  printf("Intervalo para numeros aleatorios\n");
    scanf("%f %f", &nmin, &nmax);
  printf("Introduzca el numero de lanzamiento \n");  
  scanf("%d", &N);
  printf("Introduzca la resolucion para histograma\n");
  scanf("%d", &ndiv);
 
  fp=fopen("histograma","w");

  for(i=0; i<ndiv; i++)dist[i]= 0;
   for(i=0; i<N; i++){
    try=(float)rand()/RAND_MAX;
    k=(int)(nmax-nmin)*try+nmin;
    dist[k]= dist[k]+1;
    // fprintf(fp,"%f %d %d\n", (nmax-nimin)*try+nmin, k, dist[k]);
  }

   for(k=0; k<=ndiv; k++){
    
     try=(k-nmin)/(nmax-nmin);
   fpintf(fp,"%f %d\n", try, dist[k]);
   }
   fclose(fp);
  }
}
