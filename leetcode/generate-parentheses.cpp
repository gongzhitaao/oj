class Solution {
public:
  vector<string> generateParenthesis(int n) {
    struct node {
      string val;
      int left, right;
      node(string v, int l = 0, int r = 0)
        : val(v), left(l), right(r) { }
    };

    vector<string> ret;
    queue<node> q;
    q.push(node("(", n - 1, n));
    while (!q.empty()) {
      node n = q.front(); q.pop();
      if (!n.left && !n.right) {
        ret.push_back(n.val);
      } else {
        if (n.left == n.right) {
          q.push(node(n.val + "(", n.left - 1, n.right));
        } else {
          if (n.left)
            q.push(node(n.val + "(", n.left - 1, n.right));
          if (n.right)
            q.push(node(n.val + ")", n.left, n.right - 1));
        }
      }
    }

    return ret;
  }
};

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    genparan("(", n - 1, n);
    return ret;
  }

  void genparan(string s, int l, int r) {
    if (!l && !r) {
      ret.push_back(s);
      return;
    }

    if (l == r) {
      genparan(s + "(", l - 1, r);
    } else {
      if (l) genparan(s + "(", l - 1, r);
      if (r) genparan(s + ")", l, r - 1);
    }
  }

  vector<string> ret;
};
