// Write a Program to implement a Midpoint Circle Drawing Algorithm.
#include <graphics.h>  
#include <stdlib.h>  
#include <math.h>  
#include <stdio.h>  
#include <conio.h>  
#include <iostream>  

using namespace std;

class bresen  
{  
    float x, y,a, b, r, p;  
    public:  
    void get();  
    void cal();  
};  
int main (void)  
{  
    bresen b;  
    b.get ();  
    b.cal ();  
    getch ();  
}  
void bresen::get()  
{  
    cout<<"Enter Center And Radius:" <<endl;  
    cout<< "Enter (a, b):";  
    cin>>a>>b;  
    cout<<"Enter R:";  
    cin>>r;  
}
void bresen::cal()  
{  
    /* request auto detection */  
    int gdriver = DETECT,gmode, errorcode;  
    int midx, midy, i;  
    /* initialize graphics and local variables */  
    initgraph (&gdriver, &gmode, " ");  
    /* read result of initialization */  
    errorcode = graphresult (); 

    if (errorcode != grOk)    /*an error occurred */  
    {  
        printf("Graphics error: %s \n", grapherrormsg (errorcode));  
        printf ("Press any key to halt:");  
        getch ();  
        exit (1); /* terminate with an error code */  
    }  

    x=0;  
    y=r; 

    putpixel (a, b+r, RED);  
    putpixel (a, b-r, RED);  
    putpixel (a-r, b, RED);  
    putpixel (a+r, b, RED);  
    p=(5/4)-r; 

    while(x<=y)  
    {  
        if (p<0)  
        p+= (4*x)+6;  
        else  
        {  
            p+=(2*(x-y))+5;  
            y--;  
        }  
        x++;  
        putpixel (a+x, b+y, RED);  
        putpixel (a-x, b+y, RED);  
        putpixel (a+x, b-y, RED);  
        putpixel (a+x, b-y, RED);  
        putpixel (a+x, b+y, RED);  
        putpixel (a+x, b-y, RED);  
        putpixel (a-x, b+y, RED);  
        putpixel (a-x, b-y, RED);  
    }  
}