# testing the header files

> ./test -s -r compact

<pre>
(base) ~/Documents/work/aoc/2021/day01/build (master ✘)✖✹✭ ᐅ make -j12; ./test -s -r compact
Scanning dependencies of target test
[ 25%] Building CXX object CMakeFiles/test.dir/Users/nicolasduchoud/Documents/work/aoc/help/test/bitwise.cpp.o
[ 37%] Built target app
[ 50%] Linking CXX executable test
[100%] Built target test
/Users/nicolasduchoud/Documents/work/aoc/help/test/bitwise.cpp:14: PASSED: ((a) |= (1ULL<<(bit))) == bitset.to_ulong() for: 1 == 1
/Users/nicolasduchoud/Documents/work/aoc/help/test/bitwise.cpp:14: PASSED: ((a) |= (1ULL<<(bit))) == bitset.to_ulong() for: 3 == 3
/Users/nicolasduchoud/Documents/work/aoc/help/test/bitwise.cpp:14: PASSED: ((a) |= (1ULL<<(bit))) == bitset.to_ulong() for: 7 == 7
/Users/nicolasduchoud/Documents/work/aoc/help/test/bitwise.cpp:14: PASSED: ((a) |= (1ULL<<(bit))) == bitset.to_ulong() for: 15 == 15
/Users/nicolasduchoud/Documents/work/aoc/help/test/bitwise.cpp:21: PASSED: ((a) &= ~(1ULL<<(bit))) == bitset.to_ulong() for: 0 == 0
/Users/nicolasduchoud/Documents/work/aoc/help/test/bitwise.cpp:21: PASSED: ((a) &= ~(1ULL<<(bit))) == bitset.to_ulong() for: 0 == 0
/Users/nicolasduchoud/Documents/work/aoc/help/test/bitwise.cpp:21: PASSED: ((a) &= ~(1ULL<<(bit))) == bitset.to_ulong() for: 0 == 0
/Users/nicolasduchoud/Documents/work/aoc/help/test/bitwise.cpp:21: PASSED: ((a) &= ~(1ULL<<(bit))) == bitset.to_ulong() for: 0 == 0
/Users/nicolasduchoud/Documents/work/aoc/help/test/geometry.cpp:6: PASSED: Cube(1) == 1 for: 1 == 1
/Users/nicolasduchoud/Documents/work/aoc/help/test/geometry.cpp:7: PASSED: Cube(2) == 8 for: 8 == 8
/Users/nicolasduchoud/Documents/work/aoc/help/test/math.cpp:6: PASSED: add(3,5,44) == 8 for: 8 == 8
/Users/nicolasduchoud/Documents/work/aoc/help/test/math.cpp:7: PASSED: add(3,5,4) == 4 for: 4 == 4
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:8: PASSED: sub_str(test, ',', first, second) == true for: true == true
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:9: PASSED: first.compare("first") == 0 for: 0 == 0
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:10: PASSED: !(first.compare("fist") == 0) for: !(-1 == 0)
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:11: PASSED: second.compare("second") == 0 for: 0 == 0
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:12: PASSED: !(second.compare("secondo") == 0) for: !(-1 == 0)
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:13: PASSED: sub_str(test, ',', first, second) == true for: true == true
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:14: PASSED: first.compare("first") == 0 for: 0 == 0
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:15: PASSED: !(first.compare("fist") == 0) for: !(-1 == 0)
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:16: PASSED: second.compare("second") == 0 for: 0 == 0
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:17: PASSED: !(second.compare("secondo") == 0) for: !(-1 == 0)
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:18: PASSED: sub_str(test, ':', first, second) == false for: false == false
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:19: PASSED: !(first.compare("first") == 0) for: !(-1 == 0)
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:20: PASSED: !(second.compare("second") == 0) for: !(-1 == 0)
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:28: PASSED: out.at(0).compare("first") == 0 for: 0 == 0
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:29: PASSED: out.at(1).compare("second") == 0 for: 0 == 0
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:30: PASSED: out.at(2).compare("third") == 0 for: 0 == 0
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:31: PASSED: !(out.at(2).compare("first") == 0) for: !(14 == 0)
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:37: PASSED: checkString(input) == false for: false == false
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:39: PASSED: checkString(input) == true for: true == true
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:44: PASSED: checkStringToSet(input).size() == 0 for: 0 == 0
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:46: PASSED: checkStringToSet(input).size() == 1 for: 1 == 1
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:49: PASSED: search == test.end() for: {?} == {?}
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:51: PASSED: checkStringToSet(input).size() == 2 for: 2 == 2
/Users/nicolasduchoud/Documents/work/aoc/help/test/string.cpp:54: PASSED: search != test.end() for: {?} != {?}
Passed all 7 test cases with 36 assertions.
</pre>