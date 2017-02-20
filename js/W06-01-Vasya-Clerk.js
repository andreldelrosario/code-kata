function isChangeAvailable(change, inHand) {
  if (change >= 50) {
    if (inHand[50] >= 1) {
      change -= 50;
      inHand[50]--;
    } else if (inHand[25] >= 2) {
      change -= 50;
      inHand[25] -= 2;
    }
  }

  if (change >= 25) {
    if (inHand[25] >= 1) {
      change -= 25;
      inHand[25]--;
    }
  }

  return change == 0;
}

function tickets(peopleInLine) {
  const inHand = {
    25: 0,
    50: 0,
    100: 0
  };

  return peopleInLine.every((value) =>  {
    const result = isChangeAvailable(value - 25, inHand);
    inHand[value]++;
    return result;
  }) ? "YES" : "NO";
}