/**
 * Autogenerated by Thrift Compiler (0.8.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef MyService_H
#define MyService_H

#include <TProcessor.h>
#include "example_types.h"

namespace Example {

class MyServiceIf {
 public:
  virtual ~MyServiceIf() {}
  virtual void myPut(MyValue& _return, const std::string& name, const std::string& value) = 0;
  virtual void myGet(MyValue& _return, const std::string& name) = 0;
};

class MyServiceIfFactory {
 public:
  typedef MyServiceIf Handler;

  virtual ~MyServiceIfFactory() {}

  virtual MyServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(MyServiceIf* /* handler */) = 0;
};

class MyServiceIfSingletonFactory : virtual public MyServiceIfFactory {
 public:
  MyServiceIfSingletonFactory(const boost::shared_ptr<MyServiceIf>& iface) : iface_(iface) {}
  virtual ~MyServiceIfSingletonFactory() {}

  virtual MyServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(MyServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<MyServiceIf> iface_;
};

class MyServiceNull : virtual public MyServiceIf {
 public:
  virtual ~MyServiceNull() {}
  void myPut(MyValue& /* _return */, const std::string& /* name */, const std::string& /* value */) {
    return;
  }
  void myGet(MyValue& /* _return */, const std::string& /* name */) {
    return;
  }
};

typedef struct _MyService_myPut_args__isset {
  _MyService_myPut_args__isset() : name(false), value(false) {}
  bool name;
  bool value;
} _MyService_myPut_args__isset;

class MyService_myPut_args {
 public:

  MyService_myPut_args() : name(""), value("") {
  }

  virtual ~MyService_myPut_args() throw() {}

  std::string name;
  std::string value;

  _MyService_myPut_args__isset __isset;

  void __set_name(const std::string& val) {
    name = val;
  }

  void __set_value(const std::string& val) {
    value = val;
  }

  bool operator == (const MyService_myPut_args & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const MyService_myPut_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MyService_myPut_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class MyService_myPut_pargs {
 public:


  virtual ~MyService_myPut_pargs() throw() {}

  const std::string* name;
  const std::string* value;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MyService_myPut_result__isset {
  _MyService_myPut_result__isset() : success(false) {}
  bool success;
} _MyService_myPut_result__isset;

class MyService_myPut_result {
 public:

  MyService_myPut_result() {
  }

  virtual ~MyService_myPut_result() throw() {}

  MyValue success;

  _MyService_myPut_result__isset __isset;

  void __set_success(const MyValue& val) {
    success = val;
  }

  bool operator == (const MyService_myPut_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const MyService_myPut_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MyService_myPut_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MyService_myPut_presult__isset {
  _MyService_myPut_presult__isset() : success(false) {}
  bool success;
} _MyService_myPut_presult__isset;

class MyService_myPut_presult {
 public:


  virtual ~MyService_myPut_presult() throw() {}

  MyValue* success;

  _MyService_myPut_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _MyService_myGet_args__isset {
  _MyService_myGet_args__isset() : name(false) {}
  bool name;
} _MyService_myGet_args__isset;

class MyService_myGet_args {
 public:

  MyService_myGet_args() : name("") {
  }

  virtual ~MyService_myGet_args() throw() {}

  std::string name;

  _MyService_myGet_args__isset __isset;

  void __set_name(const std::string& val) {
    name = val;
  }

  bool operator == (const MyService_myGet_args & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    return true;
  }
  bool operator != (const MyService_myGet_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MyService_myGet_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class MyService_myGet_pargs {
 public:


  virtual ~MyService_myGet_pargs() throw() {}

  const std::string* name;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MyService_myGet_result__isset {
  _MyService_myGet_result__isset() : success(false) {}
  bool success;
} _MyService_myGet_result__isset;

class MyService_myGet_result {
 public:

  MyService_myGet_result() {
  }

  virtual ~MyService_myGet_result() throw() {}

  MyValue success;

  _MyService_myGet_result__isset __isset;

  void __set_success(const MyValue& val) {
    success = val;
  }

  bool operator == (const MyService_myGet_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const MyService_myGet_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MyService_myGet_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _MyService_myGet_presult__isset {
  _MyService_myGet_presult__isset() : success(false) {}
  bool success;
} _MyService_myGet_presult__isset;

class MyService_myGet_presult {
 public:


  virtual ~MyService_myGet_presult() throw() {}

  MyValue* success;

  _MyService_myGet_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class MyServiceClient : virtual public MyServiceIf {
 public:
  MyServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  MyServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void myPut(MyValue& _return, const std::string& name, const std::string& value);
  void send_myPut(const std::string& name, const std::string& value);
  void recv_myPut(MyValue& _return);
  void myGet(MyValue& _return, const std::string& name);
  void send_myGet(const std::string& name);
  void recv_myGet(MyValue& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class MyServiceProcessor : public ::apache::thrift::TProcessor {
 protected:
  boost::shared_ptr<MyServiceIf> iface_;
  virtual bool process_fn(apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid, void* callContext);
 private:
  std::map<std::string, void (MyServiceProcessor::*)(int32_t, apache::thrift::protocol::TProtocol*, apache::thrift::protocol::TProtocol*, void*)> processMap_;
  void process_myPut(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_myGet(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  MyServiceProcessor(boost::shared_ptr<MyServiceIf> iface) :
    iface_(iface) {
    processMap_["myPut"] = &MyServiceProcessor::process_myPut;
    processMap_["myGet"] = &MyServiceProcessor::process_myGet;
  }

  virtual bool process(boost::shared_ptr<apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr<apache::thrift::protocol::TProtocol> poprot, void* callContext);
  virtual ~MyServiceProcessor() {}
};

class MyServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  MyServiceProcessorFactory(const ::boost::shared_ptr< MyServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< MyServiceIfFactory > handlerFactory_;
};

class MyServiceMultiface : virtual public MyServiceIf {
 public:
  MyServiceMultiface(std::vector<boost::shared_ptr<MyServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~MyServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<MyServiceIf> > ifaces_;
  MyServiceMultiface() {}
  void add(boost::shared_ptr<MyServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void myPut(MyValue& _return, const std::string& name, const std::string& value) {
    size_t sz = ifaces_.size();
    for (size_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->myPut(_return, name, value);
        return;
      } else {
        ifaces_[i]->myPut(_return, name, value);
      }
    }
  }

  void myGet(MyValue& _return, const std::string& name) {
    size_t sz = ifaces_.size();
    for (size_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->myGet(_return, name);
        return;
      } else {
        ifaces_[i]->myGet(_return, name);
      }
    }
  }

};

} // namespace

#endif