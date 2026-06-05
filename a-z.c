
#include <stdio.h>
#include <ctype.h>
int main() {
    char str[1000001];
    scanf("%s", str);

    int flag = 0;

    for (int i = 0; str[i]; i++) {
        
        flag = flag | (1 << (str[i] - 'a'));
        
    }
    printf((flag == (1<<26)-1) ? "Yes\n" : "No\n");
    return 0;
}