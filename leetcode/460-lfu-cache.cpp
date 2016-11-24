/*
 *        Increasing frequencies
 *    ----------------------------->
 *
 *  +------+    +---+    +---+    +---+
 *  | Head |----| 1 |----| 5 |----| 9 |  Frequencies
 *  +------+    +-+-+    +-+-+    +-+-+
 *                |        |        |
 *              +-+-+    +-+-+    +-+-+     |
 *              |2,3|    |4,3|    |6,2|     |
 *              +-+-+    +-+-+    +-+-+     | Most recent
 *                         |        |       |
 *                       +-+-+    +-+-+     |
 *   key,value pairs     |1,2|    |7,9|     |
 *                       +---+    +---+     v
 *
 */

class LFUCache
{
 public:
  struct LRUNode
  {
    int freq;
    list<pair<int, int> > vals;
    LRUNode(int f = 0) : freq(f) { }
  };

  typedef list<LRUNode>::iterator iptr;
  typedef list<pair<int, int> >::iterator jptr;

  LFUCache(int capacity)
  {
    capacity_ = capacity;
  }

  int get(int key)
  {
    int val = -1;
    if (kv_.find(key) != kv_.end()) {
      kv_[key] = promote(key);
      val = kv_[key].second->second;
    }
    return val;
  }

  void set(int key, int value)
  {
    if (capacity_ <= 0) return;
    if (kv_.find(key) == kv_.end()) {
      if (kv_.size() == capacity_) evict();
      kv_[key] = insert(key, value);
    } else {
      kv_[key] = promote(key, value);
    }
  }

 private:
  pair<iptr, jptr> promote(int key, int val = -1)
  {
    iptr i; jptr j;
    tie(i, j) = kv_[key];
    iptr k = next(i);

    if (val < 0) val = j->second;
    int freq = i->freq + 1;

    i->vals.erase(j);
    if (i->vals.empty())
      cache_.erase(i);

    if (k == cache_.end() || k->freq != freq)
      i = cache_.insert(k, LRUNode(freq));
    else i = k;
    j = i->vals.insert(i->vals.end(), {key, val});
    return {i, j};
  }

  void evict()
  {
    iptr i = cache_.begin();
    jptr j = i->vals.begin();
    kv_.erase(j->first);
    i->vals.erase(j);
    if (i->vals.empty())
      cache_.erase(i);
  }

  pair<iptr, jptr> insert(int key, int val)
  {
    iptr i = cache_.begin();
    if (i == cache_.end() || i->freq != 1)
      i = cache_.insert(i, LRUNode(1));
    jptr j = i->vals.insert(i->vals.end(), {key, val});
    return {i, j};
  }

 private:
  list<LRUNode> cache_;
  int capacity_;
  unordered_map<int, pair<iptr, jptr> > kv_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */
