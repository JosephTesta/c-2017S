/*
00000000000000000000000000000000000
00000000000000000000000000000000000
00000000001100000000011000000000000
00000000001100000000011000000000000
00000000000000000000000000000000000
00000000000000001000000000000000000
00000000000000001000000000000000000
00000000000000000000000000000000000
00000000000001000000010000000000000
00000000000000111111100000000000000
00000000000000000000000000000000000
00000000000000000000000000000000000

example of what we are doing. 
for now we will do a fixed size bitmap. we aren't ready for dynamic
*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
//#include <dos.h>
using namespace std;

class Bitmap {
private:
	enum { ROWS = 30, COLS = 40 };
	//const would work instead of enum
	int a[ROWS][COLS];

public:
	Bitmap() {
		for(int i = 0; i < ROWS; i++) 
			for(int j = 0; j < COLS; j++)
				a[i][j] = 0;
	}

	Bitmap(int fillNumber) {
		for(int i = 0; i < ROWS; i++) 
			for(int j = 0; j < COLS; j++)
				a[i][j] = fillNumber;
	}


	void horizLine(int row, int col1, int col2, int fillNumber) { //row a col b to c
		int i = row;
		for(int j = col1; j < col2; j++)
			a[i][j] = fillNumber;
	}

	void vertLine(int col, int row1, int row2, int fillNumber) {
		int j = col;
		for (int i = row1; i < row2; i++)
			a[i][j] = fillNumber;
	}

	void rect(int x, int y, int w, int h, int fillNumber) {
		for(int i = y; i < y+h; i++) 
			for(int j = x; j < x+h; j++)
				a[i][j] = fillNumber;
	}

	void putpixel(int x, int y,int fillNumber) {
		a[y][x] = fillNumber;
	}


	//line function adapted from: http://www.etechplanet.com/codesnippets/computer-graphics-draw-a-line-using-bresenham-algorithm.aspx
	void line(int x1,int y1,int x2,int y2,int c)
	{
	 int x,y,dx,dy,dx1,dy1,px,py,xe,ye,i;
	 dx=x2-x1;
	 dy=y2-y1;
	 dx1=fabs(dx);
	 dy1=fabs(dy);
	 px=2*dy1-dx1;
	 py=2*dx1-dy1;
	 if(dy1<=dx1)
	 {
	  if(dx>=0)
	  {
	   x=x1;
	   y=y1;
	   xe=x2;
	  }
	  else
	  {
	   x=x2;
	   y=y2;
	   xe=x1;
	  }
	  putpixel(x,y,c);
	  for(i=0;x<xe;i++)
	  {
	   x=x+1;
	   if(px<0)
	   {
	    px=px+2*dy1;
	   }
	   else
	   {
	    if((dx<0 && dy<0) || (dx>0 && dy>0))
	    {
	     y=y+1;
	    }
	    else
	    {
	     y=y-1;
	    }
	    px=px+2*(dy1-dx1);
	   }
	   //delay(0);
	   putpixel(x,y,c);
	  }
	 }
	 else
	 {
	  if(dy>=0)
	  {
	   x=x1;
	   y=y1;
	   ye=y2;
	  }
	  else
	  {
	   x=x2;
	   y=y2;
	   ye=y1;
	  }
	  putpixel(x,y,c);
	  for(i=0;y<ye;i++)
	  {
	   y=y+1;
	   if(py<=0)
	   {
	    py=py+2*dx1;
	   }
	   else
	   {
	    if((dx<0 && dy<0) || (dx>0 && dy>0))
	    {
	     x=x+1;
	    }
	    else
	    {
	     x=x-1;
	    }
	    py=py+2*(dx1-dy1);
	   }
	   //delay(0);
	   putpixel(x,y,c);
	  }
	 }
	}


	friend ostream& operator <<(ostream& s, Bitmap someBitmap) { //s is cout
		for(int i = 0; i < someBitmap.ROWS; i++) {
			for(int j = 0; j < someBitmap.COLS; j++)
				s << someBitmap.a[i][j];
			s << endl;
		}
		return s;
	}

};

int main() {
	Bitmap b1;
	Bitmap b2(3);
	// no sizes yet...	Bitmap b3(100,200);
	// each method has a last parameter (color) which is an integer (32-bit)
	b2.horizLine(5, 1, 27, 99); // row=5, col 1 to 27, set every pixel to 99
	b2.vertLine(19, 5, 20, 45); // col 19, row 5 to 20, set every pixel to 45
 	b2.rect(9,9, 5, 8, 205); // x=9, y = 9, w=5, h=8, set every pixel to 205
	b2.line(28, 7, 8, 25, 92); // diagonal line using Bresenham, set every pixel to 92
	cout << b2;
}