
// Includes
#include "10_SPI2_NRF24L01.h"
#include "SPI_ERROR_HANDLER.h"

// Private variable
extern SPI_HandleTypeDef hspi2;

/* 8,16,32,64 Bit Buffers used for transmission */

uint8_t  tb_8[1];             // A 8 Byte TX Buffer Of 1 Memory Locations
uint8_t  rb_8[1];             // A 8 Byte RX Buffer Of 1 Memory Locations
uint16_t tb_16[1];            // A 16 Byte TX Buffer Of 1 Memory Locations
uint16_t rb_16[1];            // A 16 Byte RX Buffer Of 1 Memory Locations
uint32_t tb_32[1];            // A 32 Byte TX Buffer Of 1 Memory Locations
uint32_t rb_32[1];            // A 32 Byte RX Buffer Of 1 Memory Locations
uint64_t tb_64[1];            // A 64 Byte TX Buffer Of 1 Memory Locations
uint64_t rb_64[1];            // A 64 Byte RX Buffer Of 1 Memory Locations


uint8_t hal_status=0;

// Buffering Varaibles
static uint8_t  rd1 = 0;     // 8-Bit Variable For Storing & Returning Data To The Caller Function
//static uint16_t rd2 = 0;     // 16-Bit Variable For Storing & Returning Data To The Caller Function
//static uint32_t rd3 = 0;     // 32-Bit Variable For Storing & Returning Data To The Caller Function
static uint64_t rd4 = 0;     // 64-Bit Variable For Storing & Returning Data To The Caller Function



// FUNCTION FOR GENERATING NRF-CSN HIGH TO LOW SIGNAL

void csn_signal()      
{
	HAL_GPIO_WritePin(GPIOF,NRF_CSN_Pin,GPIO_PIN_SET);	
	HAL_GPIO_WritePin(GPIOF,NRF_CSN_Pin,GPIO_PIN_RESET);	
}


// FUNCTION FOR GENERATING WRITE COMMAND SIGNAL FOR COMMAND & STATUS REGISTERS

// WRITING CONFIGURATION REGISTER OF NRF24L01

uint8_t w_gen(uint8_t cmd)
{
uint8_t w=0x20;
w = w+cmd;
return w;	
}



  /******************************** WRITE FUNCTIONS FOR EIGHT BIT REGISTERS NRF24L01 **************************/


void w_config(uint8_t data)
{
csn_signal();
uint8_t cmd_config = w_gen(config); 	
uint8_t cmd[2] = {cmd_config,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void w_en_aa(uint8_t data)
{
csn_signal();
uint8_t cmd_en_aa = w_gen(en_aa); 	
uint8_t cmd[2] = {cmd_en_aa,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void w_en_rxaddr(uint8_t data)
{
csn_signal();
uint8_t cmd_en_rxaddr = w_gen(en_rxaddr); 	
uint8_t cmd[2] = {cmd_en_rxaddr,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void w_setup_aw(uint8_t data)
{
csn_signal();
uint8_t cmd_setup_aw = w_gen(setup_aw); 	
uint8_t cmd[2] = {cmd_setup_aw,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void w_setup_retr(uint8_t data)
{
csn_signal();
uint8_t cmd_setup_retr = w_gen(setup_retr); 	
uint8_t cmd[2] = {cmd_setup_retr,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void w_rf_ch(uint8_t data)
{
csn_signal();
uint8_t cmd_rf_ch = w_gen(rf_ch); 	
uint8_t cmd[2] = {cmd_rf_ch,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void w_rf_setup (uint8_t data)
{
csn_signal();
uint8_t cmd_rf_setup  = w_gen(rf_setup ); 	
uint8_t cmd[2] = {cmd_rf_setup ,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void w_status(uint8_t data)
{
csn_signal();
uint8_t cmd_status = w_gen(status); 	
uint8_t cmd[2] = {cmd_status,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void w_observe_tx(uint8_t data)
{
csn_signal();
uint8_t cmd_observe_tx  = w_gen(observe_tx  ); 	
uint8_t cmd[2] = {cmd_observe_tx  ,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void w_rpd(uint8_t data)
{
csn_signal();
uint8_t cmd_rpd = w_gen(rpd); 	
uint8_t cmd[2] = {cmd_rpd,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void w_rx_addr_p0(uint64_t data)
{
csn_signal();
uint8_t cmd_rx_addr_p0 = w_gen(rx_addr_p0); 	
uint8_t cmd[2] = {cmd_rx_addr_p0,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void w_rx_addr_p1(uint64_t data)
{
csn_signal();
uint8_t cmd_rx_addr_p1 = w_gen(rx_addr_p1); 	
uint8_t cmd[2] = {cmd_rx_addr_p1,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void w_rx_addr_p2(uint8_t data)
{
csn_signal();
uint8_t cmd_rx_addr_p2  = w_gen(rx_addr_p2); 	
uint8_t cmd[2] = {cmd_rx_addr_p2 ,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void w_rx_addr_p3(uint8_t data)
{
csn_signal();
uint8_t cmd_rx_addr_p3 = w_gen(rx_addr_p3); 	
uint8_t cmd[2] = {cmd_rx_addr_p3,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void w_rx_addr_p4(uint8_t data)
{
csn_signal();
uint8_t cmd_rx_addr_p4  = w_gen(rx_addr_p4  ); 	
uint8_t cmd[2] = {cmd_rx_addr_p4 ,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void w_rx_addr_p5(uint8_t data)
{
csn_signal();
uint8_t cmd_rx_addr_p5 = w_gen(rx_addr_p5); 	
uint8_t cmd[2] = {cmd_rx_addr_p5,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void w_tx_addr(uint64_t data)
{
csn_signal();
uint8_t cmd_tx_addr = w_gen(tx_addr); 	
uint8_t cmd[2] = {cmd_tx_addr,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}



void w_rx_pw_p0(uint8_t data)
{
csn_signal();
uint8_t cmd_rx_pw_p0 = w_gen(rx_pw_p0); 	
uint8_t cmd[2] = {cmd_rx_pw_p0,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void w_rx_pw_p1(uint8_t data)
{
csn_signal();
uint8_t cmd_rx_pw_p1 = w_gen(rx_pw_p1); 	
uint8_t cmd[2] = {cmd_rx_pw_p1,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void w_rx_pw_p2(uint8_t data)
{
csn_signal();
uint8_t cmd_rx_pw_p2  = w_gen(rx_pw_p2); 	
uint8_t cmd[2] = {cmd_rx_pw_p2 ,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void w_rx_pw_p3(uint8_t data)
{
csn_signal();
uint8_t cmd_rx_pw_p3 = w_gen(rx_pw_p3); 	
uint8_t cmd[2] = {cmd_rx_pw_p3,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void w_rx_pw_p4(uint8_t data)
{
csn_signal();
uint8_t cmd_rx_pw_p4  = w_gen(rx_pw_p4  ); 	
uint8_t cmd[2] = {cmd_rx_pw_p4 ,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void w_rx_pw_p5(uint8_t data)
{
csn_signal();
uint8_t cmd_rx_pw_p5 = w_gen(rx_pw_p5); 	
uint8_t cmd[2] = {cmd_rx_pw_p5,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void w_fifo_stat(uint8_t data)
{
csn_signal();
uint8_t cmd_fifo_stat  = w_gen(fifo_stat); 	
uint8_t cmd[2] = {cmd_fifo_stat ,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void w_dynpd(uint8_t data)
{
csn_signal();
uint8_t cmd_dynpd = w_gen(dynpd); 	
uint8_t cmd[2] = {cmd_dynpd,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void w_feature(uint8_t data)
{
csn_signal();
uint8_t cmd_feature = w_gen(feature); 	
uint8_t cmd[2] = {cmd_feature,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void w_tx_payload(uint64_t data)
{
csn_signal();
uint8_t cmd_tx_payload = tx_payload; 	
uint8_t cmd[2] = {cmd_tx_payload,data};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void c_flush_tx(void)
{
csn_signal();
uint8_t cmd_flush_tx =flush_tx; 	
uint8_t cmd[1] = {cmd_flush_tx};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void c_flush_rx(void)
{
csn_signal();
uint8_t cmd_flush_rx =flush_rx; 	
uint8_t cmd[1] = {cmd_flush_rx};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void c_reuse_tx_pl (void)
{
csn_signal();
uint8_t cmd_reuse_tx_pl  =reuse_tx_pl ; 	
uint8_t cmd[1] = {cmd_reuse_tx_pl};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void c_r_rx_pl_wid(void)
{
csn_signal();
uint8_t cmd_r_rx_pl_wid  =r_rx_pl_wid ; 	
uint8_t cmd[1] = {cmd_r_rx_pl_wid};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}

void c_w_ack_payload(void)
{
csn_signal();
uint8_t cmd_w_ack_payload =w_ack_payload; 	
uint8_t cmd[1] = {cmd_w_ack_payload};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void c_w_tx_payload_no_ack  (void)
{
csn_signal();
uint8_t cmd_w_tx_payload_no_ack = w_tx_payload_no_ack  ; 	
uint8_t cmd[1] = {cmd_w_tx_payload_no_ack };
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}


void c_nop   (void)
{
csn_signal();
uint8_t cmd_nop  = nop  ; 	
uint8_t cmd[1] = {cmd_nop};
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)cmd,s_16);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}




       /******************************** READ FUNCTIONS FOR EIGHT BIT REGISTERS**************************/




// READ CONFIGURATION REGISTER OF NRF24L01
uint8_t r_config(void)
{
csn_signal();
tb_8[0] = config;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);			
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];	
return rd1;	
}


// READ ENABLE AUTO ACKNOWLEDGEMENT REGISTER OF NRF24L01
uint8_t r_en_aa(void)
{
csn_signal();
tb_8[0] = en_aa;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);			
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];	
return rd1;	
}


// READ ENABLED RX ADDRESSES OF NRF24L01
uint8_t r_en_rxaddr(void)
{
csn_signal();
tb_8[0] =  en_rxaddr;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];	
return rd1;	
}



// READ SETUP OF ADDRESS WIDTHS OF NRF24L01
uint8_t r_setup_aw(void)
{
csn_signal();
tb_8[0] = setup_aw ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];	
return rd1;	
}


// READ SETUP OF AUTOMATIC RETRANSMISSION REGISTER OF NRF24L01
uint8_t r_setup_retr (void)
{
csn_signal();
tb_8[0] = setup_retr ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];	
return rd1;	
}


// READ RF CHANNEL REGISTER OF NRF24L01
uint8_t r_rf_ch(void)
{
csn_signal();
tb_8[0] = rf_ch;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];	
return rd1;	
}


// READ RF SETUP REGISTER OF NRF24L01
uint8_t r_rf_setup (void)
{
csn_signal();
tb_8[0] =  rf_setup ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];	
return rd1;	
}



// READ STATUS REGISTER OF NRF24L01
uint8_t r_status(void)
{
csn_signal();
tb_8[0] = setup_aw ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);	
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];	
return rd1;	
}


// READ TRANSMIT OBSERVE REGISTER OF NRF24L01
uint8_t r_observe_tx (void)
{
csn_signal();
tb_8[0] = observe_tx ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];	
return rd1;	
}


// READ RECEIVED POWER DETECT REGISTER OF NRF24L01
uint8_t r_rpd (void)
{
csn_signal();
tb_8[0] =rpd   ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];	
return rd1;	
}

                          
// READ RECEIVED DATA PIPE 0 REGISTER OF NRF24L01
uint64_t r_rx_addr_p0 (void)
{
csn_signal();
tb_8[0] =rx_addr_p0  ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_64,s_40);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd4 = rb_64[0];
return rd4;	
}													
													
// READ RECEIVED DATA PIPE 1 REGISTER OF NRF24L01
uint64_t r_rx_addr_p1 (void)
{
csn_signal();
tb_8[0] =rx_addr_p1  ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_64,s_40);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd4 = rb_64[0];
return rd4;	
}													
													
													
// READ RECEIVED DATA PIPE 2 REGISTER OF NRF24L01

uint8_t r_rx_addr_p2 (void)
{
csn_signal();
tb_8[0] =rx_addr_p2  ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];
return  rd1;	
}													
													
													
// READ RECEIVED DATA PIPE 3 REGISTER OF NRF24L01

uint8_t r_rx_addr_p3 (void)
{
csn_signal();
tb_8[0] =rx_addr_p3  ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];
return  rd1;	
}													
													
													
// READ RECEIVED DATA PIPE 4 REGISTER OF NRF24L01

uint8_t r_rx_addr_p4(void)
{
csn_signal();
tb_8[0] =rx_addr_p4  ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];
return  rd1;	
}													
													
													
// READ RECEIVED DATA PIPE 5 REGISTER OF NRF24L01

uint8_t r_rx_addr_p5 (void)
{
csn_signal();
tb_8[0] =rx_addr_p5  ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];
return  rd1;	
}													
					

// READ RECEIVED TRANSMIT REGISTER OF NRF24L01
uint64_t r_tx_addr  (void)
{
csn_signal();
tb_8[0] =tx_addr ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_64,s_40);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd4 = rb_64[0];
return rd4;	
}													


// READ NUMBER OF BYTES IN RX PAYLOAD IN DATA PIPE 0 OF NRF24L01

uint8_t r_rx_pw_p0(void)
{
csn_signal();
tb_8[0] =rx_pw_p0;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];
return  rd1;	
}													
													
													
// READ NUMBER OF BYTES IN RX PAYLOAD IN DATA PIPE 1 OF NRF24L01

uint8_t r_rx_pw_p1 (void)
{
csn_signal();
tb_8[0] =rx_pw_p1 ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];
return  rd1;	
}													
													
													
// READ NUMBER OF BYTES IN RX PAYLOAD IN DATA PIPE 2 OF NRF24L01

uint8_t r_rx_pw_p2(void)
{
csn_signal();
tb_8[0] =rx_pw_p2  ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];
return  rd1;	
}													
													
													
// READ NUMBER OF BYTES IN RX PAYLOAD IN DATA PIPE 3 OF NRF24L01

uint8_t r_rx_pw_p3 (void)
{
csn_signal();
tb_8[0] =rx_pw_p3;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];
return  rd1;	
}

// READ NUMBER OF BYTES IN RX PAYLOAD IN DATA PIPE 4 OF NRF24L01

uint8_t r_rx_pw_p4(void)
{
csn_signal();
tb_8[0] =rx_pw_p4  ;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];
return  rd1;	
}													
													
													
// READ NUMBER OF BYTES IN RX PAYLOAD IN DATA PIPE 5 OF NRF24L01

uint8_t r_rx_pw_p5 (void)
{
csn_signal();
tb_8[0] =rx_pw_p5;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];
return  rd1;	
}

// READ FIFO STATUS REGISTER OF NRF24L01

uint8_t r_fifo_stat (void)
{
csn_signal();
tb_8[0] = fifo_stat;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];
return  rd1;	
}

// READ ENABLE DYNAMIC PAYLOAD LENGTH REGISTER OF NRF24L01

uint8_t r_dynpd (void)
{
csn_signal();
tb_8[0] =  dynpd;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];
return  rd1;	
}

// READ FEATURE REGISTER OF NRF24L01

uint8_t r_feature (void)
{
csn_signal();
tb_8[0] =  feature;	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb_8,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
else
rd1 = rb_8[0];
return  rd1;	
}


// READ RX_PLD REGISTER OF NRF24L01

void r_rx_payload(void)
{
csn_signal();
tb_8[0] = rx_payload ;	
uint64_t rb1_64[4];	
hal_status = HAL_SPI_Transmit_DMA(&hspi2,(uint8_t*)tb_8,s_8);	
hal_status = HAL_SPI_Receive_DMA(&hspi2,(uint8_t*)rb1_64,s_8);
if(hal_status!=HAL_OK)
{
spi2_error_handler(hal_status);
}		
}






                             /******************End Of File********************/











