#include <iostream>
#include <set>
using namespace std;

int main() {
    string s;
    while (cin >> s && s != "*") {
        bool flag = true;
        if (s.size() == 1) {
            cout << s << " is surprising." << endl;
            continue;
        }

        for (int i = 0; i <= s.size() - 2; i++) {
            set<string> st;
            for (int j = 0; j <= s.size() - i - 2; j++) {
                string sub;
                sub.push_back(s[j]);
                sub.push_back(s[j + i + 1]);
                if (st.count(sub) > 0) {
                    cout << s << " is NOT surprising." << endl;
                    flag = false;
                    break;
                }
                st.insert(sub);
            }
            if (!flag) break;
        }
        if (flag) cout << s << " is surprising." << endl;
    }
    
}