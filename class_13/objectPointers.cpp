class Node {
	int v;
	Node* next;
};

class A{
public:
	int x, y, z;
}

void f(A* p, int A::*member) {
	p->*member = 0; //relative pointer
}

void g(A a1, int A::*member) {
	a1.*member = 0; //relative object
}

int main() {
	Node* p = new Node();
	(*p).v = 5;
	(*p).next = nullptr;
	p->v = 5;//same as (*p).v = 5
	int *q = &a;//simple pointer won't have q->. only for pointer to object
	p->next = nullptr;


	A a1;
	a1.x = 2;
	a1.y = 3;
	f(*a1, &A::x); //write to the x value making it zero through the function f
	f(*a1, &A::y); //write to the y of a1 to make it 0


}