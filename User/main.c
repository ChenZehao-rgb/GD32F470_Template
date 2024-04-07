#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "bsp_key.h"
#include "bsp_pwm.h"
#include "bsp_basic_timer.h"
#include "stdlib.h"
#include "string.h"
#include "bsp_dma.h"

int main(void)
{
    uint16_t uicount = 0;
    float fcount = 0;

    nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
    systick_config();
    led_gpio_config();
    usart_gpio_config(9600U);
    key_gpio_config();
    basic_timer_config(20000,10000);
    pwm_config(200, 10000);
    dma_config();
    
    while (1)
    {
        pwm_breathing_lamp();
        if(g_recv_complete_flag)                        //数据接收完成
        {
            g_recv_complete_flag = 0;
            printf("g_recv_length:%d ",g_recv_length); 
            printf("g_recv_buff:%s\r\n ",g_recv_buff);
            memset(g_recv_buff, 0, g_recv_length);      //清空数组
            g_recv_length = 0;
        }
    }

    /* while (1)
    {
        pwm_breathing_lamp();
    } */
    
    /* while(1) 
    {
        
        gpio_bit_write(PORT_LED2, PIN_LED2, SET);
        delay_1ms(1000);
        gpio_bit_write(PORT_LED2, PIN_LED2, RESET);
        delay_1ms(1000);
        uicount++;
        fcount += 0.1;
        printf("uicount = %d, fcount = %.2f\n\r", uicount, fcount);                    
    } */

    /* while (1)
    {
        key_scan();      //按键扫描
    } */

}
