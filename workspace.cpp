#include <bits/stdc++.h>
using namespace std;

void solution()
{
    int N;
    cin>>N;

    vector<int> arr(N);
    for(int i = 0; i<N; i++) {
        cin>>arr[i];
    }

    int ans = 0;
    for(int i = 0; i<N; i++) {
        ans += arr[i] + (arr[i] + 9) / 10; //This is simply ceil division
    }

    cout<<ans<<endl;
}

int main()
{
    int t = 1;
    cin >> t;
    for(int i = 1; i<=t; i++)
    {
        cout << "Case #" << i << ": ";
        solution();
    }

    return 0;
}
