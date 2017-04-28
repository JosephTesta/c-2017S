//00000000000000000000000000000000000000000000000000000000000000000000000000000000
#ifndef BITVEC_HH_
#define BITVEC_HH_

#include <cstdint>
#include <iostream>

class BitVec {
private:
	uint64_t* bits;
	uint32_t size;

public:
	BitVec(uint32_t size) : bits(new uint64_t[(size+63)/64]) {//up to 4 billions bytes. positive number of bits. rounds up automatically by +63
		this->size = (size+63)/64;
	}

	~BitVec() {
		delete [] bits;
	}

	BitVec(const BitVec& orig) {
		size = orig.size;
		bits = new uint64_t[size];
		for (int i = 0; i < size; i++) {
			bits[i] = orig.bits[i];
		}
	}

	BitVec& operator =(const BitVec& orig) {
		if(this != &orig) {
			delete [] bits;
			size = orig.size;
			bits = new uint64_t[size];
			for (int i = 0; i < size; i++) {
				bits[i] = orig.bits[i];
			}
		}
		return *this;
	}
	

//do all the constr, copy constr, destruc, operator =

	void set(uint32_t index) { //make 1. OR
		uint32_t index2 = index % 64;
		uint64_t temp = 1;
		temp <<= index2;
		bits[size-(index/64)-1] |= temp;
		//std::cout << bits[2] << ' ' << bits[1] << ' ' << bits[0] << std::endl;
	} 

	void clear(uint32_t index) { //make a bit 0. AND with inverse
		uint32_t index2 = index % 64;
		uint64_t temp = 1;
		temp = ~temp;
		temp <<= index2;
		bits[size-(index/64)-1] &= temp;
		//std::cout << bits[2] << ' ' << bits[1] << ' ' << bits[0] << std::endl;
	}

	void toggle(uint32_t index) { //swap bit. XOR
		uint32_t index2 = index % 64;
		uint64_t temp = 1;
		temp <<= index2;
		bits[size-(index/64)-1] ^= temp;
		//std::cout << bits[2] << ' ' << bits[1] << ' ' << bits[0] << std::endl;
	}
	bool isSet(uint32_t index) {
		uint32_t index2 = index % 64;
		uint64_t temp = 1;
		temp <<= index2;
		if ((bits[size-(index/64)-1] & temp) == temp) {
			//std::cout << "true" << std::endl;
			return true;
		}
		//std::cout << "false" << std::endl;
		return false;
	}



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

#endif