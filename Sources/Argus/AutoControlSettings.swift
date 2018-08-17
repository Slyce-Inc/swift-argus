import Clibargus

public class AutoControlSettings {
  let wrapped: UnsafeRawPointer?

  init(_ wrapped: UnsafeRawPointer) {
    self.wrapped = wrapped
  }

  public var awbMode: AwbMode {
    get {
      return AwbMode(rawValue: AutoControlSettings_getMode(wrapped))!
    }
    set {
      AutoControlSettings_setMode(wrapped, newValue.rawValue)
    }
  }

  public var awbLock: Bool {
    get {
      return AutoControlSettings_getAwbLock(wrapped)
    }
    set {
      AutoControlSettings_setAwbLock(wrapped, newValue)
    }
  }

  public var aeLock: Bool {
    get {
      return AutoControlSettings_getAeLock(wrapped)
    }
    set {
      AutoControlSettings_setAeLock(wrapped, newValue)
    }
  }
}

public enum AwbMode : Int {
  case OFF = 0
  case AUTO = 1
  case INCANDESCENT = 2
  case FLUORESCENT = 3
  case WARM_FLUORESCENT = 4
  case DAYLIGHT = 5
  case CLOUDY_DAYLIGHT = 6
  case TWILIGHT = 7
  case SHADE = 8
  case MANUAL = 9
}
