#include <iostream>
#include <iomanip>
#include "../include/merkle_tree.h"



MerkleTree::MerkleTree(std::vector<Node*> blocks) {
    std::vector<Node*> nodes;
    while (blocks.size() != 1) {
        printNodeHashes(blocks);
        for (unsigned int l = 0, n = 0; l < blocks.size(); l = l + 2, n++) {
            if (l != blocks.size() - 1) { // checks for adjacent block
                nodes.push_back(new Node(hash_sha256(blocks[l]->hash + blocks[l+1]->hash))); // combine and hash adjacent blocks
                nodes[n]->left = blocks[l]; // assign children
                nodes[n]->right = blocks[l+1];
            } else {
                nodes.push_back(blocks[l]);
            }
        }
        std::cout << "\n";
        blocks = nodes;
        nodes.clear();

    }
    this->root = blocks[0];
}

MerkleTree::~MerkleTree() {
    deleteTree(root);
    std::cout << "Tree deleted" << std::endl;
}

void MerkleTree::printTree(Node* n, int indent) {
    if (n) {
        if (n->left) {
            printTree(n->left, indent + 4);
        }
        if (n->right) {
             printTree(n->right, indent + 4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        std::cout << n->hash[0] << "\n ";
    }
}

void MerkleTree::deleteTree(Node* n) {
    if (n) {
        deleteTree(n->left);
        deleteTree(n->right);
        n = NULL;
        delete n;
    }
}
