//these 2 functions are identical

void f(int* const x) { //this one x can change unless you have the const

}

void g(int x[]) {
	
}

int main() {
	int a = 2; // best style, always initialize
	int* p = &a; //in this context &a is address of a. p points to a

	const int* q = &a; //means q is a pointer to an int that is constant. Read only pointer
	//this is legal. q says I promise not to change a. 
	//CANT say *q = 5. q is a read only pointer

	int * const r = &a; //r is a constant pointer to integer.points to one place only. 
	//r can change a. *r = 19; is fine
	//CANT do r = &b; r is not allowed to point to anything else

	int x[10] = {5}; //5 0 0 0 0 0 0 0 0 0
	//x is pointing to the beginning at the 5. you can change x[5] = 11;
	//CANT say x = r; arrays are constant pointers like r

	const int* const s = x; 
	// s CANT write to the array x
	// s CANT point to anything else

	const int y[10] = {2,1,0}; // 2 1 0 0 0 0 0 0 0 0
	// y is also a cont int* const pointer like s

	//the only difference between an array and pointer is that an array allocates space
}