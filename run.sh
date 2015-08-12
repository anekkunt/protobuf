protoc-c --c_out=. test.proto  #generate .c and .h files from test.proto file
gcc encode.c test.pb-c.c -lprotobuf-c  -o encode
gcc decode.c test.pb-c.c -lprotobuf-c  -o decode
./encode |./decode   #pass o/p of encode to decode using pipe(|) 
