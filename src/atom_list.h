#ifndef ATOM_LIST_H
#define ATOM_LIST_H

#include <memory>

template <class A>
class AtomList {
public:
    std::vector<std::shared_ptr<A>> atoms;
    AtomBase* append(std::string a) {
        atoms.push_back(std::make_shared<A>(a));
        return &(*atoms.back());
    };
};

#endif // ATOM_LIST_H