#include <stdio.h>
int main(){
    struct point{
        int x;
        int y;
    };
    struct point p1,p2;
    struct rect{
        struct point p1;
        struct point p2;
    };
    struct rect x;

    int s1,s2,sum;
    printf("Enter Input of x1 and x2");
    scanf("%d %d",&x.p1.x,&x.p2.x);


    printf("Enter Input of y1 and y2");
    scanf("%d %d",&x.p1.y,&x.p2.y);

    sum = (x.p1.y-x.p1.x)*(x.p2.y-x.p2.x);
    printf("%d",sum);
}