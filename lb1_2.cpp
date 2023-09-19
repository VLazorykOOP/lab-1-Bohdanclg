//Зауваження. При розв’язуванні використати змінну(або декілька змінних) типу
//вказівник, яка би вказувала поточний елемент масиву(або на деякий елемент масиву), що
//розглядається
//Знайти номер першого мінімального елемента серед додатних елементів,
//розташованих до першого елемента, кратного п'яти.
#include <iostream>
#include <time.h>


int main()
{
    srand(time(NULL));

    int n;
    std::cin >> n;
    
    int* arr = new int[n];
    
    for(int i = 0; i < n; i++){
        arr[i] = (rand() %41 - 20);
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    
    int* p = arr;
    int* index = nullptr;
    
    if(*p % 5 == 0){
        std::cout << "The first number is a multiple of five, so we cannot find the minimum positive number";
        return 0;
    }

    bool a = false;
    int min = 21;

    for(int i = 0; i < n; i++){
        if(*p % 5 == 0){
            a = true;
            break;
        }
        if(*p < min && *p > 0){
            min = *p;
            index = p;
        }
        p++;
    }

    if(min < 21 && a == true){
        std::cout << "The minimum number satisfying the condition is " << min << " index: " << index - arr;
    } 
    else if(a == false){ 
        std::cout << "There are no multiples of 5, so I cannot solve this problem";
    }
    else{ 
        std::cout << "There are no minimum numbers that satisfy the condition";
    }

    delete[] arr;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}
