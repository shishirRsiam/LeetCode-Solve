var sumOfThree = function (num) {
  if (!(num % 3)) {
    let mod = num / 3;
    return [mod - 1, mod, mod + 1];
  }
  return [];
};
