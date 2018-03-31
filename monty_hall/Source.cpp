#include <iostream>
#include <time.h>
///
using namespace std;

int checkSmart(int times, int size);
int checkPrimitive(int times, int size);

void main() {
	int primitvePlayerWins = 0, smartPlayerWins = 0;
	primitvePlayerWins = checkPrimitive(1000, 3);
	smartPlayerWins = checkSmart(1000, 3);
	cout << "Primitive player won : " << primitvePlayerWins << " times" << endl;
	cout << "Smart player won : " << smartPlayerWins << " times" << endl;
	system("pause");


}
////

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

	int pick = rand() % size + 1;
	if (arr[pick] == 1) {

		return true;
	}
	else {
		return false;
	}
}

bool smartMethod(int *arr, int size) {
	srand((unsigned)time(0));
	int pick = rand() % size + 1;
	int secondPick = rand() % size + 1;
	int montyPick = rand() % size + 1;
	while (arr[secondPick] != 1 && secondPick != pick) {
		secondPick = rand() % size + 1;
	}
	while (arr[montyPick] != 1) {
		montyPick = rand() % size + 1;
	}
	pick = montyPick;
	if (arr[pick] == 1) {
		return true;
	}
	else {
		return false;
	}
}

int checkPrimitive(int times, int size) {
	int count = 0;
	int *arr;
	arr = buildPlayBoard(size);
	for (int i = 0; i < times; i++) {
		if (primitiveMethod(arr, size) == true) {
			count++;
		}

	}
	return count;
}
int checkSmart(int times, int size) {
	int count = 0;
	int *arr;
	arr = buildPlayBoard(size);
	for (int i = 0; i < times; i++) {
		if (smartMethod(arr, size) == true) {
			count++;
		}
	}
	return count;
}
//





