#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main(){
int i;
float m, k, F, v, x, h, Ec, Ep, Em;

m=20;
k=10;
h=0.0001;
x=5;
v=0;
FILE*f;
f=fopen("Oscilator.txt","wt");
for(i=0;i<100000;i++){

    F=-k*x;
    x=x+v*h;
    v=v+(F/m)*h;
    Ep=0.5*k*(x*x);
    Ec=0.5*m*(v*v);
    Em=Ep+Ec;

    fprintf(f,"%d %f %f %f %f %f \n",i, v, x, Ec, Ep, Em);
}
fclose(f);
return 0;
}
