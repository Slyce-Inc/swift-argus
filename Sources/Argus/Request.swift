import libargus

public class Request {
  let wrapped: UnsafeRawPointer?

  init(_ wrapped: UnsafeRawPointer) {
    self.wrapped = wrapped
  }

  deinit {
    Request_destroy(wrapped)
  }

  public func enable(outputStream: OutputStream) -> Bool {
    return Request_enableOutputStream(wrapped, outputStream.wrapped)
  }

  public var sourceSettings: SourceSettings! {
    guard let ss = Request_getSourceSettings(wrapped) else {
      return nil
    }
    return SourceSettings(ss)
  }

  public var autoControlSettings: AutoControlSettings! {
    guard let acs = Request_getAutoControlSettings(wrapped) else {
      return nil
    }
    return AutoControlSettings(acs)
  }

  public var denoiseSettings: DenoiseSettings! {
    guard let ds = Request_getDenoiseSettings(wrapped) else {
      return nil
    }
    return DenoiseSettings(ds)
  }

  public var edgeEnhanceSettings: EdgeEnhanceSettings! {
    guard let ds = Request_getEdgeEnhanceSettings(wrapped) else {
      return nil
    }
    return EdgeEnhanceSettings(ds)
  }
}
