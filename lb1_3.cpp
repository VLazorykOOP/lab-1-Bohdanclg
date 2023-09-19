#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>

int main(){
    srand(time(NULL));

    int n;
    std::cout << "Enter the number of array elements: ";
    std::cin >> n;

    std::vector<int> B(2 * n);

    for (int i = 0; i < 2 * n; i++) {
        B[i] = (rand() %41 - 20);
        std::cout << B[i] << " ";
    }

    std::cout << std::endl;

    bool a = true;
    for (int i = 0; i < n; i++) {
        if(B[i] == B[2 * n -1]) a = true;
        else a = false;
    }    

    int tmp;
    if(a == false){
        for(int i = 0; i < n; i++){
            int tmp = B[i];
            B[i] = B[i + n];
            B[i + n] = tmp;
        }
    }

    for (int i = 0; i < 2 * n; ++i) {
        std::cout << B[i] << " ";
        if ((i + 1) % 5 == 0) {
            std::cout << std::endl;
        }
    }

    return 0;
}
