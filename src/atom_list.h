#ifndef ATOM_LIST_H
#define ATOM_LIST_H

#include <memory>

namespace exs {
  
template <class A>
class AtomList {
public:
    std::vector<std::shared_ptr<A>> atoms;
    A* append(std::string a) {
        atoms.push_back(std::make_shared<A>(a));
        return &(*atoms.back());
    };
    A* append(A a) {
        atoms.push_back(std::make_shared<A>(a.value));
        return &(*atoms.back());
    };
};

}
  
#endif // ATOM_LIST_H
