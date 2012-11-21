#include <string>
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-w"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include "MyService.h"
#pragma GCC diagnostic pop

namespace thr = apache::thrift;
namespace thp = thr::protocol;
namespace tht = thr::transport;
namespace my  = ::Example;

int main(int argc, char **argv)
{
  typedef my::MyServiceClient client_type;
  typedef tht::TSocket socket_type;
  typedef tht::TFramedTransport transp_type;
  typedef thp::TBinaryProtocol prot_type;
  typedef boost::shared_ptr<tht::TSocket> socket_ptr_type;
  typedef boost::shared_ptr<tht::TTransport> transp_ptr_type;
  typedef boost::shared_ptr<thp::TProtocol> prot_ptr_type;

  const int port_num = 9999;
  const std::string address("localhost");

  socket_ptr_type socket   (new socket_type(address, port_num));
  transp_ptr_type transport(new transp_type(socket) );
  prot_ptr_type   protocol (new prot_type(transport));

  client_type client(protocol);
  try
  {
    transport->open();

    my::MyValue res;

    std::string key1("key-1");
    std::string val1("value-1");

    client.myPut(res, key1, val1);
    std::cout
      << std::boolalpha
      << "response: "
      << '(' << res.exists << ',' << res.content << ')'
      << std::endl;

    client.myGet(res, key1);
    std::cout
      << std::boolalpha
      << "response: "
      << '(' << res.exists << ',' << res.content << ')'
      << std::endl;

  }
  catch(const thr::TException& e)
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
