import asyncio 
import asyncio
import time

async def say_after(delay, what):
    print(f"[{time.strftime('%X')}] Starting '{what}' (delay: {delay}s)") # Added for clarity
    await asyncio.sleep(delay)
    print(f"[{time.strftime('%X')}] Finished '{what}'") # Added for clarity

async def main():
    print(f"[{time.strftime('%X')}] Program started.")

    # asyncio.gather runs coroutines concurrently.
    # It takes coroutine objects as arguments.
    # It effectively schedules them as independent tasks for the event loop.
    await asyncio.gather(
        say_after(5, 'hello'),
        say_after(5, 'world')
    # Ready task [say_after(5, 'hello'), say_after(5, 'world')]
    )

    print(f"[{time.strftime('%X')}] Program finished.")

asyncio.run(main())