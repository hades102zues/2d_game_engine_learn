


# Compiler Config
compiler_flags = -Wall -Wextra -g -std=c++20

# Vendor Includes
vendor_folder = src/vendors
inc_glfw = $(vendor_folder)/glfw/include
inc_glad = $(vendor_folder)/glad/include
vendor_includes = -I$(inc_glfw) -I$(inc_glad)


# Libraries
glfw_lib_path = $(vendor_folder)/glfw/lib-arm64
lib_paths = -L$(glfw_lib_path)

lib_obj = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo


libs = $(lib_paths) 
libs += $(lib_obj)

src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)




# Control Flow
.Phony = game ext_objs cleanBuild cleanObj run all

run: all

all: cleanBuild ext_objs game cleanObj

cleanBuild:
	rm -f src/game.exe
cleanObj:
	rm -f src/*.o
ext_objs:
	clang++ -o src/glad.o -c src/glad.c $(compiler_flags) $(vendor_includes)
game: $(obj)
	clang++ -o src/game $^ $(libs)
%.o: %.cpp
	clang++ -o $@ -c $< $(compiler_flags) $(vendor_includes)



