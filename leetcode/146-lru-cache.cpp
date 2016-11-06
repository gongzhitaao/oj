class LRUCache
{
 public:
  LRUCache(int capacity)
  {
    cap_ = capacity;
  }

  int get(int key)
  {
    int val = -1;
    if (kv_.find(key) != kv_.end()) {
      auto it = kv_[key];
      val = it->second;
      buf_.erase(it);
      buf_.push_front({key, val});
      kv_[key] = buf_.begin();
    }
    return val;
  }

  void set(int key, int value)
  {
    if (kv_.find(key) != kv_.end())
      buf_.erase(kv_[key]);
    else if (buf_.size() == cap_) {
      kv_.erase(buf_.back().first);
      buf_.pop_back();
    }
    buf_.push_front({key, value});
    kv_[key] = buf_.begin();
  }

 private:
  list<pair<int, int> > buf_;
  int cap_;
  unordered_map<int, list<pair<int, int> >::iterator> kv_;
};
