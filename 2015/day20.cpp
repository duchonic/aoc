#include <iostream>
#include <vector>

int main() {
  int input = 33100000;

  std::vector<int> v1(input/10), v2(input/10);

  std::cout << v1[0] << '\n';

  for(int i = 1; i < v1.size(); i++) {
    for(int j = i, k = 0; j < v1.size(); j += i, k++) {
      v1[j] += 10*i;
      if(k < 50) v2[j] += 11*i;
    }
  }

  int ans1 = 0;
  int ans2 = 0;

  while(v1[++ans1] < input);
  while(v2[++ans2] < input);

  std::cout << ans1 << std::endl;
  std::cout << ans2 << std::endl;
}
