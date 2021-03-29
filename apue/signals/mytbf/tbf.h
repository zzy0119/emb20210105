#ifndef __TBF_H
#define __TBF_H

#define MAXTBFS	1024

// 初始化令牌桶
int tbf_init(int cps, int burst);

// 取令牌
int tbf_fetchtoken(int tbf_id, int ntokens);

// 還令牌
int tbf_returntoken(int tbf_id, int ntokens);

// 销毁
void tbf_destroy(int tbf_id);

void tbf_destroy_all(void);

#endif

