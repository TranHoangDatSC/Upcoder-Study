#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Work {
    private:
        int timeStart;
        int timeEnd;
    public:
        Work() {}
        Work(int st, int ed) {
            timeStart = st;
            timeEnd = ed;
        }
        
        friend istream& operator >> (istream& is, Work& w) {
            is >> w.timeStart >> w.timeEnd;
            return is;
        }
        
        friend ostream& operator << (ostream& os, Work w) {
            os << w.timeStart << " " << w.timeEnd << "\n";
            return os;
        }
        
        int GetSt() { return this->timeStart; }
        int GetEd() { return this->timeEnd; }
        void SetSt(int st) { timeStart = st; }
        void SetEd(int ed) { timeEnd = ed; }
        
        // So sánh thời gian kết thúc của hai công việc
        static bool CompareTime(Work& a, Work& b) {
            return a.GetEd() < b.GetEd();
        }
};

int main() {
    int n;
    cin >> n;
    
    vector<Work> selected;
    vector<Work> works(n);
    for(int i = 0; i < n; i++) 
        cin >> works[i];
        
    // Sắp xếp các công việc theo thời gian kết thúc tăng dần
    sort(works.begin(),works.end(),Work::CompareTime);
    
    int cnt = 1; // Công việc đầu tiên
    int lastEnd = works[0].GetEd(); // Thời điểm kết thúc của công việc đầu tiên
    
    for(int i = 1; i < n; i++) {    
        if(works[i].GetSt() >= lastEnd) {   
            // Nếu công việc hiện tại bắt đầu sau khi công việc trước kết thúc
            cnt++;  // Chọn công việc này
            lastEnd = works[i].GetEd(); // Cập nhật thời gian kết thúc gần nhất
            
            
            // selected.push_back(works[i]);
        }
    }
    
    cout << cnt << '\n';
    
    // cout << works[0];
    // for(auto &wk : selected) {
    //     cout << wk;
    // }
    return 0;
}
