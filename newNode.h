// Programmer: Aleksandra Sukhodolskaia
// Programmer's ID: 1651380


#ifndef ADVISER_NEWNODE_H
#define ADVISER_NEWNODE_H

#include "Node.h"

//newNode() allocates a new node with the given data and NULL left and
//right pointers.
struct Node* newNode(string data)
{
// Allocate memory for new node
    auto* node = new struct Node();

// Assign data to this node
    node->data = std::move(data);

// Initialize left and right children as NULL
    node->left = nullptr;
    node->right = nullptr;
    return(node);
}

#endif //ADVISER_NEWNODE_H
