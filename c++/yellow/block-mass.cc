#include <cstdint>
#include <iostream>
using namespace std;

int main() {
  uint32_t n, res = 0;
  uint16_t r;  // r = 0...100, but uint8_t acts like unsigned char
               // use <cstdio> scandf/printf

  cin >> n >> r;

  for (uint32_t i = 0; i < n; i++) {
    uint16_t w, h, d;
    cin >> w >> h >> d;

    res += w * h * d * r;
  }

  cout << res << endl;

  return 0;
}
