/*
Cho n điểm với tọa độ (xi, yi) và m đường tròn (ui, vi, ri), tâm ui, v­i, bán kính ri. 
Đếm xem có bao nhiêu điểm nằm trong hoặc trên ít nhất một đường tròn. Đầu vào có dòng đầu chứa n (n < 1000).
N dòng tiếp chứa tọa độ của n điểm với tung độ và hoành độ cách nhau bởi dấu cách. Dòng tiếp theo chứa m (m < 1000). 
M dòng tiếp theo chứa tọa độ tâm và bán kính của m đường tròn, cách nhau bởi dấu cách. 
Chương trình in ra số điểm thỏa mãn yêu cầu, nếu không có điểm nào in ra 0.

Ví dụ:
INPUT:
5
1 1
2 2
3 3
4 4
5 5
4
1 2 2
2 2 2
4 3 2
4 3 3
OUTPUT:
5
*/

#include <stdio.h>
#include <math.h>

int main() {
    int n, m, count = 0;
    scanf("%d", &n);
    double x[n], y[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    scanf("%d", &m);
    double u[m], v[m], r[m];
    for (int i = 0; i < m; i++) {
        scanf("%lf %lf %lf", &u[i], &v[i], &r[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (sqrt(pow(x[i] - u[j], 2) + pow(y[i] - v[j], 2)) <= r[j]) {
                count++;
                break;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}