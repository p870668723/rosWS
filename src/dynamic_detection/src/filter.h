#ifndef _FILTER_H
#define _FILTER_H

struct kal_param
{
    float C_last=0;		//转移预测方差
    float X_last=0;		//

    float Q=1;			//转移噪声方差
    float R=1;			//测量噪声方差

    float K=0;			//卡氏增益
    float X=0;			//最优数据
    float C=0;          	//最优值的协方差

    float input=0;

	kal_param(float a, float b, float c, float d, float e, float f, float g, float h)
	{
		C_last=a;		//转移预测方差
    	X_last=b;		//
    	Q=c;			//转移噪声方差
    	R=d;			//测量噪声方差
    	K=e;			//卡氏增益
    	X=f;			//最优数据
    	C=g;          	//最优值的协方差
    	input=h;
	}
	kal_param() //默认构造函数
	{}
};


float kalman_filter(kal_param *k_flt, int input, float vel);

#endif
