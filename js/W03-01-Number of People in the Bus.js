var number = function(busStops){
  var on = 0;
  var off = 0;
  busStops.map(([a, b]) => { on += a; off += b; });
  return on - off;
}