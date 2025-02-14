class ProductOfNumbers {
public:
    ProductOfNumbers() {
        pv = vector<long long>{1};
    }
    
    void add(int num) {

        if(num == 0)
        {
            num = 1;
            zi = pv.size();
            pv.push_back(1);
        }
        else
        {
            if(pv.back() == 0)
                pv.push_back(num);
            else
                pv.push_back(pv.back() * num);

        }        
    }
    
    int getProduct(int k) {
      //  cout << pv.size() <<  " " << k << " " << zi << endl;
        int idx = pv.size() - k;
        if(idx <= zi)
        {
           // cout << " RR "<< pv.size() - k << " " << zi << endl;

            return 0;
        }
        //cout << pv.back() << " " << pv[pv.size() - k - 1] << endl; 
        return pv.back() / pv[pv.size() - k - 1];
    }

    private:
    vector<long long> pv;
    int zi = -1;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */