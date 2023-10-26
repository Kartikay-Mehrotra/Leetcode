class Ds{
public:
    vector<int> par,siz;
    Ds(int n)
    {
        par.resize(n+1,0);
        siz.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            par[i]=i;
        }
    }
    int findPar(int u)
    {
        if(u==par[u])
        return u;
        
        return par[u]=findPar(par[u]);
    }
    void UnionBs(int u,int v)
    {
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);
        if(ulp_u==ulp_v)
        return;
        else if(siz[ulp_u]<siz[ulp_v])
        {
            par[ulp_u]=ulp_v;
            siz[ulp_v]+=siz[ulp_u];
        }
        else
        {
            siz[ulp_u]+=siz[ulp_v];
            par[ulp_v]=ulp_u;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Ds d(n);
        int ce=0;
        for(auto i:connections)
        {
            int u=i[0];
            int v=i[1];
            if(d.findPar(u)==d.findPar(v))
                ce++;
            else
                d.UnionBs(u,v);
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(d.par[i]==i)
                c++;
        }
        c-=1;
        if(ce>=c)
            return c;
        return -1;
    }
};