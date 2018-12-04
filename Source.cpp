#include <iostream>

const int IGNORE_NUMBER = -999;
const int MARK_NUMBER = -998;

int* createHeap(int value) {
	int* arr = new int[30];
	arr[0] = IGNORE_NUMBER;
	arr[1] = value;
	arr[2] = MARK_NUMBER;
	return arr;
}

int checkSize(int* arr) {
	int index{ 0 };
	int count{ 0 };
	while (arr[index] != MARK_NUMBER) {
		++count;
		++index;
	}
	return count;
}

int swapPositiveValue(int &aValue, int &bValue) {
	if (aValue < 0 || bValue < 0) {
		return -1;
	}

	int temp{ aValue };
	aValue = bValue;
	bValue = temp;
	return 1;
}

int addValue(int* &arr, int value) {
	if (checkSize(arr) >= 30) {
		return -1;
	}

	if (value < 0) {
		return -1;
	}
	
	int newPosition = checkSize(arr);

	for (int i{ newPosition }; i > 0; i /= 2) {
		if (arr[i] == MARK_NUMBER) {
			arr[i] = value;
			arr[i + 1] = MARK_NUMBER;
		}
		if (arr[i] > arr[newPosition]) {
			swapPositiveValue(arr[i], arr[newPosition]);
			newPosition /= 2;
		}
	}

	arr[checkSize(arr)] = MARK_NUMBER;
	return 1;
}

int balanceTree(int *&arr, int pri) {
	int index{ 1 };
	while (index != MARK_NUMBER) {
		int highPriorityValue;
		if (arr[index + 1] > arr[index + 2]) {
			highPriorityValue = 1;
		}
		else {
			highPriorityValue = 2;
		}

		if (highPriorityValue == 1) {
			if (arr[index] > arr[index + 1]) {
				swapPositiveValue(arr[index], arr[index + 1]);
				index = index + 1;
			}
		}

	}
}

int deleteRoot(int *&arr) {
	int replaceValueIndex{ checkSize(arr) - 1 };
	arr[1] = arr[replaceValueIndex];
	arr[replaceValueIndex] = MARK_NUMBER;

	int index{ 1 };
	
	
}

void printHeap(int* arr) {
	for (int i{ 0 }; i < checkSize(arr); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	
	int* arr = createHeap(5);
	addValue(arr, 16);
	addValue(arr, 2);
	addValue(arr, 11);
	addValue(arr, 1);
	addValue(arr, 66);
	addValue(arr, 4);
	addValue(arr, 99);
	addValue(arr, 25);
	addValue(arr, 93);
	addValue(arr, 57);
	addValue(arr, 22);
	addValue(arr, 94);

	printHeap(arr);
	system("pause");
}