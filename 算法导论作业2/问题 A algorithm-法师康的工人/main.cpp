#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> events;

    for (int i = 0; i < N; ++i) {
        int start, end;
        cin >> start >> end;
        events.emplace_back(start, 1);  // 1表示开始工作
        events.emplace_back(end, -1);   // -1表示结束工作
    }

    // 按时间排序，时间相同的情况下，结束事件在前
    sort(events.begin(), events.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    });

    int max_working_time = 0;
    int max_idle_time = 0;
    int current_workers = 0;
    int last_time = events[0].first;
    int start_working_time = -1;
    int last_working_time = -1;

    for (const auto& event : events) {
        if (current_workers > 0) {
            max_working_time = max(max_working_time, event.first - last_time);
        } else if (start_working_time != -1) {
            max_idle_time = max(max_idle_time, event.first - last_time);
        }

        current_workers += event.second;
        last_time = event.first;

        if (current_workers > 0) {
            if (last_working_time == -1) {
                last_working_time = event.first;
            }
        } else {
            if (last_working_time != -1) {
                max_working_time = max(max_working_time, event.first - last_working_time);
                last_working_time = -1;
            }
        }

        if (current_workers > 0 && start_working_time == -1) {
            start_working_time = event.first;
        }
    }

    cout << max_working_time << " " << max_idle_time << endl;

    return 0;
}