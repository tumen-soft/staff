#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unistd.h>
struct Point {
  int x, y;
  Point(int a, int b) { this->x = a; this->y = b; }
};

struct Button{
Point lu;
Point ld;
Point ru;
Point rd;
  Button();
};


unsigned long _RGB(int r,int g, int b)
{
    return b + (g<<8) + (r<<16);
}

int
main(int argc, char **argv) {
    Display  *dpy;
    Window    root;
    Screen   *screen;
    GC        gc;
    Pixmap    pm;
    int depth,  h, w;
    char *img;
    dpy = XOpenDisplay(0);
    screen = DefaultScreenOfDisplay(dpy);
    h = HeightOfScreen(screen);
    w = WidthOfScreen(screen);
    root = DefaultRootWindow(dpy);
    depth = DefaultDepth(dpy, DefaultScreen(dpy));
    //gc = XCreateGC(dpy, pm 	, 0, NULL);
    pm = XCreatePixmap(dpy, root, w, h, depth);
    gc = XCreateGC(dpy, pm, 0, NULL);

    XSetForeground (dpy, gc, _RGB(255, 255, 0));
	//штабель
	//int j=0;
	for(int i=-100;i<=100;i++){
	//if(i>12)j=i-12;
	//XDrawLine(dpy, root, gc, 100, 100+i, 200-j, 100+i);
	//r^2=(x-h)^2+(y-k)^2    (h,k)centre  (x,y)point
	//2XDrawPoint(dpy, root, gc, 200+    i+100,200+     (-i)+100);	
        //2XDrawPoint(dpy, root, gc, 200+    i,200+     -(-i));
        //2XDrawPoint(dpy, root, gc, 200+    i+100,200+     (-i)+100);
        //2XDrawPoint(dpy, root, gc, 200+    i,200+     -(-i));
	/*

typedef struct {
	short x1, y1, x2, y2;
} XSegment;
 
typedef struct {
	short x, y;
} XPoint;
 
typedef struct {
	short x, y;
	unsigned short width, height;
} XRectangle;
 
typedef struct {
	short x, y;
	unsigned short width, height;
	short angle1, angle2;             // Degrees * 64 
} XArc;







	*/
	}
    
        //XSetForeground (dpy, gc, _RGB(0, 0, 255));


int j=0,k=0;	
bool trig=false;
 for(;;){ 

if(k>50){
if (trig)j--;else j++;
if((j>254)||(j<1)){if(trig)trig=false;else trig=true;}
k=0;
}

k++;

 XSetForeground (dpy, gc, _RGB(0, 0, j));

sleep(0.7) ; 
	for (int x=0;x<1100;x=x+190)
	for (int y=0;y<800;y=y+50){
    for(int i=0;i<3;i++){
    XDrawLine(dpy, root, gc, 150+x+i, 100+y+i, 250+x+i, 130+y+i);
    XDrawLine(dpy, root, gc, 250+x+i, 130+y+i, 150+x+i, 150+y+i);
    XDrawLine(dpy, root, gc, 150+x+i, 150+y+i, 60+x+i, 130+y+i);
    XDrawLine(dpy, root, gc, 60+x+i, 130+y+i, 150+x+i, 100+y+i);
    //std::string str("OK");
    //XDrawString (dpy, root, gc, 144, 115,  str.c_str(), 2);
}

}}



    XMapWindow(dpy, root);
    XFlush(dpy);
    XCloseDisplay(dpy);
    return 0;
}
