//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int search(vector<int>& arr, int key) {
        int e = arr.size() - 1;
        int s = 0;

        // Correct condition to include case where s == e
        while (s <= e) {
            int mid = s + (e - s) / 2;

            // If key is found, return its index
            if (key == arr[mid]) return mid;

            // Check if left part is sorted
            if (arr[s] <= arr[mid]) { 
                // If key lies in the sorted left portion
                if (arr[s] <= key && key < arr[mid]) { 
                    e = mid - 1;
                } else { 
                    s = mid + 1;
                }
            } 
            // Else right part must be sorted
            else { 
                // If key lies in the sorted right portion
                if (arr[mid] <= key && key <= arr[e]) { 
                    s = mid + 1;
                } else { 
                    e = mid - 1;
                }
            }
        }

      
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends