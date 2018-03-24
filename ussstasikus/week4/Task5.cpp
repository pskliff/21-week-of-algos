//
// Created by Stas Don on 24/03/2018.
//

//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int k, m, d, req = 1;
    cin >> k >> m >> d;

    int days_amount = 0;

    if(d != 1)
    {
        while(d <= 5)
        {
            m += k;
            m -= req++;
            ++d;
            if(m < 0)
                break;
            ++days_amount;

        }
        while(d < 8)
        {
            m -= req++;
            ++d;
            if(m < 0)
                break;
            ++days_amount;
        }

    }

    while(true)
    {
        if(req < k - 2 + (m + 4)/5)
        {
            days_amount += 5;
            m += 5*k - 5*(req + 2);
            req += 5;

            if(m > 2*req + 1)
            {
                req += 2;
                days_amount += 2;
                m -= 2*req + 1;
            }

            else if(m > req)
            {
                ++days_amount;
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            while(m >= 0)
            {
                m += k;
                m -= req++;
                ++d;
                if(m < 0)
                    break;
                ++days_amount;
            }
            break;
        }
    }
    cout<<days_amount;
}