#include "main.h"

AtomListClass::~AtomListClass() {
    for (auto a : list) {
        delete a;
    }  
}

AtomClass* AtomListClass::append(std::string a) {
    list.push_back(new AtomClass(a));
    return list.back();
}

AtomListClass AtomList;
