#ifndef BCZHC_RESULT_H
#define BCZHC_RESULT_H
namespace bczhc {
template <typename T> class Result {
public:
    T val;
    bool found = true;
    Result(T v) : val(v) {}
    Result() {}
};
} // namespace bczhc
#endif // BCZHC_RESULT_H
