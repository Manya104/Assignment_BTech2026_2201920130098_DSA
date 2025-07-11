class Solution {
public:
     int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        priority_queue<int, vector<int>, greater<int>> available_rooms;
        for (int i = 0; i < n; i++) {
            available_rooms.push(i);
        }
        
        // (end_time, room_number)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> ongoing_meetings;
        
        vector<int> count(n, 0);
        
        for (auto& m : meetings) {
            int start = m[0];
            int end = m[1];
            
            // Free up rooms whose meetings have ended
            while (!ongoing_meetings.empty() && ongoing_meetings.top().first <= start) {
                int freed_room = ongoing_meetings.top().second;
                ongoing_meetings.pop();
                available_rooms.push(freed_room);
            }
            
            if (!available_rooms.empty()) {
                int room = available_rooms.top();
                available_rooms.pop();
                ongoing_meetings.push({end, room});
                count[room]++;
            } else {
                auto [earliest_end, room] = ongoing_meetings.top();
                ongoing_meetings.pop();
                
                long long duration = end - start;
                long long new_end = earliest_end + duration;
                ongoing_meetings.push({new_end, room});
                count[room]++;
            }
        }
        
        int max_meetings = 0;
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > max_meetings) {
                max_meetings = count[i];
                answer = i;
            }
        }
        
        return answer;
    }
};