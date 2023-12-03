#include <iostream>
#include <algorithm>
using namespace std;
void mergeSortIterative(int v[], int n);
void merge(int a[], int low, int mid, int high);
int merge_try = 0;
#define MAX_SIZE 100
int main(){ 
    int n, v[MAX_SIZE];
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        for(int j=0;j<m;j++) cin>>v[j];
        merge_try = 0;
        mergeSortIterative(v, m); 
        cout<<merge_try<<endl;
    }
}
void mergeSortIterative(int v[], int n) { 
    int size = 1;
    while (size < n){ 
        for (int i = 0; i < n; i += 2 * size){ 
            int low = i; 
            int mid = low + size - 1; 
            int high = min(i + 2 * size - 1, n - 1);

            if (mid >= n - 1) // merge할 subarray가 1개일 경우
                break; 
            merge(v, low, mid, high); 
        }
        size *= 2; 
    } 
}
void merge(int a[], int low, int mid, int high){
    int i, j, k;
    int tmp[MAX_SIZE];
    for(i=low; i<=high; i++)
        tmp[i] = a[i];
    
    i = k = low;
    j = mid+1;
    while(i<=mid && j<=high){
        merge_try++;
        if(tmp[i] <= tmp[j]){ // <---- 핵심연산자(비교연산자)
            a[k++] = tmp[i++];
        }
        else
            a[k++] = tmp[j++];
    }
    while(i<=mid)
        a[k++] = tmp[i++];
    while(j<=high)
        a[k++] = tmp[j++];
}