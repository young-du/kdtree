//
//  kdtree.cpp
//  kdtree
//
//  Created by Yang Du on 7/10/20.
//  Copyright © 2020 Yang Du. All rights reserved.
//

#include "Kdtree.h"
#include <stdexcept>

Node::Node() { }
Node::~Node() { }
Node::Node(int x, int y, int z) {
    this->p = {x,y,z};
}

bool operator<(Node a, Node b) {
    if (b.level == -1) {
        throw std::runtime_error("level not equal");
    }
    switch (b.level % 3) {
        case 0:
            return (a.p.x < b.p.x);
            break;
        case 1:
            return (a.p.y < b.p.y);
            break;
        case 2:
            return (a.p.z < b.p.z);
            break;
    }
    throw std::runtime_error("undefined behavior");
    return true;
}


void Kdtree::insert(Node* n) {
    if (root == nullptr) {
        root = n;
        n->level = 0;
        return;
    }
    Node* current = root;
    Node* last = nullptr;
    do {
        last = current;
        if (*n < *current) {
            current = current->lc;
        } else {
            current = current->rc;
        }
    } while (current != nullptr);
    if (*n < *last) {
        last->lc = n;
    } else {
        last->rc = n;
    }
    n->level = last->level + 1;
}

vector<Node*> Kdtree::rangeSearch(pair<int,int> x, pair<int,int> y, pair<int,int> z) {
    return root->rangeSearch(x, y, z);
}

vector<Node*> Node::rangeSearch(pair<int,int> x, pair<int,int> y, pair<int,int> z) {
    int value = 0;
    int upper = 0;
    int lower = 0;
    switch (this->level % 3) {
        case 0:
            value = this->p.x;
            upper = x.second;
            lower = x.first;
            break;
        case 1:
            value = this->p.y;
            upper = y.second;
            lower = y.first;
            break;
        case 2:
            value = this->p.z;
            upper = z.second;
            lower = z.first;
            break;
    }
    if (value < lower) {
        if (this->rc != nullptr) {
            return this->rc->rangeSearch(x, y, z);
        }
        return vector<Node*>();
    } else if (value > upper) {
        if (this->lc != nullptr) {
            return this->lc->rangeSearch(x, y, z);
        }
        return vector<Node*>();
    } else {
        vector<Node*> v;
        if (this->p.x >= x.first && this->p.x <= x.second
                && this->p.y >= y.first && this->p.y <= y.second
                && this->p.z >= z.first && this->p.z <= z.second) {
            v.push_back(this);
        }
        if (this->rc != nullptr) {
            auto w = this->rc->rangeSearch(x, y, z);
            v.insert(v.end(), w.begin(), w.end());
        }
        if (this->lc != nullptr) {
            auto w = this->lc->rangeSearch(x, y, z);
            v.insert(v.end(), w.begin(), w.end());
        }
        return v;
    }
    
}

void printSearchResult(vector<Node*> v) {
    for (auto n : v) {
        cout << "(" << n->p.x << ", " << n->p.y << ", " << n->p.z << ")" << endl;
    }
}
