#include <string>
#include <map>
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-w"
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TNonblockingServer.h>
#include "MyService.h"
#pragma GCC diagnostic pop

namespace thr = apache::thrift;
namespace thp = thr::protocol;
namespace tht = thr::transport;
namespace ths = thr::server;
namespace thc = thr::concurrency;
namespace my  = ::Example;

class MyServiceHandler:
  virtual public my::MyServiceIf
{
public:
  typedef std::map<std::string, std::string> dict_type;
  dict_type dict_;

  MyServiceHandler()
  {
    // Your initialization goes here
  }

  void myPut(my::MyValue& _return
            ,const std::string& name
            ,const std::string& value)
  {
     const dict_type::iterator pos = dict_.find(name);
     if(pos != dict_.end())
     {
        _return.content    = pos->second;
        _return.exists     = true;
        pos->second = value;
     }
     else dict_.insert(dict_type::value_type(name, value));
  }

  void myGet(my::MyValue& _return
            ,const std::string& name)
  {
     const dict_type::const_iterator pos = dict_.find(name);
     if(pos != dict_.end())
     {
        _return.content    = pos->second;
        _return.exists     = true;
     }
  }
};

int main(int argc, char **argv)
{
  typedef my::MyServiceProcessor proc_type;
  typedef MyServiceHandler hndl_type;
  typedef ths::TNonblockingServer server_type;
  typedef thc::ThreadManager tmgr_type;
  typedef boost::shared_ptr<hndl_type> hndl_ptr_type;
  typedef boost::shared_ptr<thr::TProcessor> proc_ptr_type;
  typedef boost::shared_ptr<thp::TProtocolFactory> pfac_ptr_type;
  typedef boost::shared_ptr<tmgr_type> tmgr_ptr_type;
  typedef boost::shared_ptr<thc::PosixThreadFactory> tfac_ptr_type;

  const int port_num = 9999;
  const int max_threads = 15;

  hndl_ptr_type handler  (new hndl_type());
  proc_ptr_type processor(new proc_type(handler));
  pfac_ptr_type protfac  (new thp::TBinaryProtocolFactory());
  tfac_ptr_type thrdfac  (new thc::PosixThreadFactory());
  tmgr_ptr_type tmgr     (tmgr_type::newSimpleThreadManager(max_threads));

  tmgr->threadFactory(thrdfac);
  tmgr->start();

  server_type server(processor, protfac, port_num, tmgr);
  server.serve();

  return 0;
}
