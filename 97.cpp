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
        struct Tuple
        {
            int t1;
            int t2;
        };

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

            Tuple *tu = new Tuple[s1.size() * s2.size()];
            int tu_size = 0;
            tu[tu_size].t1 = 0;
            tu[tu_size].t2 = 0;
            tu_size++;
            
            int *add = new int[s1.size() * s2.size()];
            int add_size = 0;

            for (int i = 0; i < s3.size(); i++)
            {
               add_size = 0;
               for (int j = 0; j < tu_size; j++)
               {
                   if (tu[j].t1 == -2) continue;
                   
                   if (s3[i] == s1[tu[j].t1] && s3[i] == s2[tu[j].t2])
                   {
                       add[add_size] = tu[j].t1 + 1; add_size++;
                       add[add_size] = tu[j].t2; add_size++;
                       add[add_size] = tu[j].t1; add_size++;
                       add[add_size] = tu[j].t2 + 1; add_size++;
                   }
                   else if (s3[i] == s1[tu[j].t1] && s3[i] != s2[tu[j].t2])
                   {
                       add[add_size] = tu[j].t1 + 1; add_size++;
                       add[add_size] = tu[j].t2; add_size++;
                   }
                   else if (s3[i] != s1[tu[j].t1] && s3[i] == s2[tu[j].t2])
                   {
                       add[add_size] = tu[j].t1; add_size++;
                       add[add_size] = tu[j].t2 + 1; add_size++;
                   }
               }

               if (add_size == 0) return 0;

               tu_size = 0;
               for (int j = 0; j < add_size; j+=2)
               {
                   if (tu_size == 0)
                   {
                       tu[tu_size].t1 = add[j];
                       tu[tu_size].t2 = add[j + 1];
                       tu_size++;
                   }
                    
                   bool uni = 0;
                   for (int k = 0; k < tu_size; k++)
                   {
                       if (tu[k].t1 == add[j] && tu[k].t2 == add[j + 1])
                       {
                           uni = 1;
                           break;
                       }
                   }

                   if (uni == 0)
                   {
                       tu[tu_size].t1 = add[j];
                       tu[tu_size].t2 = add[j + 1];
                       tu_size++;
                   }
                   else continue;
               }
            }

            if (tu_size == 0) return 0;
            else 
            {
                for (int j = 0; j < tu_size; j++)
                {
                    if (tu[j].t1 != s1.size() || tu[j].t2 != s2.size()) return 0;
                }
                return 1;
            }
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
