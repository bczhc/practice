#include "SymbolTable.hpp"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>

int main(int argc, char **argv) {
    using ST = bczhc::symboltable::SymbolTable<int, const char *>;
    using Result = ST::Result;
    ST t;
    t.put(1, "qf");
    t.put(2, "xz");
    t.put(3, "dy");
    printf("%i\n", t.size());
    t.put(2, "mrx");
    printf("%i\n", t.size());
    Result r = t.get(2);
    printf("%s\n", r.val);
    t.remove(2);
    printf("%i\n", t.size());
    return 0;
}
