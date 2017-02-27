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

class Bitmap {
private:
	enum { ROWS = 30, COLS = 40 };
	//const would work instead of enum
	int a[ROWS][COLS];

public:
	Bitmap() {
		for(int i = 0; i < ROW; i++) 
			for(int j = 0; j < COLS; j++)
				a[i][j] = 0;
	}

};

int main() {
	Bitmap b1;
	Bitmap b2(3); //b cant be const since we are changing it with horizLine and vertLine
	Bitmap b3(100,200);
	b2.horizLine(5, 1, 27); //row5, col 1 to 27
	b2.vertLine(19, 5, 20); //col 19, row 5 to 20
	b2.rect(9,9, 5, 8); //x = 9, y = 9, w = 5, h = 8
	b2.line(28, 7, 8, 25) //diagonal line using Bresenham
	//needs to be able to print also
	return 0;
}