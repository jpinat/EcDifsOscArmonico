#include <stdio.h>
#include <math.h>

main(){
int i;
float m, k, F, v, x, h, Ec, Ep, Em;

m=20;
k=10;
h=0.0001;
x=5;
v=0;


for(i=0;i<1000;i++){

    F=-k*x;
    x=x+v*h;
    v=v+(F/m)*h;
    Ep=0.5*k*(x*x);
    Ec=0.5*m*(v*v);
    Em=Ep+Ec;

    printf("%f %f %f %f %f \n", v, x, Ec, Ep, Em);
}
return 0;
}
