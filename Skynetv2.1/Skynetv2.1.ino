/**
* SKYNET 3D- V2.1 - BASED ON MARLIN RC7-BUGFIX - FOR ANET 3D PRINTERS
* THIS VERSION HAS BEEN CREATED TO SORT OUT THE AUTOLEVEL BUG IN RC7 (V2) 
* 
* ALL CREDITS GO TO MARLIN FIRMWARE https://github.com/MarlinFirmware/Marlin
* 
* DISCALIMER
* I TAKE NO RESPONSIBILITY FOR ANY LOSS OR DAMMAGE THAT MAY OCCUR IF YOU CHOOSE TO MODIFY YOUR PRINTER FROM STOCK FORM.  ALSO DONT HURT YOURSELF! 
* 
* MANY THANKS TO MARC HANNAPELL + JUSTIN KAUFMAN FOR THE SUPPORT DURING DEVELOPMENT
* 
*CHECK OUT JUSTIN + FELIX'S WEBSITE https://3dprint.wiki/ 
*
* ALSO A HUGE THANKS TO THE **OFFICIAL ANET A-SERIES GROUP**  https://www.facebook.com/groups/OFFICIALAnet3DprinterSupportGroup/ 
* 
* AND LAST BUT NOT LEAST THANKS FOR ALL THE SUPPORT FROM YOU GUYS! :)  
* 
* YOUR REVIEWS, DONATIONS AND CUSTOM FROM MY EBAY SHOP HAS REALLY HELPED ALL THIS BECOME REALITY. SO HUGE THANKS!!
* 
* PLEASE CHECK OUT MY FACEBOOK PAGE FOR FUTURE UPDATES https://www.facebook.com/skynet3ddevelopment/ 
* IF YOU WANT TO BUY ME A BEER THEN THERES A DONATE BUTTON ON THE SKYNET FB PAGE.. ALL DONATIONS HELP AND IM VERY APPRECIATIVE :) 
* 
* IF DONATING ISNT FOR YOU THEN MAYBE CONSIDER CHECKING OUT MY EBAY SHOP WHERE I HAVE MODS FOR ANET - INCLUDING SENSORS AND SCREEN UPGRADE BEZELS AND MOSFETS :)
*        
*   http://www.ebay.co.uk/usr/skynet3dmods
*   
*   HAPPY PRINTING- SCOU!
*   
* 
 *PLEASE HEAD TO THE CONFIGURATION.H TAB TO BEGIN SETTING UP FOR YOUR PRINTER ;)
 */

/**
 * About Marlin
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
 * This firmware is a mashup between Sprinter and grbl.
 *  - https://github.com/kliment/Sprinter
 *  - https://github.com/simen/grbl/tree
 *
 * It has preliminary support for Matthew Roberts advance algorithm
 *  - http://reprap.org/pipermail/reprap-dev/2011-May/003323.html
 */

/* All the implementation is done in *.cpp files to get better compatibility with avr-gcc without the Arduino IDE */
/* Use this file to help the Arduino IDE find which Arduino libraries are needed and to keep documentation on GCode */

#include "MarlinConfig.h"

#if ENABLED(ULTRA_LCD)
  #if ENABLED(LCD_I2C_TYPE_PCF8575)
    #include <Wire.h>
    #include <LiquidCrystal_I2C.h>
  #elif ENABLED(LCD_I2C_TYPE_MCP23017) || ENABLED(LCD_I2C_TYPE_MCP23008)
    #include <Wire.h>
    #include <LiquidTWI2.h>
  #elif ENABLED(LCM1602)
    #include <Wire.h>
    #include <LCD.h>
    #include <LiquidCrystal_I2C.h>
  #elif ENABLED(DOGLCD)
    #include <U8glib.h> // library for graphics LCD by Oli Kraus (https://github.com/olikraus/U8glib_Arduino)
  #else
    #include <LiquidCrystal.h> // library for character LCD
  #endif
#endif

#if HAS_DIGIPOTSS
  #include <SPI.h>
#endif

#if ENABLED(DIGIPOT_I2C)
  #include <Wire.h>
#endif

#if ENABLED(HAVE_TMCDRIVER)
  #include <SPI.h>
  #include <TMC26XStepper.h>
#endif

#if ENABLED(HAVE_TMC2130DRIVER)
  #include <SPI.h>
  #include <Trinamic_TMC2130.h>
#endif

#if ENABLED(HAVE_L6470DRIVER)
  #include <SPI.h>
  #include <L6470.h>
#endif
