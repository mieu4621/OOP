#include <iostream>
#include <math.h>
using namespace std;

struct Point
{
    int x;
    int y;
};
void setPoint(Point &a, int x = 0, int y = 0)
{
    a.x = x;
    a.y = y;
}

void inputPoints(Point arr[], int n)
{
    int x;
    int y;
    for (int i = 0; i < n; i++)
    {
        switch (i % 3)
        {
        case 0:
            cout << "Nhap x: ";
            cin >> x;
            cout << "Nhap y: ";
            cin >> y;
            setPoint(arr[i], x, y);
            break;
        case 1:
            cout << "Nhap x: ";
            cin >> x;
            setPoint(arr[i], x);
            break;
        case 2:
            setPoint(arr[i]);
            break;
        default:
            break;
        }
    }
}
void outputPoint(Point a)
{
    cout << "(" << a.x << "," << a.y << ")";
}
void outputPoints(Point arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "Point " << i << ": ";
        outputPoint(arr[i]);
    }
}
float calculateDistance(Point a, Point b)
{
    float dis = abs(sqrt(pow(a.x, b.x) + pow(a.y, b.y)));
    return dis;
}
void findMaxDistance(Point arr[], int n)
{
    if (n > 1)
    {
        float maxDistance = 0;
        Point max1 = arr[0];
        Point max2 = arr[1];
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                float distance = calculateDistance(arr[i], arr[j]);
                if (distance > maxDistance)
                {
                    maxDistance = distance;
                    max1 = arr[i];
                    max2 = arr[j];
                }
            }
        }
        cout << "\n2 point have max distance: " << endl;
        outputPoint(max1);
        outputPoint(max2);
    }
    else
    {
        cout << "\nDon't have enough point" << endl;
    }
}
int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    Point arr[n];
    inputPoints(arr, n);
    outputPoints(arr, n);
    findMaxDistance(arr, n);
}