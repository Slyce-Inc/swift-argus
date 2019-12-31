import Clibargus

public class OutputStreamSettings {
  let wrapped: UnsafeRawPointer?

  init(_ wrapped: UnsafeRawPointer) {
    self.wrapped = wrapped
  }

  deinit {
    OutputStreamSettings_destroy(wrapped)
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
}

public class EGLOutputStreamSettings : OutputStreamSettings {
  override init(_ wrapped: UnsafeRawPointer) {
    super.init(wrapped)
  }

  public var pixelFormat: PixelFormat {
    get {
      return PixelFormat(rawValue: EGLOutputStreamSettings_getPixelValue(wrapped))!
    }
    set {
      EGLOutputStreamSettings_setPixelFormat(wrapped, newValue.rawValue)
    }
  }

  public var resolution: Size2D {
    get {
      var w = 0, h = 0
      EGLOutputStreamSettings_getResolution(wrapped, &w, &h)
      return Size2D(width: w, height: h)
    }
    set {
      EGLOutputStreamSettings_setResolution(wrapped, newValue.width, newValue.height)
    }
  }

  public var mode: EGLStreamMode {
    get {
      return EGLStreamMode(rawValue: EGLOutputStreamSettings_getEGLStreamMode(wrapped))!
    }
    set {
      EGLOutputStreamSettings_setEGLStreamMode(wrapped, newValue.rawValue)
    }
  }

  public var fifoLength : Int {
    get {
      return EGLOutputStreamSettings_getFifoLength(wrapped)
    }
    set {
      EGLOutputStreamSettings_setFifoLength(wrapped, newValue)
    }
  }
}
