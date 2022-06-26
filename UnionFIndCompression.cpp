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



void _union(int a,int b, unordered_map<int,int>&size,unordered_map<int,int>&m)
{
    if (size[a] < size[b])
    {
        size[b] += size[a];
        m[b] = m[a];
    }
    else
    {
        size[a] += size[b];
        m[a] = m[b];
    }
}
