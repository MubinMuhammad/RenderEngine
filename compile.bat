mkdir build
cd build

mkdir examples

mkdir object_files
cd object_files

gcc -c ../../src/*.c -I"../../vendor/" -I"../../include/"
ar rcs libRenderEngine.a *.o

move libRenderEngine.a ../
cd ..

gcc ../examples/square.c -o examples/square -L"../lib/" -L"./" ^
-lRenderEngine -lglfw3 -lOpenGL32 -lgdi32 ^
-I"../vendor/" -I"../include/"
