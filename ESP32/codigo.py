import machine

trct = machine.ADC(machine.Pin(34))
led = machine.Pin(2, machine.Pin.OUT)

while True:
    if trct.read() < 2000:
        led.on()
    else:
        led.off()
