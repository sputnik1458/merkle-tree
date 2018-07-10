#ifndef MISC_H
#define MISC_H

#include <iostream>
#include <string>
#include "merkle_tree.h"
#include "picosha2.h"


// hashes and returns a string using SHA256
inline std::string hash_sha256(std::string src_str) {
    std::string hash_hex_str = picosha2::hash256_hex_string(src_str);
    return hash_hex_str;
}

// prints all hashes contained within a vector of nodes
inline void printNodeHashes(std::vector<Node*> v) {
    for (unsigned int a = 0; a < v.size(); a++) {
        std::cout << v[a]->hash << std::endl;
    }
}

#endif /* MISC_H */
