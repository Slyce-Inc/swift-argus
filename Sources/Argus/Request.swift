import libargus

public class Request {
  let wrapped: UnsafeRawPointer?

  init(_ wrapped: UnsafeRawPointer) {
    self.wrapped = wrapped
  }

  deinit {
    Request_destroy(wrapped)
  }

  public func enable(outputStream: OutputStream) -> Bool {
    return Request_enableOutputStream(wrapped, outputStream.wrapped)
  }
}
