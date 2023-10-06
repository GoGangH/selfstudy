#include <iostream>
using namespace std;
<<<<<<< HEAD
int factorial(unsigned long long int a);
int main(){
    int n, m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        cout<<factorial(m)<<endl;
    }
}
int factorial(unsigned long long int a){
    if(a==0) return 1;
    return a * factorial(a-1);
=======
int factorial(int);
int main() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        int result = factorial(m);
        while (1) {
            if (result % 10 != 0) break;
            result /= 10;
        }
        cout << result % 1000 << endl;
    }
}
int factorial(int m) {
    if (m == 0) return 1;

    int k = m;
    while (1) {
        if (k % 10 != 0) break;
        k /= 10;
    }
    int p = factorial(m - 1);
    while (1) {
        if (p % 10 != 0) break;
        p /= 10;
    }

    return (k % 10000) * (p % 10000);
>>>>>>> 48a021e093e39a51a6314fc9044931257092eeac
}