#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// task 2
#define RANGE(X, Y) (0 <= (X) && (X) < (Y)) ? cout << "true" : cout << "false" 

void task2() {
	cout << "TASK 2" << endl;

	int x, y;

	cout << "check 0 <= x < y:" << endl;
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;

	RANGE(x, y);

	cout << endl << endl;
}


// task 3
#define ARRSZ 5
#define SwapINT(A, B) int tmp = A; A = B, B = tmp

void bubbleSort(int* arr) {
	for (int i = 0; i < ARRSZ - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			SwapINT(arr[i], arr[i + 1]);
		}
	}
}

void initArr(int* arr) {
	cout << "init array:" << endl;
	for (int i = 0; i < ARRSZ; i++) {
		cout << "[" << i << "] = ";
		cin >> arr[i];
	}
}

void printArr(const int* arr) {
	for (int i = 0; i < ARRSZ; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void task3() {
	cout << "TASK 3" << endl;

	int arr[ARRSZ];
	
	initArr(arr);
	printArr(arr);
	bubbleSort(arr);
	printArr(arr);

	cout << endl;
}


// task 4

// Объявление структуры с pragma pack
#pragma pack(push, 1)
struct employee {
	string name;
	size_t age;
};
#pragma pack(pop)

void task4() {
	cout << "TASK 4" << endl;

	// Динамическое выделение структуры
	employee* emp = new (nothrow) employee;
	if (emp == nullptr) {
		cout << "bad alloc" << endl << endl;
		return;
	}

	// Инициализация
	emp->name = "Sergei";
	emp->age = 25;

	// Вывод структуры и его размера
	cout << "name: " << emp->name << endl;
	cout << "age: " << emp->age << endl;
	cout << "sizeof: " << sizeof(*emp);

	// Сохранение структуры в текстовый файл
	ofstream outf("struct.txt");
	outf << "name: " << emp->name << endl;
	outf << "age: " << emp->age;
	outf.close();

	delete emp;

	cout << endl << endl;
}


int main() {
	task2();
	task3();
	task4();
}