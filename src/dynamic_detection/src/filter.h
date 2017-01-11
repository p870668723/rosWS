#ifndef _FILTER_H
#define _FILTER_H

typedef struct KAL_PARAM
{
    float C_last=0;		//转移预测方差
    float X_last=0;		//

    float Q=1;			//转移噪声方差
    float R=1;			//测量噪声方差

    float K=0;			//卡氏增益
    float X=0;			//最优数据
    float C=0;          	//最优值的协方差

    float input=0;
}
kal_param;


float kalman_filter(kal_param *k_flt, int input, float vel);

#endif
