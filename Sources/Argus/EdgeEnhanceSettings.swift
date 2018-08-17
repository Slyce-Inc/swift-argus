import Clibargus


public class EdgeEnhanceSettings {
  let wrapped: UnsafeRawPointer?

  init(_ wrapped: UnsafeRawPointer) {
    self.wrapped = wrapped
  }

  public var mode : EdgeEnhanceMode {
    get {
      return EdgeEnhanceMode(rawValue: EdgeEnhanceSettings_getMode(wrapped))!
    }
    set {
      EdgeEnhanceSettings_setMode(wrapped, newValue.rawValue)
    }
  }

  public var strength : Float {
    get {
      return EdgeEnhanceSettings_getStrength(wrapped)
    }
    set {
      EdgeEnhanceSettings_setStrength(wrapped, newValue)
    }
  }
}

public enum EdgeEnhanceMode : Int {
  case OFF = 0
  case FAST = 1
  case HIGH_QUALITY = 2
}
