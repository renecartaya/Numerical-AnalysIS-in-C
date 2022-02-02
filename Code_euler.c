#include <stdio.h>

main(){
  double y,v,h,t,tf,g,m,F,a;
  FILE *fp;

  fp=fopen("euler.dat","w");
  
  h=0.01; // paso de tiempo
  m=1;
  g=-10;
  F=m*g;
  a=F/m;

  tf=3;
  y=0; // condicion inicial
  v=10;
  for(t=0;t<tf;t=t+h){
    y=y+v*h;
    v=v+a*h;
    fprintf(fp,"%lf %lf %lf\n",t,y,v);
  }
}
