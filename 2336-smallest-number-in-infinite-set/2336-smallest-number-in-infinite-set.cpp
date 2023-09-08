class SmallestInfiniteSet {
public:
multiset<int> s;
    SmallestInfiniteSet() {
        for(int i=1;i<1001;i++)
        s.insert(i);
    }
    
    int popSmallest() {
        int t=*s.begin();
        s.erase(t);
        return t;
    }
    
    void addBack(int num) {
        if(s.find(num)==s.end())
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */