/*
 * =====================================================================================
 *
 *       Filename:  a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/31/2016 09:56:17 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>

using namespace std;

class Solution 
{
    private:
        bool subString(string s1, string s2, string s3, int n1, int n2, int n3)
        {
            if (n1 == 0 && n2 == 1 && n3 == 1 && s2[n2] == s3[n3]) return 1;
            else if (n1 == 0 && n2 == 0 && n3 == 1 && s1[n1] == s3[n3]) return 1;
            else
            {
                if (s3[n3] == s1[n1] && s3[n3] == s2[n2])
                {
                    return subString(s1, s2, s3, n1 - 1, n2, n3 - 1) || subString(s1, s2, s3, n1, n2 - 1, n3 - 1);
                }
                else
                {
                    if (s3[n3] == s1[n1])
                        return subString(s1, s2, s3, n1 - 1, n2, n3 - 1);
                    else if (s3[n3] == s2[n2])
                        return subString(s1, s2, s3, n1, n2 - 1, n3 - 1);
                    else
                        return 0;
                }
                return 0;
            }
        }

    public:
        bool isInterleave(string s1, string s2, string s3)
        {
            if (s1 == "" && s2 == "" && s3 == "") return 1;

            if (s1 == "")
            {
                if (s2 == s3) return 1;
                else return 0;
            }
            else if (s2 == "")
            {
                if ( s1 == s3) return 1;
                else return 0;
            }
            
            return subString(s1, s2, s3, s1.size() - 1, s2.size() - 1, s3.size() - 1);

        }
};

int main()
{
    Solution a;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    cout << a.isInterleave(s1, s2, s3) << endl;

    return 0;
}
