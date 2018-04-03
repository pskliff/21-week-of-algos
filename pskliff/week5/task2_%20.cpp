//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void changeString(string& line, int part_len, int len)
//{
//    int p1 = part_len - 1, p2 = len - 1;
//    while (p1 >= 0)
//    {
//        if (line[p1] != ' ')
//        {
//            line[p2] = line[p1];
//            --p1;
//            --p2;
//        }
//        else
//        {
//            --p1;
//            line[p2] = '0';
//            line[p2 - 1] = '2';
//            line[p2 - 2] = '%';
//            p2-=3;
//        }
//    }
//}
//
//int main()
//{
//    string line = "a d bt w            ";
//    string part = "a d bt w  ";
//    changeString(line, part.length(), line.length());
//    cout << line;
//    return 0;
//}