namespace cpp Example

struct MyValue {
  1: bool exists,
  2: string content
}

service MyService {

    // Store a value associated with a key.
    // Returns the existing value if any.
    MyValue myPut(1: string name, 2: string value)

    // Get a value associated with a key.
    // Returns the existing value if any.
    MyValue myGet(1: string name)
}
