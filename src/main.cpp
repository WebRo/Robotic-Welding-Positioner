/*
================================================================================
                    Ù†Ø¸Ø§Ù… ØªØ­ÙƒÙ… Ø¨Ø·Ø¨Ù‚ Ù„Ø­Ø§Ù… Ø¢Ù„ÙŠ - Arduino Mega Sketch
                    Automated Welding Turntable Control System
================================================================================

Ø§Ù„Ù…Ø´Ø±ÙˆØ¹: Ù†Ø¸Ø§Ù… ØªØ­ÙƒÙ… Ø¨Ø·Ø¨Ù‚ Ù„Ø­Ø§Ù… Ø¢Ù„ÙŠ Ù…ØªÙƒØ§Ù…Ù„ Ù…Ø¹ Node-RED Ùˆ Ø§Ù„Ø±ÙˆØ¨ÙˆØª Ø§Ù„ØªØ¹Ø§ÙˆÙ†ÙŠ (COBOT)
Ø§Ù„Ø¥ØµØ¯Ø§Ø±: 5.0 (Ø§Ù„Ù†Ø³Ø®Ø© Ø§Ù„Ù†Ù‡Ø§Ø¦ÙŠØ© Ù…Ø¹ ÙˆØ¶Ø¹ Ø§Ù„ØªÙƒÙˆÙŠÙ† Ø§Ù„ÙŠØ¯ÙˆÙŠ ÙˆØ§Ù„ØªØ¹Ù„ÙŠÙ‚Ø§Øª Ø§Ù„Ù…ÙØµÙ„Ø©)
Ø§Ù„Ù„ÙˆØ­Ø©: Arduino Mega 2560
ØªØ§Ø±ÙŠØ® Ø§Ù„ØªØ­Ø¯ÙŠØ«: 25 Ø£Ø¨Ø±ÙŠÙ„ 2026

Ø§Ù„Ù…ÙŠØ²Ø§Øª Ø§Ù„Ø¬Ø¯ÙŠØ¯Ø© Ø¨Ù†Ø§Ø¡Ù‹ Ø¹Ù„Ù‰ Ø§Ù„Ø·Ù„Ø¨ Ø§Ù„Ø£Ø®ÙŠØ±:
- Ø¹Ø¯Ù… Ø­Ø°Ù Ø£ÙŠ Ù†Ù‚Ø§Ø· Ù…Ø­ÙÙˆØ¸Ø© Ø¹Ù†Ø¯ Ø¹Ù…Ù„ Homing Ø£Ùˆ Ø¥ÙŠÙ‚Ø§Ù Ø§Ù„Ø·ÙˆØ§Ø±Ø¦.
- Ø²Ø± HOLD Ø£Ø«Ù†Ø§Ø¡ Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬ ÙŠÙˆÙ‚Ù Ø§Ù„Ø¹Ù…Ù„ ÙˆÙŠØ·Ù„Ø¨ Homing Ø¬Ø¯ÙŠØ¯.
- Ø£Ø²Ø±Ø§Ø± Ø§Ù„ØªØ­ÙƒÙ… Ø§Ù„ÙŠØ¯ÙˆÙŠØ©: Ø§Ù„ØªØ­Ø±Ùƒ Ù„Ù„Ø£Ù…Ø§Ù…/Ù„Ù„Ø®Ù„ÙØŒ Ø§Ù„ØªÙˆÙ‚ÙØŒ Ø§Ù„Ø¥Ø¶Ø§ÙØ© Ù„Ù„Ù‚Ø§Ø¦Ù…Ø©.
================================================================================
*/

// ============================================================================
// Ø¯Ù„ÙŠÙ„ ØªÙˆØµÙŠÙ„ Ù…Ø´ØºÙ„ Ø§Ù„Ù…Ø­Ø±Ùƒ (TB6600 Microstep Driver)
// ============================================================================
/*
 Ø§Ù„Ù…Ø´ØºÙ„ Ø§Ù„Ù…Ø±ÙÙ‚ ÙÙŠ ØµÙˆØ±ØªÙƒ ÙŠØ­ØªØ§Ø¬ Ù„ØªÙˆØµÙŠÙ„ Ù…Ù† Ù†ÙˆØ¹ (Ø§Ù„Ø³Ø§Ù„Ø¨ Ø§Ù„Ù…Ø´ØªØ±Ùƒ - Common Cathode)
 Ù…Ø¹ Ù„ÙˆØ­Ø© Ø§Ù„Ø£Ø±Ø¯ÙˆÙŠÙ†Ùˆ (Arduino Mega) Ù„ÙŠØ¹Ù…Ù„ Ø¨Ø´ÙƒÙ„ Ù…ØªÙˆØ§ÙÙ‚ 100% Ù…Ø¹ Ù‡Ø°Ø§ Ø§Ù„ÙƒÙˆØ¯:

 [1] Ù‚Ø³Ù… Ø¥Ø´Ø§Ø±Ø§Øª Ø§Ù„ØªØ­ÙƒÙ… (Signal Interface - ÙŠÙØ±Ø¨Ø· Ø¨Ø§Ù„Ø£Ø±Ø¯ÙˆÙŠÙ†Ùˆ):
 -----------------------------------------------------------------
 â€¢ (PUL-) Ùˆ (DIR-) Ùˆ (ENA-) : Ø§Ø±Ø¨Ø· Ù‡Ø°Ù‡ Ø§Ù„Ù…Ø¯Ø§Ø®Ù„ Ø§Ù„Ø«Ù„Ø§Ø«Ø© Ù…Ø¹Ø§Ù‹ (Ø¨ÙƒÙˆØ¨Ø±ÙŠ ØµØºÙŠØ±)ØŒ Ø«Ù…
 ØµÙ„Ù‡Ø§ Ø¨Ù…Ù†ÙØ° Ø§Ù„Ø£Ø±Ø¶ÙŠ (GND) ÙÙŠ Ø§Ù„Ø£Ø±Ø¯ÙˆÙŠÙ†Ùˆ. â€¢ (PUL+) [Ù†Ø¨Ø¶Ø© Ø§Ù„Ø®Ø·ÙˆØ©]   : ÙŠÙÙˆØµÙ„ Ø¨Ø§Ù„Ù…Ù†ÙØ°
 Ø±Ù‚Ù… (5) ÙÙŠ Ø§Ù„Ø£Ø±Ø¯ÙˆÙŠÙ†Ùˆ. â€¢ (DIR+) [ØªØ­Ø¯ÙŠØ¯ Ø§Ù„Ø§ØªØ¬Ø§Ù‡] : ÙŠÙÙˆØµÙ„ Ø¨Ø§Ù„Ù…Ù†ÙØ° Ø±Ù‚Ù… (6) ÙÙŠ
 Ø§Ù„Ø£Ø±Ø¯ÙˆÙŠÙ†Ùˆ. â€¢ (ENA+) [ØªÙØ¹ÙŠÙ„ Ø§Ù„Ù…Ø­Ø±Ùƒ]  : ÙŠÙÙˆØµÙ„ Ø¨Ø§Ù„Ù…Ù†ÙØ° Ø±Ù‚Ù… (7) ÙÙŠ Ø§Ù„Ø£Ø±Ø¯ÙˆÙŠÙ†Ùˆ.
   *Ù…Ù„Ø§Ø­Ø¸Ø© Ø¨Ø±Ù…Ø¬ÙŠØ©: Ø¥Ø±Ø³Ø§Ù„ (LOW) Ù„Ù…Ù†ÙØ° Ø§Ù„Ù€ ENA ÙŠÙØ´ØºÙ„ Ø§Ù„Ù…Ø­Ø±ÙƒØŒ ÙˆØ¥Ø±Ø³Ø§Ù„ (HIGH) ÙŠÙØµÙ„
 Ø·Ø§Ù‚ØªÙ‡ Ù„Ø¥Ø±Ø§Ø­ØªÙ‡.

 [2] Ù‚Ø³Ù… Ø£Ø³Ù„Ø§Ùƒ Ø§Ù„Ù…Ø­Ø±Ùƒ Ø§Ù„Ø®Ø·ÙˆÙŠ (Motor Interface):
 -----------------------------------------------------------------
 â€¢ (A+) Ùˆ (A-) : ÙŠÙÙˆØµÙ„Ø§Ù† Ø¨Ø§Ù„Ø³Ù„ÙƒÙŠÙ† Ø§Ù„Ø®Ø§ØµÙŠÙ† Ø¨Ø§Ù„Ù…Ù„Ù Ø§Ù„Ø£ÙˆÙ„ Ù„Ù„Ù…Ø­Ø±Ùƒ (Phase A).
 â€¢ (B+) Ùˆ (B-) : ÙŠÙÙˆØµÙ„Ø§Ù† Ø¨Ø§Ù„Ø³Ù„ÙƒÙŠÙ† Ø§Ù„Ø®Ø§ØµÙŠÙ† Ø¨Ø§Ù„Ù…Ù„Ù Ø§Ù„Ø«Ø§Ù†ÙŠ Ù„Ù„Ù…Ø­Ø±Ùƒ (Phase B).
   *Ù„Ù…Ø¹Ø±ÙØ© Ø§Ù„Ø£Ø³Ù„Ø§Ùƒ Ø§Ù„Ù…Ø²Ø¯ÙˆØ¬Ø©ØŒ ÙŠÙ…ÙƒÙ†Ùƒ Ø§Ø³ØªØ®Ø¯Ø§Ù… Ù…Ù‚ÙŠØ§Ø³ Ø§Ù„Ù…Ù‚Ø§ÙˆÙ…Ø© (Avometer) Ø£Ùˆ ØªÙ„Ø§Ù…Ø³
 Ø§Ù„Ø£Ø³Ù„Ø§Ùƒ.

 [3] Ù‚Ø³Ù… Ø§Ù„Ø·Ø§Ù‚Ø© Ø§Ù„Ø±Ø¦ÙŠØ³ÙŠØ© (Power Interface):
 -----------------------------------------------------------------
 â€¢ (VCC) : ÙŠÙÙˆØµÙ„ Ø¨Ø§Ù„Ù…ÙˆØ¬Ø¨ (+) Ù„Ù…ØµØ¯Ø± Ø·Ø§Ù‚Ø© Ø®Ø§Ø±Ø¬ÙŠ (Ù…Ø­ÙˆÙ„ 12 ÙÙˆÙ„Øª Ø£Ùˆ 24 ÙÙˆÙ„Øª DC).
 â€¢ (GND) : ÙŠÙÙˆØµÙ„ Ø¨Ø§Ù„Ø³Ø§Ù„Ø¨ (-) Ù„Ù†ÙØ³ Ù…ØµØ¯Ø± Ø§Ù„Ø·Ø§Ù‚Ø© Ø§Ù„Ø®Ø§Ø±Ø¬ÙŠ.

 âš ï¸ ØªØ­Ø°ÙŠØ± Ø£Ù…Ø§Ù† Ù‡Ø§Ù… Ø¬Ø¯Ø§Ù‹: Ù„Ø§ ØªÙ‚Ù… Ø£Ø¨Ø¯Ø§Ù‹ Ø¨ÙØµÙ„ Ø£Ùˆ ØªØ±ÙƒÙŠØ¨ Ø£Ø³Ù„Ø§Ùƒ Ø§Ù„Ù…Ø­Ø±Ùƒ (A Ùˆ B) Ø¨ÙŠÙ†Ù…Ø§ ØªÙƒÙˆÙ†
 Ø·Ø§Ù‚Ø© Ø§Ù„Ù€ 12V/24V Ù…ÙˆØµÙ„Ø© Ø¨Ø§Ù„Ø¯Ø±Ø§ÙŠÙØ±ØŒ Ù„Ø£Ù† Ø°Ù„Ùƒ Ø³ÙŠØªÙ„Ù Ø§Ù„Ø¯Ø±Ø§ÙŠÙØ± ÙÙˆØ±Ø§Ù‹!
*/

// ============================================================================
// [1] Ø§Ø³ØªØ¯Ø¹Ø§Ø¡ Ø§Ù„Ù…ÙƒØªØ¨Ø§Øª Ø§Ù„Ø£Ø³Ø§Ø³ÙŠØ© (Libraries)
// ============================================================================
#include <AccelStepper.h> // Ù…ÙƒØªØ¨Ø© Ù„Ù„ØªØ­ÙƒÙ… Ø§Ù„Ø¯Ù‚ÙŠÙ‚ Ø¨Ø­Ø±ÙƒØ© Ø§Ù„Ù…Ø­Ø±Ùƒ Ø§Ù„Ø®Ø·ÙˆÙŠ (Ø§Ù„ØªØ³Ø§Ø±Ø¹ ÙˆØ§Ù„Ø³Ø±Ø¹Ø©)
#include <Adafruit_NeoPixel.h> // Ù…ÙƒØªØ¨Ø© Ù„Ù„ØªØ­ÙƒÙ… ÙÙŠ Ø§Ù„Ø¥Ø¶Ø§Ø¡Ø© Ø§Ù„Ø°ÙƒÙŠØ© (Ù„Ù…Ø¨Ø© LED ÙˆØ§Ø­Ø¯Ø©)
#include <Arduino.h> // Ù…ÙƒØªØ¨Ø© Ø§Ù„Ø£Ø±Ø¯ÙˆÙŠÙ†Ùˆ Ø§Ù„Ø£Ø³Ø§Ø³ÙŠØ© (Ù…Ù‡Ù…Ø© Ù„ÙƒÙ„ Ø§Ù„Ù…Ø´Ø§Ø±ÙŠØ¹)

// ============================================================================
// [2] ØªØ¹Ø±ÙŠÙØ§Øª Ø£Ø·Ø±Ø§Ù Ø§Ù„ØªÙˆØµÙŠÙ„ Ù„Ù„Ø£Ø¬Ù‡Ø²Ø© (Hardware Pins)
// ============================================================================

// Ø£Ø·Ø±Ø§Ù Ø§Ù„Ù…Ø­Ø±Ùƒ Ø§Ù„Ø®Ø·ÙˆÙŠ (Stepper Motor Pins)
const int STEP_PIN = 5; // Ø§Ù„Ù…Ø®Ø±Ø¬ Ø§Ù„Ù…Ø³Ø¤ÙˆÙ„ Ø¹Ù† Ø¥Ø±Ø³Ø§Ù„ Ø§Ù„Ù†Ø¨Ø¶Ø§Øª Ù„Ù„Ù…Ø­Ø±Ùƒ Ù„Ù„ØªØ­Ø±Ùƒ
const int DIR_PIN = 6; // Ø§Ù„Ù…Ø®Ø±Ø¬ Ø§Ù„Ù…Ø³Ø¤ÙˆÙ„ Ø¹Ù† ØªØ­Ø¯ÙŠØ¯ Ø§ØªØ¬Ø§Ù‡ Ø¯ÙˆØ±Ø§Ù† Ø§Ù„Ù…Ø­Ø±Ùƒ
const int ENABLE_PIN = 7; // Ø§Ù„Ù…Ø®Ø±Ø¬ Ø§Ù„Ù…Ø³Ø¤ÙˆÙ„ Ø¹Ù† ØªÙØ¹ÙŠÙ„/Ø¥ÙŠÙ‚Ø§Ù Ø§Ù„Ù…Ø­Ø±Ùƒ (LOW = ØªØ´ØºÙŠÙ„)

// Ø£Ø·Ø±Ø§Ù Ù…Ø³ØªØ´Ø¹Ø±Ø§Øª Ø§Ù„Ù…ÙˆØ¶Ø¹ (Sensor)
const int SENSOR_PIN = 8; // Ù…Ø¯Ø®Ù„ Ù…Ø³ØªØ´Ø¹Ø± Ø§Ù„Ø¹ÙˆØ¯Ø© Ù„Ù„ØµÙØ± (Homing Sensor)
#define SENSOR_HOME_STATE                                                      \
  LOW // ØªÙ… Ø§Ù„ØªØ¹Ø¯ÙŠÙ„ Ø¥Ù„Ù‰ LOW Ù„Ø§Ø³ØªØ®Ø¯Ø§Ù… Ø§Ù„Ù…Ù‚Ø§ÙˆÙ…Ø© Ø§Ù„Ø¯Ø§Ø®Ù„ÙŠØ© Ù„Ù…Ù†Ø¹ Ø§Ù„ØªØ´ÙˆÙŠØ´

// Ø£Ø·Ø±Ø§Ù Ø§Ù„ØªÙˆØ§ØµÙ„ Ù…Ø¹ Ø§Ù„Ø±ÙˆØ¨ÙˆØª Ø§Ù„ØªØ¹Ø§ÙˆÙ†ÙŠ (Cobot Relays)
const int RELAY_TO_COBOT =
    9;
const int RELAY_TO_COBOT_OFF = HIGH;
const int RELAY_TO_COBOT_ON = LOW; // ØªÙØ¹ÙŠÙ„ Ø±ÙŠÙ„Ø§ÙŠ Ø§Ù„Ø±ÙˆØ¨ÙˆØª ÙŠÙƒÙˆÙ† Ø¨Ø¥Ø®Ø±Ø§Ø¬ LOW Ù„Ø£Ù† Ø§Ù„Ø±ÙŠÙ„Ø§ÙŠ ÙŠØ¹Ù…Ù„ Ø¨Ù†Ø¸Ø§Ù… Active-Low
const int RELAY_FROM_COBOT =
    10; // Ù…Ø¯Ø®Ù„ Ù„Ø§Ø³ØªÙ‚Ø¨Ø§Ù„ Ø¥Ø´Ø§Ø±Ø© Ù…Ù† Ø§Ù„Ø±ÙˆØ¨ÙˆØª ØªÙÙŠØ¯ Ø¨Ø£Ù†Ù‡ Ø§Ù†ØªÙ‡Ù‰ Ù…Ù† Ø§Ù„Ù„Ø­Ø§Ù…

// Ø£Ø·Ø±Ø§Ù Ø¥Ø¶Ø§Ø¡Ø© Ø§Ù„Ø­Ø§Ù„Ø© (Status LED)
const int LED_PIN = 11; // Ù…Ø®Ø±Ø¬ Ø¥Ø±Ø³Ø§Ù„ Ø§Ù„Ø¨ÙŠØ§Ù†Ø§Øª Ù„Ù„Ù…Ø¨Ø© LED WS2812
const int LED_COUNT =
    1; // Ø¹Ø¯Ø¯ Ø§Ù„Ù„Ù…Ø¨Ø§Øª Ø§Ù„Ù…Ø³ØªØ®Ø¯Ù…Ø© ÙÙŠ Ø§Ù„Ø´Ø±ÙŠØ· (Ù†Ø³ØªØ®Ø¯Ù… Ù„Ù…Ø¨Ø© ÙˆØ§Ø­Ø¯Ø© ÙÙ‚Ø·)

// ============================================================================
// [3] Ø¥Ø¹Ø¯Ø§Ø¯Ø§Øª Ø§Ù„Ø­Ø±ÙƒØ© ÙˆØ§Ù„ØªÙˆÙ‚ÙŠØª (Timing & Motor Specifications)
// ============================================================================

// Ø¥Ø¹Ø¯Ø§Ø¯Ø§Øª Ø³Ø±Ø¹Ø§Øª Ø§Ù„Ù…Ø­Ø±Ùƒ
#define MAX_SPEED 1000.0 // Ø£Ù‚ØµÙ‰ Ø³Ø±Ø¹Ø© ÙŠØµÙ„ Ù„Ù‡Ø§ Ø§Ù„Ù…Ø­Ø±Ùƒ (Ø¨Ø§Ù„Ù†Ø¨Ø¶Ø§Øª ÙÙŠ Ø§Ù„Ø«Ø§Ù†ÙŠØ©)
#define ACCELERATION                                                           \
  500.0 // Ù…Ù‚Ø¯Ø§Ø± ØªØ³Ø§Ø±Ø¹ ÙˆØªØ¨Ø§Ø·Ø¤ Ø§Ù„Ù…Ø­Ø±Ùƒ (Ù„ØªØ¬Ù†Ø¨ Ø§Ù„Ø§Ù‡ØªØ²Ø§Ø² ÙˆØ§Ù„Ù‚ÙØ²Ø§Øª)
#define HOMING_SPEED                                                           \
  300.0 // Ø³Ø±Ø¹Ø© Ø§Ù„Ù…Ø­Ø±Ùƒ Ø£Ø«Ù†Ø§Ø¡ Ø¹Ù…Ù„ÙŠØ© Ø§Ù„Ø¨Ø­Ø« Ø¹Ù† Ù†Ù‚Ø·Ø© Ø§Ù„ØµÙØ± (Ù†Ø¬Ø¹Ù„Ù‡Ø§ Ø¨Ø·ÙŠØ¦Ø© Ù„Ù„Ø£Ù…Ø§Ù†)
#define MANUAL_SPEED                                                           \
  500.0 // Ù…Ù‚Ø¯Ø§Ø± ØªØ³Ø§Ø±Ø¹ ÙˆØªØ¨Ø§Ø·Ø¤ Ø§Ù„Ù…Ø­Ø±Ùƒ (Ù„ØªØ¬Ù†Ø¨ Ø§Ù„Ø§Ù‡ØªØ²Ø§Ø² ÙˆØ§Ù„Ù‚ÙØ²Ø§Øª)

// Ø¥Ø¹Ø¯Ø§Ø¯Ø§Øª Ø§Ù„Ø¯Ø±Ø¬Ø§Øª ÙˆØ§Ù„Ù†Ø³Ø¨
#define STEPS_PER_REVOLUTION                                                   \
  200 // Ø¹Ø¯Ø¯ Ø§Ù„Ù†Ø¨Ø¶Ø§Øª Ø§Ù„Ù„Ø§Ø²Ù…Ø© Ù„Ø¹Ù…Ù„ Ø¯ÙˆØ±Ø© ÙƒØ§Ù…Ù„Ø© Ù„Ù„Ù…Ø­Ø±Ùƒ (Ù‚ÙŠØ§Ø³ÙŠ)

// Ø¥Ø¹Ø¯Ø§Ø¯Ø§Øª Ø§Ù„ØªÙˆÙ‚ÙŠØªØ§Øª Ø§Ù„Ø¯Ù‚ÙŠÙ‚Ø© (Ø¨Ø§Ù„Ù…Ù„ÙŠ Ø«Ø§Ù†ÙŠØ©)
#define RELAY_PULSE_MS                                                         \
  1000 // Ù…Ø¯Ø© Ø§Ù„Ù†Ø¨Ø¶Ø© Ø§Ù„ØªÙŠ ØªØ±Ø³Ù„ Ù„Ù„Ø±ÙˆØ¨ÙˆØª Ù„Ù„Ø¨Ø¯Ø¡ (ÙŠØ¬Ø¨ Ø£Ù† ØªÙƒÙˆÙ† 1 Ø«Ø§Ù†ÙŠØ© Ø¨Ø§Ù„Ø¶Ø¨Ø·)
#define COBOT_TIMEOUT_MS                                                       \
  120000 // Ù…Ù‡Ù„Ø© Ø§Ù„Ø§Ù†ØªØ¸Ø§Ø± Ù„Ù„Ø±ÙˆØ¨ÙˆØª (Ø¯Ù‚ÙŠÙ‚ØªÙŠÙ†ØŒ Ø¥Ø°Ø§ ØªØ£Ø®Ø± ÙŠØ¹ØªØ¨Ø± Ø®Ø·Ø£)
#define HOMING_TIMEOUT_MS                                                      \
  30000 // Ù…Ù‡Ù„Ø© Ø¹Ù…Ù„ÙŠØ© Ø§Ù„ØªØµÙÙŠØ± (30 Ø«Ø§Ù†ÙŠØ© Ù„ØªØ¬Ù†Ø¨ Ø¯ÙˆØ±Ø§Ù† Ø§Ù„Ù…Ø­Ø±Ùƒ Ù„Ù„Ø£Ø¨Ø¯ Ø¥Ø°Ø§ ÙƒØ§Ù†
        // Ø§Ù„Ù…Ø³ØªØ´Ø¹Ø± ØªØ§Ù„ÙØ§Ù‹)
#define STATUS_UPDATE_INTERVAL_MS                                              \
  100 // Ù…Ø¹Ø¯Ù„ Ø¥Ø±Ø³Ø§Ù„ ØªØ­Ø¯ÙŠØ« Ø§Ù„Ø²Ø§ÙˆÙŠØ© Ù„Ù€ Node-RED (ÙƒÙ„ 100 Ù…Ù„ÙŠ Ø«Ø§Ù†ÙŠØ©)
#define COUNTDOWN_UPDATE_INTERVAL_MS                                           \
  1000 // Ù…Ø¯Ø© Ø§Ù„Ù†Ø¨Ø¶Ø© Ø§Ù„ØªÙŠ ØªØ±Ø³Ù„ Ù„Ù„Ø±ÙˆØ¨ÙˆØª Ù„Ù„Ø¨Ø¯Ø¡ (ÙŠØ¬Ø¨ Ø£Ù† ØªÙƒÙˆÙ† 1 Ø«Ø§Ù†ÙŠØ© Ø¨Ø§Ù„Ø¶Ø¨Ø·)
#define PROGRAM_ACCELERATION                                                   \
  3000.0 // ØªØ³Ø§Ø±Ø¹ Ù…Ø¹Ù‚ÙˆÙ„ Ù„Ø¶Ù…Ø§Ù† Ø§Ù„Ø¯Ù‚Ø© ÙˆÙ…Ù†Ø¹ ÙÙ‚Ø¯Ø§Ù† Ø§Ù„Ø®Ø·ÙˆØ§Øª Ø£Ø«Ù†Ø§Ø¡ Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬
#define START_DELAY_MS \
  2000 // ØªØ£Ø®ÙŠØ± 2 Ø«Ø§Ù†ÙŠØ© Ø¨Ø¹Ø¯ Ø§Ø³ØªÙ„Ø§Ù… Ø¥Ø´Ø§Ø±Ø© Ø§Ù„Ø±ÙˆØ¨ÙˆØª Ù‚Ø¨Ù„ Ø¨Ø¯Ø¡ Ø­Ø±ÙƒØ© Ø§Ù„Ø·Ø§ÙˆÙ„Ø©

// ============================================================================
// [4] Ø£Ù„ÙˆØ§Ù† Ø§Ù„Ø¥Ø¶Ø§Ø¡Ø© (LED Status Colors)
// ============================================================================

const uint32_t LED_GREEN = Adafruit_NeoPixel::Color(
    0, 255, 0); // Ø£Ø®Ø¶Ø±: Ø§Ù„Ù†Ø¸Ø§Ù… Ø¬Ø§Ù‡Ø² Ù„Ù„Ø¹Ù…Ù„ØŒ Ø£Ùˆ Ø§Ù†ØªÙ‡Øª Ø§Ù„Ù…Ù‡Ù…Ø© Ø¨Ù†Ø¬Ø§Ø­
const uint32_t LED_BLUE = Adafruit_NeoPixel::Color(
    0, 0, 255); // Ø£Ø²Ø±Ù‚: Ø§Ù„Ù…Ø­Ø±Ùƒ ÙŠØªØ­Ø±Ùƒ Ø§Ù„Ø¢Ù† (ØªØµÙÙŠØ± Ø£Ùˆ Ø­Ø±ÙƒØ© Ù„Ø²Ø§ÙˆÙŠØ©)
const uint32_t LED_YELLOW = Adafruit_NeoPixel::Color(
    255, 255, 0); // Ø£ØµÙØ±: Ø¥Ù…Ø§ Ø§Ù„Ø±ÙˆØ¨ÙˆØª ÙŠÙ„Ø­Ù…ØŒ Ø£Ùˆ Ø£Ù† Ø§Ù„Ø²Ø§ÙˆÙŠØ© ØªÙ… Ø­ÙØ¸Ù‡Ø§ ÙŠØ¯ÙˆÙŠØ§Ù‹
const uint32_t LED_RED = Adafruit_NeoPixel::Color(
    255, 0, 0); // Ø£Ø­Ù…Ø±: Ø®Ø·Ø£ØŒ Ø£Ùˆ ØªÙ… Ø¶ØºØ· Ø²Ø± Ø§Ù„Ø·ÙˆØ§Ø±Ø¦ ÙˆÙŠØ·Ù„Ø¨ ØªØµÙÙŠØ± Ø¬Ø¯ÙŠØ¯

// ============================================================================
// [5] Ø­Ø§Ù„Ø§Øª Ø§Ù„Ù†Ø¸Ø§Ù… (System States Machine)
// ============================================================================

enum SystemState {
  IDLE, // Ø­Ø§Ù„Ø© Ø§Ù„Ø¬Ø§Ù‡Ø²ÙŠØ© (Ø§Ù„Ù†Ø¸Ø§Ù… Ù…ØªÙˆÙ‚Ù ÙˆÙŠÙ†ØªØ¸Ø± Ø£ÙˆØ§Ù…Ø±)
  HOMING, // Ø­Ø§Ù„Ø© Ø§Ù„ØªØµÙÙŠØ± (Ø§Ù„Ù…Ø­Ø±Ùƒ ÙŠØ¨Ø­Ø« Ø¹Ù† Ø§Ù„Ù…Ø³ØªØ´Ø¹Ø±)
  MANUAL_MOVING, // Ø­Ø§Ù„Ø© Ø§Ù„Ø¯ÙˆØ±Ø§Ù† Ø§Ù„ÙŠØ¯ÙˆÙŠ Ø§Ù„Ù…Ø³ØªÙ…Ø± (Ø¹Ù†Ø¯ Ø¶ØºØ· Move F/B)
  MANUAL_DECELERATING, // Ø­Ø§Ù„Ø© Ø§Ù„ØªØ¨Ø§Ø·Ø¤ (Ø¹Ù†Ø¯ Ø¶ØºØ· HOLD Ù„ÙŠØªÙˆÙ‚Ù Ø§Ù„Ù…Ø­Ø±Ùƒ Ø¨Ù†Ø¹ÙˆÙ…Ø©)
  MANUAL_HOLD, // Ø­Ø§Ù„Ø© Ø§Ù„ØªÙˆÙ‚Ù Ø§Ù„ØªØ§Ù… (Ù…ØªÙˆÙ‚Ù ÙˆØ¬Ø§Ù‡Ø² Ù„ÙŠØªÙ… Ø­ÙØ¸ Ø§Ù„Ø²Ø§ÙˆÙŠØ© Ø¨Ø²Ø± ADD)
  ARMED, // *** Ø¬Ø¯ÙŠØ¯ *** Ø§Ù„Ù†Ø¸Ø§Ù… Ù…ÙØ³Ù„ÙŽÙ‘Ø­ ÙˆÙŠÙ†ØªØ¸Ø± Ø¥Ø´Ø§Ø±Ø© Ø§Ù„Ø±ÙˆØ¨ÙˆØª (Pin 10) Ù„Ø¨Ø¯Ø¡/Ø¥Ø¹Ø§Ø¯Ø© Ø§Ù„Ø¯ÙˆØ±Ø©
  DELAY_BEFORE_START, // *** Ø¬Ø¯ÙŠØ¯ *** Ø§Ù†ØªØ¸Ø§Ø± 2 Ø«Ø§Ù†ÙŠØ© Ø¨Ø¹Ø¯ Ø§Ø³ØªÙ„Ø§Ù… Ø¥Ø´Ø§Ø±Ø© Ø§Ù„Ø±ÙˆØ¨ÙˆØª Ù‚Ø¨Ù„ ØªØ­Ø±ÙŠÙƒ Ø§Ù„Ø·Ø§ÙˆÙ„Ø©
  PROGRAM_MOVING, // Ø­Ø§Ù„Ø© ØªÙ†ÙÙŠØ° Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬ (ÙŠØªØ­Ø±Ùƒ Ù„Ù„Ø²Ø§ÙˆÙŠØ© Ø§Ù„ØªØ§Ù„ÙŠØ© ÙÙŠ Ø§Ù„Ù‚Ø§Ø¦Ù…Ø©)
  RELAY_ACTIVE, // Ø­Ø§Ù„Ø© ØªÙØ¹ÙŠÙ„ Ø§Ù„Ø±ÙŠÙ„Ø§ÙŠ (Ø¥Ø±Ø³Ø§Ù„ Ø¥Ø´Ø§Ø±Ø© 1 Ø«Ø§Ù†ÙŠØ© Ù„Ù„Ø±ÙˆØ¨ÙˆØª)
  WAITING_COBOT, // Ø­Ø§Ù„Ø© Ø§Ù†ØªØ¸Ø§Ø± Ø§Ù„Ø±ÙˆØ¨ÙˆØª (ÙŠÙ†ØªØ¸Ø± Ø±Ø¯ Ø§Ù„Ø±ÙˆØ¨ÙˆØª Ø¨Ø£Ù†Ù‡ Ø§Ù†ØªÙ‡Ù‰)
  DELAY_BEFORE_MOVE, // Ø­Ø§Ù„Ø© Ø§Ù„Ø§Ù†ØªØ¸Ø§Ø± 3 Ø«ÙˆØ§Ù†ÙŠ Ù„ØªÙØ§Ø¯ÙŠ Ø§ØµØ·Ø¯Ø§Ù… Ø§Ù„Ø±ÙˆØ¨ÙˆØª
  WELD_COMPLETE_DELAY, // ØªØ£Ø®ÙŠØ± Ù…Ø¬Ù‡Ø±ÙŠ 50 Ù…Ù„ÙŠ Ø«Ø§Ù†ÙŠØ© Ù„ØªØ­Ø¯ÙŠØ« Ø§Ù„Ù„Ù…Ø¨Ø© Ø¨Ø¯ÙˆÙ† ØªØ¬Ù…ÙŠØ¯
  RETURNING_HOME, // Ø­Ø§Ù„Ø© Ø§Ù„Ø¹ÙˆØ¯Ø© Ù„Ù†Ù‚Ø·Ø© Ø§Ù„ØµÙØ± ÙÙŠ Ù†Ù‡Ø§ÙŠØ© Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬ (Ø¨Ø¯ÙˆÙ† ØªØ¬Ù…ÙŠØ¯)
  MANUAL_GO_HOME,
  ERROR, // Ø­Ø§Ù„Ø© Ø§Ù„Ø®Ø·Ø£ Ø£Ùˆ Ø§Ù„Ø·ÙˆØ§Ø±Ø¦ (Ù„Ø§ ÙŠÙ…ÙƒÙ† Ø¹Ù…Ù„ Ø´ÙŠØ¡ Ø¥Ù„Ø§ Ø¨Ø¹Ø¯ Ø§Ù„ØªØµÙÙŠØ± Ù…Ù† Ø¬Ø¯ÙŠØ¯)
  PROGRAM_COMPLETE,   // Ø­Ø§Ù„Ø© Ø§ÙƒØªÙ…Ø§Ù„ Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬ (ØºÙŠØ± Ù…Ø³ØªØ®Ø¯Ù…Ø© ÙÙŠ Ø§Ù„ÙˆØ¶Ø¹ Ø§Ù„Ø­Ø§Ù„ÙŠ)
  PROGRAM_PAUSED,
  MANUAL_GO_TO_POS
};

// ============================================================================
// [6] Ø§Ù„Ù…ØªØºÙŠØ±Ø§Øª Ø§Ù„Ø¹Ø§Ù…Ø© (Global Variables)
// ============================================================================

SystemState currentState =
    IDLE; // Ø§Ù„Ù…ØªØºÙŠØ± Ø§Ù„Ø°ÙŠ ÙŠØ­ÙØ¸ Ø­Ø§Ù„Ø© Ø§Ù„Ù†Ø¸Ø§Ù… Ø§Ù„Ø­Ø§Ù„ÙŠØ© (ÙŠØ¨Ø¯Ø£ Ø¬Ø§Ù‡Ø²Ø§Ù‹)
bool isHomed =
    false; // Ù‡Ù„ ØªÙ… ØªØµÙÙŠØ± Ø§Ù„Ù†Ø¸Ø§Ù…ØŸ (ÙŠÙ…Ù†Ø¹ Ø£ÙŠ Ø­Ø±ÙƒØ© Ø¥Ø°Ø§ ÙƒØ§Ù†Øª Ø§Ù„Ù‚ÙŠÙ…Ø© False)
bool programRunning = false; // Ù‡Ù„ ÙŠÙˆØ¬Ø¯ Ø¨Ø±Ù†Ø§Ù…Ø¬ Ù„Ø­Ø§Ù… ÙŠØ¹Ù…Ù„ Ø§Ù„Ø¢Ù†ØŸ
bool programPaused = false;
SystemState pausedState = IDLE;
long pausedTargetPosition = 0;
unsigned long pausedDelayRemainingMs = 0;
unsigned long pausedCobotRemainingMs = 0;
unsigned long pausedCountdownRemainingMs = 0;
bool pausedCobotFinishedSignal = false;
float speedPercentage = 100.0;
unsigned long cobotTimeoutMs = COBOT_TIMEOUT_MS;

// Ù…ØªØºÙŠØ±Ø§Øª Ù…ØµÙÙˆÙØ© Ø§Ù„Ù†Ù‚Ø§Ø· ÙˆØ§Ù„Ø²ÙˆØ§ÙŠØ§
int totalPositions = 0; // Ø¥Ø¬Ù…Ø§Ù„ÙŠ Ø¹Ø¯Ø¯ Ø§Ù„Ø²ÙˆØ§ÙŠØ§ Ø§Ù„Ù…Ø­ÙÙˆØ¸Ø© ÙÙŠ Ø§Ù„Ù‚Ø§Ø¦Ù…Ø©
int currentPositionIndex = 0; // Ø§Ù„ÙÙ‡Ø±Ø³ Ø§Ù„Ø°ÙŠ ÙŠØ´ÙŠØ± Ù„Ù„Ù†Ù‚Ø·Ø© Ø§Ù„Ø¬Ø§Ø±ÙŠ ØªÙ†ÙÙŠØ°Ù‡Ø§ Ø­Ø§Ù„ÙŠØ§Ù‹
long targetStepsArray[30]; // Ù…ØµÙÙˆÙØ© ÙŠÙ…ÙƒÙ†Ù‡Ø§ ØªØ®Ø²ÙŠÙ† Ø­ØªÙ‰ 30 Ø²Ø§ÙˆÙŠØ© Ù…Ø®ØªÙ„ÙØ© ÙƒØ­Ø¯ Ø£Ù‚ØµÙ‰

const byte SERIAL_COMMAND_BUFFER_SIZE = 96;
char serialCommandBuffer[SERIAL_COMMAND_BUFFER_SIZE];
byte serialCommandIndex = 0;

// Ù…ØªØºÙŠØ±Ø§Øª Ø§Ù„ØªÙˆÙ‚ÙŠØª ÙˆØ­ÙØ¸ Ø§Ù„ÙˆÙ‚Øª
unsigned long relayStartTime =
    0; // ÙˆÙ‚Øª Ø¨Ø¯Ø¡ ØªØ´ØºÙŠÙ„ Ø±ÙŠÙ„Ø§ÙŠ Ø§Ù„Ø±ÙˆØ¨ÙˆØª (Ù„Ø­Ø³Ø§Ø¨ Ø§Ù„Ù€ 1 Ø«Ø§Ù†ÙŠØ©)
unsigned long cobotWaitStartTime =
    0; // ÙˆÙ‚Øª Ø¨Ø¯Ø¡ ØªØ´ØºÙŠÙ„ Ø±ÙŠÙ„Ø§ÙŠ Ø§Ù„Ø±ÙˆØ¨ÙˆØª (Ù„Ø­Ø³Ø§Ø¨ Ø§Ù„Ù€ 1 Ø«Ø§Ù†ÙŠØ©)
unsigned long homingStartTime = 0; // ÙˆÙ‚Øª Ø¨Ø¯Ø¡ Ø§Ù„ØªØµÙÙŠØ± (Ù„Ø­Ø³Ø§Ø¨ Ù…Ù‡Ù„Ø© Ø§Ù„Ù€ 30 Ø«Ø§Ù†ÙŠØ©)
unsigned long lastStatusTime = 0; // ÙˆÙ‚Øª Ø¢Ø®Ø± Ø¥Ø±Ø³Ø§Ù„ Ù„Ù„Ø²Ø§ÙˆÙŠØ© (Ù„Ø­Ø³Ø§Ø¨ ÙƒÙ„ 100ms)
unsigned long lastCountdownTime =
    0; // ÙˆÙ‚Øª Ø¨Ø¯Ø¡ ØªØ´ØºÙŠÙ„ Ø±ÙŠÙ„Ø§ÙŠ Ø§Ù„Ø±ÙˆØ¨ÙˆØª (Ù„Ø­Ø³Ø§Ø¨ Ø§Ù„Ù€ 1 Ø«Ø§Ù†ÙŠØ©)
unsigned long delayStartTime = 0; // ÙˆÙ‚Øª Ø¨Ø¯Ø¡ Ø§Ù†ØªØ¸Ø§Ø± Ø§Ù„Ù€ 3 Ø«ÙˆØ§Ù†ÙŠ Ù„Ù„Ø±ÙˆØ¨ÙˆØª

// Ø¥Ù†Ø´Ø§Ø¡ Ø§Ù„ÙƒØ§Ø¦Ù†Ø§Øª Ù…Ù† Ø§Ù„Ù…ÙƒØªØ¨Ø§Øª (Objects Initialization)
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN,
                        NEO_GRB + NEO_KHZ800); // Ø¥Ù†Ø´Ø§Ø¡ ÙƒØ§Ø¦Ù† Ø§Ù„Ø¥Ø¶Ø§Ø¡Ø©
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN,
                     DIR_PIN); // Ø¥Ù†Ø´Ø§Ø¡ ÙƒØ§Ø¦Ù† Ø§Ù„Ù…Ø­Ø±Ùƒ

// Ø§Ù„Ø¥Ø¹Ù„Ø§Ù† Ø§Ù„Ù…Ø³Ø¨Ù‚ Ø¹Ù† Ø¬Ù…ÙŠØ¹ Ø§Ù„Ø¯ÙˆØ§Ù„ Ù‚Ø¨Ù„ Ø§Ø³ØªØ®Ø¯Ø§Ù…Ù‡Ø§ (Function Prototypes)
void processSerialInput();
void processCommand(String cmd);
void performHoming();
void handleMoveForward();
void handleMoveBackward();
void handleHold();
void handleAdd();
void handleGoHome();
void handleGoToPos(String cmd);
void handleSetHomeHere();
void handleDisarm(); // *** Ø¬Ø¯ÙŠØ¯ *** Ø¥Ù„ØºØ§Ø¡ Ø§Ù„ØªØ³Ù„ÙŠØ­ Ø¹Ù†Ø¯ ØªØ¯Ø®Ù„ Ø§Ù„Ù…Ø´ØºÙ‘Ù„
void handleProgramPause();
void handleStopKeepHome();
void handleEmergencyStop();
void startProgram(String cmd);
void moveToCurrentTarget();
void handleSystemState();
void activateRelayToCobot();
void completeWeldPosition();
void handleError(String errorMsg);
void updateLED(uint32_t color);
void sendToNodeRED(String message);

// ============================================================================
// [7] Ø¯Ø§Ù„Ø© Ø§Ù„Ø¥Ø¹Ø¯Ø§Ø¯ Ø§Ù„Ø£Ø³Ø§Ø³ÙŠØ© - setup() - ÙˆØªÙ†ÙØ° Ù…Ø±Ø© ÙˆØ§Ø­Ø¯Ø© Ø¹Ù†Ø¯ Ø§Ù„Ø¥Ù‚Ù„Ø§Ø¹
// ============================================================================

void setup() {
  // 1. ÙØªØ­ Ø§Ù„Ù…Ù†ÙØ° Ø§Ù„ØªØ³Ù„Ø³Ù„ÙŠ Ù„Ù„ØªÙˆØ§ØµÙ„ Ù…Ø¹ Node-RED
  Serial.begin(115200);

  // 2. Ø¥Ø¹Ø¯Ø§Ø¯ Ø§ØªØ¬Ø§Ù‡Ø§Øª Ø¯Ø¨Ø§Ø¨ÙŠØ³ Ø§Ù„Ø£Ø±Ø¯ÙˆÙŠÙ†Ùˆ
  pinMode(STEP_PIN, OUTPUT); // Ù…Ø®Ø±Ø¬ Ù†Ø¨Ø¶Ø§Øª Ø§Ù„Ù…Ø­Ø±Ùƒ
  pinMode(DIR_PIN, OUTPUT); // Ù…Ø®Ø±Ø¬ Ø§ØªØ¬Ø§Ù‡ Ø¯ÙˆØ±Ø§Ù† Ø§Ù„Ù…Ø­Ø±Ùƒ
  pinMode(ENABLE_PIN, OUTPUT); // Ù…Ø®Ø±Ø¬ ØªÙØ¹ÙŠÙ„ Ø§Ù„Ù…Ø­Ø±Ùƒ
  pinMode(RELAY_TO_COBOT, OUTPUT); // Ù…Ø®Ø±Ø¬ Ø±ÙŠÙ„Ø§ÙŠ Ø§Ù„Ø±ÙˆØ¨ÙˆØª (Ø¥Ø±Ø³Ø§Ù„ Ø§Ù„Ø¥Ø´Ø§Ø±Ø©)

  pinMode(SENSOR_PIN,
          INPUT_PULLUP); // Ù…Ø¯Ø®Ù„ Ù…Ø³ØªØ´Ø¹Ø± Ø§Ù„ØµÙØ± (Ù…Ù‚Ø§ÙˆÙ…Ø© Ø±ÙØ¹ Ø¯Ø§Ø®Ù„ÙŠØ© Ù…ÙØ¹Ù„Ø©)
  pinMode(RELAY_FROM_COBOT,
          INPUT_PULLUP); // Ù…Ø¯Ø®Ù„ Ù…Ø³ØªØ´Ø¹Ø± Ø§Ù„ØµÙØ± (Ù…Ù‚Ø§ÙˆÙ…Ø© Ø±ÙØ¹ Ø¯Ø§Ø®Ù„ÙŠØ© Ù…ÙØ¹Ù„Ø©)

  // 3. Ø¶Ø¨Ø· Ø§Ù„Ù‚ÙŠÙ… Ø§Ù„Ø£ÙˆÙ„ÙŠØ© Ù„Ù„Ø£Ù…Ø§Ù†
  digitalWrite(ENABLE_PIN,
               HIGH); // ØªØ¹Ø·ÙŠÙ„ Ø§Ù„Ù…Ø­Ø±Ùƒ ÙÙŠ Ø§Ù„Ø¨Ø¯Ø§ÙŠØ© (HIGH ÙŠØ¹Ø·Ù„ Ø§Ù„Ù…Ø­Ø±Ùƒ ÙÙŠ Ø§Ù„ØºØ§Ù„Ø¨)
  digitalWrite(RELAY_TO_COBOT, RELAY_TO_COBOT_OFF); // Ø¥Ø¨Ù‚Ø§Ø¡ Ø±ÙŠÙ„Ø§ÙŠ Ø¥Ø´Ø§Ø±Ø© Ø§Ù„Ø±ÙˆØ¨ÙˆØª Ù…ÙØµÙˆÙ„Ø§Ù‹ Ø¹Ù†Ø¯ Ø¨Ø¯Ø¡ Ø§Ù„ØªØ´ØºÙŠÙ„

  // 4. Ø¥Ø¹Ø¯Ø§Ø¯Ø§Øª Ù…ÙƒØªØ¨Ø© Ø§Ù„Ù…Ø­Ø±Ùƒ (Ø§Ù„Ø³Ø±Ø¹Ø© Ø§Ù„Ù‚ØµÙˆÙ‰ ÙˆØ§Ù„ØªØ³Ø§Ø±Ø¹)
  stepper.setMaxSpeed(MAX_SPEED * (speedPercentage / 100.0));
  stepper.setAcceleration(ACCELERATION);

  // 5. ØªØ´ØºÙŠÙ„ Ø¥Ø¶Ø§Ø¡Ø© Ø§Ù„Ù€ LED ÙˆÙˆØ¶Ø¹Ù‡Ø§ Ø¹Ù„Ù‰ Ø§Ù„Ù„ÙˆÙ† Ø§Ù„Ø£Ø®Ø¶Ø± Ø¯Ù„Ø§Ù„Ø© Ø¹Ù„Ù‰ Ø§Ù„Ø¬Ø§Ù‡Ø²ÙŠØ©
  strip.begin();
  strip.setBrightness(255); // Ø£Ù‚ØµÙ‰ Ø³Ø·ÙˆØ¹
  updateLED(LED_GREEN);

  // 6. Ø¥Ø±Ø³Ø§Ù„ Ø¥Ø´Ø¹Ø§Ø± Ù„Ù€ Node-RED Ø¨Ø£Ù† Ø§Ù„Ù†Ø¸Ø§Ù… Ø§Ø´ØªØºÙ„
  sendToNodeRED("SYSTEM_READY");
}

// ============================================================================
// [8] Ø¯Ø§Ù„Ø© Ø§Ù„Ø¯ÙˆØ±Ø§Ù† Ø§Ù„Ø£Ø³Ø§Ø³ÙŠØ© - loop() - ÙˆØªØªÙƒØ±Ø± Ù„Ù„Ø£Ø¨Ø¯ ÙˆØ¨Ø³Ø±Ø¹Ø© Ù‚ØµÙˆÙ‰
// ============================================================================

void loop() {
  // 1. Ù‚Ø±Ø§Ø¡Ø© ÙˆØ§Ø³ØªÙ‚Ø¨Ø§Ù„ Ø£ÙŠ Ø£Ù…Ø± Ø¬Ø¯ÙŠØ¯ Ù…Ù† Node-RED Ø¹Ø¨Ø± Ø§Ù„Ø³ÙŠØ±ÙŠØ§Ù„
  processSerialInput();

  // 2. ØªØ­Ø¯ÙŠØ« Ø§Ù„Ù…Ø­Ø±Ùƒ Ø¨Ø§Ø³ØªÙ…Ø±Ø§Ø± (Non-blocking) - Ù„Ø¶Ù…Ø§Ù† Ù†Ø¹ÙˆÙ…Ø© Ø§Ù„Ø­Ø±ÙƒØ© ÙˆØ¹Ø¯Ù… ØªÙˆÙ‚Ù
  // Ø§Ù„Ù…Ø¹Ø§Ù„Ø¬
  if (programPaused && pausedState == WAITING_COBOT &&
      !pausedCobotFinishedSignal && digitalRead(RELAY_FROM_COBOT) == LOW) {
    pausedCobotFinishedSignal = true;
    sendToNodeRED("STATUS:COBOT_FINISHED_SIGNAL_STORED_DURING_PAUSE");
  }
  if (currentState == MANUAL_MOVING) {
    stepper.runSpeed(); // Ø§Ù„Ø¯ÙˆØ±Ø§Ù† Ø§Ù„ÙŠØ¯ÙˆÙŠ ÙŠØ¹ØªÙ…Ø¯ Ø¹Ù„Ù‰ Ø³Ø±Ø¹Ø© Ø«Ø§Ø¨ØªØ© ÙˆÙ…Ø³ØªÙ…Ø±Ø©
  }
  // Ù„Ù„Ø­Ø±ÙƒØ© Ø§Ù„Ù…ÙˆØ¬Ù‡Ø© (Ø§Ù„ØªØµÙÙŠØ±ØŒ ØªØ¨Ø§Ø·Ø¤ØŒ Ø£Ùˆ Ø§Ù„Ø°Ù‡Ø§Ø¨ Ù„Ù‡Ø¯Ù Ù…Ø­Ø¯Ø¯): Ù†Ø³ØªØ®Ø¯Ù… run()
  else if (stepper.distanceToGo() != 0 || currentState == MANUAL_DECELERATING ||
           currentState == PROGRAM_MOVING || currentState == RETURNING_HOME ||
           currentState == HOMING || currentState == MANUAL_GO_HOME ||
           currentState == MANUAL_GO_TO_POS) {
    stepper.run();
  }

  // 3. ØªØ´ØºÙŠÙ„ Ø¯Ø§Ù„Ø© Ø¥Ø¯Ø§Ø±Ø© Ø­Ø§Ù„Ø© Ø§Ù„Ù†Ø¸Ø§Ù… (Ù„Ù…ØªØ§Ø¨Ø¹Ø© Ù…Ø±Ø§Ø­Ù„ Ø§Ù„Ù„Ø­Ø§Ù… Ø£Ùˆ Ø§Ù„ØªØ¨Ø§Ø·Ø¤)
  handleSystemState();
}

// ============================================================================
// [9] Ø¯Ø§Ù„Ø© Ù…Ø¹Ø§Ù„Ø¬Ø© Ø§Ù„Ø£ÙˆØ§Ù…Ø± ÙˆØªØ­ÙˆÙŠÙ„Ù‡Ø§ (Command Processing)
// ============================================================================

void processSerialInput() {
  while (Serial.available() > 0) {
    char incomingChar = (char)Serial.read();

    if (incomingChar == '\r') {
      continue;
    }

    if (incomingChar == '\n') {
      serialCommandBuffer[serialCommandIndex] = '\0';
      String command = String(serialCommandBuffer);
      command.trim();
      serialCommandIndex = 0;

      if (command.length() > 0) {
        processCommand(command);
      }
      continue;
    }

    if (serialCommandIndex < SERIAL_COMMAND_BUFFER_SIZE - 1) {
      serialCommandBuffer[serialCommandIndex++] = incomingChar;
    } else {
      serialCommandIndex = 0;
      sendToNodeRED("ERROR:SERIAL_COMMAND_TOO_LONG");
    }
  }
}

void processCommand(String cmd) {
  if (cmd.startsWith("STATUS:") || cmd.startsWith("STATUS|") ||
      cmd.startsWith("ERROR:") || cmd.startsWith("STEPS:") ||
      cmd == "SYSTEM_READY" || cmd == "HOMED") {
    return;
  }
  // ØªÙˆØ²ÙŠØ¹ Ø§Ù„Ù…Ù‡Ø§Ù… Ø­Ø³Ø¨ Ø§Ù„Ø£Ù…Ø± Ø§Ù„ÙˆØ§Ø±Ø¯ Ù…Ù† Node-RED
  if (cmd == "HOMING") {
    performHoming(); // Ø¨Ø¯Ø¡ Ø¹Ù…Ù„ÙŠØ© Ø§Ù„ØªØµÙÙŠØ± ÙˆØ§Ù„Ø¹ÙˆØ¯Ø© Ù„Ù„ØµÙØ±
  } else if (cmd == "MOVE_FORWARD") {
    handleMoveForward(); // Ø¯ÙˆØ±Ø§Ù† ÙŠØ¯ÙˆÙŠ Ù„Ù„Ø£Ù…Ø§Ù…
  } else if (cmd == "MOVE_BACKWARD") {
    handleMoveBackward(); // Ø¯ÙˆØ±Ø§Ù† ÙŠØ¯ÙˆÙŠ Ù„Ù„Ø®Ù„Ù
  } else if (cmd == "HOLD") {
    handleHold(); // Ø§Ù„ØªÙˆÙ‚Ù Ø£Ø«Ù†Ø§Ø¡ Ø§Ù„Ø­Ø±ÙƒØ© (ÙŠØ¯ÙˆÙŠØ§Ù‹ Ù„Ø§Ù„ØªÙ‚Ø§Ø· Ù†Ù‚Ø·Ø©ØŒ Ø£Ùˆ Ø¨Ø±Ù…Ø¬ÙŠØ§Ù‹ Ù„Ù„Ø·ÙˆØ§Ø±Ø¦)
  } else if (cmd == "ADD") {
    handleAdd(); // Ø¥Ø¶Ø§ÙØ© Ø§Ù„Ø²Ø§ÙˆÙŠØ© Ø§Ù„Ø­Ø§Ù„ÙŠØ© Ù„Ù„Ù…ØµÙÙˆÙØ©
  } else if (cmd == "GO_HOME") {
    handleGoHome();
  } else if (cmd.startsWith("GO_TO_POS ")) {
    handleGoToPos(cmd);
  } else if (cmd == "SET_HOME_HERE") {
    handleSetHomeHere();
  } else if (cmd == "DISARM") {
    handleDisarm(); // *** Ø¬Ø¯ÙŠØ¯ *** Ø§Ù„Ù…Ø´ØºÙ‘Ù„ ØªØ¯Ø®Ù‘Ù„ Ø£Ø«Ù†Ø§Ø¡ ARMED â†’ Ø¥Ù„ØºØ§Ø¡ Ø§Ù„ØªØ³Ù„ÙŠØ­ ÙˆØ§Ù„Ø¹ÙˆØ¯Ø© Ù„Ù€ IDLE
  } else if (cmd == "PAUSE_PROGRAM") {
    handleProgramPause();
  } else if (cmd == "STOP") {
    handleStopKeepHome();
  } else if (cmd == "ESTOP") {
    handleEmergencyStop();
  } else if (cmd.startsWith("START_PROGRAM")) {
    startProgram(cmd); // Ø¨Ø¯Ø¡ ØªÙ†ÙÙŠØ° Ø§Ù„Ù„Ø­Ø§Ù… Ø¹Ø¨Ø± Ø§Ù„Ù†Ù‚Ø§Ø·
  } else if (cmd.startsWith("SET_COBOT_TIMEOUT ")) {
    long timeoutSeconds = cmd.substring(18).toInt();
    if (timeoutSeconds >= 0 && timeoutSeconds <= 3600) {
      cobotTimeoutMs = (unsigned long)timeoutSeconds * 1000UL;
      sendToNodeRED(cobotTimeoutMs == 0 ? "STATUS:COBOT_TIMEOUT_DISABLED" : "STATUS:COBOT_TIMEOUT_SET");
    } else {
      sendToNodeRED("ERROR:INVALID_COBOT_TIMEOUT");
    }
  } else if (cmd.startsWith("SET_SPEED ")) {
    float newSpeed = cmd.substring(10).toFloat();
    if (newSpeed >= 1.0 && newSpeed <= 100.0) {
      speedPercentage = newSpeed;
      if (currentState != HOMING) stepper.setMaxSpeed(MAX_SPEED * (speedPercentage / 100.0));
      sendToNodeRED("STATUS:SPEED_SET_TO_" + String((int)speedPercentage));
    }
  } else if (cmd == "STATUS") {
    // Ø¥Ø°Ø§ Ø·Ù„Ø¨ Node-RED Ø­Ø§Ù„Ø© Ø§Ù„Ù†Ø¸Ø§Ù… Ù†Ø±Ø³Ù„ Ù„Ù‡ Ø­Ø²Ù…Ø© Ù…Ø¹Ù„ÙˆÙ…Ø§Øª (Ø§Ù„Ø²Ø§ÙˆÙŠØ©ØŒ Ø§Ù„Ø­Ø§Ù„Ø©ØŒ Ù‡Ù„ ØªÙ…
    // Ø§Ù„ØªØµÙÙŠØ±)
    long steps = stepper.currentPosition();
    sendToNodeRED("STATUS|HOMED:" + String(isHomed ? "1" : "0") +
                  "|PROG:" + String(programRunning ? "1" : "0") +
                  "|PAUSED:" + String(programPaused ? "1" : "0") +
                  "|POS:" + String(steps) + "|STATE:" + String(currentState));
  } else {
    // Ø±Ø³Ø§Ù„Ø© Ù„Ù„Ø£ÙˆØ§Ù…Ø± ØºÙŠØ± Ø§Ù„Ù…Ø¹Ø±ÙˆÙØ©
    sendToNodeRED("ERROR:INVALID_COMMAND:" + cmd);
  }
}

// ============================================================================
// [10] Ø£Ø²Ø±Ø§Ø± ÙˆØ¥Ø¬Ø±Ø§Ø¡Ø§Øª Ø§Ù„ØªÙƒÙˆÙŠÙ† Ø§Ù„ÙŠØ¯ÙˆÙŠ (Manual Configuration Buttons)
// ============================================================================

// Ø¯Ø§Ù„Ø© Ø§Ù„ØªØµÙÙŠØ± ÙˆØ§Ù„Ø¨Ø­Ø« Ø¹Ù† Ù†Ù‚Ø·Ø© Ø§Ù„ØµÙØ± (Homing)
void performHoming() {
  // Ù„Ø§ ÙŠÙ…ÙƒÙ† Ø§Ù„ØªØµÙÙŠØ± Ø¥Ø°Ø§ ÙƒØ§Ù† Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬ Ù‚ÙŠØ¯ Ø§Ù„ØªÙ†ÙÙŠØ° Ù„Ø­Ù…Ø§ÙŠØ© Ø§Ù„Ù†Ø¸Ø§Ù…
  if (programRunning) {
    sendToNodeRED("ERROR:CANNOT_HOME_DURING_PROGRAM");
    return;
  }

  sendToNodeRED("STATUS:HOMING_STARTED");
  updateLED(LED_BLUE); // ØªØºÙŠÙŠØ± Ø§Ù„Ø¥Ø¶Ø§Ø¡Ø© Ù„Ù„ÙˆÙ† Ø§Ù„Ø£Ø²Ø±Ù‚ Ù„ØªØ¯Ù„ Ø¹Ù„Ù‰ Ø§Ù„Ø­Ø±ÙƒØ©

  digitalWrite(ENABLE_PIN, LOW); // ØªØ´ØºÙŠÙ„ ÙˆØªÙ…ÙƒÙŠÙ† Ø§Ù„Ù…Ø­Ø±Ùƒ
  stepper.setMaxSpeed(HOMING_SPEED); // Ø§Ø³ØªØ®Ø¯Ø§Ù… Ø§Ù„Ø³Ø±Ø¹Ø© Ø§Ù„Ø¨Ø·ÙŠØ¦Ø© Ø§Ù„Ù…Ø®ØµØµØ© Ù„Ù„ØªØµÙÙŠØ±
  stepper.setAcceleration(ACCELERATION); // Ø§Ø³ØªØ®Ø¯Ø§Ù… Ø§Ù„ØªØ³Ø§Ø±Ø¹ Ù„Ù…Ù†Ø¹ ØªÙˆÙ‚Ù Ø§Ù„Ù…ÙˆØªÙˆØ± Ø§Ù„Ù…ÙØ§Ø¬Ø¦ (Stall)
  stepper.move(1000000); // Ø¥Ø¹Ø·Ø§Ø¡ Ù‡Ø¯Ù Ø¨Ø¹ÙŠØ¯ Ø¬Ø¯Ø§Ù‹ Ù„Ù„Ø£Ù…Ø§Ù… Ù„ÙŠØ³ØªÙ…Ø± Ø¨Ø§Ù„Ø¯ÙˆØ±Ø§Ù† Ø­ØªÙ‰ ÙŠÙ„Ù…Ø³ Ø§Ù„Ù…Ø³ØªØ´Ø¹Ø±

  homingStartTime = millis(); // Ø­ÙØ¸ ÙˆÙ‚Øª Ø§Ù„Ø¨Ø¯Ø§ÙŠØ© Ù„Ø¹Ø¯ 30 Ø«Ø§Ù†ÙŠØ© Ù„Ù„Ø·ÙˆØ§Ø±Ø¦
  currentState = HOMING;

  // Ø³ÙŠØªÙ… Ø§Ø³ØªÙƒÙ…Ø§Ù„ Ø§Ù„ØªØµÙÙŠØ± ÙÙŠ handleSystemState() Ø¨Ø¯ÙˆÙ† Ø£ÙŠ loop ÙŠØ¹Ø·Ù„ Ø§Ù„Ù…Ø¹Ø§Ù„Ø¬
}

// Ø¯Ø§Ù„Ø© Ø§Ù„ØªØ­Ø±Ùƒ Ø§Ù„ÙŠØ¯ÙˆÙŠ Ù„Ù„Ø£Ù…Ø§Ù… Ø¨Ø§Ø³ØªÙ…Ø±Ø§Ø±
void handleMoveForward() {
  if (!isHomed) {
    sendToNodeRED("ERROR:MOVE_BEFORE_HOMING");
    return;
  } // Ø±ÙØ¶ Ø§Ù„ØªØ­Ø±Ùƒ Ù‚Ø¨Ù„ Ø§Ù„ØªØµÙÙŠØ±
  if (programRunning && !programPaused) {
    sendToNodeRED("ERROR:MOVE_DURING_PROGRAM");
    return;
  } // Ø±ÙØ¶ Ø§Ù„ØªØ­Ø±Ùƒ Ù‚Ø¨Ù„ Ø§Ù„ØªØµÙÙŠØ±

  digitalWrite(ENABLE_PIN, LOW); // ØªØ´ØºÙŠÙ„ ÙˆØªÙ…ÙƒÙŠÙ† Ø§Ù„Ù…Ø­Ø±Ùƒ
  stepper.setMaxSpeed(MAX_SPEED * (speedPercentage / 100.0));
  stepper.setSpeed(MANUAL_SPEED * (speedPercentage / 100.0)); // Ø¥Ø¹Ø·Ø§Ø¡ Ø³Ø±Ø¹Ø© Ù…ÙˆØ¬Ø¨Ø© Ù„Ù„Ø¯ÙˆØ±Ø§Ù† Ø§Ù„ÙŠØ¯ÙˆÙŠ Ø¨Ø§ØªØ¬Ø§Ù‡ CW

  currentState = MANUAL_MOVING; // ØªØºÙŠÙŠØ± Ø§Ù„Ø­Ø§Ù„Ø© Ù„Ø¯ÙˆØ±Ø§Ù† ÙŠØ¯ÙˆÙŠ
  updateLED(LED_BLUE); // ØªØºÙŠÙŠØ± Ø§Ù„Ø¥Ø¶Ø§Ø¡Ø© Ù„Ù„ÙˆÙ† Ø§Ù„Ø£Ø²Ø±Ù‚ Ù„ØªØ¯Ù„ Ø¹Ù„Ù‰ Ø§Ù„Ø­Ø±ÙƒØ©

  sendToNodeRED("STATUS:MOVING_FORWARD_CONTINUOUS");
  sendToNodeRED("STATUS:PRESS_HOLD_TO_CAPTURE_POSITION");
}

// Ø¯Ø§Ù„Ø© Ø§Ù„ØªØ­Ø±Ùƒ Ø§Ù„ÙŠØ¯ÙˆÙŠ Ù„Ù„Ø®Ù„Ù Ø¨Ø§Ø³ØªÙ…Ø±Ø§Ø±
void handleMoveBackward() {
  if (!isHomed) {
    sendToNodeRED("ERROR:MOVE_BEFORE_HOMING");
    return;
  }
  if (programRunning && !programPaused) {
    sendToNodeRED("ERROR:MOVE_DURING_PROGRAM");
    return;
  }

  digitalWrite(ENABLE_PIN, LOW); // ØªØ´ØºÙŠÙ„ ÙˆØªÙ…ÙƒÙŠÙ† Ø§Ù„Ù…Ø­Ø±Ùƒ
  stepper.setMaxSpeed(MAX_SPEED * (speedPercentage / 100.0));
  stepper.setSpeed(-MANUAL_SPEED * (speedPercentage / 100.0)); // Ø¥Ø¹Ø·Ø§Ø¡ Ø³Ø±Ø¹Ø© Ø³Ø§Ù„Ø¨Ø© Ù„Ù„Ø¯ÙˆØ±Ø§Ù† Ø§Ù„ÙŠØ¯ÙˆÙŠ Ø¨Ø§ØªØ¬Ø§Ù‡ CCW

  currentState = MANUAL_MOVING;
  updateLED(LED_BLUE);

  sendToNodeRED("STATUS:MOVING_BACKWARD_CONTINUOUS");
  sendToNodeRED("STATUS:PRESS_HOLD_TO_CAPTURE_POSITION");
}

// Ø¯Ø§Ù„Ø© Ø§Ù„Ø¥ÙŠÙ‚Ø§Ù (HOLD)
void handleHold() {
  if (!isHomed) {
    sendToNodeRED("ERROR:HOLD_BEFORE_HOMING");
    return;
  }

  // Ø¥Ø°Ø§ ØªÙ… Ø¶ØºØ· Ø²Ø± HOLD Ø£Ø«Ù†Ø§Ø¡ ØªÙ†ÙÙŠØ° Ø¨Ø±Ù†Ø§Ù…Ø¬ Ø§Ù„Ù„Ø­Ø§Ù…ØŒ ÙØ¥Ù†Ù‡ ÙŠØ¹Ù…Ù„ ÙƒÙ…ÙˆÙ‚Ù Ø·ÙˆØ§Ø±Ø¦
  // Ù„Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬ (Ø­Ø³Ø¨ Ø·Ù„Ø¨Ùƒ: ÙŠÙˆÙ‚Ù Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬ ÙˆÙŠØ·Ù„Ø¨ ØªØµÙÙŠØ± Ø¬Ø¯ÙŠØ¯ØŒ ÙˆÙ„ÙƒÙ† Ø¯ÙˆÙ† Ø­Ø°Ù Ø§Ù„Ù†Ù‚Ø§Ø·
  // Ø§Ù„Ù…Ø­ÙÙˆØ¸Ø©)
  if (programRunning && !programPaused) {
    stepper.stop(); // ØªÙˆÙ‚ÙŠÙ Ø§Ù„Ù…Ø­Ø±Ùƒ Ø¨Ù†Ø¹ÙˆÙ…Ø©
    digitalWrite(RELAY_TO_COBOT, RELAY_TO_COBOT_OFF); // Ø¥ÙŠÙ‚Ø§Ù Ø±ÙŠÙ„Ø§ÙŠ Ø§Ù„Ù„Ø­Ø§Ù… Ø¹Ù†Ø¯ Ø¥ÙŠÙ‚Ø§Ù Ø§Ù„Ø­Ø±ÙƒØ© Ø§Ù„ÙŠØ¯ÙˆÙŠØ©
    programRunning = false; // Ø¥ÙŠÙ‚Ø§Ù Ø¹Ù…Ù„ Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬
    isHomed = false; // Ø¥Ø¨Ø·Ø§Ù„ Ø§Ù„ØªØµÙÙŠØ± Ù„Ø§Ø¬Ø¨Ø§Ø± Ø§Ù„Ù…Ø³ØªØ®Ø¯Ù… Ø¹Ù„Ù‰ Ø§Ù„ØªØµÙÙŠØ± Ù…Ø¬Ø¯Ø¯Ø§Ù‹
    currentState = ERROR; // ØªØ­ÙˆÙŠÙ„ Ø­Ø§Ù„Ø© Ø§Ù„Ù†Ø¸Ø§Ù… Ù„Ø®Ø·Ø£
    updateLED(LED_RED); // Ø§Ù„Ù„Ù…Ø¨Ø© Ø­Ù…Ø±Ø§Ø¡
    sendToNodeRED("STATUS:PROGRAM_STOPPED_BY_HOLD");
    sendToNodeRED("STATUS:SYSTEM_REQUIRES_NEW_HOMING");
    return;
  }

  // Ø¥Ø°Ø§ ÙƒØ§Ù† Ø§Ù„Ù†Ø¸Ø§Ù… ÙÙŠ ÙˆØ¶Ø¹ Ø§Ù„ØªØ­Ø±Ùƒ Ø§Ù„ÙŠØ¯ÙˆÙŠ (Ø£Ø±Ø¯Ù†Ø§ Ø§Ù„ØªÙ‚Ø§Ø· Ø§Ù„Ù†Ù‚Ø·Ø©)
  if (currentState != MANUAL_MOVING) {
    return; // Ø¥Ø°Ø§ Ù„Ù… ÙŠÙƒÙ† Ù‡Ù†Ø§Ùƒ Ø­Ø±ÙƒØ©ØŒ ÙÙ„Ø§ Ø¯Ø§Ø¹ÙŠ Ù„Ø¹Ù…Ù„ Ø´ÙŠØ¡
  }

  stepper.setSpeed(0); // ØªÙˆÙ‚Ù Ù…ÙØ§Ø¬Ø¦
  currentState = MANUAL_HOLD; // ØªØºÙŠÙŠØ± Ø§Ù„Ø­Ø§Ù„Ø© Ù„Ù„ØªÙˆÙ‚Ù Ø§Ù„ØªØ§Ù…
  long currentSteps = stepper.currentPosition();
  updateLED(LED_YELLOW); // Ø§Ù„Ø¥Ø¶Ø§Ø¡Ø© ØµÙØ±Ø§Ø¡ Ù„ØªØ£ÙƒÙŠØ¯ ØªÙˆÙ‚Ù Ø§Ù„Ù…Ø­Ø±Ùƒ ÙˆØ¬Ø§Ù‡Ø²ÙŠØªÙ‡ Ù„Ù„Ø­ÙØ¸
  sendToNodeRED("STATUS:MOTOR_STOPPED");
  sendToNodeRED("STATUS:POSITION_CAPTURED_AT_" + String(currentSteps) +
                "_STEPS");
  sendToNodeRED(
      "STATUS:ADD_BUTTON_NOW_ENABLED"); // Ø¥Ø¨Ù„Ø§Øº Ø§Ù„Ù…Ø³ØªØ®Ø¯Ù… Ø¨Ø¶ØºØ· Ø²Ø± ADD Ù„Ù„Ø­ÙØ¸

  // ÙŠØªÙ… Ù…ØªØ§Ø¨Ø¹Ø© Ø¥ÙƒÙ…Ø§Ù„ Ø§Ù„ØªÙˆÙ‚Ù ÙÙŠ Ø¯Ø§Ù„Ø© handleSystemState()
}

// Ø¯Ø§Ù„Ø© Ø¥Ø¶Ø§ÙØ© Ø§Ù„Ø²Ø§ÙˆÙŠØ© Ø§Ù„Ø­Ø§Ù„ÙŠØ© Ù„Ù„Ù‚Ø§Ø¦Ù…Ø© (ADD)
void handleAdd() {
  if (!isHomed) {
    sendToNodeRED("ERROR:ADD_BEFORE_HOMING");
    return;
  } // Ø±ÙØ¶ Ø§Ù„ØªØ­Ø±Ùƒ Ù‚Ø¨Ù„ Ø§Ù„ØªØµÙÙŠØ±
  if (programRunning) {
    sendToNodeRED("ERROR:ADD_DURING_PROGRAM");
    return;
  } // Ø±ÙØ¶ Ø§Ù„ØªØ­Ø±Ùƒ Ù‚Ø¨Ù„ Ø§Ù„ØªØµÙÙŠØ±
  // Ø§Ù„Ø²Ø± ADD ÙŠØ¹Ù…Ù„ ÙÙ‚Ø· Ø¥Ø°Ø§ ÙƒÙ†Øª Ù‚Ø¯ Ø¶ØºØ·Øª HOLD Ù‚Ø¨Ù„Ù‡ (ÙˆØ§Ù„Ù…Ø­Ø±Ùƒ ÙÙŠ ÙˆØ¶Ø¹ Ø§Ù„ØªÙˆÙ‚Ù Ù„Ø§Ù„ØªÙ‚Ø§Ø·
  // Ø§Ù„Ø²Ø§ÙˆÙŠØ©)
  if (currentState != MANUAL_HOLD) {
    sendToNodeRED("ERROR:ADD_REQUIRES_HOLD_FIRST");
    return;
  }

  // Ù…Ù†Ø¹ Ø²ÙŠØ§Ø¯Ø© Ø§Ù„Ø²ÙˆØ§ÙŠØ§ Ø¹Ù† Ø§Ù„Ø­Ø¯ Ø§Ù„Ø£Ù‚ØµÙ‰ Ù„Ù„Ù…ØµÙÙˆÙØ© (30)
  if (totalPositions >= 30) {
    sendToNodeRED("ERROR:MAX_POSITIONS_REACHED");
    return;
  }

  // Ù‚Ø±Ø§Ø¡Ø© Ø§Ù„Ø²Ø§ÙˆÙŠØ© Ø§Ù„Ø­Ø§Ù„ÙŠØ© Ù„Ù„Ù…Ø­Ø±Ùƒ Ø¨Ø¯Ù‚Ø©
  long currentSteps = stepper.currentPosition();
  // ØªØ®Ø²ÙŠÙ† Ø§Ù„Ø²Ø§ÙˆÙŠØ© ÙÙŠ Ø§Ù„Ù…ØµÙÙˆÙØ© Ø§Ù„Ø¯Ø§Ø®Ù„ÙŠØ© Ù„Ù„Ø£Ø±Ø¯ÙˆÙŠÙ†Ùˆ
  targetStepsArray[totalPositions] = currentSteps;
  totalPositions++; // Ø²ÙŠØ§Ø¯Ø© Ø¹Ø¯Ø§Ø¯ Ø§Ù„Ù†Ù‚Ø§Ø· Ø¨Ù…Ù‚Ø¯Ø§Ø± 1

  // Ø¥Ø±Ø³Ø§Ù„ ØªØ£ÙƒÙŠØ¯Ø§Øª Ù„Ù„Ù€ Node-RED Ù„ÙŠØ¹Ø±Ø¶Ù‡Ø§ ÙÙŠ Ø§Ù„Ø¯Ø§Ø´Ø¨ÙˆØ±Ø¯
  sendToNodeRED("STATUS:POSITION_SAVED");
  sendToNodeRED("STATUS:POS_" + String(totalPositions) + "_AT_" +
                String(currentSteps) + "_STEPS_ADDED");
  sendToNodeRED("STATUS:READY_FOR_NEXT_POSITION");

  updateLED(LED_GREEN); // Ø§Ù„Ø¥Ø¶Ø§Ø¡Ø© Ø®Ø¶Ø±Ø§Ø¡ Ù„ØªØ£ÙƒÙŠØ¯ Ø§Ù„Ø­ÙØ¸ Ø¨Ù†Ø¬Ø§Ø­
  currentState = IDLE; // Ø¥Ø¹Ø§Ø¯Ø© Ø§Ù„Ù†Ø¸Ø§Ù… Ù„Ø­Ø§Ù„Ø© Ø§Ù„Ø¬Ø§Ù‡Ø²ÙŠØ© Ù„Ø§Ø³ØªÙ‚Ø¨Ø§Ù„ Ø§Ù„Ø­Ø±ÙƒØ© Ø§Ù„ØªØ§Ù„ÙŠØ©
}

void handleGoHome() {
  if (!isHomed) {
    sendToNodeRED("ERROR:MUST_BE_HOMED_FIRST");
    return;
  }
  if ((programRunning && !programPaused) || currentState == ARMED) {
    sendToNodeRED("ERROR:CANNOT_MOVE_DURING_PROGRAM");
    return;
  }

  digitalWrite(ENABLE_PIN, LOW);
  updateLED(LED_BLUE);
  stepper.setMaxSpeed(MAX_SPEED * (speedPercentage / 100.0));
  stepper.setAcceleration(PROGRAM_ACCELERATION);
  if (stepper.currentPosition() != 0) {
    stepper.moveTo(stepper.currentPosition());
    stepper.moveTo(0);
  }
  currentState = MANUAL_GO_HOME;
  sendToNodeRED("STATUS:MOVING_TO_HOME_POSITION");
}

void handleGoToPos(String cmd) {
  if (!isHomed) {
    sendToNodeRED("ERROR:MUST_BE_HOMED_FIRST");
    return;
  }
  if ((programRunning && !programPaused) || currentState == ARMED) {
    sendToNodeRED("ERROR:CANNOT_MOVE_DURING_PROGRAM");
    return;
  }
  if (currentState == HOMING || currentState == MANUAL_MOVING ||
      currentState == MANUAL_DECELERATING || currentState == MANUAL_GO_HOME ||
      currentState == MANUAL_GO_TO_POS) {
    sendToNodeRED("ERROR:MOTOR_BUSY");
    return;
  }

  long targetSteps = cmd.substring(10).toInt();
  if (targetSteps < 0) {
    sendToNodeRED("ERROR:INVALID_TARGET_POSITION");
    return;
  }

  digitalWrite(ENABLE_PIN, LOW);
  updateLED(LED_BLUE);
  stepper.setMaxSpeed(MAX_SPEED * (speedPercentage / 100.0));
  stepper.setAcceleration(PROGRAM_ACCELERATION);
  stepper.moveTo(stepper.currentPosition());
  stepper.moveTo(targetSteps);
  currentState = MANUAL_GO_TO_POS;
  sendToNodeRED("STATUS:MOVING_TO_SELECTED_POSITION");
}

void handleSetHomeHere() {
  if ((programRunning && !programPaused) || currentState == ARMED) {
    sendToNodeRED("ERROR:CANNOT_SET_HOME_DURING_PROGRAM");
    return;
  }

  stepper.setSpeed(0);
  stepper.setCurrentPosition(0);
  isHomed = true;
  currentState = IDLE;
  updateLED(LED_GREEN);
  sendToNodeRED("HOMED");
  sendToNodeRED("STEPS:0");
  sendToNodeRED("STATUS:NEW_HOME_SET_SUCCESSFULLY");
}
// ============================================================================
// *** Ø¬Ø¯ÙŠØ¯ *** Ø¯Ø§Ù„Ø© Ø¥Ù„ØºØ§Ø¡ Ø§Ù„ØªØ³Ù„ÙŠØ­ Ø¹Ù†Ø¯ ØªØ¯Ø®Ù‘Ù„ Ø§Ù„Ù…Ø´ØºÙ‘Ù„ (DISARM)
// ØªÙØ³ØªØ¯Ø¹Ù‰ Ø¹Ù†Ø¯Ù…Ø§ ÙŠØ¶ØºØ· Ø§Ù„Ù…Ø´ØºÙ‘Ù„ Ø£ÙŠ Ø²Ø± (CW/CCW/HOLD/ADD/DELETE/EDIT...) Ø£Ø«Ù†Ø§Ø¡ ARMED
// ============================================================================
void handleDisarm() {
  // Ø¥Ù„ØºØ§Ø¡ Ø§Ù„ØªØ³Ù„ÙŠØ­ ÙŠØ¹Ù…Ù„ ÙÙ‚Ø· Ø¥Ø°Ø§ ÙƒØ§Ù† Ø§Ù„Ù†Ø¸Ø§Ù… ÙÙŠ Ø­Ø§Ù„Ø© ARMED
  if (currentState != ARMED) {
    sendToNodeRED("STATUS:NOT_ARMED_IGNORING_DISARM");
    return;
  }

  programRunning = false; // Ø¥ÙŠÙ‚Ø§Ù Ø¹Ù…Ù„ Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬
  programPaused = false;
  pausedCobotFinishedSignal = false;
  currentState = IDLE; // Ø¥Ø¹Ø§Ø¯Ø© Ø§Ù„Ù†Ø¸Ø§Ù… Ù„Ø­Ø§Ù„Ø© Ø§Ù„Ø¬Ø§Ù‡Ø²ÙŠØ© Ù„Ø§Ø³ØªÙ‚Ø¨Ø§Ù„ Ø§Ù„Ø­Ø±ÙƒØ© Ø§Ù„ØªØ§Ù„ÙŠØ©
  updateLED(LED_GREEN); // Ø§Ù„Ø¥Ø¶Ø§Ø¡Ø© Ø®Ø¶Ø±Ø§Ø¡ Ù„ØªØ£ÙƒÙŠØ¯ Ø§Ù„Ø­ÙØ¸ Ø¨Ù†Ø¬Ø§Ø­
  sendToNodeRED("STATUS:DISARMED_BY_OPERATOR");
  sendToNodeRED("STATUS:CONFIGURATION_UNLOCKED"); // Ø§Ù„Ø£Ø²Ø±Ø§Ø± Ù…ØªØ§Ø­Ø© Ù…Ø¬Ø¯Ø¯Ø§Ù‹
  sendToNodeRED("STATUS:PRESS_START_WHEN_READY"); // ØªØ°ÙƒÙŠØ± Ø¨Ø¶ØºØ· START Ø¹Ù†Ø¯ Ø§Ù„Ø§Ù†ØªÙ‡Ø§Ø¡
}

// Ø¯Ø§Ù„Ø© Ø§Ù„Ø¥ÙŠÙ‚Ø§Ù Ø§Ù„ÙƒÙ„ÙŠ ÙˆØ§Ù„Ø·ÙˆØ§Ø±Ø¦ (STOP / ESTOP)
void handleProgramPause() {
  if (!programRunning && !programPaused) {
    sendToNodeRED("ERROR:PAUSE_ONLY_AFTER_START");
    return;
  }

  if (programPaused) {
    SystemState resumeState = pausedState;
    stepper.setSpeed(0);
    programPaused = false;
    currentState = resumeState;
    digitalWrite(ENABLE_PIN, LOW);

    if (resumeState == PROGRAM_MOVING || resumeState == RETURNING_HOME) {
      stepper.moveTo(stepper.currentPosition());
      stepper.moveTo(pausedTargetPosition);
    } else if (resumeState == RELAY_ACTIVE) {
      relayStartTime = millis() - (RELAY_PULSE_MS - pausedDelayRemainingMs);
      digitalWrite(RELAY_TO_COBOT, RELAY_TO_COBOT_ON);
    } else if (resumeState == DELAY_BEFORE_START) {
      delayStartTime = millis() - (START_DELAY_MS - pausedDelayRemainingMs);
    } else if (resumeState == DELAY_BEFORE_MOVE) {
      delayStartTime = millis() - (3000UL - pausedDelayRemainingMs);
    } else if (resumeState == WELD_COMPLETE_DELAY) {
      delayStartTime = millis() - (50UL - pausedDelayRemainingMs);
    } else if (resumeState == WAITING_COBOT) {
      if (pausedCobotFinishedSignal) {
        currentState = DELAY_BEFORE_MOVE;
        delayStartTime = millis();
        pausedCobotFinishedSignal = false;
        updateLED(LED_YELLOW);
        sendToNodeRED("STATUS:COBOT_FINISHED_WHILE_PAUSED");
        sendToNodeRED("STATUS:COBOT_FINISHED_WAITING_3_SECONDS");
      } else {
        if (cobotTimeoutMs > 0) cobotWaitStartTime = millis() - (cobotTimeoutMs - pausedCobotRemainingMs);
        lastCountdownTime = millis() - (COUNTDOWN_UPDATE_INTERVAL_MS - pausedCountdownRemainingMs);
      }
    }

    updateLED(resumeState == PROGRAM_MOVING || resumeState == RETURNING_HOME ? LED_BLUE : LED_YELLOW);
    sendToNodeRED("STATUS:PROGRAM_RESUMED");
    return;
  }

  switch (currentState) {
  case ARMED:
  case DELAY_BEFORE_START:
  case PROGRAM_MOVING:
  case RELAY_ACTIVE:
  case WAITING_COBOT:
  case DELAY_BEFORE_MOVE:
  case WELD_COMPLETE_DELAY:
  case RETURNING_HOME:
    pausedState = currentState;
    break;
  default:
    sendToNodeRED("ERROR:CANNOT_PAUSE_NOW");
    return;
  }

  pausedTargetPosition = stepper.targetPosition();
  pausedCobotFinishedSignal = false;
  pausedDelayRemainingMs = 0;
  pausedCobotRemainingMs = 0;
  pausedCountdownRemainingMs = 0;

  if (currentState == PROGRAM_MOVING || currentState == RETURNING_HOME) {
    stepper.moveTo(stepper.currentPosition());
  } else if (currentState == RELAY_ACTIVE) {
    unsigned long elapsed = millis() - relayStartTime;
    pausedDelayRemainingMs = elapsed >= RELAY_PULSE_MS ? 0 : RELAY_PULSE_MS - elapsed;
    digitalWrite(RELAY_TO_COBOT, RELAY_TO_COBOT_OFF);
  } else if (currentState == DELAY_BEFORE_START) {
    unsigned long elapsed = millis() - delayStartTime;
    pausedDelayRemainingMs = elapsed >= START_DELAY_MS ? 0 : START_DELAY_MS - elapsed;
  } else if (currentState == DELAY_BEFORE_MOVE) {
    unsigned long elapsed = millis() - delayStartTime;
    pausedDelayRemainingMs = elapsed >= 3000UL ? 0 : 3000UL - elapsed;
  } else if (currentState == WELD_COMPLETE_DELAY) {
    unsigned long elapsed = millis() - delayStartTime;
    pausedDelayRemainingMs = elapsed >= 50UL ? 0 : 50UL - elapsed;
  } else if (currentState == WAITING_COBOT) {
    if (cobotTimeoutMs > 0) {
      unsigned long elapsed = millis() - cobotWaitStartTime;
      pausedCobotRemainingMs = elapsed >= cobotTimeoutMs ? 0 : cobotTimeoutMs - elapsed;
    }
    unsigned long countdownElapsed = millis() - lastCountdownTime;
    pausedCountdownRemainingMs = countdownElapsed >= COUNTDOWN_UPDATE_INTERVAL_MS ? 0 : COUNTDOWN_UPDATE_INTERVAL_MS - countdownElapsed;
  }

  programPaused = true;
  currentState = PROGRAM_PAUSED;
  updateLED(LED_YELLOW);
  sendToNodeRED("STATUS:PROGRAM_PAUSED");
}
void handleStopKeepHome() {
  if (!programRunning && !programPaused && currentState != ARMED) {
    sendToNodeRED("ERROR:STOP_ONLY_WHILE_PROGRAM_ACTIVE");
    return;
  }

  stepper.stop();
  stepper.setCurrentPosition(stepper.currentPosition());
  digitalWrite(ENABLE_PIN, HIGH);
  digitalWrite(RELAY_TO_COBOT, RELAY_TO_COBOT_OFF);

  programRunning = false;
  programPaused = false;
  pausedCobotFinishedSignal = false;
  pausedDelayRemainingMs = 0;
  pausedCobotRemainingMs = 0;
  pausedCountdownRemainingMs = 0;
  currentPositionIndex = 0;
  currentState = IDLE;

  updateLED(LED_GREEN);
  sendToNodeRED("STATUS:PROGRAM_STOPPED_KEEP_HOME");
  sendToNodeRED("STATUS:PRESS_START_WHEN_READY");
}

void handleEmergencyStop() {
  stepper.stop(); // ØªÙˆÙ‚ÙŠÙ Ø§Ù„Ù…Ø­Ø±Ùƒ Ø¨Ù†Ø¹ÙˆÙ…Ø©
  stepper.setCurrentPosition(
      stepper.currentPosition()); // ØªØ«Ø¨ÙŠØª Ù…ÙƒØ§Ù†Ù‡ ÙƒÙ‡Ø¯Ù Ù„Ø¹Ø¯Ù… Ø§Ø³ØªÙƒÙ…Ø§Ù„ Ø§Ù„Ø­Ø±ÙƒØ©
  digitalWrite(ENABLE_PIN, HIGH); // ÙØµÙ„ Ø§Ù„Ø·Ø§Ù‚Ø© ÙƒÙ„ÙŠØ§Ù‹ Ø¹Ù† Ø§Ù„Ù…Ø­Ø±Ùƒ Ù„Ù„Ø£Ù…Ø§Ù†
  digitalWrite(RELAY_TO_COBOT, RELAY_TO_COBOT_OFF); // ÙØµÙ„ Ø¥Ø´Ø§Ø±Ø© Ø§Ù„Ù„Ø­Ø§Ù… Ø¹Ù† Ø§Ù„Ø±ÙˆØ¨ÙˆØª ÙÙˆØ± Ø¥ÙŠÙ‚Ø§Ù Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬

  isHomed = false; // Ø¥Ø¨Ø·Ø§Ù„ Ø§Ù„ØªØµÙÙŠØ± Ù„Ø§Ø¬Ø¨Ø§Ø± Ø§Ù„Ù…Ø³ØªØ®Ø¯Ù… Ø¹Ù„Ù‰ Ø§Ù„ØªØµÙÙŠØ± Ù…Ø¬Ø¯Ø¯Ø§Ù‹
  programRunning = false; // Ø¥ÙŠÙ‚Ø§Ù Ø¹Ù…Ù„ Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬
  programPaused = false;
  pausedCobotFinishedSignal = false;
  currentState = ERROR; // ØªØ­ÙˆÙŠÙ„ Ø­Ø§Ù„Ø© Ø§Ù„Ù†Ø¸Ø§Ù… Ù„Ø®Ø·Ø£

  // Ù„Ø§Ø­Ø¸: Ù„Ø§ ÙŠØªÙ… Ø­Ø°Ù Ø§Ù„Ù†Ù‚Ø§Ø· Ø§Ù„Ù…Ø­ÙÙˆØ¸Ø© Ù‡Ù†Ø§ Ø£ÙŠØ¶Ø§Ù‹ØŒ Ù„ØªØ¨Ù‚Ù‰ Ù…Ø¹Ø±ÙˆØ¶Ø© ÙÙŠ Ø§Ù„Ù€ Node-RED

  updateLED(LED_RED); // Ø§Ù„Ù„Ù…Ø¨Ø© Ø­Ù…Ø±Ø§Ø¡

  sendToNodeRED("ERROR:EMERGENCY_STOP_ACTIVATED");
  sendToNodeRED("STATUS:ALL_DISABLED_EXCEPT_HOMING");
  sendToNodeRED("STATUS:SYSTEM_REQUIRES_NEW_HOMING");
}

// ============================================================================
// [11] ÙˆØ¸Ø§Ø¦Ù ØªÙ†ÙÙŠØ° Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬ Ø§Ù„Ø¢Ù„ÙŠ (Program Execution Functions)
// ============================================================================

// Ø¯Ø§Ù„Ø© Ø¨Ø¯Ø¡ Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬ ÙˆØªÙ†ÙÙŠØ° Ø§Ù„Ø¹Ù…Ù„ÙŠØ§Øª Ø¹Ù„Ù‰ Ø¬Ù…ÙŠØ¹ Ø§Ù„Ù†Ù‚Ø§Ø·
void startProgram(String cmd) {
  if (!isHomed) {
    sendToNodeRED("ERROR:START_PROGRAM_NOT_HOMED");
    return;
  }
  if (programRunning) {
    sendToNodeRED("ERROR:PROGRAM_ALREADY_RUNNING");
    return;
  }

  // Ø¥Ø°Ø§ Ù‚Ø§Ù… Ø§Ù„Ù€ Node-RED Ø¨Ø¥Ø±Ø³Ø§Ù„ Ø²ÙˆØ§ÙŠØ§ ÙÙŠ Ù†ÙØ³ Ø§Ù„Ø£Ù…Ø± (Ù…Ø«Ù„Ø§Ù‹ START_PROGRAM 0 45 90)
  // ÙØ¥Ù†Ù†Ø§ Ù†Ù‚ÙˆÙ… Ø¨ØªÙØ±ÙŠØº Ø§Ù„Ù…ØµÙÙˆÙØ© ÙˆÙƒØªØ§Ø¨Ø© Ù‡Ø°Ù‡ Ø§Ù„Ø£Ø±Ù‚Ø§Ù… Ø§Ù„Ø¬Ø¯ÙŠØ¯Ø© ÙÙˆÙ‚Ù‡Ø§.
  if (cmd.length() > 14) {
    cmd = cmd.substring(cmd.indexOf(" ") + 1); // Ù‚Øµ Ø§Ù„Ù†Øµ
    cmd.replace(",", " "); // Ø§Ø³ØªØ¨Ø¯Ø§Ù„ Ø§Ù„ÙÙˆØ§ØµÙ„ Ø¨Ù…Ø³Ø§ÙØ§Øª
    cmd.replace("|", " "); // Ø§Ø³ØªØ¨Ø¯Ø§Ù„ Ø§Ù„Ø£Ø¹Ù…Ø¯Ø© Ø¨Ù…Ø³Ø§ÙØ§Øª

    int idx = 0;
    String temp = "";
    for (unsigned int i = 0; i < cmd.length(); i++) {
      if (cmd[i] == ' ') {
        if (temp.length() > 0 && idx < 30) {
          targetStepsArray[idx++] = temp.toInt();
          temp = "";
        }
      } else {
        temp += cmd[i];
      }
    }
    if (temp.length() > 0 && idx < 30) {
      targetStepsArray[idx++] = temp.toInt();
    }
    totalPositions = idx; // ØªØ­Ø¯ÙŠØ« Ø¥Ø¬Ù…Ø§Ù„ÙŠ Ø§Ù„Ø²ÙˆØ§ÙŠØ§ Ø¨Ø§Ù„Ø¹Ø¯Ø¯ Ø§Ù„Ø¬Ø¯ÙŠØ¯
  }

  // Ø¥Ø°Ø§ Ù„Ù… ØªÙƒÙ† Ù‡Ù†Ø§Ùƒ Ø£ÙŠ Ø²ÙˆØ§ÙŠØ§ Ù…Ø®Ø²Ù†Ø©ØŒ Ù„Ø§ ÙŠØ¨Ø¯Ø£ Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬
  if (totalPositions == 0) {
    sendToNodeRED("ERROR:START_PROGRAM_NO_POSITIONS");
    return;
  }

  // Ø§Ù„Ø¥Ø¹Ù„Ø§Ù† Ø¹Ù† ØªØ´ØºÙŠÙ„ Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬ - Ø§Ù„Ø§Ù†ØªÙ‚Ø§Ù„ Ù„Ø­Ø§Ù„Ø© ARMED ÙˆØ§Ù†ØªØ¸Ø§Ø± Ø¥Ø´Ø§Ø±Ø© Ø§Ù„Ø±ÙˆØ¨ÙˆØª
  programRunning = true;
  programPaused = false;
  pausedCobotFinishedSignal = false;
  currentPositionIndex = 0;

  // Ø¥Ø±Ø³Ø§Ù„ Ù…Ø¹Ù„ÙˆÙ…Ø§Øª Ù„Ù„ÙˆØ§Ø¬Ù‡Ø© Ù„ØªØ¹Ø·ÙŠÙ„ Ø§Ù„Ø£Ø²Ø±Ø§Ø± Ø§Ù„ÙŠØ¯ÙˆÙŠØ©
  sendToNodeRED("STATUS:CONFIGURATION_LOCKED");
  sendToNodeRED("STATUS:HOLD_ADD_NOW_DISABLED");
  sendToNodeRED("STATUS:PROGRAM_ARMED"); // Ø¥Ø¨Ù„Ø§Øº Node-RED Ø¨Ø§Ù„ØªØ³Ù„ÙŠØ­
  sendToNodeRED("STATUS:PROGRAM_STARTED_" + String(totalPositions) +
                "_POSITIONS");

  // *** Ø§Ù„ØªØºÙŠÙŠØ± Ø§Ù„Ø¬ÙˆÙ‡Ø±ÙŠ: Ù„Ø§ ØªØªØ­Ø±Ùƒ Ø§Ù„Ø·Ø§ÙˆÙ„Ø© Ø§Ù„Ø¢Ù†ØŒ ØªÙ†ØªØ¸Ø± Ø¥Ø´Ø§Ø±Ø© Ø§Ù„Ø±ÙˆØ¨ÙˆØª ***
  digitalWrite(ENABLE_PIN, LOW);
  currentState = ARMED;
  updateLED(LED_YELLOW); // Ø§Ù„Ø¥Ø¶Ø§Ø¡Ø© ØµÙØ±Ø§Ø¡ Ù„ØªØ£ÙƒÙŠØ¯ ØªÙˆÙ‚Ù Ø§Ù„Ù…Ø­Ø±Ùƒ ÙˆØ¬Ø§Ù‡Ø²ÙŠØªÙ‡ Ù„Ù„Ø­ÙØ¸
  sendToNodeRED("STATUS:ARMED_WAITING_FOR_ROBOT_START_SIGNAL");
}

// Ø¯Ø§Ù„Ø© ØªÙˆØ¬ÙŠÙ‡ Ø§Ù„Ù…Ø­Ø±Ùƒ Ù„Ù„Ù†Ù‚Ø·Ø© Ø§Ù„Ù…Ø·Ù„ÙˆØ¨Ø© Ø§Ù„Ø­Ø§Ù„ÙŠØ©
void moveToCurrentTarget() {
  long targetSteps =
      targetStepsArray[currentPositionIndex]; // Ø³Ø­Ø¨ Ø§Ù„Ø²Ø§ÙˆÙŠØ© Ù…Ù† Ø§Ù„Ù…ØµÙÙˆÙØ©
                                              // ØªØ­ÙˆÙŠÙ„Ù‡Ø§ Ø¥Ù„Ù‰ Ø®Ø·ÙˆØ§Øª (Steps)

  stepper.setMaxSpeed(MAX_SPEED * (speedPercentage / 100.0)); // Ø¶Ø¨Ø· Ø§Ù„Ø³Ø±Ø¹Ø© Ø§Ù„Ù‚ØµÙˆÙ‰ Ø­Ø³Ø¨ Ø§Ù„Ù†Ø³Ø¨Ø© Ø§Ù„Ù…Ø­Ø¯Ø¯Ø© Ù…Ù† Ø§Ù„ÙˆØ§Ø¬Ù‡Ø©
  stepper.setAcceleration(
      PROGRAM_ACCELERATION); // Ø¥Ø³ØªØ®Ø¯Ø§Ù… ØªØ³Ø§Ø±Ø¹ Ø¹Ø§Ù„ÙŠ Ø¬Ø¯Ø§Ù‹ Ù„Ø¥Ù„ØºØ§Ø¡ Ø§Ù„ØªÙˆÙ‚Ù Ø§Ù„Ù†Ø§Ø¹Ù…
  stepper.moveTo(
      targetSteps); // Ø¥Ø±Ø³Ø§Ù„ Ø§Ù„Ø£Ù…Ø± Ù„Ù„Ù…Ø­Ø±Ùƒ Ù„Ù„Ø°Ù‡Ø§Ø¨ Ù„Ù„Ù…ÙˆÙ‚Ø¹ (Non-blocking)

  currentState = PROGRAM_MOVING; // ØªØºÙŠÙŠØ± Ø§Ù„Ø­Ø§Ù„Ø© Ù„Ù€ "ÙŠØªØ­Ø±Ùƒ Ù„ØªÙ†ÙÙŠØ° Ø§Ù„Ù†Ù‚Ø·Ø©"
  updateLED(LED_BLUE); // ØªØºÙŠÙŠØ± Ø§Ù„Ø¥Ø¶Ø§Ø¡Ø© Ù„Ù„ÙˆÙ† Ø§Ù„Ø£Ø²Ø±Ù‚ Ù„ØªØ¯Ù„ Ø¹Ù„Ù‰ Ø§Ù„Ø­Ø±ÙƒØ©

  sendToNodeRED("STATUS:MOVING_TO_POSITION_" +
                String(currentPositionIndex + 1));
}

// ============================================================================
// [12] Ù…Ø¯ÙŠØ± Ø­Ø§Ù„Ø§Øª Ø§Ù„Ù†Ø¸Ø§Ù… - Ø§Ù„Ø¹Ù‚Ù„ Ø§Ù„Ù…Ø¯Ø¨Ø± (System State Manager)
// ============================================================================

void handleSystemState() {
  switch (currentState) {

  // Ø­Ø§Ù„Ø© Ø§Ù„ØªØµÙÙŠØ± (Ø§Ù„Ø¨Ø­Ø« Ø¹Ù† Ù†Ù‚Ø·Ø© Ø§Ù„ØµÙØ± Ø¨Ø¯ÙˆÙ† ØªÙˆÙ‚ÙŠÙ Ø§Ù„Ù†Ø¸Ø§Ù…)
  case HOMING:
    if (digitalRead(SENSOR_PIN) == SENSOR_HOME_STATE) {
      // Ø§Ù„Ù…Ø³ØªØ´Ø¹Ø± Ù„Ù‚Ø· Ù†Ù‚Ø·Ø© Ø§Ù„ØµÙØ±
      stepper.setCurrentPosition(0);
      isHomed = true;
      currentState = IDLE;

      updateLED(LED_GREEN);
      sendToNodeRED("HOMED");
      sendToNodeRED("STATUS:HOME_POSITION_0_STEPS");
      sendToNodeRED("STATUS:READY_FOR_MANUAL_CONFIGURATION");
    } else if (millis() - homingStartTime > HOMING_TIMEOUT_MS) {
      // ØªØ¬Ø§ÙˆØ² Ø§Ù„Ù…Ù‡Ù„Ø© Ø§Ù„Ù…Ø­Ø¯Ø¯Ø©
      handleError("HOMING_TIMEOUT");
    }
    break;

  // *** Ø¬Ø¯ÙŠØ¯ *** Ø§Ù†ØªØ¸Ø§Ø± Ø¥Ø´Ø§Ø±Ø© Ø§Ù„Ø±ÙˆØ¨ÙˆØª Ù„Ø¨Ø¯Ø¡ Ø£Ùˆ Ø¥Ø¹Ø§Ø¯Ø© Ø¯ÙˆØ±Ø© Ø§Ù„Ù„Ø­Ø§Ù…
  case ARMED:
    if (digitalRead(RELAY_FROM_COBOT) == LOW) {
      // Ø§Ø³ØªÙÙ„Ù…Øª Ø¥Ø´Ø§Ø±Ø© Ø§Ù„Ø±ÙˆØ¨ÙˆØª - Ø§Ù†ØªØ¸Ø± 2 Ø«Ø§Ù†ÙŠØ© Ù‚Ø¨Ù„ Ø§Ù„ØªØ­Ø±ÙŠÙƒ
      currentPositionIndex = 0;
      sendToNodeRED("STATUS:ROBOT_START_SIGNAL_RECEIVED");
      sendToNodeRED("STATUS:PROGRAM_EXECUTION_STARTED");
      currentState = DELAY_BEFORE_START; // Ø§Ù†ØªØ¸Ø± Ø«Ø§Ù†ÙŠØªÙŠÙ† Ø£ÙˆÙ„Ø§Ù‹
      delayStartTime = millis();
      updateLED(LED_YELLOW);
      sendToNodeRED("STATUS:STARTING_IN_2_SECONDS");
    }
    break;

  // *** Ø¬Ø¯ÙŠØ¯ *** ØªØ£Ø®ÙŠØ± 2 Ø«Ø§Ù†ÙŠØ© Ø¨Ø¹Ø¯ Ø¥Ø´Ø§Ø±Ø© Ø§Ù„Ø±ÙˆØ¨ÙˆØª Ù‚Ø¨Ù„ Ø¨Ø¯Ø¡ Ø­Ø±ÙƒØ© Ø§Ù„Ø·Ø§ÙˆÙ„Ø©
  case DELAY_BEFORE_START:
    if (millis() - delayStartTime >= START_DELAY_MS) {
      moveToCurrentTarget(); // Ø¨Ø¹Ø¯ Ø§Ù„Ø«Ø§Ù†ÙŠØªÙŠÙ†: Ø§Ø¨Ø¯Ø£ Ø§Ù„Ø­Ø±ÙƒØ© Ù„Ù„ÙˆØ¶Ø¹ Ø§Ù„Ø£ÙˆÙ„
    }
    break;

  case PROGRAM_PAUSED:
    if (pausedState == WAITING_COBOT && !pausedCobotFinishedSignal && digitalRead(RELAY_FROM_COBOT) == LOW) {
      pausedCobotFinishedSignal = true;
      sendToNodeRED("STATUS:COBOT_FINISHED_SIGNAL_STORED_DURING_PAUSE");
    }
    break;

  case MANUAL_MOVING:
    // ØªØ­Ø¯ÙŠØ« Ø§Ù„Ø²Ø§ÙˆÙŠØ© Ø§Ù„Ø­ÙŠØ© Ø£Ø«Ù†Ø§Ø¡ Ø§Ù„Ø¯ÙˆØ±Ø§Ù† Ø§Ù„ÙŠØ¯ÙˆÙŠ
    if (millis() - lastStatusTime >= STATUS_UPDATE_INTERVAL_MS) {
      long currentSteps = stepper.currentPosition();
      sendToNodeRED("STEPS:" + String(currentSteps));
      lastStatusTime = millis();
    }
    break;

  // Ø¹Ù†Ø¯ Ø¶ØºØ· Ø²Ø± HOLD ÙŠØ¨Ø¯Ø£ Ø§Ù„Ù…Ø­Ø±Ùƒ Ø¨Ø§Ù„ØªØ¨Ø§Ø·Ø¤ØŒ ÙˆØ¨Ù…Ø¬Ø±Ø¯ ÙˆØµÙˆÙ„Ù‡ Ù„Ù…Ø±Ø­Ù„Ø© Ø§Ù„ØªÙˆÙ‚Ù
  // (Ø§Ù„Ù…Ø³Ø§ÙØ©=0)
  case MANUAL_DECELERATING:
    if (stepper.distanceToGo() == 0) {
      currentState = MANUAL_HOLD; // ØªØºÙŠÙŠØ± Ø§Ù„Ø­Ø§Ù„Ø© Ù„Ù„ØªÙˆÙ‚Ù Ø§Ù„ØªØ§Ù…
      long currentSteps = stepper.currentPosition();
      updateLED(LED_YELLOW); // Ø§Ù„Ø¥Ø¶Ø§Ø¡Ø© ØµÙØ±Ø§Ø¡ Ù„ØªØ£ÙƒÙŠØ¯ ØªÙˆÙ‚Ù Ø§Ù„Ù…Ø­Ø±Ùƒ ÙˆØ¬Ø§Ù‡Ø²ÙŠØªÙ‡ Ù„Ù„Ø­ÙØ¸
      sendToNodeRED("STATUS:MOTOR_STOPPED");
      sendToNodeRED("STATUS:POSITION_CAPTURED_AT_" + String(currentSteps) +
                    "_STEPS");
      sendToNodeRED(
          "STATUS:ADD_BUTTON_NOW_ENABLED"); // Ø¥Ø¨Ù„Ø§Øº Ø§Ù„Ù…Ø³ØªØ®Ø¯Ù… Ø¨Ø¶ØºØ· Ø²Ø± ADD Ù„Ù„Ø­ÙØ¸
    }
    break;

  // Ø£Ø«Ù†Ø§Ø¡ Ø­Ø±ÙƒØ© Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬ Ù„Ø²Ø§ÙˆÙŠØ© Ø§Ù„Ù„Ø­Ø§Ù… Ø§Ù„Ù…Ø·Ù„ÙˆØ¨Ø©
  case PROGRAM_MOVING:
    // 1. ØªØ­Ø¯ÙŠØ« ÙˆØ¥Ø±Ø³Ø§Ù„ Ø§Ù„Ø²Ø§ÙˆÙŠØ© ÙƒÙ„ 100 Ù…Ù„ÙŠ Ø«Ø§Ù†ÙŠØ© Ù„Ø¹Ø±Ø¶Ù‡Ø§ ÙÙŠ Ø§Ù„Ø¯Ø§Ø´Ø¨ÙˆØ±Ø¯
    if (millis() - lastStatusTime >= STATUS_UPDATE_INTERVAL_MS) {
      long currentSteps = stepper.currentPosition();
      sendToNodeRED("STEPS:" + String(currentSteps));
      lastStatusTime = millis();
    }

    // 2. ÙØ­Øµ Ø¥Ø°Ø§ ÙƒØ§Ù† Ø§Ù„Ù…Ø­Ø±Ùƒ Ù‚Ø¯ ÙˆØµÙ„ Ù„Ù„Ù…ÙˆÙ‚Ø¹ Ø§Ù„Ù…Ø·Ù„ÙˆØ¨ (Ø§Ù„Ù…Ø³Ø§ÙØ© Ø§Ù„Ù…ØªØ¨Ù‚ÙŠØ©=0)
    if (stepper.distanceToGo() == 0) {
      long reachedSteps = stepper.currentPosition();
      sendToNodeRED("STATUS:POSITION_" + String(currentPositionIndex + 1) +
                    "_REACHED_" + String(reachedSteps) + "_STEPS");
      // Ø§Ù„Ø§Ù†ØªÙ‚Ø§Ù„ Ù„Ù„Ø®Ø·ÙˆØ© Ø§Ù„ØªØ§Ù„ÙŠØ© ÙˆÙ‡ÙŠ ØªØ´ØºÙŠÙ„ Ø±ÙŠÙ„Ø§ÙŠ Ø§Ù„Ø±ÙˆØ¨ÙˆØª
      activateRelayToCobot();
    }
    break;

  // Ø£Ø«Ù†Ø§Ø¡ ØªÙØ¹ÙŠÙ„ Ø§Ù„Ø±ÙŠÙ„Ø§ÙŠ (Ø¥Ø±Ø³Ø§Ù„ Ø¥Ø´Ø§Ø±Ø© Ù„Ù„Ø±ÙˆØ¨ÙˆØª)
  case RELAY_ACTIVE:
    // Ø§Ù„Ø§Ù†ØªØ¸Ø§Ø± Ø­ØªÙ‰ ØªÙ†Ù‚Ø¶ÙŠ Ø«Ø§Ù†ÙŠØ© ÙˆØ§Ø­Ø¯Ø© (1000ms) Ø¨Ø§Ù„Ø¶Ø¨Ø· Ø¨Ø§Ø³ØªØ®Ø¯Ø§Ù… millis()
    if (millis() - relayStartTime >= RELAY_PULSE_MS) {
      digitalWrite(RELAY_TO_COBOT, RELAY_TO_COBOT_OFF); // Ø¥ÙŠÙ‚Ø§Ù Ø§Ù„Ø±ÙŠÙ„Ø§ÙŠ Ø¨Ø¹Ø¯ Ø§Ù†ØªÙ‡Ø§Ø¡ Ù…Ø¯Ø© Ø§Ù„Ù†Ø¨Ø¶Ø©
      sendToNodeRED("STATUS:RELAY_OFF_TO_COBOT");

      // Ø§Ù„Ø§Ù†ØªÙ‚Ø§Ù„ Ù„Ø­Ø§Ù„Ø© Ø§Ù†ØªØ¸Ø§Ø± Ø¥Ø´Ø§Ø±Ø© Ø§Ù„Ø§Ù†ØªÙ‡Ø§Ø¡ Ù…Ù† Ø§Ù„Ø±ÙˆØ¨ÙˆØª
      currentState = WAITING_COBOT;
      cobotWaitStartTime = millis(); // Ø¨Ø¯Ø¡ Ø¹Ø¯Ø§Ø¯ Ø§Ù„Ù€ Timeout (Ø§Ù„Ø¯Ù‚ÙŠÙ‚ØªÙŠÙ†)
      lastCountdownTime = millis(); // Ø¨Ø¯Ø¡ Ø¹Ø¯Ø§Ø¯ Ø¥Ø±Ø³Ø§Ù„ Ø§Ù„Ø±Ø³Ø§Ù„Ø© ÙƒÙ„ Ø«Ø§Ù†ÙŠØ©
      sendToNodeRED("STATUS:WAITING_FOR_COBOT_RESPONSE");
    }
    break;

  // Ø£Ø«Ù†Ø§Ø¡ Ø§Ù†ØªØ¸Ø§Ø± Ø±Ø¯ Ø§Ù„Ø±ÙˆØ¨ÙˆØª Ø¨Ø§Ù„Ø§Ù†ØªÙ‡Ø§Ø¡
  case WAITING_COBOT:
    // 1. Ø¥Ø°Ø§ Ø£Ø±Ø³Ù„ Ø§Ù„Ø±ÙˆØ¨ÙˆØª Ø¥Ø´Ø§Ø±Ø© Ø§Ù„Ø§Ù†ØªÙ‡Ø§Ø¡ (Ø£ØµØ¨Ø­Øª LOW Ø¨Ø¹Ø¯ Ø§Ù„ØªØ¹Ø¯ÙŠÙ„ Ù„Ù…Ù†Ø¹ Ø§Ù„ØªØ´ÙˆÙŠØ´)
    if (digitalRead(RELAY_FROM_COBOT) == LOW) {
      currentState = DELAY_BEFORE_MOVE; // ØªØºÙŠÙŠØ± Ø§Ù„Ø­Ø§Ù„Ø© Ù„Ù„Ø§Ù†ØªØ¸Ø§Ø±
      delayStartTime = millis(); // Ø¨Ø¯Ø¡ Ø¹Ø¯Ø§Ø¯ Ø§Ù„Ù€ 3 Ø«ÙˆØ§Ù†ÙŠ
      updateLED(LED_YELLOW); // Ø§Ù„Ø¥Ø¶Ø§Ø¡Ø© ØµÙØ±Ø§Ø¡ Ù„ØªØ£ÙƒÙŠØ¯ ØªÙˆÙ‚Ù Ø§Ù„Ù…Ø­Ø±Ùƒ ÙˆØ¬Ø§Ù‡Ø²ÙŠØªÙ‡ Ù„Ù„Ø­ÙØ¸
      sendToNodeRED("STATUS:COBOT_FINISHED_WAITING_3_SECONDS");
    }
    // 2. Ø§Ù„ØªØ­Ù‚Ù‚ Ù…Ù† Ø§Ù†ØªÙ‡Ø§Ø¡ Ø§Ù„Ù…Ù‡Ù„Ø© Ø§Ù„Ù‚ØµÙˆÙ‰ Ù„Ø§Ù†ØªØ¸Ø§Ø± Ø§Ù„Ø±ÙˆØ¨ÙˆØª (Timeout - 120 Ø«Ø§Ù†ÙŠØ©)
    else if (cobotTimeoutMs > 0 && millis() - cobotWaitStartTime >= cobotTimeoutMs) {
      // Ø¥Ø¹Ù„Ø§Ù† Ø®Ø·Ø£ ÙˆØ¥ÙŠÙ‚Ø§Ù Ø§Ù„Ù†Ø¸Ø§Ù…
      handleError("WELD_TIMEOUT_POSITION_" + String(currentPositionIndex + 1));
    }
    // 3. Ø¥Ø±Ø³Ø§Ù„ Ø¹Ø¯ ØªÙ†Ø§Ø²Ù„ÙŠ ÙŠØ¸Ù‡Ø± ÙÙŠ Ø§Ù„ÙˆØ§Ø¬Ù‡Ø© Ù„ØªÙˆØ¶ÙŠØ­ Ø§Ù„Ù…Ù‡Ù„Ø© Ø§Ù„Ù…ØªØ¨Ù‚ÙŠØ© ÙƒÙ„ Ø«Ø§Ù†ÙŠØ©
    else if (cobotTimeoutMs > 0 && millis() - lastCountdownTime >= COUNTDOWN_UPDATE_INTERVAL_MS) {
      int secondsLeft = (cobotTimeoutMs - (millis() - cobotWaitStartTime)) /
                        1000; // Ø­Ø³Ø§Ø¨ Ø§Ù„Ø«ÙˆØ§Ù†ÙŠ Ø§Ù„Ù…ØªØ¨Ù‚ÙŠØ©
      sendToNodeRED("STATUS:WAITING_FOR_COBOT_RESPONSE_SECONDS_LEFT:" +
                    String(secondsLeft));
      lastCountdownTime = millis();
    }
    break;

  // Ø­Ø§Ù„Ø© Ø§Ù†ØªØ¸Ø§Ø± 3 Ø«ÙˆØ§Ù†ÙŠ Ù‚Ø¨Ù„ Ø§Ù„ØªØ­Ø±Ùƒ Ù„Ù„Ø²Ø§ÙˆÙŠØ© Ø§Ù„ØªØ§Ù„ÙŠØ©
  case DELAY_BEFORE_MOVE:
    if (millis() - delayStartTime >= 3000) { // Ø¨Ø¹Ø¯ Ù…Ø±ÙˆØ± 3 Ø«ÙˆØ§Ù†ÙŠ
      completeWeldPosition(); // Ø¥ÙƒÙ…Ø§Ù„ Ø§Ù„Ù†Ù‚Ø·Ø© ÙˆØ§Ù„Ø§Ù†ØªÙ‚Ø§Ù„ Ù„Ù„ØªØ§Ù„ÙŠØ©
    }
    break;

  // Ø­Ø§Ù„Ø© Ø§Ù„ÙˆÙ…ÙŠØ¶ Ø§Ù„Ø£Ø®Ø¶Ø± Ø§Ù„Ø³Ø±ÙŠØ¹ (50 Ù…Ù„ÙŠ Ø«Ø§Ù†ÙŠØ©) Ø¨Ø¹Ø¯ Ù†Ø¬Ø§Ø­ Ù†Ù‚Ø·Ø© Ø§Ù„Ù„Ø­Ø§Ù…
  case WELD_COMPLETE_DELAY:
    if (millis() - delayStartTime >= 50) {
      currentPositionIndex++; // Ø§Ù„Ø§Ù†ØªÙ‚Ø§Ù„ Ù„Ù„ÙÙ‡Ø±Ø³ (Ø§Ù„Ù†Ù‚Ø·Ø©) Ø§Ù„ØªØ§Ù„ÙŠØ©

      // Ø§Ù„ØªØ­Ù‚Ù‚ Ù…Ù…Ø§ Ø¥Ø°Ø§ ÙƒØ§Ù†Øª Ù‡Ù†Ø§Ùƒ Ù†Ù‚Ø§Ø· Ù…ØªØ¨Ù‚ÙŠØ© ÙÙŠ Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬
      if (currentPositionIndex < totalPositions) {
        moveToCurrentTarget(); // Ø¨Ø¹Ø¯ Ø§Ù„Ø«Ø§Ù†ÙŠØªÙŠÙ†: Ø§Ø¨Ø¯Ø£ Ø§Ù„Ø­Ø±ÙƒØ© Ù„Ù„ÙˆØ¶Ø¹ Ø§Ù„Ø£ÙˆÙ„
      } else {
        // Ø§Ù†ØªÙ‡Øª Ø¬Ù…ÙŠØ¹ Ø§Ù„Ù†Ù‚Ø§Ø· - Ø§Ù„Ø¹ÙˆØ¯Ø© Ù„Ù„ØµÙØ±
        sendToNodeRED("STATUS:RETURNING_TO_HOME");
        updateLED(LED_BLUE);

        stepper.setMaxSpeed(MAX_SPEED * (speedPercentage / 100.0));
        stepper.setAcceleration(PROGRAM_ACCELERATION);
        stepper.moveTo(0);

        currentState = RETURNING_HOME; // Ø§Ù„Ø§Ù†ØªÙ‚Ø§Ù„ Ù„Ù„Ø­Ø§Ù„Ø© Ø§Ù„Ø¬Ø¯ÙŠØ¯Ø©
      }
    }
    break;

  case MANUAL_GO_HOME:
    if (stepper.distanceToGo() == 0) {
      currentState = programPaused ? PROGRAM_PAUSED : IDLE;
      updateLED(programPaused ? LED_YELLOW : LED_GREEN);
      sendToNodeRED("STEPS:0");
      sendToNodeRED("STATUS:RETURNED_TO_HOME_MANUALLY");
    } else if (millis() - lastStatusTime >= STATUS_UPDATE_INTERVAL_MS) {
      long currentSteps = stepper.currentPosition();
      sendToNodeRED("STEPS:" + String(currentSteps));
      lastStatusTime = millis();
    }
    break;

  case MANUAL_GO_TO_POS:
    if (stepper.distanceToGo() == 0) {
      long currentSteps = stepper.currentPosition();
      currentState = programPaused ? PROGRAM_PAUSED : IDLE;
      updateLED(programPaused ? LED_YELLOW : LED_GREEN);
      sendToNodeRED("STEPS:" + String(currentSteps));
      sendToNodeRED("STATUS:GO_TO_POSITION_REACHED");
    } else if (millis() - lastStatusTime >= STATUS_UPDATE_INTERVAL_MS) {
      long currentSteps = stepper.currentPosition();
      sendToNodeRED("STEPS:" + String(currentSteps));
      lastStatusTime = millis();
    }
    break;
  case RETURNING_HOME:
    if (stepper.distanceToGo() == 0) {
      // Ø­Ø§Ù„Ø© Ø§Ù„Ø¹ÙˆØ¯Ø© Ù„Ù†Ù‚Ø·Ø© Ø§Ù„ØµÙØ± ÙÙŠ Ù†Ù‡Ø§ÙŠØ© Ø§Ù„Ø¨Ø±Ù†Ø§Ù…Ø¬ (Ø¨Ø´ÙƒÙ„ ØºÙŠØ± Ù…Ø¹Ø·Ù„)
      currentState = ARMED;
      updateLED(LED_GREEN);
      sendToNodeRED("STEPS:0");
      sendToNodeRED("STATUS:CYCLE_COMPLETE_PIECE_DONE");
      sendToNodeRED("STATUS:PROGRAM_FINISHED_" + String(totalPositions) + "_OF_" +
                    String(totalPositions) + "_POSITIONS");
      sendToNodeRED("STATUS:ARMED_WAITING_FOR_ROBOT_START_SIGNAL"); // Ø§Ù†ØªØ¸Ø§Ø± Ø§Ù„Ù‚Ø·Ø¹Ø© Ø§Ù„Ø¬Ø¯ÙŠØ¯Ø©
    } else {
      // *** Ø¨Ø¹Ø¯ Ø§Ù„Ø¹ÙˆØ¯Ø© Ù„Ù„ØµÙØ±: Ø¥Ø¹Ø§Ø¯Ø© Ø§Ù„ØªØ³Ù„ÙŠØ­ ØªÙ„Ù‚Ø§Ø¦ÙŠØ§Ù‹ Ø¨Ø¯ÙˆÙ† Ø§Ù„Ø­Ø§Ø¬Ø© Ù„Ø¶ØºØ· START ***
      if (millis() - lastStatusTime >= STATUS_UPDATE_INTERVAL_MS) {
        long currentSteps = stepper.currentPosition();
        sendToNodeRED("STEPS:" + String(currentSteps));
        lastStatusTime = millis();
      }
    }
    break;

  // Ø¥Ø±Ø³Ø§Ù„ ØªØ­Ø¯ÙŠØ« Ø§Ù„Ø®Ø·ÙˆØ§Øª Ø£Ø«Ù†Ø§Ø¡ Ø§Ù„Ø¹ÙˆØ¯Ø©
  default:
    break;
  }
}

// Ø£ÙŠ Ø­Ø§Ù„Ø© Ø£Ø®Ø±Ù‰ Ù„Ø§ ØªØªØ·Ù„Ø¨ ØªÙØ§Ø¹Ù„Ø§Ù‹ Ù‡Ù†Ø§
// ============================================================================
// [13] Ø¯ÙˆØ§Ù„ Ø§Ù„Ù„Ø­Ø§Ù… Ø§Ù„Ù…Ø³Ø§Ø¹Ø¯Ø© (Helpers)

// ============================================================================
void activateRelayToCobot() {
  currentState = RELAY_ACTIVE; // ØªØºÙŠÙŠØ± Ø§Ù„Ø­Ø§Ù„Ø©
  relayStartTime = millis(); // Ø¨Ø¯Ø¡ Ù…Ø¤Ù‚Øª Ø§Ù„Ø±ÙŠÙ„Ø§ÙŠ
  digitalWrite(RELAY_TO_COBOT, RELAY_TO_COBOT_ON); // Ø¥Ø±Ø³Ø§Ù„ Ø¥Ø´Ø§Ø±Ø© Ø§Ù„Ø¨Ø¯Ø¡ Ø¥Ù„Ù‰ Ø§Ù„Ø±ÙˆØ¨ÙˆØª Ø¹Ø¨Ø± ØªÙØ¹ÙŠÙ„ Ø§Ù„Ø±ÙŠÙ„Ø§ÙŠ

  updateLED(LED_YELLOW); // Ø§Ù„Ø¥Ø¶Ø§Ø¡Ø© ØµÙØ±Ø§Ø¡ Ù„ØªØ£ÙƒÙŠØ¯ ØªÙˆÙ‚Ù Ø§Ù„Ù…Ø­Ø±Ùƒ ÙˆØ¬Ø§Ù‡Ø²ÙŠØªÙ‡ Ù„Ù„Ø­ÙØ¸
  sendToNodeRED("STATUS:RELAY_ON_TO_COBOT");
}

// Ø¯Ø§Ù„Ø© ØªÙØ¹ÙŠÙ„ Ø§Ù„Ø±ÙŠÙ„Ø§ÙŠ Ù„Ù„Ø±ÙˆØ¨ÙˆØª
void completeWeldPosition() {
  sendToNodeRED("STATUS:WELD_COMPLETE_POSITION_" +
                String(currentPositionIndex + 1));
  updateLED(LED_GREEN); // Ø§Ù„Ø¥Ø¶Ø§Ø¡Ø© Ø®Ø¶Ø±Ø§Ø¡ Ù„ØªØ£ÙƒÙŠØ¯ Ø§Ù„Ø­ÙØ¸ Ø¨Ù†Ø¬Ø§Ø­

  currentState = WELD_COMPLETE_DELAY;
  delayStartTime = millis(); // Ø¨Ø¯Ø¡ Ø¹Ø¯Ø§Ø¯ Ø§Ù„Ù€ 3 Ø«ÙˆØ§Ù†ÙŠ
}

// Ø¯Ø§Ù„Ø© Ø§ÙƒØªÙ…Ø§Ù„ Ø§Ù„Ù„Ø­Ø§Ù… ÙÙŠ Ø§Ù„Ù†Ù‚Ø·Ø© Ø§Ù„Ø­Ø§Ù„ÙŠØ© ÙˆØªØ­Ø¯ÙŠØ¯ Ø§Ù„ØªØ§Ù„ÙŠ
void handleError(String errorMsg) {
  handleEmergencyStop(); // Ø¥ÙŠÙ‚Ø§Ù Ø·ÙˆØ§Ø±Ø¦ ÙƒØ§Ù…Ù„ (ÙŠØ¯Ù…Ø± Ø£ÙŠ Ø´ÙŠØ¡ ÙˆÙŠØ·Ù„Ø¨ Homing)
                         // Ø¯Ø§Ù„Ø© Ø¥Ø¯Ø§Ø±Ø© Ø¥Ø±Ø³Ø§Ù„ Ø±Ø³Ø§Ø¦Ù„ Ø§Ù„Ø®Ø·Ø£ Ø§Ù„Ø´Ø§Ù…Ù„Ø© (Ù„Ù„Ø·ÙˆØ§Ø±Ø¦)
  sendToNodeRED("ERROR:" + errorMsg); // Ø¥Ø±Ø³Ø§Ù„ Ø³Ø¨Ø¨ Ø§Ù„Ø®Ø·Ø£
}

// Ø§Ù„ØªØµÙÙŠØ± Ù„Ù„Ù†Ù‚Ø§Ø·
void updateLED(uint32_t color) {
  strip.setPixelColor(0, color);
  strip.show();
}

// Ø¯Ø§Ù„Ø© ØªØ­Ø¯ÙŠØ« Ø§Ù„Ù„Ù…Ø¨Ø© Ø¨Ø§Ù„Ù„ÙˆÙ† Ø§Ù„Ù…Ø·Ù„ÙˆØ¨ Ø¨ÙƒÙ„ Ø³Ù‡ÙˆÙ„Ø©
void sendToNodeRED(String message) { Serial.println(message); }
