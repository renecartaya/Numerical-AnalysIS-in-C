/*
 *  rungekutta.c
 *
 *	Title:			Fourth-order Runge-Kutta Method
 *	Author:			Tristan Jehan
 *	Description:	Runge-Kutta method is used to integrate a simple harmonic oscillator y: + y = 0
 *					The solution for this Ordinary Differential Equation is y = cos(t)
 *	Date:			03/07/00	
 *	
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* f = dy/dt */
#define y(t) cos(t)	
#define Y0 1
#define Ydot0 0
#define PI 3.14159265359879323846f
#define TMAX 100*PI

int main()
{
	int time0,time1;
	int numiter;
	double t=0, h;
	double sumerror=0;
	double error=0;
	double k1[2],k2[2],k3[2],k4[2],Y[2];
		
	/* enter argument */
	printf("Enter the step size: ");
	scanf("%lf", &h);
		
	/* check out for arguments */
	if ((h<=0) || (h>TMAX)) {
		printf("Hey, you gave a wrong step size!");
		exit(0);
	}
		
	time0=clock();
	Y[0] = Y0;
	Y[1] = Ydot0;
	/* main loop */
	while(t<TMAX) {
		k1[0] = h * Y[1];
		k1[1] = -h * Y[0];
		k2[0] = h * (Y[1] + 0.5f * k1[1]);
		k2[1] = -h * (Y[0] + 0.5f * k1[0]);
		k3[0] = h * (Y[1] + 0.5f * k2[1]);
		k3[1] = -h * (Y[0] + 0.5f * k2[0]);
		k4[0] = h * (Y[1] + k3[1]);
		k4[1] = -h * (Y[0] + k3[0]);	
		Y[0] = Y[0] + (k1[0] + 2.0f*(k2[0] + k3[0]) + k4[0]) /6.0f;
		Y[1] = Y[1] + (k1[1] + 2.0f*(k2[1] + k3[1]) + k4[1]) /6.0f;
		t+=h;
		error = fabs(y(t) - Y[0]);
		sumerror += error;
	}
	time1=clock();

	numiter = (int)(TMAX/h);
	
	/* print results */
	printf("\nThe program has computed %d points\n", numiter);
	printf("It was executed in %.3f secondes\n", (float)(time1-time0)/CLOCKS_PER_SEC);
	printf("average error: %.6f\nfinal error: %f\nfinal slope: %f\n", sumerror/numiter, error, Y[1]);
			
	return 0;
}

