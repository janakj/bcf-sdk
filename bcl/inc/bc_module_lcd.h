#ifndef _BC_MODULE_LCD
#define _BC_MODULE_LCD


#include <bc_font_common.h>

//! @addtogroup bc_module_lcd bc_module_lcd
//! @brief Driver for lcd
//! @{

//! @brief Callback events

typedef enum
{
    //! @brief Done event
    BC_MODULE_LCD_EVENT_DONE = 0,

} bc_module_lcd_event_t;


extern const tFont Font;
extern const tFont FontBig;




// See app note https://www.silabs.com/documents/public/application-notes/AN0048.pdf
// Figure 3.1
// 1B mode | 1B addr + 16B data + 1B dummy | 1B dummy END
#define BC_LCD_FRAMEBUFFER_SIZE (1 + ((1+16+1) * 128) + 1)

typedef struct bc_module_lcd_framebuffer_t
{
    uint8_t framebuffer[BC_LCD_FRAMEBUFFER_SIZE];

} bc_module_lcd_framebuffer_t;

bc_module_lcd_framebuffer_t _bc_module_lcd_framebuffer;

//! @brief Initialize lcd

void bc_module_lcd_init(bc_module_lcd_framebuffer_t *framebuffer);
void bc_module_lcd_on(void);
void bc_module_lcd_off(void);
void bc_module_lcd_clear(void);
void bc_module_lcd_draw_pixel(uint8_t x, uint8_t y, bool value);
uint32_t bc_module_lcd_draw_char(uint16_t left, uint16_t top, uint8_t ch);
void bc_module_lcd_draw_string(uint16_t left, uint16_t top, char *str);
void bc_module_lcd_draw(const uint8_t *frame, uint8_t width, uint8_t height); // In pixels
void bc_module_lcd_printf(uint8_t line, /*uint8_t size, font, */const uint8_t *string/*, ...*/);
void bc_module_lcd_update(void);
void bc_module_lcd_set_font(const tFont *font);
//! @}

#endif /* _BC_MODULE_LCD */
