class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int s=n1+n2;
        vector<int> ans(s,0);
        if(n1<n2) return findMedianSortedArrays(nums2, nums1);
        int i=0,j=0,k=0;
        double res;
        if(n2==0){
            ans = nums1;
            i = n1+1;
        }
        while(i<n1+1){
            cout << i << "-" << j << "-" << k << "-" << s/2 << endl;
            if(j>=n2){
                for(int j=i;j<s/2;j++){
                    ans[k]=nums1[j];
                    k++;
                }
                //ans[k] = nums1[i];
                break;
            }
            if(i>=n1){
                cout << "yes" << endl;
                ans[k] = nums2[j];
                break;
            }
            if(nums1[i]<nums2[j]){
                ans[k] = nums1[i];
                k++,i++;
            }
            else if(nums2[j]<nums1[i]){
                ans[k] = nums2[j];
                k++,j++;
            }
            else if(nums1[i]==nums2[j]){
                ans[k] = nums1[i];
                k++,i++;
            }
            if(k>s/2){
                break;
            }
        }
        cout << "-----------" << endl;
        for(auto i: ans) cout << i << endl;
        if(s%2==0){
            //cout << "yes" << endl;
            //cout << (double)(ans[s/2] + ans[s/2-1])/2  << endl;
            res = (double)(ans[s/2] + ans[s/2-1])/2;
        }else{
            res = ans[s/2];
        }
        return res;
    }
};