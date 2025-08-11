var longestSubarray = function (nums) {
  let ans = 0,
    cnt = 0;
  let max_element = Math.max(...nums);
  for (let num of nums) {
    if (num == max_element) cnt += 1;
    else cnt = 0;
    ans = Math.max(ans, cnt);
  }
  return ans;
};
