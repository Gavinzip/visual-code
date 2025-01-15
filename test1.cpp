#include <iostream>
#include <string>
using namespace std;

// 2
// google 2
// yahoo 3


struct WebPage {
    string url;
    int relevance;
};

int main() {
    int t;
    cin >> t;

    WebPage page[10]={0};
    

    for (int caseNumber = 1; caseNumber <= t; ++caseNumber) {
        WebPage pages[10];
        for (int i = 0; i < 10; ++i) {
            cin >> pages[i].url >> pages[i].relevance;
        }

        int highestRelevance = -1;
        for (int i = 0; i < 10; ++i) {
            if (pages[i].relevance > highestRelevance) {
                highestRelevance = pages[i].relevance;
            }
        }

        cout << "Case #" << caseNumber << ":\n";
        for (int i = 0; i < 10; ++i) {
            if (pages[i].relevance == highestRelevance) {
                cout << pages[i].url << endl;
            }
        }
    }

    return 0;
}