/****************************************************************************
 *  Copyright (C) 2023 Xiaomi Corporation
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

#ifndef __SCANNER_CALLBACKS_STUB_H__
#define __SCANNER_CALLBACKS_STUB_H__

#include <stdbool.h>
#include <stdint.h>
#include <uchar.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "bt_le_scan.h"
#include <android/binder_manager.h>

typedef struct {
    AIBinder_Class* clazz;
    AIBinder_Weak* WeakBinder;
    const scanner_callbacks_t* callbacks;
    void* cookie;
} IBtScannerCallbacks;

typedef enum {
    ICBKS_ON_SCAN_RESULT = FIRST_CALL_TRANSACTION,
    ICBKS_ON_SCAN_START_STATUS,
    ICBKS_ON_SCAN_STOPPED,
} IBtScannerCallbacks_Call;

AIBinder* BtScannerCallbacks_getBinder(IBtScannerCallbacks* adver);
binder_status_t BtScannerCallbacks_associateClass(AIBinder* binder);
IBtScannerCallbacks* BtScannerCallbacks_new(const scanner_callbacks_t* callbacks);
void BtScannerCallbacks_delete(IBtScannerCallbacks* cbks);

#ifdef __cplusplus
}
#endif
#endif /* __SCANNER_CALLBACKS_STUB_H__ */