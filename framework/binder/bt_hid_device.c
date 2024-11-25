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
#define LOG_TAG "hid_device_api"

#include <stdint.h>

#include "bluetooth.h"
#include "bt_hid_device.h"
#include "bt_profile.h"

#include "hid_device_callbacks_stub.h"
#include "hid_device_proxy.h"
#include "hid_device_stub.h"

#include "utils/log.h"

void* bt_hid_device_register_callbacks(bt_instance_t* ins, const hid_device_callbacks_t* callbacks)
{
    BpBtHidd* hidd = (BpBtHidd*)bluetooth_get_proxy(ins, PROFILE_HID_DEV);

    IBtHiddCallbacks* cbks = BtHiddCallbacks_new(callbacks);
    AIBinder* binder = BtHiddCallbacks_getBinder(cbks);
    if (!binder) {
        BtHiddCallbacks_delete(cbks);
        return NULL;
    }

    void* remote_cbks = BpBtHidd_registerCallback(hidd, binder);
    if (!remote_cbks) {
        BtHiddCallbacks_delete(cbks);
        return NULL;
    }
    cbks->cookie = remote_cbks;

    return cbks;
}

bool bt_hid_device_unregister_callbacks(bt_instance_t* ins, void* cookie)
{
    IBtHiddCallbacks* cbks = cookie;
    BpBtHidd* hidd = (BpBtHidd*)bluetooth_get_proxy(ins, PROFILE_HID_DEV);

    bool ret = BpBtHidd_unRegisterCallback(hidd, cbks->cookie);
    if (ret)
        BtHiddCallbacks_delete(cbks);

    return ret;
}

bt_status_t bt_hid_device_register_app(bt_instance_t* ins, hid_device_sdp_settings_t* sdp, bool le_hid)
{
    BpBtHidd* hidd = (BpBtHidd*)bluetooth_get_proxy(ins, PROFILE_HID_DEV);

    return BpBtHidd_registerApp(hidd, sdp, le_hid);
}

bt_status_t bt_hid_device_unregister_app(bt_instance_t* ins)
{
    BpBtHidd* hidd = (BpBtHidd*)bluetooth_get_proxy(ins, PROFILE_HID_DEV);

    return BpBtHidd_unregisterApp(hidd);
}

bt_status_t bt_hid_device_connect(bt_instance_t* ins, bt_address_t* addr)
{
    BpBtHidd* hidd = (BpBtHidd*)bluetooth_get_proxy(ins, PROFILE_HID_DEV);

    return BpBtHidd_connect(hidd, addr);
}

bt_status_t bt_hid_device_disconnect(bt_instance_t* ins, bt_address_t* addr)
{
    BpBtHidd* hidd = (BpBtHidd*)bluetooth_get_proxy(ins, PROFILE_HID_DEV);

    return BpBtHidd_disconnect(hidd, addr);
}

bt_status_t bt_hid_device_send_report(bt_instance_t* ins, bt_address_t* addr, uint8_t rpt_id, uint8_t* rpt_data, int rpt_size)
{
    BpBtHidd* hidd = (BpBtHidd*)bluetooth_get_proxy(ins, PROFILE_HID_DEV);

    return BpBtHidd_sendReport(hidd, addr, rpt_id, rpt_data, rpt_size);
}

bt_status_t bt_hid_device_response_report(bt_instance_t* ins, bt_address_t* addr, uint8_t rpt_type, uint8_t* rpt_data, int rpt_size)
{
    BpBtHidd* hidd = (BpBtHidd*)bluetooth_get_proxy(ins, PROFILE_HID_DEV);

    return BpBtHidd_responseReport(hidd, addr, rpt_type, rpt_data, rpt_size);
}

bt_status_t bt_hid_device_report_error(bt_instance_t* ins, bt_address_t* addr, hid_status_error_t error)
{
    BpBtHidd* hidd = (BpBtHidd*)bluetooth_get_proxy(ins, PROFILE_HID_DEV);

    return BpBtHidd_reportError(hidd, addr, error);
}

bt_status_t bt_hid_device_virtual_unplug(bt_instance_t* ins, bt_address_t* addr)
{
    BpBtHidd* hidd = (BpBtHidd*)bluetooth_get_proxy(ins, PROFILE_HID_DEV);

    return BpBtHidd_virtualUnplug(hidd, addr);
}
