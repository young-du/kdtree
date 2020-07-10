//
//  Kdtree.h
//  kdtree
//
//  Created by Yang Du on 7/10/20.
//  Copyright © 2020 Yang Du. All rights reserved.
//

#ifndef Kdtree_h
#define Kdtree_h

#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
    int z;
};
class Node {
    public:
    Point p;
    int level = -1;
    Node* lc = nullptr;
    Node* rc = nullptr;
    Node();
    Node(int x, int y, int z);
    vector<Node*> rangeSearch(pair<int,int> x, pair<int,int> y, pair<int,int> z);
    ~Node();
};

class Kdtree {
    public:
    Node* root = nullptr;
    void insert(Node* n);
    vector<Node*> rangeSearch(pair<int,int> x, pair<int,int> y, pair<int,int> z);
};


bool operator<(Node a, Node b);

void printSearchResult(vector<Node*> v);

#endif /* Kdtree_h */
