#include <iostream>
#include <algorithm>
using namespace std;
void standard(int, int[]);
void improve_1(int, int[]);
void improve_2(int, int[]);
int main(){
    int n, m, t1[1001], t2[1001], t3[1001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>t1[j];
            t2[j] = t1[j];
            t3[j] = t1[j];
        }
        standard(m, t1);
        improve_1(m, t2);
        improve_2(m, t3);
        cout<<endl;
    }
}

void standard(int n, int t[]){
    int a = 0, b = 0;
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            a++;
            if(t[j-1] > t[j]){
                b++;
                swap(t[j], t[j-1]);
            }
        }
    }
    cout << a << " " << b << " ";
}

void improve_1(int n, int t[]){
    int a = 0, b = 0;
    for(int i=0;i<n;i++){
        bool swapped = false;
        for(int j=1;j<n-i;j++){
            a++;
            if(t[j-1] > t[j]){
                b++;
                swap(t[j], t[j-1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
    cout << a << " " << b << " ";
}

void improve_2(int n, int t[]){
    int a = 0, b = 0;
    while(n > 0){
        int swappedPos = 0;
        for(int j=1;j<n;j++){
            a++;
            if(t[j-1] > t[j]){
                b++;
                swap(t[j], t[j-1]);
                swappedPos = j;
            }
        }
        n = swappedPos;
    }
    cout << a << " " << b;
}
