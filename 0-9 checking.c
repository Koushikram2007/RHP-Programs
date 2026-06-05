
#include <stdio.h>
#include <ctype.h>
int main() {
    char str[1000001];
    scanf("%s", str);

    int flag = 0;

    for (int i = 0; str[i]; i++) {
        if (isdigit(str[i])){
            flag = flag | (1 << (str[i] - '0'));
        }
        else{
            continue;
        }
    }
    printf((flag == (1<<10)-1) ? "Yes\n" : "No\n");
    return 0;
}