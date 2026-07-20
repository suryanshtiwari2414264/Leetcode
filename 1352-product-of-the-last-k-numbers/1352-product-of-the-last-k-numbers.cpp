class ProductOfNumbers {
private:
    vector<int> prefixproducts;

public:
    ProductOfNumbers() {
        prefixproducts.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            prefixproducts.clear();
            prefixproducts.push_back(1);
            return;
        }

        prefixproducts.push_back(prefixproducts.back() * num);
    }

    int getProduct(int k) {
        int size = prefixproducts.size();

        if (size <= k)
            return 0;

        return prefixproducts[size - 1] / prefixproducts[size - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */