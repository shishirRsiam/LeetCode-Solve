var minBitFlips = function (start, goal) {
  let xor = start ^ goal;
  let ans = 0;
  while (xor) {
    ans += xor & 1;
    xor >>= 1;
  }
  return ans;
};
