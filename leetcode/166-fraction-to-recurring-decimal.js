/**
 * @param {number} numerator
 * @param {number} denominator
 * @return {string}
 */
var fractionToDecimal = function(numerator, denominator) {
  var num = numerator, den = denominator;
  var symb = ((num >> 31) ^ (den >> 31)) && num ? '-' : '';

  num = Math.abs(num), den = Math.abs(den);
  var rem = num % den;
  num = Math.floor(num / den);
  var inte = num.toString();

  var frac = '';
  var rems = {};
  for (var p = 0; rem && !(rem in rems); ++p) {
    rems[rem] = p;
    num = rem * 10;
    rem = num % den;
    num = Math.floor(num / den);
    frac += num.toString();
  }

  for (var _ in rems) {
    if (rem > 0) {
      p = rems[rem];
      frac = frac.substr(0, p) + '(' + frac.substr(p) + ')';
    }
    frac = '.' + frac;
    break;
  }

  return symb + inte + frac;
};
