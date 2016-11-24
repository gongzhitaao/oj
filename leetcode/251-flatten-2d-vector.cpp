class Vector2D {
 public:
  typedef vector<vector<int> >::iterator iptr;
  typedef vector<int>::iterator jptr;

  Vector2D(vector<vector<int> >& vec2d)
  {
    i0_ = vec2d.begin();
    i1_ = vec2d.end();
    if (i0_ != i1_) {
      j0_ = i0_->begin();
      j1_ = i0_->end();
    } else {
      vector<int> tmp;
      j0_ = tmp.begin();
      j1_ = tmp.end();
    }
  }

  int next()
  {
    return *j0_++;
  }

  bool hasNext()
  {
    if (j0_ != j1_) return true;
    if (i0_ == i1_) return false;
    while (j0_ == j1_ && ++i0_ != i1_)
      j0_ = i0_->begin(), j1_ = i0_->end();
    return j0_ != j1_;
  }

 private:
  iptr i0_, i1_;
  jptr j0_, j1_;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
