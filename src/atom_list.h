#ifndef ATOM_LIST_H
#define ATOM_LIST_H

template <class T>
class AtomListClass {
public:
    std::vector<AtomBase*> atoms;
    ~AtomListClass() {
       for (auto a : atoms) {
            delete a;
        } 
    };
    AtomBase* append(std::string a) {
       atoms.push_back(new T(a));
        return atoms.back();
    };
};

#endif // ATOM_LIST_H