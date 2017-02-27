extern int x; //declares that somewhere x exists
extern int x; //declares that somewhere x exists
extern int x; //declares that somewhere x exists. many declarations. one definition
int x=3; //defines x as a variable

int main() {

	int x = 4; //definition: only once. can only defines once but you can declare multiple times
	//int x; //illegal
	if(2<3) {
		int x = 5; //declared in the if scope, only in if scope
		cout << x; //uses most local x
	}
	cout << x;
	cout << ::x;
}