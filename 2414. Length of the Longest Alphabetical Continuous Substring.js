var longestContinuousSubstring = function (s) {
  let n = s.length;
  let ans = 1,
    cnt = 1;
  for (let i = 1; i < n; i++) {
    if (s[i].charCodeAt() - 1 == s[i - 1].charCodeAt()) cnt += 1;
    else cnt = 1;
    ans = Math.max(ans, cnt);
  }
  return ans;
};
