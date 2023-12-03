#include <iostream>
using namespace std;
void quick(int a[], int low, int high, int type);
int partition_Hoare(int a[], int low, int high);
int partition_Lomuto(int a[], int low, int high);
void reset_num();
int comparison1 = 0, comparison2 = 0, swap1 = 0, swap2 = 0;
int main(){
    int n, a[1000], b[1000];
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        reset_num();
        for(int j=0;j<m;j++){
            cin>>a[j];
            b[j] = a[j];
        }
        quick(a, 0, m-1, 0);
        quick(b, 0, m-1, 1);
        cout<<swap1<<" "<<swap2<<" "<<comparison1<<" "<<comparison2<<" "<<endl;
    }
}
void reset_num(){
    comparison1 = 0;
    comparison2 = 0;
    swap1 = 0;
    swap2 =0;
}
void quick(int a[], int low, int high, int type){
    int p = 0;
    if(low >=high){
        return;
    }
    if(type == 0){
        p = partition_Hoare(a, low, high);
        quick(a, low, p, type);
        quick(a, p+1, high, type);
    }
    else{
        p = partition_Lomuto(a, low, high);
        quick(a, low, p-1, type);
        quick(a, p+1, high, type);
    }
}
int partition_Hoare(int a[], int low, int high){
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    while(true){
        while(a[++i] < pivot){
            comparison1++;
        }
        comparison1++;
        while (a[--j] > pivot){
            comparison1++;
        }
        comparison1++;
        if(i < j){
            swap1++;
            swap(a[i], a[j]); // swap 연산
        }
        else
            return j;
    }
}

int partition_Lomuto(int a[], int low, int high){
    int pivot = a[low];
    int j = low;
    for(int i=low+1;i<=high;i++){
        comparison2++;
        if(a[i] < pivot){ // 비교(comparison) 연산자 ‘<’
            j++;
            swap(a[i], a[j]); // swap 연산
            swap2++;
        }
    }
    int pivot_pos = j;
    swap(a[pivot_pos], a[low]); // swap 연산
    swap2++;
    return pivot_pos;
}