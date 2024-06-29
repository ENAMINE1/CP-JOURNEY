#include "print.h"
template <typename T>
bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T>
bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <class T1, class T2>
T1 floor_div(T1 num, T2 den) { return (num > 0 ? num / den : -((-num + den - 1) / den)); }
template <class T1, class T2>
std::pair<T1, T2> operator+(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r) { return std::make_pair(l.first + r.first, l.second + r.second); }
template <class T1, class T2>
std::pair<T1, T2> operator-(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r) { return std::make_pair(l.first - r.first, l.second - r.second); }

template <class T>
int arglb(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), x)); }
template <class T>
int argub(const std::vector<T> &v, const T &x) { return std::distance(v.begin(), std::upper_bound(v.begin(), v.end(), x)); }
template <class IStream, class T>
IStream &operator>>(IStream &is, std::vector<T> &vec)
{
    for (auto &v : vec)
        is >> v;
    return is;
}

template <class OStream, class T>
OStream &operator<<(OStream &os, const std::vector<T> &vec)
{
    os << '[';
    for (auto v : vec)
        os << v << ',';
    os << ']';
    return os;
}
template <class OStream, class T, size_t sz>
OStream &operator<<(OStream &os, const std::array<T, sz> &arr)
{
    os << '[';
    for (auto v : arr)
        os << v << ',';
    os << ']';
    return os;
}
template <class... T>
std::istream &operator>>(std::istream &is, std::tuple<T...> &tpl)
{
    std::apply([&is](auto &&...args)
               { ((is >> args), ...); }, tpl);
    return is;
}
template <class OStream, class... T>
OStream &operator<<(OStream &os, const std::tuple<T...> &tpl)
{
    os << '(';
    std::apply([&os](auto &&...args)
               { ((os << args << ','), ...); }, tpl);
    return os << ')';
}
template <class OStream, class T, class TH>
OStream &operator<<(OStream &os, const std::unordered_set<T, TH> &vec)
{
    os << '{';
    for (auto v : vec)
        os << v << ',';
    os << '}';
    return os;
}
template <class OStream, class T>
OStream &operator<<(OStream &os, const std::deque<T> &vec)
{
    os << "deq[";
    for (auto v : vec)
        os << v << ',';
    os << ']';
    return os;
}
template <class OStream, class T>
OStream &operator<<(OStream &os, const std::set<T> &vec)
{
    os << '{';
    for (auto v : vec)
        os << v << ',';
    os << '}';
    return os;
}
template <class OStream, class T>
OStream &operator<<(OStream &os, const std::multiset<T> &vec)
{
    os << '{';
    for (auto v : vec)
        os << v << ',';
    os << '}';
    return os;
}
template <class OStream, class T>
OStream &operator<<(OStream &os, const std::unordered_multiset<T> &vec)
{
    os << '{';
    for (auto v : vec)
        os << v << ',';
    os << '}';
    return os;
}
template <class OStream, class T, class U>
OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
template <class OStream, class TK, class TV>
OStream &operator<<(OStream &os, const std::map<TK, TV> &mp)
{
    os << '{';
    for (auto v : mp)
        os << v.first << "=>" << v.second << ',';
    os << '}';
    return os;
}
template <class OStream, class TK, class TV, class TH>
OStream &operator<<(OStream &os, const std::unordered_map<TK, TV, TH> &mp)
{
    os << '{';
    for (auto v : mp)
        os << v.first << "=>" << v.second << ',';
    os << '}';
    return os;
}