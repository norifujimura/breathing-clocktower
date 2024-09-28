#from p5 import *

import json
import asyncio
from ctypes import *
from bleak import BleakClient

#address = "19C40D9B-F748-1109-CF66-67D6BB739283" # 通信先のMacアドレス
address = "24:58:7C:5C:83:DD"
CHARACTERISTIC_UUID = "beb5483e-36e1-4688-b7f5-ea07361b26a8" # CHARACTERISTIC_UUID

state = 'init' # init, bleconnected
client = None
x = 0
y = 0

'''
async def connect(address):
    global state
    try:
        async with BleakClient(address) as client:
            message_received = await client.read_gatt_char(CHARACTERISTIC_UUID)
            print("message_received : {0}".format("".join(map(chr, message_received ))))
            state = "ble-connected"
            print(state)
            #return client
            while(True):
                print("connect")
                await send(client)
    except Exception:
        return None
        
        #info = "{\"x\": \"100\",\"y\":\"100\"}" # put your large data here
        #length = len(info)
        #factory_info_bytes = create_string_buffer(info.encode('utf-8'), length)
        '''

async def send(client):
    global x,y,state
    print("send 0")
    message = {
        "x":x,
        "y":y
    }
    masseage_b = json.dumps(message).encode('utf-8')

    try:
        print("send 1")
        await client.write_gatt_char(CHARACTERISTIC_UUID,masseage_b,response=True)
        await asyncio.sleep(0.2)
    except Exception:
     print('clientの接続は切れました')
    
        
#task1 = asyncio.create_task(connect(address))
#p5.run(frame_rate=20)
'''
def setup():
    
    #normalize()
    size(640, 360)
    no_stroke()
    background(204)
    #asyncio.run(connect(address))
   

    
def draw():
    global state, client
    if mouse_is_pressed:
        fill(random_uniform(255), random_uniform(127), random_uniform(51), 127)
    else:
        fill(255, 15)

    circle_size = random_uniform(low=10, high=80)

    circle((mouse_x, mouse_y), circle_size)

    x = mouse_x

    if 100<x:
        x = 100
    
    y = mouse_y

    if 100<y:
        y = 100

    print(state)


def key_pressed(event):

    background(204)
'''

#asyncio.run(main(address))
#await main(address)

# p5 supports different backends to render sketches,
# "vispy" for both 2D and 3D sketches & "skia" for 2D sketches
# use "skia" for better 2D experience
# Default renderer is set to "vispy"

#run(renderer="vispy",frame_rate=20) # "skia" is still in beta

async def ble(address, loop):
    async with BleakClient(address, loop=loop) as client:
        is_connected = client.is_connected
        print(f"Connected: {is_connected}")

        message = {
            "r":x,
            "g":y,
            "b":0
        }
        masseage_b = json.dumps(message).encode('utf-8')

        while True:
            # return rateを1 Hzに設定
            await client.write_gatt_char(CHARACTERISTIC_UUID,masseage_b,response=True)
            await asyncio.sleep(1)

loop = asyncio.get_event_loop()
loop.run_until_complete(ble(address, loop))




