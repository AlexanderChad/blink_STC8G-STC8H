#include	"config.h"
#include	"GPIO.h"
#include	"delay.h"

void	GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	GPIO_InitStructure.Pin  = GPIO_Pin_2;		//IO
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_Inilize(GPIO_P1,&GPIO_InitStructure);	
}

void main(void)
{
	GPIO_config();
	
	while(1)
	{
		P1=GPIO_Pin_2;
		delay_ms(50);
		P1=0;
		delay_ms(250);
		delay_ms(250);
		delay_ms(250);
		delay_ms(200);
	}
}