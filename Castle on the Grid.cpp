
// Complete the minimumMoves function below.
vector<vector<int>> adjVec(vector<string> grid){
    int n=grid.size();
    vector<vector<int>> vec(n*n); 
    for(int i=0; i<n; i++){
        for(int j=0;j<n; j++){
            if(grid[i][j]=='X') continue;
            int u,d,l,r;
            r=j+1;
            while(r<n && grid[i][r]!='X'){
                vec[i*n+j].push_back(i*n+r);
                r++;
            }
            l=j-1;
            while(l>=0 && grid[i][l]!='X'){
                vec[i*n+j].push_back(i*n+l);
                l--;
            }
            u=i-1;
            while(u>=0 && grid[u][j]!='X'){
                vec[i*n+j].push_back(u*n+j);
                u--;
            }
            d=i+1;
            while(d<n && grid[d][j]!='X'){
                vec[i*n+j].push_back(d*n+j);
                d++;
            }
        }
    }
    return vec;
}

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {

    int n=grid.size();
    int goal=goalX*n+goalY;
    int start=startX*n+startY;
    vector<vector<int>> vec=adjVec(grid);
    vector<int> isVisited(n*n);
    vector<int> prevNode(n*n, -1);
    queue<int> q;
    q.push(start);
    isVisited[start]=1;
    while(!q.empty()){
        int t=q.front();
        bool flag=false;
        q.pop();
        for(int i=0;i<vec[t].size();i++){
            int u=vec[t][i];
            if(!isVisited[u]){
                isVisited[u]=1;
                q.push(u);
                prevNode[u]=t;
            }
            if(u==goal) {
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    int p=goal, count=0;
    while(p!=start){
        p=prevNode[p];
        count++;
    }
    return count;
}