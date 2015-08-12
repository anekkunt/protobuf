protoc-c --c_out=. test.proto
gcc encode.c test.pb-c.c -lprotobuf-c  -o encode
gcc decode.c test.pb-c.c -lprotobuf-c  -o decode
./encode |./decode   #pass o/p of encode date to decode using pipe(|) 
