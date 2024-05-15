#include "main.h"

AtomListClass::~AtomListClass() {
    for (auto a : atoms) {
        delete a;
    }  
}

AtomInterface* AtomListClass::append(std::string a) {
    atoms.push_back(new AtomClass(a));
    return atoms.back();
}

