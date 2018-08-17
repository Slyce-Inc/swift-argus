import Clibargus

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

  public var resolution: Size2D {
    get {
      var w = 0, h = 0
      OutputStreamSettings_getResolution(wrapped, &w, &h)
      return Size2D(width: w, height: h)
    }
    set {
      OutputStreamSettings_setResolution(wrapped, newValue.width, newValue.height)
    }
  }

  public var cameraDevice: CameraDevice? {
    get {
      guard let cd = OutputStreamSettings_getCameraDevice(wrapped) else {
        return nil
      }
      return CameraDevice(cd)
    }
    set {
      guard let cameraDevice = newValue else {
        return
      }
      OutputStreamSettings_setCameraDevice(wrapped, cameraDevice.wrapped)
    }
  }

  public var mode: StreamMode {
    get {
      return StreamMode(rawValue: OutputStreamSettings_getStreamMode(wrapped))!
    }
    set {
      OutputStreamSettings_setStreamMode(wrapped, newValue.rawValue)
    }
  }

  public var fifoLength : Int {
    get {
      return OutputStreamSettings_getFifoLength(wrapped)
    }
    set {
      OutputStreamSettings_setFifoLength(wrapped, newValue)
    }
  }
}
