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

  public var sourceSettings: SourceSettings! {
    guard let ss = Request_getSourceSettings(wrapped) else {
      return nil
    }
    return SourceSettings(ss)
  }
}
