#ifndef PRINT_H
#define PRINT_H

template <typename T>
bool chmax(T &m, const T q);
template <typename T>
bool chmin(T &m, const T q);
int floor_lg(long long x);
template <class T1, class T2>
T1 floor_div(T1 num, T2 den);
template <class T1, class T2>
std::pair<T1, T2> operator+(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r);
template <class T1, class T2>
std::pair<T1, T2> operator-(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r);

template <class T>
int arglb(const std::vector<T> &v, const T &x);
template <class T>
int argub(const std::vector<T> &v, const T &x);
template <class IStream, class T>
IStream &operator>>(IStream &is, std::vector<T> &vec);

template <class OStream, class T>
OStream &operator<<(OStream &os, const std::vector<T> &vec);
template <class OStream, class T, size_t sz>
OStream &operator<<(OStream &os, const std::array<T, sz> &arr);
template <class OStream, class T, class TH>
OStream &operator<<(OStream &os, const std::unordered_set<T, TH> &vec);
// template <class OStream, class T, class U>
// OStream &operator<<(OStream &os, const pair<T, U> &pa);
template <class OStream, class T>
OStream &operator<<(OStream &os, const std::deque<T> &vec);
template <class OStream, class T>
OStream &operator<<(OStream &os, const std::set<T> &vec);
template <class OStream, class T>
OStream &operator<<(OStream &os, const std::multiset<T> &vec);
template <class OStream, class T>
OStream &operator<<(OStream &os, const std::unordered_multiset<T> &vec);
template <class OStream, class T, class U>
OStream &operator<<(OStream &os, const std::pair<T, U> &pa);
template <class OStream, class TK, class TV>
OStream &operator<<(OStream &os, const std::map<TK, TV> &mp);
template <class OStream, class TK, class TV, class TH>
OStream &operator<<(OStream &os, const std::unordered_map<TK, TV, TH> &mp);
template <class OStream, class... T>
OStream &operator<<(OStream &os, const std::tuple<T...> &tpl);

#include "print.cpp"

#endif // PRINT_H