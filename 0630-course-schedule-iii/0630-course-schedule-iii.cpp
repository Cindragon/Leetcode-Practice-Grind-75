class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>&a, vector<int>&b){
            return a[1]<b[1];
        });
        priority_queue<int> pq;
        int total=0;
        for(const auto&c:courses){
            total+=c[0];
            pq.push(c[0]);
            if(total>c[1]){
                total-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};

/*
先將 courses 以課程結束的時間進行排序，越晚結束的課程越後面
接下來遍歷整個 courses 陣列，用 total記錄修課的時間
如果 total>c[1](代表修完這堂會超出期限)，那我們就減去 top，並且將他pop出來
最後return pq.size()(有幾堂課可以修完)

*/