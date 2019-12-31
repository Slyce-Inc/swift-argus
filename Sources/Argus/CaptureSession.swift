import Clibargus

public class CaptureSession {
  let wrapped: UnsafeRawPointer?

  init(_ wrapped: UnsafeRawPointer) {
    self.wrapped = wrapped
  }

  deinit {
    CaptureSession_destroy(wrapped)
  }

  public func createOutputStreamSettings(_ streamType:StreamType, _ statusToReturn: inout Status) -> OutputStreamSettings? {
    var status = 0
    guard let oss = CaptureSession_createOutputStreamSettings(wrapped, streamType.rawValue, &status) else { return nil }
    statusToReturn = Status(rawValue: status)!
    switch streamType {
    case .EGL:
      return EGLOutputStreamSettings(oss)
    case .BUFFER:
      return OutputStreamSettings(oss)
    }
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
