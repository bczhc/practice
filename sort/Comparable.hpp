#ifndef COMPARABLE_H
#define COMPARABLE_H

template <typename T> class Comparable {
public:
    virtual int compare(T &a, T &b) = 0;
};

#endif // COMPARABLE_H
