/*!
  \file   122.cpp
  \author Zhitao Gong <me@gongzhitaao.org>
  \date   Thu Jun 13 15:22:37 2013

  \brief  Trees on the level
*/

#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Tree
{
public:
    Tree() { init(); }

    ~Tree() { clear(); }

    void init()
    {
        nodes_.push_back(new Node());
    }

    void clear()
    {
        for (size_t i = 0; i < nodes_.size(); ++i)
            delete nodes_[i];
        nodes_.clear();
    }

    bool insert(int val, const string &seq)
    {
        Node *n = nodes_[0];

        if (seq.empty()) {
            if (n->val_ > 0) return false;
            n->val_ = val;
            return true;
        }

        for (size_t i = 0; i < seq.size(); ++i) {
            char c = seq[i];
            if ('R' == c) {
                if (NULL == n->r_) {
                    n->r_ = new Node();
                    nodes_.push_back(n->r_);
                }
                n = n->r_;
            } else {
                if (NULL == n->l_) {
                    n->l_ = new Node();
                    nodes_.push_back(n->l_);
                }
                n = n->l_;
            }
        }

        if (n->val_ > 0) return false;

        n->val_ = val;
        return true;
    }

    bool is_complete() const
    {
        for (size_t i = 0; i < nodes_.size(); ++i)
            if (0 == nodes_[i]->val_) return false;
        return true;
    }

    void bfs_print() const
    {
        queue<Node *> q;

        cout << nodes_[0]->val_;
        if (NULL != nodes_[0]->l_) q.push(nodes_[0]->l_);
        if (NULL != nodes_[0]->r_) q.push(nodes_[0]->r_);

        while (!q.empty()) {
            Node *n = q.front();
            q.pop();
            cout << ' ' << n->val_;
            if (NULL != n->l_) q.push(n->l_);
            if (NULL != n->r_) q.push(n->r_);
        }
        cout << endl;
    }

private:
    struct Node
    {
        int val_;
        Node *p_, *l_, *r_;

        Node() : val_(0), p_(NULL), l_(NULL), r_(NULL) {}
    };

    vector<Node *> nodes_;
};

int main()
{
    int val;
    char ch;
    string par, seq;
    Tree tree;
    bool cont = true;;

    while (cin >> par) {
        if (0 == par.compare("()")) {
            if (cont && tree.is_complete()) tree.bfs_print();
            else cout << "not complete" << endl;

            tree.clear();
            tree.init();
            cont = true;

        } else {
            if (!cont) continue;

            stringstream ss;
            ss << par;
            ss >> ch >> val >> ch >> seq;
            if (')' == seq[0]) seq = "";
            else seq = seq.substr(0, seq.size()-1);

            if (cont && !tree.insert(val, seq)) {
                cont = false;
            }
        }
    }
    return 0;
}
