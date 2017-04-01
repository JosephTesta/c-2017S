void h(int x) {
	x += 2;
	cout << x;
}

int main() {
	int x = 2;
	for (int i =1; i <= 4; i++)
		h(x);
}