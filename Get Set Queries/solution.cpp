#include <iostream>
#include <set>
using namespace std;

int findUpperBound(set<int>& numbers, int index) {
  set<int>::iterator it = lower_bound(numbers.begin(), numbers.end(), index);
  if (it == numbers.end()) {
    return -1;
  }
  return *it;
}

int customLowerBound(set<int>& numbers, int target) {
  set<int>:: iterator left = numbers.begin();
  set<int>:: iterator right = numbers.end();

  while (left != right) {
    set<int>::iterator mid = left;
    advance(mid, distance(left, right) / 2);

    if (*mid < target) {
      left = ++mid;
    } else {
      right = mid;
    }
  }

  if (left == numbers.end()) {
    return -1;
  }

  return *left;
}

vector<int> answerQueries(vector<vector<int>> queries, int N) {
  
  set<int> visited;
  int q = queries.size();
  
  vector<int> res;
  for (int i = 0; i < q; ++i) {
    int type = queries[i][0];
    int index = queries[i][1];
    
    if (type == 2) {
      // get - search for upper bound of this index <= N in the visited
      // int upperIndex = findUpperBound(visited, index);
      int upperIndex = customLowerBound(visited, index);
      res.push_back(upperIndex);
    } else {
      // set
      visited.insert(index);
    }
  }
  
  return res;
}

int main () {
  vector<vector<int>> queries = {{2, 3}, {1, 2}, {2, 1}, {2, 3}, {2, 2}};

  vector<int> res = answerQueries(queries, 5);

  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << " ";
  }
  cout << endl;
}