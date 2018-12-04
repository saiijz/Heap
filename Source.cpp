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
	if (arr[0] != IGNORE_NUMBER) {
		return -1;
	}
	int index{ 0 };
	int count{ 0 };
	while (arr[index] != MARK_NUMBER) {
		++count;
		++index;
	}
	return count - 1;
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
	
	int newPosition = checkSize(arr) + 1;

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

	arr[checkSize(arr) + 1] = MARK_NUMBER;
	return 1;
}

int topDownHeapify(int *&arr, int index) {
	while (arr[index * 2] > MARK_NUMBER) {
		int highPriorityValue = 0;

		if (arr[index] > arr[index * 2]) {
			if (arr[index * 2 + 1] < arr[index * 2] && arr[index * 2 + 1] != MARK_NUMBER) {
				highPriorityValue = 2;
			}
			else {
				highPriorityValue = 1;
			}
		}
		else if (arr[index * 2 + 1] != MARK_NUMBER && arr[index] > arr[index * 2 + 1]) {
			highPriorityValue = 2;
		}

		if (highPriorityValue != 0) {

			if (highPriorityValue == 1) {
				if (arr[index] > arr[index * 2]) {
					swapPositiveValue(arr[index], arr[index * 2]);
					index = index * 2;
				}
			}

			if (highPriorityValue == 2) {
				if (arr[index] > arr[index * 2 + 1]) {
					swapPositiveValue(arr[index], arr[index * 2 + 1]);
					index = index * 2 + 1;
				}
			}
		}
		else {
			break;
		}

	}
	return 1;
}

int bottomUpHeapify(int* arr, int index) {
	int newPosition = index;

	for (int i{ newPosition }; i > 0; i /= 2) {
		if (arr[i] > arr[newPosition]) {
			swapPositiveValue(arr[i], arr[newPosition]);
			newPosition /= 2;
		}
	}

	return 1;
}

int deleteRoot(int *&arr) {
	if (checkSize(arr) < 1) {
		return -1;
	}

	int replaceValueIndex{ checkSize(arr) };
	arr[1] = arr[replaceValueIndex];
	arr[replaceValueIndex] = MARK_NUMBER;
	
	topDownHeapify(arr, 1);
	return 1;
	
}

int changeNodeValue(int*& arr, int pos, int value) {
	if (checkSize(arr) < pos) {
		return -1;
	}

	int comp{ arr[pos] - value };

	arr[pos] = value;
	if (comp == 0) {
		return -1;
	}
	
	if (comp < 0) {
		topDownHeapify(arr,pos);
		return 1;
	}
	if (comp > 0) {
		bottomUpHeapify(arr, pos);
		return 1;
	}

}

int buildTreeFromArrayNumber(int* arr, int unit) {
	for (int i{ unit }; i > 0; i--) {
		bottomUpHeapify(arr, i);
	}
	return 1;
}

void printHeap(int* arr) {
	for (int i{ 1 }; i < checkSize(arr) + 1; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	/*
	int* arr{ createHeap(5) };
	addValue(arr, 12);
	addValue(arr, 57);
	addValue(arr, 72);
	addValue(arr, 62);
	addValue(arr, 65);
	addValue(arr, 36);
	addValue(arr, 71);
	addValue(arr, 100);
	addValue(arr, 84);
	printHeap(arr);
	deleteRoot(arr);
	printHeap(arr);
	changeNodeValue(arr, 4, 11);
	printHeap(arr);
	deleteRoot(arr);
	printHeap(arr);
	changeNodeValue(arr, 1, 70);
	printHeap(arr);
	addValue(arr, 60);
	addValue(arr, 39);
	addValue(arr, 48);
	addValue(arr, 96);
	addValue(arr, 25);
	printHeap(arr);
	deleteRoot(arr);
	printHeap(arr);
	changeNodeValue(arr, 12, 8);
	printHeap(arr);
	*/

	int* arr = new int[11];
	arr[0] = IGNORE_NUMBER;
	arr[1] = 42;
	arr[2] = 78;
	arr[3] = 64;
	arr[4] = 73;
	arr[5] = 83;
	arr[6] = 4;
	arr[7] = 50;
	arr[8] = 74;
	buildTreeFromArrayNumber(arr, 8);
	for (int i{ 1 }; i < 9; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	system("pause");
}