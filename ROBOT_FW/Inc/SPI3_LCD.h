

               /*******************SPI3 LCD*****************/


#ifndef _SPI3_LCD_H
#define _SPI3_LCD_H

// Includes
#include "stm32f4xx_hal.h"

// TFT LCD CONTROLLER REGISTER ADDRESSES

/** 
  * @brief  ILI9341 Registers  
  */
	
/* Level 1 Commands */

#define man_id                   0xDA                // LCD MODULE MANUFATURER ID
#define dri_ver                  0xDB                // LCD MODULE DRIVER VERSION
#define dri_id                   0xDC                // LCD MODULE DRIVER ID   
#define disp_stat                0x09                // READ DISPLAY STATUS  
#define disp_norm_on             0x13                // DISPLAY NORMAL MODE ON 
#define disp_on                  0x29                // LCD DISPLAY ON 
#define disp_of                  0x28                // LCD DISPLAY OFF
#define disp_pow_mod             0x0A                // LCD DISPLAY POWER MODE
#define mem_write                0x2C                // MEMORY WRITE
#define color_set                0x2D                // COLOR SET  
#define mem_read                 0x2E                // MEMORY READ                      
#define mem_acc_con              0x36                // CMD : MEMORY ACCESS CONTROL
#define column_addr              0x2A                // Colomn address register 
#define page_addr                0x2B                // Page address register  
#define rddsdr                   0x0F                /* Read Display Self-Diagnostic Result */ 
#define normal_mode_on           0x13                /* Normal Display Mode ON */

/* Level 1 Commands */
#define LCD_SWRESET             0x01   /* Software Reset */
#define LCD_READ_DISPLAY_ID     0x04   /* Read display identification information */
#define LCD_RDDST               0x09   /* Read Display Status */
#define LCD_RDDPM               0x0A   /* Read Display Power Mode */
#define LCD_RDDMADCTL           0x0B   /* Read Display MADCTL */
#define LCD_RDDCOLMOD           0x0C   /* Read Display Pixel Format */
#define LCD_RDDIM               0x0D   /* Read Display Image Format */
#define LCD_RDDSM               0x0E   /* Read Display Signal Mode */

#define LCD_SPLIN               0x10   /* Enter Sleep Mode */
#define LCD_SLEEP_OUT           0x11   /* Sleep out register */
#define LCD_PTLON               0x12   /* Partial Mode ON */
#define LCD_NORMAL_MODE_ON      0x13   /* Normal Display Mode ON */
#define LCD_DINVOFF             0x20   /* Display Inversion OFF */
#define LCD_DINVON              0x21   /* Display Inversion ON */
#define LCD_GAMMA               0x26   /* Gamma register */
#define LCD_DISPLAY_OFF         0x28   /* Display off register */
#define LCD_DISPLAY_ON          0x29   /* Display on register */

#define LCD_PAGE_ADDR           0x2B   /* Page address register */ 
#define LCD_GRAM                0x2C   /* GRAM register */   
#define LCD_RGBSET              0x2D   /* Color SET */   
#define LCD_RAMRD               0x2E   /* Memory Read */   
#define LCD_PLTAR               0x30   /* Partial Area */   
#define LCD_VSCRDEF             0x33   /* Vertical Scrolling Definition */   
#define LCD_TEOFF               0x34   /* Tearing Effect Line OFF */   
#define LCD_TEON                0x35   /* Tearing Effect Line ON */   
#define LCD_MAC                 0x36   /* Memory Access Control register*/
#define LCD_VSCRSADD            0x37   /* Vertical Scrolling Start Address */   
#define LCD_IDMOFF              0x38   /* Idle Mode OFF */   
#define LCD_IDMON               0x39   /* Idle Mode ON */   
#define LCD_PIXEL_FORMAT        0x3A   /* Pixel Format register */
#define LCD_WRITE_MEM_CONTINUE  0x3C   /* Write Memory Continue */   
#define LCD_READ_MEM_CONTINUE   0x3E   /* Read Memory Continue */   
#define LCD_SET_TEAR_SCANLINE   0x44   /* Set Tear Scanline */   
#define LCD_GET_SCANLINE        0x45   /* Get Scanline */   
#define LCD_WDB                 0x51   /* Write Brightness Display register */
#define LCD_RDDISBV             0x52   /* Read Display Brightness */   
#define LCD_WCD                 0x53   /* Write Control Display register*/
#define LCD_RDCTRLD             0x54   /* Read CTRL Display */   
#define LCD_WRCABC              0x55   /* Write Content Adaptive Brightness Control */   
#define LCD_RDCABC              0x56   /* Read Content Adaptive Brightness Control */   
#define LCD_WRITE_CABC          0x5E   /* Write CABC Minimum Brightness */   
#define LCD_READ_CABC           0x5F   /* Read CABC Minimum Brightness */   
#define LCD_READ_ID1            0xDA   /* Read ID1 */
#define LCD_READ_ID2            0xDB   /* Read ID2 */
#define LCD_READ_ID3            0xDC   /* Read ID3 */

/* Level 2 Commands */
#define LCD_RGB_INTERFACE       0xB0   /* RGB Interface Signal Control */
#define LCD_FRMCTR1             0xB1   /* Frame Rate Control (In Normal Mode) */
#define LCD_FRMCTR2             0xB2   /* Frame Rate Control (In Idle Mode) */
#define LCD_FRMCTR3             0xB3   /* Frame Rate Control (In Partial Mode) */
#define LCD_INVTR               0xB4   /* Display Inversion Control */
#define LCD_BPC                 0xB5   /* Blanking Porch Control register */
#define LCD_DFC                 0xB6   /* Display Function Control register */
#define LCD_ETMOD               0xB7   /* Entry Mode Set */
#define LCD_BACKLIGHT1          0xB8   /* Backlight Control 1 */
#define LCD_BACKLIGHT2          0xB9   /* Backlight Control 2 */
#define LCD_BACKLIGHT3          0xBA   /* Backlight Control 3 */
#define LCD_BACKLIGHT4          0xBB   /* Backlight Control 4 */
#define LCD_BACKLIGHT5          0xBC   /* Backlight Control 5 */
#define LCD_BACKLIGHT7          0xBE   /* Backlight Control 7 */
#define LCD_BACKLIGHT8          0xBF   /* Backlight Control 8 */
#define LCD_POWER1              0xC0   /* Power Control 1 register */
#define LCD_POWER2              0xC1   /* Power Control 2 register */
#define LCD_VCOM1               0xC5   /* VCOM Control 1 register */
#define LCD_VCOM2               0xC7   /* VCOM Control 2 register */
#define LCD_NVMWR               0xD0   /* NV Memory Write */
#define LCD_NVMPKEY             0xD1   /* NV Memory Protection Key */
#define LCD_RDNVM               0xD2   /* NV Memory Status Read */
#define LCD_READ_ID4            0xD3   /* Read ID4 */
#define LCD_PGAMMA              0xE0   /* Positive Gamma Correction register */
#define LCD_NGAMMA              0xE1   /* Negative Gamma Correction register */
#define LCD_DGAMCTRL1           0xE2   /* Digital Gamma Control 1 */
#define LCD_DGAMCTRL2           0xE3   /* Digital Gamma Control 2 */
#define LCD_INTERFACE           0xF6   /* Interface control register */

/* Extend register commands */
#define LCD_POWERA               0xCB   /* Power control A register */
#define LCD_POWERB               0xCF   /* Power control B register */
#define LCD_DTCA                 0xE8   /* Driver timing control A */
#define LCD_DTCB                 0xEA   /* Driver timing control B */
#define LCD_POWER_SEQ            0xED   /* Power on sequence register */
#define LCD_3GAMMA_EN            0xF2   /* 3 Gamma enable register */
#define LCD_PRC                  0xF7   /* Pump ratio control register */

/* Size of read registers */
#define LCD_READ_ID4_SIZE        3      /* Size of Read ID4 */



// HAL_SPI Driver Parameter Definitios

#define s_8                       1         // Amount Of Data To Be Sent & Received = 1 Byte
#define s_16                    2
#define s_24                    3         // Amount Of Data To Be Sent & Received = 3 Byte
#define s_32                    4         // Amount of Data To Be Sent & Received = 4 Byte
#define s_40                    5         // Amount of Data To Be Sent & Received = 5 Byte
#define s_64                    8         // Amount of Data To Be Sent & Received = 8 Byte

//#define s_16                      1         // Amount of Data To Be Sent & Received = 2 Byte
#define s_16_32                   2         // Amount of Data To Be Sent & Received = 4 Byte
#define timeout                  1000       // TIMEOUT DURATION IN MILLISECONDS . In Seconds = 1S 

// Bit Banging In SPI

#define spi_set_mosi() { SPI_DR |= (1 << SPI_MOSI_PIN); }
#define spi_clear_mosi() { SPI_DR &= ~(1 << SPI_MOSI_PIN); }
#define spi_get_miso() (SPI_DR & (1 << SPI_MISO_PIN))

// if CPOL = LOW
#define sck_odd_edge_control() { SPI_DR |= (1 << SPI_SCK_PIN); }
#define sck_even_edge_control() { SPI_DR &= ~(1 << SPI_SCK_PIN); }

// IF CPOL = HIGH  

/*#define sck_odd_edge_control() { SPI_DR &= ~ (1 << SPI_SCK_PIN); }
#define sck_even_edge_control() { SPI_DR |= (1 << SPI_SCK_PIN); }
*/

#ifdef SPI_MOSI
#define mosi_control(b) { (b & msk) ? spi_set_mosi() : spi_clear_mosi(); }
#else
#define mosi_control(b) {} /* no code is provided */
#endif
#ifdef SPI_MISO
#define miso_control(b) { if( spi_get_miso() != 0) b |= msk; }
#else
#define miso_control(b) {} /* no code is provided */
#endif
#define setup_dly() {};/* no code is provided */
#define half_bit_dly() {};
	

	
// LCD I-O FUNCTIONS

void     Lcd_Ton(void);                     // LCD TOUCH ON
void     Lcd_Tof(void);                     // LCD TOUCH OFF
void     Lcd_Bl_Of(void);                   // LCD BACKLIGHT OFF
void     Lcd_Bl_On(void);                   // LCD BACKLIGHT ON
void     Lcd_Set(void);                     // SET LCD
void     Lcd_Rst(void);                     // RESET LCD
void     Lcd_disp_on(void);                 // LCD DISPLAY ON
void     Lcd_disp_of(void);                 // LCD DISPLAY OFF
void     Lcd_norm_on(void);                 // LCD NORMAL MODE ON 
void     Lcd_on(void);                      // LCD CSX LOW
void     Lcd_of(void);                      // LCD CSX HIGH
void     Lcd_normal_mode_on(void);          // LCD NORMAL DISPLAY MODE ON

// SERIAL COMMUNICATION

void     Lcd_S(void);                       // SERIAL DATA TRANSMISSION STARTS
void     Lcd_E(void);                       // SERIAL DATA TRANSMISSION ENDS 



// LCD REGISTER READ FUNCTIONS

uint8_t  Lcd_man_id_r(void);               // LCD MANUFACTURER ID
uint8_t  Lcd_mem_acc_con_r(void);          // READ MEMORY ACCESS CONTROL 




uint8_t  Lcd_dri_ver_r(void);               // READ LCD MODULE DRIVER VERSION
uint8_t  Lcd_dri_id_r(void);               // READ LCD MODULE DRIVER ID
uint8_t Lcd_disp_stat_r(void);             // READ LCD DISPLAY STATUS 
uint8_t Lcd_disp_pow_mod_r(void);          // READ LCD DISPLAY POWER MODE
uint8_t  Lcd_rddsdr_r(void);                // READ LCD SELF DIAGNOSTICS REGISTER 
uint8_t Lcd_column_addr_r(void);           // LCD COLUMN ADDRESS REGISTER READ
uint8_t Lcd_page_addr_r(void);             // LCD PAGE ADDRESS REGISTER READ
uint8_t Lcd_mem_r(void);                   // LCD MEMORY READ 


// LCD REGISTER WRITE FUNCTIONS

void Lcd_column_addr_w(uint8_t sc15_8,uint8_t sc7_0,uint8_t ec15_8,uint8_t ec7_0); // LCD COLUMN ADDRESS REGISTER WRITE 
void Lcd_page_addr_w(uint8_t sp15_8,uint8_t sp7_0,uint8_t ep15_8,uint8_t ep7_0);   // LCD PAGE ADDRESS REGISTER WRITE
void Lcd_mem_acc_con_w(uint8_t data);                                              // WRITE MEMORY ACCESS CONTROL
void Lcd_mem_w(uint32_t data);                                                     // LCD MEMORY WRITE







#endif /* _SPI3_LCD_H */

                    /********End of file***********/


















