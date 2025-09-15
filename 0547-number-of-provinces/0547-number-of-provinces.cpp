class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cityNum=isConnected.size();
        int province=0;
        vector<bool> visited(cityNum, false);
        queue<int> q;
        for(int i=0;i<cityNum;i++){
            if(!visited[i]){
                q.push(i);
                province++;
                visited[i]=true;
            }
            while(!q.empty()){
                int c=q.front();
                q.pop();
                for(int j=0;j<cityNum;++j){
                    if(isConnected[c][j]==1 && !visited[j]){
                        q.push(j);
                        visited[j]=true;
                    }
                }
            }
        }
        return province;
    }
};

/*
可以用 BFS 的方式來解決這道題目
1. cityNum 儲存城市總數，province 記錄有多少省份，visited 陣列來記錄有沒有拜訪過的城市，
queue 則儲存出發的城市
2. 遍歷所有城市，如果未拜訪（visited[i]==false），表示發現新的省份，
province+1，q.push(i)，將其設為true
3. 在 q 不為空的情況下，取出其節點，接著再次遍歷城市總數
    - 如果 c 與 j 直接相連（isConnected[c][j]==1）且 j 未拜訪
    - 將 j 放入 queue，標記已拜訪
4. 當所有城市都被訪問過後，province 即為總省份數，返回 province
*/