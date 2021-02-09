#ifndef BCZHC_RESULT_H
#define BCZHC_RESULT_H
namespace bczhc {
    template<typename T>
    class Result {
    public:
        T val;
        bool found = true;

        explicit Result(T v) : val(v) {}

        Result() = default;
    };
} // namespace bczhc
#endif // BCZHC_RESULT_H
