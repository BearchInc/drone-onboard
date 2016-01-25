import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

GPIO.setup(18, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(23, GPIO.IN, pull_up_down=GPIO.PUD_UP)


while True:
    takingoff_idle = GPIO.input(18)
    landing_idle = GPIO.input(23)

    if not takingoff_idle:
        print 'Takeoff Button Pressed'

    if not landing_idle:
        print 'Landing Button Pressed'
        time.sleep(0.2)

    time.sleep(0.2)