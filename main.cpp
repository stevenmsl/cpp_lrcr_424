#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol424;

/*
Input:
s = "ABAB", k = 2
Output:
4
Explanation:
Replace the two 'A's with two 'B's or vice versa.
*/

tuple<string, int, int>
testFixture1()
{
  return make_tuple("ABAB", 2, 4);
}

/*
Input:
s = "AABABBA", k = 1
Output:
4
Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
*/

tuple<string, int, int>
testFixture2()
{
  return make_tuple("AABABBA", 1, 4);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<2>(f) << endl;
  Solution sol;
  cout << sol.replace(get<0>(f), get<1>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << get<2>(f) << endl;
  Solution sol;
  cout << sol.replace(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  test2();

  return 0;
}