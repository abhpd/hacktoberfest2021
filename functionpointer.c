#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int multi(int n, int b)
{
    printf("product is %d",(n * b));
}
int addit(int n, int b)
{
    printf("addition is %d",(n+b));
}
int modulu(int n, int b)
{
   
    printf("modulus is %d",(n%b));
}
int divi(int n, int b)
{
    printf("division is %d",(n/b));
}
int main(){
       void (*fun_ptr)(int,int) = &multi;
       void(*fun2_ptr)(int,int)=&addit;
       void(*fun3_ptr)(int,int)=&modulu;
       void(*fun4_ptr)(int,int)=&divi;
       printf("Enter 1 2 3 or 4 for multiplication, addition, modulud or division");
       int o;
       scanf("%d", &o);
       switch (o)
       {
           case 1:(*fun_ptr)(21,3);
                   break;
           case 2:(*fun2_ptr)(21,3);
                   break;
           case 3:(*fun3_ptr)(21,3);
                   break;
           case 4:(*fun4_ptr)(21,3);
                   break;
           default: printf("invlaid");
       }
       
       return 0;
}
