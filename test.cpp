#include "SymbolTable.hpp"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>

int main(int argc, char **argv) {
    using ST = bczhc::symboltable::OrderedSymbolTable<int, const char *>;
    using R = ST::Result;
    class C : public bczhc::sort::Comparable<int> {
    public:
        int compare(int &a, int &b) override { return a - b; }
    } c;
    ST st(c);
    st.put(1, "zs");
    st.put(2, "ls");
    st.put(4, "zl");
    st.put(7, "tq");
    st.put(3, "ww");
    for (int i = 0; i < 10; ++i) {
        R r = st.get(i);
        if (r.found) {
            printf("%s\n", r.val);
        }
    }
    return 0;
}
