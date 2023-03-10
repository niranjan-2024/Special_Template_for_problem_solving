#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr, int n){
        vector<int> ans(n);
        
        stack<int> st;
        st.push(0);
        
        for(int i=1;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            ans[st.top()] = -1;
            st.pop();
        }
        
        return ans;
    }

vector<int> nextLargerElement(vector<int> arr, int n){
        vector<int> ans(n);
        
        stack<int> st;
        st.push(0);
        
        for(int i=1;i<n;i++){
            while(!st.empty() && arr[i]>arr[st.top()]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            ans[st.top()] = -1;
            st.pop();
        }
        
        return ans;
    }

int main()
{
    vector<int> nums = {3,7,4,9,2,5};
    vector<int> nge = nextLargerElement(nums,6);
    
    cout<<"NGE ->"<<" ";
    for(int i=0;i<6;i++){
       cout<<nge[i]<<" ";
    }
    cout<<endl;
    
    vector<int> nse = nextSmallerElement(nums,6);

    cout<<"NSE ->"<<" ";
    for(int i=0;i<6;i++){
       cout<<nse[i]<<" ";
    }
    cout<<endl;
    
    vector<int> rev = nums;
    reverse(rev.begin(),rev.end());
    
    vector<int> pge = nextLargerElement(rev,6);
    reverse(pge.begin(),pge.end());
    
    cout<<"PGE ->"<<" ";
    for(int i=0;i<6;i++){
       cout<<pge[i]<<" ";
    }
    cout<<endl;
    
    vector<int> pse = nextSmallerElement(rev,6);
    reverse(pse.begin(),pse.end());
    
    cout<<"PSE ->"<<" ";
    for(int i=0;i<6;i++){
       cout<<pse[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
