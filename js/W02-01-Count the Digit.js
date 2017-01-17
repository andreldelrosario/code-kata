function nbDig(n, d) {
    var count = 0;
    for (var k = 0; k <= n; ++k) {
        (k * k).toString().split('').map(function(digit) {
            if (digit === d.toString()) {
               ++count;
            }
        });
    }
    return count;
}