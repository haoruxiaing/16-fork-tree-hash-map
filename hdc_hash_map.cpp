#include "hdc_hash_map_pe.h"
#include "hdc_hash_map.h"
#include <string.h>

HPointNode* find_one_char(HPointNode* p, char c)
{
    unsigned char cc = c;
    HCharNode * cp = 0;
    if (!p->next){ return 0;}
    if (!p->next->next[hdc_pe16[cc][0]]){ return 0; }
    cp = (HCharNode*)(p->next->next[hdc_pe16[cc][0]]);
    if (!cp->next[hdc_pe16[cc][1]]){
        return 0;
    }
    return (HPointNode*)(cp->next[hdc_pe16[cc][1]]);
}
HPointNode* set_one_char(HPointNode* p, char c)
{
    unsigned char cc = c;
    HCharNode * cp = 0;
    if (!p->next){ p->next = new HCharNode; memset(p->next,0,sizeof(HCharNode));}
    if (!p->next->next[hdc_pe16[cc][0]]){
        p->next->next[hdc_pe16[cc][0]] = new HCharNode;
        memset(p->next->next[hdc_pe16[cc][0]],0,sizeof(HCharNode));
    }
    cp = (HCharNode*)(p->next->next[hdc_pe16[cc][0]]);
    if (!cp->next[hdc_pe16[cc][1]]){
        cp->next[hdc_pe16[cc][1]] = new HPointNode;
        memset(cp->next[hdc_pe16[cc][1]], 0, sizeof(HPointNode));
    }
    return (HPointNode*)(cp->next[hdc_pe16[cc][1]]);
}
int set_hash_map(HPointNode* d, const char * p, int l, void * data, int dl)
{
    if (!d){return -1;}
    HPointNode * pp = d;
    for (int i = 0; i<l; i++){
        pp = set_one_char(pp, p[i]);
        if (!pp){return -1;}
    }
    if (!pp->data){
        delete pp->data; 
        pp->data = 0;
    }
    pp->data =  new char[dl];
    memcpy(pp->data, data, dl);
    pp->data_len = dl;
    return 0;
}
int get_hash_map(HPointNode* d, const char* p, int l, void *& data, int &dl)
{
    if (!d){ return -1;}
    HPointNode * pp = d;
    for (int i = 0; i<l; i++){
        pp = find_one_char(pp, p[i]);
        if (!pp){return -1;}
    }
    data = pp->data;
    dl = pp->data_len;
    return 0;
}
void del_hash_map(HPointNode* d, const char* p, int l)
{
    if (!d){ return ;}
    HPointNode * dd = d;
    HPointNode * pp = d;
    int      mi = 0;
    for (int i = 0; i<l; i++){
        pp = find_one_char(pp, p[i]);
        if (!pp){return ;}
        if (pp->next){
            int nn = 0;
            for (int j=0; j<16; j++){
                if (pp->next->next[j]){nn++;}
            }
            if (nn>1){
                dd = pp;
                mi = i;
            }
        }
    }
    
}
