int head(unordered_map<int,int>m, int vertex)
  {
      while(m[vertex] != vertex)
      {
          // we optimise it for that particular node, that nodes goes to its top parent
          m[vertex] = m[m[vertex]];
          vertex = m[vertex];
      }
      return vertex;
  }
