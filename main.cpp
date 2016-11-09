#include <string>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include "hdc_hash_map.h"

int main(int argc ,char *argv[])
{
    HPointNode c;
    c.next = 0;
    int cc = 123213123;
    set_hash_map(&c, (const char*)&cc, 4, &cc, 4);
    void *pp = 0;
    int len;
    get_hash_map(&c, (const char*)&cc, 4, pp, len);
    printf("%d\n", (*(int*)pp));
    return 0;
}
