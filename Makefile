TARGET = main

OBJECTS = main.o control.o DJI_Pro_App.o DJI_Pro_Hw.o DJI_Pro_Link.o DJI_Pro_Codec.o DJI_Pro_Rmu.o

CFLAGS = -I/DJI_LIB

CXX = g++

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

main.o : main.cpp
	$(CXX) $(CFLAGS) -c main.cpp

control.o : control.cpp
	$(CXX) $(CFLAGS) -c control.cpp

DJI_Pro_App.o : DJI_LIB/DJI_Pro_App.cpp
	$(CXX) $(CFLAGS) -c DJI_LIB/DJI_Pro_App.cpp
	
DJI_Pro_Hw.o : DJI_LIB/DJI_Pro_Hw.cpp
	$(CXX) $(CFLAGS) -c DJI_LIB/DJI_Pro_Hw.cpp

DJI_Pro_Link.o : DJI_LIB/DJI_Pro_Link.cpp
	$(CXX) $(CFLAGS) -c DJI_LIB/DJI_Pro_Link.cpp

DJI_Pro_Codec.o : DJI_LIB/DJI_Pro_Codec.cpp
	$(CXX) $(CFLAGS) -c DJI_LIB/DJI_Pro_Codec.cpp

DJI_Pro_Rmu.o: DJI_LIB/DJI_Pro_Rmu.cpp
	$(CXX) $(CFLAGS) -c DJI_LIB/DJI_Pro_Rmu.cpp

clean:
	-rm *.o
	-rm $(TARGET)


