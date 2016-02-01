// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
protected:
    vector<int> m_cache;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
         
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        int ret = 0;
        if (m_cache.empty()) {
            if (Iterator::hasNext()) {
                ret = Iterator::next();
                m_cache.push_back(ret);
            }
        } else {
            ret = m_cache[0];
        }
        return ret;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int ret = 0;
        if (m_cache.empty()) {
            ret = Iterator::next(); 
        } else {
            ret = m_cache[0];
        }
        m_cache.clear();
        return ret;
    }

    bool hasNext() const {
        if (m_cache.empty()) {
            return Iterator::hasNext();
        } else {
            return true; 
        }
    }
};