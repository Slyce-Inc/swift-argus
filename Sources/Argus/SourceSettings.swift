import Clibargus

public typealias ExposureTimeRange = (min:UInt64, max:UInt64)
public typealias GainRange = (min:Float, max:Float)

public class SourceSettings {
  let wrapped: UnsafeRawPointer?

  init(_ wrapped: UnsafeRawPointer) {
    self.wrapped = wrapped
  }

  public func setFrameDurationRange(min: UInt64, max: UInt64) {
    SourceSettings_setFrameDurationRange(wrapped, min, max)
  }

  public var exposureTimeRange: ExposureTimeRange {
    get {
      var min: UInt64 = 0
      var max: UInt64 = 0
      SourceSettings_getExposureTimeRange(wrapped, &min, &max)
      return ExposureTimeRange(min, max)
    }
    set {
      SourceSettings_setExposureTimeRange(wrapped, newValue.min, newValue.max)
    }
  }

  public var gainRange: GainRange {
    get {
      var min: Float = 0
      var max: Float = 0
      SourceSettings_getGainRange(wrapped, &min, &max)
      return GainRange(min, max)
    }
    set {
      SourceSettings_setGainRange(wrapped, newValue.min, newValue.max)
    }
  }
}
