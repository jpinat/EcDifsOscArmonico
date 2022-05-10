#include <math.h>
#include <stdio.h>
#define X_M 640
#define Y_M 480

double M,soporte[2],K,l;
double h;

void Evoluciona_dt(double *, double *);
void Escribe_resultados(double,double,double);

main(){
double x,v;
double tiempo;
int i,j;
int mesfr=1600; //pasos
/* Fijamos los puntos de soporte */
soporte[0]=X_M/4; soporte[1]=Y_M/2;
M=10.0; // masa del oscilador
K=20.0; // Constante del muelle
l=X_M/4;// longitud natural
v=50.0; // velocidad inicial
x=soporte[0]+X_M/4; //Posicion inicial
h=0.0001; //Paso temporal de la ecuacion diferencial discreta
tiempo=0;

printf("# t T V E_t x v\n");

for(i=0;i<1000;i++)
{
for(j=0;j<mesfr;j++)
tiempo+=h;
if(i%10==0){
Escribe_resultados(tiempo,x,v);
}
}
}

void Evoluciona_dt(double *x,double *v)
{
//#define EULER
#define VERLET
double F;
#ifdef EULER
F=-K*((*x)-soporte[0]-l);
(*x)+=h*(*v);
(*v)+=F*h/M;
#endif
#ifdef VERLET
double v_temp;
F=-K*((*x)-soporte[0]-l);
v_temp=(*v)+0.5*F*h/M;
*x+=v_temp*h;
F=-K*((*x)-soporte[0]-l); //Ya hemos cambiado x, esta es la nueva fuerza
(*v)=v_temp+0.5*F*h/M;
#endif
}

void Escribe_resultados(double time,double pos,double speed)
{
double Energia,Energia_p,Energia_c;
Energia_p=0.5*K*(pos-soporte[0]-l)*(pos-soporte[0]-l);
Energia_c=0.5*M*speed*speed;
Energia=Energia_c+Energia_p;
printf("%f %-10.3lf %-10.3lf %-10.3lf %-10.3f %-10.3f\n",
time,Energia_c,Energia_p,Energia,pos,speed);
}
