class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        bool should_print_message = false;
        int last_timestamp = INT_MIN;
        if (message_timestamp_map_.find(message) != message_timestamp_map_.end()) {
            last_timestamp = message_timestamp_map_[message];
        }
        if (last_timestamp == INT_MIN || timestamp - last_timestamp >= 10) {
            message_timestamp_map_[message] = timestamp;
            message_timestamp_queue_.push(make_pair(message, timestamp));
            should_print_message = true;
        }

        while (!message_timestamp_queue_.empty()) {
            const auto& front_message_timestamp = message_timestamp_queue_.front();
            const string& front_message = front_message_timestamp.first;
            const int& front_timestamp = front_message_timestamp.second;

            if (message_timestamp_map_[front_message] - front_timestamp >= 10) {
                message_timestamp_queue_.pop();
            } else {
                break;
            }
        }
        return should_print_message;
    }
private:
    unordered_map<string, int> message_timestamp_map_;
    queue<pair<string, int> > message_timestamp_queue_;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */