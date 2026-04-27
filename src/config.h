/*------Pin configuration------*/
#ifdef WAVESHARE_RP2350_USB_A
    #define USB_A_HOST
#endif
//#define CUSTOM_LED_PIN 4
//Principal LED
#ifdef CUSTOM_LED_PIN
    #define LED_PIN CUSTOM_LED_PIN           //User custom PIN
#elif PICO_DEFAULT_LED_PIN
    #define LED_PIN PICO_DEFAULT_LED_PIN	//Default LED PIN
#endif

#ifdef PICO_DEFAULT_WS2812_PIN
    #define USE_WS2812_LED                  //WS2812 LED
#endif

//Pin WEB mode
#define WEB_PIN 18

//USB PIO PIN D+
//D- is consecutive
#ifdef USB_A_HOST
    #define PIO_USB_PIN PICO_DEFAULT_PIO_USB_DP_PIN
#elif defined(WAVESHARE_RP2040_ZERO)
    // GPIO16 is used by WS2812 on RP2040 Zero; use GPIO2 for PIO USB D+
    #define PIO_USB_PIN 2
#else
    #define PIO_USB_PIN 16
#endif

#ifdef WAVESHARE_RP2350_USB_A
    // KBD data and clock inputs must be consecutive with
    // data in the lower position.
    #define DAT_GPIO 26 // PS/2 data
    #define CLK_GPIO 27 // PS/2 clock
    // Alternative for PS1/PS2 device mode
    #define ALT_DAT_GPIO 28 	// PS/2 data
    #define ALT_CLK_GPIO 29 	// PS/2 clock

    // CMD, CLK, and ATT pins must be consecutive with CMD in the lower position.
    // No it's necessary the DAT pin be consecutive
    #define CMD 26    		// PSX CMD
    #define CLK CMD + 1     // PSX CLK
    #define ATT CMD + 2     // PSX ATT
    #define DAT 29    		// PSX DAT
    // Alternative for PS1/PS2 device mode
    #define ALT_CMD 2    		    // PSX CMD
    #define ALT_CLK ALT_CMD + 3     // PSX CLK
    #define ALT_ATT ALT_CMD + 4     // PSX ATT
    #define ALT_DAT 5    		    // PSX DAT

    // Gamecube config
    #define GC_DAT_GPIO 29			// GC DATA

    // Nintendo 64 config
    #define N64_DAT_GPIO 29			// N64 DATA
    // Alternative for N64 host mode
    #define ALT_N64_DAT_GPIO 2		// N64 DATA

#elif defined(WAVESHARE_RP2040_ZERO)
    // Waveshare RP2040 Zero profile
    // Available GPIOs: 0-15, 26-29 (GPIO16=WS2812 internal, GPIO17-25 not exposed)
    // GPIO 0,1  : UART TX/RX (debug)
    // GPIO 2,3  : PIO USB D+/D- (host)
    // GPIO 5-8  : PSX primary / GC / N64 primary
    //             PSX device mode shares these pins (CMD=5,CLK=6,SEL=7,DAT=8,ACK=26)
    //             configured in device_files/psx-device/CMakeLists.txt
    // GPIO 9-12 : PSX alt / PS2-KBD primary
    // GPIO 16   : WS2812 LED (internal, do not use)

    // KBD data and clock inputs must be consecutive with
    // data in the lower position.
    #define DAT_GPIO 9  // PS/2 data
    #define CLK_GPIO 10 // PS/2 clock
    // Alternative for PS1/PS2 device mode
    #define ALT_DAT_GPIO 11 // PS/2 data
    #define ALT_CLK_GPIO 12 // PS/2 clock

    // CMD, CLK, and ATT pins must be consecutive with CMD in the lower position.
    // No it's necessary the DAT pin be consecutive
    #define CMD 5       // PSX CMD  (matches PSX device mode pins in CMakeLists.txt)
    #define CLK CMD + 1 // PSX CLK
    #define ATT CMD + 2 // PSX ATT
    #define DAT 8       // PSX DAT
    // Alternative for PS1/PS2 host mode
    #define ALT_CMD 9           // PSX CMD
    #define ALT_CLK ALT_CMD + 1 // PSX CLK
    #define ALT_ATT ALT_CMD + 2 // PSX ATT
    #define ALT_DAT 12          // PSX DAT

    // Gamecube config
    #define GC_DAT_GPIO 5   // GC DATA

    // Nintendo 64 config
    #define N64_DAT_GPIO 5  // N64 DATA
    // Alternative for N64 host mode
    #define ALT_N64_DAT_GPIO 9  // N64 DATA

#else
    // KBD data and clock inputs must be consecutive with
    // data in the lower position.
    #define DAT_GPIO 19 // PS/2 data
    #define CLK_GPIO 20 // PS/2 clock
    // Alternative for PS1/PS2 device mode
    #define ALT_DAT_GPIO 5 	// PS/2 data
    #define ALT_CLK_GPIO 6 	// PS/2 clock

    // CMD, CLK, and ATT pins must be consecutive with CMD in the lower position.
    // No it's necessary the DAT pin be consecutive
    #define CMD 19    		// PSX CMD
    #define CLK CMD + 1     // PSX CLK
    #define ATT CMD + 2     // PSX ATT
    #define DAT 22    		// PSX DAT
    // Alternative for PS1/PS2 host mode
    #define ALT_CMD 5    		    // PSX CMD
    #define ALT_CLK ALT_CMD + 1     // PSX CLK
    #define ALT_ATT ALT_CMD + 2     // PSX ATT
    #define ALT_DAT 8    		    // PSX DAT

    // Gamecube config
    #define GC_DAT_GPIO 19			// GC DATA

    // Nintendo 64 config
    #define N64_DAT_GPIO 19			// N64 DATA
    // Alternative for N64 host mode
    #define ALT_N64_DAT_GPIO 5		// N64 DATA
#endif
