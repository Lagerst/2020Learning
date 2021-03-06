// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define scanf scanf_s

#include "bits/stdc++.h"
using namespace std;

struct node {
  int index, penalty;
};

struct cmp {
  bool operator()(const node &a, const node &b) const {
    if (a.penalty != b.penalty)
      return a.penalty < b.penalty;
    return a.index < b.index;
  }
};

set<node, cmp> s[101000];

int a[101000], b[101000], q[101000];

int main() {
  int n, m, t, p;
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  scanf("%d%d", &n, &m);
  int j1 = 0, j2 = 0;
  for (int i = 1; i <= n; i++) {
    node temp = {i, 0};
    s[0].insert(temp);
    q[i] = n;
  }
  q[0] = n;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &t, &p);
    node temp = {t, b[t]};
    s[a[t]].erase(temp);
    q[a[t]]--;
    a[t]++;
    b[t] += p;
    temp = {t, b[t]};
    s[a[t]].insert(temp);
    temp = {1, b[1]};
    cout << n - q[a[1]] + std::distance(s[a[1]].begin(), s[a[1]].find(temp)) + 1
         << endl;
  }
  return 0;
}