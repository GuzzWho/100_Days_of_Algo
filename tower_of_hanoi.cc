#include <bits/stdc++.h>
using namespace std;


// https://youtu.be/rf6uf3jNjbo?si=DyuZazKkAjwfyUwa
void tower_of_hanoi(int height, stack<int> &source, stack<int> &destination, stack<int> &auxiliary);
void print_towers(stack<int> &source, stack<int> &destination, stack<int> &auxiliary);

void tower_of_hanoi(int height, stack<int> &source, stack<int> &destination, stack<int> &auxiliary)
{   
    if (height >= 1)
    {
        tower_of_hanoi(height - 1, source, auxiliary, destination);
        cout << "Move disk " << source.top() << " from " << &source << " to " << &destination << endl;
        destination.push(source.top());
        source.pop();
        tower_of_hanoi(height - 1, auxiliary, destination, source);
    }
}

void print_towers(stack<int> &source, stack<int> &destination, stack<int> &auxiliary)
{
    cout << "Source: ";
    while (!source.empty())
    {
        cout << source.top() << " ";
        source.pop();
    }
    cout << endl;

    cout << "Destination: ";
    while (!destination.empty())
    {
        cout << destination.top() << " ";
        destination.pop();
    }
    cout << endl;

    cout << "Auxiliary: ";
    while (!auxiliary.empty())
    {
        cout << auxiliary.top() << " ";
        auxiliary.pop();
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    stack<int> source, destination, auxiliary;
    for (int i = n; i >= 1; i--)
    {
        source.push(i);
    }

    tower_of_hanoi(n, source, destination, auxiliary);
    print_towers(source, destination, auxiliary);
    return 0;
}