/*
please follow the video if you want to know how to execute the code
https://youtu.be/pZOB-JNqAs0
*/

#include <stdio.h>
#include "contiki.h"
#include "dev/leds.h"

//Blink the LEDS from 0 to 7 in binary and prints the status
//We will test it with skymote LEDs.
static struct etimer blinktimer;
//etimer is event timer

static uint8_t blinks;

PROCESS(blink_process,"LED BLINK PROCESS");
AUTOSTART_PROCESSES(&blink_process);

PROCESS_THREAD(blink_process,ev,data)
{
PROCESS_BEGIN();
blinks=0;
while(1)
{
etimer_set(&blinktimer,CLOCK_SECOND);
//CLOCK_SECOND generates 1 to 10 ms timing signals according to the motes.
PROCESS_WAIT_EVENT_UNTIL(ev==PROCESS_EVENT_TIMER);
leds_off(LEDS_ALL);
leds_on(blinks & LEDS_ALL);
blinks++;
printf("State of LED %0.2X \n",leds_get());
}
PROCESS_END();
}

//You can download this source code from https://www.nsnam.com 

//Subscribe and share my videos 
https://youtu.be/pZOB-JNqAs0
