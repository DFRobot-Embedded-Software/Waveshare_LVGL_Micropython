
from micropython import const
import lcd_bus
import lvgl as lv
import rgb_display
import time

_WIDTH = const(800)
_HEIGHT = const(480)

class Screen(object):
    def __init__(self,dir=2):
        self.display_bus = lcd_bus.RGBBus(
            hsync=46,
            vsync=3,
            de=5,
            pclk=7,
            data0=14,
            data1=38,
            data2=18,
            data3=17,
            data4=10,
            data5=39,
            data6=0,
            data7=45,
            data8=48,
            data9=47,
            data10=21,
            data11=1,
            data12=2,
            data13=42,
            data14=41,
            data15=40,
            freq=12000000, # The display creeps if this is too fast
            hsync_idle_low=False,
            hsync_front_porch = 8,
            hsync_pulse_width = 4,
            hsync_back_porch  = 8,
            vsync_idle_low=False,
            vsync_front_porch = 8,
            vsync_pulse_width = 4,
            vsync_back_porch  = 8,
            de_idle_high=False,
            pclk_idle_high=False,
            pclk_active_low=1,
            )
        '''
        self.display = ili9341.ILI9341(data_bus = self.display_bus, display_width = 240, display_height = 320,
                                       reset_state = ili9341.STATE_LOW, color_byte_order = ili9341.BYTE_ORDER_BGR,
                                       color_space = lv.COLOR_FORMAT.RGB565, rgb565_byte_swap=True)
        '''
        self.display = rgb_display.RGBDisplay(
            data_bus=self.display_bus,
            display_width=_WIDTH,
            display_height=_HEIGHT,
            backlight_on_state=rgb_display.STATE_PWM,
            color_space=lv.COLOR_FORMAT.RGB565,
            rgb565_byte_swap=False
            )
        
    #初始化屏幕，设置方向为(0~3)
    def init(self,dir=2):
        #用来打开屏幕背光
        self.display.set_power(True)
        self.display.init()
        self.display.set_backlight(100)
        if dir == 0:
            self.display.set_rotation(lv.DISPLAY_ROTATION._0)
        elif dir == 1:
            self.display.set_rotation(lv.DISPLAY_ROTATION._90)
        elif dir == 2:
            self.display.set_rotation(lv.DISPLAY_ROTATION._180)
        elif dir == 3:
            self.display.set_rotation(lv.DISPLAY_ROTATION._270)
        else:
            self.display.set_rotation(lv.DISPLAY_ROTATION._180)

screen = Screen()