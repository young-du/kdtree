//
//  main.cpp
//  kdtree
//
//  Created by Yang Du on 7/10/20.
//  Copyright © 2020 Yang Du. All rights reserved.
//

#include <iostream>
#include "Kdtree.h"

int main(int argc, char * argv[]) {
    Kdtree myTree;
    myTree.insert(new Node(5,5,5));
    myTree.insert(new Node(4,7,9));
    myTree.insert(new Node(6,8,8));
    myTree.insert(new Node(3,5,4));
    myTree.insert(new Node(2,9,9));
    myTree.insert(new Node(7,0,0));
    myTree.insert(new Node(0,10,0));
    myTree.insert(new Node(1,9,10));
    myTree.insert(new Node(7,0,1));
    auto v = myTree.rangeSearch(make_pair(3, 7), make_pair(5, 10), make_pair(8, 10));
    printSearchResult(v);
    return 0;
}
