import libargus


public class DenoiseSettings {
  let wrapped: UnsafeRawPointer?

  init(_ wrapped: UnsafeRawPointer) {
    self.wrapped = wrapped
  }

  public var mode : DenoiseMode {
    get {
      return DenoiseMode(rawValue: DenoiseSettings_getMode(wrapped))!
    }
    set {
      DenoiseSettings_setMode(wrapped, newValue.rawValue)
    }
  }

  public var strength : Float {
    get {
      return DenoiseSettings_getStrength(wrapped)
    }
    set {
      DenoiseSettings_setStrength(wrapped, newValue)
    }
  }
}

public enum DenoiseMode : Int {
  case OFF = 0
  case FAST = 1
  case HIGH_QUALITY = 2
}
