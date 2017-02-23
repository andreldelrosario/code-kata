function reverse(str) {
  return str.length <= 1 ? str : str.split('').pop() + reverse(str.slice(0, -1));
}