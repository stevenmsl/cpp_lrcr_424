#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol424;
using namespace std;

/*takeaways
  - use a sliding window as we are trying to find a substring that qualifies
  - AAABCDE, K=2
    - we first grow the window to AAABC.
      - we allow up to two chars to be different from the most
        repeated char 'A' as we can replace the other two chars
        with 'A' to form a substring that contains only 'A' char
      - so the window size is limited by this formula
        length of the window - the number of most repeated char <= k
      - now we grow the window to AAABCD. As 6 - 3 > 2, we have to slide
        the window to the right. so the window becomes AABCD
      - as you can see how the statistics have all changed:
        the number of the most repeated char has become 2.
      - so the question here is when we re-evaluate a window do we
        use 2 or 3 from before for the number of the most repeated
        char? We can't lower the bar as that will not produce a longer
        substring as we expected which has the size of 3+2=5

*/
int Solution::replace(string s, int k)
{
  int mostRepeated = 0, start = 0, maxLen = 0;
  auto freq = vector<int>(26, 0);

  for (auto i = 0; i < s.size(); i++)
  {
    /*grow the window and update the freq*/
    freq[s[i] - 'A']++;
    /* only allow to do better hence the max */
    mostRepeated = max(mostRepeated, freq[s[i] - 'A']);
    /* shrink the window until it meets the criteria  */
    while (i - start + 1 - mostRepeated > k)
      /* update the stats and remove the char from the window */
      freq[s[start] - 'A']--, start++;

    maxLen = max(maxLen, i - start + 1);
  }

  return maxLen;
}