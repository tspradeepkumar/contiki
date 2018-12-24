# contiki
To run the files. 

copy this file in the contiki/examples/anyfolder/
and create a Makefile as shown below

CONTIKI_PROJECT = ledmotes
all: $(CONTIKI_PROJECT)

#UIP_CONF_IPV6=1

CONTIKI = ../..
include $(CONTIKI)/Makefile.include

Once done, open COOJA IDE.
1. Create a new sinulation and name it 
2. Motes -> Add Motes -> SKy Motes 
3. Select the firmware as the above file (ledmotes.c)
4. Clean and Compile.
5. Once the compulation is successful, the CREATE button will be enabled and create some nodes (preferably 5 nodes)
Open the LED and Button through the interface vieweer of a particular Sky Mote. 
and Start the Simulation. 
You can see the output of LEDs as per 000,001,010,011,100,101,110,111 and so on.
