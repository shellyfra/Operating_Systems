#include "../malloc_2.cpp"
#include <unistd.h>
#include <iostream>
#include <sys/mman.h>
#include <cstring>


using namespace std;

int main() {
    std::cout << _size_meta_data() << std::endl;
    std::cout << smalloc(10) << std::endl;
    int *ptr = (int *) smalloc(32);
    for (int i = 0; i < (32 / sizeof(int)); i++) {
        ptr[i] = i;
    }

    for (int i = 0; i < (32 / sizeof(int)); i++) {
        std::cout << ptr[i] << "  "; // needs to print 0 1 2 3 4 5 6 7
    }
    std::cout << endl;

    int *ptr2 = (int *) srealloc(ptr, 33);
//    if (ptr2 != ptr) cout << "not suppose to happen";

    for (int i = 0; i < (32 / sizeof(int)); i++) {
        if (ptr2[i] != i) {
            std::cout << "You have a mistake you stupid bronze 1 ";
            std::cout << "expectd: " << i << " got: " << ptr2[i] << endl;
        }
    }
    std::cout << endl;

    int *ptrnew = (int *) smalloc(32);
    if (ptrnew != ptr)
        std::cout << "your programming sucks. you free'd ptr so now ptrnew needs to get the same adrress..." << endl;

    std::cout << ptr << std::endl;
    // sfree (ptr);
    ptr = (int *) smalloc(15);
    std::cout << ptr << std::endl;
    memset(ptr, 5, 15);
    //std::cout <<"nside ptr  :"<<((int)ptr)<<std::endl;
    //std::cout <<"size ptr"<<alocationList->getSize(ptr)<<std::endl;
    std::cout << srealloc(ptr, 7) << std::endl;
    std::cout << srealloc(ptr, 25) << std::endl;
    std::cout << smalloc(18) << std::endl;
    ptr = (int *) scalloc(4, 6);
    std::cout << ptr << std::endl;

    char *ptr3 = (char *) scalloc(1, 10);
    for (int i = 0; i < 10; i++) {
        if (ptr3[i] != 0)
            std::cout << "WTF you have a problem. A sheep programming for ISIS does a better job than you";
    }
//    std::cout <<"size ptr"<<alocationList->getSize(ptr)<<std::endl;
    return 0;
}
