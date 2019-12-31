
public struct Size2D {
  public let width: Int
  public let height: Int

  public init(width: Int, height: Int) {
    self.width = width
    self.height = height
  }
}

public typealias EGLStreamKHR = UnsafeMutableRawPointer?

public enum StreamMode : Int {
  case MAILBOX = 1
  case FIFO = 2
}

public enum EGLStreamMode : Int {
  case MAILBOX = 1
  case FIFO = 2
}

public enum StreamType : Int {
  case EGL = 1
  case BUFFER = 2
}

public enum Status : Int {
  case OK                 = 0

  /// The set of parameters passed was invalid.
  case INVALID_PARAMS     = 1

  /// The requested settings are invalid.
  case INVALID_SETTINGS   = 2

  /// The requested device is unavailable.
  case UNAVAILABLE        = 3

  /// An operation failed because of insufficient mavailable memory.
  case OUT_OF_MEMORY      = 4

  /// This method has not been implemented.
  case UNIMPLEMENTED      = 5

  /// An operation timed out.
  case TIMEOUT            = 6

  /// The capture was aborted. @see ICaptureSession::cancelRequests()
  case CANCELLED          = 7

  /// The stream or other resource has been disconnected.
  case DISCONNECTED       = 8

  /// End of stream, used by Stream objects.
  case END_OF_STREAM      = 9
}
