void tridiag(double *x,double *y,double *h,double *s,int N){

  double *a,*b,*c,*r,*gamma,*rho;
  int n;

  a=malloc(N*sizeof(double));
  b=malloc(N*sizeof(double));
  c=malloc(N*sizeof(double));
  r=malloc(N*sizeof(double));
  gamma=malloc(N*sizeof(double));
  rho=malloc(N*sizeof(double));

  s[0]=0; s[N-1]=0; // esplines naturales

  for(n=1;n<(N-1);++n){
    a[n]=h[n-1];
    b[n]=2*(h[n-1]+h[n]);
    c[n]=h[n];
    r[n]=6.*((y[n+1]-y[n])/h[n]-(y[n]-y[n-1])/h[n-1]);
  }
  
  gamma[1]=c[1]/b[1];
  rho[1]=r[1]/b[1];

  for(n=2;n<(N-1);++n){
    gamma[n]=c[n]/(b[n]-a[n]*gamma[n-1]);    
    rho[n]=(r[n]-a[n]*rho[n-1])/(b[n]-a[n]*gamma[n-1]);
  }

  s[N-2]=rho[N-2];
  for(n=(N-3);n>0;--n) s[n]=rho[n]-gamma[n]*s[n+1]; // listo !

  free(a); free(b); free(c); free(r); free(gamma); free(rho);

}

