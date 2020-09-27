#ifndef DATA_STRUCTURES_ARRAY_BOILERPLATE_H
#define DATA_STRUCTURES_ARRAY_BOILERPLATE_H

#include <memory>



template<typename T, typename It>
T swap(It it, T* const value){
    T tmp = *it;
    *it = *value;
    return tmp;
}






#endif //DATA_STRUCTURES_ARRAY_BOILERPLATE_H
