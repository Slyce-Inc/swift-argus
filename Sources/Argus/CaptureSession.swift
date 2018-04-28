import libargus

public class CaptureSession {
  let wrapped: UnsafeRawPointer?

  init(_ wrapped: UnsafeRawPointer) {
    self.wrapped = wrapped
  }

  deinit {
    CaptureSession_destroy(wrapped)
  }

  public func createOutputStreamSettings() -> OutputStreamSettings? {
    guard let oss = CaptureSession_createOutputStreamSettings(wrapped) else { return nil }
    return OutputStreamSettings(oss)
  }
}
