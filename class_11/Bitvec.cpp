Bitcev primes(1000000000); //1 billion bytes is big! 125Mb is a lot better

//00000000000000000000000000000000000000000000000000000000000000000000000000000000

class BitVec {
private:
	uint64_t* bits;
	uint32_t size;

public:
	BitVec(uint32_t size) : bits(new uint64_t[(size+63)/64]) {//up to 4 billions bytes. positive number of bits. rounds up automatically by +63

	}

//do all the constr, copy constr, destruc, operator =

void set(uint32_t index) {} //make 1
void clear(uint32_t index) {} //make a bit 0
void toggle(uint32_t index) {}
bool isSet(uint32_t index) {}

};

#if 0
bit 0 is the rightmost bit
	000000000000000000000000000000000000000000000000000

	000000000000000000000000000000000000000000000000001
	
	left shift if we want it in the kth position. it start is position 0
	1 << k
	1 << 3
	000000000000000000000000000000000000000000000001000
	

	you already have bits there

	101011100001101010001110111000101X11110100011010001
	000000000000000000000000000000000100000000000000000
	OR the original with your correct position 
	101011100001101010001110111000101111110100011010001

	x = x | (1 << k) or use x |= 1 << k

	how to do this with an array?
	bit = 100000; //how to split this into which word, which bit within?
	i = bit / 64;
	k = bit % 64;
	x[ i ] |= 1 << k

	2^10
	10000000000 = 1024 			/ 64 = 16
	>> 6
	10000 = 16

	64 = 1000000 		63 = 0111111

	10000000000
	00000111111 AND
	00000000000

	10000000011 = 1027
	00000111111 AND
	00000000011 = 3

	x[ind >> 6] |= << (ind & 63)




	For clearing
	and with the inverse
	& 	~(1 << k) CLEAR


	For flipping bit
	^		(1 << k) TOGGLE


	test 		return bits[i] & (1 << k) != 0	then the bool is true. true or false
#endif