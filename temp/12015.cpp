// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     int n;
//     vector<int> v;
//     vector<int> maxV;
//     int maxCnt = 0;

//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         int num, tmpMax = 0;
//         cin >> num;
//         v.push_back(num);
//         for (int j = 0; j < i; j++) {
//             if (v[i] > v[j]) {
//                 tmpMax = max(tmpMax, maxV[j]);
//             }
//         }
//         maxV.push_back(tmpMax+1);
//         if (maxV[i] > maxCnt) maxCnt = maxV[i];
//     }

//     cout << maxCnt << endl;
//     return 0;
// }