//Jaden Casing Strings
String.prototype.toJadenCase = function () {
  var str = this.valueOf();
  var jadenSentence = [];
  var sentence = str.split(' ').map(function(word) {
    var jadenWord =  word.charAt(0).toUpperCase().concat(word.slice(1));
    jadenSentence.push(jadenWord);
    // console.log(jadenWord);
  });
  return jadenSentence.join(' ');
};