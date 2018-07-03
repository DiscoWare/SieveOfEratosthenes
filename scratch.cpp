#include <iostream>
#include <string>
#include <vector>
using namespace std;

void findPrimes(int n)
{
    bool a[n - 1];
    for (int i = 0; i < n - 2; ++i)
    {
        a[i] = true;
    }
    
    int current = 2;
    int working = 2;
    bool done = true;
    for (int i = 0; i < n - 2; ++i)
    {
        if (a[i])
        {
            while (i + working <= n - 2)
            {
                if (a[i + working])
                {
                    a[i + working] = false;
                    done = false;
                }
                working += current;
            }
        }
        else
            done = false;
        
        if (done)
            break;
        ++current;
        working = current;
        done = true;
    }
    
    current = 2;
    int count = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        if (a[i])
        {
            cout << current << " ";
            ++count;
        }
        ++current;
    }
    cout << "Count: " << count << endl;
}

int main()
{
    cout << "Enter max number:\n";
    int n;
    cin >> n;
    while (!cin)
    {
        cout << "Not valid\n";
        cin.clear();
        cin.ignore();
    }
    cin.clear();
    cin.ignore();
    
    findPrimes(n);
    
    string trash;
    cout << "Enter anything to quit\n";
    cin >> trash;
    return 0;
}