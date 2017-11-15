class FileSystem
{
  struct Node;
  typedef shared_ptr<Node> nodeptr;

  struct Node {
    bool isdir;
    string content;
    map<string, nodeptr> next;
    Node(bool d = false) : isdir(d) {}
  };

  nodeptr root_;

 public:
  FileSystem() { root_ = make_shared<Node>(true); }

  vector<string> ls(string path)
  {
    vector<string> ret;

    nodeptr cur = root_;
    string name = "/";
    for (int i = 1, j = 0; i < path.size() && j >= 0; i = j + 1) {
      j = path.find('/', i);
      name = path.substr(i, j - i);
      cur = cur->next[name];
    }

    if (cur->isdir)
      for (auto& elm : cur->next) ret.push_back(elm.first);
    else
      ret.push_back(name);
    return ret;
  }

  void mkdir(string path)
  {
    nodeptr cur = root_;
    for (int i = 1, j = 1; i < path.size() && j > 0; i = j + 1) {
      j = path.find('/', i);
      string name = path.substr(i, j - i);
      if (cur->next.find(name) == cur->next.end())
        cur->next[name] = make_shared<Node>(true);
      cur = cur->next[name];
    }
  }

  void addContentToFile(string path, string content)
  {
    nodeptr cur = root_;
    for (int i = 1, j = 1; i < path.size() && j > 0; i = j + 1) {
      j = path.find('/', i);
      string name = path.substr(i, j - i);
      if (cur->next.find(name) == cur->next.end())
        cur->next[name] = make_shared<Node>(false);
      cur = cur->next[name];
    }
    cur->content += content;
  }

  string readContentFromFile(string path)
  {
    nodeptr cur = root_;
    for (int i = 1, j = 1; i < path.size() && j > 0; i = j + 1) {
      j = path.find('/', i);
      string name = path.substr(i, j - i);
      cur = cur->next[name];
    }
    return cur->content;
  }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */
