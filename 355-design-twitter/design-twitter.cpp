#include <bits/stdc++.h>
using namespace std;

// Class representing the Twitter system
class Twitter {
private:
    // Stores the tweets of each user as a vector of (timestamp, tweetId)
    unordered_map<int, vector<pair<int, int>>> tweets;
    // Stores the set of followees for each user
    unordered_map<int, unordered_set<int>> following;
    // Global time counter to sort tweets
    int time;

public:
    // Constructor to initialize time counter
    Twitter() {
        time = 0;
    }

    // Function to post a tweet
    void postTweet(int userId, int tweetId) {
        // Add the tweet with current timestamp to user's tweet list
        tweets[userId].push_back({time++, tweetId});
    }

    // Function to get the 10 most recent tweets in news feed
    vector<int> getNewsFeed(int userId) {
        // Min-heap to store tweets based on timestamp
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        // Insert user's own tweets
        for (auto& t : tweets[userId]) {
            pq.push(t);
            // Keep heap size max 10
            if (pq.size() > 10)
                pq.pop();
        }

        // Insert tweets from users being followed
        for (int followee : following[userId]) {
            for (auto& t : tweets[followee]) {
                pq.push(t);
                if (pq.size() > 10)
                    pq.pop();
            }
        }

        // Extract tweets from heap in reverse order
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // Function to follow another user
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    // Function to unfollow another user
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */