//g++ CleanedUpEnvironment.cpp -o cleanedEnvironment -lsfml-graphics -lsfml-window -lsfml-system
#include <SFML/Graphics.hpp>
#include <string>

struct Textures {
	sf::Texture t1, t2, t3, t4, t5, t6;
	Textures () {
		t1.loadFromFile("blank.png");
		t2.loadFromFile("singleStraightLine.png");
		t3.loadFromFile("doubleStraightLine.png");
		t4.loadFromFile("singleCurve.png");
		t5.loadFromFile("singleCurvedWithDot.png");
		t6.loadFromFile("doubleCurve.png");
	}
};

class Block : public sf::Sprite, Textures{
private:
	#if 0
	int xcoord;
	int ycoord;
	int rotation;
	#endif

public:

	Block(int x=0, int y=0,int texture=1,int rot=0){
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
		this->setOrigin(8,8);
		this->setPosition(8+16*x, 8+16*y);
		//gives an automatic offset for the center of the image as well as shifting by 16 pixels
		this->setRotation(rot);
	}

	//already have setPosition, setRotation, setOrigin, setTexture from parent
	//no other methods are need atm

};

class Environment : public sf::RenderWindow {
private:
	Block * tile[32];
	int offset;
public:
	Environment(int w, int h, std::string t) : offset(8), RenderWindow(sf::VideoMode(w, h),t) {
		//top double straight lines
		for(int i = 0; i < 5; i++) {
			tile[i] = new Block((i+1),0,3);
		}

		//left double straight lines
		for(int i = 5; i < 10; i++) {
			tile[i] = new Block(0,(i-4),3,270);
		}

		//4 outer corners
		tile[10] = new Block(0,0,6,270);
		tile[11] = new Block(6,0,6,0);
		tile[12] = new Block(0,6,6,180);
		tile[13] = new Block(6,6,6,90);

		//bottom double straight lines
		for(int i = 14; i < 19; i++) {
			tile[i] = new Block((i-13),6,3,180);
		}

		//right double straight lines
		for(int i = 19; i < 24; i++) {
			tile[i] = new Block(6,(i-18),3,90);
		}

		//4 inner corners
		tile[24] = new Block(2,2,4,270);
		tile[25] = new Block(4,2,4,0);
		tile[26] = new Block(2,4,4,180);
		tile[27] = new Block(4,4,4,90);

		//4 inner straight lines
		tile[28] = new Block(2,3,2,270);
		tile[29] = new Block(3,2,2,0);
		tile[30] = new Block(3,4,2,180);
		tile[31] = new Block(4,3,2,90);



	}

	void drawEnvironment() {
		for(int i = 0; i < 32; i++)
			this->draw(*tile[i]);
	}



};


int main() {
	int w = 224*2;
	int h = 288*2;

	Environment maze(w,h,"Pacman Bitches");

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