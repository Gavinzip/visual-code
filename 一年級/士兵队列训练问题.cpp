#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int people;
        cin >> people;
        queue<int> q;
        for (int i = 1; i <= people; i++) {
            q.push(i);//士兵編號排入 
        }
        while (q.size() > 3) {//人數不超3時重複執行
            int numnow = 1;
            int size = q.size();//不然之後pop掉q.size會越來越小
            for (int i = 0; i < size; i++) {
                if (numnow % 2 == 0) {//若為2的倍數 直接丟掉
                    q.pop();
                }
                else {//若不為2的倍數 將queue最前面的數重新push進去(進入queue最尾端) 然後pop掉front 看下一個人
                    q.push(q.front());
                    q.pop();
                }
                numnow++;
            }
            //重新檢查人數有無>3 才能執行3的倍數離開的迴圈
            if (q.size() <= 3) {
                break;
            }
            numnow = 1;
            size = q.size();
            for (int i = 0; i < size; i++) {
                if (numnow % 3 == 0) {//若為2的倍數 直接丟掉
                    q.pop();
                }
                else {//若不為2的倍數 將queue最前面的數重新push進去(進入queue最尾端) 然後pop掉front 看下一個人
                    q.push(q.front());
                    q.pop();
                }
                numnow++;
            }
        }
        while (!q.empty()) {//若empty回傳1
            cout << q.front();
            q.pop();
            if (q.size() != 0) {//如果還沒pop完 要記得編號間有空格
                cout << " ";
            }
        }
    }
    return 0;
}