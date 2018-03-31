#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int checkPrimitive(int times, int size);
int checkSmart(int times, int size);



int* buildPlayBoard(int size) {  
	int *arr;
	int car;
	arr = new int[size];
	srand((unsigned)time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
	car = rand() % size + 1;
	arr[car] = 1;
	return arr;
}

bool primitiveMethod(int *arr, int size) {
	srand((unsigned)time(0));

	int pick = rand() % size + 1;  // choose a door and dont change
	if (arr[pick] == 1) {

		return true;
	}
	else {
		return false;
	}
}

bool smartMethod(int *arr, int size) {
	srand((unsigned)time(0));
	int firstPick; 
	int secondPick;
	int montyPick;

	firstPick = secondPick = montyPick = rand() % size + 1;


	while (arr[montyPick] != 1 && montyPick != firstPick){
		montyPick = rand() % size + 1;
	}
	while((secondPick!=montyPick)&&(secondPick!=firstPick)){   // the player is changing to another door
	secondPick = rand() % size + 1;
	}
	if (arr[secondPick] == 1) {
		return true;
	}
	else {
		return false;
	}
}

int checkPrimitive(int times, int size) {
	int count = 0;
	int *arr;
	for (int i = 0; i < times; i++) {
		arr = buildPlayBoard(size);
		if (primitiveMethod(arr, size) == true) {
			count++;
		}

	}
	return count;
}
int checkSmart(int times, int size) {
	int count = 0;
	int *arr;
	for (int i = 0; i < times; i++) {
		arr = buildPlayBoard(size);
		if (smartMethod(arr, size) == true) {
			count++;
		}
	}
	return count;
}

void main() {
	srand((unsigned)time(0));
	int times = 1000;
	int size = 3;
	int	primitvePlayerWins =  checkPrimitive(times, size); 
	int	smartPlayerWins = checkSmart(times , size);

	cout << "Primitive player won : " << primitvePlayerWins << " times" << endl;
	cout << "Smart player won : " << smartPlayerWins << " times" << endl;
	system("pause");

}





