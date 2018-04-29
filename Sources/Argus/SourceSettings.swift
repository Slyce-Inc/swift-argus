import libargus

public class SourceSettings {
  let wrapped: UnsafeRawPointer?

  init(_ wrapped: UnsafeRawPointer) {
    self.wrapped = wrapped
  }

  public func setFrameDurationRange(min: UInt64, max: UInt64) {
    SourceSettings_setFrameDurationRange(wrapped, min, max)
  }
}
