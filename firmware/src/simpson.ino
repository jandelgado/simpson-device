// Simpson Device - randomly move the mouse cursor
// See Simpsons S07E07 for details ;)
//
// MCU: digispark attiny85 usb clone
//
// (c) copyright 2020 by Jan Delgado
// https://github.com/jandelgado/simpson-device
//
#include <DigiMouse.h>  // part of digispark SDK
#include <jled.h>       // github.com/jandelgado/jled

constexpr auto MAX = 4;
auto statusLed = JLed(1).Breathe(2500).DelayAfter(2500)
                        .Forever().MaxBrightness(100);

void setup() {
    DigiMouse.begin();
}

void loop() {
  const auto dx = random(MAX+1);
  const auto dy = random(MAX+1);
  auto count = random(10);

  while (count-- > 0) {
      DigiMouse.move(static_cast<char>((MAX>>1)-dx),
                     static_cast<char>((MAX>>1)-dy),
                     0);
      statusLed.Update();
      DigiMouse.delay(random(10, 20));
  }
}
