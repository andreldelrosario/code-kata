class SmallestIntegerFinder {
  findSmallestInt(args) {
    return args.reduce((n, a) => (n < a) ? n : a, 9999999);
  }
}