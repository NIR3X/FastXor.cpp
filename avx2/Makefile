AR = ar
CXX = g++
CXXFLAGS = -std=c++2a -Wall -O2 -mavx2 -fno-rtti
LDFLAGS = -s -static

SRC = FastXor.cpp
OBJ = $(SRC:.cpp=.o)
DEST = FastXor.a
TEST_SRC = FastXorTest.cpp
TEST_DEST = FastXorTest

build: $(OBJ)
	$(AR) r -o $(DEST) $^

build-test: build
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(DEST) -o $(TEST_DEST) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(DEST) $(TEST_DEST) $(TEST_DEST).exe
