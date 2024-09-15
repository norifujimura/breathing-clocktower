# https://zenn.dev/knowhere_imai/articles/ba850780152b01
#import p5
import pygame
from pygame.locals import *
import sys

import asyncio
import time

x = 0
y = 0

async def say_after(delay, what):
    print(f"prepare {what} at {time.strftime('%X')}")
    await asyncio.sleep(delay)
    print(f"{what} at {time.strftime('%X')}")

async def my_loop(delay, what):
    while True:
        # return rateを1 Hzに設定
        print(f"prepare {what} at {time.strftime('%X')}")
        await asyncio.sleep(delay)

async def pygame_loop(delay):
    pygame.init() # 初期化
    screen = pygame.display.set_mode((120,120)) # ウィンドウサイズの指定
    pygame.display.set_caption("Pygame Test") # ウィンドウの上の方に出てくるアレの指定
    font = pygame.font.Font(None, 30)
    
    while(True):
        pygame.display.update()
        mouseX, mouseY = pygame.mouse.get_pos()
        text = font.render(f'{mouseX}, {mouseY}', True, (127,127,127))
        screen.fill((255, 255, 255))
        screen.blit(text, [0, 0])
        pygame.draw.line(screen, (0,0,0), (mouseX,0), (mouseX,120), 1)
        pygame.draw.line(screen, (0,0,0), (0,mouseY), (120,mouseY), 1)
        pygame.display.flip()
        #pygame.display.update() # 画面更新

        for event in pygame.event.get(): # 終了処理
            if event.type == QUIT:
                pygame.quit()
                sys.exit()
        await asyncio.sleep(delay)

async def main():


    task1 = asyncio.create_task(my_loop(1, 'hello'))
    task2 = asyncio.create_task(my_loop(2, 'world'))
    task3 = asyncio.create_task(pygame_loop(0.02))


    print(f"started at {time.strftime('%X')}")

    await task1

    print(f"returned from await task1 at {time.strftime('%X')}")

    await task2
    await task3

    print(f"finished at {time.strftime('%X')}")
    #asyncio.run(run(renderer="vispy",frame_rate=20))

asyncio.run(main())
