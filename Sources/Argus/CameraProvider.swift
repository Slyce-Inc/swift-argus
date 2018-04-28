import libargus

public class CameraProvider {
  let wrapped: UnsafeRawPointer

  public init() {
    wrapped = CameraProvider_create()
  }

  deinit {
    reset()
    CameraProvider_destroy(wrapped)
  }

  public var version: String {
    return String(cString: CameraProvider_getVersion(wrapped))
  }

  public var vendor: String {
    return String(cString: CameraProvider_getVendor(wrapped))
  }

  public var cameraDevices: [CameraDevice]? {
    var ptrs = [UnsafeRawPointer?](repeating: nil, count: 6)
    let n = CameraProvider_getDevices(wrapped, &ptrs, ptrs.count)
    guard n != 0 else { return nil }
    return ptrs[..<n].map { CameraDevice($0!) }
  }

  public func createCaptureSession(cameraDevices: [CameraDevice]) -> CaptureSession? {
    var ptrs = cameraDevices.map { $0.wrapped }
    guard let cs = CameraProvider_createCaptureSession(wrapped, &ptrs, ptrs.count) else { return nil }
    return CaptureSession(cs)
  }

  public func reset() {
    CameraProvider_reset(wrapped)
  }
}
