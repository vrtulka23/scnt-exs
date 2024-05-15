#ifndef ATOM_LIST_H
#define ATOM_LIST_H

class AtomListClass {
public:
    std::vector<AtomInterface*> atoms;
    ~AtomListClass();
    AtomInterface* append(std::string a);
};

extern AtomListClass AtomList;

#endif // ATOM_LIST_H