COMMON = common.h rpc_controller.h svc_name2id.h
RPCSVRLIB=librpcsvr.a
RPCCLTLIB=librpcclt.a

#INCLUDES=-I/usr/local/include -I/usr/local/Cellar/libevent/2.1.8/include -I/Users/zhangyushan/code/rpc/phxrpc/third_party/protobuf/include
INCLUDES=-I/usr/local/include -I/usr/local/Cellar/libevent/2.1.8/include -I/Users/zhangyushan/code/rpc/easy_pb_rpc/protobuf/include
CCFLAGS=-g
%.o:%.cc
	c++ $(CCFLAGS) $(INCLUDES) -o $@ -c $<

all: PROTO $(RPCSVRLIB) $(RPCCLTLIB)
#all:  $(RPCSVRLIB) $(RPCCLTLIB)

PROTO: rpc.proto
	/Users/zhangyushan/code/rpc/easy_pb_rpc/protobuf/bin/protoc --cpp_out=. rpc.proto
#	/Users/zhangyushan/code/rpc/phxrpc/third_party/protobuf/bin/protoc --cpp_out=. rpc.proto

$(RPCSVRLIB): rpc_server.o service_mgr.o common.o rpc.pb.o
	ar cru $(RPCSVRLIB) rpc_server.o service_mgr.o common.o rpc.pb.o

$(RPCCLTLIB): rpc_client.o rpc_channel.o common.o
	ar cru $(RPCCLTLIB) rpc_client.o rpc_channel.o common.o rpc.pb.o

clean:
	-rm *.o $(RPCCLTLIB) $(RPCSVRLIB)
