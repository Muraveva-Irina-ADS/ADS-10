// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
class Tree {
 private:
    struct Ptr {
    std::vector<Tree*> childs;
    char ch;
    };
    Ptr* child;
    explicit Tree(char ch) {
        child = new Ptr;
        child->ch = ch;
    }
    void create(const std::vector<char>& vec) {
        for (int i = 0; i < vec.size(); i++) {
            std::vector<char> temp = vec;
            child->childs.push_back(new Tree(temp[i]));
            temp.erase(temp.begin() + i);
            child->childs[i]->create(temp);
        }
    }

 public:
    explicit Tree(const std::vector<char>& vec) {
        child = new Ptr;
        child->ch = '*';
        create(vec);
    }
    int getSize() const {
        return child->childs.size();
    }
    char getCh() const {
        return child->ch;
    }
    Tree& operator[](int n) const {
        return *child->childs[n];
    }
};
#endif  // INCLUDE_TREE_H_
