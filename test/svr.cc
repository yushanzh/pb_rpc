
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "rpc_server.h"
#include "helloworld.pb.h"

using namespace PBRPC;

class EchoServiceImpl : public EchoService {
	public:
	EchoServiceImpl() {}
	virtual void Foo(::google::protobuf::RpcController* controller,
                       const ::FooRequest* request,
                       ::FooResponse* response,
                       ::google::protobuf::Closure* done) {
		std::string str = request->text();
		std::string tmp = str;
		for (int i = 1; i < request->times(); i++)
			str += (" " + tmp);
		response->set_text(str);
		response->set_result(true);
		printf("recv0 message is %s",str.c_str());
		//exit(0);
	}
};


class TranServiceImpl : public TranService {
	public:
		TranServiceImpl(){}
	
	virtual void Tran(::google::protobuf::RpcController* controller,
                       const ::TranRequest* request,
                       ::TranResponse* response,
                       ::google::protobuf::Closure* done) {
		std::string str = request->text();
		std::string tmp = str;
		//for (int i = 1; i < request->times(); i++)
		//	str += (" " + tmp);
		response->set_text(str);
		response->set_result(true);
		printf("recv message is %s",str.c_str());
		sleep(10);
	}
};
  


int main(int argc, char *argv[]) {
	printf("main start");
	EchoServiceImpl *impl = new EchoServiceImpl();
	RpcServer rpc_server;
	rpc_server.RegisterService(impl);
	//rpc_server.Start();
	
	TranServiceImpl *tranImpl = new TranServiceImpl();
	rpc_server.RegisterService(tranImpl);
	rpc_server.Start();
	return 0;
}


