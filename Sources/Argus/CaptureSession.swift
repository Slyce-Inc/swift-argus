import Clibargus

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

  public func createOutputStream(_ outputStreamSettings: OutputStreamSettings) -> OutputStream? {
    guard let os = CaptureSession_createOutputStream(wrapped, outputStreamSettings.wrapped) else { return nil }
    return OutputStream(os)
  }

  public func createRequest() -> Request? {
    guard let r = CaptureSession_createRequest(wrapped) else { return nil }
    return Request(r)
  }

  public func `repeat`(request: Request) -> Bool {
    return CaptureSession_repeat(wrapped, request.wrapped)
  }

  public func stopRepeat() {
    CaptureSession_stopRepeat(wrapped)
  }

  public func waitForIdle() {
    CaptureSession_waitForIdle(wrapped)
  }
}
