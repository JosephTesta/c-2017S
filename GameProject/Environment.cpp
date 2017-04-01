//g++ Environment.cpp -o environment -lsfml-graphics -lsfml-window -lsfml-system


//testing stuff in this doc. ignore this completely
//don't use this or you're dumb


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
		this->setPosition(x, y);
		this->setRotation(rot);
	}

	//already have setPosition, setRotation, setOrigin, setTexture from parent

};

class Environment : public sf::RenderWindow {
private:
	Block * tile;
public:
	Environment(int w, int h, std::string t) : RenderWindow(sf::VideoMode(w, h),t) {

		tile = new Block(100,100,4);
		//maybe make a new draw method here to overwrite to parent. void draw() {}
		//might need operator overload = for b[1] = Block(200,200,4);

	}

	void drawEnvironment() {
		this->draw(*tile);
	}



};


int main() {

	Block a(100,100,4);
	int w = 224*2;
	int h = 288*2;
	//sf::RenderWindow window(sf::VideoMode(w, h), "Pacman");
	sf::Texture t1, t2, t3, t4, t5, t6, t7, t8;
	t1.loadFromFile("pacman2.jpg");
	t2.loadFromFile("pacman.gif");
	t3.loadFromFile("blank.png");
	t4.loadFromFile("singleStraightLine.png");
	t5.loadFromFile("doubleStraightLine.png");
	t6.loadFromFile("singleCurve.png");
	t7.loadFromFile("singleCurvedWithDot.png");
	t8.loadFromFile("doubleCurve.png");

	sf::Sprite sBackground(t1), sPacman(t2);
	//window.setFramerateLimit(60);

	int x=0,y=0;

	//1008 = 224*2*288*2/(16*16)
	int n = 1008;
	sf::Sprite block[n];
	int offset = 8;
	block[0].setTexture(t8);
	block[0].setOrigin(offset,offset);
	block[0].setPosition(offset, offset);
	block[0].setRotation(270);

	for(int i = 1;i <= 12;i++) {
	    block[i].setTexture(t5);
	    block[i].setOrigin(offset,offset);
	    block[i].setPosition(16*i+offset,offset);
	}


    #if 0
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
		// Request for closing the window
			if (event.type == sf::Event::Closed)
			   window.close();
			}

		window.clear();
		//window.draw(sBackground);
		for (int i=0;i<n;i++)
     		window.draw(block[i]);
     	window.draw(a);

		sPacman.setPosition(x++,y++);
		window.draw(sPacman);
		window.display();
	}
	#endif

	Environment maze(w,h,"Pacman from class");

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