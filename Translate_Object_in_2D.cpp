// Write a Program to Translate an Object in 2D plane.
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
// function to translate line
void translateLine ( int P[][2], int T[])
{
 /* init graph and line() are used for
 representing line through graphical
 functions
 */
 int gd = DETECT, gm, errorcode;
 initgraph (&gd, &gm, "c:\\tc\\bgi");
 
 // drawing original line using graphics functions
 setcolor (2);
 line(P[0][0], P[0][1], P[1][0], P[1][1]);
 // calculating translated coordinates
 P[0][0] = P[0][0] + T[0];
 P[0][1] = P[0][1] + T[1];
 P[1][0] = P[1][0] + T[0];
 P[1][1] = P[1][1] + T[1];
 // drawing translated line using graphics functions
 setcolor(3);
 line(P[0][0], P[0][1], P[1][0], P[1][1]);
 int temp;
 cin >> temp;
 closegraph();
}
// driver program
int main()
{
 int P[2][2] = {5, 8, 12, 18}; // coordinates of point
 int T[] = {2, 1}; // translation factor
 translateLine (P, T);
 int temp;
 cin >> temp;
 return 0;
}