import Clibargus

public class CameraDevice {
  let wrapped: UnsafeRawPointer?

  init(_ wrapped: UnsafeRawPointer) {
    self.wrapped = wrapped
  }

  public var basicSensorModes: [SensorMode] {
    var ptrs = [UnsafeRawPointer?](repeating: nil, count: 32)
    let n = CameraDevice_getBasicSensorModes(wrapped, &ptrs, ptrs.count)
    guard n != 0 else { return [] }
    return ptrs[..<n].map { SensorMode($0!) }
  }

  public var allSensorModes: [SensorMode] {
    var ptrs = [UnsafeRawPointer?](repeating: nil, count: 32)
    let n = CameraDevice_getAllSensorModes(wrapped, &ptrs, ptrs.count)
    guard n != 0 else { return [] }
    return ptrs[..<n].map { SensorMode($0!) }
  }
}
