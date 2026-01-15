class ProductOfNumbers {
public:
    // Optimized Solution - Prefix Product
    vector<int> nums;
    int n;
    
    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            nums = {};
            n = 0;
        } else {
            if (nums.empty()) 
                nums.push_back(num);
            else
                nums.push_back(num * nums[n - 1]);
            n++;
        }
    }
    
    int getProduct(int k) {
        if (k > n) {
            return 0;
        } else if (k == n) {
            return nums[n - 1];
        } else {
            return nums[n - 1] / nums[n - k - 1];
        }
    }
};