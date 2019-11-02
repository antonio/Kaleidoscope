/* -*- mode: c++ -*-
 * device::ATMega32U4Keyboard -- Generic ATMega32U4 keyboard base class
 * Copyright (C) 2019  Keyboard.io, Inc
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of version 3 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef __AVR__

#include <Arduino.h>
#include "kaleidoscope/device/Base.h"

#include "kaleidoscope/driver/mcu/ATMega32U4.h"
#include "kaleidoscope/driver/storage/ATMega32U4EEPROMProps.h"
#include "kaleidoscope/driver/storage/AVREEPROM.h"

#define ATMEGA32U4_KEYBOARD(BOARD_, BOOTLOADER_, ROW_PINS_, COL_PINS_)           \
  struct BOARD_##Props : kaleidoscope::device::ATMega32U4KeyboardProps {         \
    struct KeyScannerProps : public kaleidoscope::driver::keyscanner::AVRProps { \
      AVR_KEYSCANNER_PROPS(ROW_PIN_LIST(ROW_PINS_), COL_PIN_LIST(COL_PINS_));    \
    };                                                                           \
    typedef kaleidoscope::driver::keyscanner::AVR<KeyScannerProps> KeyScanner;   \
    typedef kaleidoscope::driver::bootloader::avr::BOOTLOADER_ BootLoader;       \
  }; \
  class BOARD_: public kaleidoscope::device::ATMega32U4Keyboard<BOARD_##Props> {};

namespace kaleidoscope {
namespace device {

struct ATMega32U4KeyboardProps : kaleidoscope::device::BaseProps {
  typedef kaleidoscope::driver::mcu::ATMega32U4 MCU;
  typedef kaleidoscope::driver::storage::ATMega32U4EEPROMProps StorageProps;
  typedef kaleidoscope::driver::storage::AVREEPROM<StorageProps> Storage;
};

template <typename _DeviceProps>
class ATMega32U4Keyboard : public kaleidoscope::device::Base<_DeviceProps> {
 public:
  auto serialPort() -> decltype(Serial) & {
    return Serial;
  }
};

}
}

#endif
