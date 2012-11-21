#include "MyService.h"
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace ::Example;

class MyServiceHandler : virtual public MyServiceIf {
 public:
  MyServiceHandler() {
    // Your initialization goes here
  }

  int32_t myprocedure() {
    // Your implementation goes here
    printf("myprocedure\n");
    return 1;
  }

};

int main(int argc, char **argv) {
  const int port = 9999;
  shared_ptr<MyServiceHandler>  handler          (new MyServiceHandler());
  shared_ptr<TProcessor>        processor        (new MyServiceProcessor(handler));
  shared_ptr<TServerTransport>  serverTransport  (new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory (new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory>  protocolFactory  (new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

