CXX=g++ -std=c++1z -g -I.
RM=rm -rf

LIBS=$(pkg-config --libs)

default: build

.PHONY: all run build clean

build:
	$(CXX) $(LIBS) \
		-o bin/2048 \
		src/main.cpp \
		src/Game.cpp \
		src/Utils.cpp \
		src/Kbhit.cpp \
		src/KeyPushManager.cpp

run:
	cd bin && \
		./2048

clean:
	$(RM) bin/*
