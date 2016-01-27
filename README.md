# Drone onboard

sing raspberry pi to control drone matrix 100.

# Troubleshooting

#### DJI_Pro_Control_Management_CallBack,line 523, there is unkown error,ack=0x0

Switch control mode pin to `P` and then back to `F`

#### No Response -- 374

Make sure the `API Control` checkbox is enabled on the `N1 Assistant`.

#### DJI_Pro_Control_Management_CallBack,line 523, there is unkown error,ack=0xFF00

This error seems to be related to incorrect key. Make sure your key variable don't get deallcated for some reason, that would cause the activate_data_t.app_key lose its value, and that will make your life miserable.

# Cross Compilers

### MacOS

Download and install [gcc-linaro-arm-linux-gnueabihf-raspbian-2014.05_mac](http://www.welzels.de/blog/download/gcc-linaro-arm-linux-gnueabihf-raspbian-2014.05_mac.zip)

### Ubuntu

```shell
$ sudo apt-get install g++-arm-linux-gnueabihf
```

For more information on cross compiling ARM from MacOS see [www.welzels.de](http://www.welzels.de/blog/en/arm-cross-compiling-with-mac-os-x/))

# Compiling

The following command compiles the program targeting RaspberryPI ARM architecture.

```shell
$ make
```

# Configuring SSH keys
 
The following command will configure your ~/.ssh/config file with SSH information for our `raspberry1` and `raspberry2` devices.
 
```shell
$ make ssh
```

In case you need to change the IP addresses for the Raspberry PIs, you can do so by editing the file `ssh-config/config`.

# Deploying the generated binary to Raspberry PI devices

The following command deploys the binary to the device configured as `raspberry1` in your `~/.ssh/config` file.

```shell
$ make deploy
```

In case you want to deploy the binary to `raspberry2`, run:

```shell
$ make DEPLOY_TARGET=raspberry2 deploy 
```
