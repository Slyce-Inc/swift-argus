import libargus

public class OutputStream {
  let wrapped: UnsafeRawPointer?

  init(_ wrapped: UnsafeRawPointer) {
    self.wrapped = wrapped
  }

  deinit {
    OutputStream_destroy(wrapped)
  }

  public var EGLStream: EGLStreamKHR {
    get {
      return OutputStream_getEGLStream(wrapped)
    }
  }

  public func reset() {
    OutputStream_reset(wrapped)
  }

  public func waitUntilConnected(timeout: UInt) -> Bool {
    return OutputStream_waitUntilConnected(wrapped, timeout)
  }

  public func disconnect() {
    OutputStream_disconnect(wrapped)
  }
}
