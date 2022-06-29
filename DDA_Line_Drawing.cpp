// Write a Program to implement DDA Line Drawing Algorithm.
#include<graphics.h>  
#include<conio.h>  
#include<iostream>  

using namespace std;

int main(void)  
{  
    int gd = DETECT ,gm, i, gc;  
    float x, y,dx,dy,steps;  
    int x0, x1, y0, y1;  
    initgraph(&gd, &gm, "C:\\TC\\BGI");  
    setbkcolor(WHITE);  
    x0 = 100 , y0 = 200, x1 = 500, y1 = 300; 
    cout<<"Enter Value of X0 and Y0: ";
    cin>> x0 >> y0; 
    cout<<"Enter Value of X1 and Y1: ";
    cin>> x1 >> y1;

    //Put x0 and Y0 = 100 and 200
    //Put x1 and Y2 = 500 and 300

    dx = (float)(x1 - x0);  
    dy = (float)(y1 - y0);  
    if(dx>=dy)  
    {  
        steps = dx;  
    }  
    else  
    {  
        steps = dy;  
    }  
    dx = dx/steps;  
    dy = dy/steps;  
    x = x0;  
    y = y0;  
    i = 1;  
    while(i<= steps)  
    {  
        putpixel(x, y, RED);  
        x += dx;  
        y += dy;  
        i=i+1;  
    }  
    int temp;
    cin >> temp;
    closegraph();  
}