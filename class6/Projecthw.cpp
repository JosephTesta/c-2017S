class Newton3d { //example of a project. code in rpositor with classes. empty methods are fine. focuse on the public stuff. comment what each purpose it one line. @author: Dov Kruger. each in it's own header file/
private:
	static const double G = ....;
	double m;
	Vec3d x;
	double r;
public:
	construcotr...

	void accel(Newton3d other) {}



}

class System {
private:
	vector<Newton3d> bodies;
public:
	System(...)

};