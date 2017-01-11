#include "filter.h"



float kalman_filter(kal_param *k_flt, int input, float vel)
{
    //C表示最优值协方差,C_last表示转移预测方差.X表示最优数据.Q表示转移噪声方差.R为测量噪声方差,K表示卡氏增益
    k_flt->input=input;
    k_flt->K = (k_flt->C_last)/(k_flt->C_last+k_flt->R);
    k_flt->X =(1+vel)*k_flt->X_last + k_flt->K * (k_flt->input - (1+vel)*k_flt->X_last);
    k_flt->C = (1 - k_flt->K) * (k_flt->C_last);

    k_flt->X_last = k_flt->X;
    k_flt->C_last = k_flt->C + k_flt->Q;

    return k_flt->X;
}
