#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <array>
#include <set>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <functional>
#include <numeric>
#include <iomanip>

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())

#define PI 3.1415926535897932384626433832795l 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


#define RANGE(i,a,b) int i=(a); i<=(b); i++

template <class T> class range {
private:
    class iter {
    private:
        T at;
    public:
        iter(T at) : at(at) {}
        bool operator!=(iter const& other) const { return at != other.at; }
        T const& operator*() const { return at; }
        iter& operator++() { ++at; return *this; }
    };

    T begin_val;
    T end_val;
public:
    range(T begin_val, T end_val) :
        begin_val(begin_val), end_val(end_val) { }
    iter begin() { return iter(begin_val); }
    iter end() { return iter(end_val); }
};



