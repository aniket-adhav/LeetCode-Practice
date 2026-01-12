class ExamRoom {
public:
    set<int> seats;
    int n;
    
    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }

        int prev = -1;
        int maxDist = -1;
        int candidate = 0;
        auto it = seats.begin();
        if (*it != 0) {
            maxDist = *it;
            candidate = 0;
        }
        for (auto sit : seats) {
            if (prev != -1) {
                int dist = (sit - prev) / 2;
                if (dist > maxDist) {
                    maxDist = dist;
                    candidate = prev + dist;
                }
            }
            prev = sit;
        }
        if (*seats.rbegin() != n - 1) {
            int dist = n - 1 - *seats.rbegin();
            if (dist > maxDist) {
                candidate = n - 1;
            }
        }

        seats.insert(candidate);
        return candidate;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */