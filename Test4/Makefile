CXX = g++
CXXFLAGS = -DOPTION_1 -Iinclude -Wall -g
SOURCES = main.cpp function/func.cpp function/func2.cpp
TARGET = run/m4.exe
AR = ar
LIB_OBJECTS = function/func.o function/func2.o
LIBRARY = lib/lib1.a
OBJECTS = $(SOURCES:.cpp=.o)

# 伪目标
.PHONY: all clean

# 默认目标
all: $(TARGET)

# 构建静态库
$(LIBRARY): $(LIB_OBJECTS)
	mkdir -p lib
	$(AR) rcs $(LIBRARY) $(LIB_OBJECTS)

# 构建目标可执行文件
$(TARGET): $(OBJECTS) $(LIBRARY)
	mkdir -p run
	$(CXX) $(CXXFLAGS) $(OBJECTS) -Llib -l1 -o $(TARGET)

# 具体的依赖关系
function/func.o: function/func.cpp include/func.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

function/func2.o: function/func2.cpp include/func2.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp include/func.h include/func2.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 构建对象文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理目标
clean:
	rm -f $(TARGET) $(OBJECTS) $(LIBRARY)