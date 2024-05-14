#ifndef ATOM_LIST_H
#define ATOM_LIST_H

class AtomListClass {
public:
    std::vector<AtomClass*> list;
    ~AtomListClass();
    AtomClass* append(std::string a);
};

extern AtomListClass AtomList;

#endif // ATOM_LIST_H