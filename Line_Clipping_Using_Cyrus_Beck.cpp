// Write a Program to perform Line Clipping using Cyrus Beck Algorithm.
#include<iostream>
#include<algorithm>
#include<graphics.h>

using namespace std;

void rectangle_wind(int xmin, int ymin, int xmax, int ymax)
{
    int x,y;
    y=ymin;
    for(x=xmin; x<=xmax; x++)
        putpixel(x,y,WHITE);
    y=ymax;
    for(x=xmin; x<=xmax; x++)
        putpixel(x,y,WHITE);
    x=xmin;
    for(y=ymin; y<=ymax; y++)
        putpixel(x,y,WHITE);
    x=xmax;
    for(y=ymin; y<=ymax; y++)
        putpixel(x,y,WHITE);
}

void line_majormovt(int xminl, int yminl, int xmaxl, int ymaxl, int lcolor)
{
    float x=xminl;
    float y=yminl;
    float dx = xmaxl-xminl;
    float dy = ymaxl-yminl;
    float m = dy/dx;
    if(abs((int)dy)<abs((int)dx))
    {
        putpixel(x,y,lcolor);
        while(x<=xmaxl)
        {
            y+=m;
            x++;
            putpixel(x,y,lcolor);
        }
    }
    else
    {
        putpixel(x,y,lcolor);
        while(y<=ymaxl)
        {
            x+=1/m;
            y++;
            putpixel(x,y,lcolor);
        }
    }
}

void clip_line(int xmin, int ymin, int xmax, int ymax, int xminl, int yminl, int xmaxl, int ymaxl)
{
    //normals
    int left[]={-1,0};
    int bottom[]={0,1};
    int right[]={1,0};
    int top[]={0,-1};
    float p2_p1[]={xmaxl-xminl, ymaxl-yminl};
    float pe[]={xmin, ymin};
    float tleft=(pe[0]-xminl)/p2_p1[0];
    pe[0]=xmin;
    pe[1]=ymax;
    float tbottom=(ymin-pe[1])/(-p2_p1[1]);
    pe[0]=xmax;
    pe[1]=ymax;
    float tright=(xminl-pe[0])/(-p2_p1[0]);
    pe[0]=xmax;
    pe[1]=ymin;
    float ttop=(pe[1]-yminl)/p2_p1[1];

    float s_ent[5];
    s_ent[0]=0;
    int i=1;
    float s_ext[5];
    int j=0;

    if(tleft>0 && tleft<1)
    {
        s_ent[i]=tleft;
        i++;
    }
    if(ttop>0 && ttop<1)
    {
        s_ent[i]=ttop;
        i++;
    }
    if(tright>0 && tright<1)
    {
        s_ext[j]=tright;
        j++;
    }
    if(tbottom>0 && tbottom<1)
    {
        s_ext[j]=tbottom;
        j++;
    }
    s_ext[j]=1;
    j++;

    float *t_ent = max_element(s_ent,s_ent+i);
    float *t_ext = min_element(s_ext,s_ext+j);

    float pt_ent[]= {xminl+(*t_ent)*p2_p1[0], yminl+(*t_ent)*p2_p1[1]};
    float pt_ext[]= {xminl+(*t_ext)*p2_p1[0], yminl+(*t_ext)*p2_p1[1]};

    cleardevice();
    rectangle_wind(xmin, ymin, xmax, ymax);
    line_majormovt(pt_ent[0],pt_ent[1],pt_ext[0],pt_ext[1],WHITE);
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    int xmin, ymin, xmax, ymax;
    int xminl, yminl, xmaxl, ymaxl;
    cout<<"Enter xmin, ymin, xmax, ymax for rectangular window"<<endl;
    cin>>xmin>>ymin>>xmax>>ymax;
    rectangle_wind(xmin, ymin, xmax, ymax);
    cout<<"Enter xmin, ymin, xmax, ymax for original line"<<endl;
    cin>>xminl>>yminl>>xmaxl>>ymaxl;
    line_majormovt(xminl, yminl, xmaxl, ymaxl, WHITE);
    cout<<"Press any key to clip line"<<endl;
    char ch;
    cin>>ch;
    clip_line(xmin, ymin, xmax, ymax, xminl, yminl, xmaxl, ymaxl);
    int temp;
    cin >> temp;
    getch();
    closegraph();
    return 0;
}