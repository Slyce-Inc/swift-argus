import libargus

public class CameraProvider {
  let wrapped: UnsafeRawPointer

  public init() {
    wrapped = CameraProvider_create()
  }

  deinit {
    CameraProvider_destroy(wrapped)
  }

  public func getVersion() -> String {
    return String(cString: CameraProvider_getVersion(wrapped))
  }

  public func getVendor() -> String {
    return String(cString: CameraProvider_getVendor(wrapped))
  }

  public func getDevices() -> [CameraDevice]? {
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
}
