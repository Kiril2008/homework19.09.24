//1
#include <iostream>
using namespace std;
void checkNumber(int& num) {
    if (num > 0) {
        cout << "число є +" << std::endl;
    }
    else if (num < 0) {
        cout << "число є -" << std::endl;
    }
    else {
        cout << "число є 0" << std::endl;
    }
}
int main() {
    int num;
    cout << "введіть число; ";
    cin >> num;
    checkNumber(num);
    return 0;
}
//2
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void fillArray(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = static_cast<double>(rand()) / RAND_MAX * 10;
    }
}
void printArray(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    cout << std::endl;
}
int main() {
    srand(static_cast<unsigned int>(time(0)));

    int choice;
    do {
int size;
        cout << 'введіть розмір масиву:';
        cin >> size;
        double* arr = new double[size];
        fillArray(arr,size);
        cout << 'масив випадкових дійсних чисел: '';
        printArray(arr ,size);
        delete[] arr; // deallocate memory
        cout << 'продовжити роботу? (y - так, n- ні): '';
        cin >> choice;
    } while (choice == 1);
    return 0;
}
//3
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void swapElements(int* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[2 * i];
        arr[2 * i] = arr[2 * i + 1];
        arr[2 * i + 1] = temp;
    }
}
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    srand(static_cast<unsigned int>(time(0)));
    int size;
    cout << "введіть розмір масиву: ";
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // згенерував рандомне число 1-100
    }
    cout << "початковий масив: ";
    printArray(arr, size);
    swapElements(arr, size);
    cout << "кінцевий масив: ";
    printArray(arr, size);
    delete[] arr; // очистити
    return 0;
}
//4
#include <iostream>
using namespace std;
void separateArray(int* arr, int size) {
    int posCount = 0, negCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            posCount++;
        } else if (arr[i] < 0) {
            negCount++;
        }
    }
    int* posArr = new int[posCount];
    int* negArr = new int[negCount];

    int posIndex = 0, negIndex = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            posArr[posIndex++] = arr[i];
        } else if (arr[i] < 0) {
            negArr[negIndex++] = arr[i];
        }
    }
    cout << "додатні елементи: ";
    for (int i = 0; i < posCount; i++) {
        cout << posArr[i] << " ";
    }
    cout << endl;
    cout << "відємні елементи: ";
    for (int i = 0; i < negCount; i++) {
        cout << negArr[i] << " ";
    }
    cout << endl;
    // звільнення місця
    delete[] posArr;
    delete[] negArr;
}
int main() {
    int size;
    cout << "введіть розмір масиву: ";
    cin >> size;
    int* arr = new int[size];
    cout << "введіть елементи масиву: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    separateArray(arr, size);
    delete[] arr;
    return 0;
}