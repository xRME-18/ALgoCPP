void dfs(int u, int p) {

   // level of children = parent + 1
   lvl[u] = lvl[p] + 1;

   dp[u][0] = p;

   //finding for all 
   for(int i=1; i < LN; ++i)
   {
      dp[u][i] = dp[dp[u][i-1]][i-1];
   }
     

   for(int i=0; i<adj[u].size(); ++i) 
   {
     
     // its child node
     int v = adj[u][i];

     // excluding parent          
     if(v == p) continue;

     dfs(v, u);
   }
}

int lca(int u, int v) {

   // u is the deeper node
   if(lvl[u] < lvl[v])
     swap(u, v);

   // calculating level difference
   int diff = lvl[u] - lvl[v];

   for(int i=0; i<LN; ++i) 
   {
     if((1<<i) & diff)
         u = dp[u][i];
   }

   if(u == v)
     return u;
   // jump till both are immediate child of LCA (Final ans)
   for(int i=LN-1; i>=0; --i) 
   {
     if(dp[u][i] != dp[v][i]) 
     {
         u = dp[u][i];
         v = dp[v][i];
     }
   }
   return dp[u][0];
}
