/*
For working of the this code, please follow the youtube link
https://youtu.be/Ka8gmhay0To

Sensor activation through button
example is Sensor LED Control through the button sensor. 

Whenever you press the button, the LED ON, once you press the button again, the LED OFF

We are going to use SKYMOTEs.

Files needed for this application
1. contiki.h
2. stdio.h
3. dev/leds.h
4. dev/button-sensor.h


You can download the source code in www.nsnam.com or www.engineeringclinic.com 
and please 
subscribe and share.
*/
#include <stdio.h>
#include "contiki.h"
#include "dev/leds.h"
#include "dev/button-sensor.h"

PROCESS(button_process, "Test Button");
AUTOSTART_PROCESSES(&button_process);

static uint8_t flag;
PROCESS_THREAD(button_process,ev,data)
{
PROCESS_BEGIN();
flag=0;
SENSORS_ACTIVATE(button_sensor);
while(1)
{
PROCESS_WAIT_EVENT_UNTIL(ev==sensors_event && data==&button_sensor);
leds_toggle(LEDS_ALL);
if(!flag)
{
leds_on(LEDS_BLUE);
printf("LED BLUE %d\n",leds_get());
}
else 
{
printf("LED BLUE %d\n",leds_get());
leds_off(LEDS_BLUE);
}
flag ^= 1;
leds_toggle(LEDS_ALL);
}
PROCESS_END();
}
