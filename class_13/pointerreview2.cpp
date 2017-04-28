//Legal for each or not legal?
int main() {
	int a[] = {1,3,5,7,9}; //this is ok because if you have the initializer list, it will be that big
	const int b[9] = {5,4,3,1}; //this is also ok. will pad the end with zeros
	const int c[4] = {5,4,3,2,1}; //not ok!! ILLEGAL
	const int* p1 = a; //p1 is promising not to change a. this is ok
	const int* p2 = &a[1]; //this is ok. p2 will point to second spot of a, but can't change
	int* const p3 = &a[2]; //this is ok. p3 is a constant pointer locked onto the number 5 in a
	*p3 = 11; //changes 5 to 11
	const int* const p4 = a + 4; //this is ok. you are pointing to the 9 in a. it's constant pointer and read only
	*p4 = 55; //ILLEGAL can't write to p4;
	p4++; // ILLEGAL 
	p1 = b + 2; //this is ok. you can point to something new, just can't change the value of it
	p2 = p1 + 1;
	p3 = p2 - 1; // ILLEGAL
	cout << *p1 << '\n';
	cout << *p2 << '\n';
	cout << *p3 << '\n';
}