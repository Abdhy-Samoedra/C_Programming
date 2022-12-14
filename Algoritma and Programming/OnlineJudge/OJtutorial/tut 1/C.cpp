#include <stdio.h>

int main()
{
    float a,b,c,d,e,f,g,h,i,j,k,l;
    
    scanf("%f %f %f %f", &a, &b, &c, &d);
    scanf("%f %f %f %f", &e, &f, &g, &h);
    scanf("%f %f %f %f", &i, &j, &k, &l);

    printf("%.2lf\n",a*2.0 + (b/2.0)*4.0 + (c/3.0)*6.0 + (d/4.0)*4.0);
    printf("%.2lf\n",e*2.0 + (f/2.0)*4.0 + (g/3.0)*6.0 + (h/4.0)*4.0);
    printf("%.2lf\n",i*2.0 + (j/2.0)*4.0 + (k/3.0)*6.0 + (l/4.0)*4.0);

    return 0;

}