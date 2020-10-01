#include "LinearList.hpp"
#include "Tree.hpp"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>

#include <iostream>

using namespace std;

using namespace bczhc::linearlist;

int main(int argc, char **argv) {
    SequentialList<string> list;
    for (int i = 0; i < 3; ++i) {
        string s = "a";
        list.insert(s);
    }
    return 0;
}
