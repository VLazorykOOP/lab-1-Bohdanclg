//18. Задано одновимірний масив А розміру N. Обчислити суму елементів масиву на парних
//позиціях та добуток - на непарних позиціях.

#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>

int NumberOfArrayElements(){
    int n;
    std::cout << "Enter the number of array elements: ";
    std::cin >> n;
    return n;
}

std::vector<int> Inputrray(int n) {
    srand(time(NULL));
    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 20 - 10;
    }
    return A;
}

void Console(const std::vector<int>& arr){
    for (int i : arr) {
        std::cout << i << " ";
    }
}

void InputInFile(const std::vector<int>& arr, const std::string& filename){
    std::ofstream inf(filename);

    for (const int& i : arr) {
        inf << i << " ";
    }

    inf.close();
}

void Answer(const std::vector<int>& arr, const std::string& filename){

    int sum = 0, dob = 1;

    for(int i = 0; i < arr.size(); i++){
        (i % 2 == 0) ? (sum += arr[i]) : (dob *= arr[i]);
    }

    std::cout << std::endl << "Sum: " << sum << std::endl;
    std::cout << "Dob: " << dob;
    std::ofstream inf(filename);
        inf << "Sum:" << sum <<std::endl;
        inf << "Dob: " << dob;
    inf.close();
}

int main(){

    int n = NumberOfArrayElements();
    std::vector<int> A = Inputrray(n);
    Console(A);
    
    InputInFile(A, "Array.txt");
    Answer(A,"Answer.txt");

    return 0;
}
