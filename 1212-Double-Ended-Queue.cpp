#include <iostream>
#include <deque>
#include <stdio.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    int t;
    string x;
    int n;
    int size;
    int temp;
    cin >> t;
 
    for (int cs = 1;cs <= t; cs++) {
        cin >> size;
        cin >> n;
       
        deque <int> q;
        cout << "Case " << cs << ":\n";    
        for (int i = 0; i < n; i++) {
            cin >> x;
 
            if(x == "pushLeft" or x == "pushRight") {
                cin >> temp;
                if(q.size() == size) {
                    cout << "The queue is full\n";
                }
 
                else {
                    if(x == "pushLeft") {
                        cout << "Pushed in left: " << temp << "\n";
                        q.push_front(temp);
                    }
 
                   
                    if(x == "pushRight") {
                        cout << "Pushed in right: " << temp << "\n";
                        q.push_back(temp);
                    }
                }
 
            }
 
            if(x == "popLeft" or x == "popRight") {
                if(q.size() == 0) {
                    cout << "The queue is empty\n";
                }
 
                else {
                    if(x == "popLeft") {
                        cout << "Popped from left: " << q.front() << "\n";
                        q.pop_front();
                    }
                   
                    if(x == "popRight") {
                        cout << "Popped from right: " << q.back() << "\n";
                        q.pop_back();
                    }
 
                }
 
            }
 
 
        }
 
 
 
    }
 
 
}