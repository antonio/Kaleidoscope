/* -*- mode: c++ -*-
 * device::avr::ATMega32U4 -- Generic ATMega32U4 device base class
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
#include "kaleidoscope/driver/storage/ATMega32U4StorageProps.h"
#include "kaleidoscope/driver/storage/AVREEPROM.h"

namespace kaleidoscope {
namespace device {
namespace avr {

struct ATMega32U4Props : kaleidoscope::device::BaseProps {
  typedef kaleidoscope::driver::mcu::ATMega32U4 MCU;
  typedef kaleidoscope::driver::storage::ATMega32U4StorageProps StorageProps;
  typedef kaleidoscope::driver::storage::AVREEPROM<StorageProps> Storage;
};

template <typename _DeviceProps>
class ATMega32U4 : public kaleidoscope::device::Base<_DeviceProps> {
 public:
  auto serialPort() -> decltype(Serial) & {
    return Serial;
  }
};

}
}
}

#endif
