#define log_x (float)0.1
#define log_y (float)-2.3026

float PI=3.14159265;

float mysin(float x)// only valid for x in (0,2*PI) //
{
	int sign=1;
	float y;
	if(x>PI)
	{
		sign=-1;
		x-=PI;
	}
	if(x>PI*0.5)
	{
		x=PI-x;
	}
	y=x*x;
	// (*t=x*(1-y/6+y*y/120)*sign;)
    return x*(1-y*0.166667+y*y*0.00833333)*sign;
}

float mycos(float x)// only valid for x in (0,2*PI) //
{
	int sign=1;
	float y;
	if(x>PI)
	{
		x=2*PI-x;
	}
	if(x>PI*0.5)
	{
		x=PI-x;
		sign=-1;
	}
	y=x*x;
	x=y*y;
	// *t=(1-y/2+y*y/24-y*y*y/720)*sign;
    return (1-y*0.5+x*0.0416667-x*y*0.00138889)*sign;
}

float mylog(float x) //valid only from 0 to 1
{

    int times=0;

    for(int i=0;i<10;i++)
    {
        if(x>log_x)
            break;
		x*=10;
		times++;

    }

    x=1-x;
    const int Loop=25;
    float y=0,tmp=1,pre,pre_r=0.0001;

    for(int i=1;i<=Loop;i++)
    {
        tmp*=x;
        pre=tmp/(float)i;
        y+=pre;
        if(pre<pre_r)break;
    }
    return -y+times*log_y;

}

float mysqrt(float x) //valid only from 1e-6 to 1e6
{
	const int Loop=10;
	float y=3,pre,pre_r=0.0001;

	for(int i=0;i<Loop;i++)
	{
		pre=y;
		y=(pre+x/pre)/2;
		if(y-pre<pre_r && pre-y<pre_r)
		    break;
	}
	return y;
}

