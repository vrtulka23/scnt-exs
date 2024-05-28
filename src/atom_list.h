#ifndef ATOM_LIST_H
#define ATOM_LIST_H

#include <memory>

namespace exs {
  
template <class A>
class AtomList {
public:
  std::vector<std::shared_ptr<A>> atoms;
  A* append(std::string s) {
    atoms.push_back(std::make_shared<A>(A::parse(s)));
    return &(*atoms.back());
  };
  A* append(A a) {
    atoms.push_back(std::make_shared<A>(a));
    return &(*atoms.back());
  };
};

}
  
#endif // ATOM_LIST_H
