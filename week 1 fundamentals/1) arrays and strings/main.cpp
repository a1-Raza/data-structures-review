#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <class T>
class ArrayList{
    private:
    T* arr;
    int capacity;
    int size;

    public:
    
    ArrayList<T>(){
        arr = new T[1];
        capacity = 1;
        size = 0;
    }

    ~ArrayList<T>(){
        delete[] arr;
    }

    void insertElement(T val, int index){
        if (size+1 > capacity) ExpandArray();
        for (int i = size; i > index; i--){
            arr[i] = arr[i-1];
        }
        arr[index] = val;
        size++;
    }

    void deleteElement(int index){
        for (int i = index; i < size-1; i++){
            arr[i] = arr[i+1];
        }
        size--;
    }

    void ExpandArray(){
        T* newArr = new T[capacity+1];
        for (int i = 0; i < size; i++){
            newArr[i] = arr[i];
        }
        T* temp = arr;
        arr = newArr;
        delete[] temp;
        capacity++;
    }

    void print(){ // aka traverse array
        cout << "Size: " << size << " / Capacity: " << capacity << endl;
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

void reverseString(string& s){
    for (int i = 0; i < s.length()/2; i++){
        char temp = s[i];
        s[i] = s[s.length()-1 - i];
        s[s.length()-1 - i] = temp;
    }
}

bool isPalindrome(int arr[], int len){

    for (int i = 0; i < len/2; i++){
        if (arr[i] != arr[len-1 - i]) return false;
    }
    return true;

}

vector<int> findSubarrayWindow(vector<int> arr, int k){
    int sum = 0;
    int l = 0;
    int r;
    for (r = 0; r < arr.size(); r++){
        sum += arr[r];
        if (sum == k) break;
        while (sum > k){
            sum -= arr[l];
            l++;
        }
    }

    vector<int> o;
    if (sum == k){
        for (int i = l; i <= r; i++) o.push_back(arr[i]);
    }

    return o;

}

vector<int> findSubarrayHash(vector<int> arr, int k){
    
    unordered_map<int, int> sumMap;
    
    for (int i = 0; i < arr.size(); i++){
        
    }

}

int main(int argc,char **argv) {

    // pointer arrays
    /*ArrayList<int> a;
    a.insertElement(1, 0);
    a.insertElement(2, 0);
    a.insertElement(3, 0);
    a.insertElement(4, 0);
    a.print();
    a.insertElement(10, 2);
    a.print();
    a.deleteElement(1);
    a.print();*/


    //// PRACTICE PROBLEMS
    // 1) reverse string
    string s = "hello man :)";
    reverseString(s);
    //cout << s << endl;

    // 2) find max element in array
    // initilize largest = INT_MIN; iterate through array, largest = max(largest, array[i]); return largest at end of loop

    // 3) check if array is palindrome
    int arr[] = {1,2,3,2,1};
    //cout << isPalindrome(arr, 0) << endl;

    // 4) find subarray with given sum; achieved either with sliding window (for non-neg numbers) or hash tables (works with neg numbers)
    vector<int> v = {5,3,6,7,3,2,3,7,9,5,1,3,2,6,7,0,4,4,1,5,8,5,4,0,7,5,6};
    vector<int> o = findSubarrayWindow(v, -1); // output could be 6,7,0,4
    for(int n : o) cout << n << " ";
    cout << endl;


    // end / deletes
    return 0;

}