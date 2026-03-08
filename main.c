#include "dlog.h"
int main(void)
{

    DLOG_DEBUG("Hello %d\n", 5);
    DLOG_INFO("Hello %d\n", 5);
    DLOG_WARNING("Hello %d\n", 5);
    DLOG_ERROR("Hello %d\n", 5);

    return 0;
}
