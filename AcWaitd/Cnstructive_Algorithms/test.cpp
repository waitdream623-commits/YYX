#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
struct __X {
  __X& operator<<(const auto& str) { return *this; }
  void sp(const string& str = "") {}
} dout;
#define debug(x)
#endif

int main() {
  int arr[3] = {1, 2, 3};
  debug(arr);
  vector<int> vec = {1, 2, 3};
  debug(vec);
  array<int, 3> stl_arr = {1, 2, 3};
  debug(stl_arr);
  deque<int> deq = {1, 2, 3};
  debug(deq);
  list<int> lst = {1, 2, 3};
  debug(lst);
  set<int> st = {1, 2, 3};
  debug(st);
  map<string, int> mp = {{"a", 1}, {"b", 2}, {"c", 3}};
  debug(mp);
  pair<int, int> pii = {1, 2};
  debug(pii);
  tuple<string, bool, char> tsbc = {"a", true, 'b'};
  debug(tsbc);
  queue<int> que;
  que.push(1);
  que.push(2);
  que.push(3);
  debug(que);
  priority_queue<int> pq;
  pq.push(1);
  pq.push(2);
  pq.push(3);
  debug(pq);
  stack<int> stk;
  stk.push(1);
  stk.push(2);
  stk.push(3);
  debug(stk);

  int arr2[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int arr3[2][3][4] = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
                       {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}};
  debug(arr2);
  debug(arr3);

  vector<map<string, pair<set<int>, map<pair<string, int>, vector<int>>>>> complex = {
    {{"a", {{1, 2}, {{{"a", 1}, {1, 2, 3}}, {{"b", 2}, {4, 5, 6}}}}},
     {"b", {{4, 5}, {{{"c", 3}, {7, 8, 9}}, {{"d", 4}, {10, 11, 12}}}}},
     {"c", {{7, 8}, {{{"e", 5}, {13, 14, 15}}, {{"f", 6}, {16, 17, 18}}}}}},
    {{"c", {{1, 2}, {{{"a", 1}, {19, 20, 21}}, {{"b", 2}, {22, 23, 24}}}}},
     {"d", {{4, 5}, {{{"c", 3}, {25, 26, 27}}, {{"d", 4}, {28, 29, 30}}}}},
     {"e", {{7, 8}, {{{"e", 5}, {31, 32, 33}}, {{"f", 6}, {34, 35, 36}}}}}},
    {{"g", {{1, 2}, {{{"a", 1}, {37, 38, 39}}, {{"b", 2}, {40, 41, 42}}}}},
     {"h", {{4, 5}, {{{"c", 3}, {43, 44, 45}}, {{"d", 4}, {46, 47, 48}}}}},
     {"i", {{7, 8}, {{{"e", 5}, {49, 50, 51}}, {{"f", 6}, {52, 53, 54}}}}}}};
  debug(complex);
}
