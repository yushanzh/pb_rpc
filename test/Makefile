#INCLUDES=-I../ -I/Users/zhangyushan/code/rpc/phxrpc/third_party/protobuf/include
INCLUDES=-I../ -I/Users/zhangyushan/code/rpc/easy_pb_rpc/protobuf/include

#LDFLAGS=-lpthread -lprotobuf -levent -L/usr/local/lib
LDFLAGS=-lpthread -lprotobuf -levent -L/usr/local/lib -L/Users/zhangyushan/code/rpc/easy_pb_rpc/protobuf/lib
CFLAGS=-g

COMMON = common.h rpc_controller.h svc_name2id.h

#all: client server protoc_middleman
all:protoc_middleman client server

%.o:%.cc
	c++ $(INCLUDES) $(CFLAGS) -o $@ -c $<

client: clt.o helloworld.pb.o
	c++ $(INCLUDES) -o client clt.o helloworld.pb.o -L../ -lrpcclt $(LDFLAGS) 

server: svr.o helloworld.pb.o
	c++ $(INCLUDES) -o server svr.o helloworld.pb.o  -L../ -lrpcsvr $(LDFLAGS)
protoc_middleman: helloworld.proto
	/Users/zhangyushan/code/rpc/easy_pb_rpc/protobuf/bin/protoc --cpp_out=. helloworld.proto
	#/Users/zhangyushan/code/rpc/phxrpc/third_party/protobuf/bin/protoc --cpp_out=. helloworld.proto


clean:
	-rm *.o server client
