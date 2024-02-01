AR = ar
CXX = g++
CXXFLAGS = -std=c++2a -Wall -O2 -march=x86-64-v3 -fno-rtti
LDFLAGS = -s -static -ladvapi32

SRC = FastXor.cpp
OBJ = $(SRC:.cpp=.o)
DEST = FastXor.a
TEST_SRC = FastXorTest.cpp
TEST_DEST = FastXorTest.exe

build: $(OBJ)
	$(AR) r -o $(DEST) $^

build-test: build
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(DEST) -o $(TEST_DEST) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(DEST) $(TEST_DEST)
