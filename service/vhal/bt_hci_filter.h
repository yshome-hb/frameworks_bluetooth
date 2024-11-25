/****************************************************************************
 *  Copyright (C) 2024 Xiaomi Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ***************************************************************************/
#ifndef _BT_HCI_FILTER_H__
#define _BT_HCI_FILTER_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

bool bt_hci_filter_can_recv(uint8_t* value, uint32_t size);
bool bt_hci_filter_can_send(uint8_t* value, uint32_t size);

#endif /* _BT_HCI_FILTER_H__ */
