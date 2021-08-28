#include <iostream>
#include <unordered_map>

int main() {
  std::ios::sync_with_stdio(false);
  int n, m, p, q;
  std::cin >> n >> m >> p >> q;
  std::unordered_map<int, int> map;
  while (n--) {
    int k, v;
    std::cin >> k >> v;
    map[k] = v;
  }
  while (m--) {
    int k;
    std::cin >> k;
    auto i = map.find(k);
    if (i == map.end())
      std::cout << "NOT FOUND" << std::endl;
    else
      std::cout << i->second << std::endl;
  }
  while (p--) {
    int k, v;
    std::cin >> k >> v;
    map[k] = v;
  }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    int s = 0;
    for (int i = l; i < r; i++)
      if (map.find(i) != map.end())
        s++;
    std::cout << s << std::endl;
  }
  return 0;
}