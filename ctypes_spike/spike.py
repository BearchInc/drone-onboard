from ctypes import cdll

dji = cdll.LoadLibrary("libspike.so")

dji.hello('world...')
