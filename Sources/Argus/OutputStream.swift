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
}
