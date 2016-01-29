TARGET = main

OUTPUT = .build

DEPLOY_TARGET = raspberry1

OBJECTS = $(OUTPUT)/main.o $(OUTPUT)/Lock.o $(OUTPUT)/control.o $(OUTPUT)/drone.o $(OUTPUT)/brain.o $(OUTPUT)/DJI_Pro_App.o $(OUTPUT)/DJI_Pro_Hw.o $(OUTPUT)/DJI_Pro_Link.o $(OUTPUT)/DJI_Pro_Codec.o $(OUTPUT)/DJI_Pro_Rmu.o

CFLAGS = -Ilibs/includes -IDJI_LIB -std=c++11

LDFLAGS = -Llibs -lpthread -lwiringPi -lrt -lusb-1.0 -lDJI_guidance

OS = $(shell uname)

ifeq ($(OS),Darwin)
    CXX = "/usr/local/linaro/arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf-g++"
else
    CXX = "arm-linux-gnueabi-g++"
endif

$(TARGET) : clean output $(OBJECTS)
	$(CXX) -o $(OUTPUT)/$(TARGET) $(OBJECTS) $(LDFLAGS)

output :
	mkdir -p $(OUTPUT)

$(OUTPUT)/main.o : main.cpp
	$(CXX) $(CFLAGS) -c -o $(OUTPUT)/main.o main.cpp

$(OUTPUT)/control.o : control.cpp
	$(CXX) $(CFLAGS) -c -o $(OUTPUT)/control.o control.cpp

$(OUTPUT)/drone.o : models/drone.cpp
	$(CXX) $(CFLAGS) -c -o $(OUTPUT)/drone.o models/drone.cpp

$(OUTPUT)/brain.o : models/brain.cpp
	$(CXX) $(CFLAGS) -c -o $(OUTPUT)/brain.o models/brain.cpp

$(OUTPUT)/Lock.o : models/Lock.cpp
	$(CXX) $(CFLAGS) -c -o $(OUTPUT)/Lock.o models/Lock.cpp

$(OUTPUT)/DJI_Pro_App.o : DJI_LIB/DJI_Pro_App.cpp
	$(CXX) $(CFLAGS) -c -o $(OUTPUT)/DJI_Pro_App.o DJI_LIB/DJI_Pro_App.cpp

$(OUTPUT)/DJI_Pro_Hw.o : DJI_LIB/DJI_Pro_Hw.cpp
	$(CXX) $(CFLAGS) -c -o $(OUTPUT)/DJI_Pro_Hw.o DJI_LIB/DJI_Pro_Hw.cpp

$(OUTPUT)/DJI_Pro_Link.o : DJI_LIB/DJI_Pro_Link.cpp
	$(CXX) $(CFLAGS) -c -o $(OUTPUT)/DJI_Pro_Link.o DJI_LIB/DJI_Pro_Link.cpp

$(OUTPUT)/DJI_Pro_Codec.o : DJI_LIB/DJI_Pro_Codec.cpp
	$(CXX) $(CFLAGS) -c -o $(OUTPUT)/DJI_Pro_Codec.o DJI_LIB/DJI_Pro_Codec.cpp

$(OUTPUT)/DJI_Pro_Rmu.o: DJI_LIB/DJI_Pro_Rmu.cpp
	$(CXX) $(CFLAGS) -c -o $(OUTPUT)/DJI_Pro_Rmu.o DJI_LIB/DJI_Pro_Rmu.cpp

ssh:
	cp -r ssh-config/* ~/.ssh
	chmod 0600 ~/.ssh/id_rsa*

deploy: ssh main
	scp $(OUTPUT)/main $(DEPLOY_TARGET):/home/pi/main

clean:
	@-rm -rf $(OUTPUT)
