#include <iostream>
using namespace std;
void merge(int a[], int low, int mid, int high);
void mergeSort(int v[], int low, int high);
#define MAX_SIZE 100
int merge_try = 0;
int main(){
    int n, v[MAX_SIZE];
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        for(int j=0;j<m;j++) cin>>v[j];
        merge_try = 0;
        mergeSort(v, 0, m-1);
        cout<<merge_try<<endl;
    }
}
void mergeSort(int v[], int low, int high)
{
    int mid;
    if(low == high) return; /* base case */
        mid = (low + high) / 2;
    mergeSort(v, low, mid);
    mergeSort(v, mid+1, high);
    merge(v, low, mid, high);
}
void merge(int a[], int low, int mid, int high)
{
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