//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//
//    int n = 0;
//    cin >> n;
//    int* a = new int[n];
//    int* b = new int[n];
//    int aprior_sum = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> a[i] >> b[i];
//        aprior_sum += a[i] * b[i];
//    }
//
//    for (int i = 0; i < n; ++i)
//        printf("%12.12f\n", a[i] * b[i] * 1.0 / aprior_sum);
//    return 0;
//}