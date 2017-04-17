//these operations such as the dividing are faster than regular dividing
int main() {
	//32 bit operations for any int

	int a = 3 & 5; //bitwise AND 000000011 & 0000000101
	//0000000011
	//0000000101
	//============
	//0000000001 = 1

	int b = 3 | 5; //bitwise OR
	//0000000011
	//0000000101
	//============
	//0000000111 = 7

	int c = 3 ^ 5; //bitwise XOR
	//0000000011
	//0000000101
	//============
	//0000000110 = 6

	int d = ~3; // NOT
	//00000000000000000000000000000011
	//11111111111111111111111111111100

	int e = 1 << 5; // left shift equivalent to mult by 2 to the k. mult by 2^5 = 32 
	// 00000000000000000001
	// 00000000000000100000

	int f = 1024 >> 3 // right shift equivalent to /3 to the k

	// 000000000000010000000000
	// 000000000000000010000000

	int g = 5;
	g <<= 2; 

	//there are 12 op= types += -= *= /= %= &= |= ^= <<= >>= and some 2 others
	// x = x OP y ==> x OP= y

	int x = 192;
	const int m = 16*1024*1024/3;
	x /= 3; //compiler might do x* m >> 24

}