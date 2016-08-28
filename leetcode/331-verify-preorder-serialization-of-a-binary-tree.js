/**
 * @param {string} preorder
 * @return {boolean}
 */
var isValidSerialization = function(preorder) {
  var slot = 1;
  var nodes = preorder.split(',');
  for (var i = 0; i < nodes.length; ++i) {
    if (!slot) return false;
    if ('#' == nodes[i]) --slot;
    else ++slot;
  }
  return 0 === slot;
};
