function descendingOrder(n){
  return parseInt(n.toString().split('').sort((a, b) => a < b).join(''));
}