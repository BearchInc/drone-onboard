# Drone onboard

sing raspberry pi to control drone matrix 100.

# Troubleshooting

#### DJI_Pro_Control_Management_CallBack,line 523, there is unkown error,ack=0x0

Switch control mode pin to `P` and then back to `F`

#### No Response -- 374

Make sure the `API Control` checkbox is enabled on the `N1 Assistant`.

#### DJI_Pro_Control_Management_CallBack,line 523, there is unkown error,ack=0xFF00

This error seems to be related to incorrect key. Make sure your key variable don't get deallcated for some reason, that would cause the activate_data_t.app_key lose its value, and that will make your life miserable.

# Setup

### MacOS

```shell
$ brew install gcc-arm-none-eabi-49
```

### Ubuntu

```shell
$ sudo apt-get install g++-arm-linux-gnueabihf
```

For more information on cross compiling ARM from MacOS see [www.welzels.de](http://www.welzels.de/blog/en/arm-cross-compiling-with-mac-os-x/))


