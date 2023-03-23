//Quick Find
class UnionFind {
private:
    vector<int> root;
public:
    UnionFind(int sz) : root(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }
    }
    //O(1)
    int find(int x) {
        return root[x];
    }
    //O(N)
    void unionSet(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            int n = root.size();
            for (int i = 0; i < n; i++) {
                if (root[i] == rooty) {
                    root[i] = rootx;
                }
            }
        }
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

//Quick Union
class UnionFind {
private:
    vector<int> root;
public:
    UnionFind(int sz) : root(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }
    }
    //<O(N)
    int find(int x) {
         while (x != root[x]) {
            x = root[x];
        }
        return x;
    }
    //<O(N)
    void unionSet(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            root[rooty] = rootx;
        }
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

//Union by rank 
class UnionFind {
private:
    vector<int> root;
    vector<int> rank;
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x) {
        while (x != root[x]) {
            x = root[x];
        }
        return x;
    }
    
    void unionSet(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) {
                root[rooty] = rootx;
            } else if (rank[rootx] < rank[rooty]) {
                root[rootx] = rooty;
            } else {
                root[rooty] = rootx;
                rank[rootx] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

//Path compresion
class UnionFind {
private:
    vector<int> root;
    vector<int> rank;
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }
    
    void unionSet(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) {
                root[rooty] = rootx;
            } else if (rank[rootx] < rank[rooty]) {
                root[rootx] = rooty;
            } else {
                root[rooty] = rootx;
                rank[rootx] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};