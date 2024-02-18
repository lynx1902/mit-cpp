#include "graph_rep.h"
#include <stdexcept>
#include <vector>
using namespace std;

Graph::Graph(const vector<int> &starts, const vector<int> &ends) {
  if (starts.size() != ends.size()) {
    throw invalid_argument("Size of start and end vectors do not match");
  }
  for (int i = 0; i < starts.size(); i++) {
    mp[starts[i]].push_back(ends[i]);
  }
}

int Graph::numOutgoing(const int nodeID) const {
  map<int, vector<int>>::const_iterator it = mp.find(nodeID);
  if (it == mp.end()) {
    throw invalid_argument("Given nodeID does not exist in the map");
  }

  return it->second.size();
}

const vector<int> &Graph::adjacent(const int nodeID) const {

  map<int, vector<int>>::const_iterator i = mp.find(nodeID);

  if (i == mp.end()) {
    throw invalid_argument("Invalid node ID");
  }
  return i->second;
}
