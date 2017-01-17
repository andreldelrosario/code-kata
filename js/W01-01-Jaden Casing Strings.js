//Jaden Casing Strings
String.prototype.toJadenCase = function () {
  var sentence = this.split(' ').map(function(word) {
    return word.charAt(0).toUpperCase().concat(word.slice(1));
  });
  return sentence.join(' ');
};