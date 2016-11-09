#ifndef  _HDC_HASH_MAP_H_
#define  _HDC_HASH_MAP_H_
using namespace std;
struct HCharNode
{
    void*  next[16];
};
struct HPointNode
{
    HCharNode*  next;
    char*      data;
    int        data_len;
};

int set_hash_map(HPointNode* d, const char * p, int l, void * data, int dl);
int get_hash_map(HPointNode* d, const char* p, int l, void *& data, int &dl);

#endif
