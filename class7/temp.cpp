//g++ map.cpp -o map -lsfml-graphics -lsfml-window -lsfml-system
//backup for the complete map
#include <SFML/Graphics.hpp>
#include <string>

struct Textures {
	sf::Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
	Textures () {
		t1.loadFromFile("images/blank.png");
		t2.loadFromFile("images/singleStraightLine.png");
		t3.loadFromFile("images/doubleStraightLine.png");
		t4.loadFromFile("images/singleCurve.png");
		t5.loadFromFile("images/singleCurvedWithDot.png");
		t6.loadFromFile("images/doubleCurve.png");
		t7.loadFromFile("images/curveWithTopStraight.png");
		t8.loadFromFile("images/curveWithRightStraight.png");
		t9.loadFromFile("images/ghostHouseDoor.png");
		t10.loadFromFile("images/doubleStraightLineClosedEdge.png");
		t11.loadFromFile("images/doubleStraightLineClosedEdgeRightSide.png");

	}
};

class Block : public sf::Sprite, Textures{
private:
	#if 1
	int xcoord;
	int ycoord;
	int rotation;
	int texture;
	#endif

public:

	Block(int x=0, int y=0,int texture=1,int rot=0) : xcoord(x), ycoord(y), texture(texture), rotation(rot){
		if(texture == 1)
			this->setTexture(t1);
		if(texture == 2)
			this->setTexture(t2);
		if(texture == 3)
			this->setTexture(t3);
		if(texture == 4)
			this->setTexture(t4);
		if(texture == 5)
			this->setTexture(t5);
		if(texture == 6)
			this->setTexture(t6);
		if(texture == 7)
			this->setTexture(t7);
		if(texture == 8)
			this->setTexture(t8);
		if(texture == 9)
			this->setTexture(t9);
		if(texture == 10)
			this->setTexture(t10);
		if(texture == 11)
			this->setTexture(t11);
		this->setOrigin(8,8);
		this->setPosition(8+16*x, 8+16*y);
		//gives an automatic offset for the center of the image as well as shifting by 16 pixels
		this->setRotation(rot);
	}

	Block* mirror(int xMax) {
		int tempRotation = 0;
		int tempTexture = this->texture;
		if(this->rotation == 0 || this->rotation == 180) {
			tempRotation = 0;
		}
		if(this->rotation == 90) {
			tempRotation = 0;
		}
		if(this->rotation == 270) {
			tempRotation = 180;
		}
		if(this->texture == 4) {
			tempRotation = 270;
		}
		
		if(this->texture == 5) {
			tempRotation = 270;
		}
		if(this->texture == 6) {
			tempRotation = 270;
		}

		//manually rotate the ones I couldn't account for
		if((xcoord == 0 && ycoord == 0)||(xcoord == 2 && ycoord == 2)||(xcoord == 5 && ycoord == 4)||(xcoord == 7 && ycoord == 2)||(xcoord == 11 && ycoord == 4)||
			(xcoord == 10 && ycoord == 6)||(xcoord == 7 && ycoord == 6)||(xcoord == 2 && ycoord == 6)||(xcoord == 5 && ycoord == 7)||
			(xcoord == 11 && ycoord == 10)||(xcoord == 8 && ycoord == 10)||(xcoord == 8 && ycoord == 13)||(xcoord == 5 && ycoord == 13)||
			(xcoord == 7 && ycoord == 15)||(xcoord == 10 && ycoord == 12)||(xcoord == 8 && ycoord == 19)||(xcoord == 10 && ycoord == 18)||
			(xcoord == 5 && ycoord == 19)||(xcoord == 0 && ycoord == 19)||(xcoord == 11 && ycoord == 22)||(xcoord == 7 && ycoord == 21)||
			(xcoord == 10 && ycoord == 24)||(xcoord == 2 && ycoord == 21)||(xcoord == 7 && ycoord == 24)||(xcoord == 7 && ycoord == 27)||
			(xcoord == 11 && ycoord == 28)||(xcoord == 2 && ycoord == 27)||(xcoord == 5 && ycoord == 25)||(xcoord == 2 && ycoord == 25)) {
			tempRotation += 180;
		}

		//change textures of some
		if((xcoord == 13 && ycoord == 0)){
			texture = 8;
			tempRotation -= 90;
		}

		if((xcoord == 0 && ycoord == 24)){
			texture = 7;
			tempRotation -= 90;
		}

		if((xcoord == 0 && ycoord == 25)){
			texture = 8;
			tempRotation -= 90;
		}

		if((xcoord == 12 && ycoord == 12)){
			texture = 11;
		}
		Block * BlockPointer;
		BlockPointer = new Block(xMax-this->xcoord,this->ycoord, texture, this->rotation + tempRotation);
		return BlockPointer;
	}

	//already have setPosition, setRotation, setOrigin, setTexture from parent
	//no other methods are need atm

};

class Environment : public sf::RenderWindow {
private:
	Block * tile[484];
	int offset;
	int xMax;
public:
	Environment(int w, int h, std::string t) : offset(8), RenderWindow(sf::VideoMode(w, h),t), xMax(w/16 - 1) {
		
		// left half of board is made here
		// mirroring could duplicate left half of map to create right half
		// tile placement begins from top right middle and ends at bottom right middle

		//////////////////////////////////////////
		///////LEFT HALF'S EDGE WALLS/////////////
		//////////////////////////////////////////

		// central top jut out
		// middle single curve
		tile[0] = new Block(13,4,4,180);
		// single straight lines
		for(int i = 1; i < 4; i++) {
			tile[i] = new Block(13,i,2,90);
		}
		// top straight line with curve
		tile[4] = new Block(13,0,7,0);


		//top double straight lines
		for(int i = 5; i < 17; i++) {
			tile[i] = new Block((i-4),0,3);
		}
		// top left double line corner
		tile[17] = new Block(0,0,6,270);

		// left double straight lines
		for(int i = 18; i < 26; i++) {
			tile[i] = new Block(0,(i-17),3,270);
		}

		// bottom left corner above tunnel
		tile[26] = new Block(0,9,6,180);

		// bottom double straight lines above tunnel
		for(int i = 27; i < 31; i++) {
			tile[i] = new Block((i-26),9,3,180);
		}

		// bottom right dot corner above tunnel
		tile[31] = new Block(5,9,5,0);		

		// right double straight lines above tunnel
		for(int i = 32; i < 35; i++) {
			tile[i] = new Block(5,(i-22),3,270);
		}

		// bottom right dot corner above tunnel
		tile[35] = new Block(5,13,5,90);

		// top double straight lines above tunnel
		for(int i = 36; i < 41; i++) {
			tile[i] = new Block((i-36),13,3,0);
		}

		// top double straight lines below tunnel
		for(int i = 41; i < 46; i++) {
			tile[i] = new Block((i-41),15,3,180);
		}

		// top right dot corner below tunnel
		tile[46] = new Block(5,15,5,0);

		// right double straight lines below tunnel
		for(int i = 47; i < 50; i++) {
			tile[i] = new Block(5,(i-31),3,270);
		}
		
		// bottom right dot corner below tunnel
		tile[50] = new Block(5,19,5,90);

		// middle double straight lines below tunnel
		for(int i = 51; i < 55; i++) {
			tile[i] = new Block((i-50),19,3,0);
		}

		// left dot corner below tunnel
		tile[55] = new Block(0,19,6,270);

		// left double straight lines below tunnel
		for(int i = 56; i < 60; i++) {
			tile[i] = new Block(0,(i-36),3,270);
		}

		// bottom jut out
		// right straight line with curve
		tile[60] = new Block(0,24,8,180);
		// top single straight line
		tile[61] = new Block(1,24,2,0);
		// top single curve
		tile[62] = new Block(2,24,4,0);
		// bottom single curve
		tile[63] = new Block(2,25,4,90);
		// bottom single straight line
		tile[64] = new Block(1,25,2,180);
		// top straight line with curve
		tile[65] = new Block(0,25,7,270);

		// left double straight lines below tunnel and jut out
		for(int i = 66; i < 71; i++) {
			tile[i] = new Block(0,(i-40),3,270);
		}

		// bottom left double line corner
		tile[70] = new Block(0,30,6,180);

		// bottom double straight lines
		for(int i = 71; i < 84; i++) {
			tile[i] = new Block((i-70),30,3,180);
		}



		//////////////////////////////////////////
		///////LEFT HALF'S INNER WALLS/////////////
		//////////////////////////////////////////

		// top left inner box
		// top left corner
		tile[84] = new Block(2,2,4,270);
		// top right corner
		tile[85] = new Block(5,2,4,0);
		// bottom left corner
		tile[86] = new Block(2,4,4,180);
		// bottom right corner
		tile[87] = new Block(5,4,4,90);
		// left wall
		tile[88] = new Block(2,3,2,90);
		// right wall
		tile[89] = new Block(5,3,2,90);
		// top wall
		for(int i = 90; i < 92; i++) {
			tile[i] = new Block((i-87),2,2,180);
		}
		// bottom wall
		for(int i = 92; i < 94; i++) {
			tile[i] = new Block((i-89),4,2,180);
		}


		// top right inner box (of left half of map)
		// top left corner
		tile[94] = new Block(7,2,4,270);
		// top right corner
		tile[95] = new Block(11,2,4,0);
		// bottom left corner
		tile[96] = new Block(7,4,4,180);
		// bottom right corner
		tile[97] = new Block(11,4,4,90);
		// left wall
		tile[98] = new Block(7,3,2,90);
		// right wall
		tile[99] = new Block(11,3,2,90);
		// top wall
		for(int i = 100; i < 103; i++) {
			tile[i] = new Block((i-92),2,2,180);
		}
		// bottom wall
		for(int i = 103; i < 106; i++) {
			tile[i] = new Block((i-95),4,2,180);
		}


		// top half's bottom left box (of left half of map)
		// top left corner
		tile[106] = new Block(2,6,4,270);
		// top right corner
		tile[107] = new Block(5,6,4,0);
		// bottom left corner
		tile[108] = new Block(2,7,4,180);
		// bottom right corner
		tile[109] = new Block(5,7,4,90);
		// left wall
		tile[110] = new Block(2,3,2,90);
		// right wall
		tile[111] = new Block(5,3,2,90);
		// top wall
		for(int i = 112; i < 114; i++) {
			tile[i] = new Block((i-109),6,2,180);
		}
		// bottom wall
		for(int i = 114; i < 116; i++) {
			tile[i] = new Block((i-111),7,2,180);
		}


		// center structure that resembles a rotated "T"
		// top left corner
		tile[116] = new Block(7,6,4,270);
		// top right corner
		tile[117] = new Block(8,6,4,0);
		// left wall
		for (int i = 118; i < 124; i++) {
			tile[i] = new Block(7,(i-111),2,90);
		}
		// bottom left corner
		tile[124] = new Block(7,13,4,180);
		// bottom right corner
		tile[125] = new Block(8,13,4,90);
		// right wall going up from bottom right corner
		for (int i = 126; i < 128; i++) {
			tile[i] = new Block(8,(i-115),2,90);
		}
		// jut out
		// bottom turn corner
		tile[128] = new Block(8,10,4,270);
		// bottom wall of jut out
		for(int i = 129; i < 131; i++) {
			tile[i] = new Block((i-120),10,2,180);
		}
		// bottom right upturn corner
		tile[131] = new Block(11,10,4,90);
		// top right upturn corner
		tile[132] = new Block(11,9,4,0);
		// top line of jut out
		for(int i = 133; i < 135; i++) {
			tile[i] = new Block((i-124),9,2,180);
		}
		// top left curve upturn connecting jut out
		tile[135] = new Block(8,9,4,180);
		//end of jut out
		// right wall going up from jut out
		for (int i = 136; i < 138; i++) {
			tile[i] = new Block(8,(i-129),2,90);
		}


		// top half's center structure that resembles a "T"
		// top line
		for(int i = 138; i < 141; i++) {
			tile[i] = new Block((i-127),6,2,180);
		}
		// top left corner
		tile[141] = new Block(10,6,4,270);
		// mid-bottom left corner
		tile[142] = new Block(10,7,4,180);
		// bottom wall
		for(int i = 143; i < 145; i++) {
			tile[i] = new Block((i-132),7,2,180);
		}
		// downturn corner
		tile[145] = new Block(13,7,4,0);
		// left wall
		for (int i = 146; i < 148; i++) {
			tile[i] = new Block(13,(i-138),2,90);
		}
		// bottom left corner
		tile[148] = new Block(13,10,4,180);


		// Ghost House
		// ghost door
		tile[149] = new Block(13,12,9,0);
		// double straight line with closed edge
		tile[150] = new Block(12,12,10,0);
		// top double straight wall
		tile[151] = new Block(11,12,3,0);
		// top left corner
		tile[152] = new Block(10,12,6,270);
		// left wall
		for(int i = 153; i < 156; i++) {
			tile[i] = new Block(10,(i-140),3,270);
		}
		// bottom left corner
		tile[156] = new Block(10,16,6,180);
		// bottom wall
		for(int i = 157; i < 160; i++) {
			tile[i] = new Block((i-146),16,3,180);
		}

		////// bottom half inner walls //////


		// structure that resembles "l"
		// top left corner
		tile[160] = new Block(7,15,4,270);
		// top right corner
		tile[161] = new Block(8,15,4,0);
		// left wall
		for (int i = 162; i < 165; i++) {
			tile[i] = new Block(7,(i-146),2,90);
		}
		// bottom left corner
		tile[165] = new Block(7,19,4,180);
		// bottom right corner
		tile[166] = new Block(8,19,4,90);
		// right wall going up from bottom right corner
		for (int i = 167; i < 170; i++) {
			tile[i] = new Block(8,(i-151),2,90);
		}


		// bottom half's top center structure that resembles a "T"
		// top line
		for(int i = 170; i < 173; i++) {
			tile[i] = new Block((i-159),18,2,180);
		}
		// top left corner
		tile[173] = new Block(10,18,4,270);
		// mid-bottom left corner
		tile[174] = new Block(10,19,4,180);
		// bottom wall
		for(int i = 175; i < 177; i++) {
			tile[i] = new Block((i-164),19,2,180);
		}
		// downturn corner
		tile[177] = new Block(13,19,4,0);
		// left wall
		for (int i = 178; i < 180; i++) {
			tile[i] = new Block(13,(i-158),2,90);
		}
		// bottom left corner
		tile[180] = new Block(13,22,4,180);


		// structure that resembles a rotated "L"
		// top left corner
		tile[181] = new Block(2,21,4,270);
		// bottom left corner
		tile[182] = new Block(2,22,4,180);
		// bottom wall
		tile[183] = new Block(3,22,2,180);
		// downturn corner
		tile[184] = new Block(4,22,4,0);
		// left wall
		for (int i = 185; i < 187; i++) {
			tile[i] = new Block(4,(i-162),2,90);
		}
		// bottom left corner
		tile[187] = new Block(4,25,4,180);
		// bottom right corner
		tile[188] = new Block(5,25,4,90);
		// right wall
		for (int i = 189; i < 192; i++) {
			tile[i] = new Block(5,(i-167),2,90);
		}
		// top right corner
		tile[192] = new Block(5,21,4,0);
		// top wall
		for(int i = 193; i < 195; i++) {
			tile[i] = new Block((i-190),21,2,180);
		}


		// structure that resembles a rotated "l"
		// top left corner
		tile[195] = new Block(7,21,4,270);
		// top right corner
		tile[196] = new Block(11,21,4,0);
		// bottom left corner
		tile[197] = new Block(7,22,4,180);
		// bottom right corner
		tile[198] = new Block(11,22,4,90);
		// top wall
		for(int i = 199; i < 202; i++) {
			tile[i] = new Block((i-191),21,2,180);
		}
		// bottom wall
		for(int i = 202; i < 205; i++) {
			tile[i] = new Block((i-194),22,2,180);
		}


		// structure at bottom left of map
		// center top left corner
		tile[205] = new Block(7,24,4,270);
		// left wall
		for (int i = 206; i < 208; i++) {
			tile[i] = new Block(7,(i-181),2,90);
		}
		// downturn corner
		tile[208] = new Block(7,27,4,90);
		// left top wall
		for(int i = 209; i < 213; i++) {
			tile[i] = new Block((i-206),27,2,180);
		}
		// bottom top left corner
		tile[213] = new Block(2,27,4,270);
		// bottom left corner
		tile[214] = new Block(2,28,4,180);
		// bottom wall
		for(int i = 215; i < 223; i++) {
			tile[i] = new Block((i-212),28,2,180);
		}
		// right bottom corner
		tile[223] = new Block(11,28,4,90);
		// top right corner
		tile[224] = new Block(11,27,4,0);
		// right top wall
		for(int i = 225; i < 227; i++) {
			tile[i] = new Block((i-216),27,2,180);
		}
		// right upturn corner
		tile[227] = new Block(8,27,4,180);
		// right wall
		for (int i = 228; i < 230; i++) {
			tile[i] = new Block(8,(i-203),2,90);
		}
		// top right corner
		tile[230] = new Block(8,24,4,0);


		// bottom half's bottom center structure that resembles a "T"
		// top line
		for(int i = 231; i < 234; i++) {
			tile[i] = new Block((i-220),24,2,180);
		}
		// top left corner
		tile[234] = new Block(10,24,4,270);
		// mid-bottom left corner
		tile[235] = new Block(10,25,4,180);
		// bottom wall
		for(int i = 236; i < 238; i++) {
			tile[i] = new Block((i-225),25,2,180);
		}
		// downturn corner
		tile[238] = new Block(13,25,4,0);
		// left wall
		for (int i = 239; i < 241; i++) {
			tile[i] = new Block(13,(i-213),2,90);
		}
		// bottom left corner
		tile[241] = new Block(13,28,4,180);

		for(int i = 242; i < 484; i++) {
			tile[i] = tile[i-242]->mirror(xMax);
		}








		//////////////////////////////////////////
		///////RIGHT HALF'S EDGE WALLS////////////
		//////////////////////////////////////////
#if 0
		// central top jut out
		// middle single curve
		tile[242] = new Block(27-13,4,4,90);
		// single straight lines
		for(int i = 243; i < 246; i++) {
			tile[i] = new Block((27-13),(i-242),2,90);
		}
		// right straight line with curve
		tile[246] = new Block((27-13),0,8,270);

		//top double straight lines
		for(int i = 247; i < 259; i++) {
			tile[i] = new Block((i-232),0,3);
		}
		// top right double line corner
		tile[259] = new Block((27-0),0,6,0);

		// right double straight lines
		for(int i = 260; i < 268; i++) {
			tile[i] = new Block((27-0),(i-259),3,90);
		}

		// bottom left corner above tunnel
		tile[268] = new Block((27-0),9,6,90);

		// bottom double straight lines above tunnel
		for(int i = 269; i < 273; i++) {
			tile[i] = new Block((i-246),9,3,180);
		}

		// bottom left dot corner above tunnel
		tile[273] = new Block((27-5),9,5,270);		

		// left double straight lines above tunnel
		for(int i = 274; i < 277; i++) {
			tile[i] = new Block((27-5),(i-264),3,90);
		}

		// bottom left dot corner above tunnel
		tile[277] = new Block((27-5),13,5,180);

		// top double straight lines above tunnel
		for(int i = 278; i < 283; i++) {
			tile[i] = new Block((i-255),13,3,0);
		}
#endif

/*

		// top double straight lines below tunnel
		for(int i = 41; i < 46; i++) {
			tile[i] = new Block((i-41),15,3,180);
		}

		// top right dot corner below tunnel
		tile[46] = new Block(5,15,5,0);

		// right double straight lines below tunnel
		for(int i = 47; i < 50; i++) {
			tile[i] = new Block(5,(i-31),3,270);
		}
		
		// bottom right dot corner below tunnel
		tile[50] = new Block(5,19,5,90);

		// middle double straight lines below tunnel
		for(int i = 51; i < 55; i++) {
			tile[i] = new Block((i-50),19,3,0);
		}

		// left dot corner below tunnel
		tile[55] = new Block(0,19,6,270);

		// left double straight lines below tunnel
		for(int i = 56; i < 60; i++) {
			tile[i] = new Block(0,(i-36),3,270);
		}
*/
/*
		// bottom jut out
		// right straight line with curve
		tile[60] = new Block(0,24,8,180);
		// top single straight line
		tile[61] = new Block(1,24,2,0);
		// top single curve
		tile[62] = new Block(2,24,4,0);
		// bottom single curve
		tile[63] = new Block(2,25,4,90);
		// bottom single straight line
		tile[64] = new Block(1,25,2,180);
		// top straight line with curve
		tile[65] = new Block(0,25,7,270);

		// left double straight lines below tunnel and jut out
		for(int i = 66; i < 71; i++) {
			tile[i] = new Block(0,(i-40),3,270);
		}

		// bottom left double line corner
		tile[70] = new Block(0,30,6,180);

		// bottom double straight lines
		for(int i = 71; i < 84; i++) {
			tile[i] = new Block((i-70),30,3,180);
		}

*/



	}

	void drawEnvironment() {
		for(int i = 0; i < 484; i++)
			this->draw(*tile[i]);
	}



};


int main() {

	int w = 224*2;
	int h = 288*2;

	Environment maze(w,h,"Pacman");
	maze.setVerticalSyncEnabled(false);
	maze.setFramerateLimit(60);

	while (maze.isOpen()) {
		sf::Event event2;
		while (maze.pollEvent(event2)) {
		// Request for closing the window
			if (event2.type == sf::Event::Closed)
			   maze.close();
		}
		maze.clear();
   		//maze.draw(a);
		maze.drawEnvironment();
		maze.display();
	}


	return 0;
}