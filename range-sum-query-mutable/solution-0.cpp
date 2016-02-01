#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

class NumArray {
protected:
    int size;
    int treeSize;
    vector<int> sum;
    vector<int> nums;
    int top;

    void pushup(int rt) {
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }

    void build(int l, int r, int rt) {
        if (l == r) {
            sum[rt] = nums[top++];
            return;
        }

        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        pushup(rt);
    }

    void update(int p, int value, int l, int r, int rt) {
        if (l == r)  {
            sum[rt] = value; 
            return;
        }

        int m = (l + r) >> 1;
        if (p <= m) update(p, value, lson);
        else update(p, value, rson);
        pushup(rt);
    }

    int query(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) {
            return sum[rt];
        }

        int m = (l + r) >> 1;
        int ret = 0;
        if (L <= m) ret += query(L, R, lson);
        if (R > m) ret += query(L, R, rson);
        return ret;
    }
public:
    NumArray(vector<int> &nums) {
        this->nums = nums;
        size = nums.size();
        if (size == 0) return;
        top = 0;
        treeSize = (((size) << 2));
        sum = vector<int>(treeSize, 0);
        build(1, size, 1);
    }

    void update(int i, int val) {
        if (size == 0) return;
        update(i + 1, val, 1, size, 1);
    }

    int sumRange(int i, int j) {
         if (size == 0) return 0;
         return query(i + 1, j + 1, 1, size, 1);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);