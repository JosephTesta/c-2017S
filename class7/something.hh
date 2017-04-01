
String::String(String&& orig) : //notice don't use const since you change it's pointer
	p(orig.p), len(orig.len), capacity(orig.capacity)
{
	orig.p = nullptr;
}

String f() {
	String s1(100000); //asfk for 100,000 bytes. bad to copy this
	return s1;
}