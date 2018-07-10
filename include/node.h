#ifndef NODE_H
#define NODE_H

#include <string>

struct Node {
    std::string hash;
    Node *left;
    Node *right;

    Node(std::string data);
};

#endif /* NODE_H */
