#include <queue>

using namespace std;

class RecentCounter {
private:
    queue<int> q;

public:
    RecentCounter() {
        // The queue initializes itself automatically as empty
    }
    
    int ping(int t) {
        // 1. Add the new request time to the queue
        q.push(t);
        
        // 2. Remove any requests that fall outside the [t - 3000, t] window
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        
        // 3. The remaining size of the queue is the number of valid recent calls
        return q.size();
    }
};