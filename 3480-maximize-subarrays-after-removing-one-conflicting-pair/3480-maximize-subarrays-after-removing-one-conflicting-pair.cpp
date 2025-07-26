class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        //prepare conflit pairs vector 
        //trevaser the given conflicting pairs and stoe the smallest in largest

        //1. prepare conflicting pair array
        vector<vector<long long>> conflicts(n+2);
        for(const auto& pair:conflictingPairs)
        {
            int a=pair[0];
            int b=pair[1];

            //store the small in large
            if(a<b)
            {
                conflicts[b].push_back(a);
            }
            else
            {
                conflicts[a].push_back(b);
            }
        }

        //2. track left and maxleft 
        int maxleft=0;
        int secondmaxleft=0;
        vector<long long> gains(n+2,0);
        long long validsubarray=0;

        //3. travverse array 1 to n as subaary end point and upadte these variables accordingly 
        for(int right=1; right<=n; ++right)
        {
            //compare array nums traversing uisng right index if it has any conflict by using conflicts array prepared 
            for(int left:conflicts[right]) 
            {
                if(left>maxleft)
                {
                    //update maxleft and sceond maxleft
                    secondmaxleft=maxleft;
                    maxleft=left;
                }
                else if(left>secondmaxleft)
                {
                    //ony secondmaxleft will update
                    secondmaxleft=left;
                }
            
            }

            //now that we now if conflict is tehre or not update gains and validsubarray 
            //validsubarray is from nums from maxleft to right index that count we cna get and add to validsubaary cout
            validsubarray+=right-maxleft;

            //update gain if we can recover nums till secondmaxleft then we can add those too
            gains[maxleft]+=maxleft-secondmaxleft; //if secondmaxleft is acula maxleft 


        }

        //4. get max gain possible from gains and retuen vlaissubarray count ,if anygain is poosible we add thta ele to validsubarray
        long long maxgain=*max_element(gains.begin(),gains.end());
        return validsubarray+maxgain;

        
    }
};