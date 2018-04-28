import libargus

public class OutputStreamSettings {
  let wrapped: UnsafeRawPointer?

  init(_ wrapped: UnsafeRawPointer) {
    self.wrapped = wrapped
  }

  deinit {
    OutputStreamSettings_destroy(wrapped)
  }

  public var pixelFormat: PixelFormat {
    get {
      return PixelFormat(rawValue: OutputStreamSettings_getPixelValue(wrapped))!
    }
    set {
      OutputStreamSettings_setPixelFormat(wrapped, newValue.rawValue)
    }
  }
}
