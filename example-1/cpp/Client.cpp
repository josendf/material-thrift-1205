#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>
#include <iostream>

#include "example_types.h"
#include "example_constants.h"
#include "MyService.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

using boost::shared_ptr;

using namespace ::Example;

int main(int argc, char **argv)
{
  const int port = 9999;

  boost::shared_ptr<TSocket>    socket   (new TSocket("localhost", port));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket) );
  boost::shared_ptr<TProtocol>  protocol (new TBinaryProtocol(transport));

  MyServiceClient client(protocol);
  try
  {
    transport->open();
    int32_t res = client.myprocedure();
    std::cout << "response: " << res << std::endl;
  }
  catch(const apache::thrift::TException& e)
  {
    std::cerr << "error: " << e.what() << std::endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << "error: " << e.what() << std::endl;
  }
  catch(...)
  {
    std::cerr << "error: " << "unknown" << std::endl;
  }

  transport->close();

  return 0;
}

