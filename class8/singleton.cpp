class Singleton {
private:
	Singleton() { }
public:
	static makeMe() {
		if (p == nullptr)
			p = new Singleton();
	}

};


int main(){
	Singleton* p = nullptr;
}

//we are making Singleton a, b, c; illegal
//static function takes place of the constructor
