Description : This firmware for ADC Chip was developed to measure temperature from sixteen PT100 sensors connected in differential input format with each of
their positive and negative outputs going to multiplexers and it's the job of MCU to select which temperature sensor it wants to read and therefore generates
corresponding output signal on it's I/O pin for feeding the multiplexer i/o Pin(A0,A1,A2,A3). 


MCU : STM32L476RCTX
MCU I/O Interface : SPI
Peripheral Chips Used : ADC7792(Analog to Digital Converter Chip) , (ADG706BRUZ) Multiplexer Chip

**************************MCU I/O Pin Connectivity With Peripherals*****************************

MUX I/O Connection To MCU : 

MUX Pin                              <-------->       MCU Pin                            i/o

18 EN (MUX_EN)                                        PB0 (MUX_EN)                        o          

17 A0 (MUX_A0)                                        PA0 (MUX_A0)                        o

16 A1 (MUX_A1)                                        PA1 (MUX_A1)                        o

15 A2 (MUX_A2)                                        PA2 (MUX_A2)                        o      Used also for printf debugging after available to mux

14 A3 (MUX_A3)                                        PA3 (MUX_A3)                        o      Used also for printf debugging after available to mux


ADC I/0 Connection To MCU : 

ADC Pin                            <--------->        MCU Pin                            i/o

  __
3 CS   (ADC_SPI_NSS)                                  20  PA4 (ADC_SPI_NSS)                o                                                                                                       

1 SCLK (ADC_SPI_SCK)                                  21  PA5 (ADC_SPI_SCK)                o     
        __ 
15 DOUT/RDY (ADC_SPI_MISO)                            22  PA6 (ADC_SPI_MISO)               i

16 DIN (ADC_SPI_MOSI)                                 23  PA7 (ADC_SPI_MOSI)               o  
