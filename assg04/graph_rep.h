#include <map>
#include <vector>

class Graph {
  std::map<int, std::vector<int>> mp;

public:
  Graph(const std::vector<int> &starts, const std::vector<int> &ends);
  int numOutgoing(const int nodeID) const;
  const std::vector<int> &adjacent(const int nodeID) const;
};
